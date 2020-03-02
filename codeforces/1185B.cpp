#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using P = pair<char,int>;

vector<P> f(const string &s){
    int n = s.size();
    vector<P> ret;
    int i = 0;
    while(i<n){
        int l = i;
        while(i<n && s[i]==s[l]) ++i;
        ret.pb({s[l],i-l});
    }
    return ret;
}

bool solve(){
    string s,t;
    cin >>s >>t;

    vector<P> vs=f(s), vt=f(t);
    if(vs.size() != vt.size()) return false;
    int V = vs.size();
    rep(i,V){
        if(vs[i].fi != vt[i].fi) return false;
        if(vs[i].se > vt[i].se) return false;
    }
    return true;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
