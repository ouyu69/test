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
int a[7] ;
int b[7] ;
void solve(){
    for(int i = 1; i <= 6 ; ++ i){
        cin >> a[i] ;
    }
    for(int i = 1; i <= 6 ; ++ i){
        cin >> b[i] ;
    }
    bool f = true ;
    if(a[3] >= b[6] || b[3] >= a[6]){
        f = false ;
    }
    if(a[1] >= b[4] || b[1] >= a[4]){
        f = false ;
    }
    if(a[2] >= b[5] || b[2] >= a[5]){
        f = false ;
    }
    if(f){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl ;
    }
}
signed main(){
    IOS ;
    while(T --){
        solve() ;
    }
    return 0;
    
}