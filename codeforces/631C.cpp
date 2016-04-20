#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

int main(int argc, char const *argv[]) {
  long i,j;

  long n,m;
  cin >>n >>m;

  std::vector<long> a(n);
  rep(i,n) scanf(" %ld", &a[i]);

  vector<pair<int,long>> v(m);
  rep(i,m) scanf(" %d %ld",&v[i].fi,&v[i].sc);

  vector<pair<int,long>> d;
  long now=0;
  for(i=m-1; i>=0; --i){
    if(now<v[i].sc){
      d.pb(v[i]);
      now=v[i].sc;
    }
  }

  reverse(d.begin(),d.end());
  //rep(i,d.size()) printf(" %d %ld\n",d[i].fi,d[i].sc);
  //cout<<"dsize "<<d.size()<<endl;

  vector<long> ans(n);
  for(i=d[0].sc; i<n; ++i) ans[i]=a[i];

  a.resize(d[0].sc);
  sort(a.begin(),a.end());

  //rep(i,a.size()) printf("   %ld\n",a[i]);

  long left=0,right=d[0].sc-1;
  now=d[0].sc-1;
  for(i=1; i<(long)d.size(); ++i){
    //この分を除外
    long w=d[i-1].sc-d[i].sc;
    //printf("w=%ld\n",w);

    if(d[i-1].fi==1){
      //右を詰める
      rep(j,w){
        ans[now]=a[right-j];
        --now;
      }
      right-=w;
    }
    else{
      //左を詰める
        rep(j,w){
          ans[now]=a[left+j];
          --now;
        }
        left+=w;
    }
  }

  if(d[d.size()-1].fi==1){//右から
    for(i=right;i>=left;--i){
      ans[now]=a[i];
      --now;
    }
  }
  else{//左から
    for(i=left;i<=right;++i){
      ans[now]=a[i];
      --now;
    }
  }

  //出力
  rep(i,n){
    if(i) printf(" ");
    printf("%ld", ans[i]);
  }
  printf("\n");
  return 0;
}
