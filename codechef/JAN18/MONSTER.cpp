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

const int B = 600;
const int N = 1<<17;

// 累積ダメージ
ll d[N]={};
// ブロック内のダメージ
ll t[N]={};

// [l,r)の区間に伝播
void f(int l, int r){
    if(r-l==1) return;

    int m = (l+r)/2;
    f(l,m);
    f(m,r);

    // 最上位ビットが1のやつに入るダメージは最上位ビットが0でも入る
    rep(i,m-l) t[i+l] += t[i+m];
}

int main(){
    int n;
    cin >>n;
    vector<int> h(n);
    rep(i,n) cin >>h[i];

    int Q;
    cin >>Q;
    vector<int> x(Q),y(Q);
    rep(i,Q){
        cin >>x[i] >>y[i];
        x[i] &= (N-1);
    }

    vector<int> ans(Q);
    rep(i,B){
        if(B*i>=Q) break;
        fill(t,t+N,0);
        for(int j=B*i; j<min(B*(i+1),Q); ++j) t[x[j]] += y[j];

        f(0,N);

        vector<int> check;
        rep(j,n){
            // このブロック内で死ぬモンスター
            if(d[j]<h[j] && h[j]<=d[j]+t[j]) check.pb(j);
        }

        for(int j:check){
            ll dam = d[j];
            for(int k=B*i; k<min(B*(i+1),Q); ++k){
                if((j&x[k]) == j) dam += y[k];
                if(dam>=h[j]){
                    --ans[k];
                    break;
                }
            }
        }

        // 累積の方に渡す
        rep(j,n) d[j] += t[j];
    }

    ans[0] += n;
    for(int i=1; i<Q; ++i) ans[i] += ans[i-1];
    rep(i,Q) cout << ans[i] << endl;
    return 0;
}
