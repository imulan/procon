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

int main()
{
    int h,w;
    int dx[8]={0,1,1,1,0,-1,-1,-1};
    int dy[8]={1,1,0,-1,-1,-1,0,1};
    while(cin >>h >>w,h|w)
    {
        vector<string> s(h);
        rep(i,h) cin >>s[i];

        map<string,int> ct;
        //start
        rep(i,h)rep(j,w)rep(k,8)
        {
            int x=j,y=i;
            string now="";

            vector<vector<int>> vis(h,vector<int>(w,0));
            rep(a,h*w)
            {
                if(vis[y][x]) break;

                now+=s[y][x];
                vis[y][x]=1;
                y=(y+dy[k]+h)%h;
                x=(x+dx[k]+w)%w;

                if(now.size()>=2)
                {
                    if(ct.find(now)==ct.end()) ct[now]=1;
                    else ++ct[now];
                }
            }
        }

        string ans="";
        for(const auto &i:ct)
        {
            if(i.se>1)
            {
                string t=i.fi;
                if(t.size()>ans.size()) ans=t;
                else if(t.size()==ans.size() && t<ans) ans=t;
            }
        }

        if(ans=="") ans="0";
        std::cout << ans << std::endl;
    }
    return 0;
}
