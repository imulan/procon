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

int main()
{
    int n,k;
    cin >>n >>k;

    vector<int> fox(k),hide(k);
    rep(i,k) cin >>fox[i];
    rep(i,k) cin >>hide[i];

    sort(all(fox));
    sort(all(hide));

    int zero = -1;
    if(fox[0]==0) zero = 0;
    if(hide[0]==0) zero = 1;

    // dbg(zero);

    int ans = 19191919;

    vector<int> p(n+1);
    rep(i,k) p[hide[i]] = 1;
    int t = 0;
    int tz = zero;
    rep(i,k)
    {
        if(fox[i]==0)
        {
            ++t;
            continue;
        }

        // dbg(fox[i]);
        // dbg((fox[i]-2+n)%n +1);
        // dbg(fox[i]%n +1);

        if(p[(fox[i]-2+n)%n +1])
        {
            ++t;
            p[(fox[i]-2+n)%n +1] = 0;
        }
        else if(p[fox[i]%n +1])
        {
            ++t;
            p[fox[i]%n +1] = 0;
        }
        else
        {
            if(tz==1)
            {
                tz = -1;
                ++t;
            }
            else t += 2;
        }
    }
    ans = min(ans,t);

    p = vector<int>(n+1,0);
    rep(i,k) p[hide[i]] = 1;
    t = 0;
    tz = zero;
    rep(i,k)
    {
        if(fox[i]==0)
        {
            ++t;
            continue;
        }

        if(p[fox[i]%n +1])
        {
            ++t;
            p[fox[i]%n +1] = 0;
        }
        else if(p[(fox[i]-2+n)%n +1])
        {
            ++t;
            p[(fox[i]-2+n)%n +1] = 0;
        }
        else
        {
            if(tz==1)
            {
                tz = -1;
                ++t;
            }
            else t += 2;
        }
    }
    ans = min(ans,t);

    cout << ans << endl;
    return 0;
}
