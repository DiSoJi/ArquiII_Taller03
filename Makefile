CFLAGS= -msse4 -msse2 
HELLO= hello
MAX= maxVal
#MULT= matMult


all: 
	make hello
	make max
	#make mult
	@echo "All Executables Ready. Run them using ./<exec_name>"

hello:
	$(CC) $(HELLO)_simd.c -o $(HELLO)
	@echo "hello Ready"

max:
	$(CC) $(MAX)_simd.c -o $(MAX)
	@echo "maxVal Ready"

#mult:
#	$(CC) $(MULT)_simd.c -o $(MULT) $(CFLAGS)
#	@echo "mult Ready"


clean:
	rm $(HELLO) $(MAX) $(MULT)
	@echo "Executables removed"