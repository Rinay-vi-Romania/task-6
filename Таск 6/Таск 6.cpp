#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;
int** fill(int n, int m);
int** fill2(int n, int m);
void print(int** arr, int n, int m);
void print2(int** arr, int** brr, int n, int m);
void contraction(int** arr, int** brr, int n, int m);
void null(int** arr, int n, int m);
void output(int** brr, int n, int m);
int** fill(int n, int m)
{
    int** arr = new int* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    return arr;
}
int** fill2(int n, int m)
{
    int** brr = new int* [n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        brr[i] = new int[m - 1];
    }
    return brr;
}
void print(int** arr, int n, int m)
{

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 11;
            cout << arr[i][j] << "\t";
        }
        cout << endl;

    }
}
void print2(int** arr, int n, int m)
{

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 11;
            cout << arr[i][j] << "\t";
        }
        cout << endl;

    }
}
void null(int** arr, int n, int m) // Эта функция заполняет случаейные строку и столбец нулями, чтобы их я позже смог удалить и уплотнить матрицу.
{
    srand(time(NULL));
    int x = rand() % (n);
    int y = rand() % (m);
    for (int i = 0; i < m; i++)
    {
        arr[x][i] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        arr[j][y] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;

    }
}
void contraction(int** arr, int** brr, int n, int m)
{
    int k = 0;
    int r = 0;
    int q = 0;
    int w = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {


            if (arr[i][j] == 0 && k != m)
            {
                q = i;
                w = j;
                while (k != m)
                {



                    if (arr[q][j] == 0)

                    {
                        j += 1;
                        k++;

                    }

                    else
                    {
                        q += 1;
                        k = 0;
                        j = 0;
                    }


                }
                while (r != n)
                {



                    if (arr[i][w] == 0)

                    {
                        i += 1;
                        r++;

                    }

                    else
                    {
                        w += 1;
                        r = 0;
                        i = 0;
                    }


                }
            }

        }


    }
    for (int i = q; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)

        {
            arr[i][j] = arr[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = w; j < m - 1; j++)

        {
            arr[i][j] = arr[i][j + 1];
        }
    }

}
void print2(int** arr, int** brr, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
            brr[i][j] = arr[i][j];


    }
}
void output(int** brr, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cout << brr[i][j] << "\t";
        }
        cout << endl;

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    while (n < 0 || n == 0)
    {
        cout << "Введите размер столбцов (больше нуля)" << endl;
        cin >> n;
    }
    int m = 0;
    while (m < 0 || m == 0)
    {
        cout << "Введите количество столбцов (больше нуля)" << endl;
        cin >> m;
    }
    cout << "\n";
    int** arr;
    int** brr;
    arr = fill(n, m);
    brr = fill2(n, m);
    cout << "Создаем двумерную матрицу случайного размера и наполняем ее случайными числами.." << endl;
    cout << "\n";
    print(arr, n, m);
    cout << "\n";
    cout<< "Добавляем в матрицу случайные нулевые столбец и строку, чтобы потом их сократить.." << endl;
    cout << "\n";
    null(arr, n, m);
    contraction(arr, brr, n, m);
    print2(arr, brr, n, m);
    cout << "\n";
    cout << "Уплотненная матрица:" << endl;
    cout << "\n";
    output(brr, n, m);

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    for (int i = 0; i < n - 1; i++)
    {
        delete[] brr[i];
    }
    delete[] brr;
    _getch();
    return 0;
}