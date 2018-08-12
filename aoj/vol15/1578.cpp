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

struct Point{
    int x,y,z;
};

Point READ(){
    int x,y,z;
    cin >>x >>y >>z;
    return {x,y,z};
}

int n;
Point s,g;
int ans;

Point rot_x(Point p){
    return {p.x, n-1-p.z, p.y};
}

Point rot_y(Point p){
    return {p.z, p.y, n-1-p.x};
}

Point rot_z(Point p){
    return {n-1-p.y, p.x, p.z};
}

int dist(Point p, Point q){
    return abs(p.x-q.x) + abs(p.y-q.y) + abs(p.z-q.z);
}

bool IN(Point p){
    return 0<=p.x && p.x<n && 0<=p.y && p.y<n && 0<=p.z && p.z<n;
}

const int dx[6]={1,-1,0,0,0,0};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};
const int add[3]={1,2,1};

void dfs(int d, Point p, int cost){
    ans = min(ans, dist(p,g)+cost);
    if(d==6) return;

    Point np;
    rep(i,6){
        np = p;
        np.x += dx[i];
        np.y += dy[i];
        np.z += dz[i];
        if(IN(np)) dfs(d+1, np, cost+1);
    }

    if(p.x != g.x){
        np = p;
        rep(i,3){
            np = rot_x(np);
            dfs(d+1, np, cost+add[i]);
        }
    }

    if(p.y != g.y){
        np = p;
        rep(i,3){
            np = rot_y(np);
            dfs(d+1, np, cost+add[i]);
        }
    }

    if(p.z != g.z){
        np = p;
        rep(i,3){
            np = rot_z(np);
            dfs(d+1, np, cost+add[i]);
        }
    }
}

int main(){
    cin >>n;
    s = READ();
    g = READ();

    ans = dist(s,g);
    dfs(0,s,0);
    cout << ans << endl;
    return 0;
}
