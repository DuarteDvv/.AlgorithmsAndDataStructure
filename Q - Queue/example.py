class Queue:
    def __init__(self):
        self.data = []

    def enqueue(self, value):
        self.data.append(value)

    def dequeue(self):
        if not self.is_empty():
            return self.data.pop(0)
        else:
            raise Exception("Queue is empty!")

    def is_empty(self):
        return len(self.data) == 0

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)

print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
