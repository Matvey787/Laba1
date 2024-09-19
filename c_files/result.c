#include "../h_files/result.h"
#include <math.h>
float result(int K,float resistance[])
{
    float resistance_final =0;
    for (int i = 0; i < K;i++)
        resistance_final+=resistance[i];

    resistance_final /= K;
    float devivation = 0;

    for (int i = 0;i<K;i++){
        devivation += pow((resistance[i]-resistance_final), 2);
    }
    devivation = sqrt(devivation) / K;
    printf("%f +- %f\n",resistance_final,devivation);

    return resistance_final;
}