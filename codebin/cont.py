def count():
    a=open('counting.txt','r')
    b=a.read()
    m=b.split()
    c=0
    for i in m:
        if i=='lorry':
            c=c+1
            print(c)
count()
