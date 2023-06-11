#include "oct.hpp"
#include "enDecrepit.hpp"

int main()
{
    octadec a = octadec(8);
    octadec b = octadec(8);
    octadec c = octadec(8);

    a = 25;
    b = 50000;
    c = 0;
    // c = a*b;
    cout << a.octToInt(a);
    cout << b.octToInt(b);
    cout << c.octToInt(c);

    // a.print();
    // b.print();
    // c.print();

    // encript e("s");
    // e.init();

    return 0;
}