// problem link:https://www.codechef.com/START212D/problems/P4BAR
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    int n;  cin>>n;
    string s;   cin>>s;
    int cnt_00 = 0, cnt_11 = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0') cnt_00++;
        if (s[i] == '1' && s[i + 1] == '1') cnt_11++;
    }
    int dif = max(0,cnt_00-cnt_11);
    cout<<(dif+1)/2<<nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}