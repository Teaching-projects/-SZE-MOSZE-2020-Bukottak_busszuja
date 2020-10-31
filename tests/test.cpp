#include"../Jsonparser.cpp"
#include "../Szorny.cpp"
#include "../Kalandor.cpp"
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

TEST(Szornytest, Lko_test) {
	EXPECT_EQ(round(gcd(2.4,1.6)),round(0.8));
	EXPECT_EQ(round(gcd(2.2, 4.4)), round(2.2));
	EXPECT_EQ(round(gcd(1.3, 1.1)), round(0.1));
}

TEST(Szornytest, parseUnit_test) {
	std::ifstream f("Sotetvarazslo.json");
	std::string szoveg = "Sotetvarazslo.json";
	const char * fajlnev = "Sotetvarazslo.json";
	Szorny eredmeny("Sotetvarazslo",250,40,2.0);
	Jsonparser beolvasas1(f);
	Jsonparser beolvasas2(szoveg);
	Jsonparser beolvasas3(fajlnev);
	Szorny s1 = Szorny::parseUnit(beolvasas1);
	Szorny s2 = Szorny::parseUnit(beolvasas2);
	Szorny s3 = Szorny::parseUnit(beolvasas3);
	EXPECT_EQ(s1==s2, true);
	EXPECT_EQ(s3 == s2, true);
	EXPECT_EQ(s1==eredmeny,true);
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

TEST(Szornytest, harcfunction_Kalandorwin_output_test) {
	std::string vart = "Sotetvarazslo wins. Remaining HP: 332, current level: 4, current experience: 0";
	Jsonparser f("Hosarkany.json");
	Jsonparser f1("Sotetvarazslo.json");
	Szorny s2 = Szorny::parseUnit(f);
	Kalandor s1(Szorny::parseUnit(f1));
	Szorny::harc(s1, s2);
	testing::internal::CaptureStdout();
	if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHp();
	if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHp() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(vart, output);
	}

TEST(Szornytest, harcfunction_Szornywin_output_test) {
	std::string vart = "Obelisk wins. Remaining HP: 340";
	Jsonparser f1("Obelisk.json");
	Jsonparser f("Hosarkany.json");
	Szorny s2 = Szorny::parseUnit(f1);
	Kalandor s1(Szorny::parseUnit(f));
	Szorny::harc(s1, s2);
	testing::internal::CaptureStdout();
	if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHp();
	if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHp() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(vart, output);
}

TEST(Szornytest,Kalandor_Szorny_different_test) {
	Jsonparser f1("Obelisk.json");
	Jsonparser f("Hosarkany.json");
	Szorny s2 = Szorny::parseUnit(f1);
	Kalandor s1(Szorny::parseUnit(f));
	std::string tipusk=typeid(s1).name();
	std::string tipuss = typeid(s2).name();
	EXPECT_EQ(tipusk,"class Kalandor");
	EXPECT_EQ(tipuss,"class Szorny");
}


int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}