#ifndef OCT
#define OCT

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define N 10

class octadec
{
public:
    int a;
    static bool flag;
    static int base;
    static string weight[N];
    octadec intToOct(int t1);
    int octToInt(octadec t1);
    void assignBase();

    octadec(int base)
    {
        this->base = base;
        a = 0;
        weight[0] = "1";
        weight[1] = to_string(this->base);

        if (flag == 0) // for not repeating weight[] to each object 
        {
            flag = 1;
            for (int i = 2; i < N; i++)
            {
                string s = weight[i - 1];
                weight[i] = to_string(stoi(s) * this->base);
            }
        }
    }

    void print();
    int len();

    octadec operator=(int t1);
    friend int operator%(octadec t1, int t2);
    friend int operator/(octadec t1, int t2);

    // friend octadec operator+(octadec t1, octadec t2);
    // friend octadec operator-(octadec t1, octadec t2);
    // friend octadec operator*(octadec t1, octadec t2);
    // friend octadec operator/(octadec t1, octadec t2);
    friend octadec operator%(octadec t1, octadec t2);
};

string octadec::weight[N] = {};
int octadec::base;
bool octadec::flag = 0;

inline void octadec::assignBase()
{
}

// Converting base 10 to Any Given Base
octadec octadec::intToOct(int t1)
{
    octadec t2 = octadec(base);
    string s1 = "";
    if (t1 == 0)
    {
        return t2;
    }
    while (t1)
    {

        s1 = to_string(t1 % base) + s1;
        t1 = t1 / base;
    }
    t2.a = stoi(s1);
    return t2;
}

int octadec::octToInt(octadec t1)
{
    string s = "0";
    int lnt = t1.len();
   
    if (lnt < N)
    {
        for (auto i : t1.weight)
        {
            // if (t1.a == 0)

            s = to_string((t1.a % 10) * stoi(i) + stoi(s));
            t1.a = t1.a / 10;
            lnt--;
            if (lnt <= 0)
                return stoi(s);
        }
    }
    else
    {
        cout << "Digits are greater than 10";
        //
    }
    return 4;
}

void octadec::print()
{
    cout << a << " ";
}

int octadec::len()
{
    int i1 = a, i2 = 0;
    // if (i1 != 0)
    while (i1)
    {
        i2++;
        i1 = i1 / 10;
    }
    return i2;
}

octadec octadec::operator=(int t1)
{
    *this = intToOct(t1);
    return *this;
}

int operator%(octadec t1, int t2)
{
    if (t2 == 10)
        return t1.a % t2;
    return 1;
}
int operator/(octadec t1, int t2)
{
    if (t2 == 10)
        return t1.a / t2;
    return 1;
}

// octadec operator+(octadec t1, octadec t2)
// {
//     octadec t3;
//     t3.a = t1.a + t2.a;
//     // octadec t2;
//     string s1 = "";
//     // while (t1)
//     // {

//     //     s1 = to_string(t1 % 8) + s1;
//     //     t1 = t1 / 8;
//     // }
//     // t2.a = stoi(s1);
//     return t3;
// }

#endif
