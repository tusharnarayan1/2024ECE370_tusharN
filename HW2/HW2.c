#include <stdio.h>
#include <math.h>
#define PI 3.14159

float q1circleArea(float radius)
{
    float area = PI * radius * radius;
    return area;
}

void q2time(int totalSeconds,int * seconds, int * minutes, int * hours)
{
    *seconds =  totalSeconds % 60;
    *minutes = ((totalSeconds/60)) % 60;
    *hours = totalSeconds/3600;
}

void q3bitwiseOperations(int a,int b,int * and, int * or, int * xor)
{
     *and = a & b;
      *or = a | b;
      *xor = a ^ b;

}

int main()
{

    // Question 1 
    float radius;
    float area;
    
    
    printf("\nEnter a circle's radius: ");
    scanf("%f",&radius);
    area = q1circleArea(radius);
    printf("\nYour circle's radius is: %f \n", area);

    // Question 2
    int seconds,minutes,hours,totalSeconds;

    printf("\nEnter a time (in seconds): ");
    scanf("%d",&totalSeconds);
    q2time(totalSeconds,&seconds,&minutes,&hours);
    printf("\n Hours:%d Minutes:%d Seconds:%d\n",hours,minutes,seconds);

    // Question 3
    int a,b,andResult,orResult,xorResult;
    printf("\nEnter an integer: ");
    scanf("%d",&a);
    printf("\nEnter another integer to perform bitwise operations with: ");
    scanf("%d",&b);
    q3bitwiseOperations(a,b,&andResult,&orResult,&xorResult);
    printf("\n And:%d Or:%d Xor:%d \n", andResult,orResult,xorResult);
    return 0;
}