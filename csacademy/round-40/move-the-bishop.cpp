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

int solve()
{
    int r1,c1,r2,c2;
    cin >>r1 >>c1 >>r2 >>c2;

    if((r1+c1)%2 != (r2+c2)%2) return -1;

    if(r1==r2 && c1==c2) return 0;
    else if(abs(c2-c1) == abs(r2-r1)) return 1;
    return 2;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
