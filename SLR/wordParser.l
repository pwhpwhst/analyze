%{
   #include "stdio.h"
   #include "stdlib.h"
   #include<string.h>
   #include "SLR\lex.yy.h"

    struct C_Lex_Word *lex_word=NULL;
    struct C_Lex_Word *p_lex_word=NULL;
    int buffer_size=0;
    int rest_size=0;

void write_word(char *yytext,char *symbol_name){

	int incremential = 32000;

	if(rest_size==0){
		struct C_Lex_Word * new_lex_word=(struct C_Lex_Word *)malloc(sizeof(struct C_Lex_Word)*(buffer_size+ incremential+1));
		int i1=0;
		for(i1=0;i1<(buffer_size+ incremential);i1++){
			if(i1<buffer_size){
				/*
				new_lex_word[i1].type=lex_word[i1].type;
				new_lex_word[i1].content=lex_word[i1].content;
				*/
				new_lex_word[i1].type = (char *)malloc(sizeof(char)*(strlen(lex_word[i1].type) + 1));
				strcpy(new_lex_word[i1].type, lex_word[i1].type);
				new_lex_word[i1].content = (char *)malloc(sizeof(char)*(strlen(lex_word[i1].content) + 1));
				strcpy(new_lex_word[i1].content, lex_word[i1].content);
				free(lex_word[i1].type);
				free(lex_word[i1].content);
				
			}else{
				new_lex_word[i1].type=NULL;
				new_lex_word[i1].content=NULL;
			}
		}
		free(lex_word);
		lex_word=new_lex_word;
		p_lex_word=new_lex_word+buffer_size;
		buffer_size+= incremential;
		rest_size=buffer_size;
	}

  p_lex_word->content = (char *)malloc(sizeof(char)*(strlen(yytext)+1));
  strcpy(p_lex_word->content, yytext);
  p_lex_word->type = (char *)malloc(sizeof(char)*(strlen(symbol_name)+1));
  strcpy(p_lex_word->type, symbol_name);
  rest_size--;
  p_lex_word++;
}


%}

IDENTIFIER [_0-9a-zA-Z]+
StringLiteral \"((\\['"?\\abfnrtvu0-9])|[^\\\n\"])*\"
IntegerLiteral [-+]?[0-9]+[lL]?
CharacterLiteral \'((\\['"?\\abfnrtvu0-9]+)|[^\\\'])\'


DecimalFloatingPointLiteral1 [0-9]+\.([0-9]+)?([eE][+-]?[0-9]+)?[fFdD]?
DecimalFloatingPointLiteral2 \.[0-9]+([eE][+-]?[0-9]+)?[fFdD]?
DecimalFloatingPointLiteral3 [0-9]+[eE][+-]?[0-9]+[fFdD]?
DecimalFloatingPointLiteral4 [0-9]+([eE][+-]?[0-9]+)?[fFdD]
DecimalFloatingPointLiteral ({DecimalFloatingPointLiteral1}|{DecimalFloatingPointLiteral2}{DecimalFloatingPointLiteral3}|{DecimalFloatingPointLiteral4})

HexDigits [0-9a-fA-F](([0-9a-fA-F]+)?[0-9a-fA-F])?
HexNumeral 0[xX]{HexDigits}
HexadecimalFloatingPointLiteral ((HexNumeral[\.]?)|(0[xX]({HexDigits})?\.{HexDigits}))[pP][+-]?[0-9]+[fFdD]?

FloatingPointLiteral (({DecimalFloatingPointLiteral})|({HexadecimalFloatingPointLiteral}))



U       [\x80-\xbf]
U2      [\xc2-\xdf]
U3      [\xe0-\xef]
U4      [\xf0-\xf4]
NO_ENGLISH_CH {U2}{U}|{U3}{U}{U}|{U4}{U}{U}{U} 
SPACE ([ ])
SPACE2 ({SPACE}|\n)
AT_INTERFACE @{SPACE}*interface
SPOT_STAR \.{SPACE}*\*
COMMA_RIGHT_BRACE ,{SPACE2}*\}
COMMA_semicolon ,{SPACE2}*;



%%




{IDENTIFIER} {
  write_word(yytext,"'IDENTIFIER'");
}

{COMMA_RIGHT_BRACE} {
  write_word(yytext,"'COMMA_RIGHT_BRACE'");
}

{COMMA_semicolon} {
  write_word(yytext,"'COMMA_semicolon'");
}


"||" {
  write_word(yytext,"'OR'");
}

"&&" {
  write_word(yytext,"'AND'");
}

"|" {
  write_word(yytext,"'BIT_OR'");
}

"^" {
  write_word(yytext,"'CARET'");
}

"&" {
  write_word(yytext,"'BIT_AND'");
}

"==" {
  write_word(yytext,"'DB_EQUAL'");
}

"!=" {
  write_word(yytext,"'NOT_EQUAL'");
}

"<" {
  write_word(yytext,"'LEFT_ANGLE_BRACKET'");
}



">" {
  write_word(yytext,"'RIGHT_ANGLE_BRACKET'");
}



"<=" {
  write_word(yytext,"'LT_EQUAL'");
}

">=" {
  write_word(yytext,"'GT_EQUAL'");
}




"+" {
  write_word(yytext,"'PLUS'");
}

"-" {
  write_word(yytext,"'SUBTRACT'");
}

"*" {
  write_word(yytext,"'STAR'");
}

"/" {
  write_word(yytext,"'SLASH'");
}

"%" {
  write_word(yytext,"'PRECENTAGE'");
}



"//" {
  write_word(yytext,"'COMMENT1'");
}

"++" {
  write_word(yytext,"'TWO_PLUS'");
}

"--" {
  write_word(yytext,"'TWO_SUBTRACT'");
}

":" {
  write_word(yytext,"'COLON'");
}

"::" {
  write_word(yytext,"'TWO_COLON'");
}

"@" {
  write_word(yytext,"'AT'");
}

"!" {
  write_word(yytext,"'SURPRISE'");
}



"/**" {
  write_word(yytext,"'COMMENT2'");
}

"/*" {
  write_word(yytext,"'COMMENT3'");
}

"*/" {
  write_word(yytext,"'END_COMMENT'");
}


"\n" {
  write_word(yytext,"'NEXT_LINE'");
}


"{" {
  write_word(yytext,"'LEFT_BRACE'");
}

"}" {
  write_word(yytext,"'RIGHT_BRACE'");
}



"," {
  write_word(yytext,"'COMMA'");
}

"=" {
  write_word(yytext,"'EQUAL'");
}

"*=" {
  write_word(yytext,"'MULTI_EQUAL'");
}

"/=" {
  write_word(yytext,"'DIVIDE_EQUAL'");
}

"%=" {
  write_word(yytext,"'PRECENTAGE_EQUAL'");
}



"+=" {
  write_word(yytext,"'PLUS_EQUAL'");
}

"-=" {
  write_word(yytext,"'SUBTRACT_EQUAL'");
}

"<<=" {
  write_word(yytext,"'LEFT_SHIFT_EQUAL'");
}

">>=" {
  write_word(yytext,"'RIGHT_SHIFT_EQUAL'");
}

">>>=" {
  write_word(yytext,"'RIGHT_SHIFT2_EQUAL'");
}

"<<" {
  write_word(yytext,"'LEFT_SHIFT'");
}

">>" {
  write_word(yytext,"'RIGHT_SHIFT'");
}

">>>" {
  write_word(yytext,"'RIGHT_SHIFT2'");
}

"&=" {
  write_word(yytext,"'AND_EQUAL'");
}

"^=" {
  write_word(yytext,"'XOR_EQUAL'");
}

"|=" {
  write_word(yytext,"'OR_EQUAL'");
}

"->" {
  write_word(yytext,"'LAMBDA_TO'");
}


"?" {
  write_word(yytext,"'QUESTION'");
}

"[" {
  write_word(yytext,"'LEFT_BRACKET'");
}

"]" {
  write_word(yytext,"'RIGHT_BRACKET'");
}

"(" {
  write_word(yytext,"'LEFT_PARENTHESES'");
}

")" {
  write_word(yytext,"'RIGHT_PARENTHESES'");
}

";" {
  write_word(yytext,"'semicolon'");
}

{StringLiteral} {
  write_word(yytext,"'StringLiteral'");
}

{IntegerLiteral} {
  write_word(yytext,"'IntegerLiteral'");
}

{CharacterLiteral} {
  write_word(yytext,"'CharacterLiteral'");
}

{FloatingPointLiteral} {
  write_word(yytext,"'FloatingPointLiteral'");
}

{NO_ENGLISH_CH} {
  write_word(yytext,"'NO_ENGLISH_CH'");
}

{AT_INTERFACE} {
  write_word(yytext,"'AT_INTERFACE'");
}

{SPOT_STAR} {
  write_word(yytext,"'SPOT_STAR'");
}

"`" {
  write_word(yytext,"'EXE_QUOTES'");
}

"~" {
  write_word(yytext,"'TILDE'");
}



"\." {
  write_word(yytext,"'SPOT'");
}

"\.\.\." {
  write_word(yytext,"'THREE_SPOT'");
}







"#" {
  write_word(yytext,"'POUND'");
}

"'" {
  write_word(yytext,"'SINGLE_QUOTES'");
}

"$" {
  write_word(yytext,"'DOLLAR'");
}



"\\" {
  write_word(yytext,"'BACK_SLASH'");
}

"\"" {
  write_word(yytext,"'DOUBLE_QUOTES'");
}




{SPACE} {}

"\t" {

}

%%

void c_word_parser(char* file_path,struct C_Lex_Word **beg,struct C_Lex_Word **end){

   fopen_s(&yyin, file_path, "r");
   yylex();
   fclose(yyin);
   *beg=lex_word;
   *end=p_lex_word;
}

void c_free(){
	int i1;
   for(i1=0;i1<buffer_size;i1++){
	if(lex_word[i1].type!=NULL){
	   free(lex_word[i1].type);
	   lex_word[i1].type=NULL;
	}

    if(lex_word[i1].content!=NULL){
	   free(lex_word[i1].content);
	   lex_word[i1].content=NULL;
	}
   }

    free(lex_word);
    lex_word=NULL;

    p_lex_word=NULL;
	buffer_size=0;
	rest_size=0;
}


int yywrap()

{
    return 1;
}
