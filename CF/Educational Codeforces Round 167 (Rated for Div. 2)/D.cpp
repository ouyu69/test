#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 5e3 + 10 ;
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
    string s ; 
    return res ;
}
int T = 1 ;
int ans = 0 ;
int n , m, k ;
int a[N] ;
int b[N] ; 
int dp[N][N] ;//第i个位置，能量为j
void solve(){
    cin >> n ;
    for(int i = 0 ; i < n+2 ; ++ i){
        for(int j = 0 ; j < n+2 ; ++ j){
            dp[i][j] = INF ;
        }
        b[i] = 0 ;
    }
    map<int,int> mp ;
    for(int i = 1; i <= n ; ++ i){
        cin >> a[i] ;
        mp[a[i]] ++ ;
    }
    int cnt = 0 ;
    dp[0][0] = 0 ;
    for(auto e : mp){
        b[++cnt] = e.second ;
        dp[cnt][0] = 0 ;
    }
    for(int i = 1; i <= cnt ; ++ i){
        for(int j = 0 ; j < i ; ++ j){
            dp[i][j] = INF ;
            dp[i][j] = min(dp[i-1][j], dp[i][j]) ;
            if(i - j >= dp[i-1][j-1] + b[i]){
                dp[i][j] = min(dp[i-1][j-1] + b[i], dp[i][j]) ;
            }
        }        
    }
    ans = INF ;
    for(int i = 0 ; i <= cnt ; ++ i){
        if(dp[cnt][i] != INF) ans = min(ans,cnt-i) ;
        // cout << dp[cnt][i] ;
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