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

const int MAX_V = 40;
int V = MAX_V; //頂点数
vector<int> G[MAX_V]; //グラフ
int match[MAX_V]; // マッチングのペア
bool used[MAX_V]; // dfsで既に調べたか

void add_edge(int u, int v){
    G[u].push_back(v); G[v].push_back(u);
}

// 増加パスの探索
bool bp_dfs(int v){
    used[v]=true;
    rep(i,G[v].size()){
        int u=G[v][i], w=match[u];
        if(w<0 || (!used[w]&&bp_dfs(w))){
            match[v]=u; match[u]=v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int ret=0;
    memset(match,-1,sizeof(match));
    rep(i,V){
        if(match[i]<0){
            memset(used,0,sizeof(used));
            if(bp_dfs(i)) ++ret;
        }
    }
    return ret;
}


vector<string> read_seq(){
    vector<string> ret;
    while(1){
        string s;
        cin >>s;

        if(s.back() == '.'){
            ret.pb(s.substr(0,s.size()-1));
            break;
        }
        ret.pb(s);
    }
    return ret;
}

const int A = 'Z'-'A'+1;

int n,m;
vector<string> w,s;
int ct;

vector<int> EN;
vector<bool> uw;
void dfs(int d, const vector<int> &en){
    if(d==m){
        ++ct;
        EN = en;
        return;
    }

    int sz = s[d].size();
    rep(i,n)if(!uw[i]){
        if(s[d].size() != w[i].size()) continue;

        bool valid = true;
        vector<int> t_en(en);
        rep(j,sz){
            int idw = w[i][j]-'A', ids = s[d][j]-'A';

            if(t_en[idw]==-1) t_en[idw] = ids;
            else{
                if(t_en[idw] != ids){
                    valid = false;
                    break;
                }
            }

            if(t_en[ids]==-1) t_en[ids] = idw;
            else{
                if(t_en[ids] != idw){
                    valid = false;
                    break;
                }
            }
        }
        if(!valid) continue;

        // check
        rep(j,MAX_V) G[j].clear();
        for(int ii=d+1; ii<m; ++ii)rep(jj,n){
            if(uw[jj] || jj==i) continue;
            if(s[ii].size() != w[jj].size()) continue;

            int LEN = s[ii].size();
            bool add = true;
            rep(k,LEN){
                if(t_en[w[jj][k]-'A'] != -1 && t_en[w[jj][k]-'A'] != s[ii][k]-'A') add = false;

                if(t_en[s[ii][k]-'A'] != -1 && t_en[s[ii][k]-'A'] != w[jj][k]-'A') add = false;

                if(!add) break;
            }

            if(add){
                // printf(" --- ADD %d %d\n",ii,jj);
                add_edge(ii,m+jj);
            }
        }

        int res = bipartite_matching();
        if(res == m-1-d){
            uw[i] = true;
            dfs(d+1,t_en);
            uw[i] = false;
            if(ct>1) return;
        }
    }
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    while(cin >>n,n){
        w = vector<string>(n);
        rep(i,n) cin >>w[i];

        vector<string> seq = read_seq();

        s = seq;
        sort(all(s));
        s.erase(unique(all(s)), s.end());
        m = s.size();

        sort(all(s), [](const string &lh, const string &rh){ return (lh.size()==rh.size() ? (lh<rh) : (lh.size() > rh.size())); });

        uw = vector<bool>(n,false);
        ct = 0;
        dfs(0, vector<int>(A,-1));

        string ans = "";
        if(ct == 1){
            rep(i,seq.size()){
                if(i) ans += ' ';
                rep(j,seq[i].size()) ans += EN[seq[i][j]-'A']+'A';
            }
        }
        else ans = "-";

        ans += '.';
        cout << ans << endl;
    }
    return 0;
}
