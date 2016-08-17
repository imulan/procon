s=input()

ans=""
for c in s:
    if c=='B':
        if len(ans)>0:
            ans=ans[:-1]
    else:
        ans += c

print(ans)
