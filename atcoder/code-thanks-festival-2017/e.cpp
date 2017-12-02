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

int n;

int query(const vector<int> &s)
{
    printf("?");
    rep(i,n) printf(" %d", s[i]);
    printf("\n");
    cout << flush;

    int ret;
    cin >>ret;
    return ret;
}

void finish(const vector<int> &a)
{
    printf("!");
    rep(i,n) printf(" %d", a[i]);
    printf("\n");
    cout << flush;
}

void test()
{
    vector<int> v({8,9,10,11,12});
    map<int,int> m;
    rep(a,5)rep(b,5)rep(c,5)rep(d,5)rep(e,5)
    {
        int x = v[a]+10*v[b]+100*v[c]+1000*v[d]+10000*v[e];
        dbg(x);
        ++m[x];
    }

    for(const auto &p:m)
    {
        if(p.se>1) printf("!!!! (%d %d)\n", p.fi,p.se);
    }
}

int main()
{
    // test();
    vector<int> v({8,9,10,11,12});

    cin >>n;
    vector<int> ans(n,0);

    rep(i,n/5)
    {
        int pw = 1;
        vector<int> q(n);
        rep(j,5)
        {
            q[5*i+j] = pw;
            pw*=10;
        }

        int Q = query(q);

        rep(a,5)rep(b,5)rep(c,5)rep(d,5)rep(e,5)
        {
            int x = v[a]+10*v[b]+100*v[c]+1000*v[d]+10000*v[e];
            if(x==Q)
            {
                ans[5*i]=a%2;
                ans[5*i+1]=b%2;
                ans[5*i+2]=c%2;
                ans[5*i+3]=d%2;
                ans[5*i+4]=e%2;
                a=b=c=d=e=5;
            }
        }
    }

    if(n%5!=0)
    {
        int pw = 1;
        vector<int> q(n);
        rep(j,n%5)
        {
            q[5*(n/5)+j] = pw;
            pw*=10;
        }

        int Q = query(q);

        rep(a,5)rep(b,5)rep(c,5)rep(d,5)rep(e,5)
        {
            int x = v[a]+10*v[b]+100*v[c]+1000*v[d]+10000*v[e];
            if(n%5<=4) x -= 10000*v[e];
            if(n%5<=3) x -= 1000*v[d];
            if(n%5<=2) x -= 100*v[c];
            if(n%5<=1) x -= 10*v[b];
            // dbg(x);

            if(x==Q)
            {
                vector<int> vv;
                vv.pb(a);
                vv.pb(b);
                vv.pb(c);
                vv.pb(d);
                vv.pb(e);

                // dbg(vv);

                rep(j,n%5) ans[5*(n/5)+j]=vv[j]%2;
                a=b=c=d=e=5;
            }
        }
    }

    finish(ans);
    return 0;
}
