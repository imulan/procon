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

const int X = 100000;
int my[X]={};

int main()
{
    int w,h,n;
    cin >>w >>h >>n;
    rep(i,n)
    {
        int x,y;
        cin >>x >>y;

        my[x] = max(my[x],y);
    }

    int yy = 0;
    int ans = w-1;
    for(int i=w-1; i>0; --i)
    {
        yy = max(yy,my[i]);
        ans = min(ans, i-1+yy);
    }

    cout << ans << endl;
    return 0;
}
