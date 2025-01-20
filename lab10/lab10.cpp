#include <iostream>
using namespace std;

void pack(int n, int *a, int *b)//создаем массив, где индекс это число, а значение ячейки - количество повторений этого числа
{
    for (int i = 0;i < 18;i++) b[i] = 0;
    for (int i = 0; i < n; i++) b[a[i]]++;
}

void unpack(int n, int *a, int *b)
{
    int k = 0;
    for (int i = 0; i < 18; i++)
        for (int l = 0; l < b[i];l++)
        {
            a[k] = i;
            k++;
        }
}

int main()
{
    const int n = 1500;
    int a[n];
    int b[18];
    a[0] = 0;

    for (int i = 1; i < n; i++) 
        if (a[i - 1] < 17) a[i] = a[i - 1] + rand() % 2;
            else a[i] = 17;

    pack(n, a, b);
    for (int i = 0;i < 18;i++) cout << "Чисел " << i << ": " << b[i] << endl;
    unpack(n, a, b);
}