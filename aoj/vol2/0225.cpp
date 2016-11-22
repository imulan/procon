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

    int G[26][26];
    int exist[26];
    int vis[26];

    int n;
    while(cin >>n,n)
    {
        memset(G,0,sizeof(G));
        memset(exist,0,sizeof(exist));
        memset(vis,0,sizeof(vis));

        int in[26]={0}, out[26]={0};
        rep(i,n)
        {
            string s;
            cin >>s;

            int S=s.size();
            int a=s[0]-'a', b=s[S-1]-'a';
            ++out[a];
            ++in[b];
            G[a][b]=1;
            exist[a]=exist[b]=1;
        }

        rep(i,26)
        {
            if(exist[i])
            {
                queue<int> que;
                que.push(i);
                vis[i]=1;
                while(!que.empty())
                {
                    int now=que.front(); que.pop();
                    rep(j,26)
                    {
                        if(G[now][j]==0) continue;
                        if(!vis[j])
                        {
                            vis[j]=1;
                            que.push(j);
                        }
                    }
                }
                break;
            }
        }

        bool connected=true;
        rep(i,26)
        {
            if(exist[i] && !vis[i]) connected=false;
        }

        bool valid=false;
        if(connected)
        {
            valid=true;
            rep(i,26) if(in[i]!=out[i]) valid=false;
        }

        string ans="NG";
        if(valid) ans="OK";
        cout << ans << endl;
    }
    return 0;
}
