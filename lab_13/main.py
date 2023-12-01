def put_in_table(myhash, value, table):
    if table[myhash] == "":
        table[myhash] = value
    else:
        i = 1
        while myhash - i > 0 or myhash + i < (len(table) - 1):
            if myhash + i < (len(table) - 1) and table[myhash + i] == "":
                table[myhash + i] = value
                break

            if myhash - i > 0 and table[myhash - i] == "":
                table[myhash - i] = value
                break
            i += 1


with open("input.txt") as file:
    text = file.read()

words = text.split()
n = 0
for i in ":;\'\".,?!":
    n += text.count(i)
n = len(words) + n
print(n)
table = ["" for i in range(n)]

for i in words:
    temp_hash = 0
    for j in i:
        if j in ":;\'\".,?!":
            myhash = ord(j) % len(table)
            put_in_table(myhash, j, table)
            i = i[:-1]
        temp_hash += ord(j)
    myhash = temp_hash % len(table)
    put_in_table(myhash, i + " " + str(myhash), table)

with open("output.txt", "w") as file:
    for i in range(len(table)):
        temp_string = f"{i} : {table[i]}\n"
        file.write(temp_string)
