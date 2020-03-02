N = 365

def main():
    n = int(input())
    d = list(map(int,input().split()))

    push = [False for i in range(N+1)]
    for i in d:
        push[i] = True

    ans = 0
    now,ct = 0,0
    for i in range(1,N+1):
        if push[i]:
            ct += 1

        if now+ct >= 20:
            ans += 1
            now = 0
            ct = 0
        now += ct
    if now > 0:
        ans += 1

    return ans

if __name__ == "__main__":
    print(main())
