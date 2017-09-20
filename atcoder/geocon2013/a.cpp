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

using pi = pair<int,int>;
using P = pair<pi,int>;

int main()
{
    int n = 300;

    vector<P> v(n);
    rep(i,n)
    {
        int x,y;
        cin >>x >>y;
        v[i] = P(pi(x,y),i+1);
    }

    sort(all(v));

    printf("%d\n", n/3);
    rep(i,n/3)
    {
        int j = 3*i;
        printf("%d %d %d\n", v[j].se, v[j+1].se, v[j+2].se);
    }

    return 0;
}
