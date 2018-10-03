#include <stdio.h>
#include <stdlib.h>
const int NPoints = 100;

int ReadData (double voltage[], double ecurrent[]);
int CalculateLaba (double voltage[], double ecurrent[], int n);




int main ()
{
    double voltage[NPoints] = {}, ecurrent[NPoints] ={};
    int line;
    line = ReadData (voltage,ecurrent);
    CalculateLaba (voltage, ecurrent, line);
    return 0;
}


int ReadData (double voltage[], double ecurrent[])
{
    FILE *laba = fopen ("laba.txt", "r");
    if (!laba)
    {
        printf ("Не удалось открыть файл laba.txt\n");
        return -1;
    }
    int n = 0;
    for (;;)
    {
        if (fscanf (laba, "%lg %lg", &voltage[n], &ecurrent[n]) == EOF)
            break;
        n++;
    }
    fclose (laba);
    return n;
}

int CalculateLaba (double voltage[], double ecurrent[], int n)
{
    FILE *result = fopen ("result.txt", "w");
    if (!result)
    {
        printf ("Не удалось открыть/создать файл result.txt\n");
        return -1;
    }
    for (int i = 0;;)
    {
        if (i == n) break;
        fprintf (result, "%.4lg Ohm\n", voltage[i] / ecurrent[i]);
        i++;
    }
    fclose(result);
    return 0;
}
    
