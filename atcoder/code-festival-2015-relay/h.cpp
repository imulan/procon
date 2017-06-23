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

const int INF = INT_MAX/3;

int main()
{
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    vector<vector<int>> d(h,vector<int>(w,INF));
    d[0][0]=0;
    queue<pi> que;
    que.push(pi(0,0));

    while(!que.empty())
    {
        pi p = que.front();
        que.pop();
        rep(i,4)
        {
            int nx = p.se+dx[i], ny = p.fi+dy[i];
            if(IN(nx,ny))
            {
                int add = (s[p.fi][p.se]!=s[ny][nx]);
                if(d[ny][nx] > d[p.fi][p.se]+add)
                {
                    d[ny][nx] = d[p.fi][p.se]+add;
                    que.push(pi(ny,nx));
                }
            }
        }
    }

    cout << d[h-1][w-1] << endl;
    return 0;
}
