h,w,x,y = map(int,input().split())
print('No' if (h*w)%2==1 and (x+y)%2==1 else 'Yes')
