#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
const long INF = 1e18;

int main(void) {
  long n;  cin >> n;
  vector<long> a(n), b(n);
  for (auto &x : a)  cin >> x;
  for (auto &x : b)  cin >> x;

  for (long h = 0; h - 2 <= n; h++) {
    for (long i = n - 3; i >= h; i--) {
      long val = 0, idx = 0;
      for (long d = 0; d < 3; d++)
	if (val < a[i + d]) {
	  val = a[i + d];
	  idx = d;
	}
      vector<long> x(3);
      for (long d = 0; d < 3; d++)  x[d] = a[i + d];

      for (long c = 0; c < 3 - idx; c++)
	for (long d = 0; d < 3; d++)
	  a[i + d] = x[(c + d + 1) % 3];
    }
  }

  for (long h = 0; h - 2 <= n; h++) {
    for (long i = n - 3; i >= h; i--) {
      long val = INF, idx = 0;
      for (long d = 0; d < 3; d++)
	if (val > b[i + d]) {
	  val = b[i + d];
	  idx = d;
	}
      vector<long> x(3);
      for (long d = 0; d < 3; d++)  x[d] = b[i + d];

      for (long c = 0; c < 3 - idx; c++)
	for (long d = 0; d < 3; d++)
	  b[i + d] = x[(c + d + 1) % 3];
    }
  }
  
  for (auto ai : a)  cout << ai << ' ';  cout << endl;
  for (auto ai : b)  cout << ai << ' ';  cout << endl;

  for (long i = 0;i  < n; i++)
    if (a[i] != b[i]) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes\n";

  return 0;
}
