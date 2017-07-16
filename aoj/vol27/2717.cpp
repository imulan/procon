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
    int n,m;
    cin >>n >>m;
    vector<string> d(m);
    rep(i,m) cin >>d[i];

    int W=0,E=0;
    rep(i,m)rep(j,n)
    {
        if(d[i][j]=='W') ++W;
        else ++E;
    }

    int er = 19191919;
    int b = 0;
    int w=0,e=0;
    rep(i,n+1)
    {
        int t = e+(W-w);
        if(er>t)
        {
            er = t;
            b = i;
        }

        if(i<n)
        {
            rep(j,m)
            {
                if(d[j][i]=='W') ++w;
                else ++e;
            }
        }
    }

    cout << b << " " << b+1 << endl;
    return 0;
}
