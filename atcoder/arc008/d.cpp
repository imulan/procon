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

using vd = vector<double>;
using mat = vector<vd>;

const mat E = mat({{1,0},{0,1}});

mat mul(const mat &A, const mat &B)
{
    int n = A.size();
    mat C(n,vd(n));
    rep(i,n)rep(j,n)rep(k,n) C[i][j] += A[i][k]*B[k][j];
    return C;
}

struct MatSegTree{
    int n; vector<mat> dat;
    MatSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<mat>(2*n-1,E);
    }
    void update(int k, double a, double b){
        k+=n-1;
        dat[k][0][0]=a;
        dat[k][0][1]=b;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=mul(dat[2*k+1],dat[2*k+2]);
        }
    }
    mat _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return E;

        if(a<=l && r<=b) return dat[k];

        mat vl=_query(a,b,2*k+1,l,(l+r)/2);
        mat vr=_query(a,b,2*k+2,(l+r)/2,r);
        return mul(vl,vr);
    }
    mat query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<ll> ap;

    vector<ll> p(m);
    vector<double> a(m),b(m);
    rep(i,m)
    {
        scanf(" %lld %lf %lf", &p[i], &a[i], &b[i]);
        ap.pb(p[i]);
    }

    sort(all(ap));
    ap.erase(unique(all(ap)),ap.end());
    int SZ = ap.size();

    MatSegTree st(SZ);
    double MIN = 1, MAX = 1;
    rep(i,m)
    {
        int idx = lower_bound(all(ap),p[i]) - ap.begin();
        st.update(SZ-1-idx, a[i], b[i]);

        mat res = st.query(0,SZ);
        double ans = res[0][0]+res[0][1];
        MIN = min(MIN,ans);
        MAX = max(MAX,ans);
    }

    printf("%.10f\n%.10f\n", MIN,MAX);
    return 0;
}
