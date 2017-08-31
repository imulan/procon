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
    int n,m,k;
    cin >>n >>m >>k;

    int a[1001]={};
    rep(i,n)
    {
        int v;
        cin >>v;
        a[v]=1;
    }

    int ans = 0;
    for(int i=1; i<=1000-k+1; ++i)
    {
        int need = 0;
        rep(j,k) need += !a[i+j];
        ans += (need<=m);
    }

    cout << ans << endl;
    return 0;
}
