from collections import deque

INF = 10101010

def main():
    h,w = map(int,input().split())
    s = []
    for i in range(h):
        s.append(input())

    ans = 0
    for i in range(h):
        ans += s[i].count('.')

    d = [[INF for j in range(w)] for i in range(h)]
    d[0][0] = 0
    que = deque()
    que.append((0,0))
    while que:
        y,x = que.pop()
        if (y,x) == (h-1,w-1):
            return ans - (d[h-1][w-1]+1)

        for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            nx,ny = x+dx, y+dy
            if 0 <= nx < w and 0 <= ny < h:
                if s[ny][nx] != '#' and d[ny][nx]>d[y][x]+1:
                    d[ny][nx] = d[y][x]+1
                    que.appendleft((ny,nx))

    return -1

if __name__ == '__main__':
    print(main())
