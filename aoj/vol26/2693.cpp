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

const int N = 16;
const int np[4]={0,1,2,6};

int n,k;
string s[N],rs[N];

vector<string> p[N];

string restore(int last, int perm){
    return rs[last] + p[last][perm];
}

string process(string f, int x){
    int sz = f.size();

    int idx = 0;
    string look = "";
    string rest = "";
    rep(i,sz){
        if(idx<k && s[x][idx] == f[i]){
            look += f[i];
            ++idx;
        }
        else rest += f[i];
    }

    if(idx == k){
        reverse(all(look));
        return look + rest;
    }
    else return "#";
}


bool ok[N][6][N][6];
vector<pi> G[N][6], rG[N][6];

struct State{
    int mask,last,perm;
};

bool dp[1<<N][N][6];

int main(){
    cin >>n >>k;
    rep(i,n){
        cin >>s[i];
        rs[i] = s[i];
        reverse(all(rs[i]));

        int used[N]={};
        rep(j,s[i].size()) ++used[s[i][j]-'A'];

        string tt = "";
        rep(j,n)if(!used[j]) tt += ('A'+j);

        do{
            p[i].pb(tt);
        }while(next_permutation(all(tt)));
    }

    rep(i,n)rep(ii,np[n-k])rep(j,n)rep(jj,np[n-k]){
        if(i==j) continue;
        string from = restore(i,ii), to = restore(j,jj);
        string pp = process(from, j);
        if(pp==to){
            ok[i][ii][j][jj] = true;
            G[i][ii].pb({j,jj});
            rG[j][jj].pb({i,ii});
        }
    }

    queue<State> que;
    rep(i,n)rep(j,np[n-k]){
        dp[(1<<n)-1][i][j] = true;
        que.push({(1<<n)-1,i,j});
    }
    while(!que.empty()){
        State now = que.front();
        que.pop();
        int nmask = now.mask - (1<<(now.last));
        for(const auto e:rG[now.last][now.perm]){
            if(nmask>>e.fi&1){
                if(!dp[nmask][e.fi][e.se]){
                    dp[nmask][e.fi][e.se] = true;
                    que.push({nmask,e.fi,e.se});
                }
            }
        }
    }

    string ans = "Z";
    rep(i,n){
        int mask = 1<<i;
        rep(j,np[n-k]){
            if(!dp[mask][i][j]) continue;
            string tmp = "";
            tmp += ('A'+i);

            State ss = {mask,i,j};
            while(ss.mask != (1<<n)-1){
                bool found = false;
                rep(ni,n)rep(nj,np[n-k]){
                    if(ss.mask>>ni&1) continue;

                    if(ok[ss.last][ss.perm][ni][nj]){
                        ss.mask |= (1<<ni);
                        ss.last = ni;
                        ss.perm = nj;

                        tmp += ('A'+ni);

                        found = true;
                        ni = n;
                        nj = np[n-k];
                        break;
                    }
                }
                if(!found) break;
            }

            if(tmp.size() == n) ans = min(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}
