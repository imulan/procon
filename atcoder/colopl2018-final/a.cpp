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

vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str + sep);
    string buffer;
    while( getline(ss,buffer,sep ) ) v.pb(buffer);
    return v;
}

ll f(ll x){
    return x*(x+1)/2;
}

ll solve(){
    int n;
    string s;
    cin >>n >>s;
    int S = s.size();

    bool all_a = true;
    rep(i,S) all_a &= (s[i]=='A');

    if(all_a) return f((ll)n*S);

    vector<ll> a;
    for(string t:split(s,'B')){
        if(t.size()>0) a.pb(t.size());
    }

    ll ret = 0;
    if(s[0]=='A' && s[S-1]=='A'){
        int A = a.size();
        for(int i=1; i<A-1; ++i) ret += f(a[i])*n;
        ret += f(a[0]);
        ret += f(a[A-1]);
        ret += f(a[0]+a[A-1])*(n-1);
    }
    else{
        for(ll x:a) ret += f(x)*n;
    }

    return ret;
}

int main(){
    cout << solve() << endl;
    return 0;
}
