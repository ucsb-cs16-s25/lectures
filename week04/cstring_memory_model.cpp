#include <iostream>
using namespace std;

int main()
{
    // Define a separator line
    string LINE = "\n" + string(25, '=') + "\n\n";

    // Ensure arrays have enough space for null termination
    char str1[5] = "ABCD";   // 5 bytes to include null terminator safely
    char str2[3] = "EF";  // 3 bytes
    char str3[4] = "IJK"; // 4 bytes

    // Print memory addresses of the strings
    cout << "str1: " << (void *)str1 << " Value: " << str1 << endl;
    cout << "str2: " << (void *)str2 << " Value: " << str2 << endl;
    cout << "str3: " << (void *)str3 << " Value: " << str3 << endl;

    // Pointer manipulation
    char *moving = str2; // Pointer to `str2`

    cout << (void *)moving << " The value is " << moving << endl;

    moving -= 2;
    cout << (void *)moving << " The value is " << moving << endl;

    moving += 6;
    cout << (void *)moving << " The value is " << moving << endl;

    return 0;
}
