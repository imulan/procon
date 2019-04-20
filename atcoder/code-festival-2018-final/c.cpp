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

const ll INF = LLONG_MAX/5;

int main(){
    int n;
    cin >>n;

    vector<P> plan(n);
    rep(i,n){
        ll a,b;
        cin >>a >>b;
        plan[i] = {a,b};
    }
    sort(all(plan));

    int m;
    cin >>m;
    vector<P> v(m);
    rep(i,m){
        ll t;
        cin >>t;
        v[i] = {t,i};
    }
    sort(all(v));

    ll C = INF;
    int pidx = 0;
    vector<ll> ans(m,INF);
    rep(i,m){
        ll t = v[i].fi;
        int ID = v[i].se;

        while(pidx<n && plan[pidx].fi<=t){
            C = min(C, plan[pidx].se - plan[pidx].fi);
            ++pidx;
        }

        ans[ID] = min(ans[ID], t+C);
        if(pidx<n) ans[ID] = min(ans[ID], plan[pidx].se);
    }

    rep(i,m) cout << ans[i] << endl;
    return 0;
}
