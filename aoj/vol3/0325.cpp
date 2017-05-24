#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

string solve()
{
    map<pi,int> ct;
    vector<int> l;
    rep(i,6)
    {
        int h,w;
        cin >>h >>w;
        if(h>w) swap(h,w);

        l.pb(h);
        l.pb(w);
        ++ct[pi(h,w)];
    }

    sort(all(l));
    l.erase(unique(all(l)),l.end());

    int L = l.size();

    rep(k,L)rep(j,k+1)rep(i,j+1)
    {
        int a=l[i], b=l[j], c=l[k];
        pi x[3];
        x[0] = pi(a,b);
        x[1] = pi(a,c);
        x[2] = pi(b,c);

        map<pi,int> rem=ct;
        bool ok = true;
        rep(xx,3)
        {
            if(rem[x[xx]]>=2) rem[x[xx]]-=2;
            else ok=false;
        }
        if(ok) return "yes";
    }

    return "no";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
