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

bool solve(){
    int n;
    cin >>n;

    multiset<int> rem;
    rep(i,1<<n){
        int x;
        cin >>x;
        rem.insert(x);
    }

    vector<int> v;
    int root = *rem.rbegin();
    v.pb(root);
    rem.erase(rem.find(root));

    rep(i,n){
        vector<int> add;
        for(int j:v){
            auto itr = rem.lower_bound(j);
            if(itr == rem.begin()) return false;

            --itr;
            add.pb(*itr);
            rem.erase(itr);
        }

        for(int j:add) v.pb(j);
    }

    return true;
}

int main(){
    cout << (solve()?"Yes":"No") << "\n";
    return 0;
}
