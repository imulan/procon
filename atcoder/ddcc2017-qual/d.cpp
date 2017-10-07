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

ll h,w,a,b;
int f[200][200]={};

void t()
{
    int def[200][200];
    rep(i,h)rep(j,w) def[i][j] = f[i][j];

    rep(i,h)rep(j,w) f[j][i] = def[i][j];
    swap(h,w);
    swap(a,b);
}

ll calc()
{
    int A = 0;
    int X = 0;
    int O = 0;

    rep(i,h)rep(j,w)if(f[i][j])
    {
        if(f[h-1-i][j])
        {
            ++X;
            if(j<w/2 && f[i][w-1-j] && f[h-1-i][w-1-j]) ++A;
        }
        else ++O;
    }

    X/=2;
    A/=2;
    X -= 2*A;

    if(O>0) --O;
    else
    {
        if(X>0) --X;
        else
        {
            if(A>0)
            {
                --A;
                ++X;
            }
        }
    }

    // dbg(X);dbg(A);dbg(O);
    return (a+b)*(A+1) + a*X + A*max(a,b);
}

int main()
{
    cin >>h >>w >>a >>b;
    rep(i,h)
    {
        string s;
        cin >>s;
        rep(j,w) f[i][j] = (s[j]=='S');
    }

    ll ans = 0;
    ans = max(ans,calc());
    t();
    ans = max(ans,calc());

    cout << ans << endl;
    return 0;
}
