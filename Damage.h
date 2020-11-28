#pragma once
#include<iostream>

struct Damage {
	int physical;
	int magical;

	bool operator==(const Damage &other) const {
		return(this->physical == other.physical && this->magical == other.magical);
	}

	Damage operator+(const Damage &other) {
		Damage addeddmg;
		addeddmg.physical = this->physical + other.physical;
		addeddmg.magical = this->magical + other.magical;
		return(addeddmg);
	}

	Damage operator+=(const Damage &other) {
		this->physical += other.physical;
		this->magical += other.magical;
		return(*this);
	}

	Damage operator*=(const Damage &other) {
		this->physical *= other.physical;
		this->magical *= other.magical;
		return(*this);
	}

	friend std::ostream& operator<<(std::ostream& out, const Damage& dmg) {
		out << "Physical: " << dmg.physical << ", Magical: " << dmg.magical;
		return out;
	}
};

