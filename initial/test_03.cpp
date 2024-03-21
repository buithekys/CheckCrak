#include <iostream>
#include <cmath>
using namespace std;

double P3(int e2)
{

    if (e2 < 0 || e2 > 99)
        return -99;

    double P[10] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i;

    if (e2 >= 0 && e2 <= 9) // Nếu e2 là số có một chữ số
    {
        i = e2;
    }
    else if (e2 >= 10 && e2 <= 99) // Nếu e2 là số có hai chữ số
    {
        i = (e2 / 10) + (e2 % 10); // Tính tổng của 2 chữ số
        i = i % 10;                // Lấy số hàng đơn vị của giá trị tổng
    }

    return P[i];
}

int main()
{
    cout << P3(39);
    return 0;
}