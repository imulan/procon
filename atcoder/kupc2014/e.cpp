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

const string ok = "Possible", ng = "Impossible";
string solve()
{
    int n,m;
    cin >>n >>m;
    if(n>m) swap(n,m);

    if(n==1) return ng;
    if(n==2 && m==4) return ng;

    if(n%8==0)
    {
        if(m>=2) return ok;
    }
    if(n%4==0)
    {
        if(m%2==0) return ok;
    }
    else if(n%2==0)
    {
        if(m%4==0) return ok;
    }
    else
    {
        if(m%8==0) return ok;
    }
    return ng;
}

int main()
{
    int Q;
    cin >>Q;
    while(Q--) cout << solve() << endl;
    return 0;
}
