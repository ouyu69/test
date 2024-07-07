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
    string s ; 
    return res ;
}
int T = 1 ;
int ans = 0 ;
int n , m, k ;
int dp[N] ;
void solve(){
    string s1 ;
    string s2 ;
    cin >> s1 >> s2 ;
    ans = INF ;
    for(int i = 0; i < s2.size(); i++){//枚举s1的位置
        int j = i ;
        for(auto c : s1){
            if(j < s2.size() && s2[j] == c) ++ j ;
        }
        ans = min(ans,(int)(s1.size() + s2.size())  - (j - i) ) ;
    }
    cout << ans << endl ;
}
//avvvaaa
//acbv
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}