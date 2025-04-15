class SJTG16:
    def __init__(self,present,absent):
        self.present=present
        self.absent=absent
a=int(input("enter presentees:"))
b=int(input("enter absentees:"))
G16=SJTG16(a,b)
print(G16.present)
print(G16.absent)
