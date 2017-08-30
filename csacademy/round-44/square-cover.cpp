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

const int N = 300;
const int V = 100001;

int solve()
{
    int n,m,a[N][N];
    cin >>n >>m;

    vector<int> lx(V,m), rx(V,-1), ly(V,n), ry(V,-1);

    rep(i,n)rep(j,m)
    {
        int t;
        cin >>t;
        a[i][j] = t;

        lx[t] = min(lx[t], j);
        rx[t] = max(rx[t], j);
        ly[t] = min(ly[t], i);
        ry[t] = max(ry[t], i);
    }

    rep(v,V)
    {
        if(rx[v]==-1) continue;

        if(ry[v]-ly[v] != rx[v]-lx[v]) return 0;

        for(int i=ly[v]; i<=ry[v]; ++i)for(int j=lx[v]; j<=rx[v]; ++j)if(a[i][j]!=v) return 0;
    }
    return 1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
