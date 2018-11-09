import sys

for line1 in sys.stdin:
  if line1 == 0:
    break
  for line2 in sys.stdin:
    print(int(line1) * int(line2))
