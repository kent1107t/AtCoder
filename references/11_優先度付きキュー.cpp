#include <bits/stdc++.h>
using namespace std;

int main(){
  // でかい順から出る
  //priority_queue<pair<int, int>> pque;

  // 小さい順から出る ダイクストラで使う
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
  
  pque.push({222, -3});
  pque.push({2, -9});
  pque.push({4, 22228});
  pque.push({1, 10});

  while(!pque.empty()){
    cout << pque.top().first << " " << pque.top().second << endl;
    pque.pop();
  }

  return 0;
}
