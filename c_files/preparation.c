#include "../h_files/preparation.h"

int preparation(float resistance[])
{
    float voltage[100]={};
    float current[100]={}; 
    float voltagei = 0;
    float currenti = 0;
    unsigned short m = 0;

    while ((scanf("%f%f",&voltagei,&currenti)) == 2)
    {
        voltage[m] = voltagei;
        current[m] = (currenti / 1000);
        resistance[m] = (voltage[m] / current[m]);
        m++;
    }

    return m;
}