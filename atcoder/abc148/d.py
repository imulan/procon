n = int(input())
a = list(map(int, input().split()))

ct = 0
for i in a:
    if i == ct+1:
        ct += 1

print(n-ct if ct>0 else -1)
