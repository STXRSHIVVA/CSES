#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
vector<int> dist;
vector<int> par;
vector<vector<int>> g;

void bfs(int st){

  dist.assign(n+1,-1);
  par.assign(n+1,-1);
  queue<int> q;
  
  dist[st] = 0;
  q.push(st);
  while(!q.empty()){
    int f = q.front();
    q.pop();
    for(auto c : g[f]){
      if(dist[c] == -1){
        dist[c] = dist[f]+1;
        par[c] = f;
        q.push(c);
      }
    }
  }
}

void solve() {
  cin >> n>> m;
  g.resize(n+1);

  for (int i = 1; i <= m; i++) {
      int x,y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
  }
    
  bfs(1);
  
  if(dist[n] == -1){
    cout << "IMPOSSIBLE\n";
    return;
  }

   vector<int> path;

   for (int i = n; i != -1 ; i = par[i]) {
       path.push_back(i);
   }
   reverse(path.begin(),path.end());

   cout << path.size() << "\n";
   for(auto c : path) cout <<  c << " ";

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
