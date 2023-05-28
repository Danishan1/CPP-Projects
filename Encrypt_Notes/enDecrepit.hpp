#ifndef ENCRIPT
#define ENCRIPT

#include <bits/stdc++.h>
using namespace std;
class encript
{
    map<int, char> lower;
    map<int, char> upper;
    map<int, char> num;
    map<int, char> special;

public:
    void init();
    encript(string str);
};

#endif