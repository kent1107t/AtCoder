#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
  int size;
  vector<int> dat;
  SegmentTree(int n_){
    size = 1;
    while(size < n_)  size *= 2;
    dat.resize(size*2, 1e9); // 最小を持つ場合1e9などで初期化
  }

  void update(int k, int x){ // [k] = x にアップデートしたい
    k += size - 1;
    dat[k] = x;
    while(k > 0){
      k = (k - 1) / 2;
      dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
  }
  // [a, b)が対象の区間 kは接点の番号
  // 最初の呼び出しは query(a, b, 0, 0, size) で呼ぶ
  int query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l)  return 1e9;  // 範囲外の時

    if(a <= l && r <= b)  return dat[k];  // 範囲が[a, b)に完全に含まれる場合
    
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    return min(vl, vr);
  }

  void show(){
    for(int i=0; i<size; i++)
      cout << dat[i+size-1] << " ";
    cout << endl;
  }
};

int main(){
  int n, com;  cin >> n;
  SegmentTree st(n);



  // ここからは性能確認のための

  while(cout << "put com.  1:update  2:query  3:show  0:exit ", cin >> com, com){
    if(com == 1){
      int k, a;
      cout << "where?  :  ";  cin >> k;
      cout << "number?  :  ";  cin >> a;
      st.update(k, a);
    }else if(com == 2){
      int a, b;
      cout << "where you need?  :  ";  cin >> a >> b;
      cout << st.query(a, b, 0, 0, st.size) << endl;
    }else if(com == 3){
      st.show();
    }
  }
  return 0;
}
