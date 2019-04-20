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

const int N = 200002;
int ct[N];

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        ++ct[a[i]];
    }

    int mx = 0;
    int val = 0;
    rep(i,N){
        if(mx < ct[i]){
            mx = ct[i];
            val = i;
        }
    }

    queue<int> que;
    vector<bool> done(n);
    rep(i,n){
        if(a[i] == val){
            que.push(i);
            done[i] = true;
        }
    }

    printf("%d\n", n-mx);
    while(!que.empty()){
        int i = que.front();
        que.pop();
        for(int x:{-1,1}){
            int j=i+x;
            if(j<0 || n<=j) continue;

            if(!done[j]){
                int t=1;
                if(a[j] > a[i]) t=2;
                printf("%d %d %d\n", t, j+1, i+1);

                a[j] = val;
                que.push(j);
                done[j] = true;
            }
        }
    }
    return 0;
}
