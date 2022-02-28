#include <bits/stdc++.h>
using namespace std;
const long INF = 1e18;

void tour(long cur, long last, long &time, vector<long> &in, vector<long> &out, vector<long> &route, vector<vector<long>> &g) {
  in[cur] = time;
  route.push_back(cur);
  for (auto nxt : g[cur]) {
    if (nxt == last)  continue;  // 直前のとこだったら、ここから北とこだったら
    time++;  // nxt に行く分
    tour(nxt, cur, time, in, out, route, g);
    time++;  // nxt から cur に帰る分
    route.push_back(cur);
  }
  out[cur] = time;
}

int main(void) {
  long n;  cin >> n;  // 頂点数
  vector<vector<long>> g(n);
  for (long i = 1; i < n; i++) { // 辺（1-indexed）
    long u, v;  cin >> u >> v;  u--;  v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long time = 0;
  vector<long> in(n, -1), out(n, -1), route;
  tour(0, -1, time, in, out, route, g);

  printf("idx : ");
  for (long i = 0; i < n; i++)  printf("%3ld", i + 1);  printf("\n");
  printf("in  : ");
  for (long i = 0; i < n; i++)  printf("%3ld", in[i]);  printf("\n");
  printf("out : ");
  for (long i = 0; i < n; i++)  printf("%3ld", out[i]);  printf("\n\n");
  
  printf("time  : ");
  for (long i = 0; i < route.size(); i++)  printf("%3ld", i);  printf("\n");
  printf("route : ");
  for (long i = 0; i < route.size(); i++)  printf("%3ld", route[i] + 1);  printf("\n");
  
  return 0;
}
