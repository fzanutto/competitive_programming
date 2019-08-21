# find length of longest 
# increasing subsequence 
# in O(n Log n) time
# https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

def CeilIndex(A, l, r, key): 

    while (r - l > 1): 
        m = l + (r - l)//2
        if (A[m] >= key): 
            r = m 
        else: 
            l = m 
    return r 

def LIS(A, size): 

    # Add boundary case, 
    # when array size is one 

    tailTable = [0 for i in range(size + 1)]
    len = 0 # always points empty slot 

    tailTable[0] = A[0] 
    len = 1
    for i in range(1, size): 
    
        if (A[i] < tailTable[0]): 

            # new smallest value 
            tailTable[0] = A[i] 

        elif (A[i] > tailTable[len-1]): 

            # A[i] wants to extend 
            # largest subsequence 
            tailTable[len] = A[i] 
            len+= 1

        else: 
            # A[i] wants to be current 
            # end candidate of an existing 
            # subsequence. It will replace 
            # ceil value in tailTable 
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i] 
            

    return len
