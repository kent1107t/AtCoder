#include <bits/stdc++.h>
using namespace std;

int main(){
  int v, e, r;  cin >> v >> e >> r;
  vector<vector<pair<int, int>>> g(v);
  while(e--){
    int s, t, d;  cin >> s >> t >> d;
    g[s].push_back({d, t}); // {コスト, 次の点} にしてる １つめのコストで優先度をつけたいから
  }

  vector<int> ans(v, 1e9);  ans[r] = 0;  // 最終的な最短経路のコストを入れる
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;  // 優先度付きキュー
  pque.push({0, r});
  while(!pque.empty()){
    auto now = pque.top();
    pque.pop();
    if(now.first > ans[now.second])  continue;
    // 上のif文 : もしもう決まってるやつが後から出てきた時
    // 点iから7で行けてキューに入れたけど点jから3で行けるやつが見つかってキューに入れた場合 jから行くほうが先に取り出されて決まってしまうけど、その後にもiから来た7で行けるやつがpqueに残ったままだから それが出てきた時に弾く用

    for(auto nex : g[now.second]) // 今見てる辺から行ける点nexについて
      if(now.first + nex.first < ans[nex.second]){ // もし最短を更新するなら
	ans[nex.second] = now.first + nex.first;
	pque.push({ans[nex.second], nex.second});
      }
  }
  
  for(auto i : ans)
    if(i == 1e9)  cout << "INF\n";
    else cout << i << endl;
    
  return 0;
}
