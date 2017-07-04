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
    scanf(" %d", &n);

    vector<int> p(n);
    vector<int> pos(n);
    rep(i,n)
    {
        scanf(" %d", &p[i]);
        --p[i];

        pos[p[i]] = i;
    }

    vector<int> da(n-1),db(n-1);
    rep(i,n-1)
    {
        int d = pos[i+1]-pos[i];
        if(d<0)
        {
            da[i]=1;
            db[i]=abs(d)+1;
        }
        else
        {
            da[i]=abs(d)+1;
            db[i]=1;
        }
    }

    vector<int> a(n),b(n);
    a[0] = 1;
    rep(i,n-1) a[i+1] = a[i]+da[i];
    b[n-1] = 1;
    for(int i=n-1; i>0; --i) b[i-1] = b[i]+db[i-1];

    rep(i,n) printf("%d%c", a[i]," \n"[i==n-1]);
    rep(i,n) printf("%d%c", b[i]," \n"[i==n-1]);
    return 0;
}
