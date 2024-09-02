from collections import defaultdict
n=int(input())
mp=defaultdict(int)
mp1=[]

v=set()
for i in range(n):
    x,y=input().split()
    if mp1[x]:
        mp1[x].append(y)
    else:
        mp1[x]=y
# print(v)
print(mp1)
