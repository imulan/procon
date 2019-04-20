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

const int N = 303;
const ll INF = LLONG_MAX/3;

bool prime[N];
vector<int> p;
int P;

int Q;
int m[N],x[N];

int LIM[7] = {8,5,3,2,2,2,2};
vector<int> num;
ll dfs(int idx)
{
    if(idx==P) return 0;

    if(idx<7)
    {
        ll ret = -INF;
        rep(i,LIM[idx]+1)
        {
            p[idx] = i;
            ret = max(ret,)

            p[idx] = 0;
        }
    }
    else
    {
        ll num = 1;
        rep()

        ll val = 0;
        rep(i,n)if(m[i]%p[idx]==0) val += x[i];
        return dfs(idx+1) + max(0,val);
    }
}

int main()
{
    fill(prime,prime+N,true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i)if(prime[i])
    {
        for(int j=2*i; j<N; j+=i) prime[j] = false;
    }

    rep(i,N)if(prime[i]) p.pb(i);
    P = p.size();

    cin >>Q;
    rep(i,Q) cin >>m[i] >>x[i];

    num = vector<int>(P);
    cout << dfs(0) << endl;
    return 0;
}
