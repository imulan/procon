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
    int w,h,n;
    cin >>w >>h >>n;

    vector<string> s(h,string(w,'w'));
    while(n--)
    {
        int x,y,a;
        cin >>x >>y >>a;

        int lx=0, rx=w, ly=0, ry=h;
        if(a==1) rx=x;
        if(a==2) lx=x;
        if(a==3) ry=y;
        if(a==4) ly=y;

        for(int i=ly; i<ry; ++i)for(int j=lx; j<rx; ++j) s[i][j]='b';
    }

    int ans=0;
    rep(i,h)rep(j,w) ans+=(s[i][j]=='w');
    cout << ans << endl;
    return 0;
}
