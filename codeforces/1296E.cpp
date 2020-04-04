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
    int n; vector<ll> dat;
    // 初期化
    MaxSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    // [a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int A = 26;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int n;
    string s;
    cin >>n >>s;

    vector<int> pos[A];
    for(int i=n-1; i>=0; --i) pos[s[i]-'a'].pb(i);

    MaxSegTree st(n);
    vector<int> c(n);
    int ans = 0;
    for(int i=A-1; i>=0; --i)for(int j:pos[i]){
        c[j] = st.query(0,j)+1;
        st.update(j, c[j]);
        ans = max(ans, c[j]);
    }

    // output for E1
    // if(ans >= 3) cout << "NO\n";
    // else{
    //     cout << "YES\n";
    //     rep(i,n) cout << c[i]-1;
    //     cout << "\n";
    // }
    // return 0;

    // output for E2
    cout << ans << "\n";
    rep(i,n) cout << c[i] << " \n"[i==n-1];
    return 0;
}
