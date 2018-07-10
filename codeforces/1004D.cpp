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

vector<int> divisor(int x){
    vector<int> ret;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0) ret.pb(i);
    }
    return ret;
}

void solve(){
    int t;
    scanf(" %d", &t);

    vector<int> ct(t);
    int max_a = 0;
    rep(i,t){
        int a;
        scanf(" %d", &a);

        ++ct[a];
        max_a = max(max_a, a);
    }

    int dist=1;
    for(int i=1; i<t; ++i){
        if(ct[i]<4*i){
            dist = i;
            break;
        }
    }

    vector<int> ncand = divisor(t);
    for(int n:ncand){
        int m = t/n;

        for(int x=1; x<=(n+1)/2; ++x){
            int y = n-x+m-max_a;
            if(!(1<=y && y<=(m+1)/2)) continue;

            if(min(x,y)!=dist) continue;

            vector<int> tct(t+1);
            for(int i=1; i<=n; ++i){
                int b = abs(i-x);
                ++tct[b];
                --tct[b+y-1+1];

                ++tct[b+1];
                --tct[b+m-y+1];
            }
            rep(i,t) tct[i+1] += tct[i];

            // printf(" CHECK: %d %d %d %d\n",n,m,x,y);
            // dbg(tct);

            bool ok = true;
            rep(i,t)if(tct[i]!=ct[i]) ok = false;
            if(ok){
                printf("%d %d\n%d %d\n",n,m,x,y);
                return;
            }
        }
    }

    printf("-1\n");
}

int main(){
    solve();
    return 0;
}
