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

const int INF = -19191919;

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> ans(4*n,-INF);
    int st = 2*n;
    int idx = 0;
    rep(i,n)
    {
        ans[st+idx] = a[i];

        idx = -idx;
        if(i%2==0) ++idx;
    }

    int s = 0;
    while(ans[s]==-INF) ++s;

    vector<int> x(n);
    rep(i,n) x[i]=ans[s+i];

    if(n%2==0) reverse(all(x));

    rep(i,n) printf("%d%c", x[i], (i==n-1)?'\n':' ');

    return 0;
}
