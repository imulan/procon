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
const int INF = 19191919;

int dist(pi p, pi q){
    return abs(p.fi-q.fi) + abs(p.se-q.se);
}

int main(){
    int n;
    string s;
    cin >>n >>s;

    map<pi,int> ct;
    rep(i,n-1){
        int a = s[i]-'0', b = s[i+1]-'0';
        ++ct[{a,b}];
    }

    int ans = INF;
    vector<int> v(9);

    vector<int> p(9);
    rep(i,9) p[i] = i+1;
    do{
        vector<pi> pos(10);
        rep(i,9) pos[p[i]] = {i/3,i%3};

        int t = 0;
        for(const auto &pp:ct){
            int num = pp.se;
            int a = pp.fi.fi, b = pp.fi.se;
            t += num * dist(pos[a],pos[b]);
        }

        if(t < ans){
            ans = t;
            v = p;
        }
    }while(next_permutation(all(p)));

    rep(i,3){
        rep(j,3) cout << v[3*i+j];
        cout << "\n";
    }
    return 0;
}
