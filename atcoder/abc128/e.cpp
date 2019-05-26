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

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    set<int> u;
    map<int,vector<int>> IN,OUT;
    rep(i,n){
        int s,t,x;
        scanf(" %d %d %d", &s, &t, &x);
        IN[s-x].pb(x);
        OUT[t-x].pb(x);

        // printf(" [%d %d)\n", s-x,t-x);
        u.insert(s-x);
        u.insert(t-x);
    }

    set<int> ASK;
    rep(i,q){
        int d;
        scanf(" %d", &d);
        ASK.insert(d);
        u.insert(d);
    }

    set<int> X;
    for(int i:u){
        for(int j:OUT[i]) X.erase(j);
        for(int j:IN[i]) X.insert(j);

        if(ASK.count(i)){
            int ans = -1;
            if(!X.empty()) ans = *X.begin();
            printf("%d\n", ans);
        }
    }
    return 0;
}
