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

// 2*3*5*7*11*13*17*19*23*29*31*37*41
// = 304,250,263,527,210

const int P = 13;
ll p[P]={2,3,5,7,11,13,17,19,23,29,31,37,41};

double calc(ll n){
    ll div = n;
    ll s = 1;
    rep(i,P){

        ll mul = 1;
        ll now = 1;
        while(n%p[i]==0){
            n /= p[i];
            now *= p[i];
            mul += now;
        }
        s *= mul;
    }

    return (double)s/div;
}

const ll LIM = 1000000000000010LL;
map<ll,double> memo;

void dfs(ll v, int idx, int nowct, int prect){
    if(v > LIM) return;
    if(idx == P) return;

    if(!memo.count(v)) memo[v] = calc(v);

    if(prect > nowct) dfs(v*p[idx], idx, nowct+1, prect);
    dfs(v, idx+1, 0, nowct);
}

int main(){
    dfs(1,0,0,50);

    double val = 0;
    vector<ll> v;
    vector<double> a;
    for(const auto &pp:memo){
        if(pp.se > val){
            val = pp.se;
            v.pb(pp.fi);
            a.pb(pp.se);
        }
    }
    v.pb(LIM);

    ll k;
    while(cin >>k,k){
        int idx = upper_bound(all(v), k) - v.begin();
        printf("%.10f\n", a[idx-1]);
    }
    return 0;
}
