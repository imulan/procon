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
    int n,q;
    scanf(" %d %d", &n, &q);

    vector<double> a(n);
    rep(i,n) scanf(" %lf", &a[i]);

    double total = 0;
    vector<double> e(n);

    while(q--)
    {
        int t,i;
        scanf(" %d %d", &t, &i);
        --i;

        if(t==0)
        {
            double s;
            scanf(" %lf", &s);

            a[i] += s;

            s/=n-1;

            e[i] += s;
            total += s;
        }
        else printf("%.10f\n", a[i]-total+e[i]);
    }

    return 0;
}
