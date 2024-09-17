#include <stdio.h>
#include <math.h>

float result(int K,float resistance[]);
int preparation(float resistance[]);
int data_select(int M, float resistance[]);
int check(int K, float resistance[], float resistance_final);

int main(){
    float resistance[100] = {};
    int M = preparation(resistance);
    int K = data_select(M, resistance);
    float resistance_final = result(K, resistance);
    printf("Resistance final: %lg\n", resistance_final);
    check(K, resistance, resistance_final);

return 0;
}

int preparation(float resistance[])
{
    float voltage[100]={};
    float current[100]={}; 
    float voltagei = 0;
    float currenti = 0;
    unsigned short m = 0;

    while ((scanf("%f%f",&voltagei,&currenti)) == 2)
    {
        voltage[m]=voltagei;
        current[m]=(currenti / 1000);
        resistance[m]=(voltage[m]/current[m]);
        m++;
    }

    return m;
}


float result(int K,float resistance[])
{
    float resistance_final =0;
    for (int i = 0;i < K;i++)
        resistance_final+=resistance[i];

    resistance_final /= K;
    float devivation = 0;

    for (int i = 0;i<K;i++){
        //printf("d %g\n", resistance[i]-resistance_final);
        devivation += pow((resistance[i]-resistance_final), 2);
    }
    devivation = sqrt(devivation)/K;
    printf("%f +- %f\n",resistance_final,devivation);

    return resistance_final;
}

int data_select(int M, float resistance[]){
    float summary = 0;
    float eps = 0.03;
    for (int i = 0; i < M; i++){
        //printf("res: %g\n", resistance[i]);
        summary += resistance[i];
    }
    float resistance_average = summary / M;

    int K = 0;

    for (int i = 0; i < M; i++){
        if (abs(resistance[i] - resistance_average)/resistance_average <= eps)
            resistance[K++] = resistance[i];
    }
    return K;

}

int check(int K, float resistance[], float resistance_final){
        float delta_zero = 0.001;
        float summary = 0;

        for (int i = 0; i < K; i++){
            //printf("s %f", resistance[i] - resistance_final);
            summary += resistance[i] - resistance_final;
        }
        
        printf("%lf\n", abs(summary));
        summary = summary / K;
        return (summary) < delta_zero;
}