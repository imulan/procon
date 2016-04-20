import math;

w,h=map(int,input().split())
res=math.factorial(w+h-2)//math.factorial(w-1)//math.factorial(h-1)
mod=1000000007
print(res%mod)
