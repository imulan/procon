#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

typedef struct{
	int num;
	int p; //point
	int r; //rank
}team;

int main(){
	int n;
	team t[100];
	scanf(" %d", &n);
	
	for(int i=0; i<n; ++i){
		t[i].p=0;
		t[i].num=i;
	}
	
	for(int i=0; i<n*(n-1)/2; ++i){
		int a, b, c, d;
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		if(c<d) t[b-1].p += 3;	
		else if(c>d) t[a-1].p += 3;	
		else{
			t[a-1].p += 1;
			t[b-1].p += 1;
		}
	}	
	
	for(int i=0; i<n; ++i){
		for(int j=i; j<n; ++j){
			if(t[i].p < t[j].p) swap(t[i], t[j]);		
		}
	}
	
	t[0].r=1;
	
	int now=1;
	int count=1;
	for(int i=0; i<n-1; ++i){
		if(t[i+1].p == t[i].p) count++;
		else{
			now+=count;
			count=1;
		}
		t[i+1].r=now;
	}
	
	for(int i=0; i<n; ++i){
		for(int j=i; j<n; ++j){
			if(t[i].num > t[j].num) swap(t[i], t[j]);		
		}
	}
	
	for(int i=0; i<n; ++i) printf("%d\n", t[i].r);
}