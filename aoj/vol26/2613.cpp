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

int xx,yy,zz;
int pr(char c)
{
    if(c=='+') return xx;
    if(c=='-') return yy;
    if(c=='*') return zz;
    assert(false);
}

ll E(string s)
{
    int S=s.size();
    int idx = 0;

    vector<ll> val;
    vector<char> op;

    while(idx<S)
    {
        if(s[idx]=='+' || s[idx]=='-' || s[idx]=='*') op.pb(s[idx++]);
        else
        {
            if(s[idx]=='(')
            {
                int b = 1;
                ++idx;
                int st = idx;
                while(b>0)
                {
                    if(s[idx]=='(') ++b;
                    else if(s[idx]==')') --b;
                    ++idx;
                }

                val.pb(E(s.substr(st,idx-1-st)));
            }
            else
            {
                int st = idx;
                while('0'<=s[idx] && s[idx]<='9') ++idx;
                val.pb(atoll(s.substr(st,idx-st).c_str()));
            }
        }
    }

    rep(i,3)
    {
        vector<ll> tv;
        vector<char> to;

        tv.pb(val[0]);
        rep(j,op.size())
        {
            char c = op[j];
            if(pr(c)==i)
            {
                int TV = tv.size();
                if(c=='+') tv[TV-1] = tv[TV-1]+val[j+1];
                if(c=='-') tv[TV-1] = tv[TV-1]-val[j+1];
                if(c=='*') tv[TV-1] = tv[TV-1]*val[j+1];
            }
            else
            {
                to.pb(c);
                tv.pb(val[j+1]);
            }
        }

        val = tv;
        op = to;
    }

    return val[0];
}

int main()
{
    string s;
    cin >>s;
    ll ans = -LLONG_MAX;
    for(xx=0; xx<3; ++xx)for(yy=0; yy<3; ++yy)for(zz=0; zz<3; ++zz) ans = max(ans,E(s));
    cout << ans << endl;
    return 0;
}
