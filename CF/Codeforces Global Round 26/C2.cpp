#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 1e6 + 10 ;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ;//全一才位1
const double eps = 1e-9 ;
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a * b / gcd(a,b); } 
int qmi(int a, int b){
    int res = 1 ;
    while(b){
        if(b&1) res = a * res % MOD ;
        b >>= 1 ;
        a = a * a % MOD ;
    }
    return res ;
}
int T = 1 ;
int ans = 0 ;
int n , m, k ;
int a[N] ;
int b[N] ;
int r[N] ;
int inv2 = (MOD - MOD / 2) % MOD ; 
void solve(){
    ans = 0 ;
    cin >> n ;
    int cnt = 0 ;
    map<int,vector<int>> mp;
    int mi = INF ;
    int p = 0 ;
    for(int i = 1 ; i <= n ; ++ i){
        cin >> a[i] ;
        b[i] = b[i-1] + a[i] ;
        r[i] = r[i-1] + (b[i] >= 0) ;
        mp[b[i]].push_back(i);
    }
    // cout << mp.begin()->first << " " << mp.begin()->second.size() << endl;
    if(mp.begin()->first >= 0){
        ans = qmi(2,n) % MOD ;
    }else{
        for(auto e : mp.begin()->second){ 
            ans = (ans +  qmi(2,r[e] + n - e) + MOD) % MOD ;
        }
    }
    cout << ans << endl ;
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}