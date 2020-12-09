/**
 * \Struct Damage
 *
 * \brief Damage Struct
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/12/07 17:55
*/
#pragma once
#include<iostream>

struct Damage {
    int physical;			///< A damage physical tipusanak deklaracioja
    int magical;			///< A damage magical tipusanak deklaracioja

    bool operator==(const Damage &other) const{									///< Operator ami megvizsgalja ket damage egyenlo-e
        return(this->physical == other.physical && this->magical == other.magical);
    }

    Damage operator+(const Damage &other) {										///< Operator ami ket damaget ad ossze
        Damage addeddmg;
        addeddmg.physical = this->physical + other.physical;
        addeddmg.magical = this->magical + other.magical;
        return(addeddmg);
    }

    Damage operator+=(const Damage &other) {									///< Operator ami egy damage-hez hozzaad meg egy damaget
        this->physical += other.physical;
        this->magical += other.magical;
        return(*this);
    }

    Damage operator*=(const Damage &other) {									///< Operator ami egy damaget megszoroz egy masik damage-el
        this->physical *= other.physical;
        this->magical *= other.magical;
        return(*this);
    }

    friend std::ostream& operator<<(std::ostream& out, const Damage& dmg){		///< Operator egy damage kiiratasara
            out<<"Physical: "<<dmg.physical<<", Magical: "<<dmg.magical;
            return out;
    }
};
