#include <bits/stdc++.h>
using namespace std;

int n;

bool dfs(int i, int sum){
  if(i == n)  return sum == k;

  if(dfs(i+1, sum)) return true;

  if(dfs(i+1, sum+a[i])) return true;

  return false;
}

int main(){
  return 0;
}
