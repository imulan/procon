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
    int m;
    cin >>m;
    rep(M,m)
    {
        int a;
        cin >>a;

        int now=a;
        string ans="";

        while(now>0)
        {
            int nx=(now-1)/2;
            if(2*nx+1==now) ans+="L";
            else if(2*nx+2==now) ans+="R";
            else printf("error!\n");

            now=nx;
        }

        reverse(all(ans));
        cout << ans << endl;
    }
    return 0;
}
