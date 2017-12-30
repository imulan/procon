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

bool lucky(int x)
{
    int v=0;
    rep(i,3)
    {
        v += x%10;
        x /= 10;
    }

    int sum=0;
    rep(i,3)
    {
        sum += x%10;
        x /= 10;
    }

    return sum==v;
}

int diff(const string &s, int x)
{
    int ret = 0;
    for(int i=5; i>=0; --i)
    {
        if(s[i]-'0' != x%10) ++ret;
        x /= 10;
    }
    return ret;
}

int main()
{
    string s;
    cin >>s;

    int ans=6;
    rep(i,1000000)
    {
        if(lucky(i)) ans = min(ans,diff(s,i));
    }
    cout << ans << endl;
    return 0;
}
