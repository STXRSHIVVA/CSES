#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
using ll = long long;

ll n,m,k;
vector<ll>a;
vector<ll>b;

void solve() {
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for(ll &x : a) cin >>x;
    for(ll &x : b) cin >>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    ll i = 0,j = 0,ans = 0;;
    while(i < n && j < m){
      if(abs(a[i] - b[j]) <= k){
        ans++;
        j++,i++;
      }else if((a[i] - b[j]) > k){
        j++;
      }else{
        i++;
      }
    }
    cout << ans << "\n";
  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

