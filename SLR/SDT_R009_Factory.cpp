#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R009_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R009Analyzer.h"
using namespace std;
using namespace boost;



SDT_R009_Factory SDT_R009_Factory::instance;
SDT_R009_Factory::SDT_R009_Factory() {
	control_Param = {
   { "R009_ele_begin_0", 0 },
   { "R009_AnnotationTypeMemberDeclaration_0", 1 },
   { "R009_AnnotationTypeMemberDeclaration_1", 2 },
   { "R009_AnnotationTypeMemberDeclaration_2", 3 },
   { "R009_AnnotationTypeMemberDeclaration_3", 4 },
   { "R009_AnnotationTypeMemberDeclaration_4", 5 },
   { "R009_InterfaceDeclaration_0", 6 },
   { "R009_InterfaceDeclaration_1", 7 },
   { "R009_ClassDeclaration_0", 8 },
   { "R009_ClassDeclaration_1", 9 },
   { "R009_EnumDeclaration_0", 10 },
   { "R009_EnumDeclaration_1", 11 },
   { "R009_EnumDeclaration_2", 12 },
   { "R009_EnumDeclaration_3", 13 },
   { "R009_NormalClassDeclaration_0", 14 },
   { "R009_NormalClassDeclaration_1", 15 },
   { "R009_NormalClassDeclaration_2", 16 },
   { "R009_NormalClassDeclaration_3", 17 },
   { "R009_NormalClassDeclaration_4", 18 },
   { "R009_NormalClassDeclaration_5", 19 },
   { "R009_NormalClassDeclaration_6", 20 },
   { "R009_NormalClassDeclaration_7", 21 },
   { "R009_NormalClassDeclaration_8", 22 },
   { "R009_NormalClassDeclaration_9", 23 },
   { "R009_NormalClassDeclaration_10", 24 },
   { "R009_NormalClassDeclaration_11", 25 },
   { "R009_NormalClassDeclaration_12", 26 },
   { "R009_NormalClassDeclaration_13", 27 },
   { "R009_NormalClassDeclaration_14", 28 },
   { "R009_NormalClassDeclaration_15", 29 },
   { "R009_Superclass_0", 30 },
   { "R009_Superinterfaces_0", 31 },
   { "R009_NormalInterfaceDeclaration_0", 32 },
   { "R009_NormalInterfaceDeclaration_1", 33 },
   { "R009_NormalInterfaceDeclaration_2", 34 },
   { "R009_NormalInterfaceDeclaration_3", 35 },
   { "R009_NormalInterfaceDeclaration_4", 36 },
   { "R009_NormalInterfaceDeclaration_5", 37 },
   { "R009_NormalInterfaceDeclaration_6", 38 },
   { "R009_NormalInterfaceDeclaration_7", 39 },
   { "R009_AnnotationTypeDeclaration_0", 40 },
   { "R009_AnnotationTypeDeclaration_1", 41 },
   { "R009_Identifier_0", 42 },
   { "R009_Block_0", 43 },
   { "R009_Block_1", 44 },
   { "R009_BlockStatements_0", 45 },
   { "R009_BlockStatements_1", 46 },
   { "R009_BlockStatements_2", 47 },
   { "R009_NonBrace_0", 48 },
   { "R009_NonBrace_1", 49 },
   { "R009_NonBrace_2", 50 },
   { "R009_NonBrace_3", 51 },
   { "R009_NonBrace_4", 52 },
   { "R009_NonBrace_5", 53 },
   { "R009_NonBrace_6", 54 },
   { "R009_NonBrace_7", 55 },
   { "R009_NonBrace_8", 56 },
   { "R009_NonBrace_9", 57 },
   { "R009_StatementEle_0", 58 },
   { "R009_StatementEle_1", 59 },
   { "R009_StatementEle_2", 60 },
   { "R009_StatementEle_3", 61 },
   { "R009_StatementEle_4", 62 },
   { "R009_StatementEle_5", 63 },
   { "R009_StatementEle_6", 64 },
   { "R009_StatementEle_7", 65 },
   { "R009_StatementEle_8", 66 },
   { "R009_StatementEle_9", 67 },
   { "R009_StatementEle_10", 68 },
   { "R009_StatementEle_11", 69 },
   { "R009_StatementEle_12", 70 },
   { "R009_StatementEle_13", 71 },
   { "R009_StatementEle_14", 72 },
   { "R009_StatementEle_15", 73 },
   { "R009_StatementEle_16", 74 },
   { "R009_StatementEle_17", 75 },
   { "R009_StatementEle_18", 76 },
   { "R009_StatementEle_19", 77 },
   { "R009_StatementEle_20", 78 },
   { "R009_StatementEle_21", 79 },
   { "R009_StatementEle_22", 80 },
   { "R009_StatementEle_23", 81 },
   { "R009_StatementEle_24", 82 },
   { "R009_StatementEle_25", 83 },
   { "R009_StatementEle_26", 84 },
   { "R009_StatementEle_27", 85 },
   { "R009_StatementEle_28", 86 },
   { "R009_StatementEle_29", 87 },
   { "R009_StatementEle_30", 88 },
   { "R009_StatementEle_31", 89 },
   { "R009_StatementEle_32", 90 },
   { "R009_StatementEle_33", 91 },
   { "R009_StatementEle_34", 92 },
   { "R009_StatementEle_35", 93 },
   { "R009_StatementEle_36", 94 },
   { "R009_StatementEle_37", 95 },
   { "R009_StatementEle_38", 96 },
   { "R009_StatementEle_39", 97 },
   { "R009_StatementEle_40", 98 },
   { "R009_StatementEle_41", 99 },
   { "R009_StatementEle_42", 100 },
   { "R009_StatementEle_43", 101 },
   { "R009_StatementEle_44", 102 },
   { "R009_StatementEle_45", 103 },
   { "R009_StatementEle_46", 104 },
   { "R009_StatementEle_47", 105 },
   { "R009_StatementEle_48", 106 },
   { "R009_StatementEle_49", 107 },
   { "R009_StatementEle_50", 108 },
   { "R009_StatementEle_51", 109 },
   { "R009_StatementEle_52", 110 },
   { "R009_StatementEle_53", 111 },
   { "R009_StatementEle_54", 112 },
   { "R009_StatementEle_55", 113 },
   { "R009_StatementEle_56", 114 },
   { "R009_StatementEle_57", 115 },
   { "R009_StatementEle_58", 116 },
   { "R009_StatementEle_59", 117 },
   { "R009_StatementEle_60", 118 },
   { "R009_StatementEle_61", 119 },
   { "R009_StatementEle_62", 120 },
   { "R009_StatementEle_63", 121 },
   { "R009_StatementEle_64", 122 },
   { "R009_StatementEle_65", 123 },
   { "R009_StatementEle_66", 124 },
   { "R009_StatementEle_67", 125 },
   { "R009_StatementEle_68", 126 },
   { "R009_StatementEle_69", 127 },
   { "R009_StatementEle_70", 128 },
   { "R009_StatementEle_71", 129 },
   { "R009_StatementEle_72", 130 },
   { "R009_StatementEle_73", 131 },
   { "R009_StatementEle_74", 132 },
   { "R009_StatementEle_75", 133 },
   { "R009_StatementEle_76", 134 },
   { "R009_StatementEle_77", 135 },
   { "R009_StatementEle_78", 136 },
   { "R009_StatementEle_79", 137 },
   { "R009_ModifierList_0", 138 },
   { "R009_ModifierList_1", 139 },
   { "R009_Modifier_0", 140 },
   { "R009_Modifier_1", 141 },
   { "R009_Modifier_2", 142 },
   { "R009_Modifier_3", 143 },
   { "R009_Modifier_4", 144 },
   { "R009_Modifier_5", 145 },
   { "R009_Modifier_6", 146 },
   { "R009_Modifier_7", 147 },
   { "R009_Modifier_8", 148 },
   { "R009_Modifier_9", 149 },
   { "R009_Modifier_10", 150 },
   { "R009_Modifier_11", 151 },
   { "R009_Modifier_12", 152 },
   { "R009_Annotation_0", 153 },
   { "R009_Annotation_1", 154 },
   { "R009_DetailIdentifier_0", 155 },
   { "R009_DetailIdentifier_1", 156 },
   { "R009_AnnotationContent_0", 157 },
   { "R009_AnnotationContentStatements_0", 158 },
   { "R009_AnnotationContentStatements_1", 159 },
   { "R009_NonPARENTHESES_0", 160 },
   { "R009_NonPARENTHESES_1", 161 },
   { "R009_NonPARENTHESES_2", 162 },
   { "R009_NonPARENTHESES_3", 163 },
   { "R009_NonPARENTHESES_4", 164 },
   { "R009_NonPARENTHESES_5", 165 },
   { "R009_NonPARENTHESES_6", 166 },
   { "R009_NonPARENTHESES_7", 167 },
   { "R009_NonPARENTHESES_8", 168 },
   { "R009_NonPARENTHESES_9", 169 },
   { "R009_NonPARENTHESES_10", 170 },
   { "R009_NonPARENTHESES_11", 171 },
   { "R009_TypeArguments_0", 172 },
   { "R009_TypeArguments_1", 173 },
   { "R009_TypeArguments_2", 174 },
   { "R009_TypeArguments_3", 175 },
   { "R009_TypeArgumentListL2_0", 176 },
   { "R009_TypeArgumentListL2_1", 177 },
   { "R009_TypeArgumentListL2_2", 178 },
   { "R009_TypeArgumentListL1_0", 179 },
   { "R009_TypeArgumentListL1_1", 180 },
   { "R009_TypeArgumentListL1_2", 181 },
   { "R009_TypeArgumentList_0", 182 },
   { "R009_TypeArgumentList_1", 183 },
   { "R009_NonANGLE_BRACKET_0", 184 },
   { "R009_NonANGLE_BRACKET_1", 185 },
   { "R009_NonANGLE_BRACKET_2", 186 },
   { "R009_NonANGLE_BRACKET_3", 187 },
   { "R009_NonANGLE_BRACKET_4", 188 },
   { "R009_NonANGLE_BRACKET_5", 189 },
   { "R009_NonANGLE_BRACKET_6", 190 },
   { "R009_NonANGLE_BRACKET_7", 191 },
   { "R009_NonANGLE_BRACKET_8", 192 },
   { "R009_NonANGLE_BRACKET_9", 193 },
   { "R009_ExtendsInterfaces_0", 194 },
   { "R009_InterfaceTypeList_0", 195 },
   { "R009_InterfaceTypeList_1", 196 },
   { "R009_ClassTypeEle_0", 197 },
   { "R009_ClassTypeEle_1", 198 },
   { "R009_ClassTypeEle_2", 199 },
   { "R009_ClassTypeEle_3", 200 },
   { "R009_ClassType_0", 201 },
   { "R009_ClassType_1", 202 },
   { "R009_AnnotationTypeElementDeclaration_0", 203 },
   { "R009_AnnotationTypeElementDeclaration_1", 204 },
   { "R009_AnnotationTypeElementDeclaration_2", 205 },
   { "R009_AnnotationTypeElementDeclaration_3", 206 },
   { "R009_AnnotationTypeElementDeclaration_4", 207 },
   { "R009_AnnotationTypeElementDeclaration_5", 208 },
   { "R009_AnnotationTypeElementDeclaration_6", 209 },
   { "R009_AnnotationTypeElementDeclaration_7", 210 },
   { "R009_DefaultValue_0", 211 },
   { "R009_ElementValue_0", 212 },
   { "R009_ElementValue_1", 213 },
   { "R009_Result_0", 214 },
   { "R009_Result_1", 215 },
   { "R009_UnannType_0", 216 },
   { "R009_UnannType_1", 217 },
   { "R009_UnannType_2", 218 },
   { "R009_UnannPrimitiveType_0", 219 },
   { "R009_UnannPrimitiveType_1", 220 },
   { "R009_UnannPrimitiveType_2", 221 },
   { "R009_UnannPrimitiveType_3", 222 },
   { "R009_UnannPrimitiveType_4", 223 },
   { "R009_UnannPrimitiveType_5", 224 },
   { "R009_UnannPrimitiveType_6", 225 },
   { "R009_UnannPrimitiveType_7", 226 },
   { "R009_UnannClassOrInterfaceType_0", 227 },
   { "R009_UnannClassOrInterfaceType_1", 228 },
   { "R009_UnannClassOrInterfaceType_2", 229 },
   { "R009_UnannClassOrInterfaceType_3", 230 },
   { "R009_UnannClassOrInterfaceType_4", 231 },
   { "R009_UnannClassOrInterfaceType_5", 232 },
   { "R009_UnannArrayType_0", 233 },
   { "R009_UnannArrayType_1", 234 },
   { "R009_Dims_0", 235 },
   { "R009_Dims_1", 236 },
   { "R009_Dims_2", 237 },
   { "R009_Dims_3", 238 },
   { "R009_ConstantDeclaration_0", 239 },
   { "R009_ConstantDeclaration_1", 240 },
   { "R009_ConstantDeclarationFake_0", 241 },
   { "R009_ConstantDeclarationFake_1", 242 },
   { "R009_VariableDeclaratorList_0", 243 },
   { "R009_VariableDeclaratorList_1", 244 },
   { "R009_VariableDeclarator_0", 245 },
   { "R009_VariableDeclarator_1", 246 },
   { "R009_VariableInitializer_0", 247 },
   { "R009_VariableInitializer_1", 248 },
   { "R009_VariableInitializerEle_0", 249 },
   { "R009_VariableInitializerEle_1", 250 },
   { "R009_VariableInitializerEle_2", 251 },
   { "R009_VariableInitializerEle_3", 252 },
   { "R009_VariableInitializerEle_4", 253 },
   { "R009_VariableInitializerEle_5", 254 },
   { "R009_VariableDeclaratorId_0", 255 },
   { "R009_VariableDeclaratorId_1", 256 },
   { "R009_AnnotationList_0", 257 },
   { "R009_AnnotationList_1", 258 },
   { "R009_DimExpr_0", 259 },
   { "R009_DimExpr_1", 260 },
	};
}

P_SDT_genertor SDT_R009_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R009_ele_begin_0"] = P_SDT_genertor(new R009_ele_begin_0Analyzer()); break;
	case 1: factory["R009_AnnotationTypeMemberDeclaration_0"] = P_SDT_genertor(new R009_AnnotationTypeMemberDeclaration_0Analyzer()); break;
	case 2: factory["R009_AnnotationTypeMemberDeclaration_1"] = P_SDT_genertor(new R009_AnnotationTypeMemberDeclaration_1Analyzer()); break;
	case 3: factory["R009_AnnotationTypeMemberDeclaration_2"] = P_SDT_genertor(new R009_AnnotationTypeMemberDeclaration_2Analyzer()); break;
	case 4: factory["R009_AnnotationTypeMemberDeclaration_3"] = P_SDT_genertor(new R009_AnnotationTypeMemberDeclaration_3Analyzer()); break;
	case 5: factory["R009_AnnotationTypeMemberDeclaration_4"] = P_SDT_genertor(new R009_AnnotationTypeMemberDeclaration_4Analyzer()); break;
	case 6: factory["R009_InterfaceDeclaration_0"] = P_SDT_genertor(new R009_InterfaceDeclaration_0Analyzer()); break;
	case 7: factory["R009_InterfaceDeclaration_1"] = P_SDT_genertor(new R009_InterfaceDeclaration_1Analyzer()); break;
	case 8: factory["R009_ClassDeclaration_0"] = P_SDT_genertor(new R009_ClassDeclaration_0Analyzer()); break;
	case 9: factory["R009_ClassDeclaration_1"] = P_SDT_genertor(new R009_ClassDeclaration_1Analyzer()); break;
	case 10: factory["R009_EnumDeclaration_0"] = P_SDT_genertor(new R009_EnumDeclaration_0Analyzer()); break;
	case 11: factory["R009_EnumDeclaration_1"] = P_SDT_genertor(new R009_EnumDeclaration_1Analyzer()); break;
	case 12: factory["R009_EnumDeclaration_2"] = P_SDT_genertor(new R009_EnumDeclaration_2Analyzer()); break;
	case 13: factory["R009_EnumDeclaration_3"] = P_SDT_genertor(new R009_EnumDeclaration_3Analyzer()); break;
	case 14: factory["R009_NormalClassDeclaration_0"] = P_SDT_genertor(new R009_NormalClassDeclaration_0Analyzer()); break;
	case 15: factory["R009_NormalClassDeclaration_1"] = P_SDT_genertor(new R009_NormalClassDeclaration_1Analyzer()); break;
	case 16: factory["R009_NormalClassDeclaration_2"] = P_SDT_genertor(new R009_NormalClassDeclaration_2Analyzer()); break;
	case 17: factory["R009_NormalClassDeclaration_3"] = P_SDT_genertor(new R009_NormalClassDeclaration_3Analyzer()); break;
	case 18: factory["R009_NormalClassDeclaration_4"] = P_SDT_genertor(new R009_NormalClassDeclaration_4Analyzer()); break;
	case 19: factory["R009_NormalClassDeclaration_5"] = P_SDT_genertor(new R009_NormalClassDeclaration_5Analyzer()); break;
	case 20: factory["R009_NormalClassDeclaration_6"] = P_SDT_genertor(new R009_NormalClassDeclaration_6Analyzer()); break;
	case 21: factory["R009_NormalClassDeclaration_7"] = P_SDT_genertor(new R009_NormalClassDeclaration_7Analyzer()); break;
	case 22: factory["R009_NormalClassDeclaration_8"] = P_SDT_genertor(new R009_NormalClassDeclaration_8Analyzer()); break;
	case 23: factory["R009_NormalClassDeclaration_9"] = P_SDT_genertor(new R009_NormalClassDeclaration_9Analyzer()); break;
	case 24: factory["R009_NormalClassDeclaration_10"] = P_SDT_genertor(new R009_NormalClassDeclaration_10Analyzer()); break;
	case 25: factory["R009_NormalClassDeclaration_11"] = P_SDT_genertor(new R009_NormalClassDeclaration_11Analyzer()); break;
	case 26: factory["R009_NormalClassDeclaration_12"] = P_SDT_genertor(new R009_NormalClassDeclaration_12Analyzer()); break;
	case 27: factory["R009_NormalClassDeclaration_13"] = P_SDT_genertor(new R009_NormalClassDeclaration_13Analyzer()); break;
	case 28: factory["R009_NormalClassDeclaration_14"] = P_SDT_genertor(new R009_NormalClassDeclaration_14Analyzer()); break;
	case 29: factory["R009_NormalClassDeclaration_15"] = P_SDT_genertor(new R009_NormalClassDeclaration_15Analyzer()); break;
	case 30: factory["R009_Superclass_0"] = P_SDT_genertor(new R009_Superclass_0Analyzer()); break;
	case 31: factory["R009_Superinterfaces_0"] = P_SDT_genertor(new R009_Superinterfaces_0Analyzer()); break;
	case 32: factory["R009_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_0Analyzer()); break;
	case 33: factory["R009_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_1Analyzer()); break;
	case 34: factory["R009_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_2Analyzer()); break;
	case 35: factory["R009_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_3Analyzer()); break;
	case 36: factory["R009_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_4Analyzer()); break;
	case 37: factory["R009_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_5Analyzer()); break;
	case 38: factory["R009_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_6Analyzer()); break;
	case 39: factory["R009_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R009_NormalInterfaceDeclaration_7Analyzer()); break;
	case 40: factory["R009_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R009_AnnotationTypeDeclaration_0Analyzer()); break;
	case 41: factory["R009_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R009_AnnotationTypeDeclaration_1Analyzer()); break;
	case 42: factory["R009_Identifier_0"] = P_SDT_genertor(new R009_Identifier_0Analyzer()); break;
	case 43: factory["R009_Block_0"] = P_SDT_genertor(new R009_Block_0Analyzer()); break;
	case 44: factory["R009_Block_1"] = P_SDT_genertor(new R009_Block_1Analyzer()); break;
	case 45: factory["R009_BlockStatements_0"] = P_SDT_genertor(new R009_BlockStatements_0Analyzer()); break;
	case 46: factory["R009_BlockStatements_1"] = P_SDT_genertor(new R009_BlockStatements_1Analyzer()); break;
	case 47: factory["R009_BlockStatements_2"] = P_SDT_genertor(new R009_BlockStatements_2Analyzer()); break;
	case 48: factory["R009_NonBrace_0"] = P_SDT_genertor(new R009_NonBrace_0Analyzer()); break;
	case 49: factory["R009_NonBrace_1"] = P_SDT_genertor(new R009_NonBrace_1Analyzer()); break;
	case 50: factory["R009_NonBrace_2"] = P_SDT_genertor(new R009_NonBrace_2Analyzer()); break;
	case 51: factory["R009_NonBrace_3"] = P_SDT_genertor(new R009_NonBrace_3Analyzer()); break;
	case 52: factory["R009_NonBrace_4"] = P_SDT_genertor(new R009_NonBrace_4Analyzer()); break;
	case 53: factory["R009_NonBrace_5"] = P_SDT_genertor(new R009_NonBrace_5Analyzer()); break;
	case 54: factory["R009_NonBrace_6"] = P_SDT_genertor(new R009_NonBrace_6Analyzer()); break;
	case 55: factory["R009_NonBrace_7"] = P_SDT_genertor(new R009_NonBrace_7Analyzer()); break;
	case 56: factory["R009_NonBrace_8"] = P_SDT_genertor(new R009_NonBrace_8Analyzer()); break;
	case 57: factory["R009_NonBrace_9"] = P_SDT_genertor(new R009_NonBrace_9Analyzer()); break;
	case 58: factory["R009_StatementEle_0"] = P_SDT_genertor(new R009_StatementEle_0Analyzer()); break;
	case 59: factory["R009_StatementEle_1"] = P_SDT_genertor(new R009_StatementEle_1Analyzer()); break;
	case 60: factory["R009_StatementEle_2"] = P_SDT_genertor(new R009_StatementEle_2Analyzer()); break;
	case 61: factory["R009_StatementEle_3"] = P_SDT_genertor(new R009_StatementEle_3Analyzer()); break;
	case 62: factory["R009_StatementEle_4"] = P_SDT_genertor(new R009_StatementEle_4Analyzer()); break;
	case 63: factory["R009_StatementEle_5"] = P_SDT_genertor(new R009_StatementEle_5Analyzer()); break;
	case 64: factory["R009_StatementEle_6"] = P_SDT_genertor(new R009_StatementEle_6Analyzer()); break;
	case 65: factory["R009_StatementEle_7"] = P_SDT_genertor(new R009_StatementEle_7Analyzer()); break;
	case 66: factory["R009_StatementEle_8"] = P_SDT_genertor(new R009_StatementEle_8Analyzer()); break;
	case 67: factory["R009_StatementEle_9"] = P_SDT_genertor(new R009_StatementEle_9Analyzer()); break;
	case 68: factory["R009_StatementEle_10"] = P_SDT_genertor(new R009_StatementEle_10Analyzer()); break;
	case 69: factory["R009_StatementEle_11"] = P_SDT_genertor(new R009_StatementEle_11Analyzer()); break;
	case 70: factory["R009_StatementEle_12"] = P_SDT_genertor(new R009_StatementEle_12Analyzer()); break;
	case 71: factory["R009_StatementEle_13"] = P_SDT_genertor(new R009_StatementEle_13Analyzer()); break;
	case 72: factory["R009_StatementEle_14"] = P_SDT_genertor(new R009_StatementEle_14Analyzer()); break;
	case 73: factory["R009_StatementEle_15"] = P_SDT_genertor(new R009_StatementEle_15Analyzer()); break;
	case 74: factory["R009_StatementEle_16"] = P_SDT_genertor(new R009_StatementEle_16Analyzer()); break;
	case 75: factory["R009_StatementEle_17"] = P_SDT_genertor(new R009_StatementEle_17Analyzer()); break;
	case 76: factory["R009_StatementEle_18"] = P_SDT_genertor(new R009_StatementEle_18Analyzer()); break;
	case 77: factory["R009_StatementEle_19"] = P_SDT_genertor(new R009_StatementEle_19Analyzer()); break;
	case 78: factory["R009_StatementEle_20"] = P_SDT_genertor(new R009_StatementEle_20Analyzer()); break;
	case 79: factory["R009_StatementEle_21"] = P_SDT_genertor(new R009_StatementEle_21Analyzer()); break;
	case 80: factory["R009_StatementEle_22"] = P_SDT_genertor(new R009_StatementEle_22Analyzer()); break;
	case 81: factory["R009_StatementEle_23"] = P_SDT_genertor(new R009_StatementEle_23Analyzer()); break;
	case 82: factory["R009_StatementEle_24"] = P_SDT_genertor(new R009_StatementEle_24Analyzer()); break;
	case 83: factory["R009_StatementEle_25"] = P_SDT_genertor(new R009_StatementEle_25Analyzer()); break;
	case 84: factory["R009_StatementEle_26"] = P_SDT_genertor(new R009_StatementEle_26Analyzer()); break;
	case 85: factory["R009_StatementEle_27"] = P_SDT_genertor(new R009_StatementEle_27Analyzer()); break;
	case 86: factory["R009_StatementEle_28"] = P_SDT_genertor(new R009_StatementEle_28Analyzer()); break;
	case 87: factory["R009_StatementEle_29"] = P_SDT_genertor(new R009_StatementEle_29Analyzer()); break;
	case 88: factory["R009_StatementEle_30"] = P_SDT_genertor(new R009_StatementEle_30Analyzer()); break;
	case 89: factory["R009_StatementEle_31"] = P_SDT_genertor(new R009_StatementEle_31Analyzer()); break;
	case 90: factory["R009_StatementEle_32"] = P_SDT_genertor(new R009_StatementEle_32Analyzer()); break;
	case 91: factory["R009_StatementEle_33"] = P_SDT_genertor(new R009_StatementEle_33Analyzer()); break;
	case 92: factory["R009_StatementEle_34"] = P_SDT_genertor(new R009_StatementEle_34Analyzer()); break;
	case 93: factory["R009_StatementEle_35"] = P_SDT_genertor(new R009_StatementEle_35Analyzer()); break;
	case 94: factory["R009_StatementEle_36"] = P_SDT_genertor(new R009_StatementEle_36Analyzer()); break;
	case 95: factory["R009_StatementEle_37"] = P_SDT_genertor(new R009_StatementEle_37Analyzer()); break;
	case 96: factory["R009_StatementEle_38"] = P_SDT_genertor(new R009_StatementEle_38Analyzer()); break;
	case 97: factory["R009_StatementEle_39"] = P_SDT_genertor(new R009_StatementEle_39Analyzer()); break;
	case 98: factory["R009_StatementEle_40"] = P_SDT_genertor(new R009_StatementEle_40Analyzer()); break;
	case 99: factory["R009_StatementEle_41"] = P_SDT_genertor(new R009_StatementEle_41Analyzer()); break;
	case 100: factory["R009_StatementEle_42"] = P_SDT_genertor(new R009_StatementEle_42Analyzer()); break;
	case 101: factory["R009_StatementEle_43"] = P_SDT_genertor(new R009_StatementEle_43Analyzer()); break;
	case 102: factory["R009_StatementEle_44"] = P_SDT_genertor(new R009_StatementEle_44Analyzer()); break;
	case 103: factory["R009_StatementEle_45"] = P_SDT_genertor(new R009_StatementEle_45Analyzer()); break;
	case 104: factory["R009_StatementEle_46"] = P_SDT_genertor(new R009_StatementEle_46Analyzer()); break;
	case 105: factory["R009_StatementEle_47"] = P_SDT_genertor(new R009_StatementEle_47Analyzer()); break;
	case 106: factory["R009_StatementEle_48"] = P_SDT_genertor(new R009_StatementEle_48Analyzer()); break;
	case 107: factory["R009_StatementEle_49"] = P_SDT_genertor(new R009_StatementEle_49Analyzer()); break;
	case 108: factory["R009_StatementEle_50"] = P_SDT_genertor(new R009_StatementEle_50Analyzer()); break;
	case 109: factory["R009_StatementEle_51"] = P_SDT_genertor(new R009_StatementEle_51Analyzer()); break;
	case 110: factory["R009_StatementEle_52"] = P_SDT_genertor(new R009_StatementEle_52Analyzer()); break;
	case 111: factory["R009_StatementEle_53"] = P_SDT_genertor(new R009_StatementEle_53Analyzer()); break;
	case 112: factory["R009_StatementEle_54"] = P_SDT_genertor(new R009_StatementEle_54Analyzer()); break;
	case 113: factory["R009_StatementEle_55"] = P_SDT_genertor(new R009_StatementEle_55Analyzer()); break;
	case 114: factory["R009_StatementEle_56"] = P_SDT_genertor(new R009_StatementEle_56Analyzer()); break;
	case 115: factory["R009_StatementEle_57"] = P_SDT_genertor(new R009_StatementEle_57Analyzer()); break;
	case 116: factory["R009_StatementEle_58"] = P_SDT_genertor(new R009_StatementEle_58Analyzer()); break;
	case 117: factory["R009_StatementEle_59"] = P_SDT_genertor(new R009_StatementEle_59Analyzer()); break;
	case 118: factory["R009_StatementEle_60"] = P_SDT_genertor(new R009_StatementEle_60Analyzer()); break;
	case 119: factory["R009_StatementEle_61"] = P_SDT_genertor(new R009_StatementEle_61Analyzer()); break;
	case 120: factory["R009_StatementEle_62"] = P_SDT_genertor(new R009_StatementEle_62Analyzer()); break;
	case 121: factory["R009_StatementEle_63"] = P_SDT_genertor(new R009_StatementEle_63Analyzer()); break;
	case 122: factory["R009_StatementEle_64"] = P_SDT_genertor(new R009_StatementEle_64Analyzer()); break;
	case 123: factory["R009_StatementEle_65"] = P_SDT_genertor(new R009_StatementEle_65Analyzer()); break;
	case 124: factory["R009_StatementEle_66"] = P_SDT_genertor(new R009_StatementEle_66Analyzer()); break;
	case 125: factory["R009_StatementEle_67"] = P_SDT_genertor(new R009_StatementEle_67Analyzer()); break;
	case 126: factory["R009_StatementEle_68"] = P_SDT_genertor(new R009_StatementEle_68Analyzer()); break;
	case 127: factory["R009_StatementEle_69"] = P_SDT_genertor(new R009_StatementEle_69Analyzer()); break;
	case 128: factory["R009_StatementEle_70"] = P_SDT_genertor(new R009_StatementEle_70Analyzer()); break;
	case 129: factory["R009_StatementEle_71"] = P_SDT_genertor(new R009_StatementEle_71Analyzer()); break;
	case 130: factory["R009_StatementEle_72"] = P_SDT_genertor(new R009_StatementEle_72Analyzer()); break;
	case 131: factory["R009_StatementEle_73"] = P_SDT_genertor(new R009_StatementEle_73Analyzer()); break;
	case 132: factory["R009_StatementEle_74"] = P_SDT_genertor(new R009_StatementEle_74Analyzer()); break;
	case 133: factory["R009_StatementEle_75"] = P_SDT_genertor(new R009_StatementEle_75Analyzer()); break;
	case 134: factory["R009_StatementEle_76"] = P_SDT_genertor(new R009_StatementEle_76Analyzer()); break;
	case 135: factory["R009_StatementEle_77"] = P_SDT_genertor(new R009_StatementEle_77Analyzer()); break;
	case 136: factory["R009_StatementEle_78"] = P_SDT_genertor(new R009_StatementEle_78Analyzer()); break;
	case 137: factory["R009_StatementEle_79"] = P_SDT_genertor(new R009_StatementEle_79Analyzer()); break;
	case 138: factory["R009_ModifierList_0"] = P_SDT_genertor(new R009_ModifierList_0Analyzer()); break;
	case 139: factory["R009_ModifierList_1"] = P_SDT_genertor(new R009_ModifierList_1Analyzer()); break;
	case 140: factory["R009_Modifier_0"] = P_SDT_genertor(new R009_Modifier_0Analyzer()); break;
	case 141: factory["R009_Modifier_1"] = P_SDT_genertor(new R009_Modifier_1Analyzer()); break;
	case 142: factory["R009_Modifier_2"] = P_SDT_genertor(new R009_Modifier_2Analyzer()); break;
	case 143: factory["R009_Modifier_3"] = P_SDT_genertor(new R009_Modifier_3Analyzer()); break;
	case 144: factory["R009_Modifier_4"] = P_SDT_genertor(new R009_Modifier_4Analyzer()); break;
	case 145: factory["R009_Modifier_5"] = P_SDT_genertor(new R009_Modifier_5Analyzer()); break;
	case 146: factory["R009_Modifier_6"] = P_SDT_genertor(new R009_Modifier_6Analyzer()); break;
	case 147: factory["R009_Modifier_7"] = P_SDT_genertor(new R009_Modifier_7Analyzer()); break;
	case 148: factory["R009_Modifier_8"] = P_SDT_genertor(new R009_Modifier_8Analyzer()); break;
	case 149: factory["R009_Modifier_9"] = P_SDT_genertor(new R009_Modifier_9Analyzer()); break;
	case 150: factory["R009_Modifier_10"] = P_SDT_genertor(new R009_Modifier_10Analyzer()); break;
	case 151: factory["R009_Modifier_11"] = P_SDT_genertor(new R009_Modifier_11Analyzer()); break;
	case 152: factory["R009_Modifier_12"] = P_SDT_genertor(new R009_Modifier_12Analyzer()); break;
	case 153: factory["R009_Annotation_0"] = P_SDT_genertor(new R009_Annotation_0Analyzer()); break;
	case 154: factory["R009_Annotation_1"] = P_SDT_genertor(new R009_Annotation_1Analyzer()); break;
	case 155: factory["R009_DetailIdentifier_0"] = P_SDT_genertor(new R009_DetailIdentifier_0Analyzer()); break;
	case 156: factory["R009_DetailIdentifier_1"] = P_SDT_genertor(new R009_DetailIdentifier_1Analyzer()); break;
	case 157: factory["R009_AnnotationContent_0"] = P_SDT_genertor(new R009_AnnotationContent_0Analyzer()); break;
	case 158: factory["R009_AnnotationContentStatements_0"] = P_SDT_genertor(new R009_AnnotationContentStatements_0Analyzer()); break;
	case 159: factory["R009_AnnotationContentStatements_1"] = P_SDT_genertor(new R009_AnnotationContentStatements_1Analyzer()); break;
	case 160: factory["R009_NonPARENTHESES_0"] = P_SDT_genertor(new R009_NonPARENTHESES_0Analyzer()); break;
	case 161: factory["R009_NonPARENTHESES_1"] = P_SDT_genertor(new R009_NonPARENTHESES_1Analyzer()); break;
	case 162: factory["R009_NonPARENTHESES_2"] = P_SDT_genertor(new R009_NonPARENTHESES_2Analyzer()); break;
	case 163: factory["R009_NonPARENTHESES_3"] = P_SDT_genertor(new R009_NonPARENTHESES_3Analyzer()); break;
	case 164: factory["R009_NonPARENTHESES_4"] = P_SDT_genertor(new R009_NonPARENTHESES_4Analyzer()); break;
	case 165: factory["R009_NonPARENTHESES_5"] = P_SDT_genertor(new R009_NonPARENTHESES_5Analyzer()); break;
	case 166: factory["R009_NonPARENTHESES_6"] = P_SDT_genertor(new R009_NonPARENTHESES_6Analyzer()); break;
	case 167: factory["R009_NonPARENTHESES_7"] = P_SDT_genertor(new R009_NonPARENTHESES_7Analyzer()); break;
	case 168: factory["R009_NonPARENTHESES_8"] = P_SDT_genertor(new R009_NonPARENTHESES_8Analyzer()); break;
	case 169: factory["R009_NonPARENTHESES_9"] = P_SDT_genertor(new R009_NonPARENTHESES_9Analyzer()); break;
	case 170: factory["R009_NonPARENTHESES_10"] = P_SDT_genertor(new R009_NonPARENTHESES_10Analyzer()); break;
	case 171: factory["R009_NonPARENTHESES_11"] = P_SDT_genertor(new R009_NonPARENTHESES_11Analyzer()); break;
	case 172: factory["R009_TypeArguments_0"] = P_SDT_genertor(new R009_TypeArguments_0Analyzer()); break;
	case 173: factory["R009_TypeArguments_1"] = P_SDT_genertor(new R009_TypeArguments_1Analyzer()); break;
	case 174: factory["R009_TypeArguments_2"] = P_SDT_genertor(new R009_TypeArguments_2Analyzer()); break;
	case 175: factory["R009_TypeArguments_3"] = P_SDT_genertor(new R009_TypeArguments_3Analyzer()); break;
	case 176: factory["R009_TypeArgumentListL2_0"] = P_SDT_genertor(new R009_TypeArgumentListL2_0Analyzer()); break;
	case 177: factory["R009_TypeArgumentListL2_1"] = P_SDT_genertor(new R009_TypeArgumentListL2_1Analyzer()); break;
	case 178: factory["R009_TypeArgumentListL2_2"] = P_SDT_genertor(new R009_TypeArgumentListL2_2Analyzer()); break;
	case 179: factory["R009_TypeArgumentListL1_0"] = P_SDT_genertor(new R009_TypeArgumentListL1_0Analyzer()); break;
	case 180: factory["R009_TypeArgumentListL1_1"] = P_SDT_genertor(new R009_TypeArgumentListL1_1Analyzer()); break;
	case 181: factory["R009_TypeArgumentListL1_2"] = P_SDT_genertor(new R009_TypeArgumentListL1_2Analyzer()); break;
	case 182: factory["R009_TypeArgumentList_0"] = P_SDT_genertor(new R009_TypeArgumentList_0Analyzer()); break;
	case 183: factory["R009_TypeArgumentList_1"] = P_SDT_genertor(new R009_TypeArgumentList_1Analyzer()); break;
	case 184: factory["R009_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_0Analyzer()); break;
	case 185: factory["R009_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_1Analyzer()); break;
	case 186: factory["R009_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_2Analyzer()); break;
	case 187: factory["R009_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_3Analyzer()); break;
	case 188: factory["R009_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_4Analyzer()); break;
	case 189: factory["R009_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_5Analyzer()); break;
	case 190: factory["R009_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_6Analyzer()); break;
	case 191: factory["R009_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_7Analyzer()); break;
	case 192: factory["R009_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_8Analyzer()); break;
	case 193: factory["R009_NonANGLE_BRACKET_9"] = P_SDT_genertor(new R009_NonANGLE_BRACKET_9Analyzer()); break;
	case 194: factory["R009_ExtendsInterfaces_0"] = P_SDT_genertor(new R009_ExtendsInterfaces_0Analyzer()); break;
	case 195: factory["R009_InterfaceTypeList_0"] = P_SDT_genertor(new R009_InterfaceTypeList_0Analyzer()); break;
	case 196: factory["R009_InterfaceTypeList_1"] = P_SDT_genertor(new R009_InterfaceTypeList_1Analyzer()); break;
	case 197: factory["R009_ClassTypeEle_0"] = P_SDT_genertor(new R009_ClassTypeEle_0Analyzer()); break;
	case 198: factory["R009_ClassTypeEle_1"] = P_SDT_genertor(new R009_ClassTypeEle_1Analyzer()); break;
	case 199: factory["R009_ClassTypeEle_2"] = P_SDT_genertor(new R009_ClassTypeEle_2Analyzer()); break;
	case 200: factory["R009_ClassTypeEle_3"] = P_SDT_genertor(new R009_ClassTypeEle_3Analyzer()); break;
	case 201: factory["R009_ClassType_0"] = P_SDT_genertor(new R009_ClassType_0Analyzer()); break;
	case 202: factory["R009_ClassType_1"] = P_SDT_genertor(new R009_ClassType_1Analyzer()); break;
	case 203: factory["R009_AnnotationTypeElementDeclaration_0"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_0Analyzer()); break;
	case 204: factory["R009_AnnotationTypeElementDeclaration_1"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_1Analyzer()); break;
	case 205: factory["R009_AnnotationTypeElementDeclaration_2"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_2Analyzer()); break;
	case 206: factory["R009_AnnotationTypeElementDeclaration_3"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_3Analyzer()); break;
	case 207: factory["R009_AnnotationTypeElementDeclaration_4"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_4Analyzer()); break;
	case 208: factory["R009_AnnotationTypeElementDeclaration_5"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_5Analyzer()); break;
	case 209: factory["R009_AnnotationTypeElementDeclaration_6"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_6Analyzer()); break;
	case 210: factory["R009_AnnotationTypeElementDeclaration_7"] = P_SDT_genertor(new R009_AnnotationTypeElementDeclaration_7Analyzer()); break;
	case 211: factory["R009_DefaultValue_0"] = P_SDT_genertor(new R009_DefaultValue_0Analyzer()); break;
	case 212: factory["R009_ElementValue_0"] = P_SDT_genertor(new R009_ElementValue_0Analyzer()); break;
	case 213: factory["R009_ElementValue_1"] = P_SDT_genertor(new R009_ElementValue_1Analyzer()); break;
	case 214: factory["R009_Result_0"] = P_SDT_genertor(new R009_Result_0Analyzer()); break;
	case 215: factory["R009_Result_1"] = P_SDT_genertor(new R009_Result_1Analyzer()); break;
	case 216: factory["R009_UnannType_0"] = P_SDT_genertor(new R009_UnannType_0Analyzer()); break;
	case 217: factory["R009_UnannType_1"] = P_SDT_genertor(new R009_UnannType_1Analyzer()); break;
	case 218: factory["R009_UnannType_2"] = P_SDT_genertor(new R009_UnannType_2Analyzer()); break;
	case 219: factory["R009_UnannPrimitiveType_0"] = P_SDT_genertor(new R009_UnannPrimitiveType_0Analyzer()); break;
	case 220: factory["R009_UnannPrimitiveType_1"] = P_SDT_genertor(new R009_UnannPrimitiveType_1Analyzer()); break;
	case 221: factory["R009_UnannPrimitiveType_2"] = P_SDT_genertor(new R009_UnannPrimitiveType_2Analyzer()); break;
	case 222: factory["R009_UnannPrimitiveType_3"] = P_SDT_genertor(new R009_UnannPrimitiveType_3Analyzer()); break;
	case 223: factory["R009_UnannPrimitiveType_4"] = P_SDT_genertor(new R009_UnannPrimitiveType_4Analyzer()); break;
	case 224: factory["R009_UnannPrimitiveType_5"] = P_SDT_genertor(new R009_UnannPrimitiveType_5Analyzer()); break;
	case 225: factory["R009_UnannPrimitiveType_6"] = P_SDT_genertor(new R009_UnannPrimitiveType_6Analyzer()); break;
	case 226: factory["R009_UnannPrimitiveType_7"] = P_SDT_genertor(new R009_UnannPrimitiveType_7Analyzer()); break;
	case 227: factory["R009_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R009_UnannClassOrInterfaceType_0Analyzer()); break;
	case 228: factory["R009_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R009_UnannClassOrInterfaceType_1Analyzer()); break;
	case 229: factory["R009_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R009_UnannClassOrInterfaceType_2Analyzer()); break;
	case 230: factory["R009_UnannClassOrInterfaceType_3"] = P_SDT_genertor(new R009_UnannClassOrInterfaceType_3Analyzer()); break;
	case 231: factory["R009_UnannClassOrInterfaceType_4"] = P_SDT_genertor(new R009_UnannClassOrInterfaceType_4Analyzer()); break;
	case 232: factory["R009_UnannClassOrInterfaceType_5"] = P_SDT_genertor(new R009_UnannClassOrInterfaceType_5Analyzer()); break;
	case 233: factory["R009_UnannArrayType_0"] = P_SDT_genertor(new R009_UnannArrayType_0Analyzer()); break;
	case 234: factory["R009_UnannArrayType_1"] = P_SDT_genertor(new R009_UnannArrayType_1Analyzer()); break;
	case 235: factory["R009_Dims_0"] = P_SDT_genertor(new R009_Dims_0Analyzer()); break;
	case 236: factory["R009_Dims_1"] = P_SDT_genertor(new R009_Dims_1Analyzer()); break;
	case 237: factory["R009_Dims_2"] = P_SDT_genertor(new R009_Dims_2Analyzer()); break;
	case 238: factory["R009_Dims_3"] = P_SDT_genertor(new R009_Dims_3Analyzer()); break;
	case 239: factory["R009_ConstantDeclaration_0"] = P_SDT_genertor(new R009_ConstantDeclaration_0Analyzer()); break;
	case 240: factory["R009_ConstantDeclaration_1"] = P_SDT_genertor(new R009_ConstantDeclaration_1Analyzer()); break;
	case 241: factory["R009_ConstantDeclarationFake_0"] = P_SDT_genertor(new R009_ConstantDeclarationFake_0Analyzer()); break;
	case 242: factory["R009_ConstantDeclarationFake_1"] = P_SDT_genertor(new R009_ConstantDeclarationFake_1Analyzer()); break;
	case 243: factory["R009_VariableDeclaratorList_0"] = P_SDT_genertor(new R009_VariableDeclaratorList_0Analyzer()); break;
	case 244: factory["R009_VariableDeclaratorList_1"] = P_SDT_genertor(new R009_VariableDeclaratorList_1Analyzer()); break;
	case 245: factory["R009_VariableDeclarator_0"] = P_SDT_genertor(new R009_VariableDeclarator_0Analyzer()); break;
	case 246: factory["R009_VariableDeclarator_1"] = P_SDT_genertor(new R009_VariableDeclarator_1Analyzer()); break;
	case 247: factory["R009_VariableInitializer_0"] = P_SDT_genertor(new R009_VariableInitializer_0Analyzer()); break;
	case 248: factory["R009_VariableInitializer_1"] = P_SDT_genertor(new R009_VariableInitializer_1Analyzer()); break;
	case 249: factory["R009_VariableInitializerEle_0"] = P_SDT_genertor(new R009_VariableInitializerEle_0Analyzer()); break;
	case 250: factory["R009_VariableInitializerEle_1"] = P_SDT_genertor(new R009_VariableInitializerEle_1Analyzer()); break;
	case 251: factory["R009_VariableInitializerEle_2"] = P_SDT_genertor(new R009_VariableInitializerEle_2Analyzer()); break;
	case 252: factory["R009_VariableInitializerEle_3"] = P_SDT_genertor(new R009_VariableInitializerEle_3Analyzer()); break;
	case 253: factory["R009_VariableInitializerEle_4"] = P_SDT_genertor(new R009_VariableInitializerEle_4Analyzer()); break;
	case 254: factory["R009_VariableInitializerEle_5"] = P_SDT_genertor(new R009_VariableInitializerEle_5Analyzer()); break;
	case 255: factory["R009_VariableDeclaratorId_0"] = P_SDT_genertor(new R009_VariableDeclaratorId_0Analyzer()); break;
	case 256: factory["R009_VariableDeclaratorId_1"] = P_SDT_genertor(new R009_VariableDeclaratorId_1Analyzer()); break;
	case 257: factory["R009_AnnotationList_0"] = P_SDT_genertor(new R009_AnnotationList_0Analyzer()); break;
	case 258: factory["R009_AnnotationList_1"] = P_SDT_genertor(new R009_AnnotationList_1Analyzer()); break;
	case 259: factory["R009_DimExpr_0"] = P_SDT_genertor(new R009_DimExpr_0Analyzer()); break;
	case 260: factory["R009_DimExpr_1"] = P_SDT_genertor(new R009_DimExpr_1Analyzer()); break;
	default:

		if (key.find("R009_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R009_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R009_Factory::~SDT_R009_Factory() {}
