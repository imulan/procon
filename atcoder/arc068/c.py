x = int(input())

ans = (x//11)*2
if 1 <= x%11 <= 6:
    ans += 1
elif 7 <= x%11 <= 10:
    ans += 2

print(ans)
