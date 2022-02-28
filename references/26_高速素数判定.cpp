#include <bits/stdc++.h>
using namespace std;

int main(){
  // エラトステネスのふるい
  vector<int> eratos(1e6+1, 0);
  // 素数の場合はeratos[i] = i   合成数の場合は素因数のうち一番小さいもの
  // (例) eratos[7] = 7     eratos[21] = 3

  for(int i=2; i<=1e6; i++)
    if(eratos[i] == 0){ // もしまだ0なら(素数なら)
      eratos[i] = i;
      for(int j=2; j*i<=1e6; j++)
        if(eratos[i*j] == 0)  eratos[i*j] = i; // マークのない倍数全部にマークしていく
    }

  int n;  cin >> n; // query
  // input    <-   24
  // output   ->   24 = 2^3 * 3^1
  while(n--){
    int a;  cin >> a; // target : prime factorization
    map<int, int> mp; // key:prime   value:num
    cout << a << " = ";
    do{
      mp[eratos[a]]++;
      a = a / eratos[a];
    }while(a != 1);
    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
      cout << itr->first << "^" << itr->second << " * ";
    cout << endl;
  }
  return 0;
}
