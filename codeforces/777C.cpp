#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vi> a(n,vi(m));
    rep(i,n)rep(j,m) scanf(" %d", &a[i][j]);

    vector<int> range(n);
    rep(i,n) range[i]=i;

    rep(c,m)
    {
        int start=0;
        int idx=0;
        while(idx<n-1)
        {
            start = idx;
            while(idx<n-1)
            {
                if(a[idx][c]>a[idx+1][c]) break;
                ++idx;
            }

            for(int i=start; i<=idx; ++i) range[i] = max(range[i],idx);
            ++idx;
        }
    }

    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int l,r;
        scanf(" %d %d", &l, &r);
        --l;
        --r;

        if(range[l]>=r) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
