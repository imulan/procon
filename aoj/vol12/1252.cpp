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
using ps = pair<string,string>;

int main(){
    int n;
    while(cin >>n,n){
        int d;
        cin >>d;
        vector<string> name(n);
        rep(i,n) cin >>name[i];
        sort(all(name));

        vector<set<string>> v(n);
        rep(i,n){
            string s = name[i];
            int S = s.size();
            string t;

            // delete
            rep(j,S){
                t = s;
                t.erase(t.begin()+j);
                v[i].insert(t);
            }

            // insert
            rep(j,S+1){
                rep(k,26){
                    char c = 'a'+k;
                    t = s;
                    t.insert(j,string(1,c));
                    v[i].insert(t);
                }
            }

            // replace
            rep(j,S){
                rep(k,26){
                    char c = 'a'+k;
                    t = s;
                    if(t[j] != c){
                        t[j] = c;
                        v[i].insert(t);
                    }
                }
            }

            // swap ADJACENT
            rep(j,S-1){
                t = s;
                if(t[j]!=t[j+1]){
                    swap(t[j],t[j+1]);
                    v[i].insert(t);
                }
            }
        }

        map<string,vector<int>> idx;
        rep(i,n){
            for(string ss:v[i]) idx[ss].pb(i);
        }

        set<pi> ans;
        // d==1
        rep(i,n)for(int j=i+1; j<n; ++j){
            if(v[i].count(name[j])) ans.insert({i,j});
        }
        if(d==2){
            for(const auto p:idx){
                vector<int> tt = p.se;
                int sz = tt.size();

                rep(i,sz)rep(j,i){
                    if(tt[j]!=tt[i]) ans.insert({tt[j],tt[i]});
                }
            }
        }

        // for(pi p:ans) dbg(p);
        for(pi p:ans) cout << name[p.fi] << "," << name[p.se] << "\n";
        cout << ans.size() << "\n";
    }
    return 0;
}
