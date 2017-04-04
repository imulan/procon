#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1010101010;

int main()
{
    int n;
    scanf(" %d", &n);

    int n_max_l=0, n_min_r=INF;
    rep(i,n)
    {
        int l,r;
        scanf(" %d %d", &l, &r);

        n_max_l = max(n_max_l, l);
        n_min_r = min(n_min_r, r);
    }

    int m;
    scanf(" %d", &m);

    int m_max_l=0, m_min_r=INF;
    rep(i,m)
    {
        int l,r;
        scanf(" %d %d", &l, &r);

        m_max_l = max(m_max_l, l);
        m_min_r = min(m_min_r, r);
    }

    printf("%d\n", max({0, m_max_l-n_min_r, n_max_l-m_min_r}));
    return 0;
}
