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

int solve(int n, int k)
{
    if(1<=k && k<=n)
    {
        if(n%2==1 && k==(n+1)/2) return n-1;
        return n-2;
    }
    return 0;
}

int main()
{
    int n,k;
    cin >>n >>k;
    cout << solve(n,k) << endl;
    return 0;
}
