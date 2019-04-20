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

// const int B = 20;
// const int SZ = 2;

const int B = 1000;
const int SZ = 100;

const int INF = 123456789;
const ll LINF = LLONG_MAX/3;

int X[2];

int x[2][B][SZ];
int ADD[2][B];

int MIN[2][B], MAX[2][B];
unordered_map<int,int> ct[2][B];

void update(int t, int bid){
    MIN[t][bid] = INF;
    MAX[t][bid] = -INF;
    ct[t][bid].clear();

    rep(i,SZ){
        int idx = bid*SZ+i;
        if(idx>=X[t]) break;

        MIN[t][bid] = min(MIN[t][bid], x[t][bid][i]);
        MAX[t][bid] = max(MAX[t][bid], x[t][bid][i]);
        ++ct[t][bid][x[t][bid][i]];
    }
}

void push(int t, int bid){
    if(ADD[t][bid]==0) return;

    rep(i,SZ){
        int idx = bid*SZ+i;
        if(idx>=X[t]) break;
        x[t][bid][i] += ADD[t][bid];
    }
    ADD[t][bid]=0;
}

void add(int t, int l, int r, int v){
    int lid = l/SZ, rid = r/SZ;
    push(t,lid);
    push(t,rid);
    if(lid==rid){
        for(int i=l; i<=r; ++i) x[t][lid][i%SZ] += v;
        update(t,lid);
    }
    else{
        for(int bid = lid+1; bid < rid; ++bid) ADD[t][bid] += v;

        for(int i=l; i<SZ*(lid+1); ++i) x[t][lid][i%SZ] += v;
        for(int i=SZ*rid; i<=r; ++i) x[t][rid][i%SZ] += v;
        update(t,lid);
        update(t,rid);
    }
}

ll QUERY(int t, int l, int r, int mm){
    int lid = l/SZ, rid = r/SZ;

    int ret = -INF;
    function<int(int,int)> fn = [](int lh, int rh){ return max(lh,rh); };
    int (*MM)[B];
    MM = MAX;
    if(mm == 1){
        fn = [](int lh, int rh){ return min(lh,rh); };
        ret = INF;
        MM = MIN;
    }

    if(lid==rid){
        for(int i=l; i<=r; ++i) ret = fn(ret, x[t][lid][i%SZ]+ADD[t][lid]);
    }
    else{
        for(int bid = lid+1; bid < rid; ++bid) ret = fn(ret, MM[t][bid]+ADD[t][bid]);

        for(int i=l; i<SZ*(lid+1); ++i) ret = fn(ret, x[t][lid][i%SZ]+ADD[t][lid]);
        for(int i=SZ*rid; i<=r; ++i) ret = fn(ret, x[t][rid][i%SZ]+ADD[t][rid]);
    }
    return (ll)ret;
}

ll cnt(int t, int l, int r, int v){
    int ret = 0;
    int lid = l/SZ, rid = r/SZ;

    if(lid==rid){
        for(int i=l; i<=r; ++i){
            if(x[t][lid][i%SZ]+ADD[t][lid] == v) ++ret;
        }
    }
    else{
        for(int bid = lid+1; bid < rid; ++bid){
            int focus = v-ADD[t][bid];
            if(ct[t][bid].count(focus)) ret += ct[t][bid][focus];
        }

        for(int i=l; i<SZ*(lid+1); ++i){
            if(x[t][lid][i%SZ]+ADD[t][lid] == v) ++ret;
        }
        for(int i=SZ*rid; i<=r; ++i){
            if(x[t][rid][i%SZ]+ADD[t][rid] == v) ++ret;
        }
    }

    return (ll)ret;
}

int main(){
    int q;
    scanf(" %d %d %d", &X[0], &X[1], &q);

    rep(i,2){
        rep(j,X[i]){
            int v;
            scanf(" %d", &v);
            x[i][j/SZ][j%SZ] = v;
        }
        rep(j,B) update(i,j);
    }

    while(q--){
        int t;
        scanf(" %d", &t);

        if(t<=2){
            int l,r,v;
            scanf(" %d %d %d", &l, &r, &v);
            --l; --r;
            add(t-1,l,r,v);
        }
        else{
            int l[2],r[2];
            rep(i,2){
                scanf(" %d %d", &l[i], &r[i]);
                --l[i]; --r[i];
            }

            ll C = LINF;
            if(t==4) C = -C;

            ll ans = 0;

            rep(i,2)rep(j,2){
                ll va = QUERY(0,l[0],r[0],i);
                ll vb = QUERY(1,l[1],r[1],j);

                if(t==3) C = min(C, va*vb);
                else C = max(C, va*vb);
            }

            if(C==0){
                ll a0 = cnt(0,l[0],r[0],0);
                ll b0 = cnt(1,l[1],r[1],0);

                ans += a0*(r[1]-l[1]+1);
                ans += b0*(r[0]-l[0]+1);
                ans -= a0*b0;
            }
            else{
                set<pair<ll,ll>> S;
                rep(i,2)rep(j,2){
                    ll va = QUERY(0,l[0],r[0],i);
                    ll vb = QUERY(1,l[1],r[1],j);

                    if(va*vb == C) S.insert({va,vb});
                }

                for(const auto &p:S){
                    int va = p.fi, vb = p.se;
                    ans += cnt(0,l[0],r[0],va) * cnt(1,l[1],r[1],vb);
                }
            }
            printf("%lld %lld\n", C, ans);
        }
    }
    return 0;
}
