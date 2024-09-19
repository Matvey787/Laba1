#include <stdio.h>
#include <math.h>

#include "../h_files/check.h"
#include "../h_files/preparation.h"
#include "../h_files/data_select.h"
#include "../h_files/result.h"

int main(){
    float resistance[100] = {};
    int M = preparation(resistance);
    int K = data_select(M, resistance);
    float resistance_final = result(K, resistance);

    printf("Resistance final: %lg\n", resistance_final);
    check(K, resistance, resistance_final);

    return 0;
}