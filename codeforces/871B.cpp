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

int query(int i, int j)
{
    printf("? %d %d\n", i,j);
    fflush(stdout);

    int r;
    scanf(" %d", &r);

    if(r==-1) assert(false);
    return r;
}

void test()
{
    // vector<int> p({3,1,2,0});
    // vector<int> p({0,2,1,3});
    vector<int> p({1,3,0,2});
    int n = p.size();

    vector<int> b(p);
    rep(i,n)
    {
        rep(j,n) printf(" %d", p[i]^b[j]);
        printf("\n");
    }

}

int main()
{
    // test();

    int n;
    scanf(" %d", &n);

    if(n==1)
    {
        printf("!\n1\n0\n");
        return 0;
    }

    vector<int> b0(n),val(n);
    rep(i,n) b0[i] = query(i,0);
    rep(i,n) val[i] = query(i,(i+1)%n);

    int ct=0;
    vector<int> ans(n,-1);
    rep(B,n)
    {
        vector<int> p(n);
        rep(i,n) p[i] = B^b0[i];

        vector<int> e(n);
        rep(i,n)
        {
            if(0<=p[i] && p[i]<n) e[p[i]]++;
        }
        bool valid = true;
        rep(i,n)if(e[i]!=1) valid = false;
        if(!valid) continue;

        vector<int> b(n);
        rep(i,n) b[p[i]] = i;

        bool ok = true;
        rep(i,n)
        {
            if(p[b[i]]!=i) ok = false;
            if(b0[i] != (p[i]^b[0])) ok = false;
            if(val[i] != (p[i]^b[(i+1)%n])) ok = false;
        }

        if(ok)
        {
            // dbg(p);dbg(b);
            ans = p;
            ++ct;
        }
    }

    assert(ct>0);
    printf("!\n%d\n",ct);
    rep(i,n) printf("%d%c", ans[i],(i==n-1)?'\n':' ');
    fflush(stdout);
    return 0;
}
