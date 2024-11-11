#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define num_flip 10000
#define END_COND 999
#define initstatus 100
#define coin_fwd_bwd 3
#define coin_fwd_status 1
#define coin_bwd_status 2
#define coin_not_valid 0

void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}

unsigned int GenRandFlipcoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    while (1)
    {
        nRes = ((unsigned int)(rand()) % (nRange));
        if ((nRes == coin_fwd_status) || (nRes == coin_bwd_status))
            break;
    }
    return nRes;
}

int main(void)
{
    GenRandSeed();

    int nnumsumFwdflip = 0;
    int nnumsumBdflip = 0;
    double dVarFwdflip = 0.0;
    double dVarBwdflip = 0.0;
    double dStdevFwdflip = 0.0;
    double dStdevBwdflip = 0.0;

    for (unsigned int i = 0; i < num_flip; i++)
    {
        unsigned int nstatusflip = GenRandFlipcoin(coin_fwd_bwd);


        switch (nstatusflip)
        {
        case coin_fwd_status:
        {
            nnumsumFwdflip++;
            break;
        }
        case coin_bwd_status:
        {
            nnumsumBdflip++;
            break;
        }
        default:
        {
            printf("please check your main loop or sub funciton\n");
            break;
        }
        }
    }
    printf("summation Result:(FWD,BWD):(%d,%d)\n", nnumsumFwdflip, nnumsumBdflip);
    printf("probability:(FWD,BWD):(%.4lf, %.4lf)\n", (double)(nnumsumFwdflip) / (num_flip), (double)(nnumsumBdflip) / (num_flip));
    return 0;
}