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

int ask(int idx){
    cout << idx+1 << endl;
    int ret;
    cin >>ret;
    return ret;
}

void ans(const vector<int> &v){
    for(int i:v) cout << i;
    cout << endl;

    char c;
    cin >>c;
    assert(c == 'Y');
}

vector<int> FLIP(const vector<int> &v){
    int n = v.size();
    vector<int> ret(n);
    rep(i,n) ret[i] = !v[i];
    return ret;
}

vector<int> REV(const vector<int> &v){
    vector<int> ret(v);
    reverse(all(ret));
    return ret;
}

void f10(){
    vector<int> x(10);
    rep(i,10) x[i] = ask(i);
    ans(x);
}

void f(int B){
    vector<int> x(B);

    int same = -1, diff = -1;
    for(int i=0; i<B/2; i+=4){
        // check (need to ask twice)
        if(same==-1 && diff==-1){
            // skip
            rep(j,2) ask(0);
        }
        else if(same==-1 || diff==-1){
            ask(0);

            int idx = max(same,diff);
            int res = ask(idx);
            if(x[idx] != res) x = FLIP(x);
        }
        else{
            int ss = ask(same), dd = ask(diff);
            if(x[same] != ss) x = FLIP(x);
            if(x[diff] != dd) x = REV(x);
        }

        if(B/2-i<4){
            for(int j=i; j<i+4; ++j) x[j] = ask(j);
            break;
        }
        else{
            for(int j=i; j<i+4; ++j){
                int rj = B-1-j;
                x[j] = ask(j);
                x[rj] = ask(rj);

                if(same==-1 && x[j]==x[rj]) same = j;
                if(diff==-1 && x[j]!=x[rj]) diff = j;
            }
        }
    }
    ans(x);
}

void solve(int B){
    if(B == 10) f10();
    else f(B);
}

int main(){
    int T,B;
    cin >>T >>B;
    rep(i,T) solve(B);
    return 0;
}
