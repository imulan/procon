import math
import collections

def solve():
    N,L = map(int,input().split())
    a = list(map(int,input().split()))

    v = [-1 for i in range(L+1)]
    que = collections.deque()
    for i in range(L-1):
        if a[i] != a[i+1]:
            v[i+1] = math.gcd(a[i],a[i+1])
            que.append(i+1)
            break

    while que:
        idx = que.popleft()
        for i in [-1,1]:
            nx = idx+i
            if 0 <= nx <= L and v[nx] == -1:
                if i == -1:
                    v[nx] = a[nx]//v[idx]
                else:
                    v[nx] = a[idx]//v[idx]
                que.append(nx)

    uv = list(set(v))
    uv.sort()

    d = {}
    for i in range(len(uv)):
        d[uv[i]] = i

    s = [' ' for i in range(L+1)]
    for i in range(L+1):
        s[i] = chr(ord('A')+d[v[i]])

    return ''.join(s)

def main():
    T = int(input())
    for i in range(T):
        print('Case #{}: {}'.format(i+1, solve()))

if __name__ == "__main__":
    main()
