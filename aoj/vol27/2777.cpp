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

const int B = 500;
const int N = 250000;

int n;
bool same[B]={};
ll all_add[B]={};
ll a[N]={};

void update_same(int bid)
{
    bool ok = true;
    rep(i,B-1) ok &= (a[bid*B+i]==a[bid*B+i+1]);
    same[bid] = ok;
}

int check()
{
    rep(i,B)
    {
        if(!same[i]) return 0;
        if(a[i*B]+all_add[i]!=0) return 0;
    }
    return 1;
}

void add(int l, int r, int x)
{
    int lb = l/B, rb = r/B;
    if(lb==rb)
    {
        for(int i=l; i<=r; ++i) a[i] += x;
    }
    else
    {
        // left
        for(int i=l; i<(lb+1)*B; ++i) a[i] += x;
        // mid
        for(int i=lb+1; i<rb; ++i) all_add[i] += x;
        // right
        for(int i=rb*B; i<=r; ++i) a[i] += x;
    }
    update_same(lb);
    update_same(rb);
}

int query(int l, int r, int x)
{
    if(l<n/2 && r>=n/2)
    {
        add(l, n/2-1, x);
        add(n-1-r, n/2-1, -x);
    }
    else
    {
        if(r<n/2) add(l, r, x);
        else add(n-1-r, n-1-l, -x);
    }
    return check();
}

int main()
{
    scanf(" %d", &n);

    vector<int> s(n);
    rep(i,n) scanf(" %d", &s[i]);

    // init
    rep(i,n/2) a[i] += s[i];
    for(int i=n/2; i<n; ++i) a[n-1-i] -= s[i];

    rep(i,B) update_same(i);

    // query
    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int l,r,x;
        scanf(" %d %d %d", &l, &r, &x);
        --l;
        --r;
        printf("%d\n", query(l,r,x));
    }

    return 0;
}
