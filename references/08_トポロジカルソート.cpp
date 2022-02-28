#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> to(n);
  while(m--){
    int a, b;  cin >> a >> b;
    g[a].push_back(b);
    to[b]++;
  }
  queue<int> que;
  for(int i=0; i<n; i++)
    if(!to[i])  que.push(i);

  while(!que.empty()){
    int now = que.front();
    que.pop();
    cout << now << endl;
    for(int i : g[now])
      if(--to[i] == 0)
	que.push(i);
  }
  
  return 0;
}
  
