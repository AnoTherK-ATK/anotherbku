#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum KnightType { PALADIN = 0, LANCELOT = 1, DRAGON = 2, NORMAL = 3 };
enum ItemType {ANTIDOTE = 0, PHOENIXDOWNI = 1, PHOENIXDOWNII = 2, PHOENIXDOWNIII = 3, PHOENIXDOWNIV = 4};

class BaseItem {
public:
	BaseItem(){}
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
	virtual ItemType getType() = 0;
};

class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item) = 0;
    virtual BaseItem * get(ItemType itemType) = 0;
    virtual string toString() const = 0;
};



bool isPrime(int x){
	if(x < 2) return false;
	for(int i = 2; i * i <= x; ++i){
		if(x % i == 0) return false;
	}
	return true;
}

int sqr(int x){
	return x * x;
}

bool isPyth(int x){
	int arr[3];
	for(int i = 0; i < 3; ++i){
		arr[i] = x % 10;
		x = x / 10;
	}
	if(sqr(arr[0]) + sqr(arr[1]) == sqrt(arr[2])) return true;
	if(sqr(arr[0]) + sqr(arr[2]) == sqrt(arr[1])) return true;
	if(sqr(arr[2]) + sqr(arr[1]) == sqrt(arr[0])) return true;
	return false;
}

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
    BaseKnight(int id, int maxhp, int level, int gild, int antidote, int phoenixdownI, KnightType type){
		id = id;
		maxhp = maxhp;
		hp = maxhp;
		gil = gild;
		antidote;
		level = level;
		pdI = phoenixdownI;
		knightType = type;
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
	int getAntidote(){
		return antidote;
	}
	int getPhoenixDownI(){
		return pdI;
	}
	KnightType getType(){
		return knightType;
	}
	BaseItem * findPhoenix(){
		
	}
    string toString() const;
	
};

class PaladinKnight: public BaseKnight{
private:
public:
	PaladinKnight(BaseKnight * x){
		id = x -> getId();
		maxhp = x -> getMaxHp();
		hp = x -> getHp();
		gil = x -> getGil();
		antidote = x-> getAntidote();
		level = x -> getLevel();
		knightType = PALADIN;
	}
};

class LancelotKnight: public BaseKnight{
private:
public:
	LancelotKnight(BaseKnight * x){	
		id = x -> getId();
		maxhp = x -> getMaxHp();
		hp = x -> getHp();
		gil = x -> getGil();
		antidote = x-> getAntidote();
		level = x -> getLevel();
		knightType = LANCELOT;
	}
};

class DragonKnight: public BaseKnight{
private:
public:
	DragonKnight(BaseKnight * x){
		id = x -> getId();
		maxhp = x -> getMaxHp();
		hp = x -> getHp();
		gil = x -> getGil();
		antidote = x-> getAntidote();
		level = x -> getLevel();
		knightType = DRAGON;
	}
};

class NormalKnight: public BaseKnight{
private:
public:
	NormalKnight(BaseKnight * x){
		id = x -> getId();
		maxhp = x -> getMaxHp();
		hp = x -> getHp();
		gil = x -> getGil();
		antidote = x-> getAntidote();
		level = x -> getLevel();
		knightType = NORMAL;
	}
};



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



struct Node{
	BaseItem* item;
	Node* next;
	Node (BaseItem *it){
		item = it;
		next = nullptr;
	}
};

class PaladinBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
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
					return ans;
				}
				node = node -> next;
			}
		}
	}
};

class DragonBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
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
					return ans;
				}
				node = node -> next;
			}
		}
	}
};

class LancelotBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
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
					return ans;
				}
				node = node -> next;
			}
		}
	}
};

class NormalBag: public BaseBag{
private:
	Node *head;
	Node *tail;
	int cnt;
public:
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
					return ans;
				}
				node = node -> next;
			}
		}
	}
};

int getLvl0(int id, int i){
	return (i + id) % 10 + 1;
}

int getDmg(int baseDmg , int lvl, int id, int i){
	return baseDmg * ((i + id) % 10 + 1 - lvl);
}

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
	HADES = 11
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
		ifstream in(file_events);
		in >> cnt;
		eventList = new int[cnt];
		for(int i = 0; i < cnt; ++i){
			int x;
			in >> x;
			eventList[i] = x;
		}
		in.close();
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
	bool defeatUlti = 0;
	bool hasSheild = 0;
	bool hasLance = 0;
	bool hasHair = 0;
	bool hasSword = 0;
	bool win;
public:
    ArmyKnights (const string & file_armyknights){
		ifstream in(file_armyknights);
		in >> cnt;
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
				knightList[i] = new BaseKnight(i, hp, lv, gil, antidote, phoenix, PALADIN);
			else if(hp == 888)
				knightList[i] = new BaseKnight(i, hp, lv, gil, antidote, phoenix, LANCELOT);
			else if(isPyth(hp))
				knightList[i] = new BaseKnight(i, hp, lv, gil, antidote, phoenix, DRAGON);
			else
				knightList[i] = new BaseKnight(i, hp, lv, gil, antidote, phoenix, NORMAL);
		}
		in.close();
	}
    ~ArmyKnights(){
		delete knightList;
		cnt = 0;
	}

	void addGil(int x){
		for(int i = cnt - 1; i >= 0; --i){
			x = knightList[i] -> setGil(x);
			if(x == 0){
				break;
			}
		}
	}

	BaseKnight * lastKnight() const{
		if(cnt == 0)
			return nullptr;
		int idx = cnt - 1;
		if(knightList[idx] -> getType() == PALADIN)
			return new PaladinKnight(knightList[idx]);
		else if(knightList[idx] -> getType() == DRAGON)
			return new DragonKnight(knightList[idx]);
		else if(knightList[idx] -> getType() == LANCELOT)
			return new LancelotKnight(knightList[idx]);
		else 
			return new NormalKnight(knightList[idx]);
	}
	bool meet1To5(BaseOpponent * opponent){
		BaseKnight * knight = lastKnight();
	}

    bool fight(BaseOpponent * opponent, int i, int id){
		
	}
    bool adventure (Events *events){
		for(int event = 0; event < events -> count(); ++event){
			printInfo();
		}
		if(defeatUlti == true) return true;
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

    void printInfo() const;
    void printResult(bool win) const;
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string & name){
		armyKnights = new ArmyKnights(name);
	}
    void loadEvents(const string &name){
		events = new Events(name);
	}
    void run(){
		for(int i = 0; i < events -> count(); ++i){

		}
	}
};

#endif // __KNIGHT2_H__