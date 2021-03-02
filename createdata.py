import random
# Bai 3
with open("./Bai3_Text.txt","w") as f:
    for i in range(1, 500000):
        f.write(str(random.randint(1,100)) + " ")
# Bai 3 Test
# with open("./Bai3_Text.txt", "r") as f:
#     data = f.read()
#     parse_data = data.split(" ")
#     sum = 0
#     for num in parse_data:
#         try:
#             sum += int(num)
#         except:
#             print("Error: ", num)
#     print(sum)
# Bai 4
with open("./Bai4_Text.txt","w") as f:
    for i in range(1, 1000000):
        f.write(str(random.randint(1,1000)) + " ")

# Bai 5
# with open("./Bai5_A.txt","w") as f:
#     for i in range(1, 1000000):
#         f.write(str(random.randint(1,1000)) + " ")
# with open("./Bai5_B.txt","w") as f:
#     for i in range(1, 1000000):
#         f.write(str(random.randint(1,1000)) + " ")

# Bai 6
# with open("./Bai6_A.txt","w") as f:
#     for i in range(1, 1000000):
#         f.write(str(random.randint(1,1000)) + " ")
# with open("./Bai6_B.txt","w") as f:
#     for i in range(1, 1000000):
#         f.write(str(random.randint(1,1000)) + " ")

# Bai 8
# 8000000x8 8x1
with open("./Bai8MxN_1.txt","w") as f:
    for i in range(0, 8000000):
        for j in range(0, 8):
            f.write(str(random.randint(1,20)) + " ")
        f.write("\n")
with open("./Bai8Nx1_1.txt","w") as f:
    for i in range(0, 8):
        for i in range(0, 1):
            f.write(str(random.randint(1,20)) + " ")
        f.write("\n")

# 8000x8000 8000x1
with open("./Bai8MxN_2.txt","w") as f:
    for i in range(0, 8000):
        for j in range(0, 8000):
            f.write(str(random.randint(1,20)) + " ")
        f.write("\n")
with open("./Bai8Nx1_2.txt","w") as f:
    for i in range(0, 8000):
        for i in range(0, 1):
            f.write(str(random.randint(1,20)) + " ")
        f.write("\n")

# 8x8000000 8000000x1
with open("./Bai8MxN_3.txt","w") as f:
    for i in range(0, 8):
        for j in range(0, 8000000):
            f.write(str(random.randint(1,20)) + " ")
        f.write("\n")
with open("./Bai8Nx1_3.txt","w") as f:
    for i in range(0, 8000000):
        for i in range(0, 1):
            f.write(str(random.randint(1,20)) + " ")
        f.write("\n")