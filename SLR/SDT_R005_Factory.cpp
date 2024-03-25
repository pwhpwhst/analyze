#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R005_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R005Analyzer.h"
using namespace std;
using namespace boost;



SDT_R005_Factory SDT_R005_Factory::instance;
SDT_R005_Factory::SDT_R005_Factory() {
	control_Param = {
   { "R005_ele_begin_0", 0 },
   { "R005_ClassBodyDeclaration_0", 1 },
   { "R005_ClassBodyDeclaration_1", 2 },
   { "R005_ClassBodyDeclaration_2", 3 },
   { "R005_ClassBodyDeclaration_3", 4 },
   { "R005_ClassMemberDeclaration_0", 5 },
   { "R005_ClassMemberDeclaration_1", 6 },
   { "R005_ClassMemberDeclaration_2", 7 },
   { "R005_ClassMemberDeclaration_3", 8 },
   { "R005_ClassMemberDeclaration_4", 9 },
   { "R005_FieldDeclaration_0", 10 },
   { "R005_FieldDeclaration_1", 11 },
   { "R005_FieldDeclarationFake_0", 12 },
   { "R005_FieldDeclarationFake_1", 13 },
   { "R005_InstanceInitializer_0", 14 },
   { "R005_StaticInitializer_0", 15 },
   { "R005_Block_0", 16 },
   { "R005_Block_1", 17 },
   { "R005_BlockStatements_0", 18 },
   { "R005_BlockStatements_1", 19 },
   { "R005_BlockStatements_2", 20 },
   { "R005_NonBrace_0", 21 },
   { "R005_NonBrace_1", 22 },
   { "R005_NonBrace_2", 23 },
   { "R005_NonBrace_3", 24 },
   { "R005_NonBrace_4", 25 },
   { "R005_NonBrace_5", 26 },
   { "R005_NonBrace_6", 27 },
   { "R005_NonBrace_7", 28 },
   { "R005_NonBrace_8", 29 },
   { "R005_NonBrace_9", 30 },
   { "R005_StatementEle_0", 31 },
   { "R005_StatementEle_1", 32 },
   { "R005_StatementEle_2", 33 },
   { "R005_StatementEle_3", 34 },
   { "R005_StatementEle_4", 35 },
   { "R005_StatementEle_5", 36 },
   { "R005_StatementEle_6", 37 },
   { "R005_StatementEle_7", 38 },
   { "R005_StatementEle_8", 39 },
   { "R005_StatementEle_9", 40 },
   { "R005_StatementEle_10", 41 },
   { "R005_StatementEle_11", 42 },
   { "R005_StatementEle_12", 43 },
   { "R005_StatementEle_13", 44 },
   { "R005_StatementEle_14", 45 },
   { "R005_StatementEle_15", 46 },
   { "R005_StatementEle_16", 47 },
   { "R005_StatementEle_17", 48 },
   { "R005_StatementEle_18", 49 },
   { "R005_StatementEle_19", 50 },
   { "R005_StatementEle_20", 51 },
   { "R005_StatementEle_21", 52 },
   { "R005_StatementEle_22", 53 },
   { "R005_StatementEle_23", 54 },
   { "R005_StatementEle_24", 55 },
   { "R005_StatementEle_25", 56 },
   { "R005_StatementEle_26", 57 },
   { "R005_StatementEle_27", 58 },
   { "R005_StatementEle_28", 59 },
   { "R005_StatementEle_29", 60 },
   { "R005_StatementEle_30", 61 },
   { "R005_StatementEle_31", 62 },
   { "R005_StatementEle_32", 63 },
   { "R005_StatementEle_33", 64 },
   { "R005_StatementEle_34", 65 },
   { "R005_StatementEle_35", 66 },
   { "R005_StatementEle_36", 67 },
   { "R005_StatementEle_37", 68 },
   { "R005_StatementEle_38", 69 },
   { "R005_StatementEle_39", 70 },
   { "R005_StatementEle_40", 71 },
   { "R005_StatementEle_41", 72 },
   { "R005_StatementEle_42", 73 },
   { "R005_StatementEle_43", 74 },
   { "R005_StatementEle_44", 75 },
   { "R005_StatementEle_45", 76 },
   { "R005_StatementEle_46", 77 },
   { "R005_StatementEle_47", 78 },
   { "R005_StatementEle_48", 79 },
   { "R005_StatementEle_49", 80 },
   { "R005_StatementEle_50", 81 },
   { "R005_StatementEle_51", 82 },
   { "R005_StatementEle_52", 83 },
   { "R005_StatementEle_53", 84 },
   { "R005_StatementEle_54", 85 },
   { "R005_StatementEle_55", 86 },
   { "R005_StatementEle_56", 87 },
   { "R005_StatementEle_57", 88 },
   { "R005_StatementEle_58", 89 },
   { "R005_StatementEle_59", 90 },
   { "R005_StatementEle_60", 91 },
   { "R005_StatementEle_61", 92 },
   { "R005_StatementEle_62", 93 },
   { "R005_StatementEle_63", 94 },
   { "R005_StatementEle_64", 95 },
   { "R005_StatementEle_65", 96 },
   { "R005_StatementEle_66", 97 },
   { "R005_StatementEle_67", 98 },
   { "R005_StatementEle_68", 99 },
   { "R005_StatementEle_69", 100 },
   { "R005_StatementEle_70", 101 },
   { "R005_StatementEle_71", 102 },
   { "R005_StatementEle_72", 103 },
   { "R005_StatementEle_73", 104 },
   { "R005_StatementEle_74", 105 },
   { "R005_StatementEle_75", 106 },
   { "R005_StatementEle_76", 107 },
   { "R005_StatementEle_77", 108 },
   { "R005_StatementEle_78", 109 },
   { "R005_StatementEle_79", 110 },
   { "R005_Identifier_0", 111 },
   { "R005_ModifierList_0", 112 },
   { "R005_ModifierList_1", 113 },
   { "R005_Modifier_0", 114 },
   { "R005_Modifier_1", 115 },
   { "R005_Modifier_2", 116 },
   { "R005_Modifier_3", 117 },
   { "R005_Modifier_4", 118 },
   { "R005_Modifier_5", 119 },
   { "R005_Modifier_6", 120 },
   { "R005_Modifier_7", 121 },
   { "R005_Modifier_8", 122 },
   { "R005_Modifier_9", 123 },
   { "R005_Modifier_10", 124 },
   { "R005_Modifier_11", 125 },
   { "R005_Modifier_12", 126 },
   { "R005_Annotation_0", 127 },
   { "R005_Annotation_1", 128 },
   { "R005_DetailIdentifier_0", 129 },
   { "R005_DetailIdentifier_1", 130 },
   { "R005_AnnotationContent_0", 131 },
   { "R005_AnnotationContentStatements_0", 132 },
   { "R005_AnnotationContentStatements_1", 133 },
   { "R005_NonPARENTHESES_0", 134 },
   { "R005_NonPARENTHESES_1", 135 },
   { "R005_NonPARENTHESES_2", 136 },
   { "R005_NonPARENTHESES_3", 137 },
   { "R005_NonPARENTHESES_4", 138 },
   { "R005_NonPARENTHESES_5", 139 },
   { "R005_NonPARENTHESES_6", 140 },
   { "R005_NonPARENTHESES_7", 141 },
   { "R005_NonPARENTHESES_8", 142 },
   { "R005_NonPARENTHESES_9", 143 },
   { "R005_NonPARENTHESES_10", 144 },
   { "R005_TypeArguments_0", 145 },
   { "R005_TypeArgumentList_0", 146 },
   { "R005_TypeArgumentList_1", 147 },
   { "R005_NonANGLE_BRACKET_0", 148 },
   { "R005_NonANGLE_BRACKET_1", 149 },
   { "R005_NonANGLE_BRACKET_2", 150 },
   { "R005_NonANGLE_BRACKET_3", 151 },
   { "R005_NonANGLE_BRACKET_4", 152 },
   { "R005_NonANGLE_BRACKET_5", 153 },
   { "R005_NonANGLE_BRACKET_6", 154 },
   { "R005_NonANGLE_BRACKET_7", 155 },
   { "R005_NonANGLE_BRACKET_8", 156 },
   { "R005_NonANGLE_BRACKET_9", 157 },
   { "R005_Dims_0", 158 },
   { "R005_Dims_1", 159 },
   { "R005_Dims_2", 160 },
   { "R005_Dims_3", 161 },
   { "R005_UnannType_0", 162 },
   { "R005_UnannType_1", 163 },
   { "R005_UnannType_2", 164 },
   { "R005_UnannPrimitiveType_0", 165 },
   { "R005_UnannPrimitiveType_1", 166 },
   { "R005_UnannPrimitiveType_2", 167 },
   { "R005_UnannPrimitiveType_3", 168 },
   { "R005_UnannPrimitiveType_4", 169 },
   { "R005_UnannPrimitiveType_5", 170 },
   { "R005_UnannPrimitiveType_6", 171 },
   { "R005_UnannPrimitiveType_7", 172 },
   { "R005_UnannClassOrInterfaceType_0", 173 },
   { "R005_UnannClassOrInterfaceType_1", 174 },
   { "R005_UnannClassOrInterfaceType_2", 175 },
   { "R005_UnannClassOrInterfaceType_3", 176 },
   { "R005_UnannClassOrInterfaceType_4", 177 },
   { "R005_UnannClassOrInterfaceType_5", 178 },
   { "R005_UnannArrayType_0", 179 },
   { "R005_UnannArrayType_1", 180 },
   { "R005_VariableDeclaratorList_0", 181 },
   { "R005_VariableDeclaratorList_1", 182 },
   { "R005_VariableDeclarator_0", 183 },
   { "R005_VariableDeclarator_1", 184 },
   { "R005_VariableInitializer_0", 185 },
   { "R005_VariableInitializer_1", 186 },
   { "R005_VariableInitializerEle_0", 187 },
   { "R005_VariableInitializerEle_1", 188 },
   { "R005_VariableInitializerEle_2", 189 },
   { "R005_VariableInitializerEle_3", 190 },
   { "R005_VariableDeclaratorId_0", 191 },
   { "R005_VariableDeclaratorId_1", 192 },
   { "R005_MethodDeclaration_0", 193 },
   { "R005_MethodDeclaration_1", 194 },
   { "R005_MethodDeclaration_2", 195 },
   { "R005_MethodDeclaration_3", 196 },
   { "R005_MethodDeclaration_4", 197 },
   { "R005_MethodDeclaration_5", 198 },
   { "R005_MethodDeclaration_6", 199 },
   { "R005_MethodDeclaration_7", 200 },
   { "R005_MethodDeclaration_8", 201 },
   { "R005_MethodDeclaration_9", 202 },
   { "R005_MethodDeclaration_10", 203 },
   { "R005_MethodDeclaration_11", 204 },
   { "R005_MethodDeclaration_12", 205 },
   { "R005_MethodDeclaration_13", 206 },
   { "R005_MethodDeclaration_14", 207 },
   { "R005_MethodDeclaration_15", 208 },
   { "R005_MethodDeclaration_16", 209 },
   { "R005_MethodDeclaration_17", 210 },
   { "R005_MethodDeclaration_18", 211 },
   { "R005_MethodDeclaration_19", 212 },
   { "R005_MethodHeader_0", 213 },
   { "R005_MethodHeader_1", 214 },
   { "R005_Result_0", 215 },
   { "R005_Result_1", 216 },
   { "R005_MethodDeclarator_0", 217 },
   { "R005_MethodDeclarator_1", 218 },
   { "R005_Throws_0", 219 },
   { "R005_ExceptionTypeList_0", 220 },
   { "R005_ExceptionTypeList_1", 221 },
   { "R005_ExceptionType_0", 222 },
   { "R005_ExceptionType_1", 223 },
   { "R005_ConstructorDeclaration_0", 224 },
   { "R005_ConstructorDeclaration_1", 225 },
   { "R005_ConstructorDeclaration_2", 226 },
   { "R005_ConstructorDeclaration_3", 227 },
   { "R005_ConstructorDeclarator_0", 228 },
   { "R005_ConstructorDeclarator_1", 229 },
   { "R005_ClassDeclaration_0", 230 },
   { "R005_ClassDeclaration_1", 231 },
   { "R005_NormalClassDeclaration_0", 232 },
   { "R005_NormalClassDeclaration_1", 233 },
   { "R005_NormalClassDeclaration_2", 234 },
   { "R005_NormalClassDeclaration_3", 235 },
   { "R005_NormalClassDeclaration_4", 236 },
   { "R005_NormalClassDeclaration_5", 237 },
   { "R005_NormalClassDeclaration_6", 238 },
   { "R005_NormalClassDeclaration_7", 239 },
   { "R005_NormalClassDeclaration_8", 240 },
   { "R005_NormalClassDeclaration_9", 241 },
   { "R005_NormalClassDeclaration_10", 242 },
   { "R005_NormalClassDeclaration_11", 243 },
   { "R005_NormalClassDeclaration_12", 244 },
   { "R005_NormalClassDeclaration_13", 245 },
   { "R005_NormalClassDeclaration_14", 246 },
   { "R005_NormalClassDeclaration_15", 247 },
   { "R005_Superclass_0", 248 },
   { "R005_ClassTypeEle_0", 249 },
   { "R005_ClassTypeEle_1", 250 },
   { "R005_ClassTypeEle_2", 251 },
   { "R005_ClassTypeEle_3", 252 },
   { "R005_ClassType_0", 253 },
   { "R005_ClassType_1", 254 },
   { "R005_Superinterfaces_0", 255 },
   { "R005_InterfaceTypeList_0", 256 },
   { "R005_InterfaceTypeList_1", 257 },
   { "R005_EnumDeclaration_0", 258 },
   { "R005_EnumDeclaration_1", 259 },
   { "R005_EnumDeclaration_2", 260 },
   { "R005_EnumDeclaration_3", 261 },
   { "R005_InterfaceDeclaration_0", 262 },
   { "R005_InterfaceDeclaration_1", 263 },
   { "R005_NormalInterfaceDeclaration_0", 264 },
   { "R005_NormalInterfaceDeclaration_1", 265 },
   { "R005_NormalInterfaceDeclaration_2", 266 },
   { "R005_NormalInterfaceDeclaration_3", 267 },
   { "R005_NormalInterfaceDeclaration_4", 268 },
   { "R005_NormalInterfaceDeclaration_5", 269 },
   { "R005_NormalInterfaceDeclaration_6", 270 },
   { "R005_NormalInterfaceDeclaration_7", 271 },
   { "R005_ExtendsInterfaces_0", 272 },
   { "R005_AnnotationTypeDeclaration_0", 273 },
   { "R005_AnnotationTypeDeclaration_1", 274 },
   { "R005_AnnotationTypeDeclaration_2", 275 },
   { "R005_AnnotationTypeDeclaration_3", 276 },
   { "R005_AnnotationList_0", 277 },
   { "R005_AnnotationList_1", 278 },
	};
}

P_SDT_genertor SDT_R005_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R005_ele_begin_0"] = P_SDT_genertor(new R005_ele_begin_0Analyzer()); break;
	case 1: factory["R005_ClassBodyDeclaration_0"] = P_SDT_genertor(new R005_ClassBodyDeclaration_0Analyzer()); break;
	case 2: factory["R005_ClassBodyDeclaration_1"] = P_SDT_genertor(new R005_ClassBodyDeclaration_1Analyzer()); break;
	case 3: factory["R005_ClassBodyDeclaration_2"] = P_SDT_genertor(new R005_ClassBodyDeclaration_2Analyzer()); break;
	case 4: factory["R005_ClassBodyDeclaration_3"] = P_SDT_genertor(new R005_ClassBodyDeclaration_3Analyzer()); break;
	case 5: factory["R005_ClassMemberDeclaration_0"] = P_SDT_genertor(new R005_ClassMemberDeclaration_0Analyzer()); break;
	case 6: factory["R005_ClassMemberDeclaration_1"] = P_SDT_genertor(new R005_ClassMemberDeclaration_1Analyzer()); break;
	case 7: factory["R005_ClassMemberDeclaration_2"] = P_SDT_genertor(new R005_ClassMemberDeclaration_2Analyzer()); break;
	case 8: factory["R005_ClassMemberDeclaration_3"] = P_SDT_genertor(new R005_ClassMemberDeclaration_3Analyzer()); break;
	case 9: factory["R005_ClassMemberDeclaration_4"] = P_SDT_genertor(new R005_ClassMemberDeclaration_4Analyzer()); break;
	case 10: factory["R005_FieldDeclaration_0"] = P_SDT_genertor(new R005_FieldDeclaration_0Analyzer()); break;
	case 11: factory["R005_FieldDeclaration_1"] = P_SDT_genertor(new R005_FieldDeclaration_1Analyzer()); break;
	case 12: factory["R005_FieldDeclarationFake_0"] = P_SDT_genertor(new R005_FieldDeclarationFake_0Analyzer()); break;
	case 13: factory["R005_FieldDeclarationFake_1"] = P_SDT_genertor(new R005_FieldDeclarationFake_1Analyzer()); break;
	case 14: factory["R005_InstanceInitializer_0"] = P_SDT_genertor(new R005_InstanceInitializer_0Analyzer()); break;
	case 15: factory["R005_StaticInitializer_0"] = P_SDT_genertor(new R005_StaticInitializer_0Analyzer()); break;
	case 16: factory["R005_Block_0"] = P_SDT_genertor(new R005_Block_0Analyzer()); break;
	case 17: factory["R005_Block_1"] = P_SDT_genertor(new R005_Block_1Analyzer()); break;
	case 18: factory["R005_BlockStatements_0"] = P_SDT_genertor(new R005_BlockStatements_0Analyzer()); break;
	case 19: factory["R005_BlockStatements_1"] = P_SDT_genertor(new R005_BlockStatements_1Analyzer()); break;
	case 20: factory["R005_BlockStatements_2"] = P_SDT_genertor(new R005_BlockStatements_2Analyzer()); break;
	case 21: factory["R005_NonBrace_0"] = P_SDT_genertor(new R005_NonBrace_0Analyzer()); break;
	case 22: factory["R005_NonBrace_1"] = P_SDT_genertor(new R005_NonBrace_1Analyzer()); break;
	case 23: factory["R005_NonBrace_2"] = P_SDT_genertor(new R005_NonBrace_2Analyzer()); break;
	case 24: factory["R005_NonBrace_3"] = P_SDT_genertor(new R005_NonBrace_3Analyzer()); break;
	case 25: factory["R005_NonBrace_4"] = P_SDT_genertor(new R005_NonBrace_4Analyzer()); break;
	case 26: factory["R005_NonBrace_5"] = P_SDT_genertor(new R005_NonBrace_5Analyzer()); break;
	case 27: factory["R005_NonBrace_6"] = P_SDT_genertor(new R005_NonBrace_6Analyzer()); break;
	case 28: factory["R005_NonBrace_7"] = P_SDT_genertor(new R005_NonBrace_7Analyzer()); break;
	case 29: factory["R005_NonBrace_8"] = P_SDT_genertor(new R005_NonBrace_8Analyzer()); break;
	case 30: factory["R005_NonBrace_9"] = P_SDT_genertor(new R005_NonBrace_9Analyzer()); break;
	case 31: factory["R005_StatementEle_0"] = P_SDT_genertor(new R005_StatementEle_0Analyzer()); break;
	case 32: factory["R005_StatementEle_1"] = P_SDT_genertor(new R005_StatementEle_1Analyzer()); break;
	case 33: factory["R005_StatementEle_2"] = P_SDT_genertor(new R005_StatementEle_2Analyzer()); break;
	case 34: factory["R005_StatementEle_3"] = P_SDT_genertor(new R005_StatementEle_3Analyzer()); break;
	case 35: factory["R005_StatementEle_4"] = P_SDT_genertor(new R005_StatementEle_4Analyzer()); break;
	case 36: factory["R005_StatementEle_5"] = P_SDT_genertor(new R005_StatementEle_5Analyzer()); break;
	case 37: factory["R005_StatementEle_6"] = P_SDT_genertor(new R005_StatementEle_6Analyzer()); break;
	case 38: factory["R005_StatementEle_7"] = P_SDT_genertor(new R005_StatementEle_7Analyzer()); break;
	case 39: factory["R005_StatementEle_8"] = P_SDT_genertor(new R005_StatementEle_8Analyzer()); break;
	case 40: factory["R005_StatementEle_9"] = P_SDT_genertor(new R005_StatementEle_9Analyzer()); break;
	case 41: factory["R005_StatementEle_10"] = P_SDT_genertor(new R005_StatementEle_10Analyzer()); break;
	case 42: factory["R005_StatementEle_11"] = P_SDT_genertor(new R005_StatementEle_11Analyzer()); break;
	case 43: factory["R005_StatementEle_12"] = P_SDT_genertor(new R005_StatementEle_12Analyzer()); break;
	case 44: factory["R005_StatementEle_13"] = P_SDT_genertor(new R005_StatementEle_13Analyzer()); break;
	case 45: factory["R005_StatementEle_14"] = P_SDT_genertor(new R005_StatementEle_14Analyzer()); break;
	case 46: factory["R005_StatementEle_15"] = P_SDT_genertor(new R005_StatementEle_15Analyzer()); break;
	case 47: factory["R005_StatementEle_16"] = P_SDT_genertor(new R005_StatementEle_16Analyzer()); break;
	case 48: factory["R005_StatementEle_17"] = P_SDT_genertor(new R005_StatementEle_17Analyzer()); break;
	case 49: factory["R005_StatementEle_18"] = P_SDT_genertor(new R005_StatementEle_18Analyzer()); break;
	case 50: factory["R005_StatementEle_19"] = P_SDT_genertor(new R005_StatementEle_19Analyzer()); break;
	case 51: factory["R005_StatementEle_20"] = P_SDT_genertor(new R005_StatementEle_20Analyzer()); break;
	case 52: factory["R005_StatementEle_21"] = P_SDT_genertor(new R005_StatementEle_21Analyzer()); break;
	case 53: factory["R005_StatementEle_22"] = P_SDT_genertor(new R005_StatementEle_22Analyzer()); break;
	case 54: factory["R005_StatementEle_23"] = P_SDT_genertor(new R005_StatementEle_23Analyzer()); break;
	case 55: factory["R005_StatementEle_24"] = P_SDT_genertor(new R005_StatementEle_24Analyzer()); break;
	case 56: factory["R005_StatementEle_25"] = P_SDT_genertor(new R005_StatementEle_25Analyzer()); break;
	case 57: factory["R005_StatementEle_26"] = P_SDT_genertor(new R005_StatementEle_26Analyzer()); break;
	case 58: factory["R005_StatementEle_27"] = P_SDT_genertor(new R005_StatementEle_27Analyzer()); break;
	case 59: factory["R005_StatementEle_28"] = P_SDT_genertor(new R005_StatementEle_28Analyzer()); break;
	case 60: factory["R005_StatementEle_29"] = P_SDT_genertor(new R005_StatementEle_29Analyzer()); break;
	case 61: factory["R005_StatementEle_30"] = P_SDT_genertor(new R005_StatementEle_30Analyzer()); break;
	case 62: factory["R005_StatementEle_31"] = P_SDT_genertor(new R005_StatementEle_31Analyzer()); break;
	case 63: factory["R005_StatementEle_32"] = P_SDT_genertor(new R005_StatementEle_32Analyzer()); break;
	case 64: factory["R005_StatementEle_33"] = P_SDT_genertor(new R005_StatementEle_33Analyzer()); break;
	case 65: factory["R005_StatementEle_34"] = P_SDT_genertor(new R005_StatementEle_34Analyzer()); break;
	case 66: factory["R005_StatementEle_35"] = P_SDT_genertor(new R005_StatementEle_35Analyzer()); break;
	case 67: factory["R005_StatementEle_36"] = P_SDT_genertor(new R005_StatementEle_36Analyzer()); break;
	case 68: factory["R005_StatementEle_37"] = P_SDT_genertor(new R005_StatementEle_37Analyzer()); break;
	case 69: factory["R005_StatementEle_38"] = P_SDT_genertor(new R005_StatementEle_38Analyzer()); break;
	case 70: factory["R005_StatementEle_39"] = P_SDT_genertor(new R005_StatementEle_39Analyzer()); break;
	case 71: factory["R005_StatementEle_40"] = P_SDT_genertor(new R005_StatementEle_40Analyzer()); break;
	case 72: factory["R005_StatementEle_41"] = P_SDT_genertor(new R005_StatementEle_41Analyzer()); break;
	case 73: factory["R005_StatementEle_42"] = P_SDT_genertor(new R005_StatementEle_42Analyzer()); break;
	case 74: factory["R005_StatementEle_43"] = P_SDT_genertor(new R005_StatementEle_43Analyzer()); break;
	case 75: factory["R005_StatementEle_44"] = P_SDT_genertor(new R005_StatementEle_44Analyzer()); break;
	case 76: factory["R005_StatementEle_45"] = P_SDT_genertor(new R005_StatementEle_45Analyzer()); break;
	case 77: factory["R005_StatementEle_46"] = P_SDT_genertor(new R005_StatementEle_46Analyzer()); break;
	case 78: factory["R005_StatementEle_47"] = P_SDT_genertor(new R005_StatementEle_47Analyzer()); break;
	case 79: factory["R005_StatementEle_48"] = P_SDT_genertor(new R005_StatementEle_48Analyzer()); break;
	case 80: factory["R005_StatementEle_49"] = P_SDT_genertor(new R005_StatementEle_49Analyzer()); break;
	case 81: factory["R005_StatementEle_50"] = P_SDT_genertor(new R005_StatementEle_50Analyzer()); break;
	case 82: factory["R005_StatementEle_51"] = P_SDT_genertor(new R005_StatementEle_51Analyzer()); break;
	case 83: factory["R005_StatementEle_52"] = P_SDT_genertor(new R005_StatementEle_52Analyzer()); break;
	case 84: factory["R005_StatementEle_53"] = P_SDT_genertor(new R005_StatementEle_53Analyzer()); break;
	case 85: factory["R005_StatementEle_54"] = P_SDT_genertor(new R005_StatementEle_54Analyzer()); break;
	case 86: factory["R005_StatementEle_55"] = P_SDT_genertor(new R005_StatementEle_55Analyzer()); break;
	case 87: factory["R005_StatementEle_56"] = P_SDT_genertor(new R005_StatementEle_56Analyzer()); break;
	case 88: factory["R005_StatementEle_57"] = P_SDT_genertor(new R005_StatementEle_57Analyzer()); break;
	case 89: factory["R005_StatementEle_58"] = P_SDT_genertor(new R005_StatementEle_58Analyzer()); break;
	case 90: factory["R005_StatementEle_59"] = P_SDT_genertor(new R005_StatementEle_59Analyzer()); break;
	case 91: factory["R005_StatementEle_60"] = P_SDT_genertor(new R005_StatementEle_60Analyzer()); break;
	case 92: factory["R005_StatementEle_61"] = P_SDT_genertor(new R005_StatementEle_61Analyzer()); break;
	case 93: factory["R005_StatementEle_62"] = P_SDT_genertor(new R005_StatementEle_62Analyzer()); break;
	case 94: factory["R005_StatementEle_63"] = P_SDT_genertor(new R005_StatementEle_63Analyzer()); break;
	case 95: factory["R005_StatementEle_64"] = P_SDT_genertor(new R005_StatementEle_64Analyzer()); break;
	case 96: factory["R005_StatementEle_65"] = P_SDT_genertor(new R005_StatementEle_65Analyzer()); break;
	case 97: factory["R005_StatementEle_66"] = P_SDT_genertor(new R005_StatementEle_66Analyzer()); break;
	case 98: factory["R005_StatementEle_67"] = P_SDT_genertor(new R005_StatementEle_67Analyzer()); break;
	case 99: factory["R005_StatementEle_68"] = P_SDT_genertor(new R005_StatementEle_68Analyzer()); break;
	case 100: factory["R005_StatementEle_69"] = P_SDT_genertor(new R005_StatementEle_69Analyzer()); break;
	case 101: factory["R005_StatementEle_70"] = P_SDT_genertor(new R005_StatementEle_70Analyzer()); break;
	case 102: factory["R005_StatementEle_71"] = P_SDT_genertor(new R005_StatementEle_71Analyzer()); break;
	case 103: factory["R005_StatementEle_72"] = P_SDT_genertor(new R005_StatementEle_72Analyzer()); break;
	case 104: factory["R005_StatementEle_73"] = P_SDT_genertor(new R005_StatementEle_73Analyzer()); break;
	case 105: factory["R005_StatementEle_74"] = P_SDT_genertor(new R005_StatementEle_74Analyzer()); break;
	case 106: factory["R005_StatementEle_75"] = P_SDT_genertor(new R005_StatementEle_75Analyzer()); break;
	case 107: factory["R005_StatementEle_76"] = P_SDT_genertor(new R005_StatementEle_76Analyzer()); break;
	case 108: factory["R005_StatementEle_77"] = P_SDT_genertor(new R005_StatementEle_77Analyzer()); break;
	case 109: factory["R005_StatementEle_78"] = P_SDT_genertor(new R005_StatementEle_78Analyzer()); break;
	case 110: factory["R005_StatementEle_79"] = P_SDT_genertor(new R005_StatementEle_79Analyzer()); break;
	case 111: factory["R005_Identifier_0"] = P_SDT_genertor(new R005_Identifier_0Analyzer()); break;
	case 112: factory["R005_ModifierList_0"] = P_SDT_genertor(new R005_ModifierList_0Analyzer()); break;
	case 113: factory["R005_ModifierList_1"] = P_SDT_genertor(new R005_ModifierList_1Analyzer()); break;
	case 114: factory["R005_Modifier_0"] = P_SDT_genertor(new R005_Modifier_0Analyzer()); break;
	case 115: factory["R005_Modifier_1"] = P_SDT_genertor(new R005_Modifier_1Analyzer()); break;
	case 116: factory["R005_Modifier_2"] = P_SDT_genertor(new R005_Modifier_2Analyzer()); break;
	case 117: factory["R005_Modifier_3"] = P_SDT_genertor(new R005_Modifier_3Analyzer()); break;
	case 118: factory["R005_Modifier_4"] = P_SDT_genertor(new R005_Modifier_4Analyzer()); break;
	case 119: factory["R005_Modifier_5"] = P_SDT_genertor(new R005_Modifier_5Analyzer()); break;
	case 120: factory["R005_Modifier_6"] = P_SDT_genertor(new R005_Modifier_6Analyzer()); break;
	case 121: factory["R005_Modifier_7"] = P_SDT_genertor(new R005_Modifier_7Analyzer()); break;
	case 122: factory["R005_Modifier_8"] = P_SDT_genertor(new R005_Modifier_8Analyzer()); break;
	case 123: factory["R005_Modifier_9"] = P_SDT_genertor(new R005_Modifier_9Analyzer()); break;
	case 124: factory["R005_Modifier_10"] = P_SDT_genertor(new R005_Modifier_10Analyzer()); break;
	case 125: factory["R005_Modifier_11"] = P_SDT_genertor(new R005_Modifier_11Analyzer()); break;
	case 126: factory["R005_Modifier_12"] = P_SDT_genertor(new R005_Modifier_12Analyzer()); break;
	case 127: factory["R005_Annotation_0"] = P_SDT_genertor(new R005_Annotation_0Analyzer()); break;
	case 128: factory["R005_Annotation_1"] = P_SDT_genertor(new R005_Annotation_1Analyzer()); break;
	case 129: factory["R005_DetailIdentifier_0"] = P_SDT_genertor(new R005_DetailIdentifier_0Analyzer()); break;
	case 130: factory["R005_DetailIdentifier_1"] = P_SDT_genertor(new R005_DetailIdentifier_1Analyzer()); break;
	case 131: factory["R005_AnnotationContent_0"] = P_SDT_genertor(new R005_AnnotationContent_0Analyzer()); break;
	case 132: factory["R005_AnnotationContentStatements_0"] = P_SDT_genertor(new R005_AnnotationContentStatements_0Analyzer()); break;
	case 133: factory["R005_AnnotationContentStatements_1"] = P_SDT_genertor(new R005_AnnotationContentStatements_1Analyzer()); break;
	case 134: factory["R005_NonPARENTHESES_0"] = P_SDT_genertor(new R005_NonPARENTHESES_0Analyzer()); break;
	case 135: factory["R005_NonPARENTHESES_1"] = P_SDT_genertor(new R005_NonPARENTHESES_1Analyzer()); break;
	case 136: factory["R005_NonPARENTHESES_2"] = P_SDT_genertor(new R005_NonPARENTHESES_2Analyzer()); break;
	case 137: factory["R005_NonPARENTHESES_3"] = P_SDT_genertor(new R005_NonPARENTHESES_3Analyzer()); break;
	case 138: factory["R005_NonPARENTHESES_4"] = P_SDT_genertor(new R005_NonPARENTHESES_4Analyzer()); break;
	case 139: factory["R005_NonPARENTHESES_5"] = P_SDT_genertor(new R005_NonPARENTHESES_5Analyzer()); break;
	case 140: factory["R005_NonPARENTHESES_6"] = P_SDT_genertor(new R005_NonPARENTHESES_6Analyzer()); break;
	case 141: factory["R005_NonPARENTHESES_7"] = P_SDT_genertor(new R005_NonPARENTHESES_7Analyzer()); break;
	case 142: factory["R005_NonPARENTHESES_8"] = P_SDT_genertor(new R005_NonPARENTHESES_8Analyzer()); break;
	case 143: factory["R005_NonPARENTHESES_9"] = P_SDT_genertor(new R005_NonPARENTHESES_9Analyzer()); break;
	case 144: factory["R005_NonPARENTHESES_10"] = P_SDT_genertor(new R005_NonPARENTHESES_10Analyzer()); break;
	case 145: factory["R005_TypeArguments_0"] = P_SDT_genertor(new R005_TypeArguments_0Analyzer()); break;
	case 146: factory["R005_TypeArgumentList_0"] = P_SDT_genertor(new R005_TypeArgumentList_0Analyzer()); break;
	case 147: factory["R005_TypeArgumentList_1"] = P_SDT_genertor(new R005_TypeArgumentList_1Analyzer()); break;
	case 148: factory["R005_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_0Analyzer()); break;
	case 149: factory["R005_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_1Analyzer()); break;
	case 150: factory["R005_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_2Analyzer()); break;
	case 151: factory["R005_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_3Analyzer()); break;
	case 152: factory["R005_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_4Analyzer()); break;
	case 153: factory["R005_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_5Analyzer()); break;
	case 154: factory["R005_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_6Analyzer()); break;
	case 155: factory["R005_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_7Analyzer()); break;
	case 156: factory["R005_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_8Analyzer()); break;
	case 157: factory["R005_NonANGLE_BRACKET_9"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_9Analyzer()); break;
	case 158: factory["R005_Dims_0"] = P_SDT_genertor(new R005_Dims_0Analyzer()); break;
	case 159: factory["R005_Dims_1"] = P_SDT_genertor(new R005_Dims_1Analyzer()); break;
	case 160: factory["R005_Dims_2"] = P_SDT_genertor(new R005_Dims_2Analyzer()); break;
	case 161: factory["R005_Dims_3"] = P_SDT_genertor(new R005_Dims_3Analyzer()); break;
	case 162: factory["R005_UnannType_0"] = P_SDT_genertor(new R005_UnannType_0Analyzer()); break;
	case 163: factory["R005_UnannType_1"] = P_SDT_genertor(new R005_UnannType_1Analyzer()); break;
	case 164: factory["R005_UnannType_2"] = P_SDT_genertor(new R005_UnannType_2Analyzer()); break;
	case 165: factory["R005_UnannPrimitiveType_0"] = P_SDT_genertor(new R005_UnannPrimitiveType_0Analyzer()); break;
	case 166: factory["R005_UnannPrimitiveType_1"] = P_SDT_genertor(new R005_UnannPrimitiveType_1Analyzer()); break;
	case 167: factory["R005_UnannPrimitiveType_2"] = P_SDT_genertor(new R005_UnannPrimitiveType_2Analyzer()); break;
	case 168: factory["R005_UnannPrimitiveType_3"] = P_SDT_genertor(new R005_UnannPrimitiveType_3Analyzer()); break;
	case 169: factory["R005_UnannPrimitiveType_4"] = P_SDT_genertor(new R005_UnannPrimitiveType_4Analyzer()); break;
	case 170: factory["R005_UnannPrimitiveType_5"] = P_SDT_genertor(new R005_UnannPrimitiveType_5Analyzer()); break;
	case 171: factory["R005_UnannPrimitiveType_6"] = P_SDT_genertor(new R005_UnannPrimitiveType_6Analyzer()); break;
	case 172: factory["R005_UnannPrimitiveType_7"] = P_SDT_genertor(new R005_UnannPrimitiveType_7Analyzer()); break;
	case 173: factory["R005_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_0Analyzer()); break;
	case 174: factory["R005_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_1Analyzer()); break;
	case 175: factory["R005_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_2Analyzer()); break;
	case 176: factory["R005_UnannClassOrInterfaceType_3"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_3Analyzer()); break;
	case 177: factory["R005_UnannClassOrInterfaceType_4"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_4Analyzer()); break;
	case 178: factory["R005_UnannClassOrInterfaceType_5"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_5Analyzer()); break;
	case 179: factory["R005_UnannArrayType_0"] = P_SDT_genertor(new R005_UnannArrayType_0Analyzer()); break;
	case 180: factory["R005_UnannArrayType_1"] = P_SDT_genertor(new R005_UnannArrayType_1Analyzer()); break;
	case 181: factory["R005_VariableDeclaratorList_0"] = P_SDT_genertor(new R005_VariableDeclaratorList_0Analyzer()); break;
	case 182: factory["R005_VariableDeclaratorList_1"] = P_SDT_genertor(new R005_VariableDeclaratorList_1Analyzer()); break;
	case 183: factory["R005_VariableDeclarator_0"] = P_SDT_genertor(new R005_VariableDeclarator_0Analyzer()); break;
	case 184: factory["R005_VariableDeclarator_1"] = P_SDT_genertor(new R005_VariableDeclarator_1Analyzer()); break;
	case 185: factory["R005_VariableInitializer_0"] = P_SDT_genertor(new R005_VariableInitializer_0Analyzer()); break;
	case 186: factory["R005_VariableInitializer_1"] = P_SDT_genertor(new R005_VariableInitializer_1Analyzer()); break;
	case 187: factory["R005_VariableInitializerEle_0"] = P_SDT_genertor(new R005_VariableInitializerEle_0Analyzer()); break;
	case 188: factory["R005_VariableInitializerEle_1"] = P_SDT_genertor(new R005_VariableInitializerEle_1Analyzer()); break;
	case 189: factory["R005_VariableInitializerEle_2"] = P_SDT_genertor(new R005_VariableInitializerEle_2Analyzer()); break;
	case 190: factory["R005_VariableInitializerEle_3"] = P_SDT_genertor(new R005_VariableInitializerEle_3Analyzer()); break;
	case 191: factory["R005_VariableDeclaratorId_0"] = P_SDT_genertor(new R005_VariableDeclaratorId_0Analyzer()); break;
	case 192: factory["R005_VariableDeclaratorId_1"] = P_SDT_genertor(new R005_VariableDeclaratorId_1Analyzer()); break;
	case 193: factory["R005_MethodDeclaration_0"] = P_SDT_genertor(new R005_MethodDeclaration_0Analyzer()); break;
	case 194: factory["R005_MethodDeclaration_1"] = P_SDT_genertor(new R005_MethodDeclaration_1Analyzer()); break;
	case 195: factory["R005_MethodDeclaration_2"] = P_SDT_genertor(new R005_MethodDeclaration_2Analyzer()); break;
	case 196: factory["R005_MethodDeclaration_3"] = P_SDT_genertor(new R005_MethodDeclaration_3Analyzer()); break;
	case 197: factory["R005_MethodDeclaration_4"] = P_SDT_genertor(new R005_MethodDeclaration_4Analyzer()); break;
	case 198: factory["R005_MethodDeclaration_5"] = P_SDT_genertor(new R005_MethodDeclaration_5Analyzer()); break;
	case 199: factory["R005_MethodDeclaration_6"] = P_SDT_genertor(new R005_MethodDeclaration_6Analyzer()); break;
	case 200: factory["R005_MethodDeclaration_7"] = P_SDT_genertor(new R005_MethodDeclaration_7Analyzer()); break;
	case 201: factory["R005_MethodDeclaration_8"] = P_SDT_genertor(new R005_MethodDeclaration_8Analyzer()); break;
	case 202: factory["R005_MethodDeclaration_9"] = P_SDT_genertor(new R005_MethodDeclaration_9Analyzer()); break;
	case 203: factory["R005_MethodDeclaration_10"] = P_SDT_genertor(new R005_MethodDeclaration_10Analyzer()); break;
	case 204: factory["R005_MethodDeclaration_11"] = P_SDT_genertor(new R005_MethodDeclaration_11Analyzer()); break;
	case 205: factory["R005_MethodDeclaration_12"] = P_SDT_genertor(new R005_MethodDeclaration_12Analyzer()); break;
	case 206: factory["R005_MethodDeclaration_13"] = P_SDT_genertor(new R005_MethodDeclaration_13Analyzer()); break;
	case 207: factory["R005_MethodDeclaration_14"] = P_SDT_genertor(new R005_MethodDeclaration_14Analyzer()); break;
	case 208: factory["R005_MethodDeclaration_15"] = P_SDT_genertor(new R005_MethodDeclaration_15Analyzer()); break;
	case 209: factory["R005_MethodDeclaration_16"] = P_SDT_genertor(new R005_MethodDeclaration_16Analyzer()); break;
	case 210: factory["R005_MethodDeclaration_17"] = P_SDT_genertor(new R005_MethodDeclaration_17Analyzer()); break;
	case 211: factory["R005_MethodDeclaration_18"] = P_SDT_genertor(new R005_MethodDeclaration_18Analyzer()); break;
	case 212: factory["R005_MethodDeclaration_19"] = P_SDT_genertor(new R005_MethodDeclaration_19Analyzer()); break;
	case 213: factory["R005_MethodHeader_0"] = P_SDT_genertor(new R005_MethodHeader_0Analyzer()); break;
	case 214: factory["R005_MethodHeader_1"] = P_SDT_genertor(new R005_MethodHeader_1Analyzer()); break;
	case 215: factory["R005_Result_0"] = P_SDT_genertor(new R005_Result_0Analyzer()); break;
	case 216: factory["R005_Result_1"] = P_SDT_genertor(new R005_Result_1Analyzer()); break;
	case 217: factory["R005_MethodDeclarator_0"] = P_SDT_genertor(new R005_MethodDeclarator_0Analyzer()); break;
	case 218: factory["R005_MethodDeclarator_1"] = P_SDT_genertor(new R005_MethodDeclarator_1Analyzer()); break;
	case 219: factory["R005_Throws_0"] = P_SDT_genertor(new R005_Throws_0Analyzer()); break;
	case 220: factory["R005_ExceptionTypeList_0"] = P_SDT_genertor(new R005_ExceptionTypeList_0Analyzer()); break;
	case 221: factory["R005_ExceptionTypeList_1"] = P_SDT_genertor(new R005_ExceptionTypeList_1Analyzer()); break;
	case 222: factory["R005_ExceptionType_0"] = P_SDT_genertor(new R005_ExceptionType_0Analyzer()); break;
	case 223: factory["R005_ExceptionType_1"] = P_SDT_genertor(new R005_ExceptionType_1Analyzer()); break;
	case 224: factory["R005_ConstructorDeclaration_0"] = P_SDT_genertor(new R005_ConstructorDeclaration_0Analyzer()); break;
	case 225: factory["R005_ConstructorDeclaration_1"] = P_SDT_genertor(new R005_ConstructorDeclaration_1Analyzer()); break;
	case 226: factory["R005_ConstructorDeclaration_2"] = P_SDT_genertor(new R005_ConstructorDeclaration_2Analyzer()); break;
	case 227: factory["R005_ConstructorDeclaration_3"] = P_SDT_genertor(new R005_ConstructorDeclaration_3Analyzer()); break;
	case 228: factory["R005_ConstructorDeclarator_0"] = P_SDT_genertor(new R005_ConstructorDeclarator_0Analyzer()); break;
	case 229: factory["R005_ConstructorDeclarator_1"] = P_SDT_genertor(new R005_ConstructorDeclarator_1Analyzer()); break;
	case 230: factory["R005_ClassDeclaration_0"] = P_SDT_genertor(new R005_ClassDeclaration_0Analyzer()); break;
	case 231: factory["R005_ClassDeclaration_1"] = P_SDT_genertor(new R005_ClassDeclaration_1Analyzer()); break;
	case 232: factory["R005_NormalClassDeclaration_0"] = P_SDT_genertor(new R005_NormalClassDeclaration_0Analyzer()); break;
	case 233: factory["R005_NormalClassDeclaration_1"] = P_SDT_genertor(new R005_NormalClassDeclaration_1Analyzer()); break;
	case 234: factory["R005_NormalClassDeclaration_2"] = P_SDT_genertor(new R005_NormalClassDeclaration_2Analyzer()); break;
	case 235: factory["R005_NormalClassDeclaration_3"] = P_SDT_genertor(new R005_NormalClassDeclaration_3Analyzer()); break;
	case 236: factory["R005_NormalClassDeclaration_4"] = P_SDT_genertor(new R005_NormalClassDeclaration_4Analyzer()); break;
	case 237: factory["R005_NormalClassDeclaration_5"] = P_SDT_genertor(new R005_NormalClassDeclaration_5Analyzer()); break;
	case 238: factory["R005_NormalClassDeclaration_6"] = P_SDT_genertor(new R005_NormalClassDeclaration_6Analyzer()); break;
	case 239: factory["R005_NormalClassDeclaration_7"] = P_SDT_genertor(new R005_NormalClassDeclaration_7Analyzer()); break;
	case 240: factory["R005_NormalClassDeclaration_8"] = P_SDT_genertor(new R005_NormalClassDeclaration_8Analyzer()); break;
	case 241: factory["R005_NormalClassDeclaration_9"] = P_SDT_genertor(new R005_NormalClassDeclaration_9Analyzer()); break;
	case 242: factory["R005_NormalClassDeclaration_10"] = P_SDT_genertor(new R005_NormalClassDeclaration_10Analyzer()); break;
	case 243: factory["R005_NormalClassDeclaration_11"] = P_SDT_genertor(new R005_NormalClassDeclaration_11Analyzer()); break;
	case 244: factory["R005_NormalClassDeclaration_12"] = P_SDT_genertor(new R005_NormalClassDeclaration_12Analyzer()); break;
	case 245: factory["R005_NormalClassDeclaration_13"] = P_SDT_genertor(new R005_NormalClassDeclaration_13Analyzer()); break;
	case 246: factory["R005_NormalClassDeclaration_14"] = P_SDT_genertor(new R005_NormalClassDeclaration_14Analyzer()); break;
	case 247: factory["R005_NormalClassDeclaration_15"] = P_SDT_genertor(new R005_NormalClassDeclaration_15Analyzer()); break;
	case 248: factory["R005_Superclass_0"] = P_SDT_genertor(new R005_Superclass_0Analyzer()); break;
	case 249: factory["R005_ClassTypeEle_0"] = P_SDT_genertor(new R005_ClassTypeEle_0Analyzer()); break;
	case 250: factory["R005_ClassTypeEle_1"] = P_SDT_genertor(new R005_ClassTypeEle_1Analyzer()); break;
	case 251: factory["R005_ClassTypeEle_2"] = P_SDT_genertor(new R005_ClassTypeEle_2Analyzer()); break;
	case 252: factory["R005_ClassTypeEle_3"] = P_SDT_genertor(new R005_ClassTypeEle_3Analyzer()); break;
	case 253: factory["R005_ClassType_0"] = P_SDT_genertor(new R005_ClassType_0Analyzer()); break;
	case 254: factory["R005_ClassType_1"] = P_SDT_genertor(new R005_ClassType_1Analyzer()); break;
	case 255: factory["R005_Superinterfaces_0"] = P_SDT_genertor(new R005_Superinterfaces_0Analyzer()); break;
	case 256: factory["R005_InterfaceTypeList_0"] = P_SDT_genertor(new R005_InterfaceTypeList_0Analyzer()); break;
	case 257: factory["R005_InterfaceTypeList_1"] = P_SDT_genertor(new R005_InterfaceTypeList_1Analyzer()); break;
	case 258: factory["R005_EnumDeclaration_0"] = P_SDT_genertor(new R005_EnumDeclaration_0Analyzer()); break;
	case 259: factory["R005_EnumDeclaration_1"] = P_SDT_genertor(new R005_EnumDeclaration_1Analyzer()); break;
	case 260: factory["R005_EnumDeclaration_2"] = P_SDT_genertor(new R005_EnumDeclaration_2Analyzer()); break;
	case 261: factory["R005_EnumDeclaration_3"] = P_SDT_genertor(new R005_EnumDeclaration_3Analyzer()); break;
	case 262: factory["R005_InterfaceDeclaration_0"] = P_SDT_genertor(new R005_InterfaceDeclaration_0Analyzer()); break;
	case 263: factory["R005_InterfaceDeclaration_1"] = P_SDT_genertor(new R005_InterfaceDeclaration_1Analyzer()); break;
	case 264: factory["R005_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_0Analyzer()); break;
	case 265: factory["R005_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_1Analyzer()); break;
	case 266: factory["R005_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_2Analyzer()); break;
	case 267: factory["R005_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_3Analyzer()); break;
	case 268: factory["R005_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_4Analyzer()); break;
	case 269: factory["R005_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_5Analyzer()); break;
	case 270: factory["R005_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_6Analyzer()); break;
	case 271: factory["R005_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_7Analyzer()); break;
	case 272: factory["R005_ExtendsInterfaces_0"] = P_SDT_genertor(new R005_ExtendsInterfaces_0Analyzer()); break;
	case 273: factory["R005_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_0Analyzer()); break;
	case 274: factory["R005_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_1Analyzer()); break;
	case 275: factory["R005_AnnotationTypeDeclaration_2"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_2Analyzer()); break;
	case 276: factory["R005_AnnotationTypeDeclaration_3"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_3Analyzer()); break;
	case 277: factory["R005_AnnotationList_0"] = P_SDT_genertor(new R005_AnnotationList_0Analyzer()); break;
	case 278: factory["R005_AnnotationList_1"] = P_SDT_genertor(new R005_AnnotationList_1Analyzer()); break;
	default:

		if (key.find("R005_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R005_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R005_Factory::~SDT_R005_Factory() {}
