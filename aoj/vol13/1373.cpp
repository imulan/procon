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

const int INF = 1000000010;

int main(){
    int n;
    scanf(" %d", &n);

    set<pi> s;
    s.insert({0,0});
    rep(i,n){
        int x;
        scanf(" %d", &x);

        // printf(" ---- %d\n", i);
        // for(const auto p:s) dbg(p);

        auto itr = s.lower_bound({x,INF});
        if(itr == s.begin()){
            printf("No\n");
        }
        else{
            printf("Yes\n");

            --itr;
            pi range = *itr;
            s.erase(itr);

            int l,r;
            if(range.fi<=x && x<=range.se){
                l = range.fi;
                r = x-1;
                if(l<=r) s.insert({l,r});

                l = x+1;
                r = range.se;
                if(l<=r) s.insert({l,r});
            }
            else{
                assert(range.se<x);

                l = range.fi;
                r = range.se-1;
                if(l<=r) s.insert({l,r});

                l = range.se+1;
                r = x;
                if(l<=r) s.insert({l,r});
            }
        }
    }
    return 0;
}
