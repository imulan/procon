#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

using pi = pair<int,int>;
using P = pair<pi,int>;

int query(int l, int r){
    printf("? %d %d\n",l+1,r+1);
    fflush(stdout);
    char c;
    scanf(" %c", &c);
    return c=='>';
}

void answer(int idx){
    printf("! %d\n", idx+1);
    fflush(stdout);
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> r(n);
    rep(i,n) r[i] = i;

    vector<P> res;
    while(1){
        int R = r.size();
        if(R==1) break;

        vector<int> nr;
        for(int i=0; i+1<R; i+=2){
            int a = r[i], b = r[i+1];
            int w = query(a,b);
            res.pb({{a,b},w});

            if(w==1) nr.pb(a);
            else nr.pb(b);
        }

        if(R%2==1) nr.pb(r.back());
        r = nr;
    }
    int win = r[0];

    vector<int> loser;
    for(const auto &p:res){
        int a = p.fi.fi, b = p.fi.se;

        if(b==win) swap(a,b);
        if(a==win) loser.pb(b);
    }

    int L = loser.size();
    int  ans = loser[0];
    for(int i=1; i<L; ++i){
        int w = query(loser[i], ans);
        if(w==1) ans = loser[i];
    }
    answer(ans);
    return 0;
}