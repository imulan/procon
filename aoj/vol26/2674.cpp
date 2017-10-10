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

const int INF = 1234567890;

int D;
int x[100000];

const int B = 100;
const int SZ = 1000;

// default,sorted
vector<int> d[B],s[B];

int f(int l, int r, int p, int q)
{
    int ret = r-l+1;
    for(int i=l; i<=r; ++i)if(p<=x[i] && x[i]<=q) --ret;
    return ret;
}

int g(int bid, int p, int q)
{
    int lidx = lower_bound(all(s[bid]), p) - s[bid].begin();
    int ridx = upper_bound(all(s[bid]), q) - s[bid].begin();
    int ct = ridx - lidx;
    return SZ - ct;
}

int query(int l, int r, int e)
{
    int a = min(x[l],x[r]), b = max(x[l],x[r]);
    int lb = l/SZ, rb = r/SZ;
    int ret = 0;
    if(lb==rb) ret += f(l,r,a-e,b+e);
    else
    {
        ret += f(l,SZ*(lb+1)-1,a-e,b+e);
        for(int i=lb+1; i<rb; ++i) ret += g(i,a-e,b+e);
        ret += f(SZ*rb,r,a-e,b+e);
    }
    return ret;
}

int main()
{
    scanf(" %d", &D);
    rep(i,D) scanf(" %d", &x[i]);

    rep(i,B)
    {
        d[i] = vector<int>(SZ,INF);
        rep(j,SZ)
        {
            int id = i*SZ+j;
            if(id<D) d[i][j] = x[id];
        }

        s[i] = d[i];
        sort(all(s[i]));
    }

    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int l,r,e;
        scanf(" %d %d %d", &l, &r, &e);
        --l; --r;
        printf("%d\n", query(l,r,e));
    }
    return 0;
}
