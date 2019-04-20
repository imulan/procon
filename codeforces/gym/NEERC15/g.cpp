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

vector<int> make_sequence(int x0, int a, int b, int c){
    bool used[1010]={};

    int x = x0;
    vector<int> ret;
    while(!used[x]){
        used[x] = true;
        ret.pb(x);

        x = (a*x+b)%c;
    }
    return ret;
}

void solve(istream &fin, ostream &fout){
    int n,k;
    fin >>n >>k;

    vector<int> x0(n), a(n), b(n), c(n);
    rep(i,n){
        fin >>x0[i] >>a[i] >>b[i] >>c[i];
    }

    vector<int> mx(n);
    vector<int> m_idx(n);
    rep(i,n){
        vector<int> v = make_sequence(x0[i], a[i], b[i], c[i]);
        int sz = v.size();
        rep(j,sz){
            if(mx[i] < v[j]){
                mx[i] = v[j];
                m_idx[i] = j;
            }
        }
    }

    int mx_sum = 0;
    rep(i,n) mx_sum += mx[i];

    if(mx_sum%k != 0){
        fout << mx_sum << "\n";
        rep(i,n) fout << m_idx[i] << " \n"[i==n-1];
        return;
    }

    int ans = -1;
    int ch_seq = -1;
    int ch_idx = -1;
    rep(i,n){
        vector<int> v = make_sequence(x0[i], a[i], b[i], c[i]);
        int sz = v.size();

        rep(j,sz){
            int tmp = mx_sum - mx[i] + v[j];
            if(tmp%k != 0 && ans < tmp){
                ans = tmp;
                ch_seq = i;
                ch_idx = j;
            }
        }
    }

    fout << ans << "\n";
    if(ans == -1) return;

    assert(ch_seq != -1);
    m_idx[ch_seq] = ch_idx;
    rep(i,n) fout << m_idx[i] << " \n"[i==n-1];
}

int main(){

    #ifdef ONLINE_JUDGE
    ifstream ifs("generators.in");
    ofstream ofs("generators.out");
    solve(ifs, ofs);
    ifs.close();
    ofs.close();
    #else
    solve(cin, cout);
    #endif

    return 0;
}
