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
void solve(){
    int x, y ,k ;
    cin >> x >> y >> k ;
    while(k){
        int num = y - x % y ;//倍数还需要的数
        if(num == y) num = 1 ;
        if(num <= k){
            x += num ;
            while(x%y == 0) x /= y ;
            k -= num ; 
            if(x == 1){
                x += k  % (y-1) ;
                break ;
            }
        }else{
            x += k ;
            k = 0 ;
        }
    }
    cout << x << endl ;
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}