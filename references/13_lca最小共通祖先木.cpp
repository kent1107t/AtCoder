#include <bits/stdc++.h>
using namespace std;

int p[20][500050] = {0};
int dep[500050] = {0};

int la(int x, int h){
  for(int i=19; i>=0; i--)
    if(1<<i <= h){
      x = p[i][x];
      h -= 1<<i;
    }
  return x;
}

int lca(int u, int v){
  if(dep[u] < dep[v])  swap(u, v);
  u = la(u, dep[u]-dep[v]);
  if(u == v)  return u;
  for(int i=19; i>=0; i--)
    if(p[i][u] != p[i][v]){
      u = p[i][u];
      v = p[i][v];
    }
  return p[0][u];
}


int main(){
  int n, q;  cin >> n >> q;
  for(int i=1; i<n; i++){
    cin >> p[0][i];
    dep[i] = dep[p[0][i]] + 1;
  }

  // Doubling
  for(int i=1; i<20; i++)
    for(int v=1; v<=n; v++)
      p[i][v] = p[i-1][p[i-1][v]];

  while(q--){
    int u, v;  cin >> u >> v;
    cout << lca(u, v) << endl;    
  }
  
  return 0;
}
