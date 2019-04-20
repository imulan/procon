#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<ll,ll>;
using P = pair<pi, char>;

const ll INF = LLONG_MAX/3;

vector<P> read_p(){
    vector<P> s;
    s.pb({{1,INF}, '#'});

    while(1){
        char c;
        scanf(" %c", &c);

        if(c=='E') break;

        if(c=='D'){
            ll x;
            scanf(" %lld", &x);
            --x;

            ll cur = 0;
            vector<P> ns;
            for(auto itr:s){
                pi range = itr.fi;
                ll L = range.se - range.fi + 1;

                if(cur <= x && x < cur+L){
                    if(x-cur-1 >= 0) ns.pb({{range.fi, range.fi+x-cur-1}, itr.se});
                    if(range.se - (range.fi+x-cur+1) >= 0) ns.pb({{range.fi+x-cur+1, range.se}, itr.se});
                }
                else ns.pb(itr);

                cur += L;
            }
            s = ns;
        }
        else{
            char add;
            ll x;
            scanf(" %lld %c", &x, &add);
            --x;

            ll cur = 0;
            vector<P> ns;
            for(auto itr:s){
                pi range = itr.fi;
                ll L = range.se - range.fi + 1;

                if(cur <= x && x < cur+L){
                    if(x-cur-1 >= 0) ns.pb({{range.fi, range.fi+x-cur-1}, itr.se});
                    ns.pb({{-1,-1}, add});
                    if(range.se - (range.fi+x-cur) >= 0) ns.pb({{range.fi+x-cur, range.se}, itr.se});
                }
                else ns.pb(itr);

                cur += L;
            }
            s = ns;
        }
    }

    // 結合
    int sz = s.size();

    vector<P> ret;
    int idx = 0;
    while(idx < sz){
        if(idx<sz-1 && s[idx].fi.se+1 == s[idx+1].fi.fi){
            ret.pb({{s[idx].fi.fi, s[idx+1].fi.se} , s[idx].se});
            idx += 2;
        }
        else{
            ret.pb(s[idx]);
            ++idx;
        }
    }

    return ret;
}

int main(){
    vector<P> x = read_p();
    vector<P> y = read_p();

    // dbg(x);
    // dbg(y);

    int ans = 1;
    if(x==y) ans = 0;
    cout << ans << endl;
    return 0;
}
