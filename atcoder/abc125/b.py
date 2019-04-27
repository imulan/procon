n = int(input())
v = list(map(int,input().split()))
c = list(map(int,input().split()))
print(sum([max(0,i-j) for i,j in zip(v,c)]))
