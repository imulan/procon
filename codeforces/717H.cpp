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

template<typename T=uint32_t>
class Xorshift128 {
private:
  static constexpr T MASK = 0x7FFFFFFF;
  T x = 123456789, y = 987654321, z = 1000000007, w;
public:
  T rnd(){
    T t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return w & MASK;
  }
  Xorshift128(const T seed = 1000000009) : w(seed) {}
};

const int N = 50000;
vector<int> G[N];

int main(){
    Xorshift128<> rng;

    int n,e;
    scanf(" %d %d", &n, &e);

    vector<int> a(e), b(e);
    rep(i,e){
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }

    int T = 0;
    vector<vector<int>> v;
    rep(i,n){
        int L;
        scanf(" %d", &L);

        vector<int> t(L);
        rep(j,L){
            scanf(" %d", &t[j]);
            --t[j];

            T = max(T,t[j]+1);
        }

        random_device seed_gen;
        mt19937 engine(seed_gen());
        shuffle(all(t), engine);

        v.pb(t);
    }

    // 頻度
    vector<int> f(T,0);
    rep(i,n){
        rep(j,v[i].size()) ++f[v[i][j]];
    }

    vector<int> identity(n,-1);
    rep(i,n){
        rep(j,v[i].size()){
            if(f[v[i][j]]==1) identity[i] = v[i][j];
        }
    }

    vector<int> team(T,1);
    rep(i,n)if(identity[i] == -1){
        int sz = v[i].size();
        bool black = false;
        rep(j,sz){
            if(team[v[i][j]] == 2) black = true;
        }
        if(black) continue;

        int idx = rng.rnd()%sz;
        team[v[i][idx]] = 2;
    }
    rep(i,n)if(identity[i] != -1){
        int sz = v[i].size();
        bool black = false;
        rep(j,sz){
            if(team[v[i][j]] == 2) black = true;
        }

        if(!black){
            team[identity[i]] = 2;
        }
    }

    // check
    rep(i,n){
        int sz = v[i].size();
        int c[3]={};
        rep(j,sz) ++c[team[v[i][j]]];
        assert(c[1]>0 && c[2]>0);
    }

    vector<int> trainer(n,-1);



    // treaner assignment
    rep(i,n) printf("%d%c", trainer[i], " \n"[i==n-1]);
    // team assginment
    rep(i,T) printf("%d%c", team[i], " \n"[i==T-1]);
    return 0;
}
