#include "folderA.hpp"
#include <iostream>

using namespace std;

void Aa::fun()
{
    cout << "A";
}

int main()
{
    Aa a;
    a.fun();
}