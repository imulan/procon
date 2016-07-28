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
    int T;
    cin >>T;
    rep(t,T)
    {
        int n;
        cin >>n;

        //2がある，5がある
        bool two=false;
        bool five=false;

        int s=0;
        rep(i,n)
        {
            int a;
            scanf(" %d", &a);
            s+=a;

            if(a==2) two=true;
            if(a==5) five=true;
        }

        string ans="No";
        if(!two && five && 4*n<=s) ans="Yes";
        cout << ans << endl;
    }
    return 0;
}
