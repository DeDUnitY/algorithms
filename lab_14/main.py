def put_in_table(myhash, value, table):
    table[myhash].append(value)


with open("input.txt") as file:
    text = file.read()

words = text.split()
table = [[] for i in range(len(words))]

for i in words:
    temp_hash = 0
    for j in i:
        if j in ":;\'\".,?!":
            myhash = ord(j) % len(table)
            put_in_table(myhash, j, table)
            i = i[:-1]
        temp_hash += ord(j)
    myhash = temp_hash % len(table)
    put_in_table(myhash, i, table)

with open("output.txt", "w") as file:
    for i in range(len(table)):
        temp_string = f"{i} : "
        for j in table[i]:
            temp_string += str(j) + ", "
        temp_string += "\n"
        file.write(temp_string)
