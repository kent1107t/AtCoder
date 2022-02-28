#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
const long INF = 1e18;
const long MOD = 998244353;
using mint = modint998244353;
//typedef modint1000000007 mint;

pair<mint, mint> op(pair<mint, mint> a, pair<mint, mint> b) {
  return {b.first * a.first, b.first * a.second + b.second};
}

pair<mint, mint> e() {
  return {1, 0};
}

int main(void) {
  long n, q;  cin >> n >> q;
  segtree<pair<mint, mint>, op, e> seg(n);
  
  for (long i = 0; i < n; i++) {
    long a, b;  cin >> a >> b;
    seg.set(i, {a, b});
  }

  while (q--) {
    long t;  cin >> t;
    if (t == 0) {
      long p, c, d;  cin >> p >> c >> d;
      seg.set(p, {c, d});
    } else if (t == 1) {
      long l, r, x;  cin >> l >> r >> x;
      auto [a, b] = seg.prod(l, r);
      cout << (a * x + b).val() << endl;
    }
  }

  return 0;
}
