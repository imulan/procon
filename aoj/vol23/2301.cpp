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

int K;
double P,E,T;

double dfs(int n, double l, double r)
{
    double m = (l+r)/2;
    if(n==K)
    {
        if(abs(T-m)<=E) return 1;
        else return 0;
    }

    // 区間カバーがない
    if(r<T-E || T+E<l) return 0;
    // 区間を完全に覆った
    if(T-E<=l && r<=T+E) return 1;

    double ret = 0;
    if(m>T)
    {
        ret += P*dfs(n+1,m,r);
        ret += (1-P)*dfs(n+1,l,m);
    }
    else
    {
        ret += (1-P)*dfs(n+1,m,r);
        ret += P*dfs(n+1,l,m);
    }
    return ret;
}

int main()
{
    int L,R;
    cin >>K >>L >>R >>P >>E >>T;
    printf("%.10f\n", dfs(0,L,R));
    return 0;
}
