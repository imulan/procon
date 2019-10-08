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
    string s,t;
    cin >>n >>s >>t;

    string x = "abc";

    do{
        string tmp = x+x;
        set<string> a;
        rep(i,5) a.insert(tmp.substr(i,2));

        if(a.count(s) || a.count(t)) continue;

        cout << "YES\n";
        rep(i,n) cout << x;
        cout << "\n";
        return 0;
    }while(next_permutation(all(x)));

    do{
        set<string> a;
        rep(i,2) a.insert(x.substr(i,2));

        if(a.count(s) || a.count(t)) continue;

        cout << "YES\n";
        rep(i,3)rep(j,n) cout << x[i];
        cout << "\n";
        return 0;
    }while(next_permutation(all(x)));

    cout << "NO\n";
    return 0;
}
