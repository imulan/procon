a,b,c,d = map(int,input().split())

myturn = True
while a>0 and c>0:
    if myturn:
        c -= b
    else:
        a -= d
    myturn = not myturn

print('Yes' if c<=0 else 'No')
