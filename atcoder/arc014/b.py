n=int(input())

w=[]
for i in range(n):
    w.append(input())

#既出単語リスト
past=[]

last=True
for now in range(n):
    if now>0 and (w[now] in past or w[now][0]!=w[now-1][-1]):
        last=False
        break
    else:
        past.append(w[now])

ans="DRAW"
if not last:
    if now%2==0:
        ans="LOSE"
    else:
        ans="WIN"
print(ans)
