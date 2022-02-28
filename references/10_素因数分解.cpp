#include <bits/c++.h>
using namespace std;

int main(){
  long n;  cin >> n;
  vector<pair<long, long>> ans;

  for(long i=2; i*i<n; i++){
    if(n % i)  continue;
    long cnt = 0;
    while(n%i == 0){
      cnt++;
      n /= i;
    }
    ans.push_back({i, cnt});
  }
  if(n != 1)  ans.push_back({n, 1});

  // firstに素数, secondにその指数を入れている

  for(auto i : ans)
    cout << i.first << " ^ " << i.second << endl;

  return 0;
}
