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

string cv(int x)
{
    string s = to_string(x);
    while(s.size()<4) s = "0"+s;
    return s;
}

pi query(int x)
{
    cout << cv(x) << endl;
    fflush(stdout);

    int b,c;
    cin >>b >>c;
    return pi(b,c);
}

pi comp(int call, int ans)
{
    int x[4],y[4];
    for(int i=3; i>=0; --i)
    {
        x[i] = call%10;
        call/=10;
        y[i] = ans%10;
        ans/=10;
    }

    int b = 0, c = 0;
    int bull[10]={};
    rep(i,4)if(x[i]==y[i])
    {
        ++b;
        bull[x[i]]=1;
    }

    int ap[10]={};
    rep(i,4) ++ap[x[i]];
    rep(i,4)
    {
        if(ap[y[i]] && !bull[y[i]]) ++c;
    }

    return pi(b,c);
}

int main()
{
    vector<int> s;
    rep(a,10)
    {
        rep(b,10)if(b!=a)
        {
            rep(c,10)if(c!=a && c!=b)
            {
                rep(d,10)if(d!=a && d!=b && d!=c)
                {
                    s.pb(1000*a + 100*b + 10*c + d);
                }
            }
        }
    }

    bool first = true;
    while(1)
    {
        int nx = s[0];
        if(!first)
        {
            int mn = 10000;
            for(int i:s)
            {
                map<pi,int> ct;
                for(int j:s) ++ct[comp(i,j)];

                int mx = 0;
                for(const auto &p:ct) mx = max(mx,p.se);

                if(mn>mx)
                {
                    mn = mx;
                    nx = i;
                }
            }
        }

        pi p = query(nx);
        if(p.fi==4) break;

        vector<int> ns;
        for(int i:s)
        {
            if(comp(nx,i) == p) ns.pb(i);
        }
        s = ns;

        first = false;
    }

    return 0;
}
