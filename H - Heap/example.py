class HeapMin:
    def __init__(self):
        self.heap = []

    def insert(self, value):
        self.heap.append(value)
        self.heapify_up(len(self.heap) - 1)

    def extract_min(self):
        if not self.heap:
            raise Exception("Heap is empty")

        min_value = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.heapify_down(0)

        return min_value

    def is_empty(self):
        return not bool(self.heap)

    def size(self):
        return len(self.heap)

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    def heapify_up(self, i):
        while i != 0 and self.heap[self.parent(i)] > self.heap[i]:
            self.swap(i, self.parent(i))
            i = self.parent(i)

    def heapify_down(self, i):
        smallest = i
        left = self.left(i)
        right = self.right(i)

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left

        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != i:
            self.swap(i, smallest)
            self.heapify_down(smallest)

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

# Example usage:

heap = Heap()

heap.insert(10)
heap.insert(20)
heap.insert(30)
heap.insert(5)
heap.insert(7)

while not heap.is_empty():
    print(heap.extract_min(), end=" ")

print()
