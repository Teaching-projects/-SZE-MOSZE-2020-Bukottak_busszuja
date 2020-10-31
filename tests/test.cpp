#include "../Jsonparser.cpp"
#include "gtest/gtest.h"


using namespace std;

TEST(Jsonparsertest, Fajlvaltozo) {
	std::ifstream f("Hosarkany.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Hosarkany");
	EXPECT_EQ(beolvasas.getErtek("hp"), "300");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "30");
	EXPECT_EQ(beolvasas.getErtek("speed"), "2.4");
}

TEST(Jsonparsertest, Szoveg) {
	std::string szoveg = "Sotetvarazslo.json";
	Jsonparser beolvasas(szoveg);
	EXPECT_EQ(beolvasas.getErtek("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.getErtek("hp"), "250");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "40");
	EXPECT_EQ(beolvasas.getErtek("speed"), "2.0");
}


TEST(Jsonparsertest, Fajlnev) {
	const char * fajlnev = "Arnykiraly.json";
	Jsonparser beolvasas(fajlnev);
	EXPECT_EQ(beolvasas.getErtek("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.getErtek("hp"), "200");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "48");
	EXPECT_EQ(beolvasas.getErtek("speed"), "2.3");
}
TEST(Jsontest, Whitespace_test) {
	std::ifstream f("Atoksarkany.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Atoksarkany");
	EXPECT_EQ(beolvasas.getErtek("hp"), "260");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "45");
	EXPECT_EQ(beolvasas.getErtek("speed"), "1.7");
}

TEST(Jsontest, Kulcssorrend_test) {
	std::ifstream f("Kardvadasz.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Kardvadasz");
	EXPECT_EQ(beolvasas.getErtek("hp"), "280");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "48");
	EXPECT_EQ(beolvasas.getErtek("speed"), "2.1");
}

TEST(Jsontest, Idezojelfuggetlenseg_test) {
	std::ifstream f("Arnykiraly.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.getErtek("hp"), "200");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "48");
	EXPECT_EQ(beolvasas.getErtek("speed"), "2.3");
}

TEST(Jsontest, Tobb_kevesebb_idozejel_test) {
	std::ifstream f("Sotetvarazslo.json");
	Jsonparser beolvasas(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.getErtek("hp"), "250");
	EXPECT_EQ(beolvasas.getErtek("dmg"), "40");
	EXPECT_EQ(beolvasas.getErtek("speed"), "2.0");
}
TEST(Maintest, Nem_letezo_fajl_test) {
	std::ifstream f("Lathatatlan.json");
	try {
		Jsonparser f1(f);
	}
	catch (int e) {
		EXPECT_EQ(e, MYFILEERROR);
	}
}


TEST(Maintest, Tobb_kevesebb_adat_test) {
	std::ifstream f("Exodia.json");
	try {
		Jsonparser f1(f);
	}
	catch (int e) {
		EXPECT_EQ(e, INVALID_VALUE);
	}
}


int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}