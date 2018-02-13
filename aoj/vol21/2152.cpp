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
using P = pair<pi,int>;

const int INF = 1000000001;

int main(){
    int n;
    while(cin >>n,n){
        map<int,vector<int>> m;

        // empty, filled
        set<pi> e;
        set<P> f;
        e.insert({0,INF});

        rep(i,n){
            char c;
            int x;
            cin >>c >>x;

            if(c == 'D'){
                for(int j:m[x]){
                    auto itr = f.lower_bound({{j,j},-1});
                    pi range = itr->fi;
                    e.insert(range);
                    f.erase(itr);
                }
                m[x].clear();
            }
            else if(c == 'R'){
                if(f.empty()) cout << -1 << endl;
                else{
                    auto itr = f.upper_bound({{x,INF},INF});
                    --itr;
                    pi range = itr->fi;

                    if(range.fi<=x && x<range.se) cout << itr->se << endl;
                    else cout << -1 << endl;
                }
            }
            else if(c == 'W'){
                int y;
                cin >>y;
                while(y){
                    auto itr = e.begin();
                    int l = itr->fi, r = itr->se;
                    int SZ = r-l;
                    e.erase(itr);
                    if(SZ<y){
                        m[x].pb(l);
                        f.insert({{l,r},x});
                        y -= SZ;
                    }
                    else{
                        m[x].pb(l);
                        f.insert({{l,l+y},x});
                        e.insert({l+y,r});
                        y = 0;
                   }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
