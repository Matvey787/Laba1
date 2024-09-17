#include <stdio.h>
#include <math.h>
//yee
int main(){
    return 0;
}
// resultat ye
float result(int K,float resistance[])
{
    float resistance_final =0;
    for (int i =0;i<K;i++)
        resistance_final+=resistance[i];
    resistance_final /=K;
    float devivation = 0;
    for (int i=0;i<K;i++)
        devivation+= (resistance[i]-resistance_final)*(resistance[i]-resistance_final);
    devivation = sqrt(devivation)/K;
    printf("%f +- %f",resistance_final,devivation);
    return resistance_final;
}

int preparation(float resistance[])
{
    float voltage[100]={},current[100]={},voltagei=0,currenti=0;
    unsigned short m=0;
    while ((scanf("%f%f",&voltagei,&currenti))==2)
    {
        voltage[m]=voltagei;
        current[m]=currenti;
        resistance[m]=(voltagei/currenti);
        m++;
    }
    return m;
}


int data_select(int M, float resistance[]){
    float summary = 0;
    int eps = 3;
    for (int i = 0; i < M; i++){
        summary += resistance[i];
    }
    float resistance_average = summary / M;

    int K = 0;

    for (int j = 0; j < M; j++){
        if (abs(resistance[i] - resistance_average)/resistance_average <= eps)
            resistance[K++] = resistance[i];
    return K;

}

int check(int K, float resistance[], float resistance_final){
    float delta_zero = 0.001;
    float summary = 0;
    for (int i = 0; i < k; i++)
        summary += resistance[i] - resistance_final;
    return (summary / K) < delta_zero;
}
