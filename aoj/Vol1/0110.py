import sys

for s in sys.stdin:
    #改行文字の除去
    s=s[:-1]
    #左辺と右辺に分ける
    p=s.split("=")

    ans="NA"
    st=0

    #Xとして0を許すか否かの判定
    #2桁以上で先頭にXがあるときはダメ
    tmp=p[0].split("+")
    if tmp[0][0]=="X" and len(tmp[0])>1:
        st=1
    if tmp[1][0]=="X" and len(tmp[1])>1:
        st=1
    if p[1][0]=="X" and len(p[1])>1:
        st=1

    #print(p)
    for i in range(st,10):
        a=eval(p[0].replace("X",str(i)))
        b=eval(p[1].replace("X",str(i)))
        if a==b:
            ans=i
            break

    print(ans)
