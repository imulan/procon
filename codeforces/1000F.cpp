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

using pi = pair<int,int>;

struct SegTree{
    int n; vector<int> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, int a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k] = dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

vector<int> uniform(vector<int> v){
    int n = v.size();

    int x = 0;
    map<int,int> m;
    rep(i,n){
        if(!m.count(v[i])) m[v[i]] = x++;
        v[i] = m[v[i]];
    }
    return v;
}


const int N = 500005;
vector<pi> Q[N];


int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    a = uniform(a);

    int q;
    scanf(" %d", &q);
    rep(i,q){
        int l,r;
        scanf(" %d %d", &l, &r);
        --l;
        --r;
        Q[r].pb({l,i});
    }

    vector<int> pos(n,-1),mos(n,-1);
    SegTree st(n);
    vector<int> ans(q);
    rep(r,n){
        int val = a[r];

        if(mos[val] != -1){
            dbg("HO");
            st.update(mos[val], 0);
        }
        if(pos[val] != -1){
            mos[val] = pos[val];
            st.update(mos[val], -1);
        }
        pos[val] = r;
        st.update(r,1);

        dbg(pos);
        dbg(mos);

        for(const auto &p:Q[r]){
            int l = p.fi, ID = p.se;
            ans[ID] = st.query(l,r+1);
        }
    }
    rep(i,q) printf("%d\n", ans[i]);
    return 0;
}
