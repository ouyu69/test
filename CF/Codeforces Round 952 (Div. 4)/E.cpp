#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
// #define PII pair<int, int> 
using namespace std;

const int N = 1e6 + 10 ;
const int M = 510 ;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ;//全一才位1
const double eps = 1e-9 ;
int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a * b / gcd(a,b); } 
typedef struct PII{
    int a;
    int b;
};

bool check(int k){
    while(k && k%10 ==0){
        k /= 10 ;
    }
    return k == 0 ;
}
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
int x, y, z, k ;
int l[4] ;
int c[N] ;
int d[N] ;
void solve(){
        int h, n, ans = 0;

        cin>>h>>n;
        PII a[n];
        map<int,map<int,int> >mp;
        vector<int> v;

        for(int i = 0 ; i < n ; i ++){
            cin>>a[i].a;


        }
        for(int i = 1 ; i <= n ; ++ i){
            d[i] = d[i-1] + c[i] ;
            d[i] *= d[i] ;


        }

        for(int i = 0 ; i < n ; i ++){
            cin >> a[i].b;


        }
        if(n == 1){
            ans=((h+a[0].a - 1) / a[0].a - 1) * a[0].b + 1 ;
        }
        else{
            mp.clear() ;
            for(int i = 0 ; i < n ; i ++) mp[1][i] = i;
            while(h > 0)
            {

                for(auto l : mp){
                    v.clear() ;

                ans = l.first ;

            for(auto k : l.second){
                    h -= a[k.second].a;
                        mp[ans+a[k.second].b][k.second]=k.second;
                v.push_back(k.second);
            }
                for(int i=0;i<v.size();i++){
                        mp[ans].erase(v[i]);
                    }
                    if(h<=0){
                        break;
                    }
                }     
            }
            
        }
        cout << ans << endl;;
}
signed main(){
    IOS ;
    cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}