#include <iostream>
using namespace std;

main()
{
    int m = 20;
    int *p = &m;
    int &r = m;
    r++;
    int *q = p + 1;
    int n = (*p)++;
    n *= 5;
    cout << m << ", " << &m  << ", " << n << endl;
    cout << *p << ", " << r << ", " << q << endl;
}
