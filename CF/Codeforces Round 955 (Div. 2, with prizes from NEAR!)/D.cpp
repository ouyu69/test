#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 1e6 + 10 ;
const int M = 510 ;
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
string pg[M] ;
void solve(){
    cin >> n >> m  >> k ;
    for(int i = 1 ;i <= n ; ++ i){
        for(int j =1; j <= m ; ++ j){
            cin >> g[i][j] ;
        }
    }  
    int sum1 = 0 ;
    int sum2 = 0 ;
    int c ;
    string s ;
    for(int i = 0 ;i < n ; ++ i){
        cin >> s ;
        for(int j = 0 ; j < s.size() ; ++ j){
            if(s[j] == '1'){
                sum1 += g[i+1][j+1] ;
                pg[i+1][j+1] = pg[i][j+1] + pg[i+1][j] - pg[i][j] + 1;

            }else{
                pg[i+1][j+1] = pg[i][j+1] + pg[i+1][j] - pg[i][j] ;
                sum2 += g[i+1][j+1] ;
            }
        } 
    }  
    if(sum1 == sum2){
        cout << "YES" << endl ;
        return ;
    }
    set<int> se1 ;
    for(int i = 1 ; i <= n - k + 1 ; ++ i){//枚举左上角
        for(int j = 1 ; j <= m - k + 1 ; ++ j){
            int cnt1 = pg[i+k-1][j+k-1] - pg[i-1][j+k-1] - pg[i+k-1][j-1] + pg[i-1][j-1] ;
            int cnt2 = k * k - cnt1  ;
            if(cnt1 == 0 || cnt2 == 0){//全是0
                if(abs(sum1 - sum2) % (k*k) == 0 ){
                    cout << "YES" << endl ;
                    return ;
                }
            }else{
                if(cnt1 == cnt2) continue ;
                se1.insert(abs(cnt2 - cnt1)) ;
            }
        }
    }
    int res = abs(sum1 - sum2) ;
    //小的数不能是大的数的因子   
    vector<int> vec ;
    for(auto x : se1){//如果有偶数也有奇数一定可行
        for(auto e : se1){
            if(x % e == 0){
                vec.push_back(e) ;
            }else if(e % x == 0){
                vec.push_back(x) ;
            }
        }
    }
 
    cout << "NO" << endl ;
}
//k * k的矩阵
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}