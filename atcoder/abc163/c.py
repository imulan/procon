n = int(input())
a = list(map(int,input().split()))

ct = [0 for _ in range(n)]
for i in a:
    ct[i-1] += 1
for i in ct:
    print(i)
