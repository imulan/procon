#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int main()
{
    int n,m;
    cin >>n >>m;

    vector<pi> s;
    //cの前にdに行かないとダメ
    rep(i,m)
    {
        int c,d;
        scanf(" %d %d",&c,&d);
        if(c<d) s.pb(pi(c,d));
    }

    sort(all(s));

    int ans=n+1;
    int back=s[0].fi;
    int now=s[0].se;

    if(m>0)
    {
        rep(i,m-1)
        {
            if(now<s[i+1].fi)
            {
                ans+=2*(now-back);

                back=s[i+1].fi;
                now=s[i+1].se;
            }
            else now=max(now,s[i+1].se);
        }
        ans+=2*(now-back);
    }

    printf("%d\n", ans);
    return 0;
}
