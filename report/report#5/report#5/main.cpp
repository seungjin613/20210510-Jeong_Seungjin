#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 과목 열거형 정의
typedef enum 
{
    KOREAN,
    MATH,
    ENGLISH,
    SUBJECT_COUNT
} Subject;

#define MAX_STUDENTS 200

// 학생 정보 구조체 정의
typedef struct 
{
    char name[50];
    int nId;
    int nScores[SUBJECT_COUNT];
    double dAverage;
    int nClassRank;
    int nOverallRank;
} Student;

// 함수 선언
void loadStudents(FILE* file, Student students[][MAX_STUDENTS], int* nStudentCounts, int classIndex);
void calculateAverage(Student students[][MAX_STUDENTS], int nStudentCounts[], int classIndex);
void calculateRanks(Student students[][MAX_STUDENTS], int nStudentCounts[], int classIndex);
void calculateOverallRanks(Student students[][MAX_STUDENTS], int nStudentCounts[]);
void saveResults(const char* fileName, Student students[][MAX_STUDENTS], int nStudentCounts[], int classIndex);
void saveClassSummary(const char* fileName, Student students[][MAX_STUDENTS], int nStudentCounts[]);

int main(void) 
{
    Student students[2][MAX_STUDENTS]; // 2차원 배열: [분반][학생 인덱스]
    int nStudentCounts[2] = { 0, 0 }; // 각 분반의 학생 수

    // 파일 포인터 생성
    FILE* file1;
    FILE* file2;

    if (fopen_s(&file1, "C:\\Users\\82105\\Downloads\\students_1.txt", "r") != 0)
    {
        perror("students_1.txt 열기 실패");
        exit(1);
    }

    if (fopen_s(&file2, "C:\\Users\\82105\\Downloads\\students_2.txt", "r") != 0) 
    {
        perror("students_2.txt 열기 실패");
        fclose(file1);
        exit(1);
    }

    // 학생 정보 파일 로드
    loadStudents(file1, students, nStudentCounts, 0);
    loadStudents(file2, students, nStudentCounts, 1);

    fclose(file1);
    fclose(file2);

    // 평균 및 등수 계산
    calculateAverage(students, nStudentCounts, 0);
    calculateAverage(students, nStudentCounts, 1);
    calculateRanks(students, nStudentCounts, 0);
    calculateRanks(students, nStudentCounts, 1);
    calculateOverallRanks(students, nStudentCounts);

    // 파일 저장
    saveResults("students_1_results.txt", students, nStudentCounts, 0);
    saveResults("students_2_results.txt", students, nStudentCounts, 1);
    saveClassSummary("class_results.txt", students, nStudentCounts);

    printf("결과 파일이 성공적으로 생성되었습니다.\n");
    return 0;
}

void loadStudents(FILE* file, Student students[][MAX_STUDENTS], int* nStudentCounts, int classIndex) {
    while (fscanf_s(file, "%49s %d %d %d %d",
        students[classIndex][nStudentCounts[classIndex]].name,
        (unsigned)_countof(students[classIndex][nStudentCounts[classIndex]].name),
        &students[classIndex][nStudentCounts[classIndex]].nId,
        &students[classIndex][nStudentCounts[classIndex]].nScores[KOREAN],
        &students[classIndex][nStudentCounts[classIndex]].nScores[MATH],
        &students[classIndex][nStudentCounts[classIndex]].nScores[ENGLISH]) == 5) {
        nStudentCounts[classIndex]++;
    }
}

void calculateAverage(Student students[][MAX_STUDENTS], int nStudentCounts[], int classIndex) {
    for (int i = 0; i < nStudentCounts[classIndex]; i++) {
        int nTotal = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            nTotal += students[classIndex][i].nScores[j];
        }
        students[classIndex][i].dAverage = nTotal / (double)SUBJECT_COUNT;
    }
}

void calculateRanks(Student students[][MAX_STUDENTS], int nStudentCounts[], int classIndex) {
    for (int i = 0; i < nStudentCounts[classIndex]; i++) {
        int nRank = 1;
        for (int j = 0; j < nStudentCounts[classIndex]; j++) {
            if (students[classIndex][j].dAverage > students[classIndex][i].dAverage) {
                nRank++;
            }
        }
        students[classIndex][i].nClassRank = nRank;
    }
}

void calculateOverallRanks(Student students[][MAX_STUDENTS], int nStudentCounts[]) {
    Student allStudents[MAX_STUDENTS * 2];
    int totalStudents = nStudentCounts[0] + nStudentCounts[1];

    // 합쳐진 학생 배열 생성
    for (int i = 0; i < nStudentCounts[0]; i++) {
        allStudents[i] = students[0][i];
    }
    for (int i = 0; i < nStudentCounts[1]; i++) {
        allStudents[nStudentCounts[0] + i] = students[1][i];
    }

    // 전체 등수 계산
    for (int i = 0; i < totalStudents; i++) {
        int nRank = 1;
        for (int j = 0; j < totalStudents; j++) {
            if (allStudents[j].dAverage > allStudents[i].dAverage) {
                nRank++;
            }
        }
        allStudents[i].nOverallRank = nRank;
    }

    // 전체 등수를 각 분반에 다시 매핑
    for (int i = 0; i < nStudentCounts[0]; i++) {
        for (int j = 0; j < totalStudents; j++) {
            if (students[0][i].nId == allStudents[j].nId) {
                students[0][i].nOverallRank = allStudents[j].nOverallRank;
                break;
            }
        }
    }
    for (int i = 0; i < nStudentCounts[1]; i++) {
        for (int j = 0; j < totalStudents; j++) {
            if (students[1][i].nId == allStudents[j].nId) {
                students[1][i].nOverallRank = allStudents[j].nOverallRank;
                break;
            }
        }
    }
}

void saveResults(const char* fileName, Student students[][MAX_STUDENTS], int nStudentCounts[], int classIndex) {
    FILE* file;
    if (fopen_s(&file, fileName, "w") != 0) {
        perror("파일 쓰기 실패");
        exit(1);
    }

    for (int i = 0; i < nStudentCounts[classIndex]; i++) {
        fprintf(file, "학번: %d\n이름: %s\n국어: %d\n수학: %d\n영어: %d\n평균: %.2f\n분반 등수: %d\n전체 등수: %d\n\n",
            students[classIndex][i].nId,
            students[classIndex][i].name,
            students[classIndex][i].nScores[KOREAN],
            students[classIndex][i].nScores[MATH],
            students[classIndex][i].nScores[ENGLISH],
            students[classIndex][i].dAverage,
            students[classIndex][i].nClassRank,
            students[classIndex][i].nOverallRank);
    }

    fclose(file);
}

void saveClassSummary(const char* fileName, Student students[][MAX_STUDENTS], int nStudentCounts[]) {
    FILE* file;
    if (fopen_s(&file, fileName, "w") != 0) {
        perror("파일 쓰기 실패");
        exit(1);
    }

    double dSum1 = 0, dSum2 = 0;
    for (int i = 0; i < nStudentCounts[0]; i++) {
        dSum1 += students[0][i].dAverage;
    }
    for (int i = 0; i < nStudentCounts[1]; i++) {
        dSum2 += students[1][i].dAverage;
    }

    fprintf(file, "분반 1 평균: %.2f\n", nStudentCounts[0] > 0 ?
        dSum1 / nStudentCounts[0] : 0);
    fprintf(file, "분반 2 평균: %.2f\n", nStudentCounts[1] > 0 ? dSum2 / nStudentCounts[1] : 0);
    fprintf(file, "전체 평균: %.2f\n", (nStudentCounts[0] + nStudentCounts[1]) > 0 ? (dSum1 + dSum2) / (nStudentCounts[0] + nStudentCounts[1]) : 0);

    fclose(file);
}
