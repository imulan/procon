#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    cin >>n;

    vector<vector<int>> ans;
    rep(a,2){
        map<int,vector<int>> X;
        int W = 0, s = 0;
        if(a==0){
            X[0].pb(0);
            ++W;
            s = 1;
        }
        for(int i=s; i<n; i+=2){
            X[W].pb(i);
            if(i+1<n) X[W].pb(i+1);
            ++W;
        }

        map<int,int> Y;
        int H = 0;
        for(int i=a; i<n; i+=2){
            Y[H] = i;
            ++H;
        }

        rep(b,12){
            rep(i,2){
                vector<int> row,col;
                rep(y,H)if( (y>>b&1) == i ){
                    row.pb(Y[y]);
                }
                rep(x,W)if( (x>>b&1) == !i){
                    for(int xx:X[x]) col.pb(xx);
                }

                if(!row.empty() && !col.empty()){
                    ans.pb(row);
                    ans.pb(col);
                }
            }
        }
    }

    cout << ans.size()/2 << "\n";
    for(const auto &v:ans){
        cout << v.size();
        for(int i:v) cout << " " << i+1;
        cout << "\n";
    }
    return 0;
}
