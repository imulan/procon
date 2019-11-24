#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

struct MaxSegTree{
    int n; vector<int> dat;
    // 初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,-1);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, int a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    // 内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return -1;

        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    // [a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int solve(){
    int n;
    cin >>n;

    MaxSegTree t(n);
    rep(i,n){
        int a;
        cin >>a;
        t.update(i,a);
    }

    int m;
    cin >>m;

    vector<int> pw(n+1);
    rep(i,m){
        int p,s;
        cin >>p >>s;
        pw[s] = max(pw[s], p);
    }

    for(int i=n-1; i>=0; --i) pw[i] = max(pw[i], pw[i+1]);

    auto check = [&](int l, int r){
        int ma = t.query(l,r);
        return pw[r-l] >= ma;
    };

    int now = 0;
    int ans = 0;
    while(now < n){
        int ok=0, ng=n+1;
        while(ng-ok>1){
            int mid = (ok+ng)/2;

            if(now+mid <= n && check(now,now+mid)) ok = mid;
            else ng = mid;
        }

        if(ok == 0) break;
        now += ok;
        ++ans;
    }

    if(now != n) ans = -1;
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) cout << solve() << "\n";
    return 0;
}
