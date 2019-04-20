#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using ll = long long;
using pi = pair<ll,int>;

void solve(istream &ifs, ostream &ofs){
    int n,q;
    ifs >>n >>q;

    vector<int> t(n), k(n);
    rep(i,n)
    {
        char c;
        ifs >>c >>t[i] >>k[i];
        if(c=='-') k[i] = -k[i];
    }

    vector<pi> b(q);
    rep(i,q)
    {
        int x;
        ifs >>x;
        b[i] = {x,i};
    }

    sort(all(b));

    vector<ll> d(n+1);
    rep(i,n)
    {
        d[i+1] = d[i] + k[i];
    }

    ll min_d = LLONG_MAX;
    rep(i,n+1) min_d = min(min_d,d[i]);

    map<int,int> m;
    rep(i,n-1)
    {
        int T = t[i+1]-t[i];
        // dbg(T);dbg(d[i+1]);
        if(d[i+1]<0) m[-d[i+1]] += T;
    }

    vector<ll> wid,dep;
    vector<ll> sum;
    for(const auto &p:m)
    {
        dep.push_back(p.fi);
        wid.push_back(p.se);
        sum.push_back((ll)p.fi*p.se);
    }

    int SZ = sum.size();

    vector<ll> ss(SZ+1),sw(SZ+1);
    rep(i,SZ)
    {
        ss[i+1] = ss[i]+sum[i];
        sw[i+1] = sw[i]+wid[i];
    }

    // dbg(wid);
    // dbg(dep);
    // dbg(sum);
    // dbg(ss);

    vector<string> ans(q);
    rep(i,q)
    {
        int ID = b[i].se;
        int v = b[i].fi;

        if(v+min_d>=0) ans[ID] = "0";
        else if(v+d[n]<0) ans[ID] = "INFINITY";
        else
        {
            int idx = lower_bound(all(dep), v) - dep.begin();
            ll U = ss[SZ] - ss[idx];
            ll W = sw[SZ] - sw[idx];

            // dbg(U);
            // dbg(idx);
            // dbg(W);

            U -= W*v;
            ans[ID] = to_string(U);
        }
    }

    rep(i,q) ofs << ans[i] << endl;
}

int main(int args, char* argv[]){
  if(args>1){
    solve(cin, cout);
  } else {
    ifstream ifs = ifstream("expect.in");
    ofstream ofs = ofstream("expect.out");
    solve(ifs, ofs);
  }
  return 0;
}
