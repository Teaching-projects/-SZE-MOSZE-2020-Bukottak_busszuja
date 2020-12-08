/**
 * \Class PreparedGame
 *
 * \brief PreparedGame Class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
 *
 * Created on: 2020/12/07 18:35
*/
#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

#include <string>
#include <map>

#include "Game.h"
#include "MarkedMap.h"

class PreparedGame : public Game {
    public:
        PreparedGame(std::string scenariojson);		///< Egy forgatókönyv alapján elindít egy játékot
        using Game::run;
};

#endif
