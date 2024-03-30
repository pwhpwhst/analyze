#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R004_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R004Analyzer.h"
using namespace std;
using namespace boost;



SDT_R004_Factory SDT_R004_Factory::instance;
SDT_R004_Factory::SDT_R004_Factory() {
	control_Param = {
   { "R004_ele_begin_0", 0 },
   { "R004_CompilationUnit_0", 1 },
   { "R004_CompilationUnit_1", 2 },
   { "R004_CompilationUnit_2", 3 },
   { "R004_CompilationUnit_3", 4 },
   { "R004_CompilationUnit_4", 5 },
   { "R004_CompilationUnit_5", 6 },
   { "R004_CompilationUnit_6", 7 },
   { "R004_PackageDeclaration_0", 8 },
   { "R004_PackageDeclaration_1", 9 },
   { "R004_DetailIdentifier_0", 10 },
   { "R004_DetailIdentifier_1", 11 },
   { "R004_Identifier_0", 12 },
   { "R004_ImportDeclarationList_0", 13 },
   { "R004_ImportDeclarationList_1", 14 },
   { "R004_ImportDeclaration_0", 15 },
   { "R004_ImportDeclaration_1", 16 },
   { "R004_ImportDeclaration_2", 17 },
   { "R004_ImportDeclaration_3", 18 },
   { "R004_TypeDeclarationList_0", 19 },
   { "R004_TypeDeclaration_0", 20 },
   { "R004_TypeDeclaration_1", 21 },
   { "R004_TypeDeclaration_2", 22 },
   { "R004_ClassDeclaration_0", 23 },
   { "R004_ClassDeclaration_1", 24 },
   { "R004_InterfaceDeclaration_0", 25 },
   { "R004_InterfaceDeclaration_1", 26 },
   { "R004_NormalClassDeclaration_0", 27 },
   { "R004_NormalClassDeclaration_1", 28 },
   { "R004_NormalClassDeclaration_2", 29 },
   { "R004_NormalClassDeclaration_3", 30 },
   { "R004_NormalClassDeclaration_4", 31 },
   { "R004_NormalClassDeclaration_5", 32 },
   { "R004_NormalClassDeclaration_6", 33 },
   { "R004_NormalClassDeclaration_7", 34 },
   { "R004_NormalClassDeclaration_8", 35 },
   { "R004_NormalClassDeclaration_9", 36 },
   { "R004_NormalClassDeclaration_10", 37 },
   { "R004_NormalClassDeclaration_11", 38 },
   { "R004_NormalClassDeclaration_12", 39 },
   { "R004_NormalClassDeclaration_13", 40 },
   { "R004_NormalClassDeclaration_14", 41 },
   { "R004_NormalClassDeclaration_15", 42 },
   { "R004_EnumDeclaration_0", 43 },
   { "R004_EnumDeclaration_1", 44 },
   { "R004_EnumDeclaration_2", 45 },
   { "R004_EnumDeclaration_3", 46 },
   { "R004_NormalInterfaceDeclaration_0", 47 },
   { "R004_NormalInterfaceDeclaration_1", 48 },
   { "R004_NormalInterfaceDeclaration_2", 49 },
   { "R004_NormalInterfaceDeclaration_3", 50 },
   { "R004_NormalInterfaceDeclaration_4", 51 },
   { "R004_NormalInterfaceDeclaration_5", 52 },
   { "R004_NormalInterfaceDeclaration_6", 53 },
   { "R004_NormalInterfaceDeclaration_7", 54 },
   { "R004_ExtendsInterfaces_0", 55 },
   { "R004_AnnotationTypeDeclaration_0", 56 },
   { "R004_AnnotationTypeDeclaration_1", 57 },
   { "R004_AnnotationTypeDeclaration_2", 58 },
   { "R004_AnnotationTypeDeclaration_3", 59 },
   { "R004_ClassBody_0", 60 },
   { "R004_ClassBodyDeclarationList_0", 61 },
   { "R004_ClassBodyDeclarationList_1", 62 },
   { "R004_ClassBodyDeclaration_0", 63 },
   { "R004_ClassBodyDeclaration_1", 64 },
   { "R004_ClassStatementPrefix_0", 65 },
   { "R004_ClassStatementPrefix_1", 66 },
   { "R004_NonBraceAndSemicolon_0", 67 },
   { "R004_NonBraceAndSemicolon_1", 68 },
   { "R004_NonBraceAndSemicolon_2", 69 },
   { "R004_NonBraceAndSemicolon_3", 70 },
   { "R004_NonBraceAndSemicolon_4", 71 },
   { "R004_ModifierList_0", 72 },
   { "R004_ModifierList_1", 73 },
   { "R004_AnnotationContent_0", 74 },
   { "R004_AnnotationContentStatements_0", 75 },
   { "R004_AnnotationContentStatements_1", 76 },
   { "R004_NonPARENTHESES_0", 77 },
   { "R004_NonPARENTHESES_1", 78 },
   { "R004_NonPARENTHESES_2", 79 },
   { "R004_NonPARENTHESES_3", 80 },
   { "R004_NonPARENTHESES_4", 81 },
   { "R004_NonPARENTHESES_5", 82 },
   { "R004_NonPARENTHESES_6", 83 },
   { "R004_NonPARENTHESES_7", 84 },
   { "R004_NonPARENTHESES_8", 85 },
   { "R004_NonPARENTHESES_9", 86 },
   { "R004_NonPARENTHESES_10", 87 },
   { "R004_StatementEle_0", 88 },
   { "R004_StatementEle_1", 89 },
   { "R004_StatementEle_2", 90 },
   { "R004_StatementEle_3", 91 },
   { "R004_StatementEle_4", 92 },
   { "R004_StatementEle_5", 93 },
   { "R004_StatementEle_6", 94 },
   { "R004_StatementEle_7", 95 },
   { "R004_StatementEle_8", 96 },
   { "R004_StatementEle_9", 97 },
   { "R004_StatementEle_10", 98 },
   { "R004_StatementEle_11", 99 },
   { "R004_StatementEle_12", 100 },
   { "R004_StatementEle_13", 101 },
   { "R004_StatementEle_14", 102 },
   { "R004_StatementEle_15", 103 },
   { "R004_StatementEle_16", 104 },
   { "R004_StatementEle_17", 105 },
   { "R004_StatementEle_18", 106 },
   { "R004_StatementEle_19", 107 },
   { "R004_StatementEle_20", 108 },
   { "R004_StatementEle_21", 109 },
   { "R004_StatementEle_22", 110 },
   { "R004_StatementEle_23", 111 },
   { "R004_StatementEle_24", 112 },
   { "R004_StatementEle_25", 113 },
   { "R004_StatementEle_26", 114 },
   { "R004_StatementEle_27", 115 },
   { "R004_StatementEle_28", 116 },
   { "R004_StatementEle_29", 117 },
   { "R004_StatementEle_30", 118 },
   { "R004_StatementEle_31", 119 },
   { "R004_StatementEle_32", 120 },
   { "R004_StatementEle_33", 121 },
   { "R004_StatementEle_34", 122 },
   { "R004_StatementEle_35", 123 },
   { "R004_StatementEle_36", 124 },
   { "R004_StatementEle_37", 125 },
   { "R004_StatementEle_38", 126 },
   { "R004_StatementEle_39", 127 },
   { "R004_StatementEle_40", 128 },
   { "R004_StatementEle_41", 129 },
   { "R004_StatementEle_42", 130 },
   { "R004_StatementEle_43", 131 },
   { "R004_StatementEle_44", 132 },
   { "R004_StatementEle_45", 133 },
   { "R004_StatementEle_46", 134 },
   { "R004_StatementEle_47", 135 },
   { "R004_StatementEle_48", 136 },
   { "R004_StatementEle_49", 137 },
   { "R004_StatementEle_50", 138 },
   { "R004_StatementEle_51", 139 },
   { "R004_StatementEle_52", 140 },
   { "R004_StatementEle_53", 141 },
   { "R004_StatementEle_54", 142 },
   { "R004_StatementEle_55", 143 },
   { "R004_StatementEle_56", 144 },
   { "R004_StatementEle_57", 145 },
   { "R004_StatementEle_58", 146 },
   { "R004_StatementEle_59", 147 },
   { "R004_StatementEle_60", 148 },
   { "R004_StatementEle_61", 149 },
   { "R004_StatementEle_62", 150 },
   { "R004_StatementEle_63", 151 },
   { "R004_StatementEle_64", 152 },
   { "R004_StatementEle_65", 153 },
   { "R004_StatementEle_66", 154 },
   { "R004_StatementEle_67", 155 },
   { "R004_StatementEle_68", 156 },
   { "R004_StatementEle_69", 157 },
   { "R004_StatementEle_70", 158 },
   { "R004_StatementEle_71", 159 },
   { "R004_StatementEle_72", 160 },
   { "R004_StatementEle_73", 161 },
   { "R004_StatementEle_74", 162 },
   { "R004_StatementEle_75", 163 },
   { "R004_StatementEle_76", 164 },
   { "R004_StatementEle_77", 165 },
   { "R004_StatementEle_78", 166 },
   { "R004_StatementEle_79", 167 },
   { "R004_StatementEle_80", 168 },
   { "R004_Modifier_0", 169 },
   { "R004_Modifier_1", 170 },
   { "R004_Modifier_2", 171 },
   { "R004_Modifier_3", 172 },
   { "R004_Modifier_4", 173 },
   { "R004_Modifier_5", 174 },
   { "R004_Modifier_6", 175 },
   { "R004_Modifier_7", 176 },
   { "R004_Modifier_8", 177 },
   { "R004_Modifier_9", 178 },
   { "R004_Modifier_10", 179 },
   { "R004_Modifier_11", 180 },
   { "R004_Modifier_12", 181 },
   { "R004_MethodBody_0", 182 },
   { "R004_MethodBody_1", 183 },
   { "R004_Block_0", 184 },
   { "R004_Block_1", 185 },
   { "R004_BlockStatements_0", 186 },
   { "R004_BlockStatements_1", 187 },
   { "R004_BlockStatements_2", 188 },
   { "R004_NonBrace_0", 189 },
   { "R004_NonBrace_1", 190 },
   { "R004_NonBrace_2", 191 },
   { "R004_NonBrace_3", 192 },
   { "R004_NonBrace_4", 193 },
   { "R004_NonBrace_5", 194 },
   { "R004_NonBrace_6", 195 },
   { "R004_NonBrace_7", 196 },
   { "R004_NonBrace_8", 197 },
   { "R004_Annotation_0", 198 },
   { "R004_Annotation_1", 199 },
   { "R004_TypeArguments_0", 200 },
   { "R004_TypeArguments_1", 201 },
   { "R004_TypeArguments_2", 202 },
   { "R004_TypeArguments_3", 203 },
   { "R004_TypeArgumentListL2_0", 204 },
   { "R004_TypeArgumentListL2_1", 205 },
   { "R004_TypeArgumentListL2_2", 206 },
   { "R004_TypeArgumentListL1_0", 207 },
   { "R004_TypeArgumentListL1_1", 208 },
   { "R004_TypeArgumentListL1_2", 209 },
   { "R004_TypeArgumentList_0", 210 },
   { "R004_TypeArgumentList_1", 211 },
   { "R004_NonANGLE_BRACKET_0", 212 },
   { "R004_NonANGLE_BRACKET_1", 213 },
   { "R004_NonANGLE_BRACKET_2", 214 },
   { "R004_NonANGLE_BRACKET_3", 215 },
   { "R004_NonANGLE_BRACKET_4", 216 },
   { "R004_NonANGLE_BRACKET_5", 217 },
   { "R004_NonANGLE_BRACKET_6", 218 },
   { "R004_NonANGLE_BRACKET_7", 219 },
   { "R004_NonANGLE_BRACKET_8", 220 },
   { "R004_NonANGLE_BRACKET_9", 221 },
   { "R004_UnannPrimitiveType_0", 222 },
   { "R004_UnannPrimitiveType_1", 223 },
   { "R004_NumericType_0", 224 },
   { "R004_NumericType_1", 225 },
   { "R004_IntegralType_0", 226 },
   { "R004_IntegralType_1", 227 },
   { "R004_IntegralType_2", 228 },
   { "R004_IntegralType_3", 229 },
   { "R004_IntegralType_4", 230 },
   { "R004_FloatingPointType_0", 231 },
   { "R004_FloatingPointType_1", 232 },
   { "R004_Superclass_0", 233 },
   { "R004_ClassTypeEle_0", 234 },
   { "R004_ClassTypeEle_1", 235 },
   { "R004_ClassTypeEle_2", 236 },
   { "R004_ClassTypeEle_3", 237 },
   { "R004_ClassType_0", 238 },
   { "R004_ClassType_1", 239 },
   { "R004_AnnotationList_0", 240 },
   { "R004_AnnotationList_1", 241 },
   { "R004_Superinterfaces_0", 242 },
   { "R004_InterfaceTypeList_0", 243 },
   { "R004_InterfaceTypeList_1", 244 },
   { "R004_DimExpr_0", 245 },
   { "R004_DimStatements_0", 246 },
   { "R004_DimStatements_1", 247 },
   { "R004_DimStatements_2", 248 },
   { "R004_NonDim_0", 249 },
   { "R004_NonDim_1", 250 },
   { "R004_NonDim_2", 251 },
   { "R004_NonDim_3", 252 },
   { "R004_NonDim_4", 253 },
   { "R004_NonDim_5", 254 },
   { "R004_NonDim_6", 255 },
   { "R004_NonDim_7", 256 },
   { "R004_NonDim_8", 257 },
   { "R004_NonDim_9", 258 },
   { "R004_EnumBody_0", 259 },
   { "R004_EnumBody_1", 260 },
   { "R004_EnumBody_2", 261 },
   { "R004_EnumBody_3", 262 },
   { "R004_EnumBody_4", 263 },
   { "R004_EnumBody_5", 264 },
   { "R004_EnumBody_6", 265 },
   { "R004_EnumBody_7", 266 },
   { "R004_EnumConstantList_0", 267 },
   { "R004_EnumConstantList_1", 268 },
   { "R004_EnumConstantEle_0", 269 },
   { "R004_EnumConstantEle_1", 270 },
   { "R004_EnumConstantEle_2", 271 },
   { "R004_EnumBodyDeclarations_0", 272 },
	};
}

P_SDT_genertor SDT_R004_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R004_ele_begin_0"] = P_SDT_genertor(new R004_ele_begin_0Analyzer()); break;
	case 1: factory["R004_CompilationUnit_0"] = P_SDT_genertor(new R004_CompilationUnit_0Analyzer()); break;
	case 2: factory["R004_CompilationUnit_1"] = P_SDT_genertor(new R004_CompilationUnit_1Analyzer()); break;
	case 3: factory["R004_CompilationUnit_2"] = P_SDT_genertor(new R004_CompilationUnit_2Analyzer()); break;
	case 4: factory["R004_CompilationUnit_3"] = P_SDT_genertor(new R004_CompilationUnit_3Analyzer()); break;
	case 5: factory["R004_CompilationUnit_4"] = P_SDT_genertor(new R004_CompilationUnit_4Analyzer()); break;
	case 6: factory["R004_CompilationUnit_5"] = P_SDT_genertor(new R004_CompilationUnit_5Analyzer()); break;
	case 7: factory["R004_CompilationUnit_6"] = P_SDT_genertor(new R004_CompilationUnit_6Analyzer()); break;
	case 8: factory["R004_PackageDeclaration_0"] = P_SDT_genertor(new R004_PackageDeclaration_0Analyzer()); break;
	case 9: factory["R004_PackageDeclaration_1"] = P_SDT_genertor(new R004_PackageDeclaration_1Analyzer()); break;
	case 10: factory["R004_DetailIdentifier_0"] = P_SDT_genertor(new R004_DetailIdentifier_0Analyzer()); break;
	case 11: factory["R004_DetailIdentifier_1"] = P_SDT_genertor(new R004_DetailIdentifier_1Analyzer()); break;
	case 12: factory["R004_Identifier_0"] = P_SDT_genertor(new R004_Identifier_0Analyzer()); break;
	case 13: factory["R004_ImportDeclarationList_0"] = P_SDT_genertor(new R004_ImportDeclarationList_0Analyzer()); break;
	case 14: factory["R004_ImportDeclarationList_1"] = P_SDT_genertor(new R004_ImportDeclarationList_1Analyzer()); break;
	case 15: factory["R004_ImportDeclaration_0"] = P_SDT_genertor(new R004_ImportDeclaration_0Analyzer()); break;
	case 16: factory["R004_ImportDeclaration_1"] = P_SDT_genertor(new R004_ImportDeclaration_1Analyzer()); break;
	case 17: factory["R004_ImportDeclaration_2"] = P_SDT_genertor(new R004_ImportDeclaration_2Analyzer()); break;
	case 18: factory["R004_ImportDeclaration_3"] = P_SDT_genertor(new R004_ImportDeclaration_3Analyzer()); break;
	case 19: factory["R004_TypeDeclarationList_0"] = P_SDT_genertor(new R004_TypeDeclarationList_0Analyzer()); break;
	case 20: factory["R004_TypeDeclaration_0"] = P_SDT_genertor(new R004_TypeDeclaration_0Analyzer()); break;
	case 21: factory["R004_TypeDeclaration_1"] = P_SDT_genertor(new R004_TypeDeclaration_1Analyzer()); break;
	case 22: factory["R004_TypeDeclaration_2"] = P_SDT_genertor(new R004_TypeDeclaration_2Analyzer()); break;
	case 23: factory["R004_ClassDeclaration_0"] = P_SDT_genertor(new R004_ClassDeclaration_0Analyzer()); break;
	case 24: factory["R004_ClassDeclaration_1"] = P_SDT_genertor(new R004_ClassDeclaration_1Analyzer()); break;
	case 25: factory["R004_InterfaceDeclaration_0"] = P_SDT_genertor(new R004_InterfaceDeclaration_0Analyzer()); break;
	case 26: factory["R004_InterfaceDeclaration_1"] = P_SDT_genertor(new R004_InterfaceDeclaration_1Analyzer()); break;
	case 27: factory["R004_NormalClassDeclaration_0"] = P_SDT_genertor(new R004_NormalClassDeclaration_0Analyzer()); break;
	case 28: factory["R004_NormalClassDeclaration_1"] = P_SDT_genertor(new R004_NormalClassDeclaration_1Analyzer()); break;
	case 29: factory["R004_NormalClassDeclaration_2"] = P_SDT_genertor(new R004_NormalClassDeclaration_2Analyzer()); break;
	case 30: factory["R004_NormalClassDeclaration_3"] = P_SDT_genertor(new R004_NormalClassDeclaration_3Analyzer()); break;
	case 31: factory["R004_NormalClassDeclaration_4"] = P_SDT_genertor(new R004_NormalClassDeclaration_4Analyzer()); break;
	case 32: factory["R004_NormalClassDeclaration_5"] = P_SDT_genertor(new R004_NormalClassDeclaration_5Analyzer()); break;
	case 33: factory["R004_NormalClassDeclaration_6"] = P_SDT_genertor(new R004_NormalClassDeclaration_6Analyzer()); break;
	case 34: factory["R004_NormalClassDeclaration_7"] = P_SDT_genertor(new R004_NormalClassDeclaration_7Analyzer()); break;
	case 35: factory["R004_NormalClassDeclaration_8"] = P_SDT_genertor(new R004_NormalClassDeclaration_8Analyzer()); break;
	case 36: factory["R004_NormalClassDeclaration_9"] = P_SDT_genertor(new R004_NormalClassDeclaration_9Analyzer()); break;
	case 37: factory["R004_NormalClassDeclaration_10"] = P_SDT_genertor(new R004_NormalClassDeclaration_10Analyzer()); break;
	case 38: factory["R004_NormalClassDeclaration_11"] = P_SDT_genertor(new R004_NormalClassDeclaration_11Analyzer()); break;
	case 39: factory["R004_NormalClassDeclaration_12"] = P_SDT_genertor(new R004_NormalClassDeclaration_12Analyzer()); break;
	case 40: factory["R004_NormalClassDeclaration_13"] = P_SDT_genertor(new R004_NormalClassDeclaration_13Analyzer()); break;
	case 41: factory["R004_NormalClassDeclaration_14"] = P_SDT_genertor(new R004_NormalClassDeclaration_14Analyzer()); break;
	case 42: factory["R004_NormalClassDeclaration_15"] = P_SDT_genertor(new R004_NormalClassDeclaration_15Analyzer()); break;
	case 43: factory["R004_EnumDeclaration_0"] = P_SDT_genertor(new R004_EnumDeclaration_0Analyzer()); break;
	case 44: factory["R004_EnumDeclaration_1"] = P_SDT_genertor(new R004_EnumDeclaration_1Analyzer()); break;
	case 45: factory["R004_EnumDeclaration_2"] = P_SDT_genertor(new R004_EnumDeclaration_2Analyzer()); break;
	case 46: factory["R004_EnumDeclaration_3"] = P_SDT_genertor(new R004_EnumDeclaration_3Analyzer()); break;
	case 47: factory["R004_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_0Analyzer()); break;
	case 48: factory["R004_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_1Analyzer()); break;
	case 49: factory["R004_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_2Analyzer()); break;
	case 50: factory["R004_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_3Analyzer()); break;
	case 51: factory["R004_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_4Analyzer()); break;
	case 52: factory["R004_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_5Analyzer()); break;
	case 53: factory["R004_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_6Analyzer()); break;
	case 54: factory["R004_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_7Analyzer()); break;
	case 55: factory["R004_ExtendsInterfaces_0"] = P_SDT_genertor(new R004_ExtendsInterfaces_0Analyzer()); break;
	case 56: factory["R004_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_0Analyzer()); break;
	case 57: factory["R004_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_1Analyzer()); break;
	case 58: factory["R004_AnnotationTypeDeclaration_2"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_2Analyzer()); break;
	case 59: factory["R004_AnnotationTypeDeclaration_3"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_3Analyzer()); break;
	case 60: factory["R004_ClassBody_0"] = P_SDT_genertor(new R004_ClassBody_0Analyzer()); break;
	case 61: factory["R004_ClassBodyDeclarationList_0"] = P_SDT_genertor(new R004_ClassBodyDeclarationList_0Analyzer()); break;
	case 62: factory["R004_ClassBodyDeclarationList_1"] = P_SDT_genertor(new R004_ClassBodyDeclarationList_1Analyzer()); break;
	case 63: factory["R004_ClassBodyDeclaration_0"] = P_SDT_genertor(new R004_ClassBodyDeclaration_0Analyzer()); break;
	case 64: factory["R004_ClassBodyDeclaration_1"] = P_SDT_genertor(new R004_ClassBodyDeclaration_1Analyzer()); break;
	case 65: factory["R004_ClassStatementPrefix_0"] = P_SDT_genertor(new R004_ClassStatementPrefix_0Analyzer()); break;
	case 66: factory["R004_ClassStatementPrefix_1"] = P_SDT_genertor(new R004_ClassStatementPrefix_1Analyzer()); break;
	case 67: factory["R004_NonBraceAndSemicolon_0"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_0Analyzer()); break;
	case 68: factory["R004_NonBraceAndSemicolon_1"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_1Analyzer()); break;
	case 69: factory["R004_NonBraceAndSemicolon_2"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_2Analyzer()); break;
	case 70: factory["R004_NonBraceAndSemicolon_3"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_3Analyzer()); break;
	case 71: factory["R004_NonBraceAndSemicolon_4"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_4Analyzer()); break;
	case 72: factory["R004_ModifierList_0"] = P_SDT_genertor(new R004_ModifierList_0Analyzer()); break;
	case 73: factory["R004_ModifierList_1"] = P_SDT_genertor(new R004_ModifierList_1Analyzer()); break;
	case 74: factory["R004_AnnotationContent_0"] = P_SDT_genertor(new R004_AnnotationContent_0Analyzer()); break;
	case 75: factory["R004_AnnotationContentStatements_0"] = P_SDT_genertor(new R004_AnnotationContentStatements_0Analyzer()); break;
	case 76: factory["R004_AnnotationContentStatements_1"] = P_SDT_genertor(new R004_AnnotationContentStatements_1Analyzer()); break;
	case 77: factory["R004_NonPARENTHESES_0"] = P_SDT_genertor(new R004_NonPARENTHESES_0Analyzer()); break;
	case 78: factory["R004_NonPARENTHESES_1"] = P_SDT_genertor(new R004_NonPARENTHESES_1Analyzer()); break;
	case 79: factory["R004_NonPARENTHESES_2"] = P_SDT_genertor(new R004_NonPARENTHESES_2Analyzer()); break;
	case 80: factory["R004_NonPARENTHESES_3"] = P_SDT_genertor(new R004_NonPARENTHESES_3Analyzer()); break;
	case 81: factory["R004_NonPARENTHESES_4"] = P_SDT_genertor(new R004_NonPARENTHESES_4Analyzer()); break;
	case 82: factory["R004_NonPARENTHESES_5"] = P_SDT_genertor(new R004_NonPARENTHESES_5Analyzer()); break;
	case 83: factory["R004_NonPARENTHESES_6"] = P_SDT_genertor(new R004_NonPARENTHESES_6Analyzer()); break;
	case 84: factory["R004_NonPARENTHESES_7"] = P_SDT_genertor(new R004_NonPARENTHESES_7Analyzer()); break;
	case 85: factory["R004_NonPARENTHESES_8"] = P_SDT_genertor(new R004_NonPARENTHESES_8Analyzer()); break;
	case 86: factory["R004_NonPARENTHESES_9"] = P_SDT_genertor(new R004_NonPARENTHESES_9Analyzer()); break;
	case 87: factory["R004_NonPARENTHESES_10"] = P_SDT_genertor(new R004_NonPARENTHESES_10Analyzer()); break;
	case 88: factory["R004_StatementEle_0"] = P_SDT_genertor(new R004_StatementEle_0Analyzer()); break;
	case 89: factory["R004_StatementEle_1"] = P_SDT_genertor(new R004_StatementEle_1Analyzer()); break;
	case 90: factory["R004_StatementEle_2"] = P_SDT_genertor(new R004_StatementEle_2Analyzer()); break;
	case 91: factory["R004_StatementEle_3"] = P_SDT_genertor(new R004_StatementEle_3Analyzer()); break;
	case 92: factory["R004_StatementEle_4"] = P_SDT_genertor(new R004_StatementEle_4Analyzer()); break;
	case 93: factory["R004_StatementEle_5"] = P_SDT_genertor(new R004_StatementEle_5Analyzer()); break;
	case 94: factory["R004_StatementEle_6"] = P_SDT_genertor(new R004_StatementEle_6Analyzer()); break;
	case 95: factory["R004_StatementEle_7"] = P_SDT_genertor(new R004_StatementEle_7Analyzer()); break;
	case 96: factory["R004_StatementEle_8"] = P_SDT_genertor(new R004_StatementEle_8Analyzer()); break;
	case 97: factory["R004_StatementEle_9"] = P_SDT_genertor(new R004_StatementEle_9Analyzer()); break;
	case 98: factory["R004_StatementEle_10"] = P_SDT_genertor(new R004_StatementEle_10Analyzer()); break;
	case 99: factory["R004_StatementEle_11"] = P_SDT_genertor(new R004_StatementEle_11Analyzer()); break;
	case 100: factory["R004_StatementEle_12"] = P_SDT_genertor(new R004_StatementEle_12Analyzer()); break;
	case 101: factory["R004_StatementEle_13"] = P_SDT_genertor(new R004_StatementEle_13Analyzer()); break;
	case 102: factory["R004_StatementEle_14"] = P_SDT_genertor(new R004_StatementEle_14Analyzer()); break;
	case 103: factory["R004_StatementEle_15"] = P_SDT_genertor(new R004_StatementEle_15Analyzer()); break;
	case 104: factory["R004_StatementEle_16"] = P_SDT_genertor(new R004_StatementEle_16Analyzer()); break;
	case 105: factory["R004_StatementEle_17"] = P_SDT_genertor(new R004_StatementEle_17Analyzer()); break;
	case 106: factory["R004_StatementEle_18"] = P_SDT_genertor(new R004_StatementEle_18Analyzer()); break;
	case 107: factory["R004_StatementEle_19"] = P_SDT_genertor(new R004_StatementEle_19Analyzer()); break;
	case 108: factory["R004_StatementEle_20"] = P_SDT_genertor(new R004_StatementEle_20Analyzer()); break;
	case 109: factory["R004_StatementEle_21"] = P_SDT_genertor(new R004_StatementEle_21Analyzer()); break;
	case 110: factory["R004_StatementEle_22"] = P_SDT_genertor(new R004_StatementEle_22Analyzer()); break;
	case 111: factory["R004_StatementEle_23"] = P_SDT_genertor(new R004_StatementEle_23Analyzer()); break;
	case 112: factory["R004_StatementEle_24"] = P_SDT_genertor(new R004_StatementEle_24Analyzer()); break;
	case 113: factory["R004_StatementEle_25"] = P_SDT_genertor(new R004_StatementEle_25Analyzer()); break;
	case 114: factory["R004_StatementEle_26"] = P_SDT_genertor(new R004_StatementEle_26Analyzer()); break;
	case 115: factory["R004_StatementEle_27"] = P_SDT_genertor(new R004_StatementEle_27Analyzer()); break;
	case 116: factory["R004_StatementEle_28"] = P_SDT_genertor(new R004_StatementEle_28Analyzer()); break;
	case 117: factory["R004_StatementEle_29"] = P_SDT_genertor(new R004_StatementEle_29Analyzer()); break;
	case 118: factory["R004_StatementEle_30"] = P_SDT_genertor(new R004_StatementEle_30Analyzer()); break;
	case 119: factory["R004_StatementEle_31"] = P_SDT_genertor(new R004_StatementEle_31Analyzer()); break;
	case 120: factory["R004_StatementEle_32"] = P_SDT_genertor(new R004_StatementEle_32Analyzer()); break;
	case 121: factory["R004_StatementEle_33"] = P_SDT_genertor(new R004_StatementEle_33Analyzer()); break;
	case 122: factory["R004_StatementEle_34"] = P_SDT_genertor(new R004_StatementEle_34Analyzer()); break;
	case 123: factory["R004_StatementEle_35"] = P_SDT_genertor(new R004_StatementEle_35Analyzer()); break;
	case 124: factory["R004_StatementEle_36"] = P_SDT_genertor(new R004_StatementEle_36Analyzer()); break;
	case 125: factory["R004_StatementEle_37"] = P_SDT_genertor(new R004_StatementEle_37Analyzer()); break;
	case 126: factory["R004_StatementEle_38"] = P_SDT_genertor(new R004_StatementEle_38Analyzer()); break;
	case 127: factory["R004_StatementEle_39"] = P_SDT_genertor(new R004_StatementEle_39Analyzer()); break;
	case 128: factory["R004_StatementEle_40"] = P_SDT_genertor(new R004_StatementEle_40Analyzer()); break;
	case 129: factory["R004_StatementEle_41"] = P_SDT_genertor(new R004_StatementEle_41Analyzer()); break;
	case 130: factory["R004_StatementEle_42"] = P_SDT_genertor(new R004_StatementEle_42Analyzer()); break;
	case 131: factory["R004_StatementEle_43"] = P_SDT_genertor(new R004_StatementEle_43Analyzer()); break;
	case 132: factory["R004_StatementEle_44"] = P_SDT_genertor(new R004_StatementEle_44Analyzer()); break;
	case 133: factory["R004_StatementEle_45"] = P_SDT_genertor(new R004_StatementEle_45Analyzer()); break;
	case 134: factory["R004_StatementEle_46"] = P_SDT_genertor(new R004_StatementEle_46Analyzer()); break;
	case 135: factory["R004_StatementEle_47"] = P_SDT_genertor(new R004_StatementEle_47Analyzer()); break;
	case 136: factory["R004_StatementEle_48"] = P_SDT_genertor(new R004_StatementEle_48Analyzer()); break;
	case 137: factory["R004_StatementEle_49"] = P_SDT_genertor(new R004_StatementEle_49Analyzer()); break;
	case 138: factory["R004_StatementEle_50"] = P_SDT_genertor(new R004_StatementEle_50Analyzer()); break;
	case 139: factory["R004_StatementEle_51"] = P_SDT_genertor(new R004_StatementEle_51Analyzer()); break;
	case 140: factory["R004_StatementEle_52"] = P_SDT_genertor(new R004_StatementEle_52Analyzer()); break;
	case 141: factory["R004_StatementEle_53"] = P_SDT_genertor(new R004_StatementEle_53Analyzer()); break;
	case 142: factory["R004_StatementEle_54"] = P_SDT_genertor(new R004_StatementEle_54Analyzer()); break;
	case 143: factory["R004_StatementEle_55"] = P_SDT_genertor(new R004_StatementEle_55Analyzer()); break;
	case 144: factory["R004_StatementEle_56"] = P_SDT_genertor(new R004_StatementEle_56Analyzer()); break;
	case 145: factory["R004_StatementEle_57"] = P_SDT_genertor(new R004_StatementEle_57Analyzer()); break;
	case 146: factory["R004_StatementEle_58"] = P_SDT_genertor(new R004_StatementEle_58Analyzer()); break;
	case 147: factory["R004_StatementEle_59"] = P_SDT_genertor(new R004_StatementEle_59Analyzer()); break;
	case 148: factory["R004_StatementEle_60"] = P_SDT_genertor(new R004_StatementEle_60Analyzer()); break;
	case 149: factory["R004_StatementEle_61"] = P_SDT_genertor(new R004_StatementEle_61Analyzer()); break;
	case 150: factory["R004_StatementEle_62"] = P_SDT_genertor(new R004_StatementEle_62Analyzer()); break;
	case 151: factory["R004_StatementEle_63"] = P_SDT_genertor(new R004_StatementEle_63Analyzer()); break;
	case 152: factory["R004_StatementEle_64"] = P_SDT_genertor(new R004_StatementEle_64Analyzer()); break;
	case 153: factory["R004_StatementEle_65"] = P_SDT_genertor(new R004_StatementEle_65Analyzer()); break;
	case 154: factory["R004_StatementEle_66"] = P_SDT_genertor(new R004_StatementEle_66Analyzer()); break;
	case 155: factory["R004_StatementEle_67"] = P_SDT_genertor(new R004_StatementEle_67Analyzer()); break;
	case 156: factory["R004_StatementEle_68"] = P_SDT_genertor(new R004_StatementEle_68Analyzer()); break;
	case 157: factory["R004_StatementEle_69"] = P_SDT_genertor(new R004_StatementEle_69Analyzer()); break;
	case 158: factory["R004_StatementEle_70"] = P_SDT_genertor(new R004_StatementEle_70Analyzer()); break;
	case 159: factory["R004_StatementEle_71"] = P_SDT_genertor(new R004_StatementEle_71Analyzer()); break;
	case 160: factory["R004_StatementEle_72"] = P_SDT_genertor(new R004_StatementEle_72Analyzer()); break;
	case 161: factory["R004_StatementEle_73"] = P_SDT_genertor(new R004_StatementEle_73Analyzer()); break;
	case 162: factory["R004_StatementEle_74"] = P_SDT_genertor(new R004_StatementEle_74Analyzer()); break;
	case 163: factory["R004_StatementEle_75"] = P_SDT_genertor(new R004_StatementEle_75Analyzer()); break;
	case 164: factory["R004_StatementEle_76"] = P_SDT_genertor(new R004_StatementEle_76Analyzer()); break;
	case 165: factory["R004_StatementEle_77"] = P_SDT_genertor(new R004_StatementEle_77Analyzer()); break;
	case 166: factory["R004_StatementEle_78"] = P_SDT_genertor(new R004_StatementEle_78Analyzer()); break;
	case 167: factory["R004_StatementEle_79"] = P_SDT_genertor(new R004_StatementEle_79Analyzer()); break;
	case 168: factory["R004_StatementEle_80"] = P_SDT_genertor(new R004_StatementEle_80Analyzer()); break;
	case 169: factory["R004_Modifier_0"] = P_SDT_genertor(new R004_Modifier_0Analyzer()); break;
	case 170: factory["R004_Modifier_1"] = P_SDT_genertor(new R004_Modifier_1Analyzer()); break;
	case 171: factory["R004_Modifier_2"] = P_SDT_genertor(new R004_Modifier_2Analyzer()); break;
	case 172: factory["R004_Modifier_3"] = P_SDT_genertor(new R004_Modifier_3Analyzer()); break;
	case 173: factory["R004_Modifier_4"] = P_SDT_genertor(new R004_Modifier_4Analyzer()); break;
	case 174: factory["R004_Modifier_5"] = P_SDT_genertor(new R004_Modifier_5Analyzer()); break;
	case 175: factory["R004_Modifier_6"] = P_SDT_genertor(new R004_Modifier_6Analyzer()); break;
	case 176: factory["R004_Modifier_7"] = P_SDT_genertor(new R004_Modifier_7Analyzer()); break;
	case 177: factory["R004_Modifier_8"] = P_SDT_genertor(new R004_Modifier_8Analyzer()); break;
	case 178: factory["R004_Modifier_9"] = P_SDT_genertor(new R004_Modifier_9Analyzer()); break;
	case 179: factory["R004_Modifier_10"] = P_SDT_genertor(new R004_Modifier_10Analyzer()); break;
	case 180: factory["R004_Modifier_11"] = P_SDT_genertor(new R004_Modifier_11Analyzer()); break;
	case 181: factory["R004_Modifier_12"] = P_SDT_genertor(new R004_Modifier_12Analyzer()); break;
	case 182: factory["R004_MethodBody_0"] = P_SDT_genertor(new R004_MethodBody_0Analyzer()); break;
	case 183: factory["R004_MethodBody_1"] = P_SDT_genertor(new R004_MethodBody_1Analyzer()); break;
	case 184: factory["R004_Block_0"] = P_SDT_genertor(new R004_Block_0Analyzer()); break;
	case 185: factory["R004_Block_1"] = P_SDT_genertor(new R004_Block_1Analyzer()); break;
	case 186: factory["R004_BlockStatements_0"] = P_SDT_genertor(new R004_BlockStatements_0Analyzer()); break;
	case 187: factory["R004_BlockStatements_1"] = P_SDT_genertor(new R004_BlockStatements_1Analyzer()); break;
	case 188: factory["R004_BlockStatements_2"] = P_SDT_genertor(new R004_BlockStatements_2Analyzer()); break;
	case 189: factory["R004_NonBrace_0"] = P_SDT_genertor(new R004_NonBrace_0Analyzer()); break;
	case 190: factory["R004_NonBrace_1"] = P_SDT_genertor(new R004_NonBrace_1Analyzer()); break;
	case 191: factory["R004_NonBrace_2"] = P_SDT_genertor(new R004_NonBrace_2Analyzer()); break;
	case 192: factory["R004_NonBrace_3"] = P_SDT_genertor(new R004_NonBrace_3Analyzer()); break;
	case 193: factory["R004_NonBrace_4"] = P_SDT_genertor(new R004_NonBrace_4Analyzer()); break;
	case 194: factory["R004_NonBrace_5"] = P_SDT_genertor(new R004_NonBrace_5Analyzer()); break;
	case 195: factory["R004_NonBrace_6"] = P_SDT_genertor(new R004_NonBrace_6Analyzer()); break;
	case 196: factory["R004_NonBrace_7"] = P_SDT_genertor(new R004_NonBrace_7Analyzer()); break;
	case 197: factory["R004_NonBrace_8"] = P_SDT_genertor(new R004_NonBrace_8Analyzer()); break;
	case 198: factory["R004_Annotation_0"] = P_SDT_genertor(new R004_Annotation_0Analyzer()); break;
	case 199: factory["R004_Annotation_1"] = P_SDT_genertor(new R004_Annotation_1Analyzer()); break;
	case 200: factory["R004_TypeArguments_0"] = P_SDT_genertor(new R004_TypeArguments_0Analyzer()); break;
	case 201: factory["R004_TypeArguments_1"] = P_SDT_genertor(new R004_TypeArguments_1Analyzer()); break;
	case 202: factory["R004_TypeArguments_2"] = P_SDT_genertor(new R004_TypeArguments_2Analyzer()); break;
	case 203: factory["R004_TypeArguments_3"] = P_SDT_genertor(new R004_TypeArguments_3Analyzer()); break;
	case 204: factory["R004_TypeArgumentListL2_0"] = P_SDT_genertor(new R004_TypeArgumentListL2_0Analyzer()); break;
	case 205: factory["R004_TypeArgumentListL2_1"] = P_SDT_genertor(new R004_TypeArgumentListL2_1Analyzer()); break;
	case 206: factory["R004_TypeArgumentListL2_2"] = P_SDT_genertor(new R004_TypeArgumentListL2_2Analyzer()); break;
	case 207: factory["R004_TypeArgumentListL1_0"] = P_SDT_genertor(new R004_TypeArgumentListL1_0Analyzer()); break;
	case 208: factory["R004_TypeArgumentListL1_1"] = P_SDT_genertor(new R004_TypeArgumentListL1_1Analyzer()); break;
	case 209: factory["R004_TypeArgumentListL1_2"] = P_SDT_genertor(new R004_TypeArgumentListL1_2Analyzer()); break;
	case 210: factory["R004_TypeArgumentList_0"] = P_SDT_genertor(new R004_TypeArgumentList_0Analyzer()); break;
	case 211: factory["R004_TypeArgumentList_1"] = P_SDT_genertor(new R004_TypeArgumentList_1Analyzer()); break;
	case 212: factory["R004_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_0Analyzer()); break;
	case 213: factory["R004_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_1Analyzer()); break;
	case 214: factory["R004_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_2Analyzer()); break;
	case 215: factory["R004_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_3Analyzer()); break;
	case 216: factory["R004_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_4Analyzer()); break;
	case 217: factory["R004_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_5Analyzer()); break;
	case 218: factory["R004_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_6Analyzer()); break;
	case 219: factory["R004_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_7Analyzer()); break;
	case 220: factory["R004_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_8Analyzer()); break;
	case 221: factory["R004_NonANGLE_BRACKET_9"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_9Analyzer()); break;
	case 222: factory["R004_UnannPrimitiveType_0"] = P_SDT_genertor(new R004_UnannPrimitiveType_0Analyzer()); break;
	case 223: factory["R004_UnannPrimitiveType_1"] = P_SDT_genertor(new R004_UnannPrimitiveType_1Analyzer()); break;
	case 224: factory["R004_NumericType_0"] = P_SDT_genertor(new R004_NumericType_0Analyzer()); break;
	case 225: factory["R004_NumericType_1"] = P_SDT_genertor(new R004_NumericType_1Analyzer()); break;
	case 226: factory["R004_IntegralType_0"] = P_SDT_genertor(new R004_IntegralType_0Analyzer()); break;
	case 227: factory["R004_IntegralType_1"] = P_SDT_genertor(new R004_IntegralType_1Analyzer()); break;
	case 228: factory["R004_IntegralType_2"] = P_SDT_genertor(new R004_IntegralType_2Analyzer()); break;
	case 229: factory["R004_IntegralType_3"] = P_SDT_genertor(new R004_IntegralType_3Analyzer()); break;
	case 230: factory["R004_IntegralType_4"] = P_SDT_genertor(new R004_IntegralType_4Analyzer()); break;
	case 231: factory["R004_FloatingPointType_0"] = P_SDT_genertor(new R004_FloatingPointType_0Analyzer()); break;
	case 232: factory["R004_FloatingPointType_1"] = P_SDT_genertor(new R004_FloatingPointType_1Analyzer()); break;
	case 233: factory["R004_Superclass_0"] = P_SDT_genertor(new R004_Superclass_0Analyzer()); break;
	case 234: factory["R004_ClassTypeEle_0"] = P_SDT_genertor(new R004_ClassTypeEle_0Analyzer()); break;
	case 235: factory["R004_ClassTypeEle_1"] = P_SDT_genertor(new R004_ClassTypeEle_1Analyzer()); break;
	case 236: factory["R004_ClassTypeEle_2"] = P_SDT_genertor(new R004_ClassTypeEle_2Analyzer()); break;
	case 237: factory["R004_ClassTypeEle_3"] = P_SDT_genertor(new R004_ClassTypeEle_3Analyzer()); break;
	case 238: factory["R004_ClassType_0"] = P_SDT_genertor(new R004_ClassType_0Analyzer()); break;
	case 239: factory["R004_ClassType_1"] = P_SDT_genertor(new R004_ClassType_1Analyzer()); break;
	case 240: factory["R004_AnnotationList_0"] = P_SDT_genertor(new R004_AnnotationList_0Analyzer()); break;
	case 241: factory["R004_AnnotationList_1"] = P_SDT_genertor(new R004_AnnotationList_1Analyzer()); break;
	case 242: factory["R004_Superinterfaces_0"] = P_SDT_genertor(new R004_Superinterfaces_0Analyzer()); break;
	case 243: factory["R004_InterfaceTypeList_0"] = P_SDT_genertor(new R004_InterfaceTypeList_0Analyzer()); break;
	case 244: factory["R004_InterfaceTypeList_1"] = P_SDT_genertor(new R004_InterfaceTypeList_1Analyzer()); break;
	case 245: factory["R004_DimExpr_0"] = P_SDT_genertor(new R004_DimExpr_0Analyzer()); break;
	case 246: factory["R004_DimStatements_0"] = P_SDT_genertor(new R004_DimStatements_0Analyzer()); break;
	case 247: factory["R004_DimStatements_1"] = P_SDT_genertor(new R004_DimStatements_1Analyzer()); break;
	case 248: factory["R004_DimStatements_2"] = P_SDT_genertor(new R004_DimStatements_2Analyzer()); break;
	case 249: factory["R004_NonDim_0"] = P_SDT_genertor(new R004_NonDim_0Analyzer()); break;
	case 250: factory["R004_NonDim_1"] = P_SDT_genertor(new R004_NonDim_1Analyzer()); break;
	case 251: factory["R004_NonDim_2"] = P_SDT_genertor(new R004_NonDim_2Analyzer()); break;
	case 252: factory["R004_NonDim_3"] = P_SDT_genertor(new R004_NonDim_3Analyzer()); break;
	case 253: factory["R004_NonDim_4"] = P_SDT_genertor(new R004_NonDim_4Analyzer()); break;
	case 254: factory["R004_NonDim_5"] = P_SDT_genertor(new R004_NonDim_5Analyzer()); break;
	case 255: factory["R004_NonDim_6"] = P_SDT_genertor(new R004_NonDim_6Analyzer()); break;
	case 256: factory["R004_NonDim_7"] = P_SDT_genertor(new R004_NonDim_7Analyzer()); break;
	case 257: factory["R004_NonDim_8"] = P_SDT_genertor(new R004_NonDim_8Analyzer()); break;
	case 258: factory["R004_NonDim_9"] = P_SDT_genertor(new R004_NonDim_9Analyzer()); break;
	case 259: factory["R004_EnumBody_0"] = P_SDT_genertor(new R004_EnumBody_0Analyzer()); break;
	case 260: factory["R004_EnumBody_1"] = P_SDT_genertor(new R004_EnumBody_1Analyzer()); break;
	case 261: factory["R004_EnumBody_2"] = P_SDT_genertor(new R004_EnumBody_2Analyzer()); break;
	case 262: factory["R004_EnumBody_3"] = P_SDT_genertor(new R004_EnumBody_3Analyzer()); break;
	case 263: factory["R004_EnumBody_4"] = P_SDT_genertor(new R004_EnumBody_4Analyzer()); break;
	case 264: factory["R004_EnumBody_5"] = P_SDT_genertor(new R004_EnumBody_5Analyzer()); break;
	case 265: factory["R004_EnumBody_6"] = P_SDT_genertor(new R004_EnumBody_6Analyzer()); break;
	case 266: factory["R004_EnumBody_7"] = P_SDT_genertor(new R004_EnumBody_7Analyzer()); break;
	case 267: factory["R004_EnumConstantList_0"] = P_SDT_genertor(new R004_EnumConstantList_0Analyzer()); break;
	case 268: factory["R004_EnumConstantList_1"] = P_SDT_genertor(new R004_EnumConstantList_1Analyzer()); break;
	case 269: factory["R004_EnumConstantEle_0"] = P_SDT_genertor(new R004_EnumConstantEle_0Analyzer()); break;
	case 270: factory["R004_EnumConstantEle_1"] = P_SDT_genertor(new R004_EnumConstantEle_1Analyzer()); break;
	case 271: factory["R004_EnumConstantEle_2"] = P_SDT_genertor(new R004_EnumConstantEle_2Analyzer()); break;
	case 272: factory["R004_EnumBodyDeclarations_0"] = P_SDT_genertor(new R004_EnumBodyDeclarations_0Analyzer()); break;
	default:

		if (key.find("R004_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R004_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R004_Factory::~SDT_R004_Factory() {}
