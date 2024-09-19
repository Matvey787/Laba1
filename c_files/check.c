#include <math.h>
#include "../h_files/check.h"

int check(int K, float resistance[], float resistance_final){
        float delta_zero = 0.01;
        float summary = 0;

        for (int i = 0; i < K; i++)
            summary += resistance[i] - resistance_final;

        printf("%lf\n", fabs(summary/K));
        return (summary / K) < delta_zero;
}