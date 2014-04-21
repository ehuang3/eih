#include <iostream>
#include <gtest/gtest.h>
#include <eih/camera/PointGreyCamera.h>

/* ********************************************************************************************* */
TEST(POINT_GREY, CONNECT) {
	PointGreyCamera camera;
}
/* ********************************************************************************************* */
TEST(POINT_GREY, GRAB_IMAGE) {
}
/* ********************************************************************************************* */
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/* ********************************************************************************************* */
