%{
   #include "stdio.h"
   #include "stdlib.h"
   #include<string.h>
   #include "SLR\lex.yy.h"

    struct C_Lex_Word lex_word[500];
    struct C_Lex_Word *p_lex_word=lex_word;

void write_word(struct C_Lex_Word *p_lex_word,char *yytext,char *symbol_name){
  p_lex_word->content = (char *)malloc(sizeof(char)*(strlen(yytext)+1));
  strcpy(p_lex_word->content, yytext);
  p_lex_word->type = (char *)malloc(sizeof(char)*(strlen(symbol_name)+1));
  strcpy(p_lex_word->type, symbol_name);
}

%}


IDENTIFIER [_0-9a-zA-Z]+
StringLiteral \"(\\.|[^\\"])*\"
%%


{IDENTIFIER} {
  write_word(p_lex_word,yytext,"'IDENTIFIER'");
  p_lex_word++;
}

"{" {
  write_word(p_lex_word,yytext,"'LEFT_BRACE'");
  p_lex_word++;
}

"}" {
  write_word(p_lex_word,yytext,"'RIGHT_BRACE'");
  p_lex_word++;
}

"<" {
  write_word(p_lex_word,yytext,"'LEFT_ANGLE_BRACKET'");
  p_lex_word++;
}

">" {
  write_word(p_lex_word,yytext,"'RIGHT_ANGLE_BRACKET'");
  p_lex_word++;
}

"," {
  write_word(p_lex_word,yytext,"'COMMA'");
  p_lex_word++;
}

"?" {
  write_word(p_lex_word,yytext,"'QUESTION'");
  p_lex_word++;
}

"[" {
  write_word(p_lex_word,yytext,"'LEFT_BRACKET'");
  p_lex_word++;
}

"]" {
  write_word(p_lex_word,yytext,"'RIGHT_BRACKET'");
  p_lex_word++;
}

"(" {
  write_word(p_lex_word,yytext,"'('");
  p_lex_word++;
}

")" {
  write_word(p_lex_word,yytext,"')'");
  p_lex_word++;
}

";" {
  write_word(p_lex_word,yytext,"'semicolon'");
  p_lex_word++;
}

{StringLiteral} {
  write_word(p_lex_word,yytext,"'StringLiteral'");
  p_lex_word++;
}

"\." {
  write_word(p_lex_word,yytext,"'SPOT'");
  p_lex_word++;
}

"*" {
  write_word(p_lex_word,yytext,"'STAR'");
  p_lex_word++;
}

%%

void c_word_parser(char* file_path,struct C_Lex_Word **beg,struct C_Lex_Word **end){
   int i1=0;
   for(i1=0;i1<500;i1++){
	if(lex_word[i1].type!=NULL){
	   free(lex_word[i1].type);
	   lex_word[i1].type=NULL;
	}

        if(lex_word[i1].content!=NULL){
	   free(lex_word[i1].content);
	   lex_word[i1].content=NULL;
	}
   }
   p_lex_word=lex_word;

   fopen_s(&yyin, file_path, "r");
   yylex();
   fclose(yyin);
   *beg=lex_word;
   *end=p_lex_word;
}



int yywrap()

{
    return 1;
}
