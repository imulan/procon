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

using vi = vector<int>;
using mat = vector<vi>;
using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;
    vi a(n*n);
    rep(i,n*n) cin >>a[i];

    map<int,int> ct;
    for(int i:a) ++ct[i];

    priority_queue<pi> pq;
    for(const auto &p:ct) pq.push({p.se, p.fi});

    mat m(n,vi(n));

    // 4 elements
    rep(i,n/2)rep(j,n/2){
        pi now = pq.top();
        pq.pop();

        if(now.fi>=4){
            m[i][j] = m[n-1-i][j] = m[i][n-1-j] = m[n-1-i][n-1-j] = now.se;
            now.fi -= 4;
            if(now.fi>0) pq.push(now);
        }
        else{
            cout << "NO" << "\n";
            return 0;
        }
    }

    if(n%2==1){
        int c = n/2;

        // 2 elements
        rep(i,n/2){
            pi now = pq.top();
            pq.pop();
            if(now.fi>=2){
                m[i][c] = m[n-1-i][c] = now.se;
                now.fi -= 2;
                if(now.fi>0) pq.push(now);
            }
            else{
                cout << "NO" << "\n";
                return 0;
            }
        }
        rep(i,n/2){
            pi now = pq.top();
            pq.pop();
            if(now.fi>=2){
                m[c][i] = m[c][n-1-i] = now.se;
                now.fi -= 2;
                if(now.fi>0) pq.push(now);
            }
            else{
                cout << "NO" << "\n";
                return 0;
            }
        }

        // 1 element
        pi now = pq.top();
        pq.pop();
        if(now.fi>=1) m[c][c] = now.se;
        else{
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    rep(i,n){
        rep(j,n) cout << m[i][j] << " \n"[j==n-1];
    }
    return 0;
}
