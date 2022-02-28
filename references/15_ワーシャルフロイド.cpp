/*
 *  全点対最短経路
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_V 1000

int main(){
  int n, m;  cin >> n >> m;  // n:vertices  m:edges
  int d[MAX_V][MAX_V] = {0}; // cost 0 の辺はないものとして、d[i][j]=0の場合i~jの経路は存在しない
  // d[i][j] = i~jにかかるコスト

  while(m--){
    int a, b, c;
    d[a][b] = d[b][a] = c; // 無向グラフ
  }

  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  
  return 0;
}
