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
    int n,q;
    scanf(" %d %d", &n, &q);
    vector<int> a(q),b(q);
    rep(i,q)
    {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
    }

    vector<int> x(n),pos(n),fin(n);
    iota(all(x),0);
    iota(all(pos),0);
    iota(all(fin),0);

    rep(i,q)
    {
        swap(pos[x[a[i]]],pos[x[b[i]]]);
        swap(x[a[i]],x[b[i]]);
    }

    vector<int> ans(n);
    for(int j=-1; j<=1; ++j)
    {
        int nx = pos[0]+j;
        if(0<=nx && nx<n) ans[nx]=1;
    }
    for(int i=q-1; i>=0; --i)
    {
        swap(pos[x[a[i]]],pos[x[b[i]]]);
        swap(fin[a[i]],fin[b[i]]);
        swap(x[a[i]],x[b[i]]);

        for(int j=-1; j<=1; ++j)
        {
            int nx = pos[0]+j;
            if(0<=nx && nx<n) ans[fin[nx]]=1;
        }
    }

    printf("%d\n", accumulate(all(ans),0));
    return 0;
}
