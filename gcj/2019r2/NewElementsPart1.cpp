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

const ll M = 1000000010LL;

using pl = pair<ll,ll>;

int solve(){
    int n;
    scanf(" %d", &n);
    vector<pl> p(n);
    rep(i,n) scanf(" %lld %lld", &p[i].fi, &p[i].se);

    set<pl> v;
    rep(i,n)rep(j,i){
        ll X = p[i].se-p[j].se;
        ll Y = p[j].fi-p[i].fi;
        if(X==0 || Y==0) continue;

        if(X<0){
            X *= -1;
            Y *= -1;
        }
        if(Y<0) continue;

        // printf(" %d %d : %lld %lld\n", j,i,X,Y);
        ll g = __gcd(X,Y);
        v.insert({X/g,Y/g});
    }

    return 1+(int)v.size();
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T) printf("Case #%d: %d\n", i+1, solve());
    return 0;
}
