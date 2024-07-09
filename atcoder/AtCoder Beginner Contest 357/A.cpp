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
int a[N] ;
int ans = 0 ;
void solve(){
    ans = 0 ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++ i ){
        cin >> a[i] ;      
    }
    for(int i = 1 ; i <= n ; ++ i ){
        m-=a[i] ;
        if(m < 0 ){
            break ;
        }
        ans ++ ;
    }
    cout << ans << endl ;
}
signed main(){
    // cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}