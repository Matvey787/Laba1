#include <stdio.h>
#include <math.h>

float result(int K,float resistance[]);
int preparation(float resistance[]);
int data_select(int M, float resistance[]);
int check(int K, float resistance[], float resistance_final);
//yyy
int main(){
float resistance[100] = {};
int M = preparation(resistance);
int K = data_select(M, resistance);
float resistance_final = result(K, resistance);
printf("Resistance final: %lg\n", resistance_final);

return 0;
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
printf("%f +- %f\n",resistance_final,devivation);
return resistance_final;
}

int data_select(int M, float resistance[]){
float summary = 0;
int eps = 3;
for (int i = 0; i < M; i++){
summary += resistance[i];
}
float resistance_average = summary / M;

int K = 0;

for (int i = 0; i < M; i++)
if (abs(resistance[i] - resistance_average)/resistance_average <= eps)
resistance[K++] = resistance[i];
return K;

}

int check(int K, float resistance[], float resistance_final){
float delta_zero = 0.001;
float summary = 0;
for (int i = 0; i < K; i++)
summary += resistance[i] - resistance_final;
printf("%lg\n", summary/K);
return (summary / K) < delta_zero;
}
