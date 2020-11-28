#include "JSON.h"
#include "Monster.h"
#include "Hero.h"
#include "Map.h"
#include "gtest/gtest.h"


TEST(Jsontest, Fajlvaltozo) {
	std::ifstream f("Hosarkany.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Hosarkany");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 300);
	EXPECT_EQ(beolvasas.get<int>("damage"), 30);
	EXPECT_EQ(beolvasas.get<int>("defense"), 3);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.4);
}

TEST(Jsontest, Szoveg) {
	std::string szoveg = "Sotetvarazslo.json";
	JSON beolvasas = JSON::parseFromFile(szoveg);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Sotetvarazslo");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 250);
	EXPECT_EQ(beolvasas.get<int>("defense"), 1);
	EXPECT_EQ(beolvasas.get<int>("damage"), 40);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.0);
}


TEST(Jsontest, Fajlnev) {
	const char * fajlnev = "Arnykiraly.json";
	JSON beolvasas = JSON::parseFromFile(fajlnev);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Arnykiraly");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 200);
	EXPECT_EQ(beolvasas.get<int>("damage"), 48);
	EXPECT_EQ(beolvasas.get<int>("defense"), 2);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 1.6);
}

TEST(Jsontest, Kulcssorrend_test) {
	std::ifstream f("Kardvadasz.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Kardvadasz");
	EXPECT_EQ(beolvasas.get<int>("health_points"), 280);
	EXPECT_EQ(beolvasas.get<int>("damage"), 48);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 2.1);
}

TEST(Jsontest, Whitespace_test) {
	std::ifstream f("Obelisk.json");
	JSON beolvasas = JSON::parseFromFile(f);
	EXPECT_EQ(beolvasas.get<std::string>("name"), "Obelisk");
	EXPECT_EQ(beolvasas.get<int>("damage"), 45);
	EXPECT_EQ(beolvasas.get<int>("health_points"), 260);
	EXPECT_EQ(beolvasas.get<double>("attack_cooldown"), 1.7);
}

TEST(Exceptiontest,Nem_letezo_fajl_test){
    ASSERT_THROW(JSON::parseFromFile("Lathatatlan.json"), JSON::ParseException);
}


TEST(Unittest,Badscenario_exception_test){
std::string vart = "The provided scenario file is invalid.";
testing::internal::CaptureStdout();
JSON scenario = JSON::parseFromFile("badscenario.json");
if (!(scenario.count("hero") && scenario.count("monsters")))std::cout << "The provided scenario file is invalid.";
std::string output = testing::internal::GetCapturedStdout();
EXPECT_EQ(vart, output);
}

TEST(Maptest, Getter_test) {
	ASSERT_NO_THROW(Map("palya1.txt"));
	Map palya("palya1.txt");
	EXPECT_EQ(palya.get(4,1),1);
	EXPECT_EQ(palya.get(4, 0), 0);
}

TEST(unittests, Exceptions_test) {
	ASSERT_THROW(Map("Nemletezo_ivek.txt"), std::runtime_error);
	Map test("palya1.txt");
	ASSERT_THROW(test.get(-8,2), Map::WrongIndexException);
	ASSERT_THROW(test.get(3,-2), Map::WrongIndexException);
	ASSERT_THROW(test.get(300, 400), Map::WrongIndexException);
}




int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

