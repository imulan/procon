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

const int N=20202;
int x[N]={};

int main()
{
    int n,m,t;
    cin >>n >>m >>t;

    rep(i,n)
    {
        int a;
        cin >>a;
        ++x[a-m];
        --x[a+m];
    }

    rep(i,N-1) x[i+1]+=x[i];

    int ans = 0;
    rep(i,t) ans+=(x[i]==0);
    cout << ans << endl;
    return 0;
}
