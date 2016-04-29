#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct{
	int f;
	int a;
	int t;
	int x;
	int y;
}Data;
	
int getDist2(int x1, int y1, int x2, int y2){
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
	
int main(){
	int n;
	Data d[100];
		
	//input
	cin >> n;
	for(int i=0; i<n; ++i) scanf(" %d %d %d %d %d", &d[i].f, &d[i].a, &d[i].t, &d[i].x, &d[i].y); 	

	//solve
	int dist[2];
	int fr[2];
	
	dist[0]=dist[1]=-1;	
	fr[0]=fr[1]=400000;
	
	for(int i=0; i<n-1; ++i){
		//違うチーム間でのボール移動はパスではない
		if(d[i].t != d[i+1].t) continue;
		//同じ選手同士はパスではない
		if(d[i].a == d[i+1].a) continue;
	
		int tmp = getDist2(d[i].x, d[i].y, d[i+1].x, d[i+1].y);
		
		//記録更新
		if(tmp>dist[d[i].t] || (tmp==dist[d[i].t] && fr[d[i].t]>d[i+1].f-d[i].f)){
			dist[d[i].t] = tmp;
			fr[d[i].t] = d[i+1].f-d[i].f;	
		}
	
	}
		
	//output
	if(dist[0]==-1) printf("-1 -1\n");
	else printf("%.10lf %.10lf\n", sqrt(dist[0]), (double)fr[0]/60);
	
	if(dist[1]==-1) printf("-1 -1\n");
	else printf("%.10lf %.10lf\n", sqrt(dist[1]), (double)fr[1]/60);
}