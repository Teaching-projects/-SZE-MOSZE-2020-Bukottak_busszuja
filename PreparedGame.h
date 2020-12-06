#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

#include <string>
#include <map>

#include "Game.h"
#include "MarkedMap.h"

class PreparedGame : public Game {
    public:
        PreparedGame(std::string scenariojson);
        using Game::run;
};

#endif
