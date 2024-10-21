
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int FindMaxOfMinElements(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "Enter number of rows (k): "; cin >> k;
    cout << "Enter number of columns (n): "; cin >> n;

    int Low = 7;
    int High = 65;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

   
    int maxMinElement = FindMaxOfMinElements(a, k, n);
    cout << "Max of the minimum elements = " << maxMinElement << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindMaxOfMinElements(int** a, const int k, const int n)
{
    int maxMin = a[0][0];
    for (int i = 0; i < k; i++)
    {
        int minInRow = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < minInRow)
                minInRow = a[i][j];
        }
        if (minInRow > maxMin)
            maxMin = minInRow;
    }
    return maxMin;
}
