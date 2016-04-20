n=int(input())
s=input()

ct=[0 for _ in range(4)]
for i in range(n):
	ct[int(s[i])-1]+=1

print(max(ct),min(ct))
