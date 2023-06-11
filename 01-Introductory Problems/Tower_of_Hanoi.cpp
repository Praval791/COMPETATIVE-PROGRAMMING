// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void util(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        cout << from << ' ' << to << endl;
        return;
    }
    util(n - 1, from, aux, to);
    util(1, from, to, aux);
    util(n - 1, aux, to, from);
}

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    util(n, 1, 3, 2);
    return 0;
}