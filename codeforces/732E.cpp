#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> p(n), s(m);
    rep(i,n)
    {
        scanf(" %d", &p[i].fi);
        p[i].se=i;
    }
    rep(i,m)
    {
        scanf(" %d", &s[i].fi);
        s[i].se=i;
    }

    sort(all(p));
    sort(all(s));

    // a:i番目のコンセントにいくつアダプタを繋ぐか
    // b:i番目のコンピュータは何番のコンピュータに繋ぐか
    vector<int> a(m),b(n,-1);
    vector<bool> used(m,false);

    rep(adapter,31)
    {
        int sidx=0;
        rep(i,n)
        {
            int b_idx=p[i].se;
            if(b[b_idx]!=-1) continue;

            while(sidx<m && (s[sidx].fi<p[i].fi || used[sidx])) ++sidx;

            if(sidx<m && !used[sidx] && s[sidx].fi==p[i].fi)
            {
                used[sidx]=true;
                int a_idx=s[sidx].se;

                a[a_idx]=adapter;
                b[b_idx]=a_idx;
            }
        }

        rep(i,m) s[i].fi=(s[i].fi+1)/2;
    }

    int c=0,u=0;
    rep(i,m) u+=a[i];
    rep(i,n) if(b[i]!=-1) ++c;

    printf("%d %d\n", c,u);
    rep(i,m)
    {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", b[i]+1);
    }
    printf("\n");
    return 0;
}
