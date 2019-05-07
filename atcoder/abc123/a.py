x = []
for i in range(5):
    x.append(int(input()))
k = int(input())
print(':(' if x[4]-x[0]>k else 'Yay!')
