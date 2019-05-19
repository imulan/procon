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

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    // 初期化
    BIT(){}
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }
    // sum of [1,i]
    ll sum(int i){
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
    // [l,r]
    ll sum(int l, int r){
        return sum(r)-sum(l-1);
    }
};

const int M = 2020;
const int N = 3333;

BIT row[N],col[N];

int main(){
    int h,w,k;
    cin >>h >>w >>k;

    vector<string> s(h);
    rep(i,h) cin >>s[i];

    vector<vector<pair<int,int>>> v(h+w-1);
    rep(i,h)rep(j,w) v[i+j].pb({i, j});

    rep(i,N){
        row[i] = BIT(N);
        col[i] = BIT(N);
    }

    auto calc = [&](int y, int x, ll val){
        y -= M;
        x -= M;
        if(s[y][x] == '#') return 0;
        return (int)!val;
    };

    ll sum = 0;
    int pi = M, pj = M;
    vector<vector<int>> dp(N,vector<int>(N));
    rep(i,h+w-1){
        sort(all(v[i]));
        int V = v[i].size();

        int si = v[i][0].fi+M, sj = v[i][0].se+M;
        if(i>0){
            int ti = pi-k, tj = pj;
            while(ti<=pi){
                sum -= dp[ti][tj];
                ++ti;
                --tj;
            }
            sum += dp[pi][pj];

            if(pi == si) sum += col[sj].sum(si-k,si-1);
            else sum += row[si].sum(sj-k,sj-1);
        }

        dp[si][sj] = calc(si, sj, sum);
        ll tsum = sum;
        for(int j=1; j<V; ++j){
            int ti = v[i][j].fi+M, tj = v[i][j].se+M;
            tsum -= col[tj+1].sum(ti-k-1, ti-1-1);
            tsum += row[ti].sum(tj-k, tj-1);
            dp[ti][tj] = calc(ti, tj, tsum);
        }

        rep(j,V){
            int ti = v[i][j].fi+M, tj = v[i][j].se+M;
            row[ti].add(tj, dp[ti][tj]);
            col[tj].add(ti, dp[ti][tj]);
        }

        pi = si;
        pj = sj;
    }

    cout << (dp[M+h-1][M+w-1]?"Cacao":"Chieno") << endl;
    return 0;
}
