#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

using pi = pair<int,int>;

int n;
int qct = 0;

pi query(int a, int b){
    ++qct;
    if(qct > 4*n) while(1){}

    printf("? %d %d\n", a+1, b+1);
    fflush(stdout);

    char x,y;
    scanf(" %c %c", &x, &y);

    int xx = -1, yy = -1;
    if(x=='+') xx = 1;
    if(y=='+') yy = 1;
    return {xx, yy};
}

void ans(vector<int> v){
    sort(all(v));
    int V = v.size();

    printf("! %d", V);
    rep(i,V) printf(" %d", v[i]+1);
    printf("\n");
    fflush(stdout);
}

int main(){
    scanf(" %d", &n);

    if(n<=2){
        vector<int> ret;
        rep(i,n) ret.pb(i);
        ans(ret);
        return 0;
    }

    vector<int> v(n);
    rep(i,n) v[i]=i;

    const int SEED = 191919;
    mt19937 eng(SEED);
    shuffle(all(v), eng);

    int LOOP = 12;
    if(n==3){
        LOOP = 10;
    }

//    int ch = 0;
//    for(int i=0; i<n/2; i+=2) {
//        ch += 2;
//    }
//    printf("%d\n",ch);

    bool found = false;
    vector<bool> ok(n);
    vector<int> cand;
    for(int i=0; i<n/2; i+=2){
        int a = v[i], b = v[i+1];
        int ca = 0, cb = 0;
        rep(j,LOOP){
            pi r = query(a,b);
            ca += r.fi;
            cb += r.se;
        }

        if(abs(ca) == LOOP){
            cand.pb(a);
//            found = true;
//            ok[a] = true;
//            if(ca == LOOP) ok[b] = true;
//            else ok[b] = false;
//
//            rep(j,n){
//                if(a==j || b==j) continue;
//                pi r = query(a,j);
//
//                if(r.fi==1) ok[j] = true;
//                else ok[j] = false;
//            }
//            break;
        }
        if(abs(cb) == LOOP){
            cand.pb(b);
//            found = true;
//            ok[b] = true;
//            if(cb == LOOP) ok[a] = true;
//            else ok[a] = false;
//
//            rep(j,n){
//                if(a==j || b==j) continue;
//                pi r = query(b,j);
//
//                if(r.fi==1) ok[j] = true;
//                else ok[j] = false;
//            }
//            break;
        }
    }

    shuffle(all(cand), eng);
    int c = v[n/2];
    if(!cand.empty()) c = cand.front();
    ok[c] = true;
    rep(i,n)if(c!=i){
        pi r = query(c,i);
        if(r.fi==1) ok[i] = true;
        else ok[i] = false;
    }

    vector<int> ret;
    rep(i,n)if(ok[i]) ret.pb(i);
    ans(ret);
    return 0;
}