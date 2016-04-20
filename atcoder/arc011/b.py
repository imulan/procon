d={'b':1,'c':1, 'd':2,'w':2, 't':3,'j':3, 'f':4,'q':4, 'l':5,'v':5, 's':6,'x':6, 'p':7,'m':7, 'h':8,'k':8, 'n':9, 'g':9, 'z':0, 'r':0}

n=int(input())
s=input().lower().split()

ans=[]
for t in s:
    p=""

    for i in range(len(t)):
        if t[i] in d:
            p+=str(d[t[i]])

    if len(p)>0:
        ans.append(p)

for i in range(len(ans)):
    if i>0:
        print(" ",end="")
    print(ans[i],end="")
print()
