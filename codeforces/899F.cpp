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

struct SegTree{
    int n; vector<ll> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }

    int find(int x){
        int l=-1, r=n-1;
        while(r-l>1){
            int m = (l+r)/2;
            if(query(0,m+1)<x) l=m;
            else r=m;
        }
        return r;
    }
};

// 62種類
int f(char c){
    if(isdigit(c)) return c-'0';
    else if(isupper(c)) return c-'A'+10;
    else if(islower(c)) return c-'a'+36;
    assert(false);
}

char finv(int x){
    if(x<10) return '0'+x;
    else if(x<36) return 'A'+x-10;
    else if(x<62) return 'a'+x-36;
    assert(false);
}

const int N = 62;
set<int> idx[N];

int main(){
    int n,Q;
    string s;
    cin >>n >>Q >>s;

    rep(i,n) idx[f(s[i])].insert(i);
    SegTree t(n);
    rep(i,n) t.update(i,1);

    while(Q--){
        int L,R;
        char c;
        cin >>L >>R >>c;

        int l = t.find(L), r = t.find(R);

        int id = f(c);
        auto itr = idx[id].lower_bound(l);
        while(itr!=idx[id].end() && *itr<=r){
            t.update(*itr,0);
            itr = idx[id].erase(itr);
        }
    }

    string a(n,' ');
    rep(i,N){
        for(int j:idx[i]) a[j] = finv(i);
    }

    string ans = "";
    rep(i,n)if(a[i]!=' ') ans += a[i];
    cout << ans << endl;
    return 0;
}
