#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int V=500*500;

int H,W,N;
// 参加者の初期位置
int p[V];

// 頂点番号を1次元化
inline int cv(int y, int x)
{
    return y*W+x;
}

// 次どこに行くか
int f[20][V];

int main()
{
    scanf(" %d %d %d", &H, &W, &N);

    rep(i,H)rep(j,W)
    {
        int r,c;
        scanf(" %d %d", &r, &c);
        f[0][cv(i,j)] = cv(r,c);
    }
    rep(i,N)
    {
        int r,c;
        scanf(" %d %d", &r, &c);
        p[i] = cv(r,c);
    }

    for(int i=1; i<20; ++i)rep(j,V) f[i][j] = f[i-1][f[i-1][j]];

    int l=0,r=H*W+1;
    while(r-l>1)
    {
        int m=(l+r)/2;
        vector<int> ct(V,0);
        rep(i,N)
        {
            int now = p[i];
            rep(j,20)if(m>>j&1) now = f[j][now];

            ++ct[now];
        }

        bool ok=true;
        rep(i,V)if(ct[i]>1) ok=false;

        if(ok) l=m;
        else r=m;
    }

    if(r==H*W+1) r=-1;
    printf("%d\n", r);
    return 0;
}
