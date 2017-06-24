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

bool win[50][50]={};
bool d[50][50]={};

bool dfs(int x, int y)
{
    if(x==0 || y==0) return true;
    if(d[x][y]) return win[x][y];

    bool ret = false;
    int k = min(x,y);
    for(int i=1; i<=k; ++i)
    {
        ret |= !dfs(x-i,y);
        ret |= !dfs(x,y-i);
    }

    d[x][y]=true;
    return win[x][y]=ret;
}

void test()
{
    rep(i,50)
    {
        rep(j,50) printf("%c", "Xo"[dfs(i,j)]);
        printf("\n");
    }
}

bool solve()
{
    int x,y;
    cin >>x >>y;

    if(x>y) swap(x,y);

    if(x==1) return y%2==0;
    if(x==2) return y%4!=2;
    if(x==3) return !(y>=8 && y%4==0);
    if(x==4) return y!=4;
    return true;
}

int main()
{
    // test();
    cout << (solve()?"snuke":"rng") << endl;
    return 0;
}
