#include <iostream>
#include <cstdio>

using namespace std;

typedef struct{
	int a;
	int v;
}member;

void swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int main(){
	int n, max=0;
	member m[20];
	
	cin >> n;
	for(int i=0; i<n; ++i){
		scanf(" %d %d", &m[i].a, &m[i].v);		
		if(max < m[i].v) max=m[i].v;
	}
	
	for(int i=0; i<n; ++i){
		for(int j=i; j<n; ++j){
			if(m[i].v < m[j].v){
				swap(&m[i].a, &m[j].a);
				swap(&m[i].v, &m[j].v);
			}
		}
	}

	int count=0;
	for(int i=0; i<n; ++i)
		if(max==m[i].v) ++count;

	int index=0;
	for(int i=0; i<count; ++i)
		if(m[index].a > m[i].a) index = i;

	printf("%d %d\n", m[index].a, m[index].v);

	return 0;
}