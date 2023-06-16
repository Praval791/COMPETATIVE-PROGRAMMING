// ! Date :- 16-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
// #define LOCAL

typedef array<ll, 3> times;

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    vector<times> customers(n);
    vector<ll> roomAllocation(n);

    for (int i = 0; i < n; i++)
    {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }
    sort(customers.begin(), customers.end());

    ll maxRooms = 0;
    // departureTime, roomId
    set<pair<ll, ll>> rooms;

    for (auto times : customers)
    {
        ll arrivalTime = times[0];
        ll departureTime = times[1];
        ll customerId = times[2];

        auto it = rooms.begin();
        if (it == rooms.end() or it->first >= arrivalTime) // no room available
        {
            maxRooms++;
            rooms.insert({departureTime, maxRooms});

            roomAllocation[customerId] = maxRooms;
        }
        else
        {
            ll roomId = (*it).second;
            rooms.erase(it);
            rooms.insert({departureTime, roomId});
            roomAllocation[customerId] = roomId;
        }
    }
    cout << maxRooms << endl;
    for (auto i : roomAllocation)
        cout << i << " ";
    return 0;
}