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

bool valid(const vector<int> &a, int k)
{
    int n = a.size();
    rep(i,n-1)if(abs(a[i+1]-a[i])>k) return false;
    return true;
}

void solve()
{
    int n,k;
    scanf(" %d %d", &n, &k);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    if(valid(a,k))
    {
        printf("0\n");
        return;
    }

    // not empty
    vector<int> invalid;
    rep(i,n-1)
    {
        if(abs(a[i+1]-a[i])>k) invalid.pb(i);
    }

    int I = invalid.size();
    if(I>4)
    {
        printf("-1\n");
        return;
    }

    rep(i,I)for(int ii=-1; ii<=1; ++ii)
    {
        int x = invalid[i]+ii;
        if(x<0 || n<=x) continue;

        rep(j,n)
        {
            swap(a[x],a[j]);
            bool ok = true;

            vector<int> v(invalid);
            v.pb(j);
            if(j>0) v.pb(j-1);

            for(const auto &idx:v)
            {
                for(const auto &p:vector<int>({1,-1}))
                {
                    int nx = idx+p;
                    if(0<=nx && nx<n)
                    {
                        if(abs(a[idx]-a[nx])>k) ok = false;
                    }
                }
            }
            if(ok)
            {
                printf("%d %d\n", x+1,j+1);
                return;
            }
            swap(a[x],a[j]);
        }
    }

    printf("-1\n");
}

int main()
{
    solve();
    return 0;
}
