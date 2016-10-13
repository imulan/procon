#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SumSegTree{
    int n; vector<ll> dat;
    //初期化
    SumSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    ll get(int idx){
        idx+=n-1;
        ll ret=dat[idx];
        while(idx>0){
            idx=(idx-1)/2;
            ret+=dat[idx];
            // if(idx==0) break;
        }
        return ret;
    }
    //内部的に投げられるクエリ
    void _query(int a, int b, ll v, int k, int l, int r){
        if(r<=a || b<=l) return;

        if(a<=l && r<=b)
        {
            // printf("[%d,%d) -> +%lld\n", l,r,v);
            dat[k]+=v;
        }
        else{
            _query(a,b,v,2*k+1,l,(l+r)/2);
            _query(a,b,v,2*k+2,(l+r)/2,r);
        }
    }
    //[a,b)に+v
    void add(int a, int b, ll v){
        // printf("add query(%d, %d)\n", a,b);
        _query(a,b,v,0,0,n);
    }
};

const int N=300000;

int n,m,k;
// stations that i-th state has
vector<int> state[N];
int target[N];
int l[N],r[N];
ll a[N];

int L[N],R[N];

int main()
{
    //input
    scanf(" %d %d", &n, &m);

    rep(i,m)
    {
        int o;
        scanf(" %d", &o);
        --o;
        state[o].pb(i);
    }
    rep(i,n) scanf(" %d", &target[i]);
    scanf(" %d", &k);
    rep(i,k)
    {
        scanf(" %d %d %lld", &l[i], &r[i], &a[i]);
        --l[i];
        --r[i];
    }

    // initialize
    rep(i,n)
    {
        L[i]=-1;
        R[i]=k;
    }

    rep(T,20)
    {
        // printf(" %d iteration\n", T);
        vector<int> q[N];
        rep(i,n) q[(L[i]+R[i])/2].pb(i);

        SumSegTree st(m+1);
        rep(i,k)
        {
            if(l[i]<=r[i]) st.add(l[i],r[i]+1,a[i]);
            else
            {
                st.add(l[i],m,a[i]);
                st.add(0,r[i]+1,a[i]);
            }

            // printf(" %d addend\n", i);
            // rep(j,m) printf(" %d  get %lld\n", j,st.get(j));

            rep(j,q[i].size())
            {
                int s=q[i][j];

                ll tmp=0;
                rep(x,state[s].size())
                {
                    // printf(" access %d\n", state[s][x]);
                    tmp+=st.get(state[s][x]);
                    if(target[s]<=tmp) break;
                }
                // printf("state :%d, tmp %lld\n", s,tmp);

                if(target[s]<=tmp) R[s]=i;
                else L[s]=i;
            }
        }
    }

    // rep(i,n)printf("L,R %d, %d\n", L[i],R[i]);

    rep(i,n)
    {
        if(R[i]<k) printf("%d\n", R[i]+1);
        else printf("NIE\n");
    }

    return 0;
}
