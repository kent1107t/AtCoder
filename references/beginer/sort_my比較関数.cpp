#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> s = {
    "pine",
    "orange",
    "apple",
    "grape"
  };

  cout << "そのまま" << endl;
  for(auto si : s)
    cout << si << endl;

  cout << endl << "指定なしソート(辞書順)" << endl;
  sort(s.begin(), s.end());
  for(auto si : s)
    cout << si << endl;

  cout << endl << "文字列の長さでソート" << endl;
  sort(s.begin(), s.end(), [](auto &s, auto &t){ return s.size() < t.size(); });
  for(auto si : s)
    cout << si << endl;  

  return 0;
}
