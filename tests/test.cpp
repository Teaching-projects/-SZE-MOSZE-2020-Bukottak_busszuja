#include "../Jsonparser.cpp"
#include "gtest/gtest.h"


using namespace std;


TEST(Jsontest, Fajlvaltozo) {
	std::ifstream f("Hosarkany.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Hosarkany");
	EXPECT_EQ(beolvasas.getErtek("hp"), "300");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "30");
}

TEST(Jsontest, Szoveg) {
	std::string szoveg = "Sotetvarazslo.json";
	Jsonparser beolvasas(szoveg);
	EXPECT_EQ(beolvasas.getErtek("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.getErtek("hp"), "250");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "40");
}


TEST(Jsontest, Fajlnev) {
	const char * fajlnev = "Arnykiraly.json";
	Jsonparser beolvasas(fajlnev);
	EXPECT_EQ(beolvasas.getErtek("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.getErtek("hp"), "200");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "48");
}







int main(int argc, char ** argv) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}
