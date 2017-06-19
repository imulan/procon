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

void solve()
{
    int H,W,h,w;
    cin >>H >>W >>h >>w;
    if(H%h==0 && W%w==0)
    {
        printf("No\n");
        return;
    }

    vector<vector<int>> r(H,vector<int>(W));
    bool f = false;
    if(H%h==0)
    {
        f = true;
        swap(H,W);
        swap(h,w);
    }

    rep(i,H)
    {
        int v = -1000;
        if(i%h==0) v=h*1000-1001;
        rep(j,W)
        {
            if(f) r[j][i]=v;
            else r[i][j]=v;
        }
    }

    if(f) swap(H,W);
    printf("Yes\n");
    rep(i,H)
    {
        rep(j,W)
        {
            if(j) printf(" ");
            printf("%d", r[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    solve();
    return 0;
}
