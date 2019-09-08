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

    multiset<int> s;
    rep(i,n){
        int d;
        scanf(" %d", &d);
        s.insert(d);
    }

    int x = *s.rbegin();
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            s.erase(s.find(i));
            if(i!=x/i) s.erase(s.find(x/i));
        }
    }

    int y = *s.rbegin();

    printf("%d %d\n", x, y);
    return 0;
}
