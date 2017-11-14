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

bool solve()
{
    int x1,y1,x2,y2;
    cin >>x1 >>y1 >>x2 >>y2;

    int X,Y;
    cin >>X >>Y;

    int wx = abs(x1-x2), wy = abs(y1-y2);

    if(wx%X!=0 || wy%Y!=0) return false;
    return (wx/X)%2 == (wy/Y)%2;
}

int main()
{
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
