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
void solve(){
    ans = 0 ;
    string s; 
    cin >> n ;
    cin >> s ;
    s = " " +  s ;
    int num = 0 ;
    if(s.size() == 3){
        ans = (s[1]-'0') * 10 + s[2] - '0' ;
        cout << ans << endl ;
        return ;
    }
    if(s.size() == 4 && s[2] == '0'){
        ans = min((s[1]-'0') * (s[3] - '0') , (s[1]-'0') + (s[3] - '0')) ;
        cout << ans << endl ;
        return ;
    }
    int mi ;
    for(int i = 1 ; i <= n; ++ i){
        if(s[i] == '0'){
            ans = 0 ;
            cout << ans << endl ;
            return ;
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        if(s[i] != '1'){
            a[i] = a[i-1] + s[i] - '0' ;
        }else{
            a[i] = a[i-1] ;
        }
    }
    ans = INF ;
    for(int i = 1 ; i <= n - 1; ++ i){
        int te = (s[i]-'0') * 10 + s[i+1] - '0' ;
        ans =min( ans, te + a[i-1] + a[n] - a[i+1]) ;
    }
    cout << ans  << endl ;
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}