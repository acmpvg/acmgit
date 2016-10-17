
a=1
b=1

print("string t[]={",end="")

for i in range(0,100000):
	print (",\""+str(a)[0:40]+"\"",end="")
	a,b = b,a+b
	
print("}")
