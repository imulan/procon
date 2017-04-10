#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<char,char> pc;

void solve()
{
    string s,t;
    cin >>s >>t;

    int f[26];
    memset(f,-1,sizeof(f));

    rep(i,s.size())
    {
        if(s[i]!=t[i])
        {
            int x=s[i]-'a', y=t[i]-'a';
            if(f[x]==-1 && f[y]==-1)
            {
                f[x]=y;
                f[y]=x;
            }
            else
            {
                if(f[x]==-1)
                {
                    if(f[y]!=x)
                    {
                        printf("-1\n");
                        return;
                    }
                    f[x]=y;
                }
                else if(f[y]==-1)
                {
                    if(f[x]!=y)
                    {
                        printf("-1\n");
                        return;
                    }
                    f[y]=x;
                }
                else
                {
                    if(f[x]!=y || f[y]!=x)
                    {
                        printf("-1\n");
                        return;
                    }
                }
            }
        }
        else
        {
            int x=s[i]-'a';
            if(f[x]==-1) f[x]=x;
            else
            {
                if(f[x]!=x)
                {
                    printf("-1\n");
                    return;
                }
            }
        }
    }

    vector<pc> ans;
    rep(i,26)
    {
        if(f[i]!=-1 && i<f[i]) ans.pb(pc(i+'a',f[i]+'a'));
    }

    printf("%d\n", ans.size());
    rep(i,ans.size()) printf("%c %c\n", ans[i].fi, ans[i].se);

}

int main()
{
    solve();
    return 0;
}
