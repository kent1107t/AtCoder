#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<long> p;
  UnionFind(long n) {
    p.resize(n + 1, -1);
  }
  int find(long x) {
    if(p[x] < 0)  return x;
    return p[x] = find(p[x]);
  }
  void unite(long x, long y) {
    x = find(x);
    y = find(y);
    if(x == y)  return;
    p[x] += p[y];
    p[y] = x;
  }
  bool is_same(long x, long y) {
    return find(x) == find(y);
  }
};

int main(){
  int n, q;  cin >> n >> q;
  UnionFind uf(n);
  while(q--){
  int com , x, y;  cin >> com >> x >> y;
    if(com == 0) {
      uf.unite(x, y);
    } else if(com == 1) {
      string ans = "Yes";
      if(uf.find(x) != uf.find(y))  ans = "No";
      cout << ans << endl;
    }
  }

  return 0;
}
