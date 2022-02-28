#include <stdio.h>
#define max(x, y) ((x)<(y) ? (y) : (x))

long mypow(long a, long n){
  long r = 1;
  while(n){
    if(n & 1)  r = r * a;
    a = a * a;
    n = n >> 1;
  }
  return r;
}

int main(){
  long n, p;  scanf("%ld %ld", &n, &p);
  int table[100][2] = {0}, size = 0;
  for(long i=2; i*i<=p; i++){
    if(p % i == 0){
      table[++size][0] = i;
      while(p % i == 0){
	p /= i;
	table[size][1]++;
      }
    }
  }
  if(p != 1){
    table[++size][0] = p;
    table[size][1] = 1;
  }

  long ans = 1;
  for(int i=1; i<=size; i++){
    if(table[i][1]/n){
      ans = ans * mypow(table[i][0], (table[i][1]/n));
    }
  }

  printf("%ld\n", ans);
  
  return 0;
}
