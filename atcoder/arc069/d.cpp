#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// 羊=0, 狼=1
string solve()
{
    int n;
    string s;
    cin >>n >>s;

    rep(mask,4)
    {
        vector<int> a(n);
        a[0] = mask&1;
        a[1] = mask>>1&1;

        for(int i=2; i<n; ++i)
        {
            if(s[i-1]=='o')
            {
                if(a[i-1]==0) a[i]=a[i-2];
                else a[i]=!a[i-2];
            }
            else
            {
                if(a[i-1]==0) a[i]=!a[i-2];
                else a[i]=a[i-2];
            }
        }

        bool ok=true;
        rep(i,n)
        {
            if(a[i]==0)
            {
                if(s[i]=='o') ok &= (a[(i+1)%n]==a[(i-1+n)%n]);
                else ok &= (a[(i+1)%n]!=a[(i-1+n)%n]);
            }
            else
            {
                if(s[i]=='o') ok &= (a[(i+1)%n]!=a[(i-1+n)%n]);
                else ok &= (a[(i+1)%n]==a[(i-1+n)%n]);
            }
        }

        if(ok)
        {
            string ret="";
            rep(i,n) ret += a[i]?'W':'S';
            return ret;
        }
    }

    return "-1";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
