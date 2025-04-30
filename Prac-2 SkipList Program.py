import random

class Node:
    def __init__(self, key, level):
        self.key = key
        self.forward = [None] * (level + 1)

class SkipList:
    def __init__(self, max_level, prob):
        self.max_level = max_level
        self.prob = prob
        self.header = self.create_node(self.max_level, -1)
        self.level = 0

    def create_node(self, level, key):
        return Node(key, level)

    def random_level(self):
        level = 0
        while random.random() < self.prob and level < self.max_level:
            level += 1
        return level

    def insert(self, key):
        update = [None] * (self.max_level + 1)
        current = self.header

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current

        current = current.forward[0]

        if current is None or current.key != key:
            rlevel = self.random_level()

            if rlevel > self.level:
                for i in range(self.level + 1, rlevel + 1):
                    update[i] = self.header
                self.level = rlevel

            new_node = self.create_node(rlevel, key)
            for i in range(rlevel + 1):
                new_node.forward[i] = update[i].forward[i]
                update[i].forward[i] = new_node

    def display(self):
        print("Skip List:")
        for i in range(self.level + 1):
            print("Level", i, ":", end=" ")
            node = self.header.forward[i]
            while node:
                print(node.key, end=" ")
                node = node.forward[i]
            print()

# Example use
s = SkipList(3, 0.5)
s.insert(3)
s.insert(6)
s.insert(7)
s.insert(9)
s.insert(12)
s.insert(19)
s.insert(17)
s.insert(26)
s.insert(21)
s.insert(25)

s.display()
