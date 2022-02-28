#include <bits/stdc++.h>
using namespace std;

int d[] = {1, 0, -1, 0, 1};

int main(){
  int r, c, sy, sx, gy, gx;
  cin >> r >> c >> sy >> sx >> gy >> gx;
  //  char field[55][55];
  vector<vector<char>> field(r+2, vector<char>(c+2));
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)  cin >> field[i][j];

  int dist[55][55] = {0};  dist[sy][sx] = 1;
  
  queue<pair<int, int>> que;  // how   to   make   queue 
  que.push(make_pair(sy, sx)); //  push()
  while(!que.empty()){
    int nowh = que.front().first, noww = que.front().second;    //   take front()
    que.pop();                                                  //   and pop()
    for(int i=0; i<4; i++){
      int ny = d[i] + nowh, nx = d[i+1] + noww;
      if(field[ny][nx]=='.' && !dist[ny][nx]){
	que.push({ny, nx});
	dist[ny][nx] = dist[nowh][noww] + 1;
      }
    }
  }

  cout << "ans is " << dist[gy][gx]-1 << endl;  

  return 0;
}
