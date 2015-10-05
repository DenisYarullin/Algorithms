#include "gtest/gtest.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	//::testing::FLAGS_gtest_death_test_style = "fast";
	//::testing::FLAGS_gtest_death_test_style = "threadsafe";
	std::cout << RUN_ALL_TESTS();
	std::cin.get();
	return 0;
}