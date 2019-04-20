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

using P = pair<ll,ll>;

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    cin >>n;

    map<ll,int> pos2idx;
    vector<ll> x(n),p(n);
    vector<P> v(n);
    rep(i,n){
        cin >>x[i] >>p[i];
        v[i] = {p[i],i};

        pos2idx[x[i]] = i;
    }

    sort(all(v));
    reverse(all(v));

    set<ll> c;

    vector<int> ans(n);
    ans[v[0].se] = -1;
    c.insert({x[v[0].se]});

    for(int i=1; i<n; ++i){
        int idx = v[i].se;

        int t = -1;
        auto itr = c.lower_bound(x[idx]);
        if(itr != c.end()){
            ll xx = *itr;
            t = pos2idx[xx];
        }
        if(itr != c.begin()){
            --itr;
            ll xx = *itr;

            if(t==-1) t = pos2idx[xx];
            else{
                int nt = pos2idx[xx];
                if( abs(x[idx]-x[t]) > abs(x[idx]-x[nt]) ){
                    t = nt;
                }
                else if( abs(x[idx]-x[t]) == abs(x[idx]-x[nt]) ){
                    if(p[t] < p[nt]) t = nt;
                }
            }
        }

        ans[idx] = t+1;
        c.insert(x[idx]);
    }

    rep(i,n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
