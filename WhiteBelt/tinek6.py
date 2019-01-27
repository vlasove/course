
memo = {}  

str = input()

def rec(i, depth):
  if i < len(str):
    if (i, depth) in memo: return memo[i, depth]  

    c = str[i]
    cnt = 0
    if c == '(' or c == '?':
      cnt += rec(i+1, depth+1)
    if c == ')' or c == '?':
      if depth >= 1:
        cnt += rec(i+1, depth-1)

    memo[i, depth] = cnt                          
    return cnt

  else:

    if depth != 0: return 0
    return 1

print (rec(0, 0))