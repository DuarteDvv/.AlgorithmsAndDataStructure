class Vector:
    def __init__(self, arr=None, capacity=1, size=0, mod_count=0):
        if arr is None:
            self.arr = [0] * capacity
        else:
            self.arr = arr
        self.capacity = capacity
        self.size = size
        self.mod_count = mod_count

    def __init__(self, other):
        self.arr = other.arr
        self.capacity = other.capacity
        self.size = other.size
        self.mod_count = other.mod_count
        self.arr = [0] * self.capacity
        self.arr[:self.size] = other.arr[:self.size]

    def __eq__(self, other):
        if self.size != other.size:
            return False
        for i in range(self.size):
            if self.arr[i] != other.arr[i]:
                return False
        return True

    def push_back(self, value):
        if self.size == self.capacity:
            self.capacity *= 2
            new_arr = [0] * self.capacity
            self.arr = new_arr
        self.arr[self.size] = value
        self.size += 1
        self.mod_count += 1

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        for i in range(index, self.size - 1):
            self.arr[i] = self.arr[i + 1]
        self.size -= 1
        self.mod_count += 1

    def at(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of range")
        return self.arr[index]

    def size(self):
        return self.size

    def get_mod_count(self):
        return self.mod_count

v1 = Vector()
v1.push_back(10)
v1.push_back(20)
v1.push_back(30)

v2 = Vector(v1)
v3 = v1

for i in range(v1.size()):
    print(v1.at(i), end=" ")
print()

v1.remove(1)

for i in range(v1.size()):
    print(v1.at(i), end=" ")
print()

print(v1.get_mod_count())
print(v2.get_mod_count())
print(v3.get_mod_count())

v4 = Vector(v1)
v4.remove(0)

print(v1.get_mod_count())
print(v4.get_mod_count())
