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

const int N = 1222222;
int s[N]={};
int only[N]={};

int solve()
{
    int n;
    scanf(" %d", &n);

    vector<int> l(n),r(n);
    vector<int> t;
    rep(i,n)
    {
        scanf(" %d %d", &l[i], &r[i]);
        for(int j=-1; j<=1; ++j)
        {
            t.pb(l[i]+j);
            t.pb(r[i]+j);
        }
    }

    t.pb(-1919);
    sort(all(t));
    t.erase(unique(all(t)),t.end());

    rep(i,n)
    {
        l[i] = lower_bound(all(t),l[i]) - t.begin();
        r[i] = lower_bound(all(t),r[i]) - t.begin();
    }

    rep(i,n)
    {
        ++s[l[i]];
        --s[r[i]+1];
    }

    rep(i,N-1) s[i+1] += s[i];

    rep(i,N) only[i] = (s[i]==1);
    rep(i,N-1) only[i+1] += only[i];

    rep(i,n)if(only[r[i]]-only[l[i]-1]==0) return i+1;
    return -1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
