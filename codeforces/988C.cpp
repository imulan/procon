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

using pi = pair<int,int>;

void solve(){
    int k;
    scanf(" %d", &k);

    map<ll,vector<pi>> m;
    rep(i,k){
        int n;
        scanf(" %d", &n);

        vector<ll> a(n);
        ll sum = 0;
        map<ll,int> v2id;
        rep(j,n){
            scanf(" %lld", &a[j]);
            sum += a[j];
            v2id[a[j]] = j;
        }

        for(const auto &p:v2id){
            m[sum - p.fi].pb({i+1, p.se+1});
        }
    }

    for(const auto &p:m){
        vector<pi> v = p.se;
        if(v.size()>=2){
            printf("YES\n");
            rep(i,2) printf("%d %d\n", v[i].fi, v[i].se);
            return;
        }
    }
    printf("NO\n");
}

int main(){
    solve();
    return 0;
}
