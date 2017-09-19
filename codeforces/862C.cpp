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

void solve(int n, int x)
{
    vector<int> ans;
    if(n==1)
    {
        ans.pb(x);
        n=0;
    }
    else if(n==2)
    {
        if(x==0)
        {
            printf("NO\n");
            return;
        }

        ans.pb(1<<18);
        ans.pb((1<<18)+x);
        n=0;
    }
    else
    {
        if(x>0)
        {
            ans.pb(1<<18);
            ans.pb((1<<18)+x);
            n -= 2;
        }
        for(int i=16; i>=2; --i)
        {
            if(n>=(1<<i))
            {
                // dbg(i);
                // dbg(1<<i);
                rep(j,1<<i) ans.pb(j+(1<<i));
                n -= 1<<i;
            }
        }
    }

    // dbg(n);
    if(n>0)
    {
        if(n==1) ans.pb(0);
        else if(n==2)
        {
            ans[0] ^= (1<<19);
            ans.pb(0);
            ans.pb(1<<19);
        }
        else if(n==3)
        {
            int a = 1<<19 , b = 1<<17;
            ans.pb(a);
            ans.pb(b);
            ans.pb(a+b);
        }
        else assert(false);
    }

    n = ans.size();
    printf("YES\n");
    rep(i,n) printf("%d%c", ans[i],(i==n-1?'\n':' '));

    set<int> SS;
    rep(i,n)
    {
        SS.insert(ans[i]);
        assert(ans[i]<=1000000);
    }
    assert(n==(int)SS.size());
    int XX = 0;
    rep(i,n) XX ^= ans[i];
    assert(XX==x);
}

int main()
{
    int n,x;
    cin >>n >>x;
    solve(n,x);
    return 0;
}
