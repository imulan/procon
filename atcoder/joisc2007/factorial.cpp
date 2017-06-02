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

map<int,int> factorize(int n)
{
    map<int,int> ret;
    int t=n;
    for(int i=2; i*i<=n; ++i)
    {
        while(t%i==0)
        {
            t/=i;
            ++ret[i];
        }
    }
    if(t>1) ret[t]=1;
    return ret;
}

int main()
{
    int n;
    cin >>n;
    int ans=0;
    for(const auto &p:factorize(n))
    {
        int ct=0;
        int now=p.fi;
        while(1)
        {
            int t=now;
            while(t%p.fi==0)
            {
                ++ct;
                t/=p.fi;
            }
            if(ct>=p.se) break;
            now += p.fi;
        }
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}
