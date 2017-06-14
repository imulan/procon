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

using pi = pair<int,int>;
using vi = vector<int>;

int main()
{
    int n;
    cin >>n;
    vector<vi> c(n,vi(n));
    rep(i,n)
    {
        rep(j,n) cin >>c[i][j];
        sort(all(c[i]));
    }

    vi p(n);
    rep(i,n)rep(j,i)
    {
        int MIN = 191919, MAX = -1;
        int x=0,y=0;
        while(x<n && y<n)
        {
            if(c[i][x]>c[j][y]) ++y;
            else if(c[i][x]<c[j][y]) ++x;
            else
            {
                MIN = min(MIN,c[i][x]);
                MAX = max(MAX,c[i][x]);
                ++x;
                ++y;
            }
        }

        int I = 0, J = 0;
        rep(k,n) I += (c[i][k]<MIN || MAX<c[i][k]);
        rep(k,n) J += (c[j][k]<MIN || MAX<c[j][k]);

        if(I<J) p[j]+=2;
        else if(I>J) p[i]+=2;
        else
        {
            ++p[i];
            ++p[j];
        }
    }

    vector<pi> s(n);
    rep(i,n) s[i]=pi(-p[i],i);
    sort(all(s));
    rep(i,n) cout << s[i].se+1 << endl;
    return 0;
}
