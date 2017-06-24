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
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    int ans = 0;
    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    for(int i=1; i<h; ++i)rep(j,w)
    {
        if(s[i][j]!='-') continue;

        int add = 1;
        // 隣をみる
        for(const auto &X:vector<int>({1,-1}))
        {
            int nx = j+X;
            if(IN(nx,i) && s[i][nx]!='-') add=0;
        }
        // 8近傍をみる
        for(int y=-1; y<=1; ++y)for(int x=-1; x<=1; ++x)
        {
            int nx = j+x, ny = i+y;
            if(IN(nx,ny) && s[ny][nx]=='x') add=0;
        }

        ans += add;
    }

    cout << ans << endl;
    return 0;
}
