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

int f(int t, int l, int r, int pos)
{
    if(pos<l || r<pos) return pos;

    if(t==1)
    {
        if(pos==l) return r;
        return pos-1;
    }
    else return l+r-pos;
}

int main()
{
    int n,q,m;
    scanf(" %d %d %d", &n, &q, &m);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> t(q), l(q), r(q);
    rep(i,q)
    {
        scanf(" %d %d %d", &t[i], &l[i], &r[i]);
        --l[i];
        --r[i];
    }

    vector<int> b(m);
    rep(i,m)
    {
        scanf(" %d", &b[i]);
        --b[i];
    }

    vector<int> idx(b);
    for(int i=q-1; i>=0; --i)
    {
        rep(j,m) idx[j] = f(t[i],l[i],r[i],idx[j]);
    }

    rep(i,m) printf("%d%c", a[idx[i]], " \n"[i==m-1]);
    return 0;
}
