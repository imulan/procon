n=int(input())
s=input()[:-1].split(" ")

ans=0
for v in s:
    if "TAKAHASHIKUN"==v or "Takahashikun"==v or "takahashikun"==v:
        ans+=1
print(ans)
