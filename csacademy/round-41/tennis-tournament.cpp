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

void solve()
{
    int n,k,m;
    cin >>n >>k >>m;

    if(k==(1<<n))
    {
        if(m==n)
        {
            vector<int> p(1<<n);
            iota(all(p),1);

            int P = p.size();
            rep(i,P) printf("%d%c", p[i],(i==P-1?'\n':' '));
        }
        else printf("-1\n");
        return;
    }

    if(k>=(1<<m))
    {
        vector<int> p;
        p.pb(k);
        for(int i=1; i<(1<<m); ++i) p.pb(i);
        for(int i=(1<<n); i>=(1<<m); --i)if(i!=k) p.pb(i);

        int P = p.size();
        rep(i,P) printf("%d%c", p[i],(i==P-1?'\n':' '));
    }
    else printf("-1\n");
}

int main()
{
    solve();
    return 0;
}
