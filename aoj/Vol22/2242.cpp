#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string name;
	long s; //start
	long e; //end
}era;
	
int main(){
	while(1){
		int n, q;
		era a[1000];
		
		scanf(" %d %d", &n, &q);
		if(n==0 && q==0) break;
		
		for(int i=0; i<n; ++i){
			long le;
			cin >> a[i].name;
			scanf(" %ld %ld", &le, &a[i].e);
			a[i].s=a[i].e-le+1;	
		}
		
		for(int i=0; i<q; ++i){
			long query;
			scanf(" %ld", &query);
			
			bool found=false;
			for(int j=0; j<n; ++j){
				if(a[j].s<=query && query<=a[j].e){
					cout << a[j].name << " " << query-a[j].s+1 << endl;
					found=true;
					break;	
				}
			}
			
			if( !found ) printf("Unknown\n");
		}
		
	}
}
	