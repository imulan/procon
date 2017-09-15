n = int(input())
s = input()
ans = 0
for w in s.split(' '):
    t = 0
    for c in w:
        if ord('A')<=ord(c)<=ord('Z'):
            t += 1
    ans = max(ans,t)
print(ans)
