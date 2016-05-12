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
    int w;
    cin >>w;

    int p3[13];
    p3[0]=1;
    rep(i,12) p3[i+1]=p3[i]*3;

    int now=0;
    while((p3[now+1]-1)/2<w) ++now;
    //printf("now= %d, lim=%d\n", now, (p3[now+1]-1)/2);

    string ans;

    rep(mask,p3[now+1])
    {
        //3^iのおもりをどうするか
        vector<int> st(now+1);
        int t=mask;
        rep(i,now+1)
        {
            st[i]=t%3-1;
            t/=3;
        }

        if(st[now]==0) continue;

        int v=0;
        rep(i,now+1) v+=st[i]*p3[i];

        if(v==w)
        {
            ans.resize(now+1);
            rep(i,now+1)
            {
                if(st[i]==-1) ans[now-i]='-';
                else if(st[i]==1) ans[now-i]='+';
                else ans[now-i]='0';
            }
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
