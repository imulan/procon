#include <cstdio>
#include <cmath>

typedef struct{
	double x;
	double y;
	double z;
}point;
	
int main(void){
	while(1){
		point p, q;
		double a, b, c, d;
		double ccc, theta, dist;
		
		scanf(" %lf %lf %lf %lf", &a, &b, &c, &d);
		if(a==-1 && b==-1) break;
		
		double e, f, g, h;
		e = (90-a) * M_PI / 180.0;
		f = b * M_PI / 180.0;
		g = (90-c) * M_PI / 180.0;
		h = d * M_PI / 180.0;
		
		//極座標変換
		p.x = sin(e) * cos(f);
		p.y = sin(e) * sin(f);
		p.z = cos(e);
		q.x = sin(g) * cos(h);
		q.y = sin(g) * sin(h);
		q.z = cos(g);
		
		//printf("P(%lf,%lf,%lf) , Q(%lf,%lf,%lf)\n", p.x, p.y, p.z, q.x, q.y, q.z);
		
		ccc = p.x*q.x + p.y*q.y + p.z*q.z;
		theta = acos(ccc);
		dist = theta * 6378.1 + 0.5;
		
		printf("%ld\n", (long)dist);
	}

	return 0;
}