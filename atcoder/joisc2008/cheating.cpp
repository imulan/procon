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
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> x(m),y(m);
    rep(i,m) scanf(" %d %d", &x[i], &y[i]);

    sort(all(x));
    sort(all(y));

    int l=-1, r=1000000000;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        int num=0;
        int i;

        i=0;
        while(i<m)
        {
            int st=i;
            ++num;
            while(i<m && x[st]+mid>=x[i]) ++i;
        }

        i=0;
        while(i<m)
        {
            int st=i;
            ++num;
            while(i<m && y[st]+mid>=y[i]) ++i;
        }

        if(num<=n) r=mid;
        else l=mid;
    }
    printf("%d\n", r);
    return 0;
}
