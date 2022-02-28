#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x){
  if(p[x] == x)  return x;
  else{
    p[x] = find(p[x]);
    return p[x];
  }
}
    
int main(){
  int n, q;
  cin >> n >> q;
  p.resize(n);
  for(int i=0; i<n; i++)  p[i] = i;

  while(q--){
    int com , x, y;  cin >> com >> x >> y;
    if(com == 0){
      x = find(x);
      y = find(y);
      p[y] = x;
    }else if(com == 1){
      string ans = "Yes";
      if(find(x) != find(y))  ans = "No";
      cout << ans << endl;
    }
  }

  return 0;
}
