def dfs(now,vis,G):
    if sum(vis) == len(vis):
        return 1

    ret = 0
    for nx in G[now]:
        if vis[nx] == 0:
            nvis = vis[:]
            nvis[nx] = 1
            ret += dfs(nx,nvis,G)

    return ret

def main():
    n,m = map(int,input().split())

    G = [[] for _ in range(n)]
    for _ in range(m):
        a,b = map(int,input().split())
        a -= 1
        b -= 1
        G[a].append(b)
        G[b].append(a)

    vis = [0 for _ in range(n)]
    vis[0]=1
    return dfs(0,vis,G)

if __name__ == '__main__':
    print(main())
