import math

class list_node( object ):
  def __init__( self ):
    self.next    = None
    self.element = None

class linked_list( object ):
  def __init__( self ):
    self.head = None

  def push( self, element ):
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

  def peak( self, index ):
    if self.head:
      h = self.head
      while index != 1 and h != None:
        h = h.next
        index -= 1
      return h.element

  def empty( self ):
    return self.head == None

  def size( self ):
    s = 0
    n = self.head
    while n != None:
      s += 1
      n = n.next
    return s

  def show( self ):
    l = []
    n = self.head
    while not n == None:
      l.append(n.element)
      n = n.next
    return l

hi = linked_list( )
lo = linked_list( )

def increment( D ): 
  D[0] += 1  
  if D[0]   == 1 and lo.peak( 1 ) != 0: lo.push( 0 ) 
  elif D[0] == 2: lo.pop( )  
  if D[0] == 3: D = fix( D, 0 )
  else:
    j = hi.pop( )
    if not j == None:
      D = fix( D, j  )
  return D

def fix( D, j ):
  D[j] -= 3
  if j != 0:
    if D[j-1] <= 1: lo.pop( )
    D[j-1] += 2  
  if len( D ) - 1 <= j: D.append( 0 ) # grow list
  D[j+1] += 1  
  if D[j+1] == 1 and not lo.peak( 1 ) == j + 1:
    lo.push( j + 1 )
  elif D[j+1] == 2:
    lo.pop()
  elif D[j+1] == 3:
    hi.push( j + 1  )
  if j != 0:
    if D[j-1] >= 3: hi.push( j-1 )
  if D[j] <= 1: lo.push( j )
  return D

def decrement( D ):
  if not is_idle( D ):
    if get_state( D ) == '22':
      if not hi.empty() and D[hi.peak( 1 )] == 3:
        j = lo.pop( )
        D = unfix( D, j )
    else:
      j = lo.pop( )
      if not j == None:
        D = unfix( D, j  )
  D[0] -= 1
  if D[0] == 2: hi.pop( )
  elif D[0] <= 1 and lo.peak( 1 ) != 0: lo.push( 0 )

  return D

def unfix( D, j ):
  # shrink list
  D[j+1] -= 1
  l = len( D )
  if j + 1 == l - 1 and D[l-1] == 0: 
    lo.pop()
    D.pop()
  else:
    if D[j+1] == 1:
      lo.push( j + 1 )
    elif D[j+1] == 2:
      hi.pop( )
  if j != 0: 
    if D[j-1] >= 3:
      hi.pop( )
    D[j-1] -= 2
    if D[j-1] <= 1 and not j - 1 == 0:
      lo.push( j - 1 )
  D[j] += 3
  if D[j] >= 3: hi.push( j )

  return D

def get_state( D ):
  if len( D ) < 2:
    return str(D[0])
  else:
    return str(D[0]) + str(D[1])

def is_idle( D ):
  # idle state 21t
  if get_state( D ) == '21':
    return True
  elif get_state( D ) == '12': 
    # 12a
    if not hi.empty( ):
      return False
    else:
      if lo.size( ) == 1 or lo.peak( 2 ) == len(D) - 1:
        return True
      else:
        return False
  else:
    return False

def value_of( S ):
  n = 0
  for i ,s in enumerate( S ):
    n += s * ((2**(i+1)) - 1)
  return n

def high( D ):
  h = next((x for x in D if x == 3 or x == 4), False)
  return h

D = [2,1]
n = 100000
print("------------------------------------ INC")
print( str( value_of(D) ) + ": " + str(D) )
for i in range( 0, n - 5 ):
  D = increment( D )
  print( str( value_of(D) ) + ": " + str(D) )

print("------------------------------------")
print( str( value_of(D) ) + ": " + str(D) )
print(hi.show())
print(lo.show())

print("------------------------------------ DEC")
for i in range( 0, n - 5 ):
  D = decrement( D )
  print( str( value_of(D) ) + ": " + str(D) )

print("------------------------------------")
print( str( value_of(D) ) + ": " + str(D) )
print(hi.show())
print(lo.show())

print( "--Program magic_skew--" )
