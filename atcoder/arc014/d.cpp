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
    int A,n,m;
    scanf(" %d %d %d", &A, &n, &m);
    vector<int> L(n);
    rep(i,n) scanf(" %d", &L[i]);

    vector<int> d(n-1);
    rep(i,n-1) d[i]=L[i+1]-L[i]-1;
    sort(all(d));

    vector<int> sumd(n);
    rep(i,n-1) sumd[i+1] = sumd[i]+d[i];

    while(m--)
    {
        int x,y;
        scanf(" %d %d", &x, &y);

        int ans = n;
        ans += min(L[0]-1,x);
        ans += min(A-L[n-1],y);
        if(n>1)
        {
            int idx = upper_bound(all(d),x+y)-d.begin();
            int r = n-1-idx;
            ans += r*(x+y) + sumd[idx];
        }

        printf("%d\n", ans);
    }
    return 0;
}
