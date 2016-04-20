n,m=map(int,input().split())

disk=[x+1 for x in range(n)]
play=0

for i in range(m):
    now=int(input())

    if play!=now:
        index=disk.index(now)
        play,disk[index]=disk[index],play

for v in disk:
    print(v)
