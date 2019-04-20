#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(auto i=(ll)0;i<(ll)n;i++)
#define all(a) a.begin(),a.end()
#define mmax(x,y)  (x>y?x:y)

ll N;
vector<pair<ll,ll>> r;

bool same(){
  rep(i,N-1)if(r[i].first != r[i+1].first)return false;
  return true;
}

int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  r.resize(N);
  rep(i,N){
    ll tmp;
    cin >> tmp;
    r[i] = make_pair(tmp,i);
  }
  sort(all(r));

  vector<pair<ll,ll>> def_r(r);
  for(int tt=r[0].first; tt>=0; --tt){
    ll cnt = 0;
    vector<string> ans;

    //   printf(" tt %d\n", tt);
    r = def_r;

    ll sm = 0;
    rep(i,N)sm += r[i].first-tt;
    if(sm == 1) continue;

    if(N >= 3 && sm % 2 == 1){
        r[N-1].first = mmax(0,r[N-1].first-1);
        r[N-2].first = mmax(0,r[N-2].first-1);
        r[N-3].first = mmax(0,r[N-3].first-1);
        string tmp;
        rep(i,N){
        if(i == r[N-1].second || i == r[N-2].second || i == r[N-3].second)tmp.push_back('1');
        else tmp.push_back('0');
        }
        ans.push_back(tmp);
        sort(all(r));
        cnt++;
    }

    while(!same()){
        //rep(i,N)cout << " " << r[i].first << " " << r[i].second << endl;
        r[N-1].first = mmax(0,r[N-1].first-1);
        r[N-2].first = mmax(0,r[N-2].first-1);
        string tmp;
        rep(i,N){
        if(i==r[N-1].second || i == r[N-2].second)tmp.push_back('1');
        else tmp.push_back('0');
        }
        ans.push_back(tmp);
        sort(all(r));
        cnt++;
    }

    // printf(" r0 %d\n", r[0].first);
    if(r[0].first == tt){
        cout << r[0].first << endl;
        cout << cnt << endl;
        rep(i,cnt)cout << ans[i] << endl;
        break;
    }
  }
  return 0;
}
