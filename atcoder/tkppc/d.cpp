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

const int INF=100000000;

typedef tuple<int,int,int> t3;

int main()
{
    int n,r,c;
    cin >>n >>r >>c;
    vector<vector<string>> s(n,vector<string>(r));
    rep(i,n)rep(j,r) cin >> s[i][j];

    int d[100][100][100]={0};
    //initialize
    fill(d[0][0],d[100][0],INF);

    int dx[2]={0,1},dy[2]={1,0};
    queue<t3> que;
    que.push(t3(0,0,0));
    d[0][0][0]=0;
    while(!que.empty())
    {
        t3 v=que.front();
        que.pop();
        int z=get<0>(v);
        int y=get<1>(v);
        int x=get<2>(v);
        //printf("now here: %d, %d, %d\n",z,y,x);
        rep(i,2)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(0<=nx&&nx<c && 0<=ny&&ny<r)
            {
                //下の階に移動
                if(s[z][ny][nx]=='H')
                {
                    if(d[z+1][ny][nx]>d[z][y][x]+(s[z+1][ny][nx]-'0'))
                    {
                        d[z+1][ny][nx]=d[z][y][x]+(s[z+1][ny][nx]-'0');
                        que.push(t3(z+1,ny,nx));
                    }
                }
                else
                {
                    if(d[z][ny][nx]>d[z][y][x]+(s[z][ny][nx]-'0'))
                    {
                        d[z][ny][nx]=d[z][y][x]+(s[z][ny][nx]-'0');
                        que.push(t3(z,ny,nx));
                    }
                }
            }
        }
    }
    cout << d[n-1][r-1][c-1] << endl;
    return 0;
}
