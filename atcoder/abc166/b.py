n, k = map(int, input().split())

ct = [0]*n

for i in range(k):
    d = input()
    a = list(map(int, input().split()))
    for j in a:
        ct[j-1] = 1

print(n-sum(ct))
