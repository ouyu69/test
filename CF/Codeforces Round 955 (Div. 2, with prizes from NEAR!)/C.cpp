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
int ll , rr ;
int a[N] ;  
int b[N] ;
int dp[N] ;
int T = 1 ;
int ans = 0 ;
int n , m, k ;
void solve(){
    cin >> n >> ll >> rr ;
    for(int i = 1 ; i <= n ; ++ i){
        cin >> a[i] ;
        b[i] = b[i-1] + a[i] ;
    }
    int l = 1 ;
    int res = 0 ;
    while(l <= n){
        int l1 = l , r1 = n ;
        while(l1 < r1 ){
            int mid = (l1 + r1) >> 1 ;
            if(b[mid] - b[l-1] >= ll){
                r1 = mid ;
            }else{
                l1 = mid + 1 ;
            }
        }

        if(b[r1] - b[l-1] <= rr &&b[r1] - b[l-1] >= ll ){
            l = r1 + 1 ;
            res ++ ;
        }else{
            l ++ ;
        }
    }
    cout << res << endl ;
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}