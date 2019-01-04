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

using pi = pair<int,int>;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

const int N = 222;
string s[N];
bool vis[N][N]={};

bool IN(int y, int x){
    return 0<=y && y<N && 0<=x && x<N;
}

//  0, 1,  2,  3, 4,  5,  6, 7,  8,  9, +, -, *
// 12, 5, 11, 11, 9, 11, 12, 7, 13, 12, 5, 3, 1
char GET(int y, int x, int c){
    if(c == 1) return '*';
    if(c == 3) return '-';
    if(c == 5){
        if(s[y+1][x] == 'X') return '1';
        return '+';
    }
    if(c == 7) return '7';
    if(c == 9) return '4';
    if(c == 11){
        // 2,3,5
        if(s[y+3][x+2] != 'X') return '2';
        if(s[y+1][x] != 'X') return '3';
        return '5';
    }
    if(c == 12){
        // 0,6,9
        if(s[y+2][x+1] != 'X') return '0';
        if(s[y+1][x+2] != 'X') return '6';
        return '9';
    }
    return '8';
}

int main(){
    rep(i,N) s[i] = string(N,'.');

    int n;
    cin >>n;
    rep(i,n){
        int x1,y1,x2,y2;
        cin >>x1 >>y1 >>x2 >>y2;
        if(x1==x2) for(int y=min(y1,y2); y<=max(y1,y2); ++y) s[y][x1]='X';
        else for(int x=min(x1,x2); x<=max(x1,x2); ++x) s[y1][x]='X';
    }

    string a = "";
    rep(x,N){
        rep(y,N)if(s[y][x]=='X' && !vis[y][x]){
            queue<pi> que;

            vis[y][x] = true;
            que.push({y,x});
            int ct = 1;

            while(!que.empty()){
                pi c = que.front();
                que.pop();
                rep(i,4){
                    int ny = c.fi+dy[i], nx = c.se+dx[i];
                    if(IN(ny,nx) && s[ny][nx]=='X' && !vis[ny][nx]){
                        vis[ny][nx] = true;
                        que.push({ny,nx});
                        ++ct;
                    }
                }
            }

            a += GET(y,x,ct);
        }
    }

    int A = a.size();
    ll ans = 0;

    int i = 0;
    int m = 1;
    ll t = 1;
    while(i<A){
        if(isdigit(a[i])){
            ll v = 0;
            while(i<A && isdigit(a[i])){
                v = 10*v + (a[i]-'0');
                ++i;
            }
            t *= v;
        }
        else{
            if(a[i] == '+'){
                ans += m*t;
                m = 1;
                t = 1;
            }
            else if(a[i] == '-'){
                ans += m*t;
                m = -1;
                t = 1;
            }
            ++i;
        }
    }
    ans += m*t;

    cout << ans << endl;
    return 0;
}
