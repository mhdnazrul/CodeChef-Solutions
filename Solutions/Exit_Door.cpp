// problem link:https://www.codechef.com/START212D/problems/P3BAR
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
    vector<int> v(n);   readV(v);
    int cnt = 0;
    for(int i=n; n>0; i--){
        int idx = find(all(v),i) - v.begin();
        int lf = idx;
        int rt = n-idx-1;
        cnt+=min(lf,rt);
        v.erase(v.begin()+idx);
        n--;
    }
    cout<<cnt<<nl;
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