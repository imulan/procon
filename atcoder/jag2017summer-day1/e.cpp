#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define fi first
#define se second

using ll = long long;

using pl = pair<ll,ll>;
using P = pair<pl,int>;

ll mod = 998244353;
string s;
int n;

int idx=0;

P MUL(P a, P b)
{
    if(a.se==1) swap(a,b);

    if(a.se==0 && b.se==0)
    {
        ll val = ((a.fi.fi*b.fi.fi)%mod + (a.fi.se*b.fi.se)%mod)%mod;
        return P(pl(val,-1),1);
    }
    else if(a.se==0 && b.se==1)
    {
        (a.fi.fi *= b.fi.fi)%=mod;
        (a.fi.se *= b.fi.fi)%=mod;
        return a;
    }
    else
    {
        ll val = a.fi.fi*b.fi.fi;
        val %= mod;
        return P(pl(val,-1),1);
    }
}

P NUM()
{
    ll ret = 0;
    while(isdigit(s[idx]))
    {
        ret = ret*10+s[idx]-'0';
        ret %= mod;
        ++idx;
    }
    return P(pl(ret,-1),1);
}

// vector:0, expr:1
P E()
{
    if(isdigit(s[idx])) return NUM();

    if(s[idx]=='(')
    {
        ++idx;
        P e1 = E();
        char op = s[idx++];
        P e2 = E();

        assert(s[idx]==')');
        ++idx;
        if(op==',')
        {
            return P(pl(e1.fi.fi,e2.fi.fi),0);
        }
        else if(op=='*')
        {
            return MUL(e1,e2);
        }
    }
}

int main()
{
    cin >>s;
    n = s.size();

    P ans = E();
    cout << ans.first.first << endl;
}
