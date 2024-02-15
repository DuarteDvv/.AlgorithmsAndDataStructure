class HashTable:
    def __init__(self):
        self.table = [[] for _ in range(10)]

    def is_empty(self):
        return all(not cell for cell in self.table)

    def hash_function(self, key):
        hash_value = sum(ord(character) for character in key)
        return hash_value % 10

    def add(self, key, value):
        hash_value = self.hash_function(key)
        cell = self.table[hash_value]
        for elem in cell:
            if elem[0] == key:
                elem[1] = value
                print('[WARNING] Key exists, value replaced.')
                return
        cell.append([key, value])

    def recover(self, key):
        hash_value = self.hash_function(key)
        cell = self.table[hash_value]
        for elem in cell:
            if elem[0] == key:
                return elem[1]
        print('[WARNING] Key not found.')
        return None

    def remove(self, key):
        hash_value = self.hash_function(key)
        cell = self.table[hash_value]
        for elem in cell:
            if elem[0] == key:
                cell.remove(elem)
                print('[INFO] Key deleted.')
                return
        print('[WARNING] Key not found, not deleted.')

    def print_table(self):
        for i, cell in enumerate(self.table):
            if not cell:
                continue
            print(f'{i}: {", ".join(f"{key}:{value}" for key, value in cell)}')
