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

int main()
{
    ll N;
    int m,k,d,s;
    cin >>N >>m >>k >>d >>s;

    int start = s;

    int id = 0;
    map<ll,int> r2id;

    vector<int> a(m),b(m),c(m);
    rep(i,m)
    {
        ll r;
        scanf(" %d %d %lld", &a[i], &b[i], &r);

        if(!r2id.count(r)) r2id[r] = id++;
        c[i] = r2id[r];
    }

    int n;
    if(id<N) n = id+1;
    else n = id;

    map<int,int> last;
    multiset<int> ss;
    rep(i,n)
    {
        last[i] = 0;
        ss.insert(0);
    }

    int idx = 0;
    rep(_,k)
    {
        s += d;
        while(idx<m && a[idx]<=s)
        {
            ss.erase(ss.find(last[c[idx]]));

            if(last[c[idx]]<a[idx]) last[c[idx]] = a[idx]+b[idx];
            else last[c[idx]] = last[c[idx]] + b[idx];

            ss.insert(last[c[idx]]);
            ++idx;
        }

        auto itr = ss.begin();
        if(*itr>s) s = *itr;
    }

    printf("%d\n", s-start);
    return 0;
}
