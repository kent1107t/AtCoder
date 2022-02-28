#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &A, int m, int n){
  if(A.size() == n){
    for(int i=0; i<n; i++)
      cout << A[i] << " ";
    cout << endl;
    return;
  }

  for(int i=1; i<=m; i++){
    A.push_back(i);
    dfs(A, m, n);
    A.pop_back();
  }
}

int main(){
  int n, m;  cin >> n >> m;
  vector<int> A;
  dfs(A, m, n);
  return 0;
}
