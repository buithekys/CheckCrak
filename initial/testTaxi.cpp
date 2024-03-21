#include <iostream>
#include <cmath>
using namespace std;

int find_matrix(int matrix[10][10], int i, int j)
{
    int max_value = matrix[i][j];

    // Đường chéo trái
    int x = i - 1;
    int y = j - 1;
    while (x >= 0 && y >= 0)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        --x;
        --y;
    }

    x = i + 1;
    y = j + 1;
    while (x < 10 && y < 10)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        ++x;
        ++y;
    }

    // Đường chéo phải
    x = i - 1;
    y = j + 1;
    while (x >= 0 && y < 10)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        --x;
        ++y;
    }

    x = i + 1;
    y = j - 1;
    while (x < 10 && y >= 0)
    {
        if (matrix[x][y] > max_value)
        {
            max_value = matrix[x][y];
        }
        ++x;
        --y;
    }

    return max_value;
}

int count_A_(int matrix[10][10], int E3)
{
    int count_A = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (matrix[i][j] < -E3)
                count_A++;
        }
    }
    return count_A;
}

int count_D_(int matrix[10][10], int E3)
{
    int count_D = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            if (matrix[i][j] > 2 * E3)
                count_D++;
        }
    }
    return count_D;
}

int process(int a)
{
    if (a >= 0 && a < 10)
    {
        return a;
    }

    else if (a >= 10 && a < 100)
    {
        while (a >= 10)
        {
            int sum = 0;
            while (a != 0)
            {
                sum += a % 10;
                a /= 10;
            }

            a = sum;
        }
    }
    return a;
}
int main()
{
    int arr[10][10] = {0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((59 * j) + (i * 2)) * (i - j);
        }
    }
#if 0 
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
#endif

    int count_D = count_D_(arr, 59);
    int count_A = count_A_(arr, 59);

    cout << "Positive Counts: " << count_D << " "
         << ", Negative counts: " << count_A;

    int i = process(count_D);
    int j = process(count_A);

    cout << endl;
    //      << "Value at i_j: " << arr[i][j];
    int taxiScore = arr[i][j];
    int scoreSW = find_matrix(arr, i, j);
    cout << scoreSW;

    if(abs(taxiScore) > scoreSW)
    {
        
    }

    return 0;
}