#ifndef OCT
#define OCT

#include <bits/stdc++.h>
using namespace std;

class octadec
{
#define N 10
    int a, base = 10;
    string weight[N] = {};
    octadec intToOct(int t1);
    int octToInt(octadec t1);
    void assignBase();

public:
    octadec()
    {
        a = 0;
        weight[1] = base;
        for (int i = 2; i < N; i++)
        {
            weight[i] = stoi(weight[i - 1]) * base;
        }
    }

    void print();
    octadec operator=(int t1);
    friend octadec operator+(octadec t1, octadec t2);
};

#endif

octadec octadec::intToOct(int t1)
{
    octadec t2;
    string s1 = "";
    while (t1)
    {

        s1 = to_string(t1 % 8) + s1;
        t1 = t1 / 8;
    }
    t2.a = stoi(s1);
    return t2;
}

int octadec::octToInt(octadec t1)
{
}

void octadec::print()
{
    cout << a << " ";
}

octadec octadec::operator=(int t1)
{
    *this = intToOct(t1);
    return *this;
}

octadec operator+(octadec t1, octadec t2)
{
    octadec t3;
    t3.a = t1.a + t2.a;
    // octadec t2;
    string s1 = "";
    // while (t1)
    // {

    //     s1 = to_string(t1 % 8) + s1;
    //     t1 = t1 / 8;
    // }
    t2.a = stoi(s1);
    return t3;
}