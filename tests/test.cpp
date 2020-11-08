#include "JSON.h"
#include "Monster.h"
#include "Hero.h"
#include "gtest/gtest.h"

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}


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

TEST(Maintest, Nem_letezo_fajl_test) {
	std::string vart = "The provided scenario file is not accessible.";
	testing::internal::CaptureStdout();
	std::ifstream file;
   	file.open("Lathatatlan.json");
   	if(!file.good())bad_exit(2);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(vart, output);
}



int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

