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

inline vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str + sep);
    string buffer;
    while( getline(ss,buffer,sep ) ) v.pb(buffer);
    return v;
}

const int N = 500000;

set<int> ch[N];
ll sz[N]={};
bool leaf[N]={};

int M = 0;
map<string, int> name2id;
vector<string> id2name;

ll t;
void dfs(int v){
    if(ch[v].size()==0){
        leaf[v] = true;
        return;
    }
    for(int nx:ch[v]){
        dfs(nx);
        sz[v] += sz[nx];
    }
}

void dfs2(int v){
    int child_d = 0;
    for(int nx:ch[v]){
        if(!leaf[nx]) ++child_d;
    }

    // dbg(id2name[v]);
    // dbg(child_d);

    if(child_d==0){
        cout << "  " << id2name[v] << " " << sz[v] << endl;
        return;
    }

    bool exp = false;
    for(int nx:ch[v]){
        exp |= (sz[nx]>=t);
    }

    if(exp){
        cout << "- " << id2name[v] << " " << sz[v] << endl;
        for(int nx:ch[v])if(!leaf[nx]) dfs2(nx);
    }
    else cout << "+ " << id2name[v] << " " << sz[v] << endl;
}

int main(){
    int n;
    cin >>n;

    using ps = pair<string, ll>;
    vector<ps> ss(n);
    rep(i,n) cin >>ss[i].fi >>ss[i].se;
    sort(all(ss));

    rep(i,n){
        vector<string> v = split(ss[i].fi, '/');
        int V = v.size();

        string name = "";
        string par = "?";
        rep(j,V){
            name += v[j];
            name += '/';

            if(!name2id.count(name)){
                id2name.pb(name);
                name2id[name] = M++;
            }

            // cout << name << " " << name2id[name] << endl;
            if(j>0){
                int x = name2id[par], y = name2id[name];
                ch[x].insert(y);
            }
            par = name;
        }
        sz[name2id[name]] += ss[i].se;
    }

    cin >>t;
    dfs(0);
    dfs2(0);
    return 0;
}
