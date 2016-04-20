n=int(input())
h=list(map(int,input().split()))
x=int(input())

ans=0
while ans<len(h) and h[ans]<x:
    ans+=1
print(ans+1)
