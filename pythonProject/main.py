import random

print("Random integer: ", random.randint(0, 100))
print("Random float: ", random.random())
print("Random boolean: ", random.choice([True, False]))
print("Random string: ", ''.join(random.choices('abcdefghijklmnopqrstuvwxyz', k=10)))
print("Random list: ", random.sample(range(10), 5))
print("Random tuple: ", tuple(random.sample(range(10), 5)))
print("Random set: ", set(random.sample(range(10), 5)))
print("Random dictionary: ", {random.randint(0, 10): random.random() for _ in range(5)})