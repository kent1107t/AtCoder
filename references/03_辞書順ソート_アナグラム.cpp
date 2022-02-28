#include <bits/stdc++.h>
using namespace std;

int main(){
  // アナグラム
  string ana = "indeednow";
  sort(ana.begin(), ana.end());
  cout << ana << endl;
  
  // 辞書順ソート
  int n;  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; i++)  cin >> s[i];

  sort(s.rbegin(), s.rend());

  for(int i=0; i<n; i++)
    cout << s[i] << endl;

  // おまけ
  for(char c : ana)
    cout << c << " ";
  cout << endl;

  return 0;
}
  
