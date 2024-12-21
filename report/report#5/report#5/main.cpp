#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum //과목 열거형 정의
{
    KOREAN,
    MATH,
    ENGLISH,
    SUBJECT_COUNT
} Subject;

#define MAX_STUDENTS 200


typedef struct //학생 구조체 정의
{
    char name[50];
    int Studentnum;
    int scores[SUBJECT_COUNT];
    double average;
    int ClassRank;
    int OverallRank;
} Student;

void loadStudents(FILE* file, Student students[][MAX_STUDENTS], int* StudentCounts, int classIndex)
{
    while (fscanf_s(file, "%49s %d %d %d %d",
        students[classIndex][StudentCounts[classIndex]].name,
        (unsigned)_countof(students[classIndex][StudentCounts[classIndex]].name),
        &students[classIndex][StudentCounts[classIndex]].Studentnum,
        &students[classIndex][StudentCounts[classIndex]].scores[KOREAN],
        &students[classIndex][StudentCounts[classIndex]].scores[MATH],
        &students[classIndex][StudentCounts[classIndex]].scores[ENGLISH]) == 5)
    {
        StudentCounts[classIndex]++;
    }
}

void CAverage(Student students[][MAX_STUDENTS], int StudentCounts[], int classIndex)
{
    for (int i = 0; i < StudentCounts[classIndex]; i++)
    {
        int Total = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++) 
        {
            Total += students[classIndex][i].scores[j];
        }
        students[classIndex][i].average = Total / (double)SUBJECT_COUNT;
    }
}

void CRanks(Student students[][MAX_STUDENTS], int StudentCounts[], int classIndex)
{
    for (int i = 0; i < StudentCounts[classIndex]; i++)
    {
        int Rank = 1;
        for (int j = 0; j < StudentCounts[classIndex]; j++)
        {
            if (students[classIndex][j].average > students[classIndex][i].average)
            {
                Rank++;
            }
        }
        students[classIndex][i].ClassRank = Rank;
    }
}

void COverallRanks(Student students[][MAX_STUDENTS], int StudentCounts[]) 
{
    Student allStudents[MAX_STUDENTS * 2];
    int totalStudents = StudentCounts[0] + StudentCounts[1];

    for (int i = 0; i < StudentCounts[0]; i++)  //합쳐진 학생 배열 생성
    {
        allStudents[i] = students[0][i];
    }
    for (int i = 0; i < StudentCounts[1]; i++)
    {
        allStudents[StudentCounts[0] + i] = students[1][i];
    }


    for (int i = 0; i < totalStudents; i++)//전체 등수 계산
    {
        int Rank = 1;
        for (int j = 0; j < totalStudents; j++) 
        {
            if (allStudents[j].average > allStudents[i].average)
            {
                Rank++;
            }
        }
        allStudents[i].OverallRank = Rank;
    }

    for (int i = 0; i < StudentCounts[0]; i++)//전체 등수를 각 분반에 다시 매핑
    {
        for (int j = 0; j < totalStudents; j++) 
        {
            if (students[0][i].Studentnum == allStudents[j].Studentnum)
            {
                students[0][i].OverallRank = allStudents[j].OverallRank;
                break;
            }
        }
    }
    for (int i = 0; i < StudentCounts[1]; i++)
    {
        for (int j = 0; j < totalStudents; j++) 
        {
            if (students[1][i].Studentnum == allStudents[j].Studentnum)
            {
                students[1][i].OverallRank = allStudents[j].OverallRank;
                break;
            }
        }
    }
}

void saveResults(const char* File, Student students[][MAX_STUDENTS], int StudentCounts[], int classIndex)
{
    FILE* file;
    if (fopen_s(&file, File, "w") != 0)
    {
        perror("파일 쓰기 실패");
        exit(1);
    }

    for (int i = 0; i < StudentCounts[classIndex]; i++)
    {
        fprintf(file, "학번: %d\n이름: %s\n국어: %d\n수학: %d\n영어: %d\n평균: %.2f\n분반 등수: %d\n전체 등수: %d\n\n",
            students[classIndex][i].Studentnum,
            students[classIndex][i].name,
            students[classIndex][i].scores[KOREAN],
            students[classIndex][i].scores[MATH],
            students[classIndex][i].scores[ENGLISH],
            students[classIndex][i].average,
            students[classIndex][i].ClassRank,
            students[classIndex][i].OverallRank);
    }

    fclose(file);
}

void saveClassSummary(const char* File, Student students[][MAX_STUDENTS], int StudentCounts[])
{
    FILE* file;
    if (fopen_s(&file, File, "w") != 0)
    {
        perror("파일 쓰기 실패");
        exit(1);
    }

    double Sum_1 = 0, Sum_2 = 0;
    for (int i = 0; i < StudentCounts[0]; i++)
    {
        Sum_1 += students[0][i].average;
    }
    for (int i = 0; i < StudentCounts[1]; i++)
    {
        Sum_2 += students[1][i].average;
    }

    fprintf(file, "전체 학생\n\n");

    fprintf(file, "분반 1 학생 수: %d명\n", StudentCounts[0]);
    fprintf(file, "분반 2 학생 수: %d명\n\n", StudentCounts[1]);

    fprintf(file, "분반 1\n");
    fprintf(file, "분반 1 평균 점수: %.2f\n", StudentCounts[0] > 0 ?
        Sum_1 / StudentCounts[0] : 0);
    fprintf(file, "분반 1 학생의 분반 등수:\n");
    for (int i = 0; i < StudentCounts[0]; i++)
    {
        fprintf(file, "%s (학번: %d) - 분반 등수: %d\n",
            students[0][i].name, students[0][i].Studentnum, students[0][i].ClassRank);
    }
    fprintf(file, "\n");

    fprintf(file, "분반 2\n");
    fprintf(file, "분반 2 평균 점수: %.2f\n", StudentCounts[1] > 0 ? Sum_2 / StudentCounts[1] : 0);
    fprintf(file, "분반 2 학생의 분반 등수:\n");
    for (int i = 0; i < StudentCounts[1]; i++)
    {
        fprintf(file, "%s (학번: %d) - 분반 등수: %d\n",
            students[1][i].name, students[1][i].Studentnum, students[1][i].ClassRank);
    }
    fprintf(file, "\n");

    fprintf(file, "전체 평균\n");// 전체 평균 계산
    fprintf(file, "전체 평균 점수: %.2f\n", (StudentCounts[0] + StudentCounts[1]) > 0 ?
        (Sum_1 + Sum_2) / (StudentCounts[0] + StudentCounts[1]) : 0);
    fprintf(file, "\n");

    fclose(file);
}

int main(void) 
{
    Student students[2][MAX_STUDENTS]; // 2차원 배열: [분반][학생 인덱스]
    int StudentCounts[2] = { 0, 0 }; // 각 분반의 학생 수

    FILE* file_1;//파일 포인터 생성
    FILE* file_2;

    if (fopen_s(&file_1, "C:\\Users\\82105\\Downloads\\students_1.txt", "r") != 0)
    {
        perror("students_1.txt 열기 실패");
        exit(1);
    }

    if (fopen_s(&file_2, "C:\\Users\\82105\\Downloads\\students_2.txt", "r") != 0)
    {
        perror("students_2.txt 열기 실패");
        fclose(file_1);
        exit(1);
    }

    loadStudents(file_1, students, StudentCounts, 0);//학생 정보 파일 불러오기
    loadStudents(file_2, students, StudentCounts, 1);

    fclose(file_1);
    fclose(file_2);

    CAverage(students, StudentCounts, 0);//평균 및 등수 계산
    CAverage(students, StudentCounts, 1);
    CRanks(students, StudentCounts, 0);
    CRanks(students, StudentCounts, 1);
    COverallRanks(students, StudentCounts);

    saveResults("students_1_results.txt", students, StudentCounts, 0);//파일 저장
    saveResults("students_2_results.txt", students, StudentCounts, 1);
    saveClassSummary("class_results.txt", students, StudentCounts);

    printf("결과 파일이 성공적으로 생성되었습니다.\n");
    return 0;
}