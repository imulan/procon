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

int h,w;

inline bool in(int y, int x)
{
    return (0<=y&&y<h && 0<=x&&x<w);
}

int main()
{
    cin >>h >>w;

    vector<string> f(h);
    rep(i,h) cin >>f[i];

    string line="";
    rep(i,w) line+=".";

    vector<string> a(h,line);
    int dx[8]={0,1,1,1,0,-1,-1,-1}, dy[8]={-1,-1,0,1,1,1,0,-1};

    rep(i,h)rep(j,w)
    {
        if(f[i][j]=='.') continue;

        bool ok=true;
        rep(k,8)
        {
            int nx=j+dx[k], ny=i+dy[k];
            if(in(ny,nx))
            {
                if(f[ny][nx]=='.') ok=false;
            }
        }

        if(ok) a[i][j]='#';
    }

    //復元してみる
    vector<string> b(a);

    //rep(i,h) cout << b[i] << endl;
    rep(i,h)rep(j,w)
    {
        if(a[i][j]=='#')
        {
            rep(k,8)
            {
                int nx=j+dx[k], ny=i+dy[k];
                if(in(ny,nx)) b[ny][nx]='#';
            }
        }
    }
    //rep(i,h) cout << b[i] << endl;

    bool valid=true;
    rep(i,h)rep(j,w)
    {
        if(f[i][j]!=b[i][j]) valid=false;
    }

    if(valid)
    {
        printf("possible\n");
        rep(i,h) cout << a[i] << endl;
    }
    else printf("impossible\n");
    return 0;
}
