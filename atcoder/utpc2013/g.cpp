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

int main()
{
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    ++n;
    vector<pi> v(n);
    rep(i,n-1) scanf(" %d %d", &v[i].fi, &v[i].se);
    v[n-1] = pi(m+1,INT_MAX);

    sort(all(v));

    int l=0, r=m+1;
    while(r-l>1)
    {
        int x = (l+r)/2;
        bool ok = true;

        int dm = 0;
        int tk = k;

        // 未採用マン
        multiset<int> black;

        // 採用済みマンの中でb[i]の最大値
        int blue = -1;

        int idx = 0;
        while(dm<m+1)
        {
            int d = dm+x;
            // d以下にa[i]がある未採用マンを登録
            while(idx<n && v[idx].fi<=d) black.insert(v[idx++].se);

            auto itr = black.upper_bound(dm);
            if(itr == black.end())
            {
                if(blue <= dm || tk == 0)
                {
                    ok = false;
                    break;
                }

                // 毎日マン誕生
                dm = blue;
                --tk;
                blue = -1;
            }
            else
            {
                blue = max(blue,*itr);
                dm = min(d,*itr);
                black.erase(itr);
            }
        }

        if(ok) r = x;
        else l = x;
    }

    printf("%d\n", r);
    return 0;
}
