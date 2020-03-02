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

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<int> c;
    set<int> inside,today;
    int start = 0;
    rep(i,n){
        int x = a[i];
        if(x>0){
            if(inside.count(x) || today.count(x)){
                printf("-1\n");
                return 0;
            }

            inside.insert(x);
            today.insert(x);
        }
        else{
            x = -x;
            if(!inside.count(x)){
                printf("-1\n");
                return 0;
            }
            inside.erase(x);
        }

        if(inside.empty()){
            c.pb(i-start+1);
            today.clear();
            start = i+1;
        }
    }
    if(start != n){
        printf("-1\n");
        return 0;
    }

    int C = c.size();
    printf("%d\n", C);
    rep(i,C) printf("%d%c", c[i], " \n"[i==C-1]);
    return 0;
}
