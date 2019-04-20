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

const int N = 202;
vector<pi> EV[N];

int main(){
    int n;
    cin >>n;

    rep(i,n){
        int l,u;
        cin >>l >>u;
        // in
        EV[l].pb({0,i});
        // out
        EV[u].pb({1,i});
    }

    rep(i,N) sort(all(EV[i]));

    vector<bool> used(n);
    int ans = 0;
    set<int> s;
    rep(i,N){
        for(pi p:EV[i]){
            int ID = p.se;
            if(p.fi==0){
                s.insert(ID);
            }
            else{
                if(!used[ID]){
                    ++ans;
                    for(int j:s) used[j] = true;
                    s.clear();
                }
                else s.erase(ID);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
