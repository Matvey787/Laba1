#include <math.h>
#include "../h_files/data_select.h"

int data_select(int M, float resistance[]){

    float summary = 0;
    float eps = 0.03;

    for (int i = 0; i < M; i++)
        summary += resistance[i];

    float resistance_average = summary / M;
    int K = 0;

    for (int i = 0; i < M; i++)
        if ((fabs(resistance[i] - resistance_average)) <= eps*(resistance_average))
            resistance[K++] = resistance[i];
    
    return K;

}