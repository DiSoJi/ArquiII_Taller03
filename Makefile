CFLAGS= -msse4 -msse2 


all: 
	make hello
	make maxVal
	make matMult
	@echo "All Executables Ready. Run them using ./<exec_name>"

hello:
	$(CC) hello_simd.c -o hello $(CFLAGS)
	@echo "hello Ready"

maxVal:
	$(CC) maxVal_simd.c -o maxVal $(CFLAGS)
	@echo "maxVal Ready"

matMult:
	$(CC) matMult_simd.c -o matMult $(CFLAGS)
	@echo "mult Ready"


clean:
	rm hello maxVal matMult
	@echo "Executables removed"