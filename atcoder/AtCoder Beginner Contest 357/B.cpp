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
string s ;
void solve(){
    cin >> s ;
    bool f = false ;
    int num = 0 ;
    for(int i = 0; i < s.size() ; ++ i){
        if(s[i] <= 'z' && s[i] >= 'a') num ++ ;
        else num -- ;
    }
    for(int i = 0; i < s.size() ; ++ i){
        if(num < 0 && s[i] <= 'z' && s[i] >= 'a'){
            s[i]-=32 ;
        }
        else if(num > 0 && s[i] <= 'Z' && s[i] >= 'A'){
            s[i] += 32;
        }
    }
    cout << s << endl ;
}
signed main(){
    // cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}