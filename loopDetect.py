"""
Cycle Detection - CodeWar
"""

def floyd(root):
    hare = root.next.next
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(f(hare))
 
    tortoise = root
    while tortoise != hare:
        tortoise = f(tortoise)
        hare = f(hare)   
    start = tortoise
 
    length = 1
    hare = f(tortoise)
    while tortoise != hare:
        hare = f(hare)
        length += 1
 
    return length, start