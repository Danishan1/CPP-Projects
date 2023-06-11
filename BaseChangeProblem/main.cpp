#include "oct.hpp"
#include "enDecrepit.hpp"

/**
 * 1. This Code works fine upto base 10
 * 2. Small Number (upto 8 Digits)
 * 3. Must Specify the base in Argument
 * 4. As base decreases must give smaller Number
 *
 * Future
 * 1. Implementing this using String for performing on Large Number
 * 2. implementing upto  base 20
 * 3. Basic operator Overload
 *
 */

int main()
{
    B_2to10 a = B_2to10(8);
    B_2to10 b = B_2to10(8);
    B_2to10 c = B_2to10(8);

    a = 25;
    b = 98765432;
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