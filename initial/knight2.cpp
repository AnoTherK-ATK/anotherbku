#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */
class PhoenixDownI: public BaseItem{
private:
	ItemType type = PHOENIXDOWNI;
public:
	bool canUse(BaseKnight * knight){
		if(knight -> getHp() <= 0)
			return true;
		else
			return false;
	}
	void use(BaseKnight * knight){
		knight -> setHp(knight -> getMaxHp());
	}
	ItemType getType(){
		return type;
	}
};

class PhoenixDownII: public BaseItem{
private:
	ItemType type = PHOENIXDOWNII;
public:
	bool canUse(BaseKnight * knight){
		if(knight -> getHp() < knight -> getMaxHp() / 4)
			return true;
		else
			return false;
	}
	void use(BaseKnight * knight){
		knight -> setHp(knight -> getMaxHp());
	}
	ItemType getType(){
		return type;
	}
};

class PhoenixDownIII: public BaseItem{
private:
	ItemType type = PHOENIXDOWNIII;
public:
	bool canUse(BaseKnight * knight){
		if(knight -> getHp() < knight -> getMaxHp() / 3)
			return true;
		else
			return false;
	}
	void use(BaseKnight * knight){
		if(knight -> getHp() <= 0)
			knight -> setHp(knight -> getMaxHp() / 3);
		else
			knight -> setHp(knight -> getHp() + knight -> getMaxHp() / 4);
	}
	ItemType getType(){
		return type;
	}
};

class PhoenixDownIV: public BaseItem{
private:
	ItemType type = PHOENIXDOWNIV;
public:
	bool canUse(BaseKnight * knight){
		if(knight -> getHp() < knight -> getMaxHp() / 2)
			return true;
		else
			return false;
	}
	void use(BaseKnight * knight){
		if(knight -> getHp() <= 0)
			knight -> setHp(knight -> getMaxHp() / 2);
		else
			knight -> setHp(knight -> getHp() + knight -> getMaxHp() / 5);
	}
	ItemType getType(){
		return type;
	}
};
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */