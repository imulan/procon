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

string col="RYGB";

int main()
{
    int h,w,d;
    cin >>h >>w >>d;
    rep(i,h)
    {
        rep(j,w)
        {
            int idx = 0;
            idx |= (i+j)/d %2;
            idx |= ((500*d+i-j)/d %2)*2;
            printf("%c", col[idx]);
        }
        printf("\n");
    }
    return 0;
}
