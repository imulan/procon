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
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int M = 0;
    rep(i,n) M|=a[i];

    int m[30]={};
    rep(i,30) m[i]=(M>>i&1);

    int ct[30]={};
    int ans = n;
    int s = 0;
    rep(i,n)
    {
        rep(j,30) ct[j]+=(a[i]>>j&1);

        bool ok = true;
        rep(j,30)
        {
            if(m[j] && !ct[j])
            {
                ok=false;
                break;
            }
        }

        if(ok)
        {
            bool f=false;
            while(s<i)
            {
                rep(j,30)
                {
                    ct[j]-=(a[s]>>j&1);

                    if(m[j] && !ct[j]) f=true;
                }

                if(f) break;
                ++s;
            }
            rep(j,30) ct[j]+=(a[s]>>j&1);

            ans = min(ans, i-s+1);
        }
    }

    cout << ans << endl;
    return 0;
}
