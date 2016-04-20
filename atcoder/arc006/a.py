e=set(map(int,input().split()))
b=int(input())
l=set(map(int,input().split()))

ans=0
if len(e&l)==6:
    ans=1
elif len(e&l)==5:
    if b in l-e:
        ans=2
    else:
        ans=3
elif len(e&l)>=3:
    ans=8-len(e&l)

print(ans)
