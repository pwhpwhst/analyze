#pragma once
#include"Rule.h"
#include <memory>
#include <set>
using namespace std;

class Item {

public: P_Rule rule;
public: int status;
public: set<string> end_for_symbol;


		//Ĭ�Ϲ�����
public: Item();

		//�Զ��幹����
public: Item(const P_Rule &rule, int status, set<string>& end_for_symbol);

public: Item(const P_Rule &rule, int status);

		//����
public: Item(const Item &item);

public: virtual ~Item();


};

typedef std::shared_ptr<Item> P_Item;