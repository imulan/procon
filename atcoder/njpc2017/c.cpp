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

string solve()
{
    int n,L;
    scanf(" %d %d", &n, &L);

    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);

    vector<bool> land(n,false);
    rep(i,n-1) land[i]=(x[i+1]-x[i]>L);
    land[n-1]=true;

    vector<pi> b;

    int idx=0;
    int st=0;
    while(idx<n)
    {
        if(land[idx])
        {
            b.pb(pi(x[st],x[idx]));
            st = idx+1;
        }
        ++idx;
    }
    b.pb(pi(2000000000,2000000000));

    // rep(i,b.size()) printf(" %d %d\n", b[i].fi,b[i].se);

    int pos=0;

    rep(i,b.size()-1)
    {
        int lb = b[i].se-L;
        int rb = b[i].fi;

        // printf("pos lb rb %d %d %d\n", pos,lb,rb);

        if(lb>rb) return "NO";
        if(rb<pos) return "NO";

        if(pos<=lb)
        {
            pos=lb+L+L;
            // printf(" j %d  ? %d\n", pos,b[i+1].fi);
            if(b[i+1].fi<=pos) return "NO";
        }
        else
        {
            pos+=L+L;
            if(b[i+1].fi<=pos) return "NO";
        }
    }

    return "YES";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
