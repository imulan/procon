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

using pl = pair<ll,ll>;

ll f(pl p, ll x){
    return p.fi*x + p.se;
}

bool check(pl p, pl q, pl r){
    ll lh = (r.se-p.se)*(q.fi-r.fi);
    ll rh = (r.se-q.se)*(p.fi-r.fi);
    return lh<rh;
}

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<pl> v;
    rep(i,n)
    {
        pl now(-2*i, a[i]+(ll)i*i);
        if(v.size()<2){
            v.pb(now);
            continue;
        }

        while(v.size()>=1){
            if(v.size()==1){
                v.pb(now);
                break;
            }

            bool res = check(v[v.size()-2], v[v.size()-1], now);
            if(res){
                v.pb(now);
                break;
            }
            else v.resize(v.size()-1);
        }
    }
    int V = v.size();

    int idx=0;
    rep(i,n){
        while(idx+1<V && f(v[idx],i)>f(v[idx+1],i)) ++idx;
        cout << f(v[idx],i)+(ll)i*i << endl;
    }
    return 0;
}
