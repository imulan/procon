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

int n;
string s[5];

void print_map(){
    cout << "------" << endl;
    rep(i,n) cout << s[i] << endl;
    cout << "------" << endl;
}

pi get_state(){
    int mask = 0;
    int pos = -1;
    rep(i,n)rep(j,n){
        int idx = i*n+j;
        if(s[i][j]=='#') mask |= 1<<idx;
        if(s[i][j]=='@') pos = idx;
    }

    assert(pos!=-1);
    return {pos,mask};
}

void make_state(int pos, int mask){
    rep(i,n)rep(j,n){
        int idx = i*n+j;
        if(mask>>idx&1) s[i][j] = '#';
        else if(idx == pos) s[i][j] = '@';
        else s[i][j] = '.';
    }
}

bool move(int y, int x){
    if(s[y][x] == '#') return false;

    rep(i,n)rep(j,n)if(s[i][j]=='@') s[i][j]='.';
    s[y][x] = '@';
    return true;
}

void infect(){
    string t[5];
    rep(i,n) t[i]=s[i];

    rep(i,n)rep(j,n){
        if(t[i][j]=='@') s[i][j]='@';
        else{
            int ct = 0;
            for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
                if(dy==0 && dx==0) continue;

                int y = i+dy, x = j+dx;
                if(0<=y && y<n && 0<=x && x<n) ct += (t[y][x]!='.');
            }

            if(t[i][j]=='#'){
                if(ct==2 || ct==3) s[i][j] = '#';
                else s[i][j] = '.';
            }
            else{
                if(ct==3) s[i][j] = '#';
                else s[i][j] = '.';
            }
        }
    }
}

unordered_map<int,int> dp[25];
int solve(){
    rep(i,25) dp[i].clear();

    pi start = get_state();
    if(start.se==0) return 0;

    queue<pi> que;
    que.push(start);
    dp[start.fi][start.se] = 0;
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        int pos = now.fi, mask = now.se;
        if(mask == 0) return dp[pos][mask];

        // make_state(pos,mask);
        // dbg(dp[pos][mask]);
        // print_map();

        int py = pos/n, px = pos%n;

        for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
            if(dy==0 && dx==0) continue;

            int ny = py+dy, nx = px+dx;
            if(0<=ny && ny<n && 0<=nx && nx<n){
                make_state(pos,mask);

                if(move(ny,nx)){
                    infect();
                    pi nxt = get_state();
                    if(!dp[nxt.fi].count(nxt.se)){
                        if(nxt.se == 0) return dp[pos][mask]+1;

                        dp[nxt.fi][nxt.se] = dp[pos][mask]+1;
                        que.push(nxt);
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    while(cin >>n,n){
        rep(i,n) cin >>s[i];
        cout << solve() << endl;
    }
    return 0;
}
