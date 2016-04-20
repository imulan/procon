m,n,a=map(int,input().split())

ans=0
st=0
while a>0:
    #販売
    ans+=a
    #回収
    st+=a
    #再利用
    a=st//m*n
    st%=m

print(ans)
