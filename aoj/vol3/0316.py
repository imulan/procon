h1,h2 = map(int,input().split())
k1,k2 = map(int,input().split())
a,b,c,d = map(int,input().split())

def f(x,y):
    return a*x + b*y + c*(x//10) + d*(y//20)

H,K = f(h1,h2), f(k1,k2)
ans = 'even'
if H>K:
    ans = 'hiroshi'
elif H<K:
    ans = 'kenjiro'
print(ans)
