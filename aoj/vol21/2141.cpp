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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class Key>
using ordered_set = __gnu_pbds::tree<Key, __gnu_pbds::null_type, less<Key>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

// multisetではないので注意．適当にindex貼ったりする必要がある．あと定数倍重い．
// find_by_order(idx)
// order_of_key(key)  ... lower_bound

int solve(){
    int n;
    string s;
    cin >>n >>s;
    int S = s.size();

    int ans = 0;
    rep(i,S+2){
        int x = n-1;
        int T = S;

        int g = 0, b = 0;
        rep(j,S){
            if(s[j]=='G') ++g;
            else ++b;
        }

        ordered_set<int> alive;
        rep(j,S) alive.insert(j);

        int p = 0;
        rep(j,S){
            if(g==0 || b==0) break;

            int death = (p+x+(i==j))%T;

            auto itr = alive.find_by_order(death);
            if(s[*itr]=='G') --g;
            else --b;

            // dbg(*itr);
            alive.erase(alive.find(*itr));

            p = death;
            if(death == T-1) p = 0;
            --T;
        }

        ans = max(ans,b);
    }
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) cout << solve() << "\n";
    return 0;
}
