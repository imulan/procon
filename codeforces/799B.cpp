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

const int INF = 1000000001;

priority_queue<int,vector<int>,greater<int>> s[4][4];

int main(){
    int n;
    cin >>n;
    vector<int> p(n),a(n),b(n);
    rep(i,n) cin >>p[i];
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    rep(i,n) s[a[i]][b[i]].push(p[i]);

    int m;
    cin >>m;

    vector<int> bb(m);
    rep(qqq,m){
        int c;
        cin >>c;

        int ans = INF;
        int A,B;
        rep(i,3){
            if(!s[c][i+1].empty()){
                int tmp = s[c][i+1].top();
                if(tmp < ans){
                    ans = tmp;
                    A = c;
                    B = i+1;
                }
            }
            if(!s[i+1][c].empty()){
                int tmp = s[i+1][c].top();
                if(tmp < ans){
                    ans = tmp;
                    A = i+1;
                    B = c;
                }
            }
        }

        if(ans==INF) ans = -1;
        else s[A][B].pop();
        bb[qqq] = ans;
    }

    rep(i,m) cout << bb[i] << " \n"[i==m-1];
    return 0;
}
