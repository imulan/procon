K,S = map(int,input().split())

ans = 0

for X in range(K+1):
    for Y in range(K+1):
        Z = S-X-Y
        if 0 <= Z <= K:
            ans += 1

print(ans)
