import numpy as np
#from mpl_toolkits.mplot3d import Axes3D
#from matplotlib import cm
#from matplotlib.ticker import LinearLocator, FormatStrFormatter
import matplotlib.pyplot as plt
import sys


lectura=str(sys.argv[1])
archivo=open(lectura).read().split("\n")

x=[]
y=[]

for i in range(len(archivo)-1):
    a= archivo[i].split()
    #print a
    x.append(a[0])
    y.append(a[1])
    

print len(x),len(y)

X="$ "+ str(sys.argv[-3]) + " $"
Y="$ "+ str(sys.argv[-2]) + " $"
Title= "$ "+ str(sys.argv[-1])+ " $"

plt.plot(x,y,".")
plt.xlabel(X,size=20)
plt.ylabel(Y,size=20)
plt.title(Title)
plt.show()
plt.savefig("grafica.png")
plt.close()
