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
using P = pair<int,pi>;

const int Q = 500*500;
const int N = 510;

int h,w,k,q;
P query[Q];

int f[N][N];
int sf[N][N];

inline int s(int lx, int ly)
{
    int rx = lx+k-1, ry = ly+k-1;
    return sf[ry][rx] - sf[ry][lx-1] - sf[ly-1][rx] + sf[ly-1][lx-1];
}

bool broken(int X)
{
    memset(f,0,sizeof(f));
    rep(i,X+1)
    {
        int y = query[i].se.fi, x = query[i].se.se;
        f[y][x]=1;
    }

    memset(sf,0,sizeof(sf));
    for(int i=1; i<=h; ++i)for(int j=1; j<=w; ++j) sf[i][j] = sf[i-1][j]+sf[i][j-1]-sf[i-1][j-1]+f[i][j];

    for(int i=1; i<=h-k+1; ++i)for(int j=1; j<=w-k+1; ++j)
    {
        if(s(j,i) == k*k) return true;
    }

    return false;
}

int main()
{
    cin >>h >>w >>k >>q;
    rep(i,q)
    {
        int y,x,t;
        cin >>y >>x >>t;
        query[i] = P(t,pi(y,x));
    }
    sort(query,query+q);

    int l=-1, r=q;
    while(r-l>1)
    {
        int m = (l+r)/2;
        if(broken(m)) r=m;
        else l=m;
    }

    if(r==q) r=-1;
    else r = query[r].fi;

    cout << r << endl;
    return 0;
}
