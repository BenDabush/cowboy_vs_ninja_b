#include "doctest.h"
#include "sources/Team.hpp"
#include <cfloat>
#include <stdexcept>

using namespace ariel;

TEST_SUITE("Test Point Class") {

    TEST_CASE("Point class functions don't throw errors when they shouldn't") {
        Point p(1, 2);

        SUBCASE("Point constructor does not throw an error") {
            CHECK_NOTHROW(Point(1, 2));
        }

        SUBCASE("Point distance function does not throw an error") {
            Point p1(1, 2);
            Point p2(3, 4);
            CHECK_NOTHROW(p1.distance(p2));
        }

        SUBCASE("Point print function does not throw an error") {
            CHECK_NOTHROW(p.print());
        }

        SUBCASE("Point moveTowards function does not throw an error") {
            Point source(1, 2);
            Point destination(3, 4);
            CHECK_NOTHROW(source.moveTowards(source, destination, 1));
        }

        SUBCASE("Point getters do not throw an error") {
            CHECK_NOTHROW(p.getXValue());
            CHECK_NOTHROW(p.getYValue());
        }

        SUBCASE("Point setters do not throw an error") {
            CHECK_NOTHROW(p.setXValue(2));
            CHECK_NOTHROW(p.setYValue(3));
        }
    }

    TEST_CASE("Constructor and getters") {
        SUBCASE("Can create a Point object with given coordinates") {
            Point p(3.2, 5.6);
            CHECK_EQ(p.getXValue(), 3.2);
            CHECK_EQ(p.getYValue(), 5.6);
        }

        SUBCASE("Can get the coordinates of a Point object") {
            Point p(1.1, 2.2);
            CHECK_EQ(p.getXValue(), 1.1);
            CHECK_EQ(p.getYValue(), 2.2);
        }
    }

    TEST_CASE("Setters") {
        SUBCASE("Can set the X coordinate of a Point object") {
            Point p(0, 0);
            p.setXValue(1.1);
            CHECK_EQ(p.getXValue(), 1.1);
        }

        SUBCASE("Can set the Y coordinate of a Point object") {
            Point p(0, 0);
            p.setYValue(2.2);
            CHECK_EQ(p.getYValue(), 2.2);
        }
    }

    TEST_CASE("Distance function") {
        SUBCASE("Can calculate the distance between two Points with positive coordinates") {
            Point p1(0, 0);
            Point p2(3, 4);
            CHECK_EQ(p1.distance(p2), 5);
        }

        SUBCASE("Can calculate the distance between two Points with negative coordinates") {
            Point p1(-3, -4);
            Point p2(0, 0);
            CHECK_EQ(p1.distance(p2), 5);
        }

        SUBCASE("Throws an exception when calculating the distance between Points with extreme coordinates") {
            Point p1(DBL_MAX, DBL_MIN);
            Point p2(DBL_MIN, DBL_MAX);
            CHECK_THROWS_AS(p1.distance(p2), std::overflow_error);
            CHECK_THROWS_AS(p2.distance(p1), std::overflow_error);
        }
    }

    TEST_CASE("MoveTowards function") {
        SUBCASE("Can calculate the Point closest to the destination with positive coordinates") {
            Point source(0, 0);
            Point destination(3, 4);
            Point closest = source.moveTowards(source, destination, 2.5);
            CHECK_EQ(closest.getXValue(), 1.5);
            CHECK_EQ(closest.getYValue(), 2);
        }

        SUBCASE("Throws an exception when calculating the Point closest to the destination with extreme coordinates") {
            Point source(DBL_MAX, DBL_MAX);
            Point destination(DBL_MIN, DBL_MIN);
            CHECK_THROWS_AS(source.moveTowards(source, destination, DBL_MAX), std::overflow_error);
        }

        SUBCASE("moveTowards function with zero distance between points") {
            Point source(0, 0);
            Point destination(0, 0);
            double distance = 1.0;
            CHECK_THROWS_AS(source.moveTowards(source, destination, distance), std::runtime_error);
        }

        SUBCASE("moveTowards function with large values for dx and dy") {
            Point source(0, 0);
            Point destination(DBL_MAX, DBL_MAX);
            double distance = 1.0;
            CHECK_THROWS_AS(source.moveTowards(source, destination, distance), std::overflow_error);
        }

        SUBCASE("moveTowards function with negative distance parameter") {
            Point source(0, 0);
            Point destination(1, 1);
            double distance = -1.0;
            CHECK_THROWS_AS(source.moveTowards(source, destination, distance), std::invalid_argument);
        }
    }
}

TEST_SUITE("Test Character Class") {
    TEST_CASE("Character class functions don't throw errors when they shouldn't") {
        Point location1(0, 0);
        Point location2(3, 4);

        SUBCASE("Character constructor does not throw an error") {
            CHECK_NOTHROW(Character("Aria Nightshade", location1, 100));
            CHECK_NOTHROW(Character("Kairos Stoneheart", location2, 80));
        }

        Character character1("Luna Shadowborn", location1, 100);
        Character character2("Ignis Flamestrike", location2, 1);

        SUBCASE("isAlive does not throw an error") {
            CHECK_NOTHROW(character1.isAlive());
            CHECK_NOTHROW(character2.isAlive());
        }

        SUBCASE("distance does not throw an error") {
            CHECK_NOTHROW(character1.distance(&character2));
            CHECK_NOTHROW(character2.distance(&character1));
        }

        SUBCASE("hit does not throw an error") {
            CHECK_NOTHROW(character1.hit(50));
            CHECK_NOTHROW(character2.hit(1));
        }
    }

    TEST_CASE("General tests for character class functions") {
        SUBCASE("constructor") {
            Point location1(0, 0);

            CHECK_THROWS_AS(Character("Zephyr Windrider", location1, -1), std::invalid_argument);
            CHECK_THROWS_AS(Character("Terra Earthshaker", location1, 0), std::invalid_argument);
        }

        SUBCASE("distance") {
            Point location0(0, 0);
            Point location1(-1, -1);
            Point location2(2, 3);
            Point location3(-1, -3);
            Point location4(DBL_MAX, DBL_MIN);
            Point location5(DBL_MIN, DBL_MAX);
            Point location6(DBL_MAX, DBL_MAX);       
            
            Character character0("Aurora Starlighter", location0, 100);
            Character character1("Aurora Starlighter", location1, 100);
            Character character2("CoThorne Ironfistboy", location2, 80);
            Character character3("Vesper Moonlight", location3, 100);
            Character character4("Blaze Wildfire", location4, 80);
            Character character5("Raven Nightshade", location5, 80);
            Character character6("Raven Nightshade", location6, 80);

            double dist1 = character1.distance(&character2);
            double dist2 = character2.distance(&character1);

            CHECK_EQ(dist1, 5.0);
            CHECK_EQ(dist2, dist1);
            
            CHECK_EQ(character0.distance(&character6), DBL_MAX);
            CHECK_EQ(character1.distance(&character1), 0);
            CHECK_GT(character1.distance(&character3), 0);
            CHECK_GT(character3.distance(&character1), 0);

            
            CHECK_THROWS_AS(character4.distance(&character5), std::overflow_error);
            CHECK_THROWS_AS(character5.distance(&character4), std::overflow_error);
        }

        SUBCASE("hit and isAlive") {
            Point location1(-1, -1); 
            Point location2(1, 1);    
            
            Character character1("Orion Stardust", location1, 100);
            Character character2("Phoenix Flameborn", location2, 100);
            
            CHECK_EQ(character1.isAlive(), true);
            CHECK_EQ(character2.isAlive(), true);
            CHECK_EQ(character1.getCharacterHP(), 100);
            CHECK_EQ(character2.getCharacterHP(), 100);

            character1.hit(52);
            CHECK_EQ(character1.isAlive(), true);
            CHECK_EQ(character1.getCharacterHP(), 48);
            CHECK_EQ(character2.getCharacterHP(), 100);

            for (int i = 0; i < 4; i++) {
                character1.hit(10);
            }

            CHECK_EQ(character1.isAlive(), true);
            CHECK_EQ(character1.getCharacterHP(), 8);

            character1.hit(8);
            CHECK_EQ(character1.isAlive(), false);
            CHECK_EQ(character1.getCharacterHP(), 0);
            CHECK_EQ(character2.isAlive(), true);
            CHECK_EQ(character2.getCharacterHP(), 100);

            character1.hit(10);
            CHECK_EQ(character1.isAlive(), false);
            CHECK_EQ(character1.getCharacterHP(), 0);
            CHECK_EQ(character2.isAlive(), true);
            CHECK_EQ(character2.getCharacterHP(), 100);
        }
    }
}

TEST_SUITE("Test Cowboy Class") {
    TEST_CASE("Character class functions don't throw errors when they shouldn't") {
        Point location1(0, 0);
        Point location2(3, 4);

        SUBCASE("Character constructor does not throw an error") {
            CHECK_NOTHROW(Cowboy("Wyatt Earp", location1));
            CHECK_NOTHROW(Cowboy("Billy the Kid", location2));
        }

        Cowboy Jesse("Jesse James", location1);
        Cowboy Doc("Doc Holliday", location2);

        // Test case: Shoot enemy when Jesse has bullets
        SUBCASE("Shoot does not throw an error") {
            Cowboy Jesse("Jesse James", location1);
            Cowboy Doc("Doc Holliday", location2);
            CHECK_NOTHROW(Jesse.shoot(&Doc));
        }

        SUBCASE("reload does not throw an error") {
            Cowboy Jesse("Jesse James", location1);
            Cowboy Doc("Doc Holliday", location2);
            
            for (int i = 0; i < 6; i++) {
                Jesse.shoot(&Doc);
            }
            
            CHECK_NOTHROW(Jesse.reload());
        }

    }
    // // Test case 1: Shoot enemy when cowboy has bullets
    // SUBCASE("Shoot enemy with bullets") {
    //     Cowboy cowboy("John", Point(0, 0));
    //     Cowboy enemy("Bob", Point(0, 1));
    //     cowboy.shoot(&enemy);

    //     // Check that enemy's hit points are decreased by 1
    //     CHECK(enemy.getHitPoints() == 10);

    //     // Check that cowboy has lost 1 bullet
    //     CHECK(cowboy.hasBullets() == false);
    // }

    // // Test case 2: Shoot enemy when cowboy has no bullets
    // SUBCASE("Shoot enemy without bullets") {
    //     Cowboy cowboy("John", Point(0, 0));
    //     Cowboy enemy("Bob", Point(0, 1));

    //     // Reload cowboy's gun to get 6 bullets
    //     cowboy.reload();

    //     // Shoot the enemy multiple times until bullets run out
    //     for (int i = 0; i < 6; i++) {
    //         cowboy.shoot(&enemy);
    //     }

    //     // Try shooting the enemy again (should have no effect)
    //     cowboy.shoot(&enemy);

    //     // Check that enemy's hit points are still the same
    //     CHECK(enemy.getHitPoints() == 10);

    //     // Check that cowboy has lost all bullets
    //     CHECK(cowboy.hasBullets() == false);
    // }

    // // Test case 3: Reload cowboy's gun
    // SUBCASE("Reload cowboy's gun") {
    //     Cowboy cowboy("John", Point(0, 0));

    //     // Check that cowboy starts with 6 bullets
    //     CHECK(cowboy.hasBullets() == true);

    //     // Shoot some bullets to reduce the count
    //     cowboy.shoot(nullptr);
    //     cowboy.shoot(nullptr);
    //     cowboy.shoot(nullptr);

    //     // Reload cowboy's gun
    //     cowboy.reload();

    //     // Check that cowboy now has 6 bullets again
    //     CHECK(cowboy.hasBullets() == true);
    // }
// }


    //     SUBCASE("Cowboy") {
    //         // Test Cowboy-specific functions
    //         // ...

    //         // Example tests for shoot, checkCartridgeBullets, and reload
    //         ariel::Character enemy("Enemy", location2, 100);
    //         character2.shoot(&enemy);
    //         CHECK(character2.isAlive() == true);
    //         CHECK(enemy.isAlive() == false);
    //         CHECK(character2.checkCartridgeBullets() == false);

    //         character2.reload();
    //         CHECK(character2.checkCartridgeBullets() == true);
    //     }

    //     SUBCASE("Ninja") {
    //         // Test Ninja-specific functions
    //         // ...

    //         // Example tests for move and slash
    //         ariel::Character enemy("Enemy", location2, 1);
    //         character1.move(&enemy);
    //         CHECK(character1.getLocation() == ariel::Point(3, 4));

    //         character1.slash(&enemy);
    //         CHECK(character1.isAlive() == true);
    //         CHECK(enemy.isAlive() == false);
    //     }
    // }
}
