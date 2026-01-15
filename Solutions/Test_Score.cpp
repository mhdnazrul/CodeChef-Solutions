/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7
  │                        >   Author:- Nazrul Islam
  │Problem Link:https://www.codechef.com/practice/course/logical-problems/DIFF800/problems/CHEFSCORE
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO               \
 ios::sync_with_stdio(false); \
 cin.tie(nullptr);
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const ll mod = 1e9 + 7;

void solve()
{
 int n, x, y, i, tp, cnt = 0, ans = 0;
 cin >> n >> x >> y;
 bool flag = false;
 for (i = 0; i <= n; i++)
 {
  tp = i * x;
  if (tp == y)
  {
   flag = true;
   break;
  }
 }
 cout << (flag ? "YES\n" : "NO\n");
}

int main()
{
 FAST_IO;
 int T;
 cin >> T;
 while (T--)
  solve();
 return 0;
}