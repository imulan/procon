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
vector<int> G[N];

int ee = 0;
vector<int> et;
int L[N],R[N];
void dfs(int v){
    L[v] = ee++;
    et.pb(v);
    for(int c:G[v]){
        dfs(c);
    }
    R[v] = ee++;
    et.pb(v);
}

const int B = 448;

bool flip[B]={};
int sum[B]={};
int a[B][B];

void push(int bidx){
    if(!flip[bidx]) return;

    sum[bidx] = 0;
    rep(i,B){
        a[bidx][i] = !a[bidx][i];
        sum[bidx] += a[bidx][i];
    }

    flip[bidx] = false;
}

void FLIP(int l, int r){
    int lidx = l/B, ridx = r/B;
    push(lidx);
    push(ridx);
    if(lidx == ridx){
        for(int i=l; i<=r; ++i){
            if(a[lidx][i%B] == 1) --sum[lidx];
            else ++sum[lidx];
            a[lidx][i%B] = !a[lidx][i%B];
        }
    }
    else{
        for(int i=l%B; i<B; ++i){
            if(a[lidx][i%B] == 1) --sum[lidx];
            else ++sum[lidx];
            a[lidx][i%B] = !a[lidx][i%B];
        }
        for(int bidx=lidx+1; bidx<ridx; ++bidx){
            flip[bidx] = !flip[bidx];
            sum[bidx] = B-sum[bidx];
        }
        for(int i=0; i<=r%B; ++i){
            if(a[ridx][i%B] == 1) --sum[ridx];
            else ++sum[ridx];
            a[ridx][i%B] = !a[ridx][i%B];
        }
    }
}

int SUM(int l, int r){
    int lidx = l/B, ridx = r/B;
    push(lidx);
    push(ridx);
    int ret = 0;
    if(lidx == ridx){
        for(int i=l; i<=r; ++i) ret += a[lidx][i%B];
    }
    else{
        for(int i=l%B; i<B; ++i) ret += a[lidx][i%B];
        for(int bidx=lidx+1; bidx<ridx; ++bidx) ret += sum[bidx];
        for(int i=0; i<=r%B; ++i) ret += a[ridx][i%B];
    }
    return ret;
}

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    for(int i=1; i<n; ++i){
        int p;
        cin >>p;
        --p;
        G[p].pb(i);
    }

    dfs(0);

    vector<char> c(n);
    rep(i,n) cin >>c[i];

    rep(i,ee){
        if(c[et[i]] == 'G'){
            a[i/B][i%B] = 1;
            ++sum[i/B];
        }
    }

    rep(i,q){
        int v;
        scanf(" %d", &v);
        --v;
        FLIP(L[v],R[v]);
        int s = SUM(0,ee-1);

        if(s/2 > n/2) printf("broccoli\n");
        else printf("cauliflower\n");
    }
    return 0;
}
