#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(v) int(v.size())
typedef long long ll;

void solve() {
    int N,l,r;
    cin>>N>>l>>r;
    vector<int> a(N);
    vector<ll> ps(N+1);
    for (int i=0; i<N; i++) {
        cin>>a[i];
        ps[i+1]=ps[i]+a[i];
    }
    vector<int> dp(N+1);
    for (int i=1; i<=N; i++) {
        dp[i]=dp[i-1];
        int low=0, hi=i-1;
        while (low<hi) {
            int m=(low+hi)/2+1;
            ps[i]-ps[m]>=l?low=m:hi=m-1;
        }
        if (ps[i]-ps[low]>=l&&ps[i]-ps[low]<=r) {
            dp[i]=max(dp[i],dp[low]+1);
        }
    }
    cout<<dp[N]<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T=1;
    cin>>T;
    while (T--) solve();
}