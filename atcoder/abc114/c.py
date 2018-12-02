import collections

n = int(input())

s = set()
que = collections.deque()
que.appendleft(0)
while que:
    v = que.pop()
    for c in '357':
        nv = v*10 + int(c)
        if nv <= n and nv not in s:
            s.add(str(nv))
            que.appendleft(nv)

ans = 0
for i in s:
    add = 1
    for c in '357':
        if c not in i:
            add = 0
    ans += add
print(ans)
