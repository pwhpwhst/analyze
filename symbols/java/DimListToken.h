#pragma once
#include <memory>
#include <deque>
#include "../Token.h"

using namespace std;



class DimListToken : public Token  {


public: string resultType;
public: bool isMultiParameters;
public: bool isReceiverParameter;
public: bool isThreeSpot;
public: string name;
public: int num;

public: DimListToken();
public: virtual ~DimListToken();

};

typedef std::shared_ptr<DimListToken> P_DimListToken;