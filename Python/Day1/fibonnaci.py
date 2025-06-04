f1 = 1
f2 = 2
f3 = f1 + f2
print(f1, f2)

for i in range(2,20):
    f1 = f2
    f2 = f3
    f3 = f1 + f2
    print(f3)       
