#include "../list.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ShoppingList, OutputFormat) {
  std::string unittest_output = "Shopping List:\n1) Milk\n2) Eggs\n3) Flour\n"
                                "4) Sugar\n5) Cocoa Powder\n6) Vanilla\n";
  ASSERT_DURATION_LE(3, { ASSERT_EXECIO_EQ("main", "", unittest_output); });
}

TEST(ShoppingList, DefaultConstructor) {
  ShoppingList your_shopping_list;
  ASSERT_EQ(your_shopping_list.getNumItems(), 0);
  ASSERT_EQ(your_shopping_list.getListSize(), 10);
}

TEST(ShoppingList, NonDefaultConstructor) {
  ShoppingList your_shopping_list(100);
  ASSERT_EQ(your_shopping_list.getNumItems(), 0);
  ASSERT_EQ(your_shopping_list.getListSize(), 100);
}

TEST(ShoppingList, AddItem) {
  ShoppingList your_shopping_list;
  your_shopping_list.addItem("A");
  your_shopping_list.addItem("B");
  your_shopping_list.addItem("C");
  your_shopping_list.addItem("D");
  your_shopping_list.addItem("E");
  your_shopping_list.addItem("F");
  your_shopping_list.addItem("G");
  your_shopping_list.addItem("H");
  your_shopping_list.addItem("I");
  your_shopping_list.addItem("J");
  ASSERT_EQ(your_shopping_list.getNumItems(), 10)
    << "getNumItems() did not correctly track the 10 items that were added.";
  std::string unittest_output = "Error! Shopping List full!\n";
  ASSERT_SIO_EQ("", unittest_output, { your_shopping_list.addItem("K"); });
}

TEST(ShoppingList, RemoveItem) {
  ShoppingList your_shopping_list;
  your_shopping_list.addItem("A");
  your_shopping_list.addItem("B");
  your_shopping_list.addItem("C");
  ASSERT_EQ(your_shopping_list.getNumItems(), 3)
    << "getNumItems() did not correctly track the 3 items that were added.";
  your_shopping_list.removeLast();
  ASSERT_EQ(your_shopping_list.getNumItems(), 2)
    << "getNumItems() did not correctly track that 1 item was removed.";
}

TEST(ShoppingList, PrintList) {
  ShoppingList your_shopping_list;
  your_shopping_list.addItem("A");
  your_shopping_list.addItem("B");
  your_shopping_list.addItem("C");
  your_shopping_list.addItem("D");
  your_shopping_list.addItem("E");
  std::string unittest_output =
      "Shopping List:\n1) A\n2) B\n3) C\n4) D\n5) E\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_SIO_EQ("", unittest_output, { your_shopping_list.printList(); });
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
