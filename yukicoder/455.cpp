#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    int idx=0;
    int x[2],y[2];
    rep(i,h)rep(j,w)
    {
        if(s[i][j]=='*')
        {
            x[idx]=j;
            y[idx]=i;
            ++idx;
        }
    }

    int X=0,Y=0;
    if(x[0]==x[1])
    {
        if(x[0]==0) X=1;
    }
    else if(y[0]==y[1])
    {
        if(y[0]==0) Y=1;
    }
    else
    {
        X=x[0];
        rep(i,h)
        {
            if(s[i][x[0]]=='-')
            {
                Y=i;
                break;
            }
        }
    }

    s[Y][X]='*';
    rep(i,h) cout << s[i] << endl;
    return 0;
}
