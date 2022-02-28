#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  // s[i] tekina
  cout << "3 mojime no youso " << s.at(2) << endl;

  cout << "size : " << s.size() << endl;

  // jisyo jun ni tukaeru
  string ab = "abc", xy = "xyz";
  cout << (ab < xy) << endl;
  cout << (ab == xy) << endl;  

  return 0;
}
