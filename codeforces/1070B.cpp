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

bool valid = true;

const int SZ = 2;
struct Trie{
    vector<array<int,SZ>> nodes;
    vector<int> flg;
    vector<int> par;

    vector<int> white,black;
    vector<string> ans;

    Trie(){
        nodes.pb({});
        flg.pb(0);
        par.pb(-1);
    }

    void add(ll a, int x, char c){
        int node_num = 0;
        int lim = 32-x;
        for(int i=31; i>=lim; --i){
            int b = a>>i&1;

            if(!nodes[node_num][b]){
                nodes[node_num][b] = nodes.size();
                nodes.pb({});
                flg.pb(0);
                par.pb(node_num);
            }

            bool child = false;
            if(flg[node_num] == 2) child = true;

            node_num = nodes[node_num][b];
            if(child) flg[node_num] = 2;
        }

        if(c == '+'){
            if(flg[node_num] == -1) valid = false;
            else{
                flg[node_num] = 2;
                white.pb(node_num);
            }
        }
        else{
            if(flg[node_num] == 1 || flg[node_num] == 2) valid = false;
            else{
                flg[node_num] = -1;
                black.pb(node_num);
            }
        }
    }

    void fill_w(){
        // dbg(white);
        for(int i:white){
            int now = i;
            now = par[now];
            while(now != -1){
                if(flg[now] == -1){
                    valid = false;
                    break;
                }
                else flg[now] = 1;

                // printf("  WHITE %d\n",now);
                now = par[now];
            }
        }
    }

    void fill_b(){
        for(int i:black){
            int now = i;
            while(1){
                if(flg[now] == 1) break;
                if(flg[now] == 2){
                    valid = false;
                    break;
                }

                flg[now] = -1;

                // printf("  BLACK %d\n",now);

                if(par[now] == -1) break;
                now = par[now];
            }
        }
    }

    void dfs(int num, int dep, const vector<int> &mask){
        if(flg[num]==-1){
            string add = "";
            rep(i,4){
                int val = 0;
                rep(j,8){
                    int idx = i*8+j;
                    val += (1<<(7-j))*mask[idx];
                }
                add += to_string(val);

                if(i<3) add += ".";
            }

            add += "/";
            add += to_string(dep);

            ans.pb(add);
            return;
        }

        rep(i,2){
            if(nodes[num][i]){
                vector<int> nmask(mask);
                nmask[dep] = i;
                dfs(nodes[num][i], dep+1, nmask);
            }
        }
    }

    void out(){
        cout << ans.size() << "\n";
        for(string aa:ans) cout << aa << "\n";
    }
};

int main(){
    int n;
    cin >>n;

    Trie t;
    rep(i,n){
        string s;
        cin >>s;

        char c = s[0];

        s = s.substr(1);

        int sl = -1;
        rep(j,s.size())if(s[j]=='/') sl = j;

        int x = 32;
        if(sl>=0){
            x = stoi(s.substr(sl+1));
            s = s.substr(0,sl+1);
        }

        vector<int> pps;
        rep(j,s.size())if(s[j]=='.') pps.pb(j);
        pps.pb(s.size());

        vector<int> a;
        int st = 0;
        rep(j,4){
            a.pb(stoi(s.substr(st,pps[j]-st)));
            st = pps[j]+1;
        }

        ll v = 0;
        ll pw = 1;
        for(int j=3; j>=0; --j){
            v += pw*a[j];
            pw *= (1LL<<8);
        }

        // dbg(a);
        // dbg(x);
        // dbg(bitset<32>(v));

        t.add(v,x,c);
    }

    t.fill_w();

    t.fill_b();
    if(!valid){
        printf("-1\n");
        return 0;
    }

    vector<int> mm(32,0);
    t.dfs(0,0,mm);

    t.out();
    return 0;
}
