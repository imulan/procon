for _ in range(int(input())):
    n = int(input())

    ans = ''
    if n%8 == 0:
        ans += 'iki'
    if n%10 == 0:
        ans += 'sugi'
    if ans == '':
        ans = n//3

    print(ans)

