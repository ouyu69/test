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
int a, b ;
void solve(){
    cin >> n >> a >> b ;// (b-i) + 1 b -> (b-k) + 1个
    int l = 0 , r = b ;
    int k = max((2 *b - 2 * a + 1) / 2 , 0LL) ;
    k = min(n,k) ;
    // cout << k << endl ;
    ans = ((2 *b - 2 * a + 1) * k - k * k ) /2 + a * n ;
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