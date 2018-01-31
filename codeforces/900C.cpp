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

struct MaxSegTree{
    long n; vector<ll> dat;
    //初期化
    MaxSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MIN);
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return LLONG_MIN;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n;
    cin >>n;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    vector<int> inv_p(n+1);
    rep(i,n) inv_p[p[i]] = i;

    vector<int> rec(n);
    set<int> vis_idx;
    for(int i=n; i>0; --i){
        int idx = inv_p[i];

        auto itr = vis_idx.lower_bound(idx);
        int add = 0;
        if(itr != vis_idx.end()){
            add = rec[*itr];
            // printf(" %d : p[%d] = %d\n",i,*itr,p[*itr]);
        }
        rec[idx] = add+1;
        vis_idx.insert(idx);
    }

    MaxSegTree pos(n+5);
    rep(i,n) pos.update(p[i],-i);

    int l = -1, ans = 191919;
    // p[i]を削除する場合
    int L_maxr = 0, L_maxp = 0;
    rep(i,n){
        pos.update(p[i],-19191919);
        int idx = -max(-191919LL,pos.query(L_maxp+1, n+2));
        int R_maxr = 0;
        if(idx<=n) R_maxr = rec[idx];
        int tl = L_maxr + R_maxr;
        // printf(" %d + %d\n",L_maxr, R_maxr);
        // dbg(i);
        // dbg(tl);
        if(l<tl || (l==tl&&p[i]<ans)){
            l = tl;
            ans = p[i];
        }

        if(L_maxp < p[i]){
            L_maxp = p[i];
            L_maxr++;
        }
    }

    cout << ans << endl;
    return 0;
}
