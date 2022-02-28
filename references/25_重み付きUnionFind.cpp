#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> p;
  vector<int> w;
  UnionFind(int n){
    p.resize(n+1);
    w.resize(n+1, 1);
    for(int i=1; i<=n; i++)  p[i] = i;
  }
  int find(int x){
    if(p[x] == x)  return x;
    return p[x] = find(p[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return;
    p[x] = y;
    w[x] += w[y];
    w[y] = w[x];
  }
};

int main(){
  int n, c;  cin >> n;
  UnionFind uf(n);

  while(cin >> c, c){
    if(c == 1){ // unite
      int x, y;  cin >> x >> y;
      uf.unite(x, y);
    }else if(c == 2){ // show
      vector<bool> seen(n+1, false);
      for(int i=1; i<=n; i++)
	printf("i:%d   p[i]:%d   w[i]:%d\n", i, uf.p[i], uf.w[i]);
    }
    cout << endl;
  }

  return 0;
}
