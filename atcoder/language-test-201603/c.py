import sys

n=int(input())

#1との距離
m1=0
idx=-1
for i in range(2,n+1):
	print("? {0} {1}".format(1,i))
	sys.stdout.flush()
	d=int(input())

	if m1<d :
		m1=d
		idx=i

#idxとの距離
md=0
for i in range(1,n+1):
	if i==idx:
		continue

	print("? {0} {1}".format(idx,i))
	sys.stdout.flush()
	md=max(md,int(input()))

print("! {0}".format(md))
