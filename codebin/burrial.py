import re
txtx="ther's nothin sure in this world"
x=re.findall(r"\bt\w+",txtx,re.IGNORECASE)
for i in x:
     print(i)
