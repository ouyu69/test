#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 1e6 + 10 ;
const int M = 610 ;
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
int g[M][M] ;
int dx[] = {1,0,-1,0} ;
int dy[] = {0,1,0,-1} ;
void solve(){
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++ i){
        for(int j  = 1; j <= m ; ++ j){
            cin >> g[i][j] ;
        
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        for(int j  = 1; j <= m ; ++ j){
            bool f = true ;
            int mi = -INF ;
            for(int k = 0 ; k < 4 ; ++ k){
                int ii = i + dx[k] ;
                int jj = j + dy[k] ;
                if(ii&& jj && ii <= n && jj <= m ){
                    if(g[ii][jj] >= g[i][j]){
                        f = false ;
                        break ;
                    }
                mi = max(mi,g[ii][jj]) ;

                }    
            }
            if(f) g[i][j] = mi ;
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        for(int j  = 1; j <= m ; ++ j){
            cout <<  g[i][j] << " ";
        
        }
        cout << endl ;
    }
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}