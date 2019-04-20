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
using P = pair<pi,int>;

const int B = 1000;
const int Q = 1000000;
const int N = 1000000;

int n;
int t[N];

// ((R,L),qid)
vector<P> query[B];
int ans[Q];

int L = 0, R = -1;
int ct[N] = {};
int now = 0;

inline void pr(){
    ++R;
    int val = t[R];
    if(ct[val]==0) ++now;
    else if(ct[val]==1) --now;
    ++ct[val];
}

inline void mr(){
    int val = t[R];
    if(ct[val]==2) ++now;
    else if(ct[val]==1) --now;
    --ct[val];
    --R;
}

inline void pl(){
    int val = t[L];
    if(ct[val]==2) ++now;
    else if(ct[val]==1) --now;
    --ct[val];
    ++L;
}

inline void ml(){
    --L;
    int val = t[L];
    if(ct[val]==0) ++now;
    else if(ct[val]==1) --now;
    ++ct[val];
}

int main(){
    scanf(" %d", &n);

    vector<int> sorted_t;
    rep(i,n){
        scanf(" %d", &t[i]);
        sorted_t.pb(t[i]);
    }
    sort(all(sorted_t));
    sorted_t.erase(unique(all(sorted_t)), sorted_t.end());
    rep(i,n) t[i] = lower_bound(all(sorted_t),t[i]) - sorted_t.begin();

    int q;
    scanf(" %d", &q);
    rep(i,q){
        int l,r;
        scanf(" %d %d", &l, &r);
        --l; --r;
        query[l/B].pb({{r,l},i});
    }

    rep(i,B){
        sort(all(query[i]));
        for(const auto &qq:query[i]){
            int l = qq.fi.se, r = qq.fi.fi, qid = qq.se;
            while(R<r) pr();
            while(r<R) mr();
            while(L<l) pl();
            while(l<L) ml();
            ans[qid] = now;
        }
    }

    rep(i,q) printf("%d\n", ans[i]);
    return 0;
}
