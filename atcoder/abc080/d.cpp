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

const int N = 100010;
int r[30][N]={};

int v[N]={};

int main()
{
    int n,c;
    cin >>n >>c;
    rep(i,n)
    {
        int s,t;
        cin >>s >>t >>c;
        --c;

        ++r[c][s];
        --r[c][t];
    }

    rep(cc,30)rep(i,N-1) r[cc][i+1] += r[cc][i];
    rep(cc,30)
    {
        rep(i,N-1)
        {
            if(r[cc][i]==0 && r[cc][i+1]==1) ++r[cc][i];
        }

        rep(i,N) v[i] += r[cc][i];
    }

    int ans = 0;
    rep(i,N) ans = max(ans,v[i]);
    cout << ans << endl;
    return 0;
}
