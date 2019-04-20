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

using pi = pair<int,int>;

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

bool solve(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    pi robot[2];
    rep(i,h)rep(j,w){
        if(s[i][j]!='#' && s[i][j]!='.') robot[s[i][j]-'1'] = {i,j};
    }

    vector<vector<vector<pi>>> G(h,vector<vector<pi>>(w));
    rep(i,h)rep(j,w)if(s[i][j]!='#'){
        rep(d,4){
            int ny = i+dy[d], nx = j+dx[d];
            if(IN(ny,nx) && s[ny][nx]!='#') G[i][j].pb({ny,nx});
        }
    }

    set<pi> vis;
    vis.insert(robot[0]);
    queue<pi> que({robot[0]});
    while(!que.empty()){
        pi p = que.front();
        que.pop();
        for(const auto &e:G[p.fi][p.se]){
            if(!vis.count(e)){
                vis.insert(e);
                que.push(e);
            }
        }
    }

    if(!vis.count(robot[1])) return false;

    int ct[3]={};
    for(const auto &p:vis){
        int d = G[p.fi][p.se].size();
        if(d>2) return true;
        ++ct[d];
    }

    int CC = vis.size();
    if(ct[1]==2 && ct[2]==CC-2) return false;
    return true;
}

int main(){
    cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
