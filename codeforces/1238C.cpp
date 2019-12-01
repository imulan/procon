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

int solve(){
    int h,n;
    scanf(" %d %d", &h, &n);

    set<int> s;
    rep(i,n){
        int p;
        scanf(" %d", &p);
        s.insert(p);
    }
    s.insert(0);

    int ans = 0;
    while(h>2){
        if(s.count(h-1)){
            if(s.count(h-2)){
                h -= 2;
            }
            else{
                s.erase(h-1);
                ++ans;
            }
        }
        else{
            auto itr = s.lower_bound(h);
            --itr;
            h = *itr+1;
        }
    }
    return ans;
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) printf("%d\n", solve());
    return 0;
}
