test = int(input())
t=0

while t < test:
	a,b,c = input().split(' ')
	a = int(a)
	b = int(b)
	c = int(c)
	
	res = (b+c) % a
	if (res == 0):
		res = a
	print("Case " + str(t+1) + ": " + str(res))
	t+= 1
