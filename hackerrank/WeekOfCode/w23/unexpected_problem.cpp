#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod =1e9+7;

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
    sort(all(ret));
    return ret;
}


int main()
{
    int MAX=0;
    for(int i=1; i<=500000; ++i)
    {
        vector<int> d=divisor(i);
        int D=d.size();
        if(MAX<D)
        {
            MAX=D;
            printf("update MAX : %d, i= %d\n", MAX,i);
        }
    }


    string s;
    ll m;
    cin >>s >>m;

    int ct[26]={0};
    rep(i,s.size()) ++ct[s[i]-'a'];

    int kind=0;
    rep(i,26) if(ct[i]>0) ++kind;

    int ans=m;
    if(kind>=2) ans=m/s.size();
    cout << ans%mod << endl;
    return 0;
}
