#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"

TEST_CASE("default konstruktor initialisiert x und y mit 0.0f","[constructor]")
{
  Vec2 u{};
  REQUIRE(u.x_ == 0.0f);
  REQUIRE(u.y_ == 0.0f);
}

TEST_CASE("userconstructor der x und y als argumente bekommt")
{
  Vec2 v{2.0f, -3.0f};
  REQUIRE(v.x_ == 2.0f);
  REQUIRE(v.y_ == -3.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
/*
Destruktor muss implementiert werden, wenn explizit/manuell [Speicher|Netzwerkressourcen|Dateien] 
vom Betriebssystem angefordert werden
*/