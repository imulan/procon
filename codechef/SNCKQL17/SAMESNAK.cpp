#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const string OK="yes",NG="no";

struct Snake
{
    int x[2],y[2];
    int p; // x-parallel = 0, y-parallel = 1
    int len;
};

string solve()
{
    Snake s[2];
    rep(i,2)
    {
        rep(j,2) cin >>s[i].x[j] >>s[i].y[j];

        s[i].p = (s[i].x[0]==s[i].x[1]);
        if(s[i].p)
        {
            s[i].len = max(s[i].y[0],s[i].y[1]) - min(s[i].y[0],s[i].y[1]) + 1;
        }
        else
        {
            s[i].len = max(s[i].x[0],s[i].x[1]) - min(s[i].x[0],s[i].x[1]) + 1;
        }
    }
    if(s[0].len>s[1].len) swap(s[0],s[1]);

    if(s[0].len==1)
    {
        if(s[1].p==1)
        {
            if(s[0].x[0]!=s[1].x[0]) return NG;

            int ly = min(s[1].y[0],s[1].y[1]);
            int ry = max(s[1].y[0],s[1].y[1]);

            if(ly<=s[0].y[0] && s[0].y[0]<=ry) return OK;
            return NG;
        }
        else
        {
            if(s[0].y[0]!=s[1].y[0]) return NG;

            int lx = min(s[1].x[0],s[1].x[1]);
            int rx = max(s[1].x[0],s[1].x[1]);

            if(lx<=s[0].x[0] && s[0].x[0]<=rx) return OK;
            return NG;
        }
    }

    if(s[0].p==s[1].p)
    {
        if(s[0].p==0)
        {
            if(s[0].y[0]!=s[1].y[0]) return NG;

            int lx[2],rx[2];
            rep(i,2)
            {
                lx[i] = min(s[i].x[0],s[i].x[1]);
                rx[i] = max(s[i].x[0],s[i].x[1]);
            }

            int L = max(lx[0],lx[1]), R = min(rx[0],rx[1]);

            if(L<=R) return OK;
            return NG;
        }
        else
        {
            if(s[0].x[0]!=s[1].x[0]) return NG;

            int ly[2],ry[2];
            rep(i,2)
            {
                ly[i] = min(s[i].y[0],s[i].y[1]);
                ry[i] = max(s[i].y[0],s[i].y[1]);
            }

            int L = max(ly[0],ly[1]), R = min(ry[0],ry[1]);

            if(L<=R) return OK;
            return NG;
        }
    }
    else
    {
        rep(i,2)rep(j,2)
        {
            if(s[0].x[i]==s[1].x[j] && s[0].y[i]==s[1].y[j]) return OK;
        }
        return NG;
    }
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
