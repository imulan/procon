a,b,t = map(int,input().split())

ans = 10**20
for i in range(min(a,t//b)+2):
    r = t-b*i

    j = 0
    if r>0:
        j = (t-b*i+a-1)//a

    ans = min(ans,b*i+a*j)

print(ans)
