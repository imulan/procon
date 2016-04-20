s=input()

ans=0
for i in range(len(s)):
    if s[i]=='…':
        j=i
        while j<len(s) and s[j]=='…':
            j+=1
        ans=max(ans,j-i)

print(ans)
