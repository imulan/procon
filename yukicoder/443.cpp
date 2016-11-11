#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<int> divisor(int n)
{
    vector<int> ret;
    for(int i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i!=n/i) ret.pb(n/i);
        }
    }
    sort(all(ret),greater<int>());
    return ret;
}

bool check(string s, int d)
{
    int now=0;
    rep(i,s.size()) now=(10*now+s[i]-'0')%d;
    return now==0;
}

int main()
{
    string s;
    cin >>s;

    int ct[10]={0};
    int not_zero=0;
    int sum=0;
    rep(i,s.size())
    {
        sum+=s[i]-'0';
        ++ct[s[i]-'0'];
        if(s[i]!='0') ++not_zero;
    }

    int k=0;
    rep(i,10) if(ct[i]>0) ++k;
    if(k==1)
    {
        cout << s << endl;
        return 0;
    }

    int t=-1;
    rep(i,10)rep(j,i)
    {
        if(ct[i] && ct[j])
        {
            int d=abs(9*(i-j));
            if(t==-1) t=d;
            else t=__gcd(t,d);
        }
    }

    int ans=-1;
    vector<int> div=divisor(t);
    rep(i,div.size())
    {
        if(check(s,div[i]))
        {
            ans=div[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
