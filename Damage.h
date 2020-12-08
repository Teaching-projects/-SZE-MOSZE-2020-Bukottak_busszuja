/**
 * \Struct Damage
 *
 * \brief Damage Struct
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
 *
 * Created on: 2020/12/07 17:55
*/
#pragma once
#include<iostream>

struct Damage {
    int physical;			///< A damage physical tipusának deklarációja
    int magical;			///< A damage magical tipusának deklarációja

    bool operator==(const Damage &other) const{									///< Operátor ami megvizsgálja két damage egyenlõ-e
        return(this->physical == other.physical && this->magical == other.magical);
    }

    Damage operator+(const Damage &other) {										///< Operátor ami két damaget ad össze
        Damage addeddmg;
        addeddmg.physical = this->physical + other.physical;
        addeddmg.magical = this->magical + other.magical;
        return(addeddmg);
    }

    Damage operator+=(const Damage &other) {									///< Operátor ami egy damage-hez hozzáad még egy damaget
        this->physical += other.physical;
        this->magical += other.magical;
        return(*this);
    }

    Damage operator*=(const Damage &other) {									///< Operátor ami egy damaget megszoroz egy másik damage-el
        this->physical *= other.physical;
        this->magical *= other.magical;
        return(*this);
    }

    friend std::ostream& operator<<(std::ostream& out, const Damage& dmg){		///< Operátor egy damage kiiratására
            out<<"Physical: "<<dmg.physical<<", Magical: "<<dmg.magical;
            return out;
    }
};
