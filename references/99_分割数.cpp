#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;  cin >> n >> m;
  int mod = 1e7+7;
  int dp[100][100] = {0};  dp[0][0] = 1;

  for(int i=1; i<=m; i++)
    for(int j=0; j<=n; j++)
      if(j - i >= 0)
	dp[i][j] = (dp[i-1][j] + dp[i][j-i]) & mod;
      else
	dp[i][j] = dp[i-1][j];
  
  cout << dp[m][n] << endl;
  return 0;
}
