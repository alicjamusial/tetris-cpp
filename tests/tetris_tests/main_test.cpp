//
// Created by Alicja on 2020-03-19.
//

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(main_test, test_eq) {
  EXPECT_EQ(1, 0);
}
