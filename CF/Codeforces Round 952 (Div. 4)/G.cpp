#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 1e6 + 10 ;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7 ;//全一才位1
const double eps = 1e-9 ;
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a * b / gcd(a,b); } 
PII ac[N];
int T = 1 ;
int n , m , k ;
int ans = 0 ;
int h ;
bool check(int k){
    //每个攻击每个一个周期
    int res = 0 ;
    for(int i = 1 ; i <= n ; ++ i){
        res += ((int)(k/ac[i].second)+(k%ac[i].second != 0)) * ac[i].first ;
    }
    return res >= h ;
}
void solve(){
    cin >> h >> n ;
    for(int i = 1 ; i<= n ; ++ i) cin >> ac[i].first ;
    for(int i = 1 ; i<= n ; ++ i) cin >> ac[i].second ;
    int l = 1, r = 1e11 + 10 ;
    while(l < r){
        // cout << l << " " << r << endl ;
        int mid = l + r>> 1 ;
        if(check(mid)){
            r = mid ;
        }else{
            l = mid + 1 ;
        }
    }
    cout << r << endl ;
   
    

    
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}