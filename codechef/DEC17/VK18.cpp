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

int f(int x)
{
    int r=0;
    while(x)
    {
        int v = x%10;
        int m = 1;
        if(v%2==1) m = -1;

        r += m*v;
        x/=10;
    }
    return abs(r);
}

const int N = 1000010;
ll ans[N]={}, s[2*N]={};

int main()
{
    for(int i=1; i<2*N; ++i) s[i] = s[i-1]+f(i);
    for(int i=1; i<N-2; ++i) ans[i] = ans[i-1]-f(2*i)+2*(s[2*i]-s[i]);

    int T;
    cin >>T;
    while(T--)
    {
        int n;
        cin >>n;
        cout << ans[n] << endl;
    }
    return 0;
}
