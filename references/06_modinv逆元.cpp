#include <bits/stdc++.h>
using namespace std;

long modpow(long a, long n, long m){
  // return a^n % m
  long r = 1;
  while(n > 0){
    if(n & 1)  r = r * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return r;
}

long modinv(long a, long m){ // 使える条件はmが素数  それ以外は拡張ユークリッド
  //         1
  // return --- % m
  //         a
  return modpow(a, m-2, m);
}  

long factorial_data[10000000]; // 逐次階乗を計算するのだとたまにTLEになる
long factorial(long n, long m) {
  // return n! % m
  if (factorial_data[n] == 0) {
    factorial_data[0] = factorial_data[1] = 1l;
    for (long i = 2; i < 1e7; i++)
      factorial_data[i] = factorial_data[i - 1] * i % m;
  }
  return factorial_data[n];
}

long nCr(long n, long r, long m) {
  //                      n!
  // return = nCr = -------------  % m
  //                 r! (n - r)!
  return factorial(n, m) * modinv(factorial(r, m), m) % m * modinv(factorial(n - r, m), m) % m;
}

int main(){
  /*
    例えば、 nCr を (mod = 1e9+7 などの素数) で求める時、

      n * (n - 1) * ... * (n - r + 1)
      -------------------------------
                     r !
    である。
    このとき 分母の r ! を割り算でなく掛け算にする。つまり
    
             1 / r ! 三 ?  (mod p)   

    となる ? を求めたい。
    フェルマーの少定理から、
          Y^(p - 1) 三 1  (mod p)  (p は素数、p と Y は互いに素)
    が成り立つ。これを変形すると、
          Y * Y^(p - 2) 三 1                   (mod p)
              Y^(p - 2) 三 1 / Y ( = Y^(-1) )  (mod p)
	          1 / Y 三 Y^(p - 2)           (mod p)

    である。よって

                 1 / r! 三 (r!)^(p - 2)        (mod p)

    が成り立つ。ここから、

    nCr = {n * (n-1) * ... * (n-r+1)} * {(r!)^(p-2)} % p

    である。
   */
  return 0;
}
