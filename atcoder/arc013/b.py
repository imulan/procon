c=int(input())

t=[]
for i in range(c):
    tt=list(map(int,input().split()))
    tt.sort()
    t.append(tt)

ans=1
for i in range(3):
    mul=1
    for j in range(c):
        mul=max(mul,t[j][i])
    ans*=mul
print(ans)
