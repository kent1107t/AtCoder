#include <bits/stdc++.h>
using namespace std;

struct BIT{
  vector<int> d;
  BIT(int n){
    d.resize(n+1, 0);
  }
  void add(int i, int x){ // iにxを加える
    while(i <= d.size()){
      d[i] += x;
      i += i & -i;
    }
  }
  int sum(int i){ // [1, i]の和を返す
    int s = 0;
    while(i > 0){
      s += d[i];
      i -= i & -i;
    }
    return s;
  }
};

int main(){
  int a[] = {6, 4, 1, 3, 2, 8, 2};
  int n = sizeof(a)/sizeof(a[0]);
  BIT b(n);
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
    b.add(i+1, a[i]);
  }

  while(cin >> n, n){
    cout << b.sum(n) << endl;
  }
  return 0;
}
