#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a(10, 2); // len = 10,  {2, 2, 2, ..., 2} de syoki

  for(int i=0; i<a.size(); i++)
    cin >> a.at(i);

  cout << a.size() << endl;
  a.push_back(2222);  // saigo ni tuika
  cout << a.size() << endl;

  
  int max = 0;
  for(int i=0; i<a.size(); i++)
    if(a.at(i) > max)
      max = a.at(i);
  
  cout << "max is " <<  max << endl;

  return 0;
}
  
