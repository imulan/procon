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

const int B=317;

int n;
int x[B][B],r[B],ct[B][2];

void update_rev(int bid)
{
    if(r[bid])
    {
        rep(i,B)if(bid*B+i<n) x[bid][i] = !x[bid][i];
    }
    r[bid]=0;
}

void update_ct(int bid)
{
    rep(i,2) ct[bid][i]=0;
    rep(i,B)if(bid*B+i<n) ++ct[bid][x[bid][i]];
}

void rev(int L, int R)
{
    int lid=L/B, rid=R/B;
    update_rev(lid);
    update_rev(rid);
    if(lid==rid)
    {
        for(int i=L; i<=R; ++i) x[lid][i%B] = !x[lid][i%B];
    }
    else
    {
        for(int i=L; i<B*(lid+1); ++i) x[lid][i%B] = !x[lid][i%B];
        for(int i=B*rid; i<=R; ++i) x[rid][i%B] = !x[rid][i%B];
        for(int bid=lid+1; bid<rid; ++bid) r[bid] = !r[bid];
    }
    update_ct(lid);
    update_ct(rid);
}

int count(int L, int R)
{
    int ret = 0;
    int lid=L/B, rid=R/B;
    if(lid==rid)
    {
        for(int i=L; i<=R; ++i) ret += (x[lid][i%B]+r[lid])%2;
    }
    else
    {
        for(int i=L; i<B*(lid+1); ++i) ret += (x[lid][i%B]+r[lid])%2;
        for(int i=B*rid; i<=R; ++i) ret += (x[rid][i%B]+r[rid])%2;
        for(int bid=lid+1; bid<rid; ++bid) ret += ct[bid][!r[bid]];
    }
    return ret;
}

int main()
{
    int q;
    cin >>n >>q;

    rep(i,n) ++ct[i/B][0];
    while(q--)
    {
        int t,L,R;
        cin >>t >>L >>R;
        if(t==1) rev(L,R-1);
        else cout << count(L,R-1) << endl;
    }
    return 0;
}
