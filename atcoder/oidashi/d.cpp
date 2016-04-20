#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

typedef pair<ll,ll> pl;
typedef vector<pl> vpl;

vpl pf(ll n){
  vpl ret;

  ll t=n;
  for(ll i=2; i*i<=n; ++i){
    if(t%i==0){
      ll ct=0;
      while(t%i==0){
        t/=i;
        ++ct;
      }
      ct*=2;
      ct%=6;
      if(ct>0) ret.pb(pl(i,ct));
    }
  }
  if(t>1) ret.pb(pl(t,2LL));

  return ret;
}

int main(int argc, char const *argv[]) {
  int i,j,k;

  int n;
  cin >>n;
  vector<ll> v(n);
  rep(i,n) cin >>v[i];

  vector<vpl> can;
  rep(i,n){
    vpl m=pf(v[i]);
    can.pb(m);

    /*
    printf(" %lld: ",v[i]);
    each(it,m) cout<<"("<<it->fi<<","<<it->sc<<") ";
    cout<<endl;
    */
  }

  int ans=0;
  rep(i,n){//i番目を入れることにした場合
    int tmp=1;
    vpl now=can[i];

    rep(j,n){
      if(i==j) continue;

      vpl v=can[j];
      bool valid=(now.size()==v.size());
      if(!valid) continue;

      rep(k,now.size()){
        if(!(now[k].fi==v[k].fi&&now[k].sc==v[k].sc)){
          valid=false;
          break;
        }
      }

      if(valid) ++tmp;
    }

    //printf("i %d, tmp %d\n",i,tmp);
    ans=max(ans,tmp);
  }

  std::cout << ans << std::endl;
  return 0;
}
