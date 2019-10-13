#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

TEST(TuffyPrinter, OutputFormat)
{
   std::string unittest_output = "Welcome to Tuffy Printing services.\n"
                          "How many pages do you need printed? "
                          "Select a printing quality from the list:\n"
                          " D - draft, $0.10 per page\n"
                          " M - medium quality, $0.15 per page\n"
                          " H - high quality, $0.20 per page\n"
                          "Quality: Total cost: $9.00\n";
   ASSERT_EXECIO_EQ("main", "45 h", unittest_output);
}

TEST(TuffyPrinter, ValidQuality)
{
   srand (time(NULL));
   for(int i = 0; i < 10; i++)
   {
     int num_pages = rand() % 5000 + 1;
     char quality_types[6] = {'D', 'd', 'M', 'm', 'H', 'h'};
     char quality = quality_types[rand() %6];
     double cost = 0;
     std::string input = std::to_string(num_pages) + " " + std::string(1, quality);
     switch(quality) {
       case 'd':
       case 'D':
         cost = num_pages * 0.10;
         break;
       case 'm':
       case 'M':
         cost = num_pages * 0.15;
         break;
       case 'h':
       case 'H':
         cost = num_pages * 0.20;
         break;
     }
     std::string unittest_output = "Welcome to Tuffy Printing services.\n"
                            "How many pages do you need printed? "
                            "Select a printing quality from the list:\n"
                            " D - draft, $0.10 per page\n"
                            " M - medium quality, $0.15 per page\n"
                            " H - high quality, $0.20 per page\n"
                            "Quality: ";
     unittest_output += "Total cost: $" + to_string_double(cost) + "\n";
     ASSERT_EXECIO_EQ("main", input, unittest_output);
   }
}

TEST(TuffyPrinter, InValidQuality)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    int num_pages = rand() % 100 + 1;
    char quality;

    // Ensure special characters that need escaping are not used.
    do {
      quality = (char)(rand()%93+33);
    } while (quality == 34 || quality == 92 || quality == 96
             || quality == 68 || quality == 100 || quality == 77
             || quality == 109 || quality == 72 || quality == 104);

   std::string input = std::to_string(num_pages) + " " + std::string(1, quality);
   std::string unittest_output = "Welcome to Tuffy Printing services.\n"
                          "How many pages do you need printed? "
                          "Select a printing quality from the list:\n"
                          " D - draft, $0.10 per page\n"
                          " M - medium quality, $0.15 per page\n"
                          " H - high quality, $0.20 per page\n"
                          "Quality: ";
   unittest_output += "Invalid quality. Please try again.\n";

   ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
