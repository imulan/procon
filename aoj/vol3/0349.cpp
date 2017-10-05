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

const int INF = 191919;

int main()
{
    int n;
    cin >>n;

    vector<int> nx(n);
    rep(i,n)
    {
        int a;
        cin >>a;
        nx[i] = (i+a)%n;
    }

    int ans = 0;
    vector<int> d(n,INF);
    rep(i,n)if(d[i]==INF)
    {
        vector<int> vis;
        d[i] = 0;
        int now = i;
        vis.pb(i);
        while(1)
        {
            if(d[nx[now]]==INF)
            {
                d[nx[now]] = d[now]+1;
                now = nx[now];
                vis.pb(now);
            }
            else
            {
                if(d[nx[now]]>=0) ans += d[now]-d[nx[now]]+1;
                break;
            }
        }

        for(int j:vis) d[j]=-1;
    }

    cout << ans << endl;
    return 0;
}
