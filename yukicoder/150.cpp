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
    string good="good", problem="problem";

    int T;
    cin >>T;
    rep(times,T)
    {
        string s;
        cin >>s;

        int n=s.size();

        int ans=n;
        //まず文字列を2つに区切る
        for(int i=4; i<=n-7; ++i)
        {
            //x内に"good"を，y内にproblemを作る
            string x=s.substr(0,i), y=s.substr(i);
            int X=x.size(), Y=y.size();

            //変化文字数
            int mx=4, my=7;

            rep(j,X-3)
            {
                int ct=0;
                rep(k,4) if(x[j+k]!=good[k]) ++ct;
                mx=min(mx,ct);
            }

            rep(j,Y-6)
            {
                int ct=0;
                rep(k,7) if(y[j+k]!=problem[k]) ++ct;
                my=min(my,ct);
            }

            ans=min(ans,mx+my);
        }
        cout << ans << endl;
    }
    return 0;
}
