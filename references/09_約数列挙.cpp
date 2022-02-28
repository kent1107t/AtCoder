#include <bits/stdc++.h>
using namespace std;

int main(){
  long n;  cin >> n;
  vector<long> ans;

  for(long i=1; i*i<=n; i++)
    if(n%i==0){
      ans.push_back(i);
      if(i*i != n)  ans.push_back(n/i);
    }

  sort(ans.begin(), ans.end());

  for(long i : ans)
    cout << i << " ";
  cout << endl;

  return 0;
}
