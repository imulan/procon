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

vector<int> p({2,3,5,7,11,13,17,19,23,29,31,37,41,43,47});
ll n;
ll ax,ay;

void dfs(int idx, int lim, ll x, ll y)
{
    if(idx==p.size()) return;

    if(x>ax || (x==ax&&y<ay))
    {
        ax=x;
        ay=y;
    }

    for(int i=1; i<=lim; ++i)
    {
        if(y*p[idx]>n) break;
        dfs(idx+1,i,x*(i+1),y*p[idx]);
        y*=p[idx];
    }
}

int main()
{
    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        scanf(" %lld",&n);

        ax=ay=1;
        dfs(0,60,1,1);
        printf("%lld %lld\n", ax, ay);
    }
    return 0;
}
