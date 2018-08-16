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

const int SZ = 2;
struct Trie{
    vector<array<int,SZ>> nodes;
    vector<int> rem;

    Trie(){
        nodes.pb({});
        rem.pb(0);
    }

    void add(int x){
        int node_num = 0;
        for(int i=17; i>=0; --i){
            int b = x>>i&1;
            // 行き先が無いのでnodeを作成
            if(!nodes[node_num][b]){
                nodes[node_num][b] = nodes.size();
                nodes.pb({});
                rem.pb(x);
            }
            node_num = nodes[node_num][b];
            rem[node_num] = min(rem[node_num], x);
        }
    }

    // x との XOR を最大化出来る値を見つける
    int query(int x, int lim){
        int ret = 0;
        int node_num = 0;
        for(int i=17; i>=0; --i){
            int b = !(x>>i&1);
            // bと同じ方向にあれば行きたい
            if(!nodes[node_num][b]) b = !b;

            // 無理
            if(!nodes[node_num][b]) return -1;

            // 妥協しないといけない
            if(ret+(b<<i) > lim || rem[ nodes[node_num][b] ]>lim) b = !b;

            // 無理
            if(!nodes[node_num][b] || ret+(b<<i) > lim) return -1;

            node_num = nodes[node_num][b];
            // --rem[node_num];
            ret |= b<<i;
        }
        // printf("x %d ret %d\n", x,ret);
        return ret;
    }
};

vector<int> divisor(int x){
    vector<int> ret;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            ret.pb(i);
            if(i != x/i) ret.pb(x/i);
        }
    }
    return ret;
}

const int N = 100001;

int main(){
    vector<Trie> t(N);

    int Q;
    scanf(" %d", &Q);
    while(Q--){
        int type;
        scanf(" %d", &type);
        if(type==1){
            int u;
            scanf(" %d", &u);
            for(int d:divisor(u)) t[d].add(u);
        }
        else{
            int x,k,s;
            scanf(" %d %d %d", &x, &k, &s);
            int lim = s-x;

            int ans = -1;
            if(x%k==0 && lim>0) ans = t[k].query(x,lim);

            printf("%d\n", ans);
        }
    }
    return 0;
}
