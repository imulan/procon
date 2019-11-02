def solve():
    n = int(input())
    a = list(map(lambda x:x-1, map(int,input().split())))

    ans = [-1 for _ in range(n)]
    for i in range(n):
        if ans[i] != -1:
            continue

        now = i
        cycle = []
        while ans[now] == -1:
            ans[now] = 0
            cycle.append(now)
            now = a[now]

        sz = len(cycle)
        for j in cycle:
            ans[j] = sz

    return ' '.join(map(str, ans))

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
