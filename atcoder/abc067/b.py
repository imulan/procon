n,k = map(int,input().split())
l = list(map(int,input().split()))

l.sort()
l.reverse()
print(sum(l[0:k]))
