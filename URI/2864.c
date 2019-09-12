#include <stdio.h>
#include <math.h>

int main(){


    int t;
    float a,b,c;

    scanf("%d", &t);

    while(t--){

        scanf("%f %f %f", &a, &b, &c);

        float x = -b / (a*2);
        float y = (a*pow(x,2)) + b*x + c;
        printf("%.2f\n", y);

    }

}
