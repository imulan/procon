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

const int N = 200;
vector<int> G[N];

map<vector<int>,int> h2id;

int tree_hash(int v){
    vector<int> hs;
    for(int ch:G[v]){
        hs.pb(tree_hash(ch));
    }
    sort(all(hs));

    if(!h2id.count(hs)) h2id[hs] = h2id.size();
    return h2id[hs];
}

const int MX = 128;

string s;
int n;

int T;
int l[MX],r[MX];
int make_tree(int &idx){
    int ID = T;
    ++T;

    if(s[idx]=='('){
        ++idx;
        l[ID] = make_tree(idx);

        assert(s[idx]==' ');
        ++idx;

        r[ID] = make_tree(idx);
        assert(s[idx]==')');
        ++idx;
    }
    else{
        assert(s[idx]=='x');
        ++idx;
        l[ID] = -1;
        r[ID] = -1;
    }
    return ID;
}

int hs[MX];
int ch_hs[MX][MX];

void mergehs(int v){
    for(int ch:G[v]){
        mergehs(ch);
        rep(i,MX) ch_hs[v][i] += ch_hs[ch][i];
    }
    ++ch_hs[v][hs[v]];
}

using pi = pair<int,int>;
const pi INI(-1,1);
pi sim[MX];

bool small(pi p, pi q){
    return p.fi*q.se < q.fi*p.se;
}

pi calc_sim(int v){
    if(sim[v] != INI) return sim[v];

    pi ret;
    if(l[v] == -1) ret = {0,1};
    else{
        int p = 0, q = 0;
        rep(i,MX){
            int ct = 0;
            if(ch_hs[l[v]][i] > 0) ++ct;
            if(ch_hs[r[v]][i] > 0) ++ct;

            if(ct>0){
                ++q;
                if(ct==2) ++p;
            }
        }

        ret = {p,q};
    }
    return sim[v] = ret;
}

int memo[MX][MX];
int strong(int u, int v){
    if(memo[u][v]!=-1) return memo[u][v];

    // cond.1
    pi sim_u = calc_sim(u), sim_v = calc_sim(v);
    if(small(sim_u,sim_v)) return memo[u][v] = 1;
    if(small(sim_v,sim_u)) return memo[u][v] = 0;

    // cond.2
    if(l[u]==-1 && l[v]==-1) return memo[u][v] = 0;

    // cond.3
    int fu = l[u], su = r[u];
    if(strong(su,fu)) swap(fu,su);

    int fv = l[v], sv = r[v];
    if(strong(sv,fv)) swap(fv,sv);

    if(strong(fu,fv)) return memo[u][v] = 1;
    if(strong(fv,fu)) return memo[u][v] = 0;

    // cond.4
    if(strong(su,sv)) return memo[u][v] = 1;
    if(strong(sv,su)) return memo[u][v] = 0;

    // cond.5
    return memo[u][v] = 0;
}

void SWAP(int v, int flg){
    if(l[v]==-1) return;
    assert(r[v]!=-1);

    int L = l[v], R = r[v];

    int ct[MX]={};
    rep(i,MX){
        if(ch_hs[l[v]][i] > 0) ++ct[i];
        if(ch_hs[r[v]][i] > 0) ++ct[i];
    }

    if(flg == 0){
        if(strong(R,L)) swap(l[v],r[v]);
    }
    else{
        if(strong(L,R)) swap(l[v],r[v]);
    }

    SWAP(l[v],0);
    SWAP(r[v],1);
}

string tree2str(int v){
    if(l[v]==-1) return "x";

    string res = "";
    res += "(";
    res += tree2str(l[v]);
    res += " ";
    res += tree2str(r[v]);
    res += ")";

    return res;
}

int main(){
    while( getline(cin,s), (s!="0") ){
        rep(i,N) G[i].clear();
        h2id.clear();
        rep(i,MX)rep(j,MX) ch_hs[i][j] = 0;
        rep(i,MX) sim[i] = INI;
        memset(memo,-1,sizeof(memo));

        n = s.size();

        T = 0;
        int ttt = 0;
        make_tree(ttt);

        rep(i,T){
            if(l[i]!=-1) G[i].pb(l[i]);
            if(r[i]!=-1) G[i].pb(r[i]);
        }

        rep(i,T) hs[i] = tree_hash(i);

        mergehs(0);

        SWAP(0,0);

        cout << tree2str(0) << endl;
    }
    return 0;
}
