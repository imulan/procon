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

int d[200][200];
const int INF = 123456789;

int main()
{
    int n,m,R;
    cin >>n >>m >>R;
    vector<int> r(R);
    rep(i,R)
    {
        cin >>r[i];
        --r[i];
    }
    sort(all(r));

    fill(d[0],d[200],INF);
    rep(i,n) d[i][i] = 0;
    rep(i,m)
    {
        int a,b,c;
        cin >>a >>b >>c;
        --a;
        --b;
        d[a][b] = d[b][a] = c;
    }

    rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

    int ans = INF;
    do {
        int t = 0;
        rep(i,R-1) t+=d[r[i]][r[i+1]];
        ans = min(ans,t);
    } while(next_permutation(all(r)));
    cout << ans << endl;
    return 0;
}
