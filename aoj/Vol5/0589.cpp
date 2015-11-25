#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

typedef struct{
	char name[6];
	long num;
}product;

product p[12000000];

int main(){
	long n, now=0;
	
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i){
		char s[6];
		long a;
		scanf(" %s %ld", s, &a);
		 
		bool find=false;
		for(long j=0; j<now; ++j){
			if(strcmp(p[j].name, s)==0){
				find=true;
				p[j].num+=a;
				break;
			}
		}
		
		if(!find){
			strcpy(p[now].name, s);	
			p[now].num=a;
			++now;
		}
	}

	for(long i=0; i<now; ++i){
		for(long j=i; j<now; ++j){
			if(strlen(p[i].name) > strlen(p[j].name)) swap(p[i], p[j]);
		}
	}
	
	for(long i=0; i<now; ++i){
		for(long j=i; j<now; ++j){
			if(strlen(p[i].name) == strlen(p[j].name)){
				for(int k=0; k<strlen(p[i].name); ++k){
					if(p[i].name[k] > p[j].name[k]){
						swap(p[i], p[j]);
						break;
					}
					else if(p[i].name[k] == p[j].name[k]){
						continue;
					}
					else break;
				}		
			}
		}
	}

	
	for(long i=0; i<now; ++i)
		cout << p[i].name << " " << p[i].num << endl;
	
}