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
int T = 1 ;
int ans = 0 ;
int n , m, k ;
int a[N] ;
int b[N] ;
int bb[N] ;
void solve(){
    ans = 0 ; 
    cin >> n >> k ;
    map<int,int> mp; 
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
        mp[a[i]] ++ ;
    }
    int cnt = 0 ;
    map<int,vector<int>> mp1 ;
    for(auto it : mp){
        if(it.second & 1){
            cnt ++ ;
            mp1[it.first % k].push_back(it.first) ;
        }        
    }
    if(cnt <= 1 ){
        cout << 0 << endl ;
        return ;
    }
    int cnt2  = 0 ;
    for(auto it : mp1){
        if(it.second.size() & 1){//说明可能要删
            cnt2 ++ ;
        }
        if(cnt2 > 1){
            cout << -1 << endl ;
            return ;
        }
    }
    if(cnt  & 1){
        for(auto e : mp1){
            int ans1 = 0 ;
            int ans2 = 0 ;
            if(e.second.size() & 1){
                vector<int> aa(n+6) ;
                vector<int> bb(n+6) ;
                for(int i = 0 ; i + 1 < e.second.size() ; i += 2){
                    aa[i+1] = aa[i] + (e.second[i+1] - e.second[i]) / k ;
                    aa[i+2] = aa[i+1] ; 
                }
                for(int i = e.second.size() - 1 ; i-1 >= 0 ; i -= 2){
                    bb[i+1] = bb[i+2] + (e.second[i] - e.second[i-1]) / k ;
                    bb[i] = bb[i+1] ;
                }
                int ans1 = INF ;
                for(int i = 1; i <= e.second.size() ; i ++){//i为可能删去的数
                    ans1 = min(ans1,aa[i-1] + bb[i+1]) ;
                }
                ans += ans1 ;
            }else{
                for(int i = 0 ; i + 1 < e.second.size()  ; i += 2){
                    ans += (e.second[i+1] - e.second[i]) / k ;
                }
            }    
        }
    }else{
        for(auto e : mp1){
            for(int i = 0 ; i < e.second.size() ; i += 2){
                ans += (e.second[i+1] - e.second[i]) / k ;
            }
        }
    }
    cout << ans << endl ;


}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}