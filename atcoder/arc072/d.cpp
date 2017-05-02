#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

bool vis[100][100]={};
bool win[100][100]={};

bool dfs(ll x, ll y)
{
    if(vis[x][y]) return win[x][y];

    bool ret=false;

    for(ll i=1; 2*i<=x; ++i) ret |= !dfs(x-2*i,y+i);
    for(ll i=1; 2*i<=y; ++i) ret |= !dfs(x+i,y-2*i);

    vis[x][y]=true;
    return win[x][y]=ret;

}

void test()
{
    win[0][0]=win[1][0]=win[0][1]=false;
    vis[0][0]=vis[1][0]=vis[0][1]=true;

    rep(i,50)
    {
        rep(j,50) printf("%c", "XO"[dfs(i,j)]);
        printf("\n");
    }
}

int main()
{
    // test();

    ll x,y;
    cin >>x >>y;
    cout << (abs(x-y)<=1?"Brown":"Alice") << endl;
    return 0;
}
