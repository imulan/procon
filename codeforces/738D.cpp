#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

vector<int> solve()
{
    int n,a,b,k;
    string s;
    cin >>n >>a >>b >>k;
    cin >>s;

    vector<pi> z;

    int idx=0;
    while(idx<n)
    {
        if(s[idx]=='1') ++idx;
        else
        {
            int start=idx;
            while(idx<n && s[idx]=='0') ++idx;

            int len = idx-start;
            if(len>=b) z.pb(pi(start,idx-1));
        }
    }

    int Z=z.size();
    int can = 0;
    rep(i,Z)
    {
        int L = z[i].se+1 - z[i].fi;
        can += L/b;
    }

    // printf(" can = %d\n", can);

    vector<int> ret;

    rep(i,Z)
    {
        while(z[i].se+1 - z[i].fi>=b)
        {
            z[i].fi+=b;
            ret.pb(z[i].fi-1);
            --can;

            if(can+1==a) return ret;
        }
    }

    return ret;
}

int main()
{
    vector<int> ans = solve();

    int A=ans.size();
    printf("%d\n", A);
    rep(i,A)
    {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");
    return 0;
}
