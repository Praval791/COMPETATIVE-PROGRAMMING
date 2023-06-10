#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    cout << n << ' ';
    while (n != 1)
        cout << (n = (n & 1) ? n * 3 + 1 : n / 2) << ' ';

    cout << endl;
    return 0;
}