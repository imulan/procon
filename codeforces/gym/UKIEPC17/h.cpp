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

const vector<int> NG(1,-1);

vector<int> solve(){
    int b,p;
    scanf(" %d %d", &b, &p);

    vector<int> d(p);
    rep(i,p) scanf(" %d", &d[i]);

    int k;
    scanf(" %d", &k);

    vector<int> a(k),v(k);
    rep(i,k){
        scanf(" %d %d", &a[i], &v[i]);
        --v[i];
    }

    vector<int> sd(d);
    sort(all(sd));
    assert(d == sd);

    vector<int> ret;
    while(1){
        bool upd = false;
        for(int i=k-1; i>=0; --i){
            if(v[i]==p-1) continue;
            while(v[i]<p-1){
                bool forward = true;
                for(int j:{-1,1}){
                    int nx = i+j;
                    if(0<=nx && nx<k && v[nx]<p-1){
                        int dist = abs(d[v[i]+1]-d[v[nx]]);
                        if(!(dist<=b && dist>=max(a[i],a[nx]))){
                            forward = false;
                            break;
                        }
                    }
                }

                if(forward){
                    // printf(" GO %d\n",i);
                    upd = true;
                    ret.pb(i);
                    ++v[i];
                }
                else break;
            }
        }

        if(!upd) break;
    }

    rep(i,k)if(v[i]!=p-1) return NG;
    return ret;
}

int main(){
    vector<int> v = solve();
    int n = v.size();
    if(v[0]==-1) printf("impossible\n");
    else rep(i,n) printf("%d%c", v[i]+1, " \n"[i==n-1]);
    return 0;
}
