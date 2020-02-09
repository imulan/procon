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

const int N = 300;

int query(const string &t){
    cout << t << endl;
    int x;
    cin >>x;
    assert(x!=-1);
    return x;
}

int main(){
    int x = query(string(N,'a'));
    if(x == 0) return 0;
    int y = query(string(N,'b'));
    if(y == 0) return 0;

    int A = N-x, B = N-y;
    int n = A+B;

    string s(n,'a');
    vector<bool> isB(n);
    int cb = 0;
    rep(i,n-1){
        s[i] = 'b';

        int res = query(s);
        if(res == 0) return 0;

        if(res < B){
            isB[i] = true;
            ++cb;
        }
        s[i] = 'a';
    }

    if(cb<B) isB[n-1] = true;
    rep(i,n)if(isB[i]) s[i] = 'b';

    int check = query(s);
    assert(check == 0);

    return 0;
}
