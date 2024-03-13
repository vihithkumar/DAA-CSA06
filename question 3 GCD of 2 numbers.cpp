#include <stdio.h>  
#include <conio.h>  
int GCD_Rec(int num1, int num2);  
int main()  
{  
    int num1, num2;  
    printf( " Enter any two positive numbers:  ");  
    scanf("%d %d", &num1, &num2);  
    printf(" GCD of two numbers %d and %d is %d", num1, num2, GCD_Rec(num1, num2));  
    return 0;  
}  
int GCD_Rec(int num1, int num2)  
{  
    if (num2 != 0)  
    {  
        return GCD_Rec( num2, num1 % num2);  
    }  
    else  
    {  
        return num1;  
    }  
}  
