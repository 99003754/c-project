object=display.cpp\
sensor.cpp\
display_main.cpp\
simulation.cpp\
simulation_main.cpp

obj: $(object)
	g++ $(object) -c

c=mqrcvr.c\
mqsender.c
obj1:$(c)
	gcc $(c) -c -lm

dis=mqrcvr.o\
	display.o\
	display_main.o

dis1:$(dis)
	g++ $(dis) -o display.out -lrt -lm

sen=sensor.o\
mqsender.o

sen1:$(sen)
	g++ $(sen) -o sensor.out -lrt -lm

sim=simulation.o\
mqsender.o\
simulation_main.o

sim1:$(sim)
	g++ $(sim) -o sim.out -lrt -lm