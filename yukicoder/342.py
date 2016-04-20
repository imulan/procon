s=input()

head=0
while head<len(s) and s[head]=='ｗ':
    head+=1
s=s[head:]

#最長のｗを探す
M=0
for i in range(len(s)):
    if s[i]=='ｗ':
        j=i
        while j<len(s) and s[j]=='ｗ':
            j+=1
        M=max(M,j-i)

ans=[]
for i in range(len(s)):
    if s[i]=='ｗ':
        j=i
        while j<len(s) and s[j]=='ｗ':
            j+=1

        #最長なのでここの文字列を探しに行く
        if j-i==M:
            st=i-1
            while st>=0 and s[st]!='ｗ':
                st-=1
            #print("st=",st)
            ans.append(s[st+1:i])

for v in ans:
    if len(v)>0:
        print(v)
