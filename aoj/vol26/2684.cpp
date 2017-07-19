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

using pc = pair<char,int>;
using icpc = vector<pc>;

icpc readICPC()
{
    icpc ret;
    char c;
    while(cin >>c,(c!='$'))
    {
        int l;
        cin >>l;
        ret.pb({c,l});
    }
    return ret;
}

icpc solve(icpc a, icpc b, icpc c)
{
    int A = a.size(), B = b.size(), C = c.size();

    if(B==1)
    {
        rep(i,A)
        {
            // 発見したので置換
            if(a[i].fi==b[0].fi && a[i].se>=b[0].se)
            {
                icpc ret;
                rep(j,i) ret.pb(a[j]);
                rep(j,C) ret.pb(c[j]);
                ret.pb({b[0].fi, a[i].se-b[0].se});
                for(int j=i+1; j<A; ++j) ret.pb(a[j]);
                return ret;
            }
        }
    }
    else
    {
        rep(i,A-B+1)
        {
            bool ok = false;
            if(a[i].fi==b[0].fi && a[i].se>=b[0].se && a[i+B-1].fi==b[B-1].fi && a[i+B-1].se>=b[B-1].se)
            {
                ok = true;
                for(int j=1; j<B-1; ++j)
                {
                    if(!(a[i+j].fi==b[j].fi && a[i+j].se==b[j].se)) ok = false;
                }
            }

            if(ok)
            {
                icpc ret;
                rep(j,i) ret.pb(a[j]);
                ret.pb({a[i].fi, a[i].se-b[0].se});
                rep(j,C) ret.pb(c[j]);
                ret.pb({a[i+B-1].fi, a[i+B-1].se-b[B-1].se});
                for(int j=i+B; j<A; ++j) ret.pb(a[j]);
                return ret;
            }
        }
    }
    // 見つからなければ変換しない
    return a;
}

icpc compress(icpc s)
{
    icpc ret;
    rep(i,s.size())
    {
        if(s[i].se == 0) continue;

        if(ret.size() == 0) ret.pb(s[i]);
        else
        {
            int R = ret.size();
            if(ret[R-1].fi == s[i].fi) ret[R-1].se += s[i].se;
            else ret.pb(s[i]);
        }
    }
    return ret;
}

int main()
{
    icpc a = readICPC();
    icpc b = readICPC();
    icpc c = readICPC();

    icpc ans = compress(solve(a,b,c));
    rep(i,ans.size()) printf("%c %d ", ans[i].fi, ans[i].se);
    printf("$\n");
    return 0;
}
