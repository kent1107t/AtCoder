#include <bits/stdc++.h>
using namespace std;
const long INF = 1e18;

struct SegmentTree {
  vector<long> dat;
  long n;
  SegmentTree(long n_) {
    n = 1l;
    while (n < n_)  n *= 2;  // 一番下の配列を簡略化のため2べき乗個に
    dat.resize(n * 2 - 1, INF);  // 最小値なのでINF埋め
  }
  void update(long k, long a) {  // k 番目(0-indexed)を a で置き換え
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  long query(long a, long b) {
    // [a, b) の最小値
    return query_sub(a, b, 0, 0, n);
  }
  long query_sub(long a, long b, long k, long l, long r) {
    // [l, r) は、dat[k] が表す最小値の対称範囲
    if (r <= a || b <= l)  return INF;     // 求めたい範囲([a, b))と今のdat[k] の指す範囲([l, r))が全く関係がない場合
    if (a <= l && r <= b)  return dat[k];  // 完全に含まれる場合

    return min(query_sub(a, b, k * 2 + 1, l, (l + r) / 2),   // 左の子を使う 
	       query_sub(a, b, k * 2 + 2, (l + r) / 2, r));  // 右の子を使う
  }
};

int main(void) {
  


  return 0;
}
