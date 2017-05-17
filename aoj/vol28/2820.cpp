#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int B=315;
const int SZ=318;

int dat[SZ][B]={};
int sumF[SZ]={}, sumG[SZ]={};
int flg[SZ];

void init(int n, string s)
{
    rep(i,SZ)rep(j,B)
    {
        int idx = i*B+j;
        if(idx<n) dat[i][j] = s[idx]-'0';
    }

    memset(flg,-1,sizeof(flg));

    // sumF
    rep(i,SZ)
    {
        rep(j,B) sumF[i]+=dat[i][j];
    }

    // sumG
    rep(i,SZ)
    {
        rep(j,B-1) sumG[i]+=dat[i][j]*dat[i][j+1];
    }
}

void update(int l, int r, int b)
{
    int lb = l/B, rb = r/B;
    if(lb==rb)
    {
        if(flg[lb]!=-1)
        {
            rep(i,B) dat[lb][i] = flg[lb];
            flg[lb] = -1;
        }

        for(int i=l-lb*B; i<=r-lb*B; ++i) dat[lb][i]=b;

        sumF[lb]=sumG[lb]=0;
        rep(i,B) sumF[lb]+=dat[lb][i];
        rep(i,B-1) sumG[lb]+=dat[lb][i]*dat[lb][i+1];
    }
    else
    {
        if(flg[lb]!=-1)
        {
            rep(i,B) dat[lb][i] = flg[lb];
            flg[lb] = -1;
        }
        for(int i=l-lb*B; i<B; ++i) dat[lb][i]=b;
        sumF[lb]=sumG[lb]=0;
        rep(i,B) sumF[lb]+=dat[lb][i];
        rep(i,B-1) sumG[lb]+=dat[lb][i]*dat[lb][i+1];

        for(int i=lb+1; i<rb; ++i)
        {
            flg[i]=b;
            sumF[i]=B*b;
            sumG[i]=(B-1)*b;
        }

        if(flg[rb]!=-1)
        {
            rep(i,B) dat[rb][i] = flg[rb];
            flg[rb] = -1;
        }
        for(int i=0; i<=r-rb*B; ++i) dat[rb][i]=b;
        sumF[rb]=sumG[rb]=0;
        rep(i,B) sumF[rb]+=dat[rb][i];
        rep(i,B-1) sumG[rb]+=dat[rb][i]*dat[rb][i+1];
    }
}

int F()
{
    int ret=0;
    rep(i,SZ) ret+=sumF[i];
    return ret;
}

int G()
{
    int ret=0;
    rep(i,SZ) ret+=sumG[i];

    rep(i,SZ-1)
    {
        int p=dat[i][B-1];
        if(flg[i]!=-1) p=flg[i];

        int q=dat[i+1][0];
        if(flg[i+1]!=-1) q=flg[i+1];

        ret+=p*q;
    }
    return ret;
}

int main()
{
    int n;
    string s;
    cin >>n >>s;

    init(n,s);

    int q;
    scanf(" %d", &q);
    while(q--)
    {
        int l,r,b;
        scanf(" %d %d %d", &l, &r, &b);
        --l;
        --r;
        update(l,r,b);
        printf("%d\n", F()-G());
    }

    return 0;
}
