#include <bits/stdc++.h>
using namespace std;

bool chk(long a) {
  return true; // or false
}

int main(void) {
  long ac = 0, wa = 100; // ac : オッケーの上限   wa : 駄目の下限
  while (ac + 1 < wa) {
    long wj = (ac + wa) / 2; // wating judge  : 大丈夫かどうかみてくところ
    if (chk(wj))  ac = wj;
    else  wa = wj;
  }
  return 0;
}
