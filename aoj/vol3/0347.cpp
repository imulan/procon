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
    sort(all(a));

    double ans = 0;
    rep(i,n)rep(j,i)
    {
        double p = 0, q = a[i]-a[j];
        int ct = 0;
        for(int k=n-1; k>=0; --k)
        {
            if(ct==2) break;

            if(k!=i && k!=j)
            {
                ++ct;
                p+=a[k];
            }
        }

        ans = max(ans,p/q);
    }

    printf("%.10f\n", ans);
    return 0;
}
