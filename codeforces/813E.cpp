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

const int N = 100000;
vector<int> idx[N];

const int B = 400;
const int INF = 19191919;

int b[N];
vector<int> sb[N/B];

int query(int l, int r){
    int ret = 0;

    int lid = l/B, rid = r/B;
    if(lid == rid){
        for(int i=l; i<=r; ++i) ret += (b[i]<l);
    }
    else{
        for(int i=l; i<B*(lid+1); ++i) ret += (b[i]<l);
        for(int bid=lid+1; bid<rid; ++bid){
            int add = lower_bound(all(sb[bid]), l) - sb[bid].begin();
            ret += add;
        }
        for(int i=B*rid; i<=r; ++i) ret += (b[i]<l);
    }

    return ret;
}

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        --a[i];
        idx[a[i]].pb(i);
    }

    fill(b,b+N,INF);
    rep(i,N){
        int SZ = idx[i].size();

        rep(j,min(k,SZ)) b[idx[i][j]] = -1;
        for(int j=k; j<SZ; ++j) b[idx[i][j]] = idx[i][j-k];
    }
    rep(i,N) sb[i/B].pb(b[i]);
    rep(i,N/B) sort(all(sb[i]));

    int q;
    scanf(" %d", &q);

    int ans = 0;
    while(q--){
        int x,y;
        scanf(" %d %d", &x, &y);
        int l = (x+ans)%n, r = (y+ans)%n;
        if(l>r) swap(l,r);

        ans = query(l,r);
        printf("%d\n", ans);
    }
    return 0;
}
