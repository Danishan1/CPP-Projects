#include "oct.hpp"
#include "enDecrepit.hpp"

int main()
{
    octadec a = octadec(8);
    octadec b = octadec(8);
    octadec c = octadec(8);

    a = 25;
    b = 500;
    c = 0;
    // c = a*b;
    cout << a.octToInt(a) << "\n";
    cout << b.octToInt(b) << "\n";
    cout << c.octToInt(c) << "\n";

    a.print();
    // b.print();
    // c.print();

    // encript e("s");
    // e.init();

    return 0;
}