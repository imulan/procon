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

using vi = vector<int>;
using mat = vector<vi>;

void P(const mat &a)
{
    int n = a.size();
    rep(i,n)
    {
        rep(j,n) printf("%d%c", a[i][j], " \n"[j==n-1]);
    }
}

mat f(int n, int k, int d)
{
    mat ZERO(n,vi(n));
    if(k<d) return ZERO;

    mat a(n,vi(n));
    rep(i,d) a[i][i] = 1;
    k -= d;

    if(k%2!=0) return ZERO;
    rep(i,n)for(int j=i+1; j<n; ++j)
    {
        if(k==0) break;

        k -= 2;
        a[i][j] = a[j][i] = 1;
    }

    return a;
}

void solve(int n, int k)
{
    mat ret(n,vi(n));

    if(n*n<k)
    {
        printf("-1\n");
        return;
    }

    rep(i,n+1) ret = max(ret,f(n,k,i));
    P(ret);
}

int main()
{
    int n,k;
    cin >>n >>k;
    solve(n,k);
    return 0;
}
