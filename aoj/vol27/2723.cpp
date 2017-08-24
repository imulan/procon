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

int dx[6]={1,-1,0,0,0,0}, dy[6]={0,0,1,-1,0,0}, dz[6]={0,0,0,0,1,-1};

int main()
{
    ll a,b,c;
    int n;
    cin >>a >>b >>c >>n;
    
    #define IN(x,y,z) (0<=x && x<a && 0<=y && y<b && 0<=z && z<c)
    ll ans = 2*(a*b+b*c+c*a);
    set<tuple<int,int,int>> s;
    rep(i,n)
    {
        int x,y,z;
        cin >>x >>y >>z;
        rep(j,6)
        {
            int nx = x+dx[j], ny = y+dy[j], nz = z+dz[j];
            if(IN(nx,ny,nz) && !s.count(make_tuple(nx,ny,nz))) ++ans;
            else --ans;
        }
        s.insert(make_tuple(x,y,z));
    }

    cout << ans << endl;
    return 0;
}
