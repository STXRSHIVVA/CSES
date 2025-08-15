#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
vector<string> a;
vector<vector<int>>v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check(int i,int j){
  if(i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#'){
    return true;
  }
  return false;
}

void dfs(int x,int y){
    v[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if(check(x+dx[i],y+dy[i])){
            if(!v[x+dx[i]][y+dy[i]]){
                dfs(x+dx[i],y+dy[i]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    v.resize(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!v[i][j]  && a[i][j] == '.'){
              count++;  
              dfs(i,j);
            }
        }
    }
    cout << count << "\n";
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
