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
const int N = 10000010;
const ll INF = LLONG_MAX/3;
vector<int> pos[N];

inline ll lcm(ll x, ll y){
    return x/__gcd(x,y)*y;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        pos[a[i]].pb(i);
    }

    ll ans = INF;
    pi idx(-1,-1);
    for(int i=1; i<N; ++i){
        pi t(-1,-1);
        for(int j=i; j<N; j+=i){
            for(int x:pos[j]){
                if(t.fi == -1) t.fi = x;
                else if(t.se == -1) t.se = x;
                else break;
            }
            if(t.se != -1) break;
        }

        if(t.se != -1){
            ll L = lcm(a[t.fi], a[t.se]);
            if(L < ans){
                ans = L;
                idx = t;
            }
        }
    }

    if(idx.fi > idx.se) swap(idx.fi, idx.se);
    printf("%d %d\n", idx.fi+1, idx.se+1);
    return 0;
}
