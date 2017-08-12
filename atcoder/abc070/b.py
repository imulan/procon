a,b,c,d = map(int,input().split())

l,r = max(a,c),min(b,d)
print(max(0,r-l))
