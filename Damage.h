/**
 * \Struct Damage
 *
 * \brief Damage Struct
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
 *
 * Created on: 2020/12/07 17:55
*/
#pragma once
#include<iostream>

struct Damage {
    int physical;			///< A damage physical tipus�nak deklar�ci�ja
    int magical;			///< A damage magical tipus�nak deklar�ci�ja

    bool operator==(const Damage &other) const{									///< Oper�tor ami megvizsg�lja k�t damage egyenl�-e
        return(this->physical == other.physical && this->magical == other.magical);
    }

    Damage operator+(const Damage &other) {										///< Oper�tor ami k�t damaget ad �ssze
        Damage addeddmg;
        addeddmg.physical = this->physical + other.physical;
        addeddmg.magical = this->magical + other.magical;
        return(addeddmg);
    }

    Damage operator+=(const Damage &other) {									///< Oper�tor ami egy damage-hez hozz�ad m�g egy damaget
        this->physical += other.physical;
        this->magical += other.magical;
        return(*this);
    }

    Damage operator*=(const Damage &other) {									///< Oper�tor ami egy damaget megszoroz egy m�sik damage-el
        this->physical *= other.physical;
        this->magical *= other.magical;
        return(*this);
    }

    friend std::ostream& operator<<(std::ostream& out, const Damage& dmg){		///< Oper�tor egy damage kiirat�s�ra
            out<<"Physical: "<<dmg.physical<<", Magical: "<<dmg.magical;
            return out;
    }
};
