#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
string s ="";
void solve(){
	char c ;
	while(cin >> c ){
		if(c == 'E'){
			return ;
		}
		else if(c == 'I'){
			while(getchar() == '\n'){
			}
			int p ;
			string s1 ;
			cin >> s1 >> p ;
			string s11 = s.substr(0,p) ;
			string s22 = s.substr(p, s.size() - p) ; 
			s = s11.append(s1.append(s22)); 

		}else if(c == 'C'){
			int p ;
			cin >> p ;
			cout << s[p] ;
		}
	}
}

signed main(){
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}