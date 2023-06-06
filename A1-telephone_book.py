class Client:
    def __init__(self, name, phone_number):
        self.name = name
        self.phone_number = phone_number
 
 
class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]
 
    def hash_function(self, key):
        return sum(ord(char) for char in key) % self.size
 
    def insert(self, client):
        key = client.name
        index = self.hash_function(key)
        self.table[index].append(client)
 
    def search(self, key):
        index = self.hash_function(key)
        comparisons = 0
        for client in self.table[index]:
            comparisons += 1
            if client.name == key:
                return comparisons, client.phone_number
        return comparisons, None
 
 
# Example usage
clients = [
    Client("Jerome Smith", "1234567890"),
    Client("Mike Ross", "0987654321"),
    Client("Thomas Shelby", "9876543210"),
    Client("Harry Lewis", "4567890123"),
]
 
hash_table_chaining = HashTable(10)
hash_table_probing = HashTable(10)
 
# Insert clients into hash tables
for client in clients:
    hash_table_chaining.insert(client)
    hash_table_probing.insert(client)
 
# Search for telephone numbers
search_names = ["Jerome Smith", "Thomas Shelby", "Harry Lewis"]
total_comparisons_chaining = 0
total_comparisons_probing = 0
 
print("Separate Chaining:")
for name in search_names:
    comparisons, phone_number = hash_table_chaining.search(name)
    total_comparisons_chaining += comparisons
    if phone_number:
        print(f"Found {name}: {phone_number}")
    else:
        print(f"{name} not found")
 
print("Linear Probing:")
for name in search_names:
    comparisons, phone_number = hash_table_probing.search(name)
    total_comparisons_probing += comparisons
    if phone_number:
        print(f"Found {name}: {phone_number}")
    else:
        print(f"{name} not found")
 
print("Total comparisons (Separate Chaining):", total_comparisons_chaining)
print("Total comparisons (Linear Probing):", total_comparisons_probing)