// ! Date :- 14-06-2023

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
#define pll pair<ll, ll>
// #define LOCAL

struct Node
{
    ll val;
    Node *next;
    Node(ll x) : val(x) {}
};

class Solutions
{
    void printJosephus1(Node *curr)
    {
        // skip curr and print next
        cout << curr->next->val << ' ';
        if (curr == curr->next)
            return;
        // remove curr->next element
        curr->next = curr->next->next;

        printJosephus1(curr->next);
    }

public:
    /*
    Using 2 sets
    */
    void sol1(ll x)
    {
        set<ll> nums1, nums2;
        for (ll i = 1; i <= x; i++)
            nums1.insert(i);

        bool flag = true;
        while (nums1.size())
        {

            for (auto it = nums1.begin(); it != nums1.end(); it++)
            {
                if (flag)
                    nums2.insert(*it);
                else
                    cout << *it << " ";
                flag = !flag;
            }
            nums1.clear();
            swap(nums1, nums2);
        }
    }
    /*
    Using Circular Linked List
    */
    void sol2(ll x)
    {
        // create circular linked List
        Node *head = new Node(1);
        Node *curr = head;
        for (ll val = 2; val <= x; ++val)
        {
            curr->next = new Node(val);
            curr = curr->next;
        }
        curr->next = head;

        printJosephus1(head);
    }
};

int main()
{
#ifdef LOCAL
    freopen(".././00-input-output/input.txt", "r", stdin);
    freopen(".././00-input-output/output.txt", "w", stdout);
#endif

    ll x;
    cin >> x;
    Solutions solution;
    // solution.sol1(x);
    solution.sol2(x);
    return 0;
}