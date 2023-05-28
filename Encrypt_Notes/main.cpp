#include "oct.hpp"
#include "enDecrepit.hpp"

int main()
{
    octadec a, b, c;

    a = 25;
    b = 30 + 20;
    c = a + b;
    // cout << a.a;
    // cout << b.a;
    // a = a + b;

    a.print();
    b.print();
    c.print();
    // encript e("s");
    // e.init();

    return 0;
}