#include "../JSON.cpp"
#include "gtest/gtest.h"




TEST(Jsontest, Fajlvaltozo) {
	std::ifstream f("Hosarkany.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Hosarkany");
	EXPECT_EQ(beolvasas.getErtek("health_points"), "300");
	EXPECT_EQ(beolvasas.getErtek("damage"), "30");
	EXPECT_EQ(beolvasas.getErtek("attack_cooldown"),"2.4");
}

TEST(Jsontest, Szoveg) {
	std::string szoveg = "Sotetvarazslo.json";
	JSON beolvasas = JSON::parseFromFile(szoveg);
	EXPECT_EQ(beolvasas.getErtek("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.getErtek("health_points"), "250");
	EXPECT_EQ(beolvasas.getErtek("damage"), "40");
	EXPECT_EQ(beolvasas.getErtek("attack_cooldown"),"2.0");
}


TEST(Jsontest, Fajlnev) {
        const char * fajlnev="Arnykiraly.json";
	JSON beolvasas = JSON::parseFromFile(fajlnev);
	EXPECT_EQ(beolvasas.getErtek("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.getErtek("health_points"), "200");
	EXPECT_EQ(beolvasas.getErtek("damage"), "48");
	EXPECT_EQ(beolvasas.getErtek("attack_cooldown"),"2.3");
}







int main(int argc, char ** argv) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}