#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

int main()
{
    int r,c;
    cin >>r >>c;
    vector<string> s(r);
    rep(i,r) cin >>s[i];

    #define IN(x,y) (0<=x && x<c && 0<=y && y<r)
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    vector<vector<bool>> vis(r, vector<bool>(c));
    int ans = 0;
    rep(i,r)rep(j,c)if(s[i][j]=='B' && !vis[i][j])
    {
        ++ans;

        queue<pi> que;
        que.push({i,j});
        vis[i][j] = true;
        while(!que.empty())
        {
            pi p = que.front();
            que.pop();
            rep(k,4)
            {
                int nx = p.se+dx[k], ny = p.fi+dy[k];
                if(IN(nx,ny) && s[ny][nx]=='B' && !vis[ny][nx])
                {
                    vis[ny][nx] = true;
                    que.push({ny,nx});
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
