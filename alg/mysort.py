# mysort.py
# sorting algorithms

from random import random

def rlist(count):
        '''generate a random list'''
	a = []
	for i in xrange(count):
		a.append(int(random()*100))
	return a
    
def insertion_sort(alist):
    '''
        insertion_sort

        >>> a = [3, 9, 7, 8, 6, 2, 1, 5, 4]
        >>> insertion_sort(a)
        [1, 2, 3, 4, 5, 6, 7, 8, 9]

    '''
    
    for i in xrange(1,len(alist)):
        val = alist[i]
        while i>0:
            if val < alist[i-1]:
                alist[i] = alist[i-1] # move right
                alist[i-1] = val
                i = i -1
            else:
                break
    return alist

def merge(left,right):
    result = []
    i = j = 0
    while True:
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
        if i >= len(left) or j >= len(right):
            break
        
    result += left[i:]
    result += right[j:]
    return result
        
def merge_sort(m):
    '''
        merge_sort

        >>> a = [3, 9, 7, 8, 6, 2, 1, 5, 4]
        >>> merge_sort(a)
        [1, 2, 3, 4, 5, 6, 7, 8, 9]

    '''
    if len(m) <= 1:
        return m

    middle = len(m)/2
    left = m[:middle]
    right = m[middle:]
    left = merge_sort(left)
    right = merge_sort(right)
    result = merge(left,right)
    return result

def bubble_sort(m):
    '''
        bubble_sort

        >>> a = [3, 9, 7, 8, 6, 2, 1, 5, 4]
        >>> merge_sort(a)
        [1, 2, 3, 4, 5, 6, 7, 8, 9]

    '''
    if len(m) <= 1:
        return m
    
    for i in xrange(len(m)):
        for j in xrange(i+1,len(m)):
            if m[j] < m[i]:
                tmp = m[i]
                m[i] = m[j]
                m[j] = tmp
    return m
    
if __name__ == '__main__':
    import doctest
    print doctest.testmod()
    
