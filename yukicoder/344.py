n=int(input())

a=[[1,3],[1,1]]

pw=[a]
while len(pw)<10 :
    print(len(pw))
    #末尾の要素
    t=pw[-1]

    nn=[[0,0],[0,0]]
    nn[0][0]=t[0][0]**2+t[0][1]*t[1][0]
    nn[0][1]=t[0][0]*t[0][1]+t[0][1]*t[1][0]
    nn[1][0]=t[0][0]*t[1][0]+t[1][0]*t[1][1]
    nn[1][1]=t[0][1]*t[1][0]+t[1][1]**2

    pw.append(nn)

for i in pw:
    print(i)
