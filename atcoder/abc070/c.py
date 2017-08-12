import fractions

def lcm(x,y):
    return x*y//fractions.gcd(x,y);

n = int(input())
ans = 1
for _ in range(n):
    t = int(input())
    ans = lcm(ans,t)

print(ans)
