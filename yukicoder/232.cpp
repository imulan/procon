#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int t,a,b;
    cin >>t >>a >>b;

    bool ok=true;
    vector<string> ans;

    if(a==0 && b==0)
    {
        if(t==1) ok=false;
        else
        {
            if(t%2==1)
            {
                ans.pb(">");
                ans.pb("^");
                ans.pb("<v");
                t-=3;
            }

            while(t>0)
            {
                ans.pb(">");
                ans.pb("<");
                t-=2;
            }
        }
    }
    else
    {
        int min_dist = max(a,b);
        if(min_dist>t) ok=false;
        else
        {
            if(min_dist%2 == t%2)
            {
                int m=min(a,b);
                rep(i,m) ans.pb(">^");

                string tmp=(a>b)?"^":">";
                rep(i,min_dist-m) ans.pb(tmp);

                t-=min_dist;
            }
            else
            {
                if(a==0)
                {
                    ans.pb("^");
                    ans.pb(">v");
                    rep(i,b-1) ans.pb(">");
                    t-=b+1;
                }
                else if(b==0)
                {
                    ans.pb(">");
                    ans.pb("<^");
                    rep(i,a-1) ans.pb("^");
                    t-=a+1;
                }
                else
                {
                    ans.pb(">");
                    ans.pb("^");
                    int m=min(a,b);
                    rep(i,m-1) ans.pb(">^");
                    string tmp=(a>b)?"^":">";
                    rep(i,min_dist-m) ans.pb(tmp);
                    t-=min_dist+1;
                }

            }

            while(t>0)
            {
                ans.pb(">");
                ans.pb("<");
                t-=2;
            }
        }
    }

    if(!ok) cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        rep(i,ans.size()) cout << ans[i] << '\n';
    }
    return 0;
}
