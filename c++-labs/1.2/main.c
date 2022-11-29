#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    /*Входные данные*/
    float a,b;
    int n;
    /*Выходные данные*/
    float x,y;
    /*Промежуточные данные*/
    int i;
    float step;

    printf("Type the number of values: \n");
    scanf("%d", &n);
    printf("Type the start of the line: \n");
    scanf("%f", &a);
    printf("Type end of the line: \n");
    scanf("%f", &b);

    step=(b - a)/n;
    printf("The step of calculating values:%f\n", step);

    x=a;
    i=0;

    printf("n      x         y\n");
    while (x <= b) {
        y = logf(sqrtf(M_PI + fabsf(2 - x))) / (3-(1/x)) + (expf(logf(powf(x, 2))/3) * sinf((1/4) * x));
        printf("%d     %f     %f\n", i, x, y);
        x = x + step;
        i++;
    }

    return 0;
}
