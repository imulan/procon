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

struct SuffixArray{
    const string &s;

    int n;
    vector<int> sa, rank;
    vector<int> lcp;

    void construct_sa(){
        sa.resize(n+1);
        rank.resize(n+1);
        // 1文字でのランク
        rep(i,n+1){
            sa[i] = i;
            rank[i] = (i<n)?s[i]:-1;
        }
        vector<int> tmp(n+1,0);
        for(int k=1; k<=n; k*=2){
            auto comp = [&](const int i, const int j){
                if(rank[i] != rank[j]) return rank[i] < rank[j];
                int ri = (i+k<=n)?rank[i+k]:-1;
                int rj = (j+k<=n)?rank[j+k]:-1;
                return ri < rj;
            };
            sort(all(sa), comp);
            tmp[sa[0]] = 0;
            for(int i=1; i<=n; ++i){
                tmp[sa[i]] = tmp[sa[i-1]];
                if(comp(sa[i-1], sa[i])) ++tmp[sa[i]];
            }
            swap(tmp, rank);
        }
    }

    SuffixArray(const string &str) : s(str){
        n = s.size();
        construct_sa();
    }

    // lcp配列が欲しかったら個別に呼ぶ
    void construct_lcp(){
        lcp.resize(n+1);

        int h = 0;
        lcp[0] = 0;
        rep(i,n){
            int j = sa[rank[i]-1];

            // hを先頭のぶん減らし、後ろが一致しているまで増やす
            if(h>0) --h;
            for(; j+h<n && i+h<n; ++h){
                if(s[j+h] != s[i+h]) break;
            }

            lcp[rank[i]-1] = h;
        }
    }

    int getRank(const string &t) const {
        int m = t.size();
        int l = 0, r = n+1;
        while(r-l>1){
            int mid = (l+r)/2;
            if(s.compare(sa[mid], m, t) < 0) l = mid;
            else r = mid;
        }
        return r;
    }
};

const ll INF = LLONG_MAX/3;

struct SegTree{
    int n; vector<ll> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,INF);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N = 100010, X = 32;
int dp[N][X];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m,x;
    string s,t;
    cin >>n >>s >>m >>t >>x;

    string C = s+'#'+t;
    SuffixArray sa(C);
    sa.construct_lcp();

    vector<int> l = sa.lcp;
    int L = l.size();
    SegTree st(L);
    rep(i,n+m+1) st.update(i, l[i]);

    rep(i,n)rep(j,x+1){
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        if(j<x){
            int RI = sa.rank[i], RJ = sa.rank[n+1+dp[i][j]];
            // printf(" RI RJ %d %d\n",RI,RJ);
            // printf("index: %d %d,  lcp %d\n",i,n+1+dp[i][j],add);
            if(RI>RJ) swap(RI,RJ);
            int add = st.query(RI,RJ);
            int ni = i + add;
            dp[ni][j+1] = max(dp[ni][j+1], dp[i][j]+add);
        }
    }

    string ans = "NO";
    rep(i,x+1)if(dp[n][i]==m) ans = "YES";
    cout << ans << endl;
    return 0;
}
