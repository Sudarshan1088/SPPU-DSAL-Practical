class HashTable:
    def __init__(self):
        self.m = int(input("Enter size of hash table: "))  # Initialize table size
        self.hashtable = [None] * self.m  # Initialize hash table with None values
        self.elecount = 0  # Track number of elements in table
        print(self.hashtable)

    def hashfunction(self, key):
        return key % self.m  # Basic hash function

    def isfull(self):
        return self.elecount == self.m  # Check if the table is full

    def linearprobr(self, key, data):
        index = self.hashfunction(key)
        compare = 0
        while self.hashtable[index] is not None:
            index = (index + 1) % self.m  # Linear probing
            compare += 1
        self.hashtable[index] = [key, data]  # Insert data
        self.elecount += 1
        print("Data inserted at index", index)
        print(self.hashtable)
        print("Number of comparisons:", compare)

    def getline(self, key, data):
        index = self.hashfunction(key)
        while self.hashtable[index] is not None:
            if self.hashtable[index] == [key, data]:  # Check for matching key and data
                return index
            index = (index + 1) % self.m
        return None  # Return None if not found

    def quadraticprobr(self, key, data):
        index = self.hashfunction(key)
        compare = 0
        i = 1
        while self.hashtable[index] is not None:
            index = (index + i * i) % self.m  # Quadratic probing
            compare += 1
            i += 1
        self.hashtable[index] = [key, data]  # Insert data
        self.elecount += 1
        print("Data inserted at index", index)
        print(self.hashtable)
        print("Number of comparisons:", compare)

    def getQuadratic(self, key, data):
        index = self.hashfunction(key)
        i = 1
        while self.hashtable[index] is not None:
            if self.hashtable[index] == [key, data]:  # Check for matching key and data
                return index
            index = (index + i * i) % self.m
            i += 1
        return None  # Return None if not found

    def insertvialinear(self, key, data):
        if self.isfull():
            print("Table is full")
            return False
        index = self.hashfunction(key)
        if self.hashtable[index] is None:
            self.hashtable[index] = [key, data]
            self.elecount += 1
            print("Data inserted at index", index)
            print(self.hashtable)
        else:
            print("Collision occurred, applying linear probing")
            self.linearprobr(key, data)

    def insertviaQuadratic(self, key, data):
        if self.isfull():
            print("Table is full")
            return False
        index = self.hashfunction(key)
        if self.hashtable[index] is None:
            self.hashtable[index] = [key, data]
            self.elecount += 1
            print("Data inserted at index", index)
            print(self.hashtable)
        else:
            print("Collision occurred, applying quadratic probing")
            self.quadraticprobr(key, data)


def menu():
    obj = HashTable()
    while True:
        print("\n*********")
        print("1. Linear Probe")
        print("2. Quadratic Probe")
        print("3. Exit")
        print("*********")
        ch = int(input("Enter choice: "))

        if ch == 1:
            while True:
                print("\n** Linear Probing Menu **")
                print("1. Insert")
                print("2. Search")
                print("3. Back to Main Menu")
                ch2 = int(input("Enter your choice: "))
                if ch2 == 1:
                    a = int(input("Enter phone number (key): "))
                    b = input("Enter name: ")
                    obj.insertvialinear(a, b)
                elif ch2 == 2:
                    k = int(input("Enter key to be searched: "))
                    b = input("Enter name: ")
                    f = obj.getline(k, b)
                    if f is None:
                        print("Key not found")
                    else:
                        print("Key found at index", f)
                elif ch2 == 3:
                    break

        elif ch == 2:
            while True:
                print("\n** Quadratic Probing Menu **")
                print("1. Insert")
                print("2. Search")
                print("3. Back to Main Menu")
                ch2 = int(input("Enter your choice: "))
                if ch2 == 1:
                    a = int(input("Enter phone number (key): "))
                    b = input("Enter name: ")
                    obj.insertviaQuadratic(a, b)
                elif ch2 == 2:
                    k = int(input("Enter key to be searched: "))
                    b = input("Enter name: ")
                    f = obj.getQuadratic(k, b)
                    if f is None:
                        print("Key not found")
                    else:
                        print("Key found at index", f)
                elif ch2 == 3:
                    break

        elif ch == 3:
            print("Exiting Program.")
            break

menu()
