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

vector<int> p[4];

const int N = 400004;
int df[N];

int main(){
    int n;
    cin >>n;

    rep(i,n){
        string s;
        int a;
        cin >>s >>a;

        int idx = 0;
        rep(j,2)if(s[j]=='1') idx += (1<<j);
        p[idx].pb(a);
    }

    rep(i,4) sort(all(p[i]), greater<int>());

    int sd = 0;
    for(int i:p[3]) sd += i;

    int B = p[1].size(), C = p[2].size();
    vector<int> sb(B+1), sc(C+1);

    rep(i,B) sb[i+1] = sb[i]+p[1][i];
    rep(i,C) sc[i+1] = sc[i]+p[2][i];

    memset(df, -1, sizeof(df));
    rep(i,N){
        // Bをmax選ぶ
        for(int j:{-i,i}){
            int nc = B+j;
            if(0<=nc && nc<=C) df[i] = max(df[i], sb[B]+sc[nc]);
        }

        // Cをmax選ぶ
        for(int j:{-i,i}){
            int nb = C+j;
            if(0<=nb && nb<=B) df[i] = max(df[i], sb[nb]+sc[C]);
        }
    }
    rep(i,N-1) df[i+1] = max(df[i+1], df[i]);

    int A = p[0].size();
    int D = p[3].size();

    int sa = 0;
    int ans = sd;
    rep(i,A+1){
        int rr = i - D;
        if(rr>0) continue;

        int tmp = sd + sa + df[-rr];
        ans = max(ans, tmp);
        if(i<A) sa += p[0][i];
    }

    cout << ans << endl;
    return 0;
}
