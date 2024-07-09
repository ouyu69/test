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
void solve(){
    cin >> n >> m ;
    vector<string> g1(n+1) ;
    vector<string> g2(n+1) ;
    vector<vector<int>> g11(n+1,vector<int>(m+1)) ;
    vector<vector<int>> g22(n+1,vector<int>(m+1)) ;
    for(int i = 0 ;i < n ; ++ i) cin >> g1[i] ;
    for(int i = 0 ;i < n ; ++ i) cin >> g2[i] ;
    for(int i = 0 ; i < n ; ++ i){
        for(int j = 0 ; j < m ; ++ j){
            g11[i][j] = g1[i][j] -'0' ;
            g22[i][j] = g2[i][j] -'0' ;
        }
    }
    for(int i = 0 ; i < n - 1 ; ++ i){
        for(int j = 0 ; j < m - 1 ; ++ j){
            if(g11[i][j] != g22[i][j]){
                int sub =  g11[i][j] - g22[i][j] ;
                if(sub == 1){
                    g11[i][j] = (g11[i][j] + 2) % 3  ;
                    g11[i+1][j+1] = (g11[i+1][j+1] + 2) % 3  ;
                    g11[i+1][j] = (g11[i+1][j] + 1) % 3  ;
                    g11[i][j+1] = (g11[i][j+1] + 1) % 3  ;
                }else if(sub == -1){
                    g11[i][j] = (g11[i][j] + 1) % 3  ;
                    g11[i+1][j+1] = (g11[i+1][j+1] + 1) % 3  ;
                    g11[i+1][j] = (g11[i+1][j] + 2) % 3  ;
                    g11[i][j+1] = (g11[i][j+1] + 2) % 3  ;
                }else if(sub == 2){
                    g11[i][j] = (g11[i][j] + 1) % 3  ;
                    g11[i+1][j+1] = (g11[i+1][j+1] + 1) % 3  ;
                    g11[i+1][j] = (g11[i+1][j] + 2) % 3  ;
                    g11[i][j+1] = (g11[i][j+1] + 2) % 3  ;
                }else{
                    g11[i][j] = (g11[i][j] + 2) % 3  ;
                    g11[i+1][j+1] = (g11[i+1][j+1] + 2) % 3  ;
                    g11[i+1][j] = (g11[i+1][j] + 1) % 3  ;
                    g11[i][j+1] = (g11[i][j+1] + 1) % 3  ;
                }
            }
        }
    }
    // for(int i = 0 ;i < n  ; ++ i){
    //     for(int j = 0 ; j < m ; ++ j){
    //         cout << g11[i][j] << " " ;
    //     }
    //     cout << endl ;
    // }
    bool f = true ;
    for(int i =  0 ; i < m ; ++ i){
        if(g11[n-1][i] != g22[n-1][i] || !f){
            f = false ;
            break ;
        }
    }
    for(int i =  0 ; i < n ; ++ i ){
        if(g11[i][m-1] != g22[i][m-1] || !f){
            f = false ;
            break ;
        }
    }
    if(f){
        cout << "YES" << endl ;
    }else{
        cout << "NO" << endl ;
    }
    return ;
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}