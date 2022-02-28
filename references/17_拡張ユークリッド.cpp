#include <bits/stdc++.h>
using namespace std;

int extgcd(int a, int b, int &x, int &y){
  int d = a;
  if(b != 0){
    d = extgcd(b, a%b, y, x);
    y -= (a / b) * x;
  }else{
    x = 1, y = 0;
  }
  return d;
}

int main(){
  // ax + by = 1 となる(x, y)を探す
  int a, b;  cin >> a >> b;  // 好きなa, bを入力  aとbは互いに素であることが条件

  int x, y;
  extgcd(a, b, x, y);

  printf("%d * %d + %d * %d = 1\n", a, x, b, y);

  return 0;
}
