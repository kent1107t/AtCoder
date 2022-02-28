/*
 *クラスカル法
 */
#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> p;
  UnionFind(int n){
    p.resize(n+1);
    for(int i=0; i<=n; i++)  p[i] = i;
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
  }
  bool same(int x, int y){
    return find(x) == find(y);
  }
};

int main(){
  int n, m;  // n:頂点数  m:辺数
  cin >> n >> m;
  vector<tuple<int, int, int>> edge(m);  // <0>:cost  <1>:from  <2>:to
  for(int i=0; i<m; i++)  // 入力は from to cost の形式
    cin >> get<1>(edge[i]) >> get<2>(edge[i]) >> get<0>(edge[i]);
  sort(edge.begin(), edge.end()); // costでソート

  UnionFind uf(n);
  int allcost = 0;  // ansは最小で前連結するよう繋いだ時の全コスト
  for(int i=0; i<m; i++){
    if(uf.same(get<1>(edge[i]), get<2>(edge[i])))  continue;  // もう連結されてれば
    uf.unite(get<1>(edge[i]), get<2>(edge[i]));  // 連結する
    allcost += get<0>(edge[i]);
  }

  cout << allcost << endl;

  return 0;
}
