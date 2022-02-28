#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  for(int bit=0; bit<1<<n; bit++){
    vector<int> a;
    for(int i=0; i<n; i++)
      if(bit & (1<<i))
	a.push_back(i);

    for(int i : a)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}
    
