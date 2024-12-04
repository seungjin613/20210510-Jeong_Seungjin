#include <stdio.h>

void SetArray(double *pDArr, int nArrsize)
{
	int i;
	printf("%d개의 실수값 입력 : ", nArrsize);
	for (unsigned int i = 0; i < nArrsize; i++)
	{
		scanf_s("%lf", pDArr + i);
	}
}

void printArrray(double *pDArr, int nArrsize)
{
	printf("%d개의 실수값 입력 : ", nArrsize);
	for (unsigned int i = 0; i < nArrsize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr +i));
	}
}

double CMVA(double* pDArr, int Arrsize)
{	//double dRes = pDArr[0];
	double dRes = *(pDArr + 0);
	for (unsigned int i = 0; i < nArrsize; i++)
	{
		if (*(pDArr + i) > dRes)
		{
			dRes = *(pDArr + i);
		}
	}
	return dRes;
}

int main(void)
{
	double dArr[5] = {};
	double pDArr = dArr;
	const int nArrsize = sizeof(dArr) / sizeof(dArr[0]);

	SetArray(dArr, nArrsize);
	printArrray(dArr, nArrsize);
	for(unsigned int i =0; i < nArrsize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, dArr + i, *(dArr + i);
	}

	printf("[max](%.4lf)\n", CMVA(pDArr, nArrsize);
	return 0;
}