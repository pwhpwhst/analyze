#include"symbols\Env.h"
#include"symbols\CompileInfo.h"
#include"slr.h"
#include"symbols\Type.h"
#include"symbols\Tag.h"
#include"SLR\Lex_Word.h"
#include"symbols\PrimarySymbolConverter.h"

#include <vector>




void testForSynax(){
//string rule_file="E:\\Users\\Administrator\\Desktop\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\pwh的试验\\ruleForLexical.txt";
//string compile_file="E:\\Users\\Administrator\\Desktop\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\pwh的试验\\testForLexical.txt";

string rule_file="C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\rule.txt";
//string compile_file= "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh.java";
string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java";
string ignore_file_path = "C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\ignore.txt";

//string rule_file="F:\\codeWeaponStore\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\rule.txt";
//string compile_file="F:\\codeWeaponStore\\project2018.3_2018.9\\2018.3~2018.9\\编译原理实验\\微型编译器\\test.txt";
Env env;
//



cout<<"尝试将java转成符号表！"<<endl;
Slr slr;
CompileInfo compileInfo;
slr.slr( rule_file, compile_file, ignore_file_path,env,compileInfo);
cout<<"检测开始！"<<endl;

if(compileInfo.errInfo!=""){
    cout<<compileInfo.errInfo<<endl;
}



cout<<"检测完成！"<<endl;

}



void testForLexer(){
	//string compile_file="C:\\Users\\Administrator\\Desktop\\代码武器库-总\\万花筒写轮眼\\kaleidoscope-writing-wheel-eye\\resources\\java范本\\pwh.java";
	string compile_file = "C:\\Users\\Administrator\\Desktop\\javaSpecification\\tomcat-main\\tomcat-main\\java\\org\\apache\\catalina\\ant\\AbstractCatalinaCommandTask.java";

Env env;
vector<P_Lex_Word>  total_lex_word_list;
total_lex_word_list.clear();
word_parser(compile_file,total_lex_word_list,env);

PrimarySymbolConverter primarySymbolConverter;

vector<P_Lex_Word>  primary_total_lex_word_list;



for(P_Lex_Word &e:total_lex_word_list){
	primary_total_lex_word_list.push_back(P_Lex_Word(new Lex_Word()));
	primarySymbolConverter.convert(*e,*primary_total_lex_word_list.back());
}

for (P_Lex_Word &e : primary_total_lex_word_list) {
	cout << e->type <<","<< e->content << endl;
}

}




int main(){
	testForSynax();
	//testForLexer();
}
