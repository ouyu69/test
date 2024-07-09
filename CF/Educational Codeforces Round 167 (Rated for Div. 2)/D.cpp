#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
using namespace std;
const int N = 5e3 + 10 ;
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
int b[N] ; 
void mergr(int l, int r, int p){//二分递归
    if(l == r){
        return 1;
    }
    int mid = l + r + 1 >> 2 ;
    int res1 = 0 , res2 = 0 ;//表示两边的数的数量
    if((r - l + 1)&1){
        if(a[mid] != b[mid]){
            return  ; 
        }        
        merge(l, mid-1) ;
        merge(mid+1, r) ;
    }else{
        merge(l, mid) ;
        merge(mid+1, r) ;     
    }

}
void solve(){
    cin >> n ;
    map<int,int> mp1 ;
    map<int,int> mp2 ;
    for(iut i = 1 ; i <= n ; ++ i){
        cin >> a[i] ;
        mp1[a[i]] ++ ;
    }
    for(int i = 1 ; i <= n ; ++ i){
        cin >> b[i] ;
        mp2[a[i]] ++ ;
    }
    for(auto e:mp1){
        if(e.second ! mp2[e]){
            cout << "NO" << endl ;
            return ;
        }
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