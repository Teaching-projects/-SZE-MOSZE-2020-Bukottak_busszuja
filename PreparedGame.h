/**
 * \Class PreparedGame
 *
 * \brief PreparedGame Class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
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
        PreparedGame(std::string scenariojson);		///< Egy forgatokonyv alapjan elindit egy jatekot
        using Game::run;
};

#endif
