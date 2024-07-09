#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<PII, int> 
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
int n , m, k ;
void solve(){
    int sum = 0 ;
    int te = 0 ;
    cin >> n ;
    vector<vector<int>> pre(3,vector<int>(n+1)) ;
    for(int i = 0 ; i < 3 ; ++ i){
        for(int j = 1; j <= n ; ++ j){
            cin >> te ;
            pre[i][j] = pre[i][j-1] + te ; 
        }
    }
    vector<int> num = {0, 1, 2} ;
    bool f = false ;
    int pos = (pre[0][n] + 2 ) / 3 ;
    vector<PII> ans(3) ;
    for(int i = 1 ; i <= 6 ; ++ i){//6种排列组合
        int cur = 0 ;
        while(pre[num[0]][cur] - pre[num[0]][0] < pos) cur ++ ;
        for(int j = cur + 1 ; j <= n ; ++ j){
            if(pre[num[1]][j] - pre[num[1]][cur] >= pos && pre[num[2]][n] - pre[num[2]][j]>=pos){
                ans[num[0]] = {1, cur} ;
                ans[num[1]] = {cur + 1, j} ;
                ans[num[2]] = {j + 1, n} ;
                for(auto e: ans){
                    cout << e.first << " " << e.second << " " ;
                }
                cout << endl ;
                return ;
            }
        }
        next_permutation(num.begin(),num.end()) ;
    }
    cout << -1 << endl ;
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