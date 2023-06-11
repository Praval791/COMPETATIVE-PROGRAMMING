// ! Date :- 11-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // freopen(".././00-input-output/input.txt", "r", stdin);
    // freopen(".././00-input-output/output.txt", "w", stdout);
    ll q;
    cin >> q;
    // powers of 10
    vector<ll> powers(19, 1);
    for (int i = 1; i < 19; ++i)
        powers[i] = powers[i - 1] * 10;

    while (q--)
    {
        ll k;
        cin >> k;

        /*
        first find the number of digits in the number that contains the kth digit
        */
        ll digitsInNum = 1;
        // count of total digits of numbers encountered so far
        ll totaldigits = 0;
        ll previousTotalDigits = 0;
        for (int i = 1; i < 19; ++i)
        {
            // count of numbers that have i digits
            ll numberOfDigitsI = powers[i] - powers[i - 1];
            totaldigits += numberOfDigitsI * i;

            if (totaldigits >= k)
            {
                digitsInNum = i;
                break;
            }
            previousTotalDigits = totaldigits;
        }

        /*
        Now find the number that contains the kth digit
        */
        ll startingNumber = powers[digitsInNum - 1];
        ll low = powers[digitsInNum - 1];
        ll high = powers[digitsInNum] - 1;
        string number;
        ll startPosOfNumber = -1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            ll startingPosOfMid = previousTotalDigits + (mid - startingNumber) * digitsInNum + 1;
            ll endingPosOfMid = startingPosOfMid + digitsInNum - 1;
            if (startingPosOfMid <= k && k <= endingPosOfMid)
            {
                number = to_string(mid);
                startPosOfNumber = startingPosOfMid;
                break;
            }
            else if (k < startingPosOfMid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        cout << number[k - startPosOfNumber] << endl;
    }
    return 0;
}