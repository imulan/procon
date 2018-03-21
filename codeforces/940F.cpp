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

struct Query{
    int t,x,y;
};

// 既にch_queryをt個,区間[x,y]
vector<Query> mex_query;
// t番目の要素をxからyに変更
vector<Query> ch_query;

const int N = 200000;
int ct[N]={}, sz[N]={};

const int SZ = 2100;
const int B = 60;

using pi = pair<int,int>;
set<pi> mx[B][B]={};
int a[N]={};

int L=0,R=-1;
int T=-1;

inline void pr(){
    ++R;
    --sz[ct[a[R]]];
    ++ct[a[R]];
    ++sz[ct[a[R]]];
}

inline void pl(){
    --sz[ct[a[L]]];
    --ct[a[L]];
    ++sz[ct[a[L]]];
    ++L;
}

inline void mr(){
    --sz[ct[a[R]]];
    --ct[a[R]];
    ++sz[ct[a[R]]];
    --R;
}

inline void ml(){
    --L;
    --sz[ct[a[L]]];
    ++ct[a[L]];
    ++sz[ct[a[L]]];
}

inline void pt(){
    ++T;
    int idx = ch_query[T].t;

    if(L<=idx && idx<=R){
        --sz[ct[a[idx]]];
        --ct[a[idx]];
        ++sz[ct[a[idx]]];
    }

    assert(a[idx] == ch_query[T].x);
    a[idx] = ch_query[T].y;

    if(L<=idx && idx<=R){
        --sz[ct[a[idx]]];
        ++ct[a[idx]];
        ++sz[ct[a[idx]]];
    }
}

inline void mt(){
    int idx = ch_query[T].t;

    if(L<=idx && idx<=R){
        --sz[ct[a[idx]]];
        --ct[a[idx]];
        ++sz[ct[a[idx]]];
    }

    assert(a[idx] == ch_query[T].y);
    a[idx] = ch_query[T].x;

    if(L<=idx && idx<=R){
        --sz[ct[a[idx]]];
        ++ct[a[idx]];
        ++sz[ct[a[idx]]];
    }
    --T;
}

inline int calc(){
    int ret = 1;
    while(sz[ret]!=0) ++ret;
    return ret;
}

int main(){
    int n,Q;
    scanf(" %d %d", &n, &Q);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> ta(n);
    rep(i,n) ta[i] = a[i];

    rep(i,Q){
        int t,l,r;
        scanf(" %d %d %d", &t, &l, &r);
        if(t==1){
            --l;
            --r;
            mex_query.pb({(int)ch_query.size(), l, r});
        }
        else{
            --l;
            ch_query.pb({l, ta[l], r});
            ta[l] = r;
        }
    }

    // クエリ全体で現れる値を列挙
    vector<int> v;
    rep(i,n) v.pb(a[i]);
    for(const auto &q:ch_query) v.pb(q.y);
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    // 変換
    rep(i,n) a[i] = lower_bound(all(v), a[i]) - v.begin();
    rep(i,ch_query.size()){
        ch_query[i].x = lower_bound(all(v), ch_query[i].x) - v.begin();
        ch_query[i].y = lower_bound(all(v), ch_query[i].y) - v.begin();
    }

    // ブロックごとにクエリを分類
    int M = mex_query.size();
    rep(i,M) mx[mex_query[i].t/SZ][mex_query[i].x/SZ].insert({mex_query[i].y, i});

    // 実際にクエリを処理
    vector<int> ans(M);
    rep(i,B)rep(j,B){
        for(const auto &p:mx[i][j]){
            int ID = p.se;

            // 区間を動かす
            while(R < mex_query[ID].y) pr();
            while(mex_query[ID].y < R) mr();
            while(mex_query[ID].x < L) ml();
            while(L < mex_query[ID].x) pl();

            // ch_queryを動かす
            while(T+1 < mex_query[ID].t) pt();
            while(mex_query[ID].t < T+1) mt();

            // 答えを求める
            ans[ID] =  calc();
        }
    }

    rep(i,M) printf("%d\n", ans[i]);
    return 0;
}
