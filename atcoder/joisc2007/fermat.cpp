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

int pw[10000]={};
ll ct[10000]={};

ll mod_pow(ll x, ll n, ll mod)
{
    ll ret = 1;
    while(n>0)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll solve(int p, int n)
{
    set<int> s;
    rep(i,p)
    {
        pw[i] = mod_pow(i,n,p);
        s.insert(pw[i]);
        ++ct[pw[i]];
    }

    int S = s.size();
    if(S == p) return p*p;

    ll ret=0;
    vector<int> c(s.begin(),s.end());
    rep(i,S)rep(j,S)
    {
        int val = (c[i]+c[j])%p;
        ret += ct[val]*ct[c[i]]*ct[c[j]];
    }
    return ret;
}

int main()
{
    int p,n;
    cin >>p >>n;
    cout << solve(p,n) << endl;
    return 0;
}
