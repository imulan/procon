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

void solve()
{
    int n,k;
    cin >>n >>k;

    vector<int> a(k,1);
    int idx = 0;
    for(int i=2; i*i<=n; ++i)
    {
        while(n%i==0)
        {
            n/=i;
            a[idx] *= i;
            idx = (idx+1)%k;
        }
    }
    a[idx]*=n;

    rep(i,k)if(a[i]==1)
    {
        printf("-1\n");
        return;
    }
    rep(i,k) printf("%d%c", a[i],(i==k-1?'\n':' '));
}

int main()
{
    solve();
    return 0;
}
