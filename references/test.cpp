#include <bits/stdc++.h>
using namespace std;
#define F(I,B) for(int I=1;I<=B;I++)
int an=0,cu=0,n,m,c[99][99];
void s(int x,int y){
	if(c[x][y]==0)return;
	c[x][y]=0;cu++;
	an=max(an,cu);
	s(x+1,y);s(x,y+1);s(x-1,y);s(x,y-1);
	c[x][y]=1;
	cu--;
}

main(){
	cin>>n>>m;
	F(i,m)F(j,n)cin>>c[i][j];
	F(i,m)F(j,n)s(i,j);
	cout<<an<<endl;
}
