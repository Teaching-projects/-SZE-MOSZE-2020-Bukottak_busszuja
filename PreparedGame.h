/**
 * \Class PreparedGame
 *
 * \brief PreparedGame Class
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
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
        PreparedGame(std::string scenariojson);		///< Egy forgat�k�nyv alapj�n elind�t egy j�t�kot
        using Game::run;
};

#endif
