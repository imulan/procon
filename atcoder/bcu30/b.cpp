#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

string solve()
{
    string ok="Yes", ng="No";

    string s[9];
    rep(i,9) cin >>s[i];

    // 横
    rep(i,9)
    {
        int ct[9]={};
        rep(j,9) ct[s[i][j]-'1']++;

        rep(j,9) if(ct[j]>1) return ng;
    }

    // 縦
    rep(i,9)
    {
        int ct[9]={};
        rep(j,9) ct[s[j][i]-'1']++;

        rep(j,9) if(ct[j]>1) return ng;
    }

    // ナイト
    #define IN(x,y) (0<=x && x<9 && 0<=y && y<9)
    int dx[4]={1,2,2,1}, dy[4]={-2,-1,1,2};
    rep(i,9)rep(j,9)rep(d,8)
    {
        int sgn=(d>=4)?-1:1;

        int nx=j+sgn*dx[d%4], ny=i+sgn*dy[d%4];
        if(IN(nx,ny))
        {
            if(s[i][j] == s[ny][nx]) return ng;
        }
    }

    return ok;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
