#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

pi make_range(int Q, int R)
{
    int l = 10*Q;
    int d = 11*R;

    int a = (l%d!=0);
    l /= d;
    l += a;
    int r = 10*Q/(9*R);

    if(l>r) return pi(0,0);
    return pi(l,r);
}

int solve()
{
    int n,p;
    cin >>n >>p;
    vector<int> r(n);
    rep(i,n) cin >>r[i];
    vector<vector<pi>> q(n,vector<pi>(p));
    rep(i,n)
    {
        rep(j,p)
        {
            int t;
            cin >>t;
            q[i][j] = make_range(t,r[i]);
            // dbg(q[i][j]);
        }
        sort(all(q[i]));
    }

    int ans = 0;
    int mul = 1;
    vector<int> idx(n);
    while(1)
    {
        rep(i,n)
        {
            while(idx[i]<p && q[i][idx[i]].se<mul) ++idx[i];
            if(idx[i]==p) return ans;
        }

        bool ok = true;
        rep(i,n)
        {
            ok &= (q[i][idx[i]].fi<=mul && mul<=q[i][idx[i]].se);
        }

        if(ok)
        {
            ++ans;
            rep(i,n) ++idx[i];
        }
        else ++mul;
    }
}

int main()
{
    int T;
    cin >>T;
    rep(t,T) printf("Case #%d: %d\n", t+1, solve());
    return 0;
}
