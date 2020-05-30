import itertools

n = int(input())
p = tuple(map(int, input().split()))
q = tuple(map(int, input().split()))

l = list(itertools.permutations([i+1 for i in range(n)], n))
print(abs(l.index(p)-l.index(q)))
