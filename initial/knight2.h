#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
class BaseKnight;
class BaseItem;
class Events;
class BaseOpponent;
class BaseBag;
class ArmyKnights;
class KnightAdventure;

enum KnightType { PALADIN = 0, LANCELOT = 1, DRAGON = 2, NORMAL = 3 };
enum ItemType {ANTIDOTE = 0, PHOENIXDOWNI = 1, PHOENIXDOWNII = 2, PHOENIXDOWNIII = 3, PHOENIXDOWNIV = 4};

class BaseItem {
public:
	BaseItem(){}
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
	virtual ItemType getType() = 0;
};

class AntiDote: public BaseItem{
private:
	ItemType type = ANTIDOTE;
public:
	AntiDote (){}
	//this is fake
	bool canUse(BaseKnight * knight);
	void use(BaseKnight * knight);
	//this is real
	ItemType getType(){
		return type;
	}
};

class PhoenixDownI: public BaseItem{
private:
	ItemType type = PHOENIXDOWNI;
public:
	PhoenixDownI(){}
	bool canUse(BaseKnight * knight);
	void use(BaseKnight * knight);
	ItemType getType(){
		return type;
	}
};

class PhoenixDownII: public BaseItem{
private:
	ItemType type = PHOENIXDOWNII;
public:
	PhoenixDownII(){}
	bool canUse(BaseKnight * knight);
	void use(BaseKnight * knight);
	ItemType getType(){
		return type;
	}
};

class PhoenixDownIII: public BaseItem{
private:
	ItemType type = PHOENIXDOWNIII;
public:
	PhoenixDownIII(){}
	bool canUse(BaseKnight * knight);
	void use(BaseKnight * knight);
	ItemType getType(){
		return type;
	}
};

class PhoenixDownIV: public BaseItem{
private:
	ItemType type = PHOENIXDOWNIV;
public:
	PhoenixDownIV(){}
	bool canUse(BaseKnight * knight);
	void use(BaseKnight * knight);
	ItemType getType(){
		return type;
	}
};

struct Node{
	BaseItem* item;
	Node* next;
	Node (BaseItem *it = nullptr){
		item = it;
		next = nullptr;
	}
};

class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item) = 0;
    virtual BaseItem * get(ItemType itemType) = 0;
    virtual string toString() const = 0;
	virtual Node *getHead() = 0;
};

class PaladinBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
	Node *getHead(){
		return head;
	}
	PaladinBag(){
		head = nullptr;
		tail = nullptr;
	}
	~PaladinBag(){
		delete head;
		delete tail;
	}
	bool insertFirst(BaseItem *it){
		Node *tmp = new Node(it);
		if(tail == nullptr){
			head = tail = tmp;
		}else{
			tmp -> next = head;
			head = tmp;
		}
		++cnt;
		return true;
	}
	BaseItem * get(ItemType itemType){
		Node *node = head;
		while(node){
			if(node -> item -> getType() == itemType){
				return (node -> item);
			}
			node = node -> next;
		}
		return NULL;
	}
	string toString() const{
		string ans = "Bag[count=";
		ans += to_string(cnt);
		if(cnt == 0){
			ans += "]";
			return ans;
		}else{
			ans += ";";
			Node *node = head;
			while(node){
				if(node -> item -> getType() == ANTIDOTE){
					ans += "Antidote";
				}else if(node -> item -> getType() == PHOENIXDOWNI){
					ans += "PhoenixDownI";
				}else if(node -> item -> getType() == PHOENIXDOWNII){
					ans += "PhoenixDownII";
				}else if(node -> item -> getType() == PHOENIXDOWNIII){
					ans += "PhoenixDownIII";
				}else if(node -> item -> getType() == PHOENIXDOWNIV){
					ans += "PhoenixDownIV";
				}
				if(node -> next != nullptr)
					ans += ",";
				else{
					ans += "]";

				}
				node = node -> next;
			}
			return ans;
		}
	}
};

class DragonBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
	Node *getHead(){
		return head;
	}
	DragonBag(){
		head = nullptr;
		tail = nullptr;
	}
	~DragonBag(){
		delete head;
		delete tail;
	}
	bool insertFirst(BaseItem *it){
		Node *tmp = new Node(it);
		if(cnt == 14 || it -> getType() == ANTIDOTE)
			return false;
		if(tail == nullptr){
			head = tail = tmp;
		}else{
			tmp -> next = head;
			head = tmp;
		}
		++cnt;
		return true;
	}
	BaseItem * get(ItemType itemType){
		if(itemType == ANTIDOTE)
			return nullptr;
		Node *node = head;
		while(node){
			if(node -> item -> getType() == itemType){
				return (node -> item);
			}
			node = node -> next;
		}
		return NULL;
	}
	string toString() const{
		string ans = "Bag[count=";
		ans += to_string(cnt);
		if(cnt == 0){
			ans += "]";
			return ans;
		}else{
			ans += ";";
			Node *node = head;
			while(node){
				if(node -> item -> getType() == ANTIDOTE){
					ans += "Antidote";
				}else if(node -> item -> getType() == PHOENIXDOWNI){
					ans += "PhoenixDownI";
				}else if(node -> item -> getType() == PHOENIXDOWNII){
					ans += "PhoenixDownII";
				}else if(node -> item -> getType() == PHOENIXDOWNIII){
					ans += "PhoenixDownIII";
				}else if(node -> item -> getType() == PHOENIXDOWNIV){
					ans += "PhoenixDownIV";
				}
				if(node -> next != nullptr)
					ans += ",";
				else{
					ans += "]";

				}
				node = node -> next;
			}
			return ans;
		}
	}
};

class LancelotBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
	Node *getHead(){
		return head;
	}
	LancelotBag(){
		head = nullptr;
		tail = nullptr;
	}
	~LancelotBag(){
		delete head;
		delete tail;
	}
	bool insertFirst(BaseItem *it){
		Node *tmp = new Node(it);
		if(cnt == 16)
			return false;
		if(tail == nullptr){
			head = tail = tmp;
		}else{
			tmp -> next = head;
			head = tmp;
		}
		++cnt;
		return true;
	}
	BaseItem * get(ItemType itemType){
		Node *node = head;
		while(node){
			if(node -> item -> getType() == itemType){
				return (node -> item);
			}
			node = node -> next;
		}
		return NULL;
	}
	string toString() const{
		string ans = "Bag[count=";
		ans += to_string(cnt);
		if(cnt == 0){
			ans += "]";
			return ans;
		}else{
			ans += ";";
			Node *node = head;
			while(node){
				if(node -> item -> getType() == ANTIDOTE){
					ans += "Antidote";
				}else if(node -> item -> getType() == PHOENIXDOWNI){
					ans += "PhoenixDownI";
				}else if(node -> item -> getType() == PHOENIXDOWNII){
					ans += "PhoenixDownII";
				}else if(node -> item -> getType() == PHOENIXDOWNIII){
					ans += "PhoenixDownIII";
				}else if(node -> item -> getType() == PHOENIXDOWNIV){
					ans += "PhoenixDownIV";
				}
				if(node -> next != nullptr)
					ans += ",";
				else{
					ans += "]";

				}
				node = node -> next;
			}
			return ans;
		}
	}
};

class NormalBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
	Node *getHead(){
		return head;
	}
	NormalBag(){
		head = nullptr;
		tail = nullptr;
	}
	~NormalBag(){
		delete head;
		delete tail;
	}
	bool insertFirst(BaseItem *it){
		Node *tmp = new Node(it);
		if(cnt == 19)
			return false;
		if(tail == nullptr){
			head = tail = tmp;
		}else{
			tmp -> next = head;
			head = tmp;
		}
		++cnt;
		return true;
	}
	BaseItem * get(ItemType itemType){
		Node *node = head;
		while(node){
			if(node -> item -> getType() == itemType){
				return (node -> item);
			}
			node = node -> next;
		}
		return NULL;
	}
	string toString() const{
		string ans = "Bag[count=";
		ans += to_string(cnt);
		if(cnt == 0){
			ans += "]";
			return ans;
		}else{
			ans += ";";
			Node *node = head;
			while(node){
				if(node -> item -> getType() == ANTIDOTE){
					ans += "Antidote";
				}else if(node -> item -> getType() == PHOENIXDOWNI){
					ans += "PhoenixDownI";
				}else if(node -> item -> getType() == PHOENIXDOWNII){
					ans += "PhoenixDownII";
				}else if(node -> item -> getType() == PHOENIXDOWNIII){
					ans += "PhoenixDownIII";
				}else if(node -> item -> getType() == PHOENIXDOWNIV){
					ans += "PhoenixDownIV";
				}
				if(node -> next != nullptr)
					ans += ",";
				else{
					ans += "]";
				}
				node = node -> next;
			}
			return ans;
		}
	}
};

class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
	int pdI;
    BaseBag * bag;
    KnightType knightType;

public:
	BaseKnight(){
		id = 0;
		hp = 0;
		maxhp = 0;
		level = 0;
		gil = 0;
		antidote = 0;
		pdI = 0;
		bag = nullptr;
	}
    BaseKnight(int idd, int maxhpd, int leveld, int gild, int antidoted, int phoenixdownI, KnightType type){
		id = idd;
		maxhp = maxhpd;
		hp = maxhpd;
		gil = gild;
		antidote = antidoted;
		level = leveld;
		pdI = phoenixdownI;
		knightType = type;
		for(int i = 0; i < antidoted; ++i){
            bag->insertFirst(new AntiDote());
		}
		for(int i = 0; i < phoenixdownI; ++i){
            bag->insertFirst(new PhoenixDownI());
		}
	}
	int getId(){
		return id;
	}
	int getHp(){
		return hp;
	}
	int getMaxHp(){
		return maxhp;
	}
	int getLevel(){
		return level;
	}
	void setLevel(int x){
		level = min(10, x);
	}
	int getGil(){
		return gil;
	}
	int getAntidote(){
		return antidote;
	}
	int setGil(int x){
		if (x > 999){
			x -= 999;
			gil = 999;
			return x;
		}else{
			gil = x;
			return 0;
		}
	}
	void setHp(int x){
		hp = min(x, maxhp);
	}
	int getPhoenixDownI(){
		return pdI;
	}
	KnightType getType(){
		return knightType;
	}
	bool heal(){
		Node *node = bag -> getHead();
		while(node != nullptr){
			if(node -> item -> getType() == ANTIDOTE) node = node -> next;
			else if(!(node -> item -> canUse(this))) node = node -> next;
			//else bag -> get(node -> item -> getType()) -> use(this);
			else{
				node -> item -> use(this);
			}
		}
		if(node == nullptr){
			if(gil >= 100){
				gil -= 100;
				hp = maxhp / 2;
				return 1;
			}else return 0;
		}
		return 1;
	}
	bool insertItem(BaseItem *item){
		return bag -> insertFirst(item);
	}
    string toString() const;

};

class PaladinKnight: public BaseKnight{
private:
public:
	PaladinKnight(int idd, int maxhpd, int leveld, int gild, int antidoted, int phoenixdownI, KnightType type){
		id = idd;
		maxhp = maxhpd;
		hp = maxhpd;
		gil = gild;
		antidote = antidoted;
		level = leveld;
		pdI = phoenixdownI;
		knightType = type;
		bag = new PaladinBag;
		for(int i = 0; i < antidoted; ++i){
            bag->insertFirst(new AntiDote());
		}
		for(int i = 0; i < phoenixdownI; ++i){
            bag->insertFirst(new PhoenixDownI());
		}
	}
};

class LancelotKnight: public BaseKnight{
private:
public:
	LancelotKnight(int idd, int maxhpd, int leveld, int gild, int antidoted, int phoenixdownI, KnightType type){
		id = idd;
		maxhp = maxhpd;
		hp = maxhpd;
		gil = gild;
		antidote = antidoted;
		level = leveld;
		pdI = phoenixdownI;
		knightType = type;
		bag = new LancelotBag;
		for(int i = 0; i < antidoted; ++i){
            bag->insertFirst(new AntiDote());
		}
		for(int i = 0; i < phoenixdownI; ++i){
            bag->insertFirst(new PhoenixDownI());
		}
	}
};

class DragonKnight: public BaseKnight{
private:
public:
	DragonKnight(int idd, int maxhpd, int leveld, int gild, int antidoted, int phoenixdownI, KnightType type){
		id = idd;
		maxhp = maxhpd;
		hp = maxhpd;
		gil = gild;
		antidote = antidoted;
		level = leveld;
		pdI = phoenixdownI;
		knightType = type;
		bag = new DragonBag;
		for(int i = 0; i < phoenixdownI; ++i){
            bag->insertFirst(new PhoenixDownI());
		}
	}
};

class NormalKnight: public BaseKnight{
private:
public:
	NormalKnight(int idd, int maxhpd, int leveld, int gild, int antidoted, int phoenixdownI, KnightType type){
		id = idd;
		maxhp = maxhpd;
		hp = maxhpd;
		gil = gild;
		antidote = antidoted;
		level = leveld;
		pdI = phoenixdownI;
		knightType = type;
		bag = new NormalBag;
		for(int i = 0; i < antidoted; ++i){
            bag->insertFirst(new AntiDote());
		}
		for(int i = 0; i < phoenixdownI; ++i){
            bag->insertFirst(new PhoenixDownI());
		}
	}
};



enum OpponentType {
	MADBEAR = 1,
	BANDIT = 2,
	LORDLUPIN = 3,
	ELF = 4,
	TROLL = 5,
	TORNBERY = 6,
	CARDSQUEEN = 7,
	NINA = 8,
	DURIAN = 9,
	OMEGA = 10,
	HADES = 11,
	ULTIMECIA = 99
};

class BaseOpponent{
/*
	int id;
	int baseDmg;
	int gil;
	OpponentType type;
*/
public:
	virtual int getBaseDmg() = 0;
	virtual int getGil() = 0;
	virtual int getType() = 0;
};

class MadBear: public BaseOpponent{
private:
	int baseDmg;
	int gil;
	OpponentType type;
public:
	MadBear(){
		baseDmg = 10;
		gil = 100;
		type = MADBEAR;
	}
	int getBaseDmg(){
		return baseDmg;
	}
	int getGil(){
		return gil;
	}
	int getType(){
		return type;
	}
};

class Bandit: public BaseOpponent{
private:
	int baseDmg;
	int gil;
	OpponentType type;
public:
	Bandit(){
		baseDmg = 15;
		gil = 150;
		type = BANDIT;
	}
	int getBaseDmg(){
		return baseDmg;
	}
	int getGil(){
		return gil;
	}
	int getType(){
		return type;
	}
};

class LordLupin: public BaseOpponent{
private:
	int baseDmg;
	int gil;
	OpponentType type;
public:
	LordLupin(){
		baseDmg = 45;
		gil = 450;
		type = LORDLUPIN;
	}
	int getBaseDmg(){
		return baseDmg;
	}
	int getGil(){
		return gil;
	}
	int getType(){
		return type;
	}
};

class Elf: public BaseOpponent{
private:
	int baseDmg;
	int gil;
	OpponentType type;
public:
	Elf(){
		baseDmg = 75;
		gil = 750;
		type = ELF;
	}
	int getBaseDmg(){
		return baseDmg;
	}
	int getGil(){
		return gil;
	}
	int getType(){
		return type;
	}
};

class Troll: public BaseOpponent{
private:
	int baseDmg;
	int gil;
	OpponentType type;
public:
	Troll(){
		baseDmg = 95;
		gil = 800;
		type = TROLL;
	}
	int getBaseDmg(){
		return baseDmg;
	}
	int getGil(){
		return gil;
	}
	int getType(){
		return type;
	}
};

class Ultimecia: public BaseOpponent{
private:
	int hp;
	OpponentType type;
public:
	Ultimecia(){
		hp = 5000;
		type = ULTIMECIA;
	}
	int getHp(){
		return hp;
	}
	void setHp(int x){
		hp = x;
	}
	int getType(){
		return type;
	}
	int getBaseDmg(){
		return 0;
	}
	int getGil(){
		return 0;
	}
};

class Events {
private:
	int *eventList;
	int cnt;
public:
    int count() const{
		return cnt;
	}
    int get(int i) const{
		return eventList[i];
	}
	Events ( const string & file_events ){
		cout << file_events << '\n';
		ifstream in(file_events);
		in >> cnt;
		cout << cnt << '\n';
		eventList = new int[cnt];
		for(int i = 0; i < cnt; ++i){
			int x;
			in >> x;
			eventList[i] = x;
		}
		in.close();
		for(int i = 0; i < cnt; ++i){
			cout << eventList[i] << ' ';
		}
		cout << '\n';
	}
	~Events(){
		delete eventList;
		cnt = 0;
	}
};

class ArmyKnights {
private:
	int cnt;
	BaseKnight* knightList[1005];
	int defeatUlti = 0;
	bool hasSheild = 0;
	bool hasLance = 0;
	bool hasHair = 0;
	bool hasSword = 0;
	bool win;
public:
	bool isPrime(int x);
	int sqr(int x);
	bool isPyth(int x);
    ArmyKnights (const string & file_armyknights);

    ~ArmyKnights(){
		for(int i = 0; i <= cnt + 1; ++i)
			delete knightList[i];
		cnt = 0;
	}

	void addGil(int x){
		for(int i = cnt; i >= 1; --i){
			x = knightList[i] -> setGil(x);
			if(x == 0){
				break;
			}
		}
	}

    void printInfo() const;
    void printResult(bool win) const;

	BaseKnight * lastKnight() const{
	    if(cnt == 0)
            return nullptr;
        else return knightList[cnt];
	}
	int getLvl0(int id, int i){
		return (i + id) % 10 + 1;
	}

	int getDmg(int baseDmg , int lvl, int id, int i){
		return baseDmg * ((i + id) % 10 + 1 - lvl);
	}
	int meet1To5(BaseOpponent * opponent, int i, int id){
		BaseKnight * knight = lastKnight();
		BaseOpponent * oppo;
		if(knight -> getLevel() >= getLvl0(id, i) || knight -> getType() == LANCELOT || knight -> getType() == DRAGON || knight -> getType() == PALADIN)
			return opponent -> getGil();
		else{
			if((knight -> heal())) return 0;
			else{
                delete knightList[cnt];
                --cnt;
				return -1;
			}
		}
	}

	bool meetUltimecia(){
		Ultimecia *opponent = new Ultimecia();
		if(hasSword)
			return 1;
		if(!(hasHair && hasLance && hasSheild))
			return 0;
		while(lastKnight() != nullptr && opponent -> getHp() > 0){
			BaseKnight *knight = lastKnight();
			if(knight -> getType() == NORMAL){
				--cnt;
				delete knightList[cnt];
			}else{
				double base[3] = {0.06, 0.05, 0.075};
				int dmg = (int)(base[knight -> getType()] * (1.0 * knight -> getLevel()) * (1.0 * knight -> getHp()));
				opponent -> setHp(opponent -> getHp() - dmg);
				if(opponent -> getHp() > 0){
					--cnt;
					delete knightList[cnt];
				}
			}
		}
		if(opponent -> getHp() > 0 || cnt == 0)
			return 0;
		else return 1;
	}

    bool fight(BaseOpponent * opponent, int i, int id){
		if(id <= 5){
			int gil = meet1To5(opponent, i, id);
			if(gil >= 0){
				addGil(gil);
				return 1;
			}else return 0;
		}return 0;
	}
    bool adventure (Events *events){
		for(int event = 0; event < events -> count(); ++event){
			cout << "event " << event << ": " << events -> get(event) << '\n';
			if(events -> get(event) == 1){
				bool ok = fight(new MadBear, event, events -> get(event));
				if(!ok){
					--cnt;
					delete knightList[cnt];
				}
			}
			else if(events -> get(event) == 2){
				bool ok = fight(new Bandit, event, events -> get(event));
				if(!ok){
					--cnt;
					delete knightList[cnt];
				}
			}else if(events -> get(event) == 3){
				bool ok = fight(new LordLupin, event, events -> get(event));
				if(!ok){
					--cnt;
					delete knightList[cnt];
				}
			}else if(events -> get(event) == 4){
				bool ok = fight(new Elf, event, events -> get(event));
				if(!ok){
					--cnt;
					delete knightList[cnt];
				}
			}else if(events -> get(event) == 5){
				bool ok = fight(new Troll, event, events -> get(event));
				if(!ok){
					--cnt;
					delete knightList[cnt];
				}
			}else if(events -> get(event) == 95){
				if(!hasSheild)
					hasSheild = 1;
			}else if(events -> get(event) == 96){
				if(!hasLance)
					hasLance = 1;
			}else if(events -> get(event) == 97){
				if(!hasHair)
					hasHair = 1;
			}else if(events -> get(event) == 98){
				if(hasLance && hasSheild && hasHair)
					hasSword = 1;
			}else if(events -> get(event) == 99){
				bool ok = meetUltimecia();
				if(ok)
					defeatUlti = 1;
				else
					defeatUlti = -1;
			}
			printInfo();
		}
		if(defeatUlti == 1) return true;
		else return false;
	}
    int count() const{
		return cnt;
	}


    bool hasPaladinShield() const{
		return hasSheild;
	}
    bool hasLancelotSpear() const{
		return hasLance;
	}
    bool hasGuinevereHair() const{
		return hasHair;
	}
    bool hasExcaliburSword() const{
		return hasSword;
	}

};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(){
		delete armyKnights;
		delete events;
	} // TODO:

    void loadArmyKnights(const string & name){
		armyKnights = new ArmyKnights(name);
	}
    void loadEvents(const string &name){
		events = new Events(name);
	}
    void run(){
		bool ok = armyKnights -> adventure(events);
		armyKnights -> printResult(ok);
	}
};

#endif // __KNIGHT2_H__
