#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
}

int IFirst(int* a, const int size, int& min, int i)
{
    if (a[i] % 2 != 0)
    {
        min = a[i];
        return i;
    }

    if (i < size - 1)
        return IFirst(a, size, min, i + 1);
    else
        return -1;
}

int Min(int* a, const int size, int min, int i)
{
    if (a[i] < min && a[i] % 2 != 0)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, min, i + 1);
    else
        return min;
}

int Find(int* a, const int size, int i)
{
    if (a[i] == Min(a, size, a[0], 0))
        return i;
    if (i < size - 1)
        return Find(a, size, i + 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));

    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    int Low, High;

    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;

    Create(a, n, Low, High, 0);

    cout << "a[" << n << "] = {";
    Print(a, n, 0);
    cout << "}" << endl;

    int min;
    int imin = IFirst(a, n, min, 0);
    if (imin == -1)
        cerr << "немає елементів, які задовольняють умові" << endl;
    else
        cout << "індекс найменшого непарного елемента = " << Find(a, n, 0) << endl;

    return 0;
}
