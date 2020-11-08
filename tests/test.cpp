#include "JSON.h"
#include "Monster.h"
#include "Hero.h"
#include "gtest/gtest.h"


TEST(Jsontest, Fajlvaltozo) {
	std::ifstream f("Hosarkany.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Hosarkany");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 300);
	EXPECT_EQ(beolvasas.get<int>("damage"), 30);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.4);
}

TEST(Jsontest, Szoveg) {
	std::string szoveg = "Sotetvarazslo.json";
	JSON beolvasas = JSON::parseFromFile(szoveg);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 250);
	EXPECT_EQ(beolvasas.get<int>("damage"), 40);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.0);
}


TEST(Jsontest, Fajlnev) {
	const char * fajlnev = "Arnykiraly.json";
	JSON beolvasas = JSON::parseFromFile(fajlnev);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 200);
	EXPECT_EQ(beolvasas.get<int>("damage"), 48);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 1.6);
}

TEST(Jsontest, Whitespace_test) {
	std::ifstream f("Atoksarkany.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Atoksarkany");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 260);
	EXPECT_EQ(beolvasas.get<int>("damage"), 45);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 1.7);
}

TEST(Jsontest, Kulcssorrend_test) {
	std::ifstream f("Kardvadasz.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.getErtek("name"), "Kardvadasz");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 280);
	EXPECT_EQ(beolvasas.get<int>("damage"), 48);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.1);
}

TEST(Jsontest, Idezojelfuggetlenseg_test) {
	std::ifstream f("Arnykiraly.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 200);
	EXPECT_EQ(beolvasas.get<int>("damage"), 48);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 1.6);
}

TEST(Jsontest, Tobb_kevesebb_idozejel_test) {
	std::ifstream f("Sotetvarazslo.json");
	JSON beolvasas = JSON::parseFromFile(szoveg);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 250);
	EXPECT_EQ(beolvasas.get<int>("damage"), 40);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.0);
}

/*TEST(Maintest, Nem_letezo_fajl_test) {
	std::ifstream f("Lathatatlan.json");
	try {
		JSON f1 = JSON::parseFromFile(f);
	}
	catch (int e) {
		EXPECT_EQ(e, MYFILEERROR);
	}
}


TEST(Maintest, Tobb_kevesebb_adat_test) {
	std::ifstream f("Exodia.json");
	try {
		JSON f1 = JSON::parseFromFile(f);
	}
	catch (int e) {
		EXPECT_EQ(e, INVALID_VALUE);
	}
}

TEST(Szornytest, Lko_test) {
	EXPECT_EQ(round(gcd(2.4,1.6)),round(0.8));
	EXPECT_EQ(round(gcd(2.2, 4.4)), round(2.2));
	EXPECT_EQ(round(gcd(1.3, 1.1)), round(0.1));
}*/

TEST(Szornytest, parseUnit_test) {
	std::ifstream f("Sotetvarazslo.json");
	std::string szoveg = "Sotetvarazslo.json";
	const char * fajlnev = "Sotetvarazslo.json";
	Monster eredmeny("Sotetvarazslo",250,40,2.0);
	JSON beolvasas1 = JSON::parseFromFile(f);
	JSON beolvasas2 = JSON::parseFromFile(szoveg);
	JSON beolvasas3 = JSON::parseFromFile(fajlnev);
	Monster s1 = Monster::parse(beolvasas1);
	Monster s2 = Monster::parse(beolvasas2);
	Monster s3 = Monster::parse(beolvasas3);
	EXPECT_TRUE(s1==eredmeny);
	EXPECT_TRUE(s2==eredmeny);
	EXPECT_TRUE(s3==eredmeny);
}

TEST(Szornytest, harcfunction_Kalandorwin_output_test) {
	std::string vart = "Sotetvarazslo wins. Remaining HP: 332, current level: 4, current experience: 0";
	JSON f = JSON::parseFromFile("Hosarkany.json");
	JSON f1 = JSON::parseFromFile("Sotetvarazslo.json");
	Monster s2 = Monster::parse(f);
	Hero s1(Hero::parse(f1));
	hero.fightTilDeath(s2);
	testing::internal::CaptureStdout();
	if (s1.getHealthPoints() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHealthPoints();
	if (s2.getHealthPoints() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHealthPoints() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(vart, output);
	}

TEST(Szornytest, harcfunction_Szornywin_output_test) {
	std::string vart = "Obelisk wins. Remaining HP: 340";
	JSON f1 = JSON::parseFromFile("Obelisk.json");
	JSON f = JSON::parseFromFile("Hosarkany.json");
	Monster s2 = Monster::parse(f1);
	Hero s1(Hero::parse(f));
	hero.fightTilDeath(s2);
	testing::internal::CaptureStdout();
	if (s1.getHealthPoints() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHealthPoints();
	if (s2.getHealthPoints() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHealthPoints() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp();
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(vart, output);
}

TEST(Szornytest,Kalandor_Szorny_different_test) {
	JSON f1 = JSON::parseFromFile("Obelisk.json");
	JSON f = JSON::parseFromFile("Hosarkany.json");
	Monster s2 = Monster::parse(f1);
	Hero s1(Hero::parse(f));
	std::string tipusk=typeid(s1).name();
	std::string tipuss = typeid(s2).name();
        tipusk.erase(0,1);
	tipuss.erase(0,1);
	EXPECT_EQ(tipusk,"Hero");
	EXPECT_EQ(tipuss,"Monster");
}

TEST(Szornytest, Levelup_Xpgain_test) {
	Hero s1("Hosarkany", 300, 30, 2.4, 10, 1, 1, 0.9);
	Monster s2("Sotetvarazslo", 250, 40, 2.0);
	s1.tamad(s2);
	Hero s3("Hosarkany", 300, 30, 2.4, 10, 1, 1, 0.9);
	EXPECT_TRUE(s3==s1);
}


int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

