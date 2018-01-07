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

int a[114514]={};

const int B = 317;
int b[B][B];
int x[B]={};

map<int,int> ct[B];

void update_ct(int bid)
{
    ct[bid].clear();
    rep(i,B)
    {
        if(b[bid][i]!=-1) ++ct[bid][b[bid][i]];
    }
}

void XOR(int l, int r, int val)
{
    int lb = l/B, rb = r/B;
    if(lb==rb)
    {
        for(int i=l%B; i<=r%B; ++i) b[lb][i]^=val;
    }
    else
    {
        for(int i=l%B; i<B; ++i) b[lb][i]^=val;
        for(int i=0; i<=r%B; ++i) b[rb][i]^=val;
        for(int i=lb+1; i<rb; ++i) x[i]^=val;
    }
    update_ct(lb);
    update_ct(rb);
}

int COUNT(int idx, int k)
{
    int bid = idx/B;
    int ret = 0;
    rep(i,bid)
    {
        if(ct[i].count(k^x[i])) ret += ct[i][k^x[i]];
    }
    rep(i,B)
    {
        if(B*bid+i>idx) break;
        if((x[bid]^b[bid][i]) == k) ++ret;
    }
    return ret;
}

int main()
{
    memset(b,-1,sizeof(b));

    int n,q;
    scanf(" %d %d", &n, &q);

    int v = 0;
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        v ^= a[i];

        b[i/B][i%B] = v;
    }
    rep(i,B) update_ct(i);

    while(q--)
    {
        int t,idx,k;
        scanf(" %d %d %d", &t, &idx, &k);
        --idx;
        if(t==1)
        {
            XOR(idx,n-1,a[idx]^k);
            a[idx] = k;
        }
        else printf("%d\n", COUNT(idx,k));
    }

    return 0;
}
