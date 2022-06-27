#pragma once
#include <memory>
#include<string>
#include<vector>
#include"../Token.h"
using namespace std;


class CompileUnit : public Token {



public: string path;
public: string file_name;
public: string package;
public: P_Token import_class_list;
public: P_Token type_declaration_list;
		
//默认构造器
public: CompileUnit();


public: virtual ~CompileUnit();

};


