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

inline bool al(char c)
{
    return ('A'<=c && c<='Z');
}

int main()
{
    int n;
    string s,t;
    cin >>n >>s >>t;

    set<char> v;
    set<char> top;
    rep(i,n)
    {
        if(al(s[i])) v.insert(s[i]);
        if(al(t[i])) v.insert(t[i]);
    }
    if(al(s[0])) top.insert(s[0]);
    if(al(t[0])) top.insert(t[0]);

    map<char,vector<char>> G;

    rep(i,n)
    {
        if(al(s[i]) || al(t[i]))
        {
            G[s[i]].pb(t[i]);
            G[t[i]].pb(s[i]);
        }
    }

    map<char,bool> vis;
    for(const auto &x : v) vis[x]=false;

    ll ans=1;
    for(const auto &x : v)
    {
        if(vis[x]) continue;

        bool number=false;
        bool head=false;
        queue<char> que;
        que.push(x);
        vis[x]=true;
        while(!que.empty())
        {
            char now=que.front();
            que.pop();

            if(top.find(now)!=top.end()) head=true;

            rep(i,G[now].size())
            {
                char nx=G[now][i];
                if(al(nx))
                {
                    if(!vis[nx])
                    {
                        vis[nx]=true;
                        que.push(nx);
                    }
                }
                else number=true;
            }
        }

        if(!number)
        {
            if(head) ans*=9;
            else ans*=10;
        }
    }
    cout << ans << endl;
    return 0;
}
