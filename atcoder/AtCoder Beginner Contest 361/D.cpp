#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
#define PSI pair<string, int>//表示字符串和空白的位置 
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
int n , m;

void solve(){
    cin >> n ;
    string s, t ;
    cin >> s ;
    cin >> t ;
    s = " " + s ;
    t = " " + t ;
    s += ".." ;
    t += ".." ;
    if(s == t){
        cout << 0 << endl ;
        return ;
    }
    map<string,int> dis ;//表示这种路已经存在
    queue<PSI> q ;
    q.push({s,n+1}) ;
    dis[s] = 0 ;
    while(q.size()){
        PSI te = q.front() ;
        q.pop() ;
        string s1 = te.first ;
        int k = te.second ;
        for(int i = 1 ; i <= n + 1 ; ++ i){
            // cout << endl ;
            string s2 = s1 ;
            if(i == k  || i == k + 1 || i == k - 1){
                continue ;
            }
            swap(s2[i],s2[k]) ;
            swap(s2[i+1],s2[k+1]) ;
            if(!dis[s2]){
                dis[s2] = dis[s1] + 1 ;
                q.push({s2,i});
            }
            // cout << s2  ;
        }
    }
    if(dis[t] == 0){
        cout << -1 << endl; 
    }else{
        cout << dis[t] << endl ;
    }
}
signed main(){
    IOS ;
    // cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}