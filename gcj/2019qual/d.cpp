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

int n,b,f;

string ask(string s){
    cout << s << endl;
    string res;
    cin >>res;
    return res;
}

int ans(vector<int> v){
    assert(v.size() == b);
    sort(all(v));

    rep(i,b) cout << v[i] << " \n"[i==b-1];
    cout << flush;

    int res;
    cin >>res;
    return res;
}

vector<int> ct_rems(string s){
    int S = s.size();
    int sidx = 0;
    int c = 1;
    vector<int> ret;
    while(sidx<S){
        int nx = sidx;
        while(nx<S && s[nx]=='0'+c) ++nx;
        ret.pb(nx-sidx);
        sidx = nx;
        c = !c;
    }
    return ret;
}

const int N = 1024;

int x[5]={16,8,4,2,1};
void solve(){
    cin >>n >>b >>f;

    int sz;
    vector<int> lost;
    rep(qq,5){
        string q(N,' ');

        int c = 0;
        rep(i,N){
            if(i%x[qq] == 0) c = !c;
            q[i] = c+'0';
        }

        string r = ask(q.substr(0,n)) + q.substr(n);

        if(qq == 0){
            vector<int> qv = ct_rems(q), rv = ct_rems(r);
            assert(qv.size() == rv.size());

            sz = qv.size();
            lost = vector<int>(sz);
            rep(i,sz) lost[i] = qv[i]-rv[i];
        }
        else{
            int ridx = 0;

            vector<int> nl;
            rep(i,sz){
                string t = r.substr(ridx, 2*x[qq]-lost[i]);
                // dbg(r);
                // dbg(t);
                int ct[2]={};
                for(char cc:t) ++ct[cc-'0'];

                int l_sum = 0;
                for(int j:{1,0}){
                    l_sum += x[qq]-ct[j];
                    nl.pb(x[qq]-ct[j]);
                }
                assert(l_sum == lost[i]);

                ridx += 2*x[qq]-lost[i];
            }

            lost = nl;
            sz = lost.size();
        }
        // dbg(lost);
    }

    assert(sz == N);
    vector<int> v;
    rep(i,n)if(lost[i]) v.pb(i);
    assert(ans(v) == 1);
}

int main(){
    int T;
    cin >>T;
    rep(i,T) solve();
    return 0;
}
