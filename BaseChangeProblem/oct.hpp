#ifndef OCT
#define OCT

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define N 10

class B_2to10
{
public:
    long long a;
    static bool flag;
    static int base;
    static string weight[N];
    B_2to10 intToOct(int t1);
    int octToInt(B_2to10 t1);
    void assignBase();

    B_2to10(int base)
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

    B_2to10 operator=(int t1);
    friend int operator%(B_2to10 t1, int t2);
    friend int operator/(B_2to10 t1, int t2);

    // friend B_2to10 operator+(B_2to10 t1, B_2to10 t2);
    // friend B_2to10 operator-(B_2to10 t1, B_2to10 t2);
    // friend B_2to10 operator*(B_2to10 t1, B_2to10 t2);
    // friend B_2to10 operator/(B_2to10 t1, B_2to10 t2);
    friend B_2to10 operator%(B_2to10 t1, B_2to10 t2);
};

string B_2to10::weight[N] = {};
int B_2to10::base;
bool B_2to10::flag = 0;

inline void B_2to10::assignBase()
{
}

// Converting base 10 to Any Given Base
B_2to10 B_2to10::intToOct(int t1)
{
    B_2to10 t2 = B_2to10(base);
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

// Converting Any base into 10
int B_2to10::octToInt(B_2to10 t1)
{
    string s = "0";
    int lnt = t1.len();

    if (lnt < N)
    {
        for (auto i : t1.weight)
        {
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
    }
    return -1;
}

void B_2to10::print()
{
    cout << a << " ";
}

int B_2to10::len()
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

B_2to10 B_2to10::operator=(int t1)
{
    *this = intToOct(t1);
    return *this;
}

int operator%(B_2to10 t1, int t2)
{
    if (t2 == 10)
        return t1.a % t2;
    return 1;
}
int operator/(B_2to10 t1, int t2)
{
    if (t2 == 10)
        return t1.a / t2;
    return 1;
}

// B_2to10 operator+(B_2to10 t1, B_2to10 t2)
// {
//     B_2to10 t3;
//     t3.a = t1.a + t2.a;
//     // B_2to10 t2;
//     string s1 = "";
//     // while (t1)
//     // {

//     //     s1 = to_string(t1 % base) + s1;
//     //     t1 = t1 / base;
//     // }
//     // t2.a = stoi(s1);
//     return t3;
// }

#endif
