n, k = map(int, input().split())
p = list(sorted(map(int, input().split())))
print(sum(p[:k]))
