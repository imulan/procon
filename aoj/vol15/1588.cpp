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

int n,m,k;
int a[15],b[15];

int idx[4];
ll ans = 0;
void dfs(int num)
{
    if(num==k)
    {
        vector<pair<int,int>> v;
        rep(i,k) v.pb({a[idx[i]],b[idx[i]]});
        sort(all(v));
        reverse(all(v));

        int rem = m;
        ll t = 0;
        rep(i,k)
        {
            int A = v[i].fi, B = v[i].se;

            t += A*min(B,rem);
            rem -= min(B,rem);
        }
        t += rem;

        ans = max(ans,t);
        return;
    }

    rep(i,n)
    {
        bool ok = true;
        rep(j,num) ok &= (idx[j]!=i);

        if(ok)
        {
            idx[num] = i;
            dfs(num+1);
            idx[num] = -1;
        }
    }
}

int main()
{
    cin >>n >>m >>k;
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    memset(idx,-1,sizeof(idx));
    dfs(0);
    cout << ans << endl;
    return 0;
}
