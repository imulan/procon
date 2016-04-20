s=input()
a=s.split(" ")

mp={}
freq=""
longest=""

mx=0
for v in a:
    #出現回数カウント
    if v in mp:
        mp[v]+=1
    else:
        mp[v]=1

    if mx<mp[v]:
        freq=v
        mx=mp[v]

    #最長文字列更新
    if len(longest)<len(v):
        longest=v

print(freq,longest)
