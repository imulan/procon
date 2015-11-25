#include <cstdio>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main(){
	while(1){
		int n, k;
		int p[10];
		set<long> s;
		
		scanf(" %d", &n);
		if(n==0) break;
		scanf(" %d", &k);	
		for(int i=0; i<n; ++i) scanf(" %d", &p[i]);
		
		if(k==2){
			for(int a=0; a<n; ++a){
				for(int b=0; b<n; ++b){
					if(b==a) continue;
					stringstream ss;
					ss<<p[a];
					ss<<p[b];
					
					istringstream iss(ss.str());
					long t;
					iss>>t;
					s.insert(t);
					iss.clear();
				}
			}	
		}
		else if(k==3){
			for(int a=0; a<n; ++a){
				for(int b=0; b<n; ++b){
					if(b==a) continue;
					for(int c=0; c<n; ++c){
						if(c==a || c==b) continue;
						stringstream ss;
						ss<<p[a];
						ss<<p[b];
						ss<<p[c];
						
						istringstream iss(ss.str());
						long t;
						iss>>t;
						s.insert(t);
						iss.clear();	
					}
				}
			}
		}
		else if(k==4){
			for(int a=0; a<n; ++a){
				for(int b=0; b<n; ++b){
					if(b==a) continue;
					for(int c=0; c<n; ++c){
						if(c==a || c==b) continue;
						for(int d=0; d<n; ++d){
							if(d==a || d==b || d==c) continue;
							stringstream ss;
							ss<<p[a];
							ss<<p[b];
							ss<<p[c];
							ss<<p[d];
							
							istringstream iss(ss.str());
							long t;
							iss>>t;
							s.insert(t);
							iss.clear();	
						}
					}
				}
			}
		}
		
		printf("%ld\n", s.size());
	}
}