#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  int nw,nb;
  cin >>nw;
  std::vector<int> w(nw);
  rep(i,nw) cin >>w[i];
  cin >>nb;
  std::vector<int> b(nb);
  rep(i,nb) cin >>b[i];

  sort(w.begin(),w.end());
  sort(b.begin(),b.end());

  int p=0,q=0;
  //白を一番下に積む時
  bool white=true;
  int ww=nw-1;
  int bb=nb-1;
  int now=100;
  while(1){
    if(white){
      while(now<=w[ww]){
        --ww;
        if(ww==-1) break;
      }

      if(ww==-1) break;
      else{
        ++p;
        now=w[ww];
        white=false;
      }
    }
    else{
      while(now<=b[bb]){
        --bb;
        if(bb==-1) break;
      }

      if(bb==-1) break;
      else{
        ++p;
        now=b[bb];
        white=true;
      }
    }
  }


  //黒を一番下に積む時
  white=false;
  ww=nw-1;
  bb=nb-1;
  now=100;
  while(1){
    if(white){
      while(now<=w[ww]){
        --ww;
        if(ww==-1) break;
      }

      if(ww==-1) break;
      else{
        ++q;
        now=w[ww];
        white=false;
      }
    }
    else{
      while(now<=b[bb]){
        --bb;
        if(bb==-1) break;
      }

      if(bb==-1) break;
      else{
        ++q;
        now=b[bb];
        white=true;
      }
    }
  }

  std::cout << max(p,q) << std::endl;
  return 0;
}
