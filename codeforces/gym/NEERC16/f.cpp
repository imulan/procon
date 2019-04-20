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

ll f(ll x)
{
    return x*(x+1)/2;
}

void solve(istream &ifs, ostream &ofs){
    string s;
    ifs >> s;

    int n = s.size();

    double dp=0, x=0;
    ll y=0;
    for(int i=n-1; i>=0; --i)
    {
        if(s[i]=='W') y+=n-i;

        ll add = y;
        if(s[i]=='W') add = f(n-i)-y;
        dp = (x+add)/(n-i);
        x += dp;
    }

    ofs << setprecision(12);
    ofs << dp;
    ofs << '\n';
}

int main(int args, char* argv[]){
  if(args>1){
    solve(cin, cout);
  } else {
    ifstream ifs = ifstream("foreign.in");
    ofstream ofs = ofstream("foreign.out");
    solve(ifs, ofs);
  }
  return 0;
}
