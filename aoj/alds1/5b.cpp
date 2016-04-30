#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

long L[MAX/2+2], R[MAX/2+2];
long cnt;

void merge(long x[], long n, long left, long mid, long right){
	long n1=mid-left;
	long n2=right-mid;
	
	for(long i=0; i<n1; ++i) L[i]=x[left+i];
	for(long i=0; i<n2; ++i) R[i]=x[mid+i];
	L[n1]=R[n2]=SENTINEL; //終端を示すもの

	long i=0, j=0;
	for(long k=left; k<right; ++k){
		++cnt;
		if(L[i]<=R[j]) x[k]=L[i++];
		else x[k]=R[j++];
	}	
}

void mergesort(long x[], long n, long left, long right){
	if(left+1 < right){
		long mid=(left+right)/2;
		
		mergesort(x, n, left, mid);
		mergesort(x, n, mid, right);
		merge(x, n, left, mid, right);	
	}
}

int main(){
	long a[MAX], n;
	
	cnt=0;
	scanf(" %ld", &n);
	for(long i=0; i<n; ++i) scanf(" %ld", &a[i]);
	
	mergesort(a, n, 0, n);
	
	for(long i=0; i<n; ++i){
		if(i>0) printf(" ");
		printf("%ld", a[i]);
	}
	printf("\n%ld\n", cnt);
}