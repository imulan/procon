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

using pi = pair<int,int>;

int solve(){
    int a,b,p,q;
    scanf(" %d %d %d %d", &a, &b, &p, &q);

    const int mod = 2*q;
    auto g = [&](int x){
        ll ret = 2LL*p*x;
        ret %= mod;
        return (int)ret;
    };

    int W = b-a+1;

    int w = 1;
    while(1){
        int t = (w+1);
        if(t*t > W) break;
        ++w;
    }

    // list up [a, a+w-1]
    set<int> used;
    vector<pi> v;
    rep(i,w){
        int x = a+i;
        int y = g(x);
        if(!used.count(y)){
            v.pb({y,x});
            used.insert(y);
        }
    }

    sort(all(v));
    int V = v.size();

    int diff = INT_MAX;
    int ans = -1;

    auto CHECK = [&](int x){
        int val = g(x);
        int d = abs(q-val);
        if(d<diff || (d==diff && x<ans)){
            diff = d;
            ans = x;
        }
    };

    rep(i,33333){
        int y = i*w;
        // searching: [y+a, y+a+(w-1)]
        int R = y+a+w-1;
        if(b < R){
            for(const pi &pp:v){
                if(y+pp.se > b) continue;
                CHECK(y+pp.se);
            }
            break;
        }
        else{
            int gy = g(y);

            int t = q-gy;
            if(t<0) t += mod;

            int idx = lower_bound(all(v), pi(t,-1))-v.begin();
            rep(j,2){
                int jj = (idx+j-1+V)%V;
                CHECK(y+v[jj].se);
            }
        }
    }

    assert(a<=ans && ans<=b);
    return ans;
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) printf("%d\n", solve());
    return 0;
}
