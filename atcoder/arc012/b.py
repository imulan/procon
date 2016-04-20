n,va,vb,l=map(int,input().split())

dist=l

for i in range(n):
    t=dist/va
    dist=t*vb

print("{0:.20f}".format(dist))
