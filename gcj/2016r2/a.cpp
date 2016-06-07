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

int n;
map<char,string> f;

string rec(string now, int d)
{
    if(d==n-1) return now;

    string a=rec(f[now[0]],d+1);
    string b=rec(f[now[1]],d+1);

    return min(a+b,b+a);
}

int main()
{
    f['R']="RS";
    f['S']="PS";
    f['P']="PR";

    int T;
    cin >>T;
    rep(t,T)
    {
        int r,p,s;
        scanf(" %d %d %d %d",&n,&r,&p,&s);

        string can[3]={"RS","PS","PR"};

        string ans="IMPOSSIBLE";
        rep(i,3)
        {
            string now=can[i];
            for(int j=2; j<=n; ++j)
            {
                string tmp="";
                rep(k,now.size()) tmp+=f[now[k]];
                now=tmp;
            }

            int tr=0,tp=0,ts=0;
            rep(j,now.size())
            {
                if(now[j]=='R') ++tr;
                if(now[j]=='S') ++ts;
                if(now[j]=='P') ++tp;
            }

            if(r==tr && p==tp && s==ts)
            {
                ans=rec(can[i],0);
                break;
            }
        }

        printf("Case #%d: ", t+1);
        cout << ans << endl;
    }
    return 0;
}
