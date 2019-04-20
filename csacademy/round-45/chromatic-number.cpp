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

struct edge{int to; ll cost};

const int N = 300;
vector<edge> G[N];

int main()
{
    int n,m,k;
    cin >>n >>m >>k;
    rep(i,m)
    {
        int u,v,c;
        cin >>u >>v >>c;
        --u;
        --v;
    }

    

    return 0;
}
