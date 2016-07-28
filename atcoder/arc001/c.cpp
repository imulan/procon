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

inline bool in(int x, int y)
{
    return (0<=x&&x<8 && 0<=y&&y<8);
}

bool check(const vector<string> &ans)
{
    //i行目
    rep(i,8)
    {
        int ct=0;
        rep(j,8) if(ans[i][j]=='Q') ++ct;
        if(ct>1) return false;
    }
    //i列目
    rep(i,8)
    {
        int ct=0;
        rep(j,8) if(ans[j][i]=='Q') ++ct;
        if(ct>1) return false;
    }
    //斜め左
    rep(i,8)
    {
        //スタート地点(i,0)
        int ct=0;
        rep(j,8)
        {
            int nx=i-j, ny=j;
            if(in(nx,ny) && ans[ny][nx]=='Q') ++ct;
        }
        if(ct>1) return false;
    }
    rep(i,8)
    {
        //スタート地点(7,i)
        int ct=0;
        rep(j,8)
        {
            int nx=7-j, ny=i+j;
            if(in(nx,ny) && ans[ny][nx]=='Q') ++ct;
        }
        if(ct>1) return false;
    }
    //斜め右
    rep(i,8)
    {
        //スタート地点(i,0)
        int ct=0;
        rep(j,8)
        {
            int nx=i+j, ny=j;
            if(in(nx,ny) && ans[ny][nx]=='Q') ++ct;
        }
        if(ct>1) return false;
    }
    rep(i,8)
    {
        //スタート地点(0,i)
        int ct=0;
        rep(j,8)
        {
            int nx=j, ny=i+j;
            if(in(nx,ny) && ans[ny][nx]=='Q') ++ct;
        }
        if(ct>1) return false;
    }

    return true;
}

int main()
{
    vector<string> s(8);
    rep(i,8) cin >>s[i];

    bool found=false;
    vector<string> ans(8);
    vector<int> p(8);
    rep(i,8) p[i]=i;
    do{
        ans=s;
        rep(i,8) ans[i][p[i]]='Q';
        if(check(ans))
        {
            found=true;
            break;
        }
    }while(next_permutation(all(p)));

    if(found) rep(i,8) cout << ans[i] << endl;
    else printf("No Answer\n");
    return 0;
}
