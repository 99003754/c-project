all: all.out 
all.out : display.o mqsender.o simulation.o mqrcvr.o test.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread -lrt -lm
box-test.o: test.cpp display.h simulation.h source.h
	g++ $< -c
wcbox.o : display.cpp display.h
	g++ $< -c    
box.o : simulation simulation.h source.h
	g++ $< -c
run:	all.out
	./$(all).out
clean:
	rm -rf *.o *.out
