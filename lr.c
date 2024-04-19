#include <stdio.h>
#include "lr.h"
#define pi 3.14
#define SIZE 10

int factorial(int n) {
if (n == 0 || n == 1) {
return 1;
}
else {
return n * factorial(n - 1);
}
}

double powr(double x, int n) {
double result = 1.0;
int i;

for (i = 0; i < n; i++) {
result *= x;
}
return result;
}

double computeSeriesSum(double x, int n) {
double sum = 0.0;
int sign = 1;
int power = 0;
for (int i = 0; i < n; i++) {
double term = 1.0 * sign * powr(x, power) / factorial(power);
sum = sum + term;
sign = -1 * sign;
power = power + 2;
}
return sum;
}

struct Pair {
int index1;
int index2;
int sum;
};

// Функция Шейкер-сортировки
void shekerSort(double* mass, int count)
{
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (mass[i] > mass[i+1]) // если следующий элемент меньше текущего,
            {             // меняем их местами
                double t = mass[i];
                mass[i] = mass[i+1];
                mass[i+1] = t;
                flag = 1;      // перемещения
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (mass[i-1] > mass[i]) // если предыдущий элемент больше текущего,f
            {            // меняем их местами
                double t = mass[i];
                mass[i] = mass[i-1];
                mass[i-1] = t;
                flag = 1;    // перемещения в этом цикле
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
        if(flag == 0) break;
    }
}

unsigned int reverse_bytes(unsigned int n) {
    unsigned int result = 0;

    for (int i = 0; i < sizeof(n); i++) {
        result = (result << 8) | (n & 0xFF);
        n = n >> 8;
    }

    return result;
}



int lab1(){
float H, R, D, V;

    printf("H= ");
    scanf("%f", &H);

    printf("R= ");
    scanf("%f", &R);

    printf("D= ");
    scanf("%f", &D);

        if (D>=H)
    {
 printf ("ERROR");
 return 1;
  }
        else
    {
    V = (1.0/3.0)*pi*R*R*H-(1.0/3.0)*pi*(R-((R*D)/H))*(R-((R*D)/H))*(H-D);
    printf("V=%f\n", V);
    }
return 0;
}

int lab2(){
    double x;
int n;
printf("Vvedite x: ");
scanf("%lf", &x);
printf("Vvedite N: ");
scanf("%d", &n);

for (int step = 1; step < n+1; step++){
double sum = computeSeriesSum(x, step);
printf("Summa pervih %d elementov ryada: %.4lf\n", step, sum);
}
return 0;
}

int lab3(){
char prev_char, current_char;
int counter = 0;
int in_word = 0;
printf("Enter a stream of characters: ");

prev_char = getchar();
while((current_char = getchar()) != EOF) {
    if(current_char == '\n') {
        break;
    }

    if(current_char == prev_char) {
        if(!in_word) {
            in_word = 1;
            counter++;
        }
    } else {
        in_word = 0;
    }

    prev_char = current_char;
}

printf("Number of words with consecutive identical letters: %d\n", counter);

return 0;
}

int lab4() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (str[i] == str[i + 1]) {
                while (str[i] != ' ' && str[i] != '\0') {
                    printf("%c", str[i]);
                    i++;
                }
                printf(" ");
            } else {
                while (str[i] != ' ' && str[i] != '\0') {
                    i++;
                }   }
        } else {
            i++;   }}
    return 0;
}

int dop4 () {
char str[100];
printf("Enter a string: ");
fgets(str, 100, stdin);
int i = 0;
while (str[i] != '\0') {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
        int count = 1;
        char currentChar = str[i];
        i++;
        while (str[i] == currentChar) {
            count++;
            i++;
        }
        if (count >= 3) {
            i = i - count;
            while (str[i] != ' ' && str[i] != '\0') {
                printf("%c", str[i]);
                i++;
            }
            printf(" ");
        }
    } else {
        i++;
    }
}

return 0;
}


int lab5 ()
{
int arr[10];
int max_sum = 0;
int max_pair_index = 0;
printf("Enter 10 integers:\n");

for (int i = 0; i < 10; i++)
{
    scanf("%d", &arr[i]);
}

for (int i = 1; i < 9; i++)
{
    int sum = arr[i] + arr[i + 1];
    if (sum > max_sum)
    {
        max_sum = sum;
        max_pair_index = i+1;
    }
}

printf("Rezult %d and %d\n", max_pair_index, max_pair_index + 1);

return 0;
}

int dop5()
{
int arr[10];
struct Pair max_pair = {0, 1, 0};
printf("Enter 10 integers:\n");
for (int i = 0; i < 10; i++)
{
    scanf("%d", &arr[i]);
}

for (int i = 1; i < 9; i++)
{
    int sum = arr[i] + arr[i + 1];
    if (sum > max_pair.sum)
    {
        max_pair.index1 = i;
        max_pair.index2 = i + 1;
        max_pair.sum = sum;
    }
}

printf("The pair of adjacent elements with the maximum sum is at indices %d and %d\n", max_pair.index1, max_pair.index2);

return 0;
}

int lab6() {
    int N, K, i, j;

    printf("Enter the size of the array (N K): ");
    scanf("%d %d", &N, &K);

    int arr[N][K];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int even, odd;
    for (j = 0; j < K; j++) {
        even = 0;
        odd = 0;
        for (i = 0; i < N; i++) {
            if (arr[i][j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (even > odd) {
            for (i = 0; i < N; i++) {
                arr[i][j] = 0;
            }
        }
    }
    printf("\nThe modified array is:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int dop6()
{
    double m[SIZE];
    // Вводим элементы массива
    for (int i = 0; i < SIZE; i++)
    {
        printf("m[%d]=", i);
        scanf("%lf", &m[i]);
    }
    shekerSort(m, SIZE); // вызываем функцию сортировки
    // Выводим отсортированные элементы массива
    for (int i = 0; i < SIZE; i++)
        printf("%.2lf ", m[i]);
    getchar(); getchar();
    return 0;
}

int lab7() {
    unsigned int N;
    printf("Enter a long number ");
    scanf("%f", &N);
    unsigned int reversed_N = reverse_bytes(N);

    printf("A number with mirrored bytes: %u\n", reversed_N);

    return 0;
}
