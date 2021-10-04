#include "Item.h"
#include "Rule.h"
#include <set>
using namespace std;





Item::Item() {
}
//
Item::Item(const P_Rule &rule, int status, set<string>& end_for_symbol) {
	this->rule = rule;
	this->status = status;
	this->end_for_symbol.insert(end_for_symbol.begin(), end_for_symbol.end());
}

Item::Item(const P_Rule &rule, int status) {
	this->rule = rule;
	this->status = status;
}


Item::Item(const Item &item) {
	this->rule = item.rule;
	this->status = item.status;
	this->end_for_symbol = item.end_for_symbol;
}


Item::~Item() {
	this->rule = nullptr;

}




