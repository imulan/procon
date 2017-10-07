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

using pi = pair<int,int>;

pi normalize(int y, int x, int n)
{
    if(y>=n/2) y = n-1-y;
    if(x>=n/2) x = n-1-x;
    return {y,x};
}

int main()
{
    int C,n;
    cin >>C >>n;
    --C;

    vector<vector<int>> p(n,vector<int>(n));
    rep(i,n)
    {
        string tmp;
        cin >>tmp;
        rep(j,n) p[i][j] = tmp[j]-'0';
    }

    set<pi> s;

    vector<vector<int>> ct(n/2,vector<int>(n/2));
    rep(i,n/2)rep(j,n/2)
    {
        ct[i][j] += p[i][j];
        ct[i][j] += p[i][n-1-j];
        ct[i][j] += p[n-1-i][j];
        ct[i][j] += p[n-1-i][n-1-j];

        if(ct[i][j]!=0 && ct[i][j]!=4) s.insert({i,j});
    }

    int ans = 0;
    if(s.empty()) ++ans;

    while(C--)
    {
        // dbg(vector<pi>(all(s)));
        int D;
        cin >>D;
        while(D--)
        {
            int r,c;
            cin >>r >>c;
            --r;
            --c;

            pi pos = normalize(r,c,n);

            if(p[r][c]==0) ++ct[pos.fi][pos.se];
            else --ct[pos.fi][pos.se];
            p[r][c] = !p[r][c];

            if(ct[pos.fi][pos.se]==0 || ct[pos.fi][pos.se]==4) s.erase(pos);
            else s.insert(pos);
        }

        if(s.empty()) ++ans;
    }

    cout << ans << endl;
    return 0;
}
