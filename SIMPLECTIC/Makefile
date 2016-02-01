.PHONY:graficar 
graficar: 
	cc leapfrog.c
	./a.out	
	python lee.py osc_y.dat T Y Position
	python lee.py osc_v.dat T V Velocity
clean:
	rm osc.dat *~ a.out
