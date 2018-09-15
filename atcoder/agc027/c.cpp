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

const int N = 200000;
set<int> A[N],B[N];
int ca[N]={}, cb[N]={};

int main(){
    int n,m;
    string s;
    cin >>n >>m >>s;

    rep(i,m){
        int a,b;
        cin >>a >>b;
        --a;
        --b;

        if(s[a] == 'A') A[b].insert(a);
        else B[b].insert(a);

        if(s[b] == 'A') A[a].insert(b);
        else B[a].insert(b);
    }

    vector<bool> alive(n,true);
    queue<int> que;
    rep(i,n){
        ca[i] = A[i].size();
        cb[i] = B[i].size();

        if(ca[i]==0 || cb[i]==0){
            alive[i] = false;
            que.push(i);
        }
    }
    while(!que.empty()){
        int v = que.front();
        que.pop();
        // dbg(v);

        for(int nx:A[v]){
            if(s[v]=='A'){
                --ca[nx];
                if(alive[nx] && ca[nx]==0){
                    alive[nx] = false;
                    que.push(nx);
                }
            }
            else{
                --cb[nx];
                if(alive[nx] && cb[nx]==0){
                    alive[nx] = false;
                    que.push(nx);
                }
            }
        }
        for(int nx:B[v]){
            if(s[v]=='A'){
                --ca[nx];
                if(alive[nx] && ca[nx]==0){
                    alive[nx] = false;
                    que.push(nx);
                }
            }
            else{
                --cb[nx];
                if(alive[nx] && cb[nx]==0){
                    alive[nx] = false;
                    que.push(nx);
                }
            }
        }
    }

    // rep(i,n){
    //     dbg(ca[i]);dbg(cb[i]);
    // }

    string ans = "No";
    rep(i,n)if(alive[i]) ans = "Yes";
    cout << ans << endl;
    return 0;
}
