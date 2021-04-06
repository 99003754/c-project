
sensor: sensor.out 
sensor.out: display.o mqsender.o sensor.o mqrcvr.o test_sensor.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread -lrt -lm
test_sensor.o: test_sensor.cpp display.h sensor.h source.h
	g++ $< -c
display.o : display.cpp display.h
	g++ $< -c    
sensor.o: sensor.cpp sensor.h source.h
	g++ $< -c 

controller: controller.out 
controller.out : display.o mqsender.o simulation.o mqrcvr.o test_controller.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread -lrt -lm
test_controller.o: test_controller.cpp display.h simulation.h source.h
	g++ $< -c
#display.o : display.cpp display.h
#	g++ $< -c    
simulation.o : simulation.cpp simulation.h source.h
	g++ $< -c



clean:
	rm -rf *.o *.out