#MEMOISATION - Use dictionary/hashmap to make it more efficient

#        STEPS: 1) come up with a brute force solution after visualising the problem using a tree
#               2) make it more efficient using a hashmap


def fib(n):
    if n == 1:
        return 0
    
    elif n == 2:
        return 1
    
    else: 
        return fib(n-1) + fib(n-2)
        

def fib_d(n,h):
    if n == 1:
        return 0
    
    elif n == 2:
        return 1
    
    elif n in h: 
        return h[n]
    
    else:
        h[n] = fib_d(n-1,h) + fib_d(n-2,h)
        return h[n]
    
        
def grid2(m, n):
    if m == 1 and n == 1:
        return 1
    
    elif m == 0 or n == 0:
        return 0
    else:
         return grid2(m-1,n) + grid2(m,n-1)
         
         
def grid_d(m, n,h):
    if m == 1 and n == 1:
        return 1
    
    elif m <= 0 or n <= 0:
        return 0
    
    elif (m,n) in h:
        return h[(m,n)]
    else:
         h[(m,n)] = grid_d(m-1,n,h) + grid_d(m,n-1,h)
         return h[(m,n)]


def canSum(target,arr):
    if target == 0:
        return True
    
    elif target < 0:
        return False
    
    for i in arr:
        x = canSum(target - i,arr)
        
        if x == True:
            return True
    return False

def canSum_d(target,arr,h):
    if target == 0:
        return True
    
    elif target < 0:
        return False
    
    for i in arr:
        if target - i in h:
            x = h[target - i]
        else:
            x = canSum_d(target - i,arr,h)
            h[target - i] = x
        
        if x == True:
            return True
    return False
        

a = canSum_d(201,[2,4],{})
print(a)


def howSum(target,arr,l):
    
    s = list(l)
    
    if target == 0:
        return l
    
    elif target < 0:
        return []
    
    for i in arr:
        s.append(i)
        x = howSum(target - i,arr,s)
        
        if x != []:
            return x
    return []

b = howSum(7,[2,7],[])
print(b)