#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

string ltos(long n){
  ostringstream ost;
  ost << n;
  return ost.str();
}

int main(int argc, char const *argv[]) {
  int i,j;

  //変換、逆変換
  int f[10],fi[10];

  rep(i,10){
    int b;
    cin >>b;

    f[b]=i;
    fi[i]=b;
  }

  int n;
  cin >>n;

  std::vector<long> v;

  //変換して配列vに入れる
  rep(i,n){
    long a;
    scanf(" %ld", &a);

    string t=ltos(a);

    rep(j,t.size()) t[j]=f[t[j]-'0']+'0';

    //cout<<"convert: "<<t<<endl;
    v.pb(atol(t.c_str()));
  }

  //vをソート
  sort(v.begin(), v.end());

  //逆変換して表示
  rep(i,n){
    string t=ltos(v[i]);
    rep(j,t.size()) t[j]=fi[t[j]-'0']+'0';
    std::cout << t << std::endl;
  }

  return 0;
}
