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

const int N = 100010;
const ll INF = LLONG_MAX/3;
ll v[N]={};
ll t[N]={};

ll pret[N]={};

ll full[N]={};
ll part[N]={};

ll ans[N]={};
int main(){
    int n;
    cin >>n;
    rep(i,n) cin >>v[i+1];
    rep(i,n) cin >>t[i+1];

    for(int i=1; i<=n; ++i) pret[i] = pret[i-1]+t[i];
    pret[n+1] = INF;

    for(int i=1; i<=n; ++i){
        int idx = lower_bound(pret,pret+n+1,v[i]+pret[i-1])-pret;
        ++full[i];
        --full[idx];

        ll rem = v[i] - (pret[idx-1] - pret[i-1]);
        // printf("ADD i %d: idx %d rem %lld\n",i,idx,rem);
        part[idx] += rem;
    }

    rep(i,N-1) full[i+1] += full[i];

    for(int i=1; i<=n; ++i){
        ans[i] = full[i]*t[i];
        ans[i] += part[i];
    }
    for(int i=1; i<=n; ++i) printf("%lld%c", ans[i], " \n"[i==n]);
    return 0;
}
