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
typedef pair<int,vector<int>> P;

int main()
{
    int n,s;
    scanf(" %d %d", &n, &s);
    vi p(n);
    rep(i,n) scanf(" %d", &p[i]);

    int A=n/2;
    int B=n-A;

    vector<P> sumB;

    rep(i,1<<B)
    {
        int sum=0;
        vi t;
        rep(j,B)
        {
            if(i>>j&1)
            {
                t.pb(A+j);
                sum+=p[A+j];
            }
        }

        sumB.pb(P(sum,t));
    }
    sort(all(sumB));

    vector<vi> ans;
    rep(i,1<<A)
    {
        int sum=0;
        vi t;
        rep(j,A)
        {
            if(i>>j&1)
            {
                t.pb(j);
                sum+=p[j];
            }
        }

        if(sum>s) continue;

        int idx = lower_bound(all(sumB),P(s-sum,vi())) - sumB.begin();

        while(idx<sumB.size() && sum+sumB[idx].fi==s)
        {
            vi tmp=sumB[idx].se;
            vi tt(t);
            rep(j,tmp.size()) tt.pb(tmp[j]);

            ans.pb(tt);
            ++idx;
        }
    }

    sort(all(ans));

    rep(i,ans.size())
    {
        rep(j,ans[i].size())
        {
            if(j) printf(" ");
            printf("%d", ans[i][j]+1);
        }
        printf("\n");
    }
    return 0;
}
