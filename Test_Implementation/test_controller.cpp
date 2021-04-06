#include "display.h"
#include "simulation.h"
//#include "sensor.h"
#include <gtest/gtest.h>

TEST(no_Ack, controller)
{
    int16_t data1 = 128;
    simulation obj(data1, 0);
    EXPECT_EQ(sent, obj.send());
    display obj1;
    EXPECT_EQ(success_controller, obj1.receieve());
    EXPECT_EQ(129, obj1.frameid());
    EXPECT_EQ(ACK_REC, obj.receieve_ack());
}
TEST(with_Ack, controller)
{
    int16_t data = 128;
    simulation obj_sim(data, 1);
    display obj_dis;
    EXPECT_EQ(sent, obj_sim.send());

    EXPECT_EQ(success_controller_ack, obj_dis.receieve());
    EXPECT_EQ(12417, obj_dis.frameid());
    EXPECT_EQ(6, obj_dis.ack_check());
    EXPECT_EQ(ACK_NOT_REQ, obj_sim.receieve_ack());
}
TEST(invalid_data, controller)
{
    int16_t data = 280;
    simulation obj_sim1(data, 0);
    EXPECT_EQ(OUT_OF_RANGE, obj_sim1.send());
}




int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
object=display.cpp\
sensor.cpp\
display_main.cpp\
simulation.cpp\
simulation_main.cpp\
sensor_main.cpp

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
mqsender.o\
sensor_main.o

sen1:$(sen)
	g++ $(sen) -o sensor.out -lrt -lm -lpthread

sim=simulation.o\
mqsender.o\
simulation_main.o

sim1:$(sim)
	g++ $(sim) -o sim.out -lrt -lm

object1=display.cpp\
test.cpp\
simulation.cpp
object_files:$(object1)
	g++ $(object1) -c
test_files=display.o\
simulation.o\
test.o\
mqrcvr.o\
mqsender.o
test:$(test_files)
	g++ $(test_files) -lgtest -lgtest_main -lpthread -lrt -lm
clean:
	rm -rf *.o *.out
    */