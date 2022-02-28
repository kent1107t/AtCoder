#include <bits/stdc++.h>
using namespace std;

int main(){
  // 文字列でやってるけどもちろんintでもできる
  string a = "apple", b = "orange";
  cout << "max is " << max(a, b) << endl;
  cout << "min is " << min(a, b) << endl;

  cout << "a : " << a << "   b : " << b << endl << "swap" << endl;
  swap(a, b);
  cout << "a : " << a << "   b : " << b << endl;

  // ソート
  vector<int> x = {2, 3, 1, 9, -22};
  for(int i=0; i<x.size(); i++)
    cout << x.at(i) << " ";
  cout << endl;

  sort(x.begin(), x.end());

  for(int i=0; i<x.size(); i++)
    cout << x.at(i) << " ";
  cout << endl;
  // 逆順
  reverse(x.begin(), x.end());
  for(int i=0; i<x.size(); i++)
    cout << x.at(i) << " ";
  cout << endl;

  

  return 0;
}
