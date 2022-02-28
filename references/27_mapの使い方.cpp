#include <bits/stdc++.h>
using namespace std;

int main(){
  map<string, int> mp;  // name : height

  mp["Kent"] = 168;
  mp["Okubo"] = 148;
  
  // keyが存在するかの判定
  if(mp.find("Kent") == mp.end())  cout << "key:Kent is not found\n";
  else  cout << "key:Kent is found\n";

  if(mp.find("Taro") == mp.end())  cout << "key:Taro is not found\n";
  else  cout << "key:Taro is found\n";

  // 数字ならインクリメントも使える
  mp["Okubo"]++;
  mp["Yuchan"]++; // 数字の場合最初は0が想定されてる だからここでは1になる

  // 全key, value の回り方
  for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    cout << "key : " << itr->first << "    value : " << itr->second << endl;

  return 0;
}
