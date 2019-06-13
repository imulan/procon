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
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    queue<int> p[6];
    int V = 0;
    for(int v:{4,8,15,16,23,42}){
        rep(i,n)if(a[i]==v) p[V].push(i);
        ++V;
    }

    int ans = n;
    int idx[6]={};
    while(1){
        int now = -1;
        bool ok = true;
        rep(i,6){
            while(!p[i].empty() && p[i].front()<=now) p[i].pop();
            if(p[i].empty()){
                ok = false;
                break;
            }
            now = p[i].front();
            p[i].pop();
        }
        if(ok) ans -= 6;
        else break;
    }

    printf("%d\n", ans);
    return 0;
}
