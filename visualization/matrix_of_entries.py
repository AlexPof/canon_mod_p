import numpy as np
import matplotlib.pyplot as plt

########################
###### MAIN ######
########################

N=625
P=5
M = np.zeros((N-1,N))


with open("s"+str(N)+"-mod"+str(P)+".txt","r") as f:
	for i,x in enumerate(f):
		if (i>1) and not (("***" in x) or ("Final" in x)):
			p = int(x)
			M[p//N,p-N*(p//N)]=M[p//N,p-N*(p//N)]+1
			

plt.figure(figsize=(12,12))
plt.imshow(M,interpolation="None",cmap="Greys_r")
plt.axis('off')
plt.savefig("s"+str(N)+"-mod"+str(P)+".jpg",dpi=150)
plt.show()