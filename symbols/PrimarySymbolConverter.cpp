#include "PrimarySymbolConverter.h"
#include "..\SLR\Lex_Word.h"



PrimarySymbolConverter::PrimarySymbolConverter() {

	string key_word_array[] = { "default","interface","throws","this","package","import","public","protected","private","static","abstract","final","native","synchronized","transient","volatile",
		"void","class","extends","super","implements","byte","short","char","int","long","float","double","boolean","null","enum","new","instanceof" };
	for (auto &e : key_word_array) {
		key_word_set.insert(e);
	}
	
}

PrimarySymbolConverter::~PrimarySymbolConverter() {

}


void PrimarySymbolConverter::identifierMap(string idName, string type) {
	env[idName] =type;
}

void PrimarySymbolConverter::convert(Lex_Word *oriLexWord, Lex_Word *newLexWord) {
	newLexWord->content = oriLexWord->content;

	//位置统计 begin
	if (oriLexWord->type == "'NEXT_LINE'") {
		lineNum++;
		colNum = 0;
	}
	else {
		colNum++;
	}
	newLexWord->lineNum = lineNum;
	newLexWord->colNum = colNum;
	newLexWord->index = oriLexWord->index;
	//位置统计 end

	//注释过滤 begin
	if (is_comment1) {
		if (oriLexWord->type != "'NEXT_LINE'") {
			newLexWord->type = "0";
			return;
		}
		else {
			newLexWord->type = "0";
			is_comment1 = false;
			return;
		}
	}
	else {
		if (oriLexWord->type == "'COMMENT1'") {
			newLexWord->type = "0";
			is_comment1 = true;
			return;
		}
	}

	if (is_comment2) {

		if (oriLexWord->type == "'SPOT_STAR'") {
			newLexWord->type = "0";
			spotStar = true;
			return;
		}else if (oriLexWord->type == "'SLASH'") {
			if (spotStar) {
				newLexWord->type = "0";
				spotStar = false;
				is_comment2 = false;
				return;
			}
			else {
				newLexWord->type = "0";
				spotStar = false;
				return;
			}
		}else if (oriLexWord->type != "'END_COMMENT'") {
			newLexWord->type = "0";
			spotStar = false;
			return;
		}
		else {
			newLexWord->type = "0";
			spotStar = false;
			is_comment2 = false;
			return;
		}
	}
	else {
		if (oriLexWord->type == "'COMMENT2'") {
			newLexWord->type = "0";
			is_comment2 = true;
			return;
		}
	}

	if (is_comment3) {
		if (oriLexWord->type == "'SPOT_STAR'") {
			newLexWord->type = "0";
			spotStar = true;
			return;
		}
		else if (oriLexWord->type == "'SLASH'") {
			if (spotStar) {
				newLexWord->type = "0";
				spotStar = false;
				is_comment3 = false;
				return;
			}
			else {
				newLexWord->type = "0";
				spotStar = false;
				return;
			}
		}
		else if (oriLexWord->type != "'END_COMMENT'") {
			newLexWord->type = "0";
			spotStar = false;
			return;
		}
		else {
			newLexWord->type = "0";
			spotStar = false;
			is_comment3 = false;
			return;
		}
	}
	else {
		if (oriLexWord->type == "'COMMENT3'") {
			newLexWord->type = "0";
			is_comment3 = true;
			return;
		}
	}
	//注释过滤 end


	if (oriLexWord->type == "'NEXT_LINE'") {
		newLexWord->type = "0";
		return;
	}


	if (oriLexWord->type == "'IDENTIFIER'") {

		if (key_word_set.count(oriLexWord->content) > 0) {
			newLexWord->type = "'"+oriLexWord->content+"'";
		}
		else if (oriLexWord->content == "true"| oriLexWord->content == "false") {
			newLexWord->type = "'BooleanLiteral'";
		}
		else if (env.count(oriLexWord->content) == 1) {
			newLexWord->type =  env[oriLexWord->content] ;
		}else {
			newLexWord->type = oriLexWord->type;
		}

	}else {
		newLexWord->type = oriLexWord->type;
	}



	
}

void PrimarySymbolConverter::initPositionInfo() {
	lineNum = 1;
	colNum = 0;
}
