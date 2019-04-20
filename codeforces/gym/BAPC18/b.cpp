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

int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int f(int m, int d){
    int ret = 0;
    rep(i,m) ret += M[i];
    ret += d-1;
    return ret;
}

int cv(string s){
    int m = stoi(s.substr(0,2));
    int d = stoi(s.substr(3));
    return f(m,d);
}

int DIST(int v){
    int base = f(10,28);
    if(v < base) return v+365 - base;
    return v - base;
}

int main(){
    int n;
    cin >>n;

    vector<int> x(n);
    rep(i,n){
        string s,d;
        cin >>s >>d;
        x[i] = cv(d);
    }
    sort(all(x));
    // dbg(x);

    int dist = 0;
    int ans = 0;
    rep(i,365){
        auto itr = upper_bound(all(x),i);

        int d;
        if(itr == x.begin()){
            d = 365+i - x.back();
        }
        else{
            --itr;
            d = i - (*itr);
        }
        // dbg(d);

        if(d > dist || (d==dist && DIST(i)<DIST(ans))){
            dist = d;
            ans = i;
        }
    }

    int am = 1, ad = 0;
    while(1){
        if(ans - M[am] < 0){
            ad = ans+1;
            break;
        }

        ans -= M[am];
        ++am;
    }
    printf("%02d-%02d\n", am, ad);
    return 0;
}
