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

const int A = 26+1;
int f(char c){
    if(c == '?') return A-1;
    return c-'a';
}

queue<int> L[A],R[A];
queue<int> remL,remR;

int main(){
    int n;
    string l,r;
    cin >>n >>l >>r;

    rep(i,n){
        L[f(l[i])].push(i);
        R[f(r[i])].push(i);
    }

    vector<pi> ans;
    // 'A'~'Z' pair
    rep(i,A-1){
        while(!L[i].empty() && !R[i].empty()){
            ans.pb({L[i].front(), R[i].front()});
            L[i].pop();
            R[i].pop();
        }

        while(!L[i].empty()){
            remL.push(L[i].front());
            L[i].pop();
        }
        while(!R[i].empty()){
            remR.push(R[i].front());
            R[i].pop();
        }
    }

    // '?' & ALP
    while(!L[A-1].empty() && !remR.empty()){
        ans.pb({L[A-1].front(), remR.front()});
        L[A-1].pop();
        remR.pop();
    }

    // 'ALP & '?'
    while(!R[A-1].empty() && !remL.empty()){
        ans.pb({remL.front(), R[A-1].front()});
        R[A-1].pop();
        remL.pop();
    }

    // '? & '?'
    while(!L[A-1].empty() && !R[A-1].empty()){
        ans.pb({L[A-1].front(), R[A-1].front()});
        L[A-1].pop();
        R[A-1].pop();
    }

    cout << ans.size() << '\n';
    for(pi p:ans) cout << p.fi+1 << " " << p.se+1 << '\n';
    return 0;
}
