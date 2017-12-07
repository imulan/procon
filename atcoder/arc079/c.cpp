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

bool solve()
{
    int n,m;
    cin >>n >>m;

    vector<set<int>> G(n);
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        --a; --b;
        G[a].insert(b);
        G[b].insert(a);
    }

    for(int i=1; i<n-1; ++i)
    {
        if(G[0].count(i) && G[n-1].count(i)) return true;
    }
    return false;
}

int main()
{
    cout << (solve()?"POSSIBLE":"IMPOSSIBLE") << endl;
    return 0;
}
