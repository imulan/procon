n,l=map(int,input().split())

#[1,2,3,...,n]のリスト作成
nums=[x+1 for x in range(n)]

#あみだくじ読み込み
for i in range(l):
    s=input()[1::2]
    for j in range(n-1):
        if s[j]=='-':
            #swap
            nums[j],nums[j+1]=nums[j+1],nums[j]

#oの位置を探して答えを出力
print(nums[input().find('o')//2])
