#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define SUBJECT_COUNT 3

enum { SUBJ1, SUBJ2, SUBJ3 };

typedef struct {
    char name[NAME_LEN];
    int class_div;
    int student_id;
    int scores[SUBJECT_COUNT];
    double avg;
    int class_rank;
    int overall_rank;
} Student;

int read_students(const char* filename, Student students[], int class_div);
void compute_average(Student students[], int count);
void compute_ranks(Student students[], int total_count);
void compute_class_stats(Student students[], int total_count,
    double* class1_avg, double* class1_var,
    double* class2_avg, double* class2_var,
    double* overall_avg);
void write_results_per_class(const char* filename, Student students[], int total_count, int class_div);
void write_class_results(const char* filename, double c1_avg, double c1_var, double c2_avg, double c2_var, double overall_avg);

int main(void) {
    Student all_students[MAX_STUDENTS];
    int count1 = 0, count2 = 0;
    int total_count = 0;

    // students_1.txt -> 1반
    count1 = read_students("students_1.txt", all_students, 1);
    // students_2.txt -> 2반
    count2 = read_students("students_2.txt", all_students + count1, 2);
    total_count = count1 + count2;

    // 학생별 평균 계산
    compute_average(all_students, total_count);

    // 전체 등수 및 분반등수 계산
    compute_ranks(all_students, total_count);

    // 분반별/전체 통계 계산
    double c1_avg, c1_var, c2_avg, c2_var, overall_avg;
    compute_class_stats(all_students, total_count, &c1_avg, &c1_var, &c2_avg, &c2_var, &overall_avg);

    // 결과 출력
    write_results_per_class("students_1_results.txt", all_students, total_count, 1);
    write_results_per_class("students_2_results.txt", all_students, total_count, 2);
    write_class_results("class_results.txt", c1_avg, c1_var, c2_avg, c2_var, overall_avg);

    return 0;
}

int read_students(const char* filename, Student students[], int class_div) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "File %s open error\n", filename);
        return 0;
    }

    int count = 0;
    while (!feof(fp) && count < MAX_STUDENTS) {
        // 형식: 이름 학번 점수1 점수2 점수3
        // 분반 정보는 함수 호출 시 파라미터로 받은 class_div로 대입
        if (fscanf(fp, "%s %d %d %d %d",
            students[count].name,
            &students[count].student_id,
            &students[count].scores[SUBJ1],
            &students[count].scores[SUBJ2],
            &students[count].scores[SUBJ3]) == 5) {
            students[count].class_div = class_div;
            count++;
        }
    }
    fclose(fp);
    return count;
}

void compute_average(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int s = 0; s < SUBJECT_COUNT; s++) {
            sum += students[i].scores[s];
        }
        students[i].avg = sum / SUBJECT_COUNT;
    }
}

int compare_by_avg(const void* a, const void* b) {
    double diff = ((Student*)b)->avg - ((Student*)a)->avg;
    if (diff > 0) return 1;
    else if (diff < 0) return -1;
    else return 0;
}

void compute_ranks(Student students[], int total_count) {
    // 전체 등수 계산용
    Student* temp = (Student*)malloc(sizeof(Student) * total_count);
    memcpy(temp, students, sizeof(Student) * total_count);
    qsort(temp, total_count, sizeof(Student), compare_by_avg);

    // 전체등수 매기기
    for (int i = 0; i < total_count; i++) {
        for (int j = 0; j < total_count; j++) {
            if (temp[i].student_id == students[j].student_id &&
                strcmp(temp[i].name, students[j].name) == 0 &&
                temp[i].class_div == students[j].class_div) {
                students[j].overall_rank = i + 1;
                break;
            }
        }
    }

    // 분반별 등수 계산
    int c1_count = 0, c2_count = 0;
    for (int i = 0; i < total_count; i++)
        if (students[i].class_div == 1) c1_count++;
    c2_count = total_count - c1_count;

    Student* class1 = (Student*)malloc(sizeof(Student) * c1_count);
    Student* class2 = (Student*)malloc(sizeof(Student) * c2_count);

    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < total_count; i++) {
        if (students[i].class_div == 1) class1[idx1++] = students[i];
        else class2[idx2++] = students[i];
    }

    qsort(class1, c1_count, sizeof(Student), compare_by_avg);
    qsort(class2, c2_count, sizeof(Student), compare_by_avg);

    // class1 분반등수 부여
    for (int i = 0; i < c1_count; i++) {
        for (int j = 0; j < total_count; j++) {
            if (class1[i].student_id == students[j].student_id &&
                strcmp(class1[i].name, students[j].name) == 0 &&
                class1[i].class_div == students[j].class_div) {
                students[j].class_rank = i + 1;
                break;
            }
        }
    }

    // class2 분반등수 부여
    for (int i = 0; i < c2_count; i++) {
        for (int j = 0; j < total_count; j++) {
            if (class2[i].student_id == students[j].student_id &&
                strcmp(class2[i].name, students[j].name) == 0 &&
                class2[i].class_div == students[j].class_div) {
                students[j].class_rank = i + 1;
                break;
            }
        }
    }

    free(temp);
    free(class1);
    free(class2);
}

void compute_class_stats(Student students[], int total_count,
    double* class1_avg, double* class1_var,
    double* class2_avg, double* class2_var,
    double* overall_avg) {
    double sum_all = 0;
    double sum_c1 = 0, sum_c2 = 0;
    int c1_count = 0, c2_count = 0;

    for (int i = 0; i < total_count; i++) {
        sum_all += students[i].avg;
        if (students[i].class_div == 1) {
            sum_c1 += students[i].avg;
            c1_count++;
        }
        else {
            sum_c2 += students[i].avg;
            c2_count++;
        }
    }

    *overall_avg = sum_all / total_count;
    *class1_avg = (c1_count > 0) ? (sum_c1 / c1_count) : 0.0;
    *class2_avg = (c2_count > 0) ? (sum_c2 / c2_count) : 0.0;

    double var_sum_c1 = 0, var_sum_c2 = 0;
    for (int i = 0; i < total_count; i++) {
        if (students[i].class_div == 1)
            var_sum_c1 += (students[i].avg - (*class1_avg)) * (students[i].avg - (*class1_avg));
        else
            var_sum_c2 += (students[i].avg - (*class2_avg)) * (students[i].avg - (*class2_avg));
    }

    *class1_var = (c1_count > 0) ? var_sum_c1 / c1_count : 0.0;
    *class2_var = (c2_count > 0) ? var_sum_c2 / c2_count : 0.0;
}

void write_results_per_class(const char* filename, Student students[], int total_count, int class_div) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Cannot open %s for writing\n", filename);
        return;
    }

    // 헤더
    fprintf(fp, "학번 이름 점수1 점수2 점수3 평균 분반등수 전체등수\n");
    for (int i = 0; i < total_count; i++) {
        if (students[i].class_div == class_div) {
            fprintf(fp, "%d %s %d %d %d %.2f %d %d\n",
                students[i].student_id,
                students[i].name,
                students[i].scores[SUBJ1],
                students[i].scores[SUBJ2],
                students[i].scores[SUBJ3],
                students[i].avg,
                students[i].class_rank,
                students[i].overall_rank
            );
        }
    }

    fclose(fp);
}

void write_class_results(const char* filename, double c1_avg, double c1_var, double c2_avg, double c2_var, double overall_avg) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Cannot open %s for writing\n", filename);
        return;
    }

    fprintf(fp, "분반별/전체 통계 결과\n");
    fprintf(fp, "1반 평균: %.2f\n", c1_avg);
    fprintf(fp, "1반 분산: %.2f\n", c1_var);
    fprintf(fp, "2반 평균: %.2f\n", c2_avg);
    fprintf(fp, "2반 분산: %.2f\n", c2_var);
    fprintf(fp, "전체 평균: %.2f\n", overall_avg);

    fclose(fp);
}