#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */
bool AntiDote::canUse(BaseKnight * knight){
    return (knight -> getType() == DRAGON && knight -> getPoison());
}
void AntiDote::use(BaseKnight * knight){
	knight -> setPoison(0);
}

bool PhoenixDownI::canUse(BaseKnight * knight){
	if(knight -> getHp() <= 0)
		return true;
	else
		return false;
}
void PhoenixDownI::use(BaseKnight * knight){
	knight -> setHp(knight -> getMaxHp());
}

bool PhoenixDownII::canUse(BaseKnight * knight){
	if(knight -> getHp() < knight -> getMaxHp() / 4)
		return true;
	else
		return false;
}
void PhoenixDownII::use(BaseKnight * knight){
	knight -> setHp(knight -> getMaxHp());
}

bool PhoenixDownIII::canUse(BaseKnight * knight){
	if(knight -> getHp() < knight -> getMaxHp() / 3)
		return true;
	else
		return false;
}
void PhoenixDownIII::use(BaseKnight * knight){
	if(knight -> getHp() <= 0)
		knight -> setHp(knight -> getMaxHp() / 3);
	else
		knight -> setHp(knight -> getHp() + knight -> getMaxHp() / 4);
}

bool PhoenixDownIV::canUse(BaseKnight * knight){
	if(knight -> getHp() < knight -> getMaxHp() / 2)
		return true;
	else
		return false;
}
void PhoenixDownIV::use(BaseKnight * knight){
	if(knight -> getHp() <= 0)
		knight -> setHp(knight -> getMaxHp() / 2);
	else
		knight -> setHp(knight -> getHp() + knight -> getMaxHp() / 5);
}
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
bool ArmyKnights::isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int ArmyKnights::sqr(int x){
    return x * x;
}

bool ArmyKnights::isPyth(int x){
    int arr[3];
    for(int i = 0; i < 3; ++i){
        arr[i] = x % 10;
        x = x / 10;
    }
    if(sqr(arr[0]) + sqr(arr[1]) == sqr(arr[2])) return true;
    if(sqr(arr[0]) + sqr(arr[2]) == sqr(arr[1])) return true;
    if(sqr(arr[2]) + sqr(arr[1]) == sqr(arr[0])) return true;
    return false;
}

ArmyKnights::ArmyKnights (const string & file_armyknights){
	ifstream in(file_armyknights);
	cout << file_armyknights << '\n';
	in >> cnt;
	cout << cnt << '\n';
	for(int i = 0; i <= cnt + 1; ++i){
		knightList[i] = new BaseKnight;
	}
	for(int i = 1; i <= cnt; ++i){
		int hp;
		int lv;
		int phoenix;
		int gil;
		int antidote;
		in >> hp >> lv >> phoenix >> gil >> antidote;
		if(isPrime(hp))
			knightList[i] = new PaladinKnight(i, hp, lv, gil, antidote, phoenix, PALADIN);
		else if(hp == 888)
			knightList[i] = new LancelotKnight(i, hp, lv, gil, antidote, phoenix, LANCELOT);
		else if(isPyth(hp)){
			knightList[i] = new DragonKnight(i, hp, lv, gil, antidote, phoenix, DRAGON);
			for(int j = i - 1, k = 0; j >= 1 && k < antidote;){
				if(knightList[j] -> insertItem(new AntiDote()))
					++k;
				else --j;
			}
		}
		else
			knightList[i] = new NormalKnight(i, hp, lv, gil, antidote, phoenix, NORMAL);
	}
	in.close();
}
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
