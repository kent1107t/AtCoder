#include <bits/stdc++.h>
using namespace std;

long modpow(long a, long n, long mod){
  long r = 1;
  while(n > 0){
    if(n & 1)  r = r * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return r;
}

long modpow2(long a, long n, long mod) {
  // 再帰バージョン
  if (n <= 0)  return 1;
  return (n & 1 ? a : 1) * modpow2(a * a % mod, n >> 1, mod) % mod;
}

int main(){
  long a, n, m;
  cin >> a >> n >> m;

  cout << "a^n = " << modpow(a, n, m) << " (mod m)\n";

  return 0;
}
  
