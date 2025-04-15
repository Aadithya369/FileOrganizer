import re
import facesmash_vit
a="The worlds a cruel place so u better stop showing mercy"
b=re.sub("\s","|",a,100)
print(b)
