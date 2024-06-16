#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R008_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R008Analyzer.h"
using namespace std;
using namespace boost;



SDT_R008_Factory SDT_R008_Factory::instance;
SDT_R008_Factory::SDT_R008_Factory() {
	control_Param = {
   { "R008_ele_begin_0", 0 },
   { "R008_InterfaceMemberDeclaration_0", 1 },
   { "R008_InterfaceMemberDeclaration_1", 2 },
   { "R008_InterfaceMemberDeclaration_2", 3 },
   { "R008_InterfaceMemberDeclaration_3", 4 },
   { "R008_InterfaceMemberDeclaration_4", 5 },
   { "R008_InterfaceDeclaration_0", 6 },
   { "R008_InterfaceDeclaration_1", 7 },
   { "R008_ClassDeclaration_0", 8 },
   { "R008_ClassDeclaration_1", 9 },
   { "R008_EnumDeclaration_0", 10 },
   { "R008_EnumDeclaration_1", 11 },
   { "R008_EnumDeclaration_2", 12 },
   { "R008_EnumDeclaration_3", 13 },
   { "R008_NormalClassDeclaration_0", 14 },
   { "R008_NormalClassDeclaration_1", 15 },
   { "R008_NormalClassDeclaration_2", 16 },
   { "R008_NormalClassDeclaration_3", 17 },
   { "R008_NormalClassDeclaration_4", 18 },
   { "R008_NormalClassDeclaration_5", 19 },
   { "R008_NormalClassDeclaration_6", 20 },
   { "R008_NormalClassDeclaration_7", 21 },
   { "R008_NormalClassDeclaration_8", 22 },
   { "R008_NormalClassDeclaration_9", 23 },
   { "R008_NormalClassDeclaration_10", 24 },
   { "R008_NormalClassDeclaration_11", 25 },
   { "R008_NormalClassDeclaration_12", 26 },
   { "R008_NormalClassDeclaration_13", 27 },
   { "R008_NormalClassDeclaration_14", 28 },
   { "R008_NormalClassDeclaration_15", 29 },
   { "R008_Superclass_0", 30 },
   { "R008_Superinterfaces_0", 31 },
   { "R008_NormalInterfaceDeclaration_0", 32 },
   { "R008_NormalInterfaceDeclaration_1", 33 },
   { "R008_NormalInterfaceDeclaration_2", 34 },
   { "R008_NormalInterfaceDeclaration_3", 35 },
   { "R008_NormalInterfaceDeclaration_4", 36 },
   { "R008_NormalInterfaceDeclaration_5", 37 },
   { "R008_NormalInterfaceDeclaration_6", 38 },
   { "R008_NormalInterfaceDeclaration_7", 39 },
   { "R008_AnnotationTypeDeclaration_0", 40 },
   { "R008_AnnotationTypeDeclaration_1", 41 },
   { "R008_Identifier_0", 42 },
   { "R008_Block_0", 43 },
   { "R008_Block_1", 44 },
   { "R008_BlockStatements_0", 45 },
   { "R008_BlockStatements_1", 46 },
   { "R008_BlockStatements_2", 47 },
   { "R008_NonBrace_0", 48 },
   { "R008_NonBrace_1", 49 },
   { "R008_NonBrace_2", 50 },
   { "R008_NonBrace_3", 51 },
   { "R008_NonBrace_4", 52 },
   { "R008_NonBrace_5", 53 },
   { "R008_NonBrace_6", 54 },
   { "R008_NonBrace_7", 55 },
   { "R008_NonBrace_8", 56 },
   { "R008_NonBrace_9", 57 },
   { "R008_StatementEle_0", 58 },
   { "R008_StatementEle_1", 59 },
   { "R008_StatementEle_2", 60 },
   { "R008_StatementEle_3", 61 },
   { "R008_StatementEle_4", 62 },
   { "R008_StatementEle_5", 63 },
   { "R008_StatementEle_6", 64 },
   { "R008_StatementEle_7", 65 },
   { "R008_StatementEle_8", 66 },
   { "R008_StatementEle_9", 67 },
   { "R008_StatementEle_10", 68 },
   { "R008_StatementEle_11", 69 },
   { "R008_StatementEle_12", 70 },
   { "R008_StatementEle_13", 71 },
   { "R008_StatementEle_14", 72 },
   { "R008_StatementEle_15", 73 },
   { "R008_StatementEle_16", 74 },
   { "R008_StatementEle_17", 75 },
   { "R008_StatementEle_18", 76 },
   { "R008_StatementEle_19", 77 },
   { "R008_StatementEle_20", 78 },
   { "R008_StatementEle_21", 79 },
   { "R008_StatementEle_22", 80 },
   { "R008_StatementEle_23", 81 },
   { "R008_StatementEle_24", 82 },
   { "R008_StatementEle_25", 83 },
   { "R008_StatementEle_26", 84 },
   { "R008_StatementEle_27", 85 },
   { "R008_StatementEle_28", 86 },
   { "R008_StatementEle_29", 87 },
   { "R008_StatementEle_30", 88 },
   { "R008_StatementEle_31", 89 },
   { "R008_StatementEle_32", 90 },
   { "R008_StatementEle_33", 91 },
   { "R008_StatementEle_34", 92 },
   { "R008_StatementEle_35", 93 },
   { "R008_StatementEle_36", 94 },
   { "R008_StatementEle_37", 95 },
   { "R008_StatementEle_38", 96 },
   { "R008_StatementEle_39", 97 },
   { "R008_StatementEle_40", 98 },
   { "R008_StatementEle_41", 99 },
   { "R008_StatementEle_42", 100 },
   { "R008_StatementEle_43", 101 },
   { "R008_StatementEle_44", 102 },
   { "R008_StatementEle_45", 103 },
   { "R008_StatementEle_46", 104 },
   { "R008_StatementEle_47", 105 },
   { "R008_StatementEle_48", 106 },
   { "R008_StatementEle_49", 107 },
   { "R008_StatementEle_50", 108 },
   { "R008_StatementEle_51", 109 },
   { "R008_StatementEle_52", 110 },
   { "R008_StatementEle_53", 111 },
   { "R008_StatementEle_54", 112 },
   { "R008_StatementEle_55", 113 },
   { "R008_StatementEle_56", 114 },
   { "R008_StatementEle_57", 115 },
   { "R008_StatementEle_58", 116 },
   { "R008_StatementEle_59", 117 },
   { "R008_StatementEle_60", 118 },
   { "R008_StatementEle_61", 119 },
   { "R008_StatementEle_62", 120 },
   { "R008_StatementEle_63", 121 },
   { "R008_StatementEle_64", 122 },
   { "R008_StatementEle_65", 123 },
   { "R008_StatementEle_66", 124 },
   { "R008_StatementEle_67", 125 },
   { "R008_StatementEle_68", 126 },
   { "R008_StatementEle_69", 127 },
   { "R008_StatementEle_70", 128 },
   { "R008_StatementEle_71", 129 },
   { "R008_StatementEle_72", 130 },
   { "R008_StatementEle_73", 131 },
   { "R008_StatementEle_74", 132 },
   { "R008_StatementEle_75", 133 },
   { "R008_StatementEle_76", 134 },
   { "R008_StatementEle_77", 135 },
   { "R008_StatementEle_78", 136 },
   { "R008_StatementEle_79", 137 },
   { "R008_ModifierList_0", 138 },
   { "R008_ModifierList_1", 139 },
   { "R008_Modifier_0", 140 },
   { "R008_Modifier_1", 141 },
   { "R008_Modifier_2", 142 },
   { "R008_Modifier_3", 143 },
   { "R008_Modifier_4", 144 },
   { "R008_Modifier_5", 145 },
   { "R008_Modifier_6", 146 },
   { "R008_Modifier_7", 147 },
   { "R008_Modifier_8", 148 },
   { "R008_Modifier_9", 149 },
   { "R008_Modifier_10", 150 },
   { "R008_Modifier_11", 151 },
   { "R008_Modifier_12", 152 },
   { "R008_Modifier_13", 153 },
   { "R008_Annotation_0", 154 },
   { "R008_Annotation_1", 155 },
   { "R008_DetailIdentifier_0", 156 },
   { "R008_DetailIdentifier_1", 157 },
   { "R008_AnnotationContent_0", 158 },
   { "R008_AnnotationContentStatements_0", 159 },
   { "R008_AnnotationContentStatements_1", 160 },
   { "R008_NonPARENTHESES_0", 161 },
   { "R008_NonPARENTHESES_1", 162 },
   { "R008_NonPARENTHESES_2", 163 },
   { "R008_NonPARENTHESES_3", 164 },
   { "R008_NonPARENTHESES_4", 165 },
   { "R008_NonPARENTHESES_5", 166 },
   { "R008_NonPARENTHESES_6", 167 },
   { "R008_NonPARENTHESES_7", 168 },
   { "R008_NonPARENTHESES_8", 169 },
   { "R008_NonPARENTHESES_9", 170 },
   { "R008_NonPARENTHESES_10", 171 },
   { "R008_NonPARENTHESES_11", 172 },
   { "R008_TypeArguments_0", 173 },
   { "R008_TypeArguments_1", 174 },
   { "R008_TypeArguments_2", 175 },
   { "R008_TypeArguments_3", 176 },
   { "R008_TypeArgumentListL2_0", 177 },
   { "R008_TypeArgumentListL2_1", 178 },
   { "R008_TypeArgumentListL2_2", 179 },
   { "R008_TypeArgumentListL1_0", 180 },
   { "R008_TypeArgumentListL1_1", 181 },
   { "R008_TypeArgumentListL1_2", 182 },
   { "R008_TypeArgumentList_0", 183 },
   { "R008_TypeArgumentList_1", 184 },
   { "R008_NonANGLE_BRACKET_0", 185 },
   { "R008_NonANGLE_BRACKET_1", 186 },
   { "R008_NonANGLE_BRACKET_2", 187 },
   { "R008_NonANGLE_BRACKET_3", 188 },
   { "R008_NonANGLE_BRACKET_4", 189 },
   { "R008_NonANGLE_BRACKET_5", 190 },
   { "R008_NonANGLE_BRACKET_6", 191 },
   { "R008_NonANGLE_BRACKET_7", 192 },
   { "R008_NonANGLE_BRACKET_8", 193 },
   { "R008_NonANGLE_BRACKET_9", 194 },
   { "R008_ExtendsInterfaces_0", 195 },
   { "R008_InterfaceTypeList_0", 196 },
   { "R008_InterfaceTypeList_1", 197 },
   { "R008_ClassTypeEle_0", 198 },
   { "R008_ClassTypeEle_1", 199 },
   { "R008_ClassTypeEle_2", 200 },
   { "R008_ClassTypeEle_3", 201 },
   { "R008_ClassType_0", 202 },
   { "R008_ClassType_1", 203 },
   { "R008_InterfaceMethodDeclaration_0", 204 },
   { "R008_InterfaceMethodDeclaration_1", 205 },
   { "R008_InterfaceMethodDeclaration_2", 206 },
   { "R008_InterfaceMethodDeclaration_3", 207 },
   { "R008_MethodHeader_0", 208 },
   { "R008_MethodHeader_1", 209 },
   { "R008_Result_0", 210 },
   { "R008_Result_1", 211 },
   { "R008_UnannType_0", 212 },
   { "R008_UnannType_1", 213 },
   { "R008_UnannType_2", 214 },
   { "R008_UnannPrimitiveType_0", 215 },
   { "R008_UnannPrimitiveType_1", 216 },
   { "R008_UnannPrimitiveType_2", 217 },
   { "R008_UnannPrimitiveType_3", 218 },
   { "R008_UnannPrimitiveType_4", 219 },
   { "R008_UnannPrimitiveType_5", 220 },
   { "R008_UnannPrimitiveType_6", 221 },
   { "R008_UnannPrimitiveType_7", 222 },
   { "R008_UnannClassOrInterfaceType_0", 223 },
   { "R008_UnannClassOrInterfaceType_1", 224 },
   { "R008_UnannClassOrInterfaceType_2", 225 },
   { "R008_UnannClassOrInterfaceType_3", 226 },
   { "R008_UnannClassOrInterfaceType_4", 227 },
   { "R008_UnannClassOrInterfaceType_5", 228 },
   { "R008_UnannArrayType_0", 229 },
   { "R008_UnannArrayType_1", 230 },
   { "R008_MethodDeclarator_0", 231 },
   { "R008_MethodDeclarator_1", 232 },
   { "R008_Dims_0", 233 },
   { "R008_Dims_1", 234 },
   { "R008_Dims_2", 235 },
   { "R008_Dims_3", 236 },
   { "R008_Throws_0", 237 },
   { "R008_ExceptionTypeList_0", 238 },
   { "R008_ExceptionTypeList_1", 239 },
   { "R008_ExceptionType_0", 240 },
   { "R008_ExceptionType_1", 241 },
   { "R008_ConstantDeclaration_0", 242 },
   { "R008_ConstantDeclaration_1", 243 },
   { "R008_ConstantDeclarationFake_0", 244 },
   { "R008_ConstantDeclarationFake_1", 245 },
   { "R008_VariableDeclaratorList_0", 246 },
   { "R008_VariableDeclaratorList_1", 247 },
   { "R008_VariableDeclarator_0", 248 },
   { "R008_VariableDeclarator_1", 249 },
   { "R008_VariableInitializer_0", 250 },
   { "R008_VariableInitializer_1", 251 },
   { "R008_VariableInitializerEle_0", 252 },
   { "R008_VariableInitializerEle_1", 253 },
   { "R008_VariableInitializerEle_2", 254 },
   { "R008_VariableInitializerEle_3", 255 },
   { "R008_VariableInitializerEle_4", 256 },
   { "R008_VariableDeclaratorId_0", 257 },
   { "R008_VariableDeclaratorId_1", 258 },
   { "R008_AnnotationList_0", 259 },
   { "R008_AnnotationList_1", 260 },
   { "R008_DimExpr_0", 261 },
   { "R008_DimExpr_1", 262 },
	};
}

P_SDT_genertor SDT_R008_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R008_ele_begin_0"] = P_SDT_genertor(new R008_ele_begin_0Analyzer()); break;
	case 1: factory["R008_InterfaceMemberDeclaration_0"] = P_SDT_genertor(new R008_InterfaceMemberDeclaration_0Analyzer()); break;
	case 2: factory["R008_InterfaceMemberDeclaration_1"] = P_SDT_genertor(new R008_InterfaceMemberDeclaration_1Analyzer()); break;
	case 3: factory["R008_InterfaceMemberDeclaration_2"] = P_SDT_genertor(new R008_InterfaceMemberDeclaration_2Analyzer()); break;
	case 4: factory["R008_InterfaceMemberDeclaration_3"] = P_SDT_genertor(new R008_InterfaceMemberDeclaration_3Analyzer()); break;
	case 5: factory["R008_InterfaceMemberDeclaration_4"] = P_SDT_genertor(new R008_InterfaceMemberDeclaration_4Analyzer()); break;
	case 6: factory["R008_InterfaceDeclaration_0"] = P_SDT_genertor(new R008_InterfaceDeclaration_0Analyzer()); break;
	case 7: factory["R008_InterfaceDeclaration_1"] = P_SDT_genertor(new R008_InterfaceDeclaration_1Analyzer()); break;
	case 8: factory["R008_ClassDeclaration_0"] = P_SDT_genertor(new R008_ClassDeclaration_0Analyzer()); break;
	case 9: factory["R008_ClassDeclaration_1"] = P_SDT_genertor(new R008_ClassDeclaration_1Analyzer()); break;
	case 10: factory["R008_EnumDeclaration_0"] = P_SDT_genertor(new R008_EnumDeclaration_0Analyzer()); break;
	case 11: factory["R008_EnumDeclaration_1"] = P_SDT_genertor(new R008_EnumDeclaration_1Analyzer()); break;
	case 12: factory["R008_EnumDeclaration_2"] = P_SDT_genertor(new R008_EnumDeclaration_2Analyzer()); break;
	case 13: factory["R008_EnumDeclaration_3"] = P_SDT_genertor(new R008_EnumDeclaration_3Analyzer()); break;
	case 14: factory["R008_NormalClassDeclaration_0"] = P_SDT_genertor(new R008_NormalClassDeclaration_0Analyzer()); break;
	case 15: factory["R008_NormalClassDeclaration_1"] = P_SDT_genertor(new R008_NormalClassDeclaration_1Analyzer()); break;
	case 16: factory["R008_NormalClassDeclaration_2"] = P_SDT_genertor(new R008_NormalClassDeclaration_2Analyzer()); break;
	case 17: factory["R008_NormalClassDeclaration_3"] = P_SDT_genertor(new R008_NormalClassDeclaration_3Analyzer()); break;
	case 18: factory["R008_NormalClassDeclaration_4"] = P_SDT_genertor(new R008_NormalClassDeclaration_4Analyzer()); break;
	case 19: factory["R008_NormalClassDeclaration_5"] = P_SDT_genertor(new R008_NormalClassDeclaration_5Analyzer()); break;
	case 20: factory["R008_NormalClassDeclaration_6"] = P_SDT_genertor(new R008_NormalClassDeclaration_6Analyzer()); break;
	case 21: factory["R008_NormalClassDeclaration_7"] = P_SDT_genertor(new R008_NormalClassDeclaration_7Analyzer()); break;
	case 22: factory["R008_NormalClassDeclaration_8"] = P_SDT_genertor(new R008_NormalClassDeclaration_8Analyzer()); break;
	case 23: factory["R008_NormalClassDeclaration_9"] = P_SDT_genertor(new R008_NormalClassDeclaration_9Analyzer()); break;
	case 24: factory["R008_NormalClassDeclaration_10"] = P_SDT_genertor(new R008_NormalClassDeclaration_10Analyzer()); break;
	case 25: factory["R008_NormalClassDeclaration_11"] = P_SDT_genertor(new R008_NormalClassDeclaration_11Analyzer()); break;
	case 26: factory["R008_NormalClassDeclaration_12"] = P_SDT_genertor(new R008_NormalClassDeclaration_12Analyzer()); break;
	case 27: factory["R008_NormalClassDeclaration_13"] = P_SDT_genertor(new R008_NormalClassDeclaration_13Analyzer()); break;
	case 28: factory["R008_NormalClassDeclaration_14"] = P_SDT_genertor(new R008_NormalClassDeclaration_14Analyzer()); break;
	case 29: factory["R008_NormalClassDeclaration_15"] = P_SDT_genertor(new R008_NormalClassDeclaration_15Analyzer()); break;
	case 30: factory["R008_Superclass_0"] = P_SDT_genertor(new R008_Superclass_0Analyzer()); break;
	case 31: factory["R008_Superinterfaces_0"] = P_SDT_genertor(new R008_Superinterfaces_0Analyzer()); break;
	case 32: factory["R008_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_0Analyzer()); break;
	case 33: factory["R008_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_1Analyzer()); break;
	case 34: factory["R008_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_2Analyzer()); break;
	case 35: factory["R008_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_3Analyzer()); break;
	case 36: factory["R008_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_4Analyzer()); break;
	case 37: factory["R008_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_5Analyzer()); break;
	case 38: factory["R008_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_6Analyzer()); break;
	case 39: factory["R008_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R008_NormalInterfaceDeclaration_7Analyzer()); break;
	case 40: factory["R008_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R008_AnnotationTypeDeclaration_0Analyzer()); break;
	case 41: factory["R008_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R008_AnnotationTypeDeclaration_1Analyzer()); break;
	case 42: factory["R008_Identifier_0"] = P_SDT_genertor(new R008_Identifier_0Analyzer()); break;
	case 43: factory["R008_Block_0"] = P_SDT_genertor(new R008_Block_0Analyzer()); break;
	case 44: factory["R008_Block_1"] = P_SDT_genertor(new R008_Block_1Analyzer()); break;
	case 45: factory["R008_BlockStatements_0"] = P_SDT_genertor(new R008_BlockStatements_0Analyzer()); break;
	case 46: factory["R008_BlockStatements_1"] = P_SDT_genertor(new R008_BlockStatements_1Analyzer()); break;
	case 47: factory["R008_BlockStatements_2"] = P_SDT_genertor(new R008_BlockStatements_2Analyzer()); break;
	case 48: factory["R008_NonBrace_0"] = P_SDT_genertor(new R008_NonBrace_0Analyzer()); break;
	case 49: factory["R008_NonBrace_1"] = P_SDT_genertor(new R008_NonBrace_1Analyzer()); break;
	case 50: factory["R008_NonBrace_2"] = P_SDT_genertor(new R008_NonBrace_2Analyzer()); break;
	case 51: factory["R008_NonBrace_3"] = P_SDT_genertor(new R008_NonBrace_3Analyzer()); break;
	case 52: factory["R008_NonBrace_4"] = P_SDT_genertor(new R008_NonBrace_4Analyzer()); break;
	case 53: factory["R008_NonBrace_5"] = P_SDT_genertor(new R008_NonBrace_5Analyzer()); break;
	case 54: factory["R008_NonBrace_6"] = P_SDT_genertor(new R008_NonBrace_6Analyzer()); break;
	case 55: factory["R008_NonBrace_7"] = P_SDT_genertor(new R008_NonBrace_7Analyzer()); break;
	case 56: factory["R008_NonBrace_8"] = P_SDT_genertor(new R008_NonBrace_8Analyzer()); break;
	case 57: factory["R008_NonBrace_9"] = P_SDT_genertor(new R008_NonBrace_9Analyzer()); break;
	case 58: factory["R008_StatementEle_0"] = P_SDT_genertor(new R008_StatementEle_0Analyzer()); break;
	case 59: factory["R008_StatementEle_1"] = P_SDT_genertor(new R008_StatementEle_1Analyzer()); break;
	case 60: factory["R008_StatementEle_2"] = P_SDT_genertor(new R008_StatementEle_2Analyzer()); break;
	case 61: factory["R008_StatementEle_3"] = P_SDT_genertor(new R008_StatementEle_3Analyzer()); break;
	case 62: factory["R008_StatementEle_4"] = P_SDT_genertor(new R008_StatementEle_4Analyzer()); break;
	case 63: factory["R008_StatementEle_5"] = P_SDT_genertor(new R008_StatementEle_5Analyzer()); break;
	case 64: factory["R008_StatementEle_6"] = P_SDT_genertor(new R008_StatementEle_6Analyzer()); break;
	case 65: factory["R008_StatementEle_7"] = P_SDT_genertor(new R008_StatementEle_7Analyzer()); break;
	case 66: factory["R008_StatementEle_8"] = P_SDT_genertor(new R008_StatementEle_8Analyzer()); break;
	case 67: factory["R008_StatementEle_9"] = P_SDT_genertor(new R008_StatementEle_9Analyzer()); break;
	case 68: factory["R008_StatementEle_10"] = P_SDT_genertor(new R008_StatementEle_10Analyzer()); break;
	case 69: factory["R008_StatementEle_11"] = P_SDT_genertor(new R008_StatementEle_11Analyzer()); break;
	case 70: factory["R008_StatementEle_12"] = P_SDT_genertor(new R008_StatementEle_12Analyzer()); break;
	case 71: factory["R008_StatementEle_13"] = P_SDT_genertor(new R008_StatementEle_13Analyzer()); break;
	case 72: factory["R008_StatementEle_14"] = P_SDT_genertor(new R008_StatementEle_14Analyzer()); break;
	case 73: factory["R008_StatementEle_15"] = P_SDT_genertor(new R008_StatementEle_15Analyzer()); break;
	case 74: factory["R008_StatementEle_16"] = P_SDT_genertor(new R008_StatementEle_16Analyzer()); break;
	case 75: factory["R008_StatementEle_17"] = P_SDT_genertor(new R008_StatementEle_17Analyzer()); break;
	case 76: factory["R008_StatementEle_18"] = P_SDT_genertor(new R008_StatementEle_18Analyzer()); break;
	case 77: factory["R008_StatementEle_19"] = P_SDT_genertor(new R008_StatementEle_19Analyzer()); break;
	case 78: factory["R008_StatementEle_20"] = P_SDT_genertor(new R008_StatementEle_20Analyzer()); break;
	case 79: factory["R008_StatementEle_21"] = P_SDT_genertor(new R008_StatementEle_21Analyzer()); break;
	case 80: factory["R008_StatementEle_22"] = P_SDT_genertor(new R008_StatementEle_22Analyzer()); break;
	case 81: factory["R008_StatementEle_23"] = P_SDT_genertor(new R008_StatementEle_23Analyzer()); break;
	case 82: factory["R008_StatementEle_24"] = P_SDT_genertor(new R008_StatementEle_24Analyzer()); break;
	case 83: factory["R008_StatementEle_25"] = P_SDT_genertor(new R008_StatementEle_25Analyzer()); break;
	case 84: factory["R008_StatementEle_26"] = P_SDT_genertor(new R008_StatementEle_26Analyzer()); break;
	case 85: factory["R008_StatementEle_27"] = P_SDT_genertor(new R008_StatementEle_27Analyzer()); break;
	case 86: factory["R008_StatementEle_28"] = P_SDT_genertor(new R008_StatementEle_28Analyzer()); break;
	case 87: factory["R008_StatementEle_29"] = P_SDT_genertor(new R008_StatementEle_29Analyzer()); break;
	case 88: factory["R008_StatementEle_30"] = P_SDT_genertor(new R008_StatementEle_30Analyzer()); break;
	case 89: factory["R008_StatementEle_31"] = P_SDT_genertor(new R008_StatementEle_31Analyzer()); break;
	case 90: factory["R008_StatementEle_32"] = P_SDT_genertor(new R008_StatementEle_32Analyzer()); break;
	case 91: factory["R008_StatementEle_33"] = P_SDT_genertor(new R008_StatementEle_33Analyzer()); break;
	case 92: factory["R008_StatementEle_34"] = P_SDT_genertor(new R008_StatementEle_34Analyzer()); break;
	case 93: factory["R008_StatementEle_35"] = P_SDT_genertor(new R008_StatementEle_35Analyzer()); break;
	case 94: factory["R008_StatementEle_36"] = P_SDT_genertor(new R008_StatementEle_36Analyzer()); break;
	case 95: factory["R008_StatementEle_37"] = P_SDT_genertor(new R008_StatementEle_37Analyzer()); break;
	case 96: factory["R008_StatementEle_38"] = P_SDT_genertor(new R008_StatementEle_38Analyzer()); break;
	case 97: factory["R008_StatementEle_39"] = P_SDT_genertor(new R008_StatementEle_39Analyzer()); break;
	case 98: factory["R008_StatementEle_40"] = P_SDT_genertor(new R008_StatementEle_40Analyzer()); break;
	case 99: factory["R008_StatementEle_41"] = P_SDT_genertor(new R008_StatementEle_41Analyzer()); break;
	case 100: factory["R008_StatementEle_42"] = P_SDT_genertor(new R008_StatementEle_42Analyzer()); break;
	case 101: factory["R008_StatementEle_43"] = P_SDT_genertor(new R008_StatementEle_43Analyzer()); break;
	case 102: factory["R008_StatementEle_44"] = P_SDT_genertor(new R008_StatementEle_44Analyzer()); break;
	case 103: factory["R008_StatementEle_45"] = P_SDT_genertor(new R008_StatementEle_45Analyzer()); break;
	case 104: factory["R008_StatementEle_46"] = P_SDT_genertor(new R008_StatementEle_46Analyzer()); break;
	case 105: factory["R008_StatementEle_47"] = P_SDT_genertor(new R008_StatementEle_47Analyzer()); break;
	case 106: factory["R008_StatementEle_48"] = P_SDT_genertor(new R008_StatementEle_48Analyzer()); break;
	case 107: factory["R008_StatementEle_49"] = P_SDT_genertor(new R008_StatementEle_49Analyzer()); break;
	case 108: factory["R008_StatementEle_50"] = P_SDT_genertor(new R008_StatementEle_50Analyzer()); break;
	case 109: factory["R008_StatementEle_51"] = P_SDT_genertor(new R008_StatementEle_51Analyzer()); break;
	case 110: factory["R008_StatementEle_52"] = P_SDT_genertor(new R008_StatementEle_52Analyzer()); break;
	case 111: factory["R008_StatementEle_53"] = P_SDT_genertor(new R008_StatementEle_53Analyzer()); break;
	case 112: factory["R008_StatementEle_54"] = P_SDT_genertor(new R008_StatementEle_54Analyzer()); break;
	case 113: factory["R008_StatementEle_55"] = P_SDT_genertor(new R008_StatementEle_55Analyzer()); break;
	case 114: factory["R008_StatementEle_56"] = P_SDT_genertor(new R008_StatementEle_56Analyzer()); break;
	case 115: factory["R008_StatementEle_57"] = P_SDT_genertor(new R008_StatementEle_57Analyzer()); break;
	case 116: factory["R008_StatementEle_58"] = P_SDT_genertor(new R008_StatementEle_58Analyzer()); break;
	case 117: factory["R008_StatementEle_59"] = P_SDT_genertor(new R008_StatementEle_59Analyzer()); break;
	case 118: factory["R008_StatementEle_60"] = P_SDT_genertor(new R008_StatementEle_60Analyzer()); break;
	case 119: factory["R008_StatementEle_61"] = P_SDT_genertor(new R008_StatementEle_61Analyzer()); break;
	case 120: factory["R008_StatementEle_62"] = P_SDT_genertor(new R008_StatementEle_62Analyzer()); break;
	case 121: factory["R008_StatementEle_63"] = P_SDT_genertor(new R008_StatementEle_63Analyzer()); break;
	case 122: factory["R008_StatementEle_64"] = P_SDT_genertor(new R008_StatementEle_64Analyzer()); break;
	case 123: factory["R008_StatementEle_65"] = P_SDT_genertor(new R008_StatementEle_65Analyzer()); break;
	case 124: factory["R008_StatementEle_66"] = P_SDT_genertor(new R008_StatementEle_66Analyzer()); break;
	case 125: factory["R008_StatementEle_67"] = P_SDT_genertor(new R008_StatementEle_67Analyzer()); break;
	case 126: factory["R008_StatementEle_68"] = P_SDT_genertor(new R008_StatementEle_68Analyzer()); break;
	case 127: factory["R008_StatementEle_69"] = P_SDT_genertor(new R008_StatementEle_69Analyzer()); break;
	case 128: factory["R008_StatementEle_70"] = P_SDT_genertor(new R008_StatementEle_70Analyzer()); break;
	case 129: factory["R008_StatementEle_71"] = P_SDT_genertor(new R008_StatementEle_71Analyzer()); break;
	case 130: factory["R008_StatementEle_72"] = P_SDT_genertor(new R008_StatementEle_72Analyzer()); break;
	case 131: factory["R008_StatementEle_73"] = P_SDT_genertor(new R008_StatementEle_73Analyzer()); break;
	case 132: factory["R008_StatementEle_74"] = P_SDT_genertor(new R008_StatementEle_74Analyzer()); break;
	case 133: factory["R008_StatementEle_75"] = P_SDT_genertor(new R008_StatementEle_75Analyzer()); break;
	case 134: factory["R008_StatementEle_76"] = P_SDT_genertor(new R008_StatementEle_76Analyzer()); break;
	case 135: factory["R008_StatementEle_77"] = P_SDT_genertor(new R008_StatementEle_77Analyzer()); break;
	case 136: factory["R008_StatementEle_78"] = P_SDT_genertor(new R008_StatementEle_78Analyzer()); break;
	case 137: factory["R008_StatementEle_79"] = P_SDT_genertor(new R008_StatementEle_79Analyzer()); break;
	case 138: factory["R008_ModifierList_0"] = P_SDT_genertor(new R008_ModifierList_0Analyzer()); break;
	case 139: factory["R008_ModifierList_1"] = P_SDT_genertor(new R008_ModifierList_1Analyzer()); break;
	case 140: factory["R008_Modifier_0"] = P_SDT_genertor(new R008_Modifier_0Analyzer()); break;
	case 141: factory["R008_Modifier_1"] = P_SDT_genertor(new R008_Modifier_1Analyzer()); break;
	case 142: factory["R008_Modifier_2"] = P_SDT_genertor(new R008_Modifier_2Analyzer()); break;
	case 143: factory["R008_Modifier_3"] = P_SDT_genertor(new R008_Modifier_3Analyzer()); break;
	case 144: factory["R008_Modifier_4"] = P_SDT_genertor(new R008_Modifier_4Analyzer()); break;
	case 145: factory["R008_Modifier_5"] = P_SDT_genertor(new R008_Modifier_5Analyzer()); break;
	case 146: factory["R008_Modifier_6"] = P_SDT_genertor(new R008_Modifier_6Analyzer()); break;
	case 147: factory["R008_Modifier_7"] = P_SDT_genertor(new R008_Modifier_7Analyzer()); break;
	case 148: factory["R008_Modifier_8"] = P_SDT_genertor(new R008_Modifier_8Analyzer()); break;
	case 149: factory["R008_Modifier_9"] = P_SDT_genertor(new R008_Modifier_9Analyzer()); break;
	case 150: factory["R008_Modifier_10"] = P_SDT_genertor(new R008_Modifier_10Analyzer()); break;
	case 151: factory["R008_Modifier_11"] = P_SDT_genertor(new R008_Modifier_11Analyzer()); break;
	case 152: factory["R008_Modifier_12"] = P_SDT_genertor(new R008_Modifier_12Analyzer()); break;
	case 153: factory["R008_Modifier_13"] = P_SDT_genertor(new R008_Modifier_13Analyzer()); break;
	case 154: factory["R008_Annotation_0"] = P_SDT_genertor(new R008_Annotation_0Analyzer()); break;
	case 155: factory["R008_Annotation_1"] = P_SDT_genertor(new R008_Annotation_1Analyzer()); break;
	case 156: factory["R008_DetailIdentifier_0"] = P_SDT_genertor(new R008_DetailIdentifier_0Analyzer()); break;
	case 157: factory["R008_DetailIdentifier_1"] = P_SDT_genertor(new R008_DetailIdentifier_1Analyzer()); break;
	case 158: factory["R008_AnnotationContent_0"] = P_SDT_genertor(new R008_AnnotationContent_0Analyzer()); break;
	case 159: factory["R008_AnnotationContentStatements_0"] = P_SDT_genertor(new R008_AnnotationContentStatements_0Analyzer()); break;
	case 160: factory["R008_AnnotationContentStatements_1"] = P_SDT_genertor(new R008_AnnotationContentStatements_1Analyzer()); break;
	case 161: factory["R008_NonPARENTHESES_0"] = P_SDT_genertor(new R008_NonPARENTHESES_0Analyzer()); break;
	case 162: factory["R008_NonPARENTHESES_1"] = P_SDT_genertor(new R008_NonPARENTHESES_1Analyzer()); break;
	case 163: factory["R008_NonPARENTHESES_2"] = P_SDT_genertor(new R008_NonPARENTHESES_2Analyzer()); break;
	case 164: factory["R008_NonPARENTHESES_3"] = P_SDT_genertor(new R008_NonPARENTHESES_3Analyzer()); break;
	case 165: factory["R008_NonPARENTHESES_4"] = P_SDT_genertor(new R008_NonPARENTHESES_4Analyzer()); break;
	case 166: factory["R008_NonPARENTHESES_5"] = P_SDT_genertor(new R008_NonPARENTHESES_5Analyzer()); break;
	case 167: factory["R008_NonPARENTHESES_6"] = P_SDT_genertor(new R008_NonPARENTHESES_6Analyzer()); break;
	case 168: factory["R008_NonPARENTHESES_7"] = P_SDT_genertor(new R008_NonPARENTHESES_7Analyzer()); break;
	case 169: factory["R008_NonPARENTHESES_8"] = P_SDT_genertor(new R008_NonPARENTHESES_8Analyzer()); break;
	case 170: factory["R008_NonPARENTHESES_9"] = P_SDT_genertor(new R008_NonPARENTHESES_9Analyzer()); break;
	case 171: factory["R008_NonPARENTHESES_10"] = P_SDT_genertor(new R008_NonPARENTHESES_10Analyzer()); break;
	case 172: factory["R008_NonPARENTHESES_11"] = P_SDT_genertor(new R008_NonPARENTHESES_11Analyzer()); break;
	case 173: factory["R008_TypeArguments_0"] = P_SDT_genertor(new R008_TypeArguments_0Analyzer()); break;
	case 174: factory["R008_TypeArguments_1"] = P_SDT_genertor(new R008_TypeArguments_1Analyzer()); break;
	case 175: factory["R008_TypeArguments_2"] = P_SDT_genertor(new R008_TypeArguments_2Analyzer()); break;
	case 176: factory["R008_TypeArguments_3"] = P_SDT_genertor(new R008_TypeArguments_3Analyzer()); break;
	case 177: factory["R008_TypeArgumentListL2_0"] = P_SDT_genertor(new R008_TypeArgumentListL2_0Analyzer()); break;
	case 178: factory["R008_TypeArgumentListL2_1"] = P_SDT_genertor(new R008_TypeArgumentListL2_1Analyzer()); break;
	case 179: factory["R008_TypeArgumentListL2_2"] = P_SDT_genertor(new R008_TypeArgumentListL2_2Analyzer()); break;
	case 180: factory["R008_TypeArgumentListL1_0"] = P_SDT_genertor(new R008_TypeArgumentListL1_0Analyzer()); break;
	case 181: factory["R008_TypeArgumentListL1_1"] = P_SDT_genertor(new R008_TypeArgumentListL1_1Analyzer()); break;
	case 182: factory["R008_TypeArgumentListL1_2"] = P_SDT_genertor(new R008_TypeArgumentListL1_2Analyzer()); break;
	case 183: factory["R008_TypeArgumentList_0"] = P_SDT_genertor(new R008_TypeArgumentList_0Analyzer()); break;
	case 184: factory["R008_TypeArgumentList_1"] = P_SDT_genertor(new R008_TypeArgumentList_1Analyzer()); break;
	case 185: factory["R008_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_0Analyzer()); break;
	case 186: factory["R008_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_1Analyzer()); break;
	case 187: factory["R008_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_2Analyzer()); break;
	case 188: factory["R008_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_3Analyzer()); break;
	case 189: factory["R008_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_4Analyzer()); break;
	case 190: factory["R008_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_5Analyzer()); break;
	case 191: factory["R008_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_6Analyzer()); break;
	case 192: factory["R008_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_7Analyzer()); break;
	case 193: factory["R008_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_8Analyzer()); break;
	case 194: factory["R008_NonANGLE_BRACKET_9"] = P_SDT_genertor(new R008_NonANGLE_BRACKET_9Analyzer()); break;
	case 195: factory["R008_ExtendsInterfaces_0"] = P_SDT_genertor(new R008_ExtendsInterfaces_0Analyzer()); break;
	case 196: factory["R008_InterfaceTypeList_0"] = P_SDT_genertor(new R008_InterfaceTypeList_0Analyzer()); break;
	case 197: factory["R008_InterfaceTypeList_1"] = P_SDT_genertor(new R008_InterfaceTypeList_1Analyzer()); break;
	case 198: factory["R008_ClassTypeEle_0"] = P_SDT_genertor(new R008_ClassTypeEle_0Analyzer()); break;
	case 199: factory["R008_ClassTypeEle_1"] = P_SDT_genertor(new R008_ClassTypeEle_1Analyzer()); break;
	case 200: factory["R008_ClassTypeEle_2"] = P_SDT_genertor(new R008_ClassTypeEle_2Analyzer()); break;
	case 201: factory["R008_ClassTypeEle_3"] = P_SDT_genertor(new R008_ClassTypeEle_3Analyzer()); break;
	case 202: factory["R008_ClassType_0"] = P_SDT_genertor(new R008_ClassType_0Analyzer()); break;
	case 203: factory["R008_ClassType_1"] = P_SDT_genertor(new R008_ClassType_1Analyzer()); break;
	case 204: factory["R008_InterfaceMethodDeclaration_0"] = P_SDT_genertor(new R008_InterfaceMethodDeclaration_0Analyzer()); break;
	case 205: factory["R008_InterfaceMethodDeclaration_1"] = P_SDT_genertor(new R008_InterfaceMethodDeclaration_1Analyzer()); break;
	case 206: factory["R008_InterfaceMethodDeclaration_2"] = P_SDT_genertor(new R008_InterfaceMethodDeclaration_2Analyzer()); break;
	case 207: factory["R008_InterfaceMethodDeclaration_3"] = P_SDT_genertor(new R008_InterfaceMethodDeclaration_3Analyzer()); break;
	case 208: factory["R008_MethodHeader_0"] = P_SDT_genertor(new R008_MethodHeader_0Analyzer()); break;
	case 209: factory["R008_MethodHeader_1"] = P_SDT_genertor(new R008_MethodHeader_1Analyzer()); break;
	case 210: factory["R008_Result_0"] = P_SDT_genertor(new R008_Result_0Analyzer()); break;
	case 211: factory["R008_Result_1"] = P_SDT_genertor(new R008_Result_1Analyzer()); break;
	case 212: factory["R008_UnannType_0"] = P_SDT_genertor(new R008_UnannType_0Analyzer()); break;
	case 213: factory["R008_UnannType_1"] = P_SDT_genertor(new R008_UnannType_1Analyzer()); break;
	case 214: factory["R008_UnannType_2"] = P_SDT_genertor(new R008_UnannType_2Analyzer()); break;
	case 215: factory["R008_UnannPrimitiveType_0"] = P_SDT_genertor(new R008_UnannPrimitiveType_0Analyzer()); break;
	case 216: factory["R008_UnannPrimitiveType_1"] = P_SDT_genertor(new R008_UnannPrimitiveType_1Analyzer()); break;
	case 217: factory["R008_UnannPrimitiveType_2"] = P_SDT_genertor(new R008_UnannPrimitiveType_2Analyzer()); break;
	case 218: factory["R008_UnannPrimitiveType_3"] = P_SDT_genertor(new R008_UnannPrimitiveType_3Analyzer()); break;
	case 219: factory["R008_UnannPrimitiveType_4"] = P_SDT_genertor(new R008_UnannPrimitiveType_4Analyzer()); break;
	case 220: factory["R008_UnannPrimitiveType_5"] = P_SDT_genertor(new R008_UnannPrimitiveType_5Analyzer()); break;
	case 221: factory["R008_UnannPrimitiveType_6"] = P_SDT_genertor(new R008_UnannPrimitiveType_6Analyzer()); break;
	case 222: factory["R008_UnannPrimitiveType_7"] = P_SDT_genertor(new R008_UnannPrimitiveType_7Analyzer()); break;
	case 223: factory["R008_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R008_UnannClassOrInterfaceType_0Analyzer()); break;
	case 224: factory["R008_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R008_UnannClassOrInterfaceType_1Analyzer()); break;
	case 225: factory["R008_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R008_UnannClassOrInterfaceType_2Analyzer()); break;
	case 226: factory["R008_UnannClassOrInterfaceType_3"] = P_SDT_genertor(new R008_UnannClassOrInterfaceType_3Analyzer()); break;
	case 227: factory["R008_UnannClassOrInterfaceType_4"] = P_SDT_genertor(new R008_UnannClassOrInterfaceType_4Analyzer()); break;
	case 228: factory["R008_UnannClassOrInterfaceType_5"] = P_SDT_genertor(new R008_UnannClassOrInterfaceType_5Analyzer()); break;
	case 229: factory["R008_UnannArrayType_0"] = P_SDT_genertor(new R008_UnannArrayType_0Analyzer()); break;
	case 230: factory["R008_UnannArrayType_1"] = P_SDT_genertor(new R008_UnannArrayType_1Analyzer()); break;
	case 231: factory["R008_MethodDeclarator_0"] = P_SDT_genertor(new R008_MethodDeclarator_0Analyzer()); break;
	case 232: factory["R008_MethodDeclarator_1"] = P_SDT_genertor(new R008_MethodDeclarator_1Analyzer()); break;
	case 233: factory["R008_Dims_0"] = P_SDT_genertor(new R008_Dims_0Analyzer()); break;
	case 234: factory["R008_Dims_1"] = P_SDT_genertor(new R008_Dims_1Analyzer()); break;
	case 235: factory["R008_Dims_2"] = P_SDT_genertor(new R008_Dims_2Analyzer()); break;
	case 236: factory["R008_Dims_3"] = P_SDT_genertor(new R008_Dims_3Analyzer()); break;
	case 237: factory["R008_Throws_0"] = P_SDT_genertor(new R008_Throws_0Analyzer()); break;
	case 238: factory["R008_ExceptionTypeList_0"] = P_SDT_genertor(new R008_ExceptionTypeList_0Analyzer()); break;
	case 239: factory["R008_ExceptionTypeList_1"] = P_SDT_genertor(new R008_ExceptionTypeList_1Analyzer()); break;
	case 240: factory["R008_ExceptionType_0"] = P_SDT_genertor(new R008_ExceptionType_0Analyzer()); break;
	case 241: factory["R008_ExceptionType_1"] = P_SDT_genertor(new R008_ExceptionType_1Analyzer()); break;
	case 242: factory["R008_ConstantDeclaration_0"] = P_SDT_genertor(new R008_ConstantDeclaration_0Analyzer()); break;
	case 243: factory["R008_ConstantDeclaration_1"] = P_SDT_genertor(new R008_ConstantDeclaration_1Analyzer()); break;
	case 244: factory["R008_ConstantDeclarationFake_0"] = P_SDT_genertor(new R008_ConstantDeclarationFake_0Analyzer()); break;
	case 245: factory["R008_ConstantDeclarationFake_1"] = P_SDT_genertor(new R008_ConstantDeclarationFake_1Analyzer()); break;
	case 246: factory["R008_VariableDeclaratorList_0"] = P_SDT_genertor(new R008_VariableDeclaratorList_0Analyzer()); break;
	case 247: factory["R008_VariableDeclaratorList_1"] = P_SDT_genertor(new R008_VariableDeclaratorList_1Analyzer()); break;
	case 248: factory["R008_VariableDeclarator_0"] = P_SDT_genertor(new R008_VariableDeclarator_0Analyzer()); break;
	case 249: factory["R008_VariableDeclarator_1"] = P_SDT_genertor(new R008_VariableDeclarator_1Analyzer()); break;
	case 250: factory["R008_VariableInitializer_0"] = P_SDT_genertor(new R008_VariableInitializer_0Analyzer()); break;
	case 251: factory["R008_VariableInitializer_1"] = P_SDT_genertor(new R008_VariableInitializer_1Analyzer()); break;
	case 252: factory["R008_VariableInitializerEle_0"] = P_SDT_genertor(new R008_VariableInitializerEle_0Analyzer()); break;
	case 253: factory["R008_VariableInitializerEle_1"] = P_SDT_genertor(new R008_VariableInitializerEle_1Analyzer()); break;
	case 254: factory["R008_VariableInitializerEle_2"] = P_SDT_genertor(new R008_VariableInitializerEle_2Analyzer()); break;
	case 255: factory["R008_VariableInitializerEle_3"] = P_SDT_genertor(new R008_VariableInitializerEle_3Analyzer()); break;
	case 256: factory["R008_VariableInitializerEle_4"] = P_SDT_genertor(new R008_VariableInitializerEle_4Analyzer()); break;
	case 257: factory["R008_VariableDeclaratorId_0"] = P_SDT_genertor(new R008_VariableDeclaratorId_0Analyzer()); break;
	case 258: factory["R008_VariableDeclaratorId_1"] = P_SDT_genertor(new R008_VariableDeclaratorId_1Analyzer()); break;
	case 259: factory["R008_AnnotationList_0"] = P_SDT_genertor(new R008_AnnotationList_0Analyzer()); break;
	case 260: factory["R008_AnnotationList_1"] = P_SDT_genertor(new R008_AnnotationList_1Analyzer()); break;
	case 261: factory["R008_DimExpr_0"] = P_SDT_genertor(new R008_DimExpr_0Analyzer()); break;
	case 262: factory["R008_DimExpr_1"] = P_SDT_genertor(new R008_DimExpr_1Analyzer()); break;
	default:

		if (key.find("R008_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R008_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R008_Factory::~SDT_R008_Factory() {}
