#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

typedef struct{
	string name;
	double eff;
}vegetable;

int main(){
	while(1){
		int n;
		vegetable v[50];
		
		scanf(" %d", &n);
		if(n==0) break;
		for(int i=0; i<n; ++i){
			cin >> v[i].name;
			int p,a,b,c,d,e,f,s,m;	
			
			cin>>p>>a>>b>>c>>d>>e>>f>>s>>m;
			int time=a+b+c;
			for(int j=0; j<m; ++j) time+=d+e;
			long price=m*f*s;
			price-=p;
			v[i].eff = (double)price/time;
		}
		
		for(int i=0; i<n; ++i){
			for(int j=i; j<n; ++j){
				if(v[i].eff < v[j].eff) swap(v[i], v[j]);
				else if(v[i].eff == v[j].eff){
					if(v[i].name > v[j].name) swap(v[i], v[j]);	
				}
			}
		}
		
		for(int i=0; i<n; ++i) cout << v[i].name << endl;
		printf("#\n");
	}
	return 0;
}