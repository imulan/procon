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
using E = pair<int,pi>;

int main()
{
    int n,m;
    cin >>n >>m;

    vector<E> e(m);
    rep(i,m)
    {
        int a,b,c;
        cin >>a >>b >>c;
        --a;
        --b;
        e[i] = {c,{a,b}};
    }
    sort(all(e));

    int ans = -1;
    vector<bool> vis(n);
    vis[0] = true;
    rep(i,m)
    {
        pi p = e[i].se;

        if(vis[p.fi])
        {
            vis[p.se] = true;
            if(p.se == n-1) ans = e[i].fi;
        }
    }

    cout << ans << endl;
    return 0;
}
