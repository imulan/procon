#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct line
{
    ll a,b;

    bool operator<(const line& t) const {
        return a*(t.a+t.b) < t.a*(a+b);
    }
};

inline int intersect_inside(const line& m, const line& n)
{
    if(m.a*(n.a+n.b) + n.a*(m.a+m.b) > (m.a+m.b)*(n.a+n.b)) return 1;
    return 0;
}

inline int intersect_onedge(const line& m, const line& n)
{
    if(m.a*(n.a+n.b) + n.a*(m.a+m.b) == (m.a+m.b)*(n.a+n.b)) return 1;
    return 0;
}

inline line crosspoint(const line& pp, const line& qq)
{
    ll D=pp.a*(qq.a+qq.b) + qq.a*(pp.a+pp.b);
    ll C=(pp.a+pp.b)*(qq.a+qq.b);
    ll A=2*C-D, B=D-C;

    ll G=__gcd(A,B);
    A/=G;
    B/=G;
    return line{A,B};
}

int main()
{
    int n;
    scanf(" %d", &n);

    vector<line> l[3];
    rep(i,n)
    {
        int p;
        ll a,b;
        scanf(" %d %lld %lld", &p, &a, &b);

        ll G=__gcd(a,b);
        a/=G;
        b/=G;

        l[p].pb(line{a,b});
    }

    rep(i,3) sort(all(l[i]));

    ll two=0,three=0;

    rep(i,3)
    {
        int P=i, Q=(i+1)%3, R=(i+2)%3;
        rep(j,l[P].size())rep(k,l[Q].size())
        {
            line pp=l[P][j], qq=l[Q][k];

            two+=intersect_inside(pp,qq);

            if(intersect_inside(pp,qq) || intersect_onedge(pp,qq))
            {
                line base = max(line{pp.b,pp.a}, line{qq.b,qq.a});

                int idx = lower_bound(all(l[R]),base) - l[R].begin();
                three += (int)l[R].size()-idx;

                line cr = crosspoint(pp,qq);
                if(cr.a>0 && cr.b>0 && cr.a+cr.b<=400000)
                {
                    int c_idx = lower_bound(all(l[R]),cr) - l[R].begin();
                    if(c_idx<l[R].size() && l[R][c_idx].a==cr.a && l[R][c_idx].b==cr.b) --three;
                }
            }
        }
    }

    printf("%lld\n", 1+n+two+three/3);
    return 0;
}
