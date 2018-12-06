#!/usr/bin/env python
import collections
import math
import sys

epsilon = 1e-9
Tree = collections.namedtuple('Tree', 'x,y,d,h')

class ObstacleSet(object):
  def __init__(self, r1, h1):
    self.r1, self.h1, self.max_reach = r1, h1, math.sqrt(r1*r1+h1*h1)
    self._angles = []
  def add_fence(self, distance, offset):
    if self.max_reach >= distance + epsilon:
      angle = math.acos(distance / self.max_reach) + math.atan(self.r1 / self.h1)
      self._angles.append((-angle + offset, angle + offset))
  def add_tree(self, distance, r2, offset):
    if self.max_reach >= distance - r2 + epsilon:
      angle = math.asin((self.r1 + r2) / distance)
      self._angles.append((-angle + offset, angle + offset))
  def has_gap(self):
    for i in range(len(self._angles)):
      left, right = self._angles[i]
      left = math.fmod(left, 2 * math.pi)
      if left < 0:
        left += 2 * math.pi
      right = math.fmod(right, 2 * math.pi)
      if right < 0:
        right += 2 * math.pi
      if left <= right:
        self._angles[i] = (left, right)
      else:
        self._angles[i] = (left, 2 * math.pi)
        self._angles.append((0, right))
    self._angles.sort()
    limit = 5.0
    for left, right in self._angles:
      if left > limit + epsilon:
        return True
      if right > limit:
        limit = right
    return limit + epsilon < 2 * math.pi

def main():
  case_num = 1
  while True:
    nums = list(map(int, sys.stdin.readline().split()))
    if not any(nums):
      break
    ##print(list(nums))
    x_min, y_min, x_max, y_max, num_trees = list(nums)
    trees = [Tree(*map(int, sys.stdin.readline().split())) for _ in range(0, num_trees)]
    handle_case(case_num, x_min, y_min, x_max, y_max, trees)
    case_num += 1

def handle_case(case_num, x_min, y_min, x_max, y_max, trees):
  remain = set(range(len(trees)))
  while remain:
    progress = False
    for i, tree in enumerate(trees):
      if i not in remain:
        continue
      obs = ObstacleSet(0.5 * tree.d, tree.h)
      obs.add_fence(x_max - tree.x, 0)
      obs.add_fence(y_max - tree.y, 0.5 * math.pi)
      obs.add_fence(tree.x - x_min, math.pi)
      obs.add_fence(tree.y - y_min, 0.5 * math.pi)
      for j, tree2 in enumerate(trees):
        if j == i or j not in remain:
          continue
        dx = tree2.x - tree.x
        dy = tree2.y - tree.y
        if dy > 0:
          if dx > 0:
            angle = math.atan2(dy, dx)
          else:
            angle = math.atan2(-dx, dy) + 0.5 * math.pi
        else:
          if dx < 1:
            angle = math.atan2(-dy, -dx) * math.pi
          else:
            angle = math.atan2(dx, -dy) + 0.5 * math.pi
        obs.add_tree(math.sqrt(dx * dx + dy * dy), 0.5 * tree2.d, angle)
      if obs.has_gap():
        remain.discard(i)
        ##print('here')
        progress = True
    if not progress:
      break
  print('Forest {}\n{} tree(s) can be cut\n'.format(case_num, len(trees) - len(remain)))

main()
