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

const int N = 12*60*60;
int t[60][60][60];

void print_clock(int x){
    int s = x%60;
    x/=60;
    int m = x%60;
    x/=60;
    int h = x;
    printf("%02d:%02d:%02d",h,m,s);
}

void init(){
    memset(t,-1,sizeof(t));
    // for all of the time, calculate triplet of hand's directions
    int h=0, m=0, s=0;
    rep(i,N){
        t[h][m][s] = i;

        ++s;
        if(s == 60){
            s = 0;
            ++m;

            if(m%12 == 0){
                ++h;
                if(m == 60) m = 0;
            }
        }
    }
}

int main(){
    init();

    int n;
    while(cin >>n,n){
        vector<vector<int>> c(n);
        rep(i,n){
            c[i].resize(3);
            rep(j,3) cin >>c[i][j];
            sort(all(c[i]));
        }

        // interval length, start time
        int L = N;
        int S = 0;

        rep(i,n){
            do{
                rep(j,60){
                    int h = (c[i][0]+j)%60;
                    int m = (c[i][1]+j)%60;
                    int s = (c[i][2]+j)%60;
                    if(t[h][m][s]==-1) continue;

                    // printf(" CHECK: ");
                    // print_clock(t[h][m][s]);
                    // printf(" \n");

                    bool ok = true;
                    int START = t[h][m][s];
                    int END = START;

                    rep(ii,n)if(ii != i){
                        bool found = false;
                        int tt = N;
                        do{
                            rep(jj,60){
                                int hh = (c[ii][0]+jj)%60;
                                int mm = (c[ii][1]+jj)%60;
                                int ss = (c[ii][2]+jj)%60;
                                if(t[hh][mm][ss]==-1) continue;

                                if(t[hh][mm][ss] >= START){
                                    tt = min(tt, t[hh][mm][ss]);
                                    found = true;
                                }
                            }
                        }while(next_permutation(all(c[ii])));

                        if(found) END = max(END,tt);
                        else{
                            ok = false;
                            break;
                        }
                    }

                    if(ok){
                        if(L > END-START){
                            L = END-START;
                            S = START;
                        }
                        else if(L == END-START) S = min(S, START);
                    }
                }
            }while(next_permutation(all(c[i])));
        }

        print_clock(S);
        printf(" ");
        print_clock(S+L);
        printf("\n");
    }
    return 0;
}
