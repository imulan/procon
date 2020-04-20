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

const string NG = "IMPOSSIBLE";

const int D = 4;
ll X,Y;

int md;
string ans;
void dfs(int f, int x, int y, string s){
    if(x==X && y==Y){
        if(f<md){
            md = f;
            ans = s;
        }
    }
    if(f==D){
        return;
    }
    if(x>=0 && y>=0  && x<=y)printf(" (%d %d) : %d\n",x,y,x+y);


    dfs(f+1, x+(1<<f), y, s+'E');
    dfs(f+1, x-(1<<f), y, s+'W');
    dfs(f+1, x, y+(1<<f), s+'N');
    dfs(f+1, x, y-(1<<f), s+'S');
}

string solve(){
    cin >>X >>Y;

    md = D+1;
    ans = NG;
    dfs(0,0,0,"");

    return ans;
}

string greed(){
    cin >>X >>Y;

    for(int i=1; i<=31; ++i){

        ll nx=0, ny=0;
        string t = "";
        for(int j=i-1; j>=0; --j){
            ll w = 1<<j;

            if(abs(nx-X) > abs(ny-Y)){
                if(nx < X){
                    t += 'E';
                    nx += w;
                }
                else{
                    t += 'W';
                    nx -= w;
                }
            }
            else{
                if(ny < Y){
                    t += 'N';
                    ny += w;
                }
                else{
                    t += 'S';
                    ny -= w;
                }
            }
        }

        reverse(all(t));
        if(nx==X && ny==Y) return t;
    }
    return NG;
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d: ", i+1);
        cout << greed() << "\n";
    }
    return 0;
}
