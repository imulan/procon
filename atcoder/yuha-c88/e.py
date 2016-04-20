n=int(input())

#input
s=[]
for i in range(n):
    s.append(input())

l=[]
a=[]

line=input()
l.append(line[2])

line=input()
a.append(line[2])

line=input()
l.append(line[0])
a.append(line[1])
a.append(line[3])
l.append(line[4])

line=input()
a.append(line[2])

line=input()
l.append(line[2])

#solve
#条件に合致するものを全探索
candidate=[]
for i in range(4):
    idx=0
    if i==0:
        if a[i]=='↓':
            idx=0
        else:
            idx=1
    elif i==1:
        if a[i]=='→':
            idx=0
        else:
            idx=1
    elif i==2:
        if a[i]=='←':
            idx=0
        else:
            idx=1
    elif i==3:
        if a[i]=='↑':
            idx=0
        else:
            idx=1

    tmp=[]
    for v in s:
        if v[idx]==l[i]:
            tmp+=list(v)
            #print(tmp)
    candidate.append(tmp)

#どちらの文字か判別
sets=[]
for i in range(4):
    sets.append(set(candidate[i]))
#print(sets)
print(list(sets[0]&sets[1]&sets[2]&sets[3])[0])
