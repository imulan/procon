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

const ll mod = 1e9+7;

int f(char c){
    if(isdigit(c)) return c-'0';
    if(islower(c)) return 10+c-'a';
    return 20+c-'A';
}

const int sz = 30;
vector<int> G[sz];
bool ap[sz];
bool vis[sz];

int main(){
    int n,m;
    string s;
    cin >>n >>m >>s;

    vector<char> var(m);
    vector<int> u(m);
    map<char,int> c2id;
    rep(i,m){
        cin >>var[i] >>u[i];
        c2id[var[i]] = i;
    }

    rep(i,n){
        if(islower(s[i])) s[i] = 'a'+c2id[s[i]];
    }
    rep(i,m) var[i] = 'a'+i;

    ll ans = 0;
    // 1桁 or 2桁
    rep(mask,1<<m){
        // init
        rep(i,sz) G[i].clear();
        fill(ap,ap+sz,false);
        fill(vis,vis+sz,false);

        // check
        bool ok = true;
        rep(i,m){
            // var[i]を2桁にすることは不可能
            if((mask>>i&1) && u[i]<10) ok = false;
        }
        if(!ok) continue;

        string t = "";
        rep(i,n){
            if(islower(s[i])){
                int ss = s[i]-'a';
                if(mask>>ss&1){
                    t += s[i]-'a'+'A';
                    t += s[i];
                }
                else t += s[i];
            }
            else t += s[i];
        }

        int T = t.size();
        rep(i,T){
            int U = f(t[i]), V = f(t[T-1-i]);
            ap[U] = ap[V] = true;
            G[U].pb(V);
            G[V].pb(U);
        }

        vector<vector<int>> cc;
        rep(i,sz)if(ap[i] && !vis[i]){
            vector<int> tmp;
            queue<int> que;
            tmp.pb(i);
            vis[i] = true;
            que.push(i);
            while(!que.empty()){
                int now = que.front();
                que.pop();
                for(int e:G[now])if(!vis[e]){
                    tmp.pb(e);
                    vis[e] = true;
                    que.push(e);
                }
            }
            cc.pb(tmp);
        }

        // dbg(t);
        // dbg(cc);
        rep(mm,1<<m){
            bool valid = true;
            vector<bool> kotei(m);
            rep(i,m){
                if(mm>>i&1){
                    if(!(mask>>i&1)) valid = false;
                    kotei[i] = true;
                }
            }
            if(!valid) continue;

            ll add = 1;
            for(vector<int> comp:cc){
                bool num[10]={};
                int start = 0;
                int lim = 9;
                for(int idx:comp){
                    if(idx<10) num[idx] = true;
                    else if(idx<20){
                        if(kotei[idx-10]){
                            lim = min(lim, u[idx-10]%10);
                        }
                        else{
                            if(u[idx-10]<10) lim = min(lim, u[idx-10]);
                        }
                    }
                    else{
                        start = 1;
                        if(kotei[idx-20]) num[u[idx-20]/10] = true;
                        else lim = min(lim, u[idx-20]/10 - 1);
                    }
                }

                int num_count = 0;
                int NUM = -1;
                rep(i,10)if(num[i]){
                    ++num_count;
                    NUM = i;
                }

                ll mul = 1;
                if(num_count == 0){
                    mul = max(0, lim-start+1);
                }
                else if(num_count == 1){
                    if( !(start<=NUM && NUM<=lim) ) mul = 0;
                }
                else mul = 0;

                (add *= mul) %= mod;
            }
            (ans += add) %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
