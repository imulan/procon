#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int i;

  int a[3];
  rep(i,3) cin >>a[i];
  sort(a,a+3,greater<int>());

  int left=0,right=10000010;
  int mid;
  while(left<right){
    mid=(left+right)/2;

    bool end=(right-left<=1);
    if(end) mid=right;

    //mid個作れるか判定
    bool valid=true;
    if(a[0]<mid) valid=false;
    else{
      //とりあえず変える数
      int ch=(a[0]-mid)/2;

      if(a[1]>=mid){//足りてたら更に変える
        ch+=(a[1]-mid)/2;
      }
      else{
        ch-=(mid-a[1]);
      }

      if(a[2]+ch<mid){//足りない
        valid=false;
      }
    }

    if(end){
      if(!valid) mid=left;
      break;
    }

    if(valid) left=mid;
    else right=mid;
  }

  std::cout << mid << std::endl;
  return 0;
}
