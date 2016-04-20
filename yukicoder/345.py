s=input()
cww="cww"
a=1000
for i in range(len(s)):
    for j in range(i+1, len(s)):
        t=s[i:j+1]
        now=0
        for k in range(len(t)):
            if t[k]==cww[now]:
                now+=1
                if now==3:
                    break

        if now==3:
            a=min(a,j-i+1)

if a==1000:
    a=-1

print(a)
