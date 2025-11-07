// problem link:https://www.codechef.com/problems/VALIDSTK
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
void solve()
{
 int n, cnt = 0;
 cin >> n;
 vector<int> v(n);
 for (int &i : v)
  cin >> i;

 for (int &i : v)
 {
  if (i == 1)
   cnt++;
  else
  {
   if (cnt == 0)
   {
    cout << "Invalid\n";
    return;
   }
   else
    cnt--;
  }
 }
 cout << "Valid\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}