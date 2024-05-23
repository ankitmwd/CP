with open('data.txt', 'r') as file:
    lines = file.readlines()
    avg=275
    cnt=0
    n=len(lines)
    i=0
    while(i<n):
        if avg>=int(lines[i]):
            cnt=cnt+1
        i=i+1
        print(cnt)
    print(cnt)
    lines[1]=str(avg)+'\n'
    
with open('data.txt', 'w') as file:
    file.writelines(lines)
    
            