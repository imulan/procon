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

const int N = 1000010;
char s[N],buf[N];
int ans[N];

int pos = 0;

int ld[N],rd[N];
int lidx = 0, ridx = 0;

stack<int> l_br,r_br;
stack<int> l_dep,r_dep;
int lc=0, rc=0;

bool isbr(char c){
    return c=='(' || c==')';
}

int main(){
    int S;
    scanf(" %d", &S);
    scanf(" %s", s);

    rep(i,N) buf[i] = ' ';

    rep(i,S){
        if(s[i]=='L'){
            if(pos != 0){
                char b = buf[pos];
                if(isbr(b)){
                    assert(l_br.top() == pos);
                    l_br.pop();
                    r_br.push(pos);

                    if(b=='('){
                        int idx = max(0,rc);
                        r_dep.push(idx);
                        ++rd[idx];
                        ridx = max(ridx,idx);

                        --lc;
                        --rc;
                    }
                    else{
                        ++lc;
                        ++rc;

                        int d = max(0,l_dep.top());
                        l_dep.pop();
                        --ld[d];
                    }
                }

                --pos;
            }
        }
        else if(s[i]=='R'){
            ++pos;
            char b = buf[pos];
            if(isbr(b)){
                assert(r_br.top() == pos);
                r_br.pop();
                l_br.push(pos);

                if(b=='('){
                    ++lc;
                    ++rc;

                    int d = max(0,r_dep.top());
                    r_dep.pop();
                    --rd[d];
                }
                else{
                    int idx = max(lc,0);
                    l_dep.push(idx);
                    ++ld[idx];
                    lidx = max(lidx,idx);

                    --lc;
                    --rc;
                }
            }
        }
        else{
            char c = s[i];
            if(buf[pos] == '('){
                --lc;
                l_br.pop();
            }
            else if(buf[pos] == ')'){
                ++lc;
                l_br.pop();

                int d = max(0,l_dep.top());
                l_dep.pop();
                --ld[d];
            }

            buf[pos] = c;

            if(buf[pos] == '('){
                ++lc;
                l_br.push(pos);
            }
            else if(buf[pos] == ')'){
                int idx = max(lc,0);
                l_dep.push(idx);
                ++ld[idx];
                lidx = max(lidx,idx);

                --lc;
                l_br.push(pos);
            }
        }

        // move lidx, ridx
        while(lidx>0 && ld[lidx]==0) --lidx;
        while(ridx>0 && rd[ridx]==0) --ridx;

        if(ld[0]!=0 || rd[0]!=0 || lc != rc) ans[i] = -1;
        else ans[i] = max({lidx, ridx, lc});

        // printf("%2d , pos %d lidx %d ridx %d : ",i,pos,lidx,ridx);
        // rep(j,10) printf("%c",buf[j]);
        // printf(" lc %d rc %d ",lc,rc);

        // printf(" ld");
        // rep(j,5) printf(" %d", ld[j]);
        // printf(" rd");
        // rep(j,5) printf(" %d", rd[j]);

        // printf(" :: %d\n", ans[i]);
    }

    rep(i,S) printf("%d%c", ans[i], " \n"[i==S-1]);
    return 0;
}
