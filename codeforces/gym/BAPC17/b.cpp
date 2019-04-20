#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()
#define EPS 1e-10
class Point{
public:
    double x,y;
    Point(){}
    Point(double xx,double yy){
        x=xx;
        y=yy;
    }
    Point operator +(Point p){
        return Point(x+p.x,y+p.y);
    }
    Point operator -(Point p){
        return Point(x-p.x,y-p.y);
    }
    Point operator *(double a){
        return Point(x*a,y*a);
    }
    Point operator /(double a){
        return Point(x/a,y/a);
    }
    double abs(){
        return sqrt(norm());
    }
    double norm(){
        return x*x+y*y;
    }
    bool operator<(const Point &p)const{
        return x!=p.x ? x<p.x:y<p.y;
    }
    bool operator ==(const Point &p)const{
        return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
    }
};

typedef Point Vector;

struct Segment{
    Point p1,p2;
    Segment(){}
    Segment(Point pp1,Point pp2){
        p1=pp1;
        p2=pp2;
    }
};

typedef Segment Line;

class Circle{
public:
    Point c;
    double r;
    Circle(){}
    Circle(Point cc,double rr){
        c=cc;
        r=rr;
    }
};

double norm(Vector v){
    return v.x*v.x+v.y*v.y;
}

double abs(Vector v){
    return sqrt(norm(v));
}

double dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

double arg(Vector p){
    return atan2(p.y,p.x);
}

Vector polar(double a,double r){
    return Point(cos(r)*a,sin(r)*a);
}

int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS)return 1;
    if(cross(a,b)<-EPS)return -1;
    if(dot(a,b)<-EPS)return 2;
    if(a.norm()<b.norm())return -2;
    return 0;
}

Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

double getDistance(Point a,Point b){
    return abs(a-b);
}

double getDistanceLP(Line l,Point p){
    return abs(cross(l.p2-l.p1,p-l.p1))/abs(l.p2-l.p1);
}

bool intersect(Circle c,Line l){
    return c.r>=(getDistanceLP(l,c.c));
}

pair<Point,Point> getCrossPoints(Circle c,Line l){
    assert(intersect(c,l));
    Vector pr=project(l,c.c);
    Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
    double base=sqrt(c.r*c.r-norm(pr-c.c));
    return make_pair(pr+e*base,pr-e*base);
}
bool intersect(Circle c1,Circle c2){
    if(c1.r+c2.r<getDistance(c1.c,c2.c))return false;
    if(abs(c1.r-c2.r)>getDistance(c1.c,c2.c))return false;
    return true;
}

pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
    assert(intersect(c1,c2));
    double d=abs(c1.c-c2.c);
    double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2.0*c1.r*d));
    double t=arg(c2.c-c1.c);
    return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}

//in=2, on=1,out=0
int Contains(Circle c,Point p){
    double dist=abs(c.c-p);
    if(dist<c.r-EPS)return 2;
    if(dist>c.r+EPS)return 0;
    return 1;
}

struct edge{
    int to;
    double c;
    edge(){}
    edge(int tt,double cc){
        to=tt;
        c=cc;
    }
};

Point s,g;
int n;
Circle c[30];
vector<Point> pos;
vector<edge> G[5001];
typedef pair<Point,int> PP;

void init(){
    pos.push_back(s);
    pos.push_back(g);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(intersect(c[i],c[j])){
                pair<Point,Point> tmp=getCrossPoints(c[i],c[j]);
                //printf("%.3f %.3f\n",tmp.first.x,tmp.first.y);
                pos.push_back(tmp.first);
                //printf("%.3f %.3f\n",tmp.second.x,tmp.second.y);
                pos.push_back(tmp.second);
            }
        }
    }
    sort(pos.begin(),pos.end());
    pos.erase(unique(pos.begin(),pos.end()),pos.end());
}

int type[30][2];
int cts[30];

bool checkline(Point p1,Point p2){
    if(p2<p1)swap(p1,p2);
    memset(type,0,sizeof(type));
    for(int i=0;i<n;i++){
        type[i][0]=Contains(c[i],p1);
        type[i][1]=Contains(c[i],p2);
        if(type[i][0]>0 && type[i][1]>0)return true;
    }
    vector<PP> crs;
    for(int i=0;i<n;i++){
        if(intersect(c[i],Line(p1,p2))){
            pair<Point,Point> tmp=getCrossPoints(c[i],Line(p1,p2));
            if(tmp.first==tmp.second)continue;
            if(ccw(p1,p2,tmp.first)==0)crs.push_back(PP(tmp.first,i));
            if(ccw(p1,p2,tmp.second)==0)crs.push_back(PP(tmp.second,i));
        }
    }
    crs.push_back(PP(p1,-1));
    crs.push_back(PP(p2,114514));
    sort(crs.begin(),crs.end());
    crs.erase(unique(crs.begin(),crs.end()),crs.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(type[i][0]==2)cnt++;
    }

    memset(cts,0,sizeof(cts));
    for(int i=0;i<(int)crs.size();i++){
        //printf("(%.2f,%.2f) %d\n",crs[i].first.x,crs[i].first.y,cnt);
        int v=crs[i].second;
        if(i>0 && !(crs[i].first==crs[i-1].first) && cnt<=0)return false;
        if(v==-1 || v==114514)continue;
        if(cts[v]==0){
            if(type[v][0]==0 && type[v][1]==2)cnt++;
            else if(type[v][0]==0 && type[v][1]==0)cnt++;
            else if(type[v][0]==2 && type[v][1]==0)cnt--;
        }
        if(cts[v]==1){
            cnt--;
        }
        cts[v]++;

    }
    return true;
}

void setlines(){
    for(int i=0;i<(int)pos.size();i++){
        for(int j=i+1;j<(int)pos.size();j++){
            if(checkline(pos[i],pos[j])){
                double dist=abs(pos[i]-pos[j]);
                //printf("(%.2f,%.2f)->(%.2f,%.2f)=%.2f\n",pos[i].x,pos[i].y,pos[j].x,pos[j].y,dist);
                G[i].push_back(edge(j,dist));
                G[j].push_back(edge(i,dist));
            }
        }
    }
}

double dist[5005];

typedef pair<double,int> node;

double dijk(){
    for(int i=0;i<(int)pos.size();i++){
        dist[i]=1e18;
    }
    priority_queue<node,vector<node>,greater<node> > que;
    for(int i=0;i<(int)pos.size();i++){
        if(pos[i]==s){
            que.push(node(0,i));
            dist[i]=0.0;
        }
    }
    while(que.size()){
        node q=que.top();
        que.pop();
        if(q.first>dist[q.second])continue;
        int v=q.second;
        //printf("dijk %d %.2f\n",v,dist[v]);
        for(int i=0;i<(int)G[v].size();i++){
            edge e=G[v][i];
            if(e.c+dist[v]<dist[e.to]){
                dist[e.to]=dist[v]+e.c;
                que.push(node(dist[e.to],e.to));
            }
        }
    }
    for(int i=0;i<(int)pos.size();i++){
        if(pos[i]==g)return dist[i];
    }
}

int main(){
    scanf("%lf%lf%lf%lf",&s.x,&s.y,&g.x,&g.y);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf%lf",&c[i].c.x,&c[i].c.y,&c[i].r);
    }
    init();
    setlines();
    double ans=dijk();
    if(fabs(ans-1e18)<EPS)printf("impossible\n");
    else printf("%.10f\n",ans);
    return 0;
}
