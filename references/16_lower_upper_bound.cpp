#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> t = {1, 2, 4, 8, 9, 10};
  int key = 4;

  // key以下の数が何個あるか
  cout << (int)(upper_bound(t.begin(), t.end(), key) - t.begin()) << endl;

  // keyより下の数が何個あるか
  cout << (int)(lower_bound(t.begin(), t.end(), key) - t.begin()) << endl;

  // key以上の数が何個あるか
  cout << (int)(t.end() - lower_bound(t.begin(), t.end(), key)) << endl;

  // keyより上の数が何個あるか
  cout << (int)(t.end() - upper_bound(t.begin(), t.end(), key)) << endl;
  

  return 0;
}
