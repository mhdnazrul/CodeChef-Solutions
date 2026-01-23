/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: http://codechef.com/practice/course/strings/STRINGS/problems/PALINDRCHECK
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;       using ld=long double;
using vi=vector<int>;     using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const ll INF = 2e18;   const int MOD = 1e9 + 7; 
#define per(i,a,b)  for(int i=(b)-1;i>=(a);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define trav(a, x)     for (auto &a : x)
#define forr(i, n)       rep(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define rall(x) rbegin(x),rend(x)
#define sz(x) (int)(x).size()
const char nl = '\n';
template<class T>    void inV(vector<T> &v){for(auto &x:v) cin>>x;}
template<typename T> void outV(const vector<T>& v) {if (v.empty()) return;
    for (int i = 0; i < sz(v); ++i)cout << v[i] << " \n"[i == sz(v) - 1];}


void run_case() {
    string s;    getline(cin, s);
    int n = s.size();
    reverse(all(s));

    int i = 0;
    for (int j = 0; j <= n; j++) {
        if (j == n || s[j] == ' ') {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }

    int idx = 0;
    i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        while (i < n && s[i] != ' ')
            s[idx++] = s[i++];

        s[idx++] = ' ';
    }

    if (idx > 0) idx--;
    s.resize(idx);

    cout << s << nl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    //if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}

/* 
for class soluton ==>

string reverseWords(string s) {
    int n = s.size();

    reverse(s.begin(), s.end());

    int i = 0;
    for (int j = 0; j <= n; j++) {
        if (j == n || s[j] == ' ') {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
    }

    int idx = 0;
    i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++;         
        if (i >= n) break;

        while (i < n && s[i] != ' ')
            s[idx++] = s[i++];                    

        s[idx++] = ' ';                           
    }

    if (idx > 0) idx--;                           
    s.resize(idx);

    return s;
}

*/