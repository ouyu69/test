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
void dfs(vector<vector<char>> &vec,int k,int x,int y){//x,y表示位置
    if(k == 0){
        return ;
    }
    int num = (int)pow(3,k-1) ;
    for(int i = num ; i < 2 * num ; ++ i){
        for(int j = num ; j < 2 * num ; ++ j){
            vec[x+i][y+j] = '.' ;
        }
    }

    dfs(vec,k-1,x,y) ;
    dfs(vec,k-1,x+2 * num,y+2 * num) ;

    dfs(vec,k-1,x+num,y) ;
    dfs(vec,k-1,x+ 2 *num,y) ;

    dfs(vec,k-1,x,y+ 2 * num) ;
    dfs(vec,k-1,x,y + num) ;

    dfs(vec,k-1,x + num,y+ 2 * num) ;
    dfs(vec,k-1,x + 2 * num , y + num) ;
}
void solve(){
    cin >> n ; 
    vector<vector<char>> vec((int)pow(3,n) + 1,vector<char>((int)pow(3,n) + 1 ,'#')) ;
    dfs(vec,n,1,1) ;
    for(int i = 1 ; i <= (int)pow(3,n) ; ++ i ){
        for(int j = 1;j <= (int)pow(3,n) ; ++j ){
            cout << vec[i][j];
        }
        cout << endl ;
    }
}
signed main(){
    // cin >> T ;
    while(T --){
        solve() ;
    }
    return 0;
    
}