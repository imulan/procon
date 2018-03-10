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

const int N = 100010;
int x[N]={}, y[N]={};
int xa[N]={}, ya[N]={};

int main(){
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    rep(i,S){
        if(s[i]=='B' || s[i]=='C'){
            ++x[i+1];
            xa[i+1] = 0;
        }
        else{
            xa[i+1] = xa[i]+1;
        }
    }
    rep(i,T){
        if(t[i]=='B' || t[i]=='C'){
            ++y[i+1];
            ya[i+1] = 0;
        }
        else{
            ya[i+1] = ya[i]+1;
        }
    }

    rep(i,N-1){
        x[i+1] += x[i];
        y[i+1] += y[i];
    }

    int Q;
    cin >>Q;
    rep(i,Q){
        int a,b,c,d;
        scanf(" %d %d %d %d", &a, &b, &c, &d);

        int ss = x[b]-x[a-1];
        int tt = y[d]-y[c-1];

        int ans = 0;
        if(ss<=tt){
            if(ss==0){
                if(tt==0){
                    if((b-a)>=(d-c) && (b-a)%3 == (d-c)%3) ans = 1;
                }
                else{
                    if((b-a+1)>ya[d] && tt%2==0) ans = 1;
                }
            }
            else{
                if(xa[b]%3 == ya[d]%3){
                    if(xa[b]>=ya[d] && (tt-ss)%2==0) ans = 1;
                }
                else{
                    if(xa[b]>ya[d] && ss<tt && (tt-ss)%2==0) ans = 1;
                }

            }
        }
        printf("%d",ans);
    }
    printf("\n");
    return 0;
}
