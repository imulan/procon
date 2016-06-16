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
    int dx[8]={0,1,1,1,0,-1,-1,-1};
    int dy[8]={-1,-1,0,1,1,1,0,-1};

    int n;
    while(cin >>n,n)
    {
        vector<string> s(n);
        rep(i,n) cin >>s[i];

        int a[255][255];
        rep(i,n)rep(j,n) a[i][j]=s[i][j]-'0';

        int ans=0;

        //スタート位置
        rep(i,n)rep(j,n)
        {
            if(a[i][j]==0) continue;

            rep(k,8)
            {
                int t=0;
                int nx=j, ny=i;
                while(0<=nx&&nx<n && 0<=ny&&ny<n)
                {
                    if(a[ny][nx]==1)
                    {
                        ++t;
                        ny+=dy[k];
                        nx+=dx[k];
                    }
                    else break;
                }

                ans=max(ans,t);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
