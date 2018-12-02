def prime(n):
    for i in range(2,n):
        if n%i == 0:
            return False
    return True

def main():
    n = int(input())

    f = 1
    for i in range(1,n+1):
        f *= i

    p = []
    for i in range(2,n):
        if prime(i):
            p.append(i)
    P = len(p)

    ans = set()
    for i in range(P):
        x = p[i]**74
        if f%x == 0:
            ans.add(x)

        for j in range(P):
            if i == j:
                continue

            x = p[i]**24 * p[j]**2
            if f%x == 0:
                ans.add(x)

            x = p[i]**14 * p[j]**4
            if f%x == 0:
                ans.add(x)

            for k in range(P):
                if i == k or j == k:
                    continue

                x = p[i]**4 * p[j]**4 * p[k]**2
                if f%x == 0:
                    ans.add(x)

    print(len(ans))

if __name__ == "__main__":
    main()
