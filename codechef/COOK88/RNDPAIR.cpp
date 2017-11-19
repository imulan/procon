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

double solve()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    int U = n*(n-1)/2;

    map<int,int> ct;
    rep(i,n) ++ct[a[i]];

    int P = 0;
    if(a[n-1]==a[n-2])
    {
        int v = ct[a[n-1]];
        P = v*(v-1)/2;
    }
    else P = ct[a[n-2]];

    return (double) P/U;
}

int main()
{
    int T;
    cin >>T;
    while(T--) printf("%.10f\n", solve());
    return 0;
}
