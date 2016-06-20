import math

s=input()

ct=[0 for i in range(26)]
for c in s:
    ct[ord(c)-ord('A')]+=1

ans=math.factorial(len(s))
for i in range(26):
    ans=ans//math.factorial(ct[i])
ans-=1

print(ans%573)
