#include <bits/stdc++.h>
using namespace std;

int main(void) {
  set<string>  st1{"kent", "okubo", "dango"};

  // 追加
  st1.insert("sakamoto");

  // 消去
  st1.erase("dango");
  
  // 消去 範囲指定
  // st1.erase(st1.find("kent"), st1.find("sakamoto"));

  // いてレート
  for (auto x : st1)
    cout << x << ' ';
  cout << endl;n

  // 値が存在するかどうか 判定
  string s = "okubo";
  if (st1.find(s) != st1.end())
    cout << "okubo in st1! I found!";

  set<string> st2{"kent", "dango", "yoshiki", "kado", "sakamoto"};


  // 積集合をつくる
  set<string> st1and2;
  set_intersection(st1.begin(), st1.end(),
                   st2.begin(), st2.end(),
                   inserter(st1and2, st1and2.begin()));

  // 和集合をつくる
  set<string> st1or2;
  set_union(st1.begin(), st1.end(),
            st2.begin(), st2.end(),
	    inserter(st1or2, st1or2.begin()));

  cout << "and : ";
  for (auto x : st1and2)
    cout << x << ' ';
  cout << endl;

  cout << "or  : ";
  for (auto x : st1or2)
    cout << x << ' ';
  cout << endl;

  
  
  return 0;
}
