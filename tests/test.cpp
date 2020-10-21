#include "../Jsonparser.cpp"
#include "gtest/gtest.h"


using namespace std;


TEST(Jsontest, Fajlvaltozo) {
	Jsonparser eredmeny("Hosarkany", "300", "30");
	std::ifstream f("Hosarkany.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(eredmeny == beolvasas, true);
}

TEST(Jsontest, Szoveg) {
	Jsonparser eredmeny("Sotetvarazslo", "250", "40");
	std::string szoveg = "Sotetvarazslo.json";
	Jsonparser beolvasas(szoveg);
	EXPECT_EQ(eredmeny == beolvasas, true);
}


TEST(Jsontest, Fajlnev) {
	Jsonparser eredmeny("Arnykiraly", "200", "48");
	const char * fajlnev = "Arnykiraly.json";
	Jsonparser beolvasas(fajlnev);
	EXPECT_EQ(eredmeny == beolvasas, true);
}







int main(int argc, char ** argv) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}
