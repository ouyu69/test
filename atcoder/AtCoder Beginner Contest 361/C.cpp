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
int a[N] ;
int  pp ; //表示空白的的位置
void dfs(vector<int> arr){//la表示上一次的位置冒
   

}
void solve(){
    cin >> n >> k ;
    pp = n + 1 ;
    for(int i = 1; i <= n ; ++ i){
        cin >> a[i] ;
    }
    sort(a+1,a+1+n) ;
    int len = n - k ;
    ans = INF ;
    for(int i = 1 ; i + len - 1 <= n  ; ++ i){
        ans = min(a[i+len-1] - a[i],ans) ;
    }
    cout << ans << endl ;

}
signed main(){
    IOS ;
    // cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}