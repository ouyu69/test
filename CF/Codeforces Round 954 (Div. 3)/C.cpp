#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define PII pair<int, int> 
#define ff first
#define ss second
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
int qmi1(int a, int b){
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    vector<bool>   v(n);
    string ss;
    cin >> ss;
 
    string c;
    for (int i = 0; i< m; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    cin >> c;


    sort(vec.begin(),      vec.end());


    vec.erase(unique(vec.begin(),   vec.end()),   vec.end());
 
    int mi = qmi(10,10) ;



    sort(c.begin(), c.end());
    for (int i = 0; i < vec.size() ; ++i) 
    {
        mi = qmi(mi,10) ;
        if (v[vec[i] - 1]) 
        {
           continue ;
        }
        ss[vec[i] - 1] = c[i];
        v[vec[i] - 1] = true;
    }
    cout << ss << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
