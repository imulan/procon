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

const ll mod = 1e9;
const int N = 41;
ll f[N];

// const int B = 3;
const int B = 317;

int add[B]={};
int ct[B][N]={};

int x[B][B];

void update_ct(int bid)
{
    assert(add[bid]==0);
    fill(ct[bid],ct[bid]+N,0);
    rep(i,B)if(x[bid][i]<N) ++ct[bid][x[bid][i]];
}

void add_one(int l, int r)
{
    int lid=l/B, rid=r/B;
    if(lid==rid)
    {
        for(int i=l; i<=r; ++i)
        {
            int v = x[lid][i%B];
            if(v<N) --ct[lid][v];
            ++x[lid][i%B];
            ++v;
            if(v<N) ++ct[lid][v];
        }
    }
    else
    {
        for(int i=l; i<B*(lid+1); ++i)
        {
            int v = x[lid][i%B];
            if(v<N) --ct[lid][v];
            ++x[lid][i%B];
            ++v;
            if(v<N) ++ct[lid][v];
        }
        for(int i=B*rid; i<=r; ++i)
        {
            int v = x[rid][i%B];
            if(v<N) --ct[rid][v];
            ++x[rid][i%B];
            ++v;
            if(v<N) ++ct[rid][v];
        }
        for(int bid=lid+1; bid<rid; ++bid) ++add[bid];
    }
}

void update(int idx, int v)
{
    int bid = idx/B;
    // add
    rep(i,B) x[bid][i] += add[bid];
    add[bid] = 0;
    // update
    x[bid][idx%B] = v;
    update_ct(bid);
}

ll query(int l, int r)
{
    int lid=l/B, rid=r/B;
    ll ret = 0;
    if(lid==rid)
    {
        for(int i=l; i<=r; ++i)
        {
            int v = x[lid][i%B]+add[lid];
            if(v<N) (ret+=f[v])%=mod;
        }
    }
    else
    {
        for(int i=l; i<B*(lid+1); ++i)
        {
            int v = x[lid][i%B]+add[lid];
            if(v<N) (ret+=f[v])%=mod;
        }
        for(int i=B*rid; i<=r; ++i)
        {
            int v = x[rid][i%B]+add[rid];
            if(v<N) (ret+=f[v])%=mod;
        }
        for(int bid=lid+1; bid<rid; ++bid)
        {
            rep(i,N)
            {
                int v=i+add[bid];
                if(v<N) (ret+=(f[v]*ct[bid][i])%mod)%=mod;
            }
        }
    }
    return ret;
}

int main()
{
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    rep(i,B)rep(j,B) x[i][j]=1919;

    int n,Q;
    scanf(" %d %d", &n, &Q);
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        x[i/B][i%B]=a;
    }

    rep(i,B) update_ct(i);

    while(Q--)
    {
        int T;
        scanf(" %d", &T);
        if(T==1)
        {
            int l,r;
            scanf(" %d %d", &l, &r);
            --l; --r;
            add_one(l,r);
        }
        else if(T==2)
        {
            int l,r;
            scanf(" %d %d", &l, &r);
            --l; --r;
            printf("%lld\n", query(l,r));
        }
        else
        {
            int idx,v;
            scanf(" %d %d", &idx, &v);
            update(idx-1,v);
        }

        // printf("CHECK:\n");
        // rep(i,n) printf("%d%c", x[i/B][i%B], " \n"[i==n-1]);
    }

    return 0;
}
