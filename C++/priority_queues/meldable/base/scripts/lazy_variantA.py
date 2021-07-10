import math
from timeit import Timer
import cProfile


class list_node( object ):
  def __init__( self ):
    self.next    = None
    self.element = None

class linked_list( object ):
  def __init__( self ):
    self.head = None

  def append( self, element ):
    n          = list_node( )
    n. element = element
    n.next     = self.head
    self.head  = n

  def pop( self ):
    n = self.head
    if n:
      self.head = n.next
      n.next = None
    
      return n.element

  def empty( self ):
    return self.head == None

  def size( self ):
    s = 0
    n = self.head
    while n != None:
      s += 1
      n = n.next
    return s

  def gather( self ):
    l = []
    n = self.head
    while not n == None:
      l.append(n.element)
      n = n.next
    return l

def size( L ):
  s = 0
  for i in range(0, len(L)):
    s = s + L[i]
  return s

def collect( A, L):
  for t in L:
    A[math.floor(math.log(t,2))].append(t)
  return A
  
def cons_alg_a(A):
  i = 0
  b = 0
  while(True):
    print( A )
    while(len(A[i]) > 2):
      if(i == 0):
        h = A[i].pop() + A[i].pop() + A[i].pop() - 1
        A[i+1].append(h)
      elif(len(A[i]) > 2):
        e = A[i].pop() + A[i].pop() - i
        w = ( A[i].pop() - 1 ) #// 2
        A[i-1].append( w )
        A[i-1].append( w )
        A[i+1].append( e )
        if( len(A[i-1]) > 2 ):
          b = 1
    if(i == len( A ) - 1 ):
      break
    elif( b == 1):
      i = i - 1
      b = 0
    else:
      i = i + 1
  return A  

def cons_alg_b(A, L):
  def rec(A, i):
    if( len(A[i]) < 3):
      return
    else:
      e = A[i].pop() + A[i].pop() + 1
      w = (A[i].pop() - 1) // 2
      A[i-1].append(w)
      A[i-1].append(w)
      A[i+1].append(e)
      rec(A, i - 1)
      rec(A, i + 1)
  for h in L:
    i = math.floor(math.log(h,2)) 
    A[i].append(h)
    if(len(A[i]) == 3):
      if(i == 0):
        h = A[0].pop() + A[0].pop() + A[0].pop()
        A[1].append(h)
        rec(A, 1)
      else: rec(A, i)
  return A

def cons_alg_inp(A, L):
  pass

L = []
P = []
Q = [1,1,1,1,1,1,1,1,1,15,15,15,1,1,1,1,32767,32767,1,1,1,1023,1023,1023,2047,2047,4095,4095,4095,4095,4095]

Li = linked_list()

for i in range(0,1000):
  Li.append(1)

for i in range(0,1000):
  L.append(1)

for i in range(0,100):
  P.append(10)

print("----------------------------")

# Alloc Array

A = []
for i in range(0, math.floor(math.log(size(P), 2))):
  A.append([])
print(cons_alg_a(collect(A, P)))
#cProfile.run( 'cons_alg_a(collect(A, L))' )

'''
A = []
for i in range(0, math.floor(math.log(size(Q), 2)-1)):
  A.append([])

R = cons_alg_b(A, Q)
print( R )
'''
'''
hh = 0
for l in R:
  for t in l:
    hh = hh + math.floor(math.log(t,2)) + 1

print(hh)
print(hh-10000000)
'''


#cProfile.run( 'cons_alg_b(A, L)' )

'''
A = []
for i in range(0, math.floor(math.log(size(L), 2)-1)):
  A.append([])
#print(cons_alg_inp(A, Q))
'''
