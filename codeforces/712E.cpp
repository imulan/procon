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

using pd = pair<double, double>;

struct SegTree{
    int n; vector<pd> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pd>(2*n-1,{1,0});
    }

    pd merge(pd l, pd r){
        double x1 = l.fi, y1 = l.se;
        double x2 = r.fi, y2 = r.se;

        double X = x1*x2 / (1 - y1*(1-x2));
        double Y = y2 + (1-y2)*y1*x2 / (1 - (1-x2)*y1);
        return {X,Y};
    }

    //k番目(0-indexed)の値をaに変更
    void update(int k, double a){
        k+=n-1;
        dat[k] = {a,a};
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=merge(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    pd _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return {1,0};

        if(a<=l && r<=b) return dat[k];

        pd vl=_query(a,b,2*k+1,l,(l+r)/2);
        pd vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)
    pd query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    SegTree st(n);
    rep(i,n){
        int a,b;
        scanf(" %d %d", &a, &b);
        st.update(i, (double)a/b);
    }

    while(q--){
        int t;
        scanf(" %d", &t);
        if(t==1){
            int i,a,b;
            scanf(" %d %d %d", &i, &a, &b);
            --i;
            st.update(i, (double)a/b);
        }
        else{
            int l,r;
            scanf(" %d %d", &l, &r);
            --l; --r;
            printf("%.10f\n", st.query(l,r+1).fi);
        }
    }

    return 0;
}
