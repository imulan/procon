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

string s[10];
bool check()
{
    int dx[4]={1,0,1,-1}, dy[4]={0,1,1,1};
    rep(d,4)
    {
        rep(i,10)rep(j,10)
        {
            int ct = 0;
            rep(k,5)
            {
                int x = j+k*dx[d], y = i+k*dy[d];
                if(0<=x && x<10 && 0<=y && y<10) ct += (s[y][x]=='X');
            }
            if(ct==5) return true;
        }
    }
    return false;
}

string solve()
{
    rep(i,10) cin >>s[i];
    rep(i,10)rep(j,10)if(s[i][j]=='.')
    {
        s[i][j] = 'X';
        if(check()) return "YES";
        s[i][j] = '.';
    }
    return "NO";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
