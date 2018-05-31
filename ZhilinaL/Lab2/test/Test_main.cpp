#include <gtest.h>
#include <cstdlib>
#include <conio.h>
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}