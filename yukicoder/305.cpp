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
  int i,j;
  bool found=false;
  while(1){
    int x;
    string lock;

    string ans="0000000000";
    rep(i,10){//左からi番目の桁について
      int ct[10]={0};
      rep(j,10){
        string r="0000000000";
        r[i]=j+'0';

        cout << r <<endl;
        cout <<flush;

        cin >>x >>lock;
        if(x==10){
          found=true;
          break;
        }
        else{
          ct[j]=x;
        }


      }
      if(found)break;
      else{
        int m=0;
        int r=-1;
        rep(j,10){
          if(m<ct[j]){
            m=ct[j];
            r=j;
          }
        }
        ans[i]='0'+r;
      }
    }
    if(found)break;

    cout << ans <<endl;
    cout <<flush;
    cin >>x >>lock;
    if(x==10){
      found=true;
      break;
    }
  }
  return 0;
}
