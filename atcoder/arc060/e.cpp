#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// j番目のホテルから2^i日以内に到達可能な最も右のホテル番号
// 2^17 = 131072
int r[18][100000];

int main()
{
    int n,L;
    cin >>n;
    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);
    cin >>L;

    // ダブリング
    rep(i,n) r[0][i]=upper_bound(all(x), x[i]+L)-x.begin()-1;
    for(int i=1; i<18; ++i)rep(j,n) r[i][j]=r[i-1][r[i-1][j]];

    int Q;
    cin >>Q;
    rep(q,Q)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        if(a>b) swap(a,b);

        int ans=0;
        int now=a;
        for(int i=17; i>=0; --i)
        {
            if(r[i][now]<b)
            {
                now=r[i][now];
                ans+=1<<i;
            }
        }
        if(now<b)
        {
            now=r[0][now];
            ++ans;
        }

        printf("%d\n", ans);
    }

    return 0;
}
