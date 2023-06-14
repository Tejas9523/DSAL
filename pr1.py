def insertHash1(val):
    pos = val % max
    if arr[pos] == -1:
        arr[pos] = val
    else:
        # with replacement
        temp = arr[pos]
        ind = temp % max
        if ind == pos:
            while(arr[pos] != -1):
                pos += 1
            arr[pos] = val
        else:
            arr[pos] = val
            while(arr[pos] != -1):
                pos += 1
            arr[pos] = temp
        
def insertHash2(val):
    pos = val % max
    if arr[pos] == -1:
        arr[pos] = val
    else:
        #quadratic
        for i in range(max):
           temp = (pos + i * i) % max
           if (arr[temp] == -1):
                arr[temp] = val
                break
        
        
max = int(input("Enter max value - "))
arr=[]

for i in range(max):
    arr.append(-1)

    
while(1>0):
    print("1. Insert")
    print("2. Display")
    ch = int(input("Enter choice - "))
    if ch == 1:
        n = int(input("Enter no of keys - "))
        for i in range(n):
            key = int(input("Enter telephone no - "))
            insertHash2(key)
    elif ch == 2:
        ind = 0
        for i in arr:
            print("Index ",ind," - ",i)
            ind += 1