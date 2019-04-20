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

using vi = vector<int>;

map<vi,bool> dp;

bool dfs(const vi &v)
{
    if(dp.count(v)) return dp[v];

    int n = v.size();

    int s=0;
    int rem=0;
    rep(i,n)
    {
        s+=v[i];
        rem += (v[i]>0);
    }
    if(s==0) return false;
    if(rem==1) return true;

    bool ret=false;
    rep(i,n)
    {
        if(v[i]==0) continue;
        for(int j=1; j<=v[i]; ++j)
        {
            vector<int> nx(v);
            nx[i] -= j;
            sort(all(nx));
            ret |= !dfs(nx);
        }
    }

    return dp[v]=ret;
}

void test(int n)
{
    vector<int> a(n);
    iota(all(a),1);

    dp.clear();
    if(dfs(a)) printf("O\n");
    else printf("X\n");
}

int main()
{
    ll n;
    cin >>n;
    test(n);

    return 0;
}
