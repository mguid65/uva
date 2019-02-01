import sys

cache = list()
cache.append(0)
cache.append(1)

def fib(n):
  if n < len(cache):
    return cache[n]
  i = len(cache) - 1
  while i < n:
    i += 1
    cache.append(cache[i-1] + cache[i-2])
  return cache[i]

for n in sys.stdin:
  if n != '\n':
    print('The Fibonacci number for ' + n[:-1] + ' is ' +  str(fib(int(n))))
