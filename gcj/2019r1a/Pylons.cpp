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

int R,C;
bool ok;
vector<pi> ans;
int vis[6][6]={};
void dfs(int r, int c, int d){
    if(ok) return;
    if(d == R*C){
        ans = vector<pi>(R*C);
        vis[r][c] = d;
        ok = true;
        rep(i,R){
            rep(j,C){
                // printf(" %2d", vis[i][j]);
                ans[vis[i][j] - 1] = {i,j};
            }
            // printf("\n");
        }
        vis[r][c] = 0;
    }
    vis[r][c] = d;
    rep(i,R)rep(j,C){
        if(r == i) continue;
        if(c == j) continue;
        if(r-c == i-j) continue;
        if(r+c == i+j) continue;

        if(vis[i][j]>0) continue;
        dfs(i,j,d+1);
    }

    vis[r][c] = 0;
}

void solve(){
    cin >>R >>C;

    if(max(R,C)<=5){
        rep(i,R)rep(j,C) dfs(i,j,1);
        // dbg(ok);
    }
    else{
        ok = true;
        bool sw = false;
        if(R > C){
            swap(R,C);
            sw = true;
        }

        int y = 0;
        bool odd = (R%2==1);
        while(y<R){
            rep(i,C-3){
                ans.pb({y+0,i});
                ans.pb({y+1,i+3});
                if(odd) ans.pb({y+2,i});
            }
            for(int i=C-3; i<C; ++i){
                ans.pb({y+0,i});
                ans.pb({y+1,i-(C-3)});
                if(odd) ans.pb({y+2,i});
            }

            y += 2;
            if(odd){
                ++y;
                odd = false;
            }
        }

        if(sw) for(auto &p:ans) swap(p.fi,p.se);
    }
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T){
        printf("Case #%d: ", i+1);

        ok = false;
        ans.clear();
        solve();
        if(ok){
            cout << "POSSIBLE" << "\n";
            for(const auto &p:ans) cout << p.fi+1 << " " << p.se+1 << "\n";
        }
        else cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
