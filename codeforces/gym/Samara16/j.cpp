#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

//const int B = 3;
const int B = 448;

ll mx[B],mn[B],add[B];
ll x[B][B];

void push(int bid){
    rep(i,B) x[bid][i] += add[bid];
    add[bid] = 0;

    mx[bid] = mn[bid] = x[bid][0];
    rep(i,B){
        mx[bid] = max(mx[bid], x[bid][i]);
        mn[bid] = min(mn[bid], x[bid][i]);
    }
}

ll MAX(int l, int r){
    int lidx = l/B, ridx=r/B;
    push(lidx);
    push(ridx);

    ll ret = 0;
    if(lidx==ridx){
        for(int i=l; i<=r; ++i) ret = max(ret, x[lidx][i%B]);
    }
    else{
        for(int i=l; i<(lidx+1)*B; ++i) ret = max(ret, x[lidx][i%B]);
        for(int b=lidx+1; b<ridx; ++b) ret = max(ret, mx[b]+add[b]);
        for(int i=ridx*B; i<=r; ++i) ret = max(ret, x[ridx][i%B]);
    }
    return ret;
}

void ADD(int l, int r, ll v){
    int lidx = l/B, ridx=r/B;

    if(lidx==ridx){
        for(int i=l; i<=r; ++i) x[lidx][i%B] += v;
    }
    else{
        for(int i=l; i<(lidx+1)*B; ++i) x[lidx][i%B] += v;
        for(int b=lidx+1; b<ridx; ++b) add[b] += v;
        for(int i=ridx*B; i<=r; ++i) x[ridx][i%B] += v;
    }

    push(lidx);
    push(ridx);
}

int FIND_MX(int v) {
    rep(i,B){
        if(mx[i]+add[i] == v){
            rep(j,B){
                if(x[i][j]+add[i]==v) return i*B+j;
            }
        }
    }

    while(1){}
}

int FIND_L(int idx, int v){
    int bid = idx/B;

    int ret = idx;
    while(ret>=bid*B){
        if(x[bid][ret%B]+add[bid] != v) return ret;
        --ret;
    }

    for(int b=bid-1; b>=0; --b){
        if(mx[b]+add[b]==v && mn[b]+add[b]==v) continue;

        ret = b*B + B-1;
        while(ret>=b*B){
            if(x[b][ret%B]+add[b] != v) return ret;
            --ret;
        }
    }
}

int FIND_R(int idx, int v){
    int bid = idx/B;
    int ret = idx;

    while(ret<(bid+1)*B){
        if(x[bid][ret%B]+add[bid] != v) return ret;
        ++ret;
    }

    for(int b=bid+1; b<B; ++b){
        if(mx[b]+add[b]==v && mn[b]+add[b]==v) continue;

        ret = b*B;
        while(ret<(b+1)*B){
            if(x[b][ret%B]+add[b] != v) return ret;
            ++ret;
        }
    }
}

int main(){
    int n;
    scanf(" %d", &n);

    rep(i,n){
        int a;
        scanf(" %d", &a);

        int idx = i+1;
        x[idx/B][idx%B] = a;
    }
    n+=2;

    rep(i,B) push(i);

    ll ans = 0;
    while(1){
        ll v = MAX(0,n-1);
        if(v==0) break;

        int idx = FIND_MX(v);

        int l = FIND_L(idx,v);
        int r = FIND_R(idx,v);

        ll max_lr = max(x[l/B][l%B]+add[l/B], x[r/B][r%B]+add[r/B]);
        ll diff = v - max_lr;
        assert(diff>0);

//        printf(" %d %d, [%d %d],  %d\n",v,idx,l,r,diff);
        ans += diff;

        ADD(l+1,r-1,-diff);
    }
    printf("%lld\n", ans);
    return 0;
}