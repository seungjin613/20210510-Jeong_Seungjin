#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum //���� ������ ����
{
    KOREAN,
    MATH,
    ENGLISH,
    SUBJECT_COUNT
} Subject;

#define MAX_STUDENTS 200


typedef struct //�л� ����ü ����
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

    for (int i = 0; i < StudentCounts[0]; i++)  //������ �л� �迭 ����
    {
        allStudents[i] = students[0][i];
    }
    for (int i = 0; i < StudentCounts[1]; i++)
    {
        allStudents[StudentCounts[0] + i] = students[1][i];
    }


    for (int i = 0; i < totalStudents; i++)//��ü ��� ���
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

    for (int i = 0; i < StudentCounts[0]; i++)//��ü ����� �� �йݿ� �ٽ� ����
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
        perror("���� ���� ����");
        exit(1);
    }

    for (int i = 0; i < StudentCounts[classIndex]; i++)
    {
        fprintf(file, "�й�: %d\n�̸�: %s\n����: %d\n����: %d\n����: %d\n���: %.2f\n�й� ���: %d\n��ü ���: %d\n\n",
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
        perror("���� ���� ����");
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

    fprintf(file, "��ü �л�\n\n");

    fprintf(file, "�й� 1 �л� ��: %d��\n", StudentCounts[0]);
    fprintf(file, "�й� 2 �л� ��: %d��\n\n", StudentCounts[1]);

    fprintf(file, "�й� 1\n");
    fprintf(file, "�й� 1 ��� ����: %.2f\n", StudentCounts[0] > 0 ?
        Sum_1 / StudentCounts[0] : 0);
    fprintf(file, "�й� 1 �л��� �й� ���:\n");
    for (int i = 0; i < StudentCounts[0]; i++)
    {
        fprintf(file, "%s (�й�: %d) - �й� ���: %d\n",
            students[0][i].name, students[0][i].Studentnum, students[0][i].ClassRank);
    }
    fprintf(file, "\n");

    fprintf(file, "�й� 2\n");
    fprintf(file, "�й� 2 ��� ����: %.2f\n", StudentCounts[1] > 0 ? Sum_2 / StudentCounts[1] : 0);
    fprintf(file, "�й� 2 �л��� �й� ���:\n");
    for (int i = 0; i < StudentCounts[1]; i++)
    {
        fprintf(file, "%s (�й�: %d) - �й� ���: %d\n",
            students[1][i].name, students[1][i].Studentnum, students[1][i].ClassRank);
    }
    fprintf(file, "\n");

    fprintf(file, "��ü ���\n");// ��ü ��� ���
    fprintf(file, "��ü ��� ����: %.2f\n", (StudentCounts[0] + StudentCounts[1]) > 0 ?
        (Sum_1 + Sum_2) / (StudentCounts[0] + StudentCounts[1]) : 0);
    fprintf(file, "\n");

    fclose(file);
}

int main(void) 
{
    Student students[2][MAX_STUDENTS]; // 2���� �迭: [�й�][�л� �ε���]
    int StudentCounts[2] = { 0, 0 }; // �� �й��� �л� ��

    FILE* file_1;//���� ������ ����
    FILE* file_2;

    if (fopen_s(&file_1, "C:\\Users\\82105\\Downloads\\students_1.txt", "r") != 0)
    {
        perror("students_1.txt ���� ����");
        exit(1);
    }

    if (fopen_s(&file_2, "C:\\Users\\82105\\Downloads\\students_2.txt", "r") != 0)
    {
        perror("students_2.txt ���� ����");
        fclose(file_1);
        exit(1);
    }

    loadStudents(file_1, students, StudentCounts, 0);//�л� ���� ���� �ҷ�����
    loadStudents(file_2, students, StudentCounts, 1);

    fclose(file_1);
    fclose(file_2);

    CAverage(students, StudentCounts, 0);//��� �� ��� ���
    CAverage(students, StudentCounts, 1);
    CRanks(students, StudentCounts, 0);
    CRanks(students, StudentCounts, 1);
    COverallRanks(students, StudentCounts);

    saveResults("students_1_results.txt", students, StudentCounts, 0);//���� ����
    saveResults("students_2_results.txt", students, StudentCounts, 1);
    saveClassSummary("class_results.txt", students, StudentCounts);

    printf("��� ������ ���������� �����Ǿ����ϴ�.\n");
    return 0;
}