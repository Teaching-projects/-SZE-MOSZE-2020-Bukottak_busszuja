#include "JSON.h"
#include "Monster.h"
#include "Hero.h"
#include "Map.h"
#include "Damage.h"
#include "Game.h"
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
	EXPECT_EQ(palya.get(1,1),1);
	EXPECT_EQ(palya.get(1,0), 0);
}

TEST(unittests, Exceptions_test) {
	ASSERT_THROW(Map("Nemletezo_ivek.txt"), std::runtime_error);
	Map test("palya1.txt");
	ASSERT_THROW(test.get(-8,2), Map::WrongIndexException);
	ASSERT_THROW(test.get(3,-2), Map::WrongIndexException);
	ASSERT_THROW(test.get(300, 400), Map::WrongIndexException);
}

TEST(Jsontest,Different_input_equal_test){
	std::ifstream f("Hosarkany.json");
	std::string szoveg = "Hosarkany.json";
	const char * fajlnev = "Hosarkany.json";
	JSON beolvasas1 = JSON::parseFromFile(f);
	JSON beolvasas2 = JSON::parseFromFile(szoveg);
	JSON beolvasas3 = JSON::parseFromFile(fajlnev);
	EXPECT_EQ(beolvasas1.get<std::string>("name"), beolvasas2.get<std::string>("name"));
	EXPECT_EQ(beolvasas3.get<std::string>("name"), beolvasas2.get<std::string>("name"));
	EXPECT_EQ(beolvasas1.get<int>("health_points"), beolvasas2.get<int>("health_points"));
	EXPECT_EQ(beolvasas3.get<int>("health_points"), beolvasas2.get<int>("health_points"));
	EXPECT_EQ(beolvasas1.get<int>("damage"),beolvasas2.get<int>("damage"));
	EXPECT_EQ(beolvasas3.get<int>("damage"),beolvasas2.get<int>("damage"));
	EXPECT_EQ(beolvasas1.get<double>("attack_cooldown"),beolvasas2.get<double>("attack_cooldown"));
	EXPECT_EQ(beolvasas3.get<double>("attack_cooldown"),beolvasas2.get<double>("attack_cooldown"));
        EXPECT_EQ(beolvasas1.get<int>("defense"),beolvasas2.get<int>("defense"));
	EXPECT_EQ(beolvasas3.get<int>("defense"),beolvasas2.get<int>("defense"));
}

TEST(Unittest,Type_fine_test){
Monster monster{Monster::parse("Hosarkany.json")};
std::string type_hp = typeid(monster.getHealthPoints()).name();
std::string type_dmg = typeid(monster.getDamage()).name();
std::string type_def = typeid(monster.getDefense()).name();
std::string type_speed = typeid(monster.getAttackCoolDown()).name();
type_dmg.erase(0, 1);
EXPECT_TRUE(type_hp == "i");
EXPECT_EQ(type_dmg ,"Damage");
EXPECT_TRUE(type_def == "i");
EXPECT_TRUE(type_speed == "d");
}

TEST(Exceptiontest,Nincs_hibauzenet_test){
    ASSERT_NO_THROW(Hero::parse("Dark_Wanderer.json"));
    ASSERT_NO_THROW(Monster::parse("Hosarkany.json"));
}

TEST(Unittest,Fight_function_test){
Hero hero {Hero::parse("Dark_Wanderer.json")};
Monster monster{Monster::parse("Hosarkany.json")};
hero.fightTilDeath(monster);
EXPECT_TRUE(monster.isAlive());
EXPECT_FALSE(hero.isAlive());
}

TEST(Unittest, Hero_Monster_different_test) {
Hero hero {Hero::parse("Dark_Wanderer.json")};
Monster monster{Monster::parse("Hosarkany.json")};
std::string tipush = typeid(hero).name();
std::string tipusm = typeid(monster).name();
tipush.erase(0, 1);
tipusm.erase(0, 1);
EXPECT_EQ(tipush, "Hero");
EXPECT_EQ(tipusm, "Monster");
}

TEST(Unittest,Monster_parse_test){
Monster monster{Monster::parse("Sotetvarazslo.json")};
Damage d;
d.physical = 40;
d.magical = 0;
Monster monster1("Sotetvarazslo", 250, d,1, 2.0);
EXPECT_TRUE(monster==monster1);
}

TEST(Unittest,Hero_parse_test){
Damage d;
d.physical = 3;
d.magical = 1;
Hero hos("Prince Aidan of Khanduras",30,d,1,1.1,20,5,1,1,1,0.9);
Hero hero{ Hero::parse("Dark_Wanderer.json") };
EXPECT_TRUE(hos==hero);
}

TEST(Unittest,Private_functions_test){
Damage d;
d.physical = 3;
d.magical = 1;
Hero hero {Hero::parse("Dark_Wanderer.json")};
Monster monster{Monster::parse("Hosarkany.json")};
hero.tamad(&monster);
Hero hos("Prince Aidan of Khanduras",30,d,1,1.1,20,5,1,1,1,0.9,1,1);
EXPECT_TRUE(hos==hero);
}


TEST(GameTest,Map_is_not_init_test){
Game jatek;
Damage d;
d.physical = 3;
d.magical = 1;
Monster monster1("Sotetvarazslo", 250, d, 1, 2.0);
Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
ASSERT_THROW(jatek.putHero(hos,1,1), Map::WrongIndexException);
ASSERT_THROW(jatek.putMonster(monster1,1,3), Map::WrongIndexException);
}

TEST(GameTest,Only_one_hero_test){
Game jatek;
Damage d;
d.physical = 3;
d.magical = 1;
Map palya("palya1.txt");
jatek.setMap(palya);
Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
Hero hos2("Hosarkany", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
jatek.putHero(hos,1,1);
ASSERT_THROW(jatek.putHero(hos2,1,3), Game::AlreadyHasHeroException);
}

TEST(GameTest,Monster_Hero_Wall_test){
Game jatek;
Damage d;
d.physical = 3;
d.magical = 1;
Map palya("palya1.txt");
jatek.setMap(palya);
Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
ASSERT_THROW(jatek.putHero(hos,1,0), Game::OccupiedException);
}

TEST(GameTest,Map_has_units_test){
Game jatek;
Damage d;
d.physical = 3;
d.magical = 1;
Map palya("palya1.txt");
jatek.setMap(palya);
Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
jatek.putHero(hos,1,1);
ASSERT_THROW(jatek.setMap(palya), Game::AlreadyHasUnitsException);
}

TEST(GameTest,Gamenotinitial_test){
Game jatek;
Damage d;
d.physical = 3;
d.magical = 1;
Map palya("palya1.txt");
Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
ASSERT_THROW(jatek.run(), Game::NotInitializedException);
jatek.setMap(palya);
ASSERT_THROW(jatek.run(), Game::NotInitializedException);
}

TEST(GameTest,GetMonsterdb_test){
Game jatek;
Damage d;
d.physical = 3;
d.magical = 1;
Map palya("palya1.txt");
Monster monster1("Sotetvarazslo", 250, d, 1, 2.0);
Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
jatek.setMap(palya);
Monster monster2("Hosarkany", 300, d, 1, 2.4);
jatek.putHero(hos,1,1);
jatek.putMonster(monster1,1,3);
jatek.putMonster(monster2,1,3);
EXPECT_EQ(jatek.getMonsterdb(1,3),2);


}





int main(int argc, char ** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

