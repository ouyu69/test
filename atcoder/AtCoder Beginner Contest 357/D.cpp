#include<bits/stdc++.h>
#include<vector>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long 
using namespace std;
const int N = 1e6 + 10 ;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353 ;//全一才位1
int T = 1 ;
int n , m, k ;
int inv[N] ;
int qmi(int a,int b){
    int res= 1 ;
    while(b){
        if(b&1) res = (res * a) % MOD ;
        b >>= 1 ;
        a = (a * a) % MOD ;
    }
    return res ;
}
void solve(){
    cin >> n ;
    n = 1e18-1;
    int t = n ;
    int num = (int) (log10(t) + 1);
    cout << num << endl ;
    int num2 = 0 ;
    while(t){
        t /= 10 ;
        num2 ++ ;
    }
    cout << num2 << endl ;

}
signed main(){
    while(T --){
        solve() ;
    }
    return 0;
    
}