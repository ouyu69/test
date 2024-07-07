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
int dp[N][2] ;
void solve(){
    ans =0 ;
    cin >> n ;
    int z = 0 ;
    int f = 0 ;
    for(int i = 1 ; i <= n ; ++ i){
        cin >> a[i] ;
        dp[i][1] = min(dp[i-1][1] + a[i] ,dp[i-1][0] + a[i]) ;
        dp[i][0] = max((int)abs(dp[i-1][1] + a[i]) ,(int)abs(dp[i-1][0] + a[i])) ;
    }
    ans = max(dp[n][1],dp[n][0]) ;
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