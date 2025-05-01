#include <iostream>
using namespace std;
// Function that modifies three variables through different types of parameters
void modify(int *a, int &b, int c)
{
    *a += 10; // Dereferences pointer `a` and adds 10 to the value it points to
    b += 10;  // Adds 10 to reference `b` (modifies original variable directly)
    c += 10;  // Adds 10 to `c` (passed by value — modification is local only)
}

int main()
{
    int x = 4;   // Declare integer variable x and initialize to 4
    int *p = &x; // Pointer `p` points to the address of `x`

    // Call modify:
    // a → pointer to x (p),
    // b → reference to x (*p),
    // c → value of x (*p again, which is 4 at the time of call)
    modify(p, *p, *p);

    // Let's trace what happens inside `modify`:
    // 1. *a += 10 → x becomes 14
    // 2. b += 10 → x becomes 24 (because b is also x)
    // 3. c += 10 → does not affect x (c is passed by value)

    cout << "x: " << x << endl; // Output the final value of x → "x: 24"
    return 0;
}