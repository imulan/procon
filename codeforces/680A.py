def main():
    t = list(map(int,input().split()))

    sum = 0
    for v in t:
        sum += v

    ans = sum
    for i in range(5):
        ct = 0
        for j in range(5):
            if t[i] == t[j]:
                ct += 1

        if ct>=2:
            val = sum-ct*t[i]
            if ct>3:
                val = sum-3*t[i]
            ans = min(ans,val)

    print(ans)

if __name__ == '__main__':
    main()
