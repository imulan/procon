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
    int n;
    cin >>n;

    vector<int> b(n-1);
    rep(i,n-1)
    {
        int a;
        cin >>a;
        if(a>0) b[i+a-1]=max(b[i+a-1],a);
    }

    for(int i=n-2; i>0; --i)b[i-1] = max(b[i-1],b[i]-1);

    rep(i,n-1) printf("%d%c", b[i],(i==n-2?'\n':' '));
    return 0;
}
