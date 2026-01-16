/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/EXAMTIME
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
    int a,b,c,x,y,z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int Dragon = a + b + c;
    int Sloth  = x + y + z;

    if(Dragon == Sloth){
        if(a == x && b == y && c == z){
            cout << "TIE\n";
            return; 
        }
        if(a == x){
            if(b == y){
                if(c > z) cout << "DRAGON\n";
                else cout << "SLOTH\n";
            }
            else if(b > y) cout << "DRAGON\n";
            else cout << "SLOTH\n";
        }
        else if(a > x) cout << "DRAGON\n";
        else cout << "SLOTH\n";

        return;
    }

    if(Dragon > Sloth) cout << "DRAGON\n";
    else cout << "SLOTH\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}

