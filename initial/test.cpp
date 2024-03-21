#include <iostream>
#include <cmath>
using namespace std;

void setExp(int &exp)
{
    if (exp > 600)
        exp = 600;
    if (exp < 0)
        exp = 0;
}

void setHP(int &Hp)
{
    if (Hp > 666)
        Hp = 666;
    if (Hp < 0)
        Hp = 0;
}

void setMoney(int &money)
{
    if (money > 3000)
        money = 3000;
    if (money < 0)
        money = 0;
}

// !Không cần set tại mình sẽ set trước khi truyền tham số
void goShopping(int &HP, int &money)
{

    if (HP < 200 && HP > 0)
    {
        HP += (double)HP * 30 / 100 + 0.999;
        money -= 150;
    }

    else if (HP >= 200 && HP <= 666)
    {
        HP += (double)HP * 10 / 100 + 0.999;
        money -= 70;
    }
}

void RentCar(int &exp1, int &money)
{
    if (exp1 < 400 && exp1 >= 0)
    {
        money -= 200;
    }

    else if (exp1 >= 400 && exp1 < 600)
    {
        money -= 120;
    }
    exp1 += (double)exp1 * 13 / 100 + 0.999;
}

void helpHomeless(int &exp1, int &money)
{
    if (exp1 < 300 && exp1 >= 0)
    {
        money -= 100;
    }

    else if (exp1 >= 300 && exp1 < 600)
    {
        money -= 120;
    }

    exp1 = ceil(exp1 - (double)exp1 * 10 / 100);
}

double closestSquare(int exp1)
{
    int S = round(sqrt(exp1));
    S *= S;

    if (exp1 >= S)
    {
        return 1;
    }

    else
    {
        return ((double)exp1 / S + 80) / 123;
    }
}

// Con đường 2
double simulate_02(int E2, int &exp1, int &hp, int &money)
{
    int half = (double)money * 0.5 + 0.999;

    if (E2 % 2 == 1)
    {
        while (money >= half)
        {
            goShopping(hp, money);
            setHP(hp);
            setMoney(money);
            if (money < half)
                break;
            RentCar(exp1, money);
            setExp(exp1);
            setMoney(money);
            if (money < half)
                break;
            helpHomeless(exp1, money);
            setExp(exp1);
            setMoney(money);
            if (money < half)
                break;
        }
    }

    else
    {
        while (money > 0)
        {
            goShopping(hp, money);
            setHP(hp);
            setMoney(money);
            if (money <= 0)
                break;
            RentCar(exp1, money);
            setExp(exp1);
            setMoney(money);
            if (money <= 0)
                break;
            helpHomeless(exp1, money);
            setExp(exp1);
            setMoney(money);
            if (money <= 0)
                break;
        }
    }

    hp = ceil(hp - (double)hp * 17 / 100);
    setHP(hp);
    exp1 += (double)exp1 * 17 / 100 + 0.999;
    setExp(exp1);

    return closestSquare(exp1);
}

int main()
{
    int e = 39, exp = 430, hp = 333, money = 890;
    double P2 = simulate_02(e, exp, hp, money);

    cout << "HP: " << hp << " "
         << "EXP: " << exp << " "
         << "P2: " << P2;

    return 0;
}