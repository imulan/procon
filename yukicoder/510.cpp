#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using vl = vector<ll>;
using mat = vector<vl>;

const mat E{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
const mat I{{1,0,0,0},{0,0,0,1},{0,0,0,1},{0,0,0,1}};

const ll mod = 1e9+7;

mat mul(const mat &A, const mat &B)
{
    int n = A.size();
    mat C(n,vl(n,0));
    rep(i,n)rep(j,n)rep(k,n) (C[i][j]+=A[i][k]*B[k][j])%=mod;
    return C;
}

struct MatSegTree{
    int n; vector<mat> dat;
    //初期化
    MatSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<mat>(2*n-1,I);
    }
    //k番目(0-indexed)のx/yをaに変更
    void update(int k, int xy, ll a){
        k+=n-1;

        a%=mod;
        if(xy==0)
        {
            dat[k][0][2]=a;
        }
        else
        {
            dat[k][1][1]=a;
            dat[k][2][1]=(2*a)%mod;
            dat[k][2][2]=(a*a)%mod;
        }
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=mul(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    mat _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return E;
        if(a<=l && r<=b) return dat[k];

        mat L=_query(a,b,2*k+1,l,(l+r)/2);
        mat R=_query(a,b,2*k+2,(l+r)/2,r);
        return mul(L,R);
    }
    //[a,b)
    mat query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n,q;
    scanf(" %d %d", &n, &q);

    MatSegTree st(n);
    while(q--)
    {
        char o;
        int i,v;
        scanf(" %c %d", &o, &i);
        if(o=='a')
        {
            ll ans=1;
            if(i>0)
            {
                mat M = st.query(n-i,n);
                ans = 0;
                rep(j,4) (ans += M[0][j])%=mod;
            }
            printf("%lld\n", ans);
        }
        else
        {
            scanf(" %d", &v);
            st.update(n-1-i,(o=='y'),v);
        }
    }
    return 0;
}
