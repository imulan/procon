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

string solve()
{
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)

    int px,py;
    rep(i,h)rep(j,w)if(s[i][j]=='%')
    {
        py = i;
        px = j;
    }

    while(1)
    {
        vector<string> ns(s);
        rep(i,h)rep(j,w)if(s[i][j]=='@')
        {
            rep(k,4)
            {
                int nx = j+dx[k], ny = i+dy[k];
                if(IN(nx,ny) && (s[ny][nx]=='.'||s[ny][nx]=='%')) ns[ny][nx]='@';
            }
        }

        rep(i,h)rep(j,w)if(s[i][j]=='$')
        {
            rep(k,4)
            {
                int nx = j+dx[k], ny = i+dy[k];
                if(IN(nx,ny) && s[ny][nx]!='#') ns[ny][nx]='$';
            }
        }

        s = ns;
        if(s[py][px]=='@') return "Yes";
        if(s[py][px]=='$') return "No";
    }
}

int main()
{
    cout << solve() << endl;
    return 0;
}
