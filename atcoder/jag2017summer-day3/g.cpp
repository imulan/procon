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

int n,m,k,s;
int a[10][10];

bool ok = false;

pi check()
{
    // 横チェック
    rep(i,n)
    {
        int sum = 0;
        rep(j,m)
        {
            sum += a[i][j];
            if(sum>s) return pi(i,0);
            if(sum<0) sum = 0;
        }
    }

    // 縦チェック
    rep(j,m)
    {
        int sum = 0;
        rep(i,n)
        {
            sum += a[i][j];
            if(sum>s) return pi(j,1);
            if(sum<0) sum=0;
        }
    }

    return pi(-1,-1);
}

void dfs(int d)
{
    pi p = check();
    if(p == pi(-1,-1)) ok = true;
    else
    {
        if(d<k)
        {
            rep(i,n)
            {
                if(p.se==0) a[p.fi][i] = -a[p.fi][i];
                else a[i][p.fi] = - a[i][p.fi];

                dfs(d+1);

                if(p.se==0) a[p.fi][i] = -a[p.fi][i];
                else a[i][p.fi] = - a[i][p.fi];
            }
        }
    }
}

int main()
{
    cin >>n >>m >>k >>s;
    rep(i,n)rep(j,m) cin >>a[i][j];

    dfs(0);

    string ans = "No";
    if(ok) ans = "Yes";
    cout << ans << endl;
    return 0;
}
