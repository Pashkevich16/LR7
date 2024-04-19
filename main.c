#include <stdio.h>
#include "lr.h"
#define pi 3.14
#define SIZE 10
int main()
{
    int c;
    scanf("%d", &c);
    switch(c){
    case 1: return lab1();
    case 2: return lab2();
    case 3: return lab3();
    case 4: return lab4();
    case 5: return dop4();
    case 6: return lab5();
    case 7: return dop5();
    case 8: return lab6();
    case 9: return dop6();
    case 10: return lab7();
    }
    return 0;
}
