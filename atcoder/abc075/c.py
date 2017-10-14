import queue
n,m = map(int,input().split())

g = [[0 for i in range(n)] for j in range(n)]

for _ in range(m):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    g[a][b] = g[b][a] = 1

ans = 0
for i in range(n):
    for j in range(i):
        if g[i][j] == 1:
            g[i][j] = g[j][i] = 0

            vis = [False for _ in range(n)]
            vis[0] = True
            q = queue.Queue()
            q.put(0)
            while not q.empty():
                v = q.get()
                for e in range(n):
                    if g[v][e] == 1 and not vis[e]:
                        vis[e] = True
                        q.put(e)

            add = 0
            for k in range(n):
                if not vis[k]:
                    add = 1
            ans += add

            g[i][j] = g[j][i] = 1

print(ans)
