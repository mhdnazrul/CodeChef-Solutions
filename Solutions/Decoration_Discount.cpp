/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://www.codechef.com/problems/DECDISC
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;      using ld=long double;
using vi=vector<int>;    using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
constexpr ll INF=4e18;   constexpr int MOD=1e9+7;
const char nl='\n';
#define sz(x) (int)(x.size())
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
template<class T> void in(T &x){cin>>x;}
template<class T> void inV(vector<T> &v){for(auto &x:v) cin>>x;}
template<class T> void out(const T &x){cout<<x<<'\n';}
template<class T> void outV(const vector<T> &v){for(int i=0;i<(int)v.size();i++) cout<<v[i]<<(i+1<(int)v.size()?' ':'\n');}

void run_case(){
 int n;
 cin >> n;
 vi a(n);
 for (int i = 0; i < n; ++i)
  cin >> a[i];

 int min_val = INT_MAX;
 for (int i = 0; i < n; ++i)
 {
  for (int j = 0; j < n; ++j)
  {
   if (i == j)
    continue;
   int cost;
   if (j == i + 1)
   {
    cost = a[i] + a[j] / 2;
   }
   else
   {
    cost = a[i] + a[j];
   }
   min_val = min(min_val, cost);
  }
 }

 cout << min_val << endl;
}

int32_t main(){
    fastio();      int T=1; 
    if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}
