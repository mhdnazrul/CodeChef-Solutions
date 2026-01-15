/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7
  │                        >   Author:- Nazrul Islam
  │Problem Link: https://www.codechef.com/practice/course/basic-programming-concepts/DIFF500/problems/KITCHENTIME
  └────────────────────────────────────────────────────────────────────────────────────┘*/

#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const ll mod = 1e9 + 7;

void solve()
{
  int x, n;
  cin >> x >> n;
  cout << n - x << endl;
}

int main()
{
  FAST_IO;
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}