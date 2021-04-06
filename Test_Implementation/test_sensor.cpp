#include "display.h"
#include "sensor.h"
#include <gtest/gtest.h>
TEST(no_sof,sensor)
{
    int16_t data=17766;
    sensor obj_sen(data,1,1);
    display object_sensor2;
    EXPECT_EQ(sent,obj_sen.send());
    EXPECT_EQ(17766,obj_sen.frameis());
    EXPECT_EQ(SOF_NOT_PRESENT_sensor,object_sensor2.receieve());
    EXPECT_EQ(0,object_sensor2.frameid());
    data=30958;
    sensor obj_sen2(data,1,1);
    display object_sensor1;
    EXPECT_EQ(sent,obj_sen2.send());
    EXPECT_EQ(30958,obj_sen2.frameis());
    EXPECT_EQ(SOF_NOT_PRESENT_sensor,object_sensor1.receieve());
    EXPECT_EQ(0,object_sensor1.frameid());
}
TEST(with_sof,sensor)
{
    int16_t data=6250;
    sensor obj_sen3(data,1,1);
    display object_sensor3;
    EXPECT_EQ(sent,obj_sen3.send());
    EXPECT_EQ(6250,obj_sen3.frameis());
    EXPECT_EQ(success_sensor,object_sensor3.receieve());
    EXPECT_EQ(6250,object_sensor3.frameid());
    data=7978;
    sensor obj_sen4(data,1,1);
    display object_sensor4;
    EXPECT_EQ(sent,obj_sen4.send());
    EXPECT_EQ(7978,obj_sen4.frameis());
    EXPECT_EQ(success_sensor,object_sensor4.receieve());
    EXPECT_EQ(7978,object_sensor4.frameid());
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}