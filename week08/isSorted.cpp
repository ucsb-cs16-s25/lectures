#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if a vector is sorted in non-decreasing order
bool isSorted(const vector<int> &vec, int index = 0)
{
    // Base case: if we've reached the end or there's only one element left to check
    if (index >= vec.size() - 1)
        return true;

    // If the current element is less than the next, continue checking
    if (vec[index] < vec[index + 1])
        return isSorted(vec, index + 1);

    // If any element is greater than the next, the vector is not sorted
    else
        return false;
}

int main()
{
    vector<int> vec = {2, 3, 41, 10, 40};
    cout << boolalpha << isSorted(vec) << endl;

    return 0;
}
