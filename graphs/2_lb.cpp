#include<bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

ll n, m;
vector<string>a;
vector<vector<int>> dist;
vector<vector<pair<int,int>>> par;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char d[4] = {'D','R','U','L'};

bool check(int x,int y){
  if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#' ) return true;;
  return false;
}

void bfs(pair<int,int> st){
    dist.resize(n,vector<int>(m,INT_MAX));
    par.resize(n,vector<pair<int,int>>(m,{-1,-1}));
    dist[st.first][st.second] = 0;

    queue<pair<int,int>> q;
    q.push(st);

    while(!q.empty()){
      auto [x,y] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx,ny) && dist[nx][ny] > dist[x][y] + 1){
          dist[nx][ny] = dist[x][y] + 1;
          par[nx][ny] = {x,y};
          q.push({nx,ny});
        }
      }
    }
}


void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int,int> st,end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 'A') st = {i,j};
            if(a[i][j] == 'B') end = {i,j};
        }
    }
    bfs(st);

    if(dist[end.first][end.second] == INT_MAX){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << dist[end.first][end.second] << "\n";
    
    vector<char> path;
    pair<int,int> ch = end;
    while(ch != st){
      auto [x,y] = par[ch.first][ch.second];
      for (int i = 0; i < 4; i++) {
          if(x + dx[i] == ch.first && y + dy[i] == ch.second){
              path.push_back(d[i]);
          }
      }
      ch = {x,y};
    }
    reverse(path.begin(),path.end());
    for(auto c : path) cout << c;

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
