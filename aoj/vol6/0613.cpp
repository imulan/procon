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

using pl = pair<ll,ll>;

const int N = 14348907;
pl f[N],s[N];
int ff=0, ss=0;
bool vis[N]={};

const ll INF = 101010101010101010LL;
const int SEG = 1<<24;
ll dat[2*SEG-1];

inline void init()
{
    fill(dat,dat+2*SEG-1,-INF);
    rep(i,ff) dat[SEG-1+i] = f[i].se;
    for(int i=SEG-2; i>=0; --i) dat[i] = max(dat[2*i+1],dat[2*i+2]);
}

inline ll _query(int a, int b, int k, int l, int r)
{
    if(r<=a || b<=l) return -INF;
    if(a<=l && r<=b) return dat[k];
    ll vl=_query(a,b,2*k+1,l,(l+r)/2);
    ll vr=_query(a,b,2*k+2,(l+r)/2,r);
    return max(vl,vr);
}

inline ll query(int a, int b)
{
    return _query(a,b,0,0,SEG);
}

int main()
{
    int p3[17];
    p3[0]=1;
    for(int i=1; i<17; ++i) p3[i]=p3[i-1]*3;

    int n;
    ll D,x[30],y[30];
    scanf(" %d %lld", &n, &D);
    rep(i,n) scanf(" %lld %lld", &x[i], &y[i]);

    int F = n/2, S = n-F;

    rep(i,p3[F]-1)
    {
        if(vis[i]) continue;

        int mask = i;
        int rev = 0;
        ll ax=0,ay=0,bx=0,by=0;
        rep(j,F)
        {
            if(mask%3==0)
            {
                ax += x[j];
                ay += y[j];
                rev += p3[j];
            }
            else if(mask%3==1)
            {
                bx += x[j];
                by += y[j];
            }
            else rev += p3[j]*2;
            mask /= 3;
        }

        vis[i] = vis[rev] = true;
        f[ff++] = {bx-ax,by-ay};
        f[ff++] = {ax-bx,ay-by};
    }
    f[ff++] = {0,0};

    fill(vis,vis+N,false);
    rep(i,p3[S]-1)
    {
        if(vis[i]) continue;

        int mask = i;
        int rev = 0;
        ll ax=0,ay=0,bx=0,by=0;
        rep(j,S)
        {
            if(mask%3==0)
            {
                ax += x[F+j];
                ay += y[F+j];
                rev += p3[j];
            }
            else if(mask%3==1)
            {
                bx += x[F+j];
                by += y[F+j];
            }
            else rev += p3[j]*2;
            mask /= 3;
        }

        vis[i] = vis[rev] = true;
        s[ss++] = {bx-ax,by-ay};
        s[ss++] = {ax-bx,ay-by};
    }
    s[ss++] = {0,0};

    sort(f,f+ff);
    sort(s,s+ss,greater<pl>());

    init();

    ll ans = 0;
    int lidx = 0, ridx = 0;
    rep(i,ss)
    {
        ll X = s[i].fi, Y = s[i].se;
        while(ridx<ff && X+f[ridx].fi<=D) ++ridx;
        while(lidx<ridx && X+f[lidx].fi<-D) ++lidx;

        ans = max(ans, Y+query(lidx, ridx));
    }
    printf("%lld\n", ans);
    return 0;
}
