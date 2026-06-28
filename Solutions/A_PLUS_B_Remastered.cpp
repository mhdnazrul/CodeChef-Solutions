/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://www.codechef.com/problems/APLUSB
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

void run_case(){
    int n;  cin>>n;
    vi a(n),b(n);
    int mxA=INT_MIN,mnA=INT_MAX,mxB=INT_MIN,mnB=INT_MAX;
    rep(i,0,n){
        cin>>a[i];
        if(a[i]>mxA)mxA=a[i];
        if(a[i]<mnA)mnA=a[i];
    }
    rep(i,0,n){
        cin>>b[i];
        if(b[i]>mxB)mxB=b[i];
        if(b[i]<mnB)mnB=b[i];
    }
    if(mxA+mnB != mxB+ mnA){
        cout<<"-1\n";
        return;
    }

    int sum = mxA+mnB;
    sort(all(a));
    sort(rall(b));
    rep(i,0,n){
        if(a[i]+b[i]!=sum){
            cout<<"-1\n";
            return;
        }
    }
    outV(a);
    outV(b);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}

