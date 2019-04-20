#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

vector<string> sp_sp(string s){
    s += ' ';
    vector<string> ret;

    string t = "";
    for(char c:s){
        if(c==' '){
            ret.pb(t);
            t = "";
        }
        else t += c;
    }

    return ret;
}

void solve(istream &fin, ostream &fout){
    int n;
    fin >>n;

    string unk;
    getline(fin,unk);

    map<string,int> name2id;
    vector<int> dp(n);
    vector<int> par(n,-1);
    rep(i,n){
        string s;
        getline(fin, s);
        vector<string> v = sp_sp(s);

//        for(string vv:v) cout << "  !!" <<vv<<endl;

        int V = v.size();
        string a = v[0];
        a = a.substr(0,a.size()-1);

        if(!name2id.count(a)) name2id[a] = i;

        for(int j=1; j<V; ++j){
            string m = v[j];
            if(m.size()>0 && m[0]=='@' && m!=a){
                int idx = -1;
                if(name2id.count(m)) idx = name2id[m];
                if(idx == -1) continue;

//                printf(" IDX %d\n",idx);

                if(dp[i] < dp[idx]+1){
                    dp[i] = dp[idx]+1;
                    par[i] = idx;
                }
            }
        }

        if(dp[i] > dp[name2id[a]]) name2id[a] = i;


//        printf(" dp %d: %d\n",i,dp[i]);
    }

    int mx = -1;
    int now = 0;
    rep(i,n){
        if(dp[i] > mx){
            mx = dp[i];
            now = i;
        }
    }

    vector<int> ans;
    while(now!=-1){
        ans.pb(now);
        now = par[now];
    }
    reverse(all(ans));

    int A = ans.size();
    fout << A << "\n";
    rep(i,A) fout << ans[i]+1 << " \n"[i==A-1];
}

int main(){
#ifdef ONLINE_JUDGE
    ifstream ifs("join.in");
    ofstream ofs("join.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
#else
    solve(cin, cout);
#endif
    return 0;
}