#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R003Analyzer.h"
using namespace std;
using namespace boost;



SDT_Factory SDT_Factory::instance;
SDT_Factory::SDT_Factory() {
	 control_Param = {
	{ "R003_ele_begin_0", 0 },
	{ "R003_CompilationUnit_0", 1 },
	{ "R003_CompilationUnit_1", 2 },
	{ "R003_CompilationUnit_2", 3 },
	{ "R003_CompilationUnit_3", 4 },
	{ "R003_CompilationUnit_4", 5 },
	{ "R003_CompilationUnit_5", 6 },
	{ "R003_CompilationUnit_6", 7 },
	{ "R003_PackageDeclaration_0", 8 },
	{ "R003_DetailIdentifier_0", 9 },
	{ "R003_DetailIdentifier_1", 10 },
	{ "R003_Identifier_0", 11 },
	{ "R003_ImportDeclarationList_0", 12 },
	{ "R003_ImportDeclarationList_1", 13 },
	{ "R003_ImportDeclaration_0", 14 },
	{ "R003_ImportDeclaration_1", 15 },
	{ "R003_ImportDeclaration_2", 16 },
	{ "R003_ImportDeclaration_3", 17 },
	{ "R003_TypeDeclarationList_0", 18 },
	{ "R003_TypeDeclarationList_1", 19 },
	{ "R003_TypeDeclaration_0", 20 },
	{ "R003_TypeDeclaration_1", 21 },
	{ "R003_ClassDeclaration_0", 22 },
	{ "R003_NormalClassDeclaration_0", 23 },
	{ "R003_ClassBody_0", 24 },
	{ "R003_ClassBodyDeclarationList_0", 25 },
	{ "R003_ClassBodyDeclarationList_1", 26 },
	{ "R003_ClassBodyDeclaration_0", 27 },
	{ "R003_ClassMemberDeclaration_0", 28 },
	{ "R003_MethodDeclaration_0", 29 },
	{ "R003_MethodDeclaration_1", 30 },
	{ "R003_MethodHeader_0", 31 },
	{ "R003_MethodDeclarator_0", 32 },
	{ "R003_ModifierList_0", 33 },
	{ "R003_ModifierList_1", 34 },
	{ "R003_AnnotationContent_0", 35 },
	{ "R003_AnnotationContentStatements_0", 36 },
	{ "R003_AnnotationContentStatements_1", 37 },
	{ "R003_NonPARENTHESES_0", 38 },
	{ "R003_NonPARENTHESES_1", 39 },
	{ "R003_NonPARENTHESES_2", 40 },
	{ "R003_NonPARENTHESES_3", 41 },
	{ "R003_NonPARENTHESES_4", 42 },
	{ "R003_NonPARENTHESES_5", 43 },
	{ "R003_NonPARENTHESES_6", 44 },
	{ "R003_NonPARENTHESES_7", 45 },
	{ "R003_NonPARENTHESES_8", 46 },
	{ "R003_NonPARENTHESES_9", 47 },
	{ "R003_StatementEle_0", 48 },
	{ "R003_StatementEle_1", 49 },
	{ "R003_StatementEle_2", 50 },
	{ "R003_StatementEle_3", 51 },
	{ "R003_StatementEle_4", 52 },
	{ "R003_StatementEle_5", 53 },
	{ "R003_StatementEle_6", 54 },
	{ "R003_StatementEle_7", 55 },
	{ "R003_StatementEle_8", 56 },
	{ "R003_StatementEle_9", 57 },
	{ "R003_StatementEle_10", 58 },
	{ "R003_StatementEle_11", 59 },
	{ "R003_StatementEle_12", 60 },
	{ "R003_StatementEle_13", 61 },
	{ "R003_StatementEle_14", 62 },
	{ "R003_StatementEle_15", 63 },
	{ "R003_StatementEle_16", 64 },
	{ "R003_StatementEle_17", 65 },
	{ "R003_StatementEle_18", 66 },
	{ "R003_StatementEle_19", 67 },
	{ "R003_StatementEle_20", 68 },
	{ "R003_StatementEle_21", 69 },
	{ "R003_StatementEle_22", 70 },
	{ "R003_StatementEle_23", 71 },
	{ "R003_StatementEle_24", 72 },
	{ "R003_StatementEle_25", 73 },
	{ "R003_StatementEle_26", 74 },
	{ "R003_StatementEle_27", 75 },
	{ "R003_StatementEle_28", 76 },
	{ "R003_StatementEle_29", 77 },
	{ "R003_StatementEle_30", 78 },
	{ "R003_StatementEle_31", 79 },
	{ "R003_StatementEle_32", 80 },
	{ "R003_StatementEle_33", 81 },
	{ "R003_StatementEle_34", 82 },
	{ "R003_StatementEle_35", 83 },
	{ "R003_StatementEle_36", 84 },
	{ "R003_StatementEle_37", 85 },
	{ "R003_StatementEle_38", 86 },
	{ "R003_StatementEle_39", 87 },
	{ "R003_StatementEle_40", 88 },
	{ "R003_StatementEle_41", 89 },
	{ "R003_StatementEle_42", 90 },
	{ "R003_StatementEle_43", 91 },
	{ "R003_StatementEle_44", 92 },
	{ "R003_StatementEle_45", 93 },
	{ "R003_StatementEle_46", 94 },
	{ "R003_StatementEle_47", 95 },
	{ "R003_StatementEle_48", 96 },
	{ "R003_StatementEle_49", 97 },
	{ "R003_StatementEle_50", 98 },
	{ "R003_StatementEle_51", 99 },
	{ "R003_StatementEle_52", 100 },
	{ "R003_StatementEle_53", 101 },
	{ "R003_StatementEle_54", 102 },
	{ "R003_StatementEle_55", 103 },
	{ "R003_StatementEle_56", 104 },
	{ "R003_StatementEle_57", 105 },
	{ "R003_StatementEle_58", 106 },
	{ "R003_StatementEle_59", 107 },
	{ "R003_StatementEle_60", 108 },
	{ "R003_StatementEle_61", 109 },
	{ "R003_StatementEle_62", 110 },
	{ "R003_StatementEle_63", 111 },
	{ "R003_StatementEle_64", 112 },
	{ "R003_StatementEle_65", 113 },
	{ "R003_StatementEle_66", 114 },
	{ "R003_StatementEle_67", 115 },
	{ "R003_StatementEle_68", 116 },
	{ "R003_StatementEle_69", 117 },
	{ "R003_StatementEle_70", 118 },
	{ "R003_StatementEle_71", 119 },
	{ "R003_StatementEle_72", 120 },
	{ "R003_StatementEle_73", 121 },
	{ "R003_StatementEle_74", 122 },
	{ "R003_StatementEle_75", 123 },
	{ "R003_StatementEle_76", 124 },
	{ "R003_StatementEle_77", 125 },
	{ "R003_StatementEle_78", 126 },
	{ "R003_StatementEle_79", 127 },
	{ "R003_StatementEle_80", 128 },
	{ "R003_Modifier_0", 129 },
	{ "R003_Modifier_1", 130 },
	{ "R003_Modifier_2", 131 },
	{ "R003_Modifier_3", 132 },
	{ "R003_Modifier_4", 133 },
	{ "R003_Modifier_5", 134 },
	{ "R003_Modifier_6", 135 },
	{ "R003_Modifier_7", 136 },
	{ "R003_Modifier_8", 137 },
	{ "R003_Modifier_9", 138 },
	{ "R003_Modifier_10", 139 },
	{ "R003_Modifier_11", 140 },
	{ "R003_MethodBody_0", 141 },
	{ "R003_MethodBody_1", 142 },
	{ "R003_Block_0", 143 },
	{ "R003_BlockStatements_0", 144 }
	};
}

P_SDT_genertor SDT_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key)>0) {
		return factory[key];
	}
	

	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R003_ele_begin_0"] = P_SDT_genertor(new R003_ele_begin_0Analyzer()); break;
	case 1: factory["R003_CompilationUnit_0"] = P_SDT_genertor(new R003_CompilationUnit_0Analyzer()); break;
	case 2: factory["R003_CompilationUnit_1"] = P_SDT_genertor(new R003_CompilationUnit_1Analyzer()); break;
	case 3: factory["R003_CompilationUnit_2"] = P_SDT_genertor(new R003_CompilationUnit_2Analyzer()); break;
	case 4: factory["R003_CompilationUnit_3"] = P_SDT_genertor(new R003_CompilationUnit_3Analyzer()); break;
	case 5: factory["R003_CompilationUnit_4"] = P_SDT_genertor(new R003_CompilationUnit_4Analyzer()); break;
	case 6: factory["R003_CompilationUnit_5"] = P_SDT_genertor(new R003_CompilationUnit_5Analyzer()); break;
	case 7: factory["R003_CompilationUnit_6"] = P_SDT_genertor(new R003_CompilationUnit_6Analyzer()); break;
	case 8: factory["R003_PackageDeclaration_0"] = P_SDT_genertor(new R003_PackageDeclaration_0Analyzer()); break;
	case 9: factory["R003_DetailIdentifier_0"] = P_SDT_genertor(new R003_DetailIdentifier_0Analyzer()); break;
	case 10: factory["R003_DetailIdentifier_1"] = P_SDT_genertor(new R003_DetailIdentifier_1Analyzer()); break;
	case 11: factory["R003_Identifier_0"] = P_SDT_genertor(new R003_Identifier_0Analyzer()); break;
	case 12: factory["R003_ImportDeclarationList_0"] = P_SDT_genertor(new R003_ImportDeclarationList_0Analyzer()); break;
	case 13: factory["R003_ImportDeclarationList_1"] = P_SDT_genertor(new R003_ImportDeclarationList_1Analyzer()); break;
	case 14: factory["R003_ImportDeclaration_0"] = P_SDT_genertor(new R003_ImportDeclaration_0Analyzer()); break;
	case 15: factory["R003_ImportDeclaration_1"] = P_SDT_genertor(new R003_ImportDeclaration_1Analyzer()); break;
	case 16: factory["R003_ImportDeclaration_2"] = P_SDT_genertor(new R003_ImportDeclaration_2Analyzer()); break;
	case 17: factory["R003_ImportDeclaration_3"] = P_SDT_genertor(new R003_ImportDeclaration_3Analyzer()); break;
	case 18: factory["R003_TypeDeclarationList_0"] = P_SDT_genertor(new R003_TypeDeclarationList_0Analyzer()); break;
	case 19: factory["R003_TypeDeclarationList_1"] = P_SDT_genertor(new R003_TypeDeclarationList_1Analyzer()); break;
	case 20: factory["R003_TypeDeclaration_0"] = P_SDT_genertor(new R003_TypeDeclaration_0Analyzer()); break;
	case 21: factory["R003_TypeDeclaration_1"] = P_SDT_genertor(new R003_TypeDeclaration_1Analyzer()); break;
	case 22: factory["R003_ClassDeclaration_0"] = P_SDT_genertor(new R003_ClassDeclaration_0Analyzer()); break;
	case 23: factory["R003_NormalClassDeclaration_0"] = P_SDT_genertor(new R003_NormalClassDeclaration_0Analyzer()); break;
	case 24: factory["R003_ClassBody_0"] = P_SDT_genertor(new R003_ClassBody_0Analyzer()); break;
	case 25: factory["R003_ClassBodyDeclarationList_0"] = P_SDT_genertor(new R003_ClassBodyDeclarationList_0Analyzer()); break;
	case 26: factory["R003_ClassBodyDeclarationList_1"] = P_SDT_genertor(new R003_ClassBodyDeclarationList_1Analyzer()); break;
	case 27: factory["R003_ClassBodyDeclaration_0"] = P_SDT_genertor(new R003_ClassBodyDeclaration_0Analyzer()); break;
	case 28: factory["R003_ClassMemberDeclaration_0"] = P_SDT_genertor(new R003_ClassMemberDeclaration_0Analyzer()); break;
	case 29: factory["R003_MethodDeclaration_0"] = P_SDT_genertor(new R003_MethodDeclaration_0Analyzer()); break;
	case 30: factory["R003_MethodDeclaration_1"] = P_SDT_genertor(new R003_MethodDeclaration_1Analyzer()); break;
	case 31: factory["R003_MethodHeader_0"] = P_SDT_genertor(new R003_MethodHeader_0Analyzer()); break;
	case 32: factory["R003_MethodDeclarator_0"] = P_SDT_genertor(new R003_MethodDeclarator_0Analyzer()); break;
	case 33: factory["R003_ModifierList_0"] = P_SDT_genertor(new R003_ModifierList_0Analyzer()); break;
	case 34: factory["R003_ModifierList_1"] = P_SDT_genertor(new R003_ModifierList_1Analyzer()); break;
	case 35: factory["R003_AnnotationContent_0"] = P_SDT_genertor(new R003_AnnotationContent_0Analyzer()); break;
	case 36: factory["R003_AnnotationContentStatements_0"] = P_SDT_genertor(new R003_AnnotationContentStatements_0Analyzer()); break;
	case 37: factory["R003_AnnotationContentStatements_1"] = P_SDT_genertor(new R003_AnnotationContentStatements_1Analyzer()); break;
	case 38: factory["R003_NonPARENTHESES_0"] = P_SDT_genertor(new R003_NonPARENTHESES_0Analyzer()); break;
	case 39: factory["R003_NonPARENTHESES_1"] = P_SDT_genertor(new R003_NonPARENTHESES_1Analyzer()); break;
	case 40: factory["R003_NonPARENTHESES_2"] = P_SDT_genertor(new R003_NonPARENTHESES_2Analyzer()); break;
	case 41: factory["R003_NonPARENTHESES_3"] = P_SDT_genertor(new R003_NonPARENTHESES_3Analyzer()); break;
	case 42: factory["R003_NonPARENTHESES_4"] = P_SDT_genertor(new R003_NonPARENTHESES_4Analyzer()); break;
	case 43: factory["R003_NonPARENTHESES_5"] = P_SDT_genertor(new R003_NonPARENTHESES_5Analyzer()); break;
	case 44: factory["R003_NonPARENTHESES_6"] = P_SDT_genertor(new R003_NonPARENTHESES_6Analyzer()); break;
	case 45: factory["R003_NonPARENTHESES_7"] = P_SDT_genertor(new R003_NonPARENTHESES_7Analyzer()); break;
	case 46: factory["R003_NonPARENTHESES_8"] = P_SDT_genertor(new R003_NonPARENTHESES_8Analyzer()); break;
	case 47: factory["R003_NonPARENTHESES_9"] = P_SDT_genertor(new R003_NonPARENTHESES_9Analyzer()); break;
	case 48: factory["R003_StatementEle_0"] = P_SDT_genertor(new R003_StatementEle_0Analyzer()); break;
	case 49: factory["R003_StatementEle_1"] = P_SDT_genertor(new R003_StatementEle_1Analyzer()); break;
	case 50: factory["R003_StatementEle_2"] = P_SDT_genertor(new R003_StatementEle_2Analyzer()); break;
	case 51: factory["R003_StatementEle_3"] = P_SDT_genertor(new R003_StatementEle_3Analyzer()); break;
	case 52: factory["R003_StatementEle_4"] = P_SDT_genertor(new R003_StatementEle_4Analyzer()); break;
	case 53: factory["R003_StatementEle_5"] = P_SDT_genertor(new R003_StatementEle_5Analyzer()); break;
	case 54: factory["R003_StatementEle_6"] = P_SDT_genertor(new R003_StatementEle_6Analyzer()); break;
	case 55: factory["R003_StatementEle_7"] = P_SDT_genertor(new R003_StatementEle_7Analyzer()); break;
	case 56: factory["R003_StatementEle_8"] = P_SDT_genertor(new R003_StatementEle_8Analyzer()); break;
	case 57: factory["R003_StatementEle_9"] = P_SDT_genertor(new R003_StatementEle_9Analyzer()); break;
	case 58: factory["R003_StatementEle_10"] = P_SDT_genertor(new R003_StatementEle_10Analyzer()); break;
	case 59: factory["R003_StatementEle_11"] = P_SDT_genertor(new R003_StatementEle_11Analyzer()); break;
	case 60: factory["R003_StatementEle_12"] = P_SDT_genertor(new R003_StatementEle_12Analyzer()); break;
	case 61: factory["R003_StatementEle_13"] = P_SDT_genertor(new R003_StatementEle_13Analyzer()); break;
	case 62: factory["R003_StatementEle_14"] = P_SDT_genertor(new R003_StatementEle_14Analyzer()); break;
	case 63: factory["R003_StatementEle_15"] = P_SDT_genertor(new R003_StatementEle_15Analyzer()); break;
	case 64: factory["R003_StatementEle_16"] = P_SDT_genertor(new R003_StatementEle_16Analyzer()); break;
	case 65: factory["R003_StatementEle_17"] = P_SDT_genertor(new R003_StatementEle_17Analyzer()); break;
	case 66: factory["R003_StatementEle_18"] = P_SDT_genertor(new R003_StatementEle_18Analyzer()); break;
	case 67: factory["R003_StatementEle_19"] = P_SDT_genertor(new R003_StatementEle_19Analyzer()); break;
	case 68: factory["R003_StatementEle_20"] = P_SDT_genertor(new R003_StatementEle_20Analyzer()); break;
	case 69: factory["R003_StatementEle_21"] = P_SDT_genertor(new R003_StatementEle_21Analyzer()); break;
	case 70: factory["R003_StatementEle_22"] = P_SDT_genertor(new R003_StatementEle_22Analyzer()); break;
	case 71: factory["R003_StatementEle_23"] = P_SDT_genertor(new R003_StatementEle_23Analyzer()); break;
	case 72: factory["R003_StatementEle_24"] = P_SDT_genertor(new R003_StatementEle_24Analyzer()); break;
	case 73: factory["R003_StatementEle_25"] = P_SDT_genertor(new R003_StatementEle_25Analyzer()); break;
	case 74: factory["R003_StatementEle_26"] = P_SDT_genertor(new R003_StatementEle_26Analyzer()); break;
	case 75: factory["R003_StatementEle_27"] = P_SDT_genertor(new R003_StatementEle_27Analyzer()); break;
	case 76: factory["R003_StatementEle_28"] = P_SDT_genertor(new R003_StatementEle_28Analyzer()); break;
	case 77: factory["R003_StatementEle_29"] = P_SDT_genertor(new R003_StatementEle_29Analyzer()); break;
	case 78: factory["R003_StatementEle_30"] = P_SDT_genertor(new R003_StatementEle_30Analyzer()); break;
	case 79: factory["R003_StatementEle_31"] = P_SDT_genertor(new R003_StatementEle_31Analyzer()); break;
	case 80: factory["R003_StatementEle_32"] = P_SDT_genertor(new R003_StatementEle_32Analyzer()); break;
	case 81: factory["R003_StatementEle_33"] = P_SDT_genertor(new R003_StatementEle_33Analyzer()); break;
	case 82: factory["R003_StatementEle_34"] = P_SDT_genertor(new R003_StatementEle_34Analyzer()); break;
	case 83: factory["R003_StatementEle_35"] = P_SDT_genertor(new R003_StatementEle_35Analyzer()); break;
	case 84: factory["R003_StatementEle_36"] = P_SDT_genertor(new R003_StatementEle_36Analyzer()); break;
	case 85: factory["R003_StatementEle_37"] = P_SDT_genertor(new R003_StatementEle_37Analyzer()); break;
	case 86: factory["R003_StatementEle_38"] = P_SDT_genertor(new R003_StatementEle_38Analyzer()); break;
	case 87: factory["R003_StatementEle_39"] = P_SDT_genertor(new R003_StatementEle_39Analyzer()); break;
	case 88: factory["R003_StatementEle_40"] = P_SDT_genertor(new R003_StatementEle_40Analyzer()); break;
	case 89: factory["R003_StatementEle_41"] = P_SDT_genertor(new R003_StatementEle_41Analyzer()); break;
	case 90: factory["R003_StatementEle_42"] = P_SDT_genertor(new R003_StatementEle_42Analyzer()); break;
	case 91: factory["R003_StatementEle_43"] = P_SDT_genertor(new R003_StatementEle_43Analyzer()); break;
	case 92: factory["R003_StatementEle_44"] = P_SDT_genertor(new R003_StatementEle_44Analyzer()); break;
	case 93: factory["R003_StatementEle_45"] = P_SDT_genertor(new R003_StatementEle_45Analyzer()); break;
	case 94: factory["R003_StatementEle_46"] = P_SDT_genertor(new R003_StatementEle_46Analyzer()); break;
	case 95: factory["R003_StatementEle_47"] = P_SDT_genertor(new R003_StatementEle_47Analyzer()); break;
	case 96: factory["R003_StatementEle_48"] = P_SDT_genertor(new R003_StatementEle_48Analyzer()); break;
	case 97: factory["R003_StatementEle_49"] = P_SDT_genertor(new R003_StatementEle_49Analyzer()); break;
	case 98: factory["R003_StatementEle_50"] = P_SDT_genertor(new R003_StatementEle_50Analyzer()); break;
	case 99: factory["R003_StatementEle_51"] = P_SDT_genertor(new R003_StatementEle_51Analyzer()); break;
	case 100: factory["R003_StatementEle_52"] = P_SDT_genertor(new R003_StatementEle_52Analyzer()); break;
	case 101: factory["R003_StatementEle_53"] = P_SDT_genertor(new R003_StatementEle_53Analyzer()); break;
	case 102: factory["R003_StatementEle_54"] = P_SDT_genertor(new R003_StatementEle_54Analyzer()); break;
	case 103: factory["R003_StatementEle_55"] = P_SDT_genertor(new R003_StatementEle_55Analyzer()); break;
	case 104: factory["R003_StatementEle_56"] = P_SDT_genertor(new R003_StatementEle_56Analyzer()); break;
	case 105: factory["R003_StatementEle_57"] = P_SDT_genertor(new R003_StatementEle_57Analyzer()); break;
	case 106: factory["R003_StatementEle_58"] = P_SDT_genertor(new R003_StatementEle_58Analyzer()); break;
	case 107: factory["R003_StatementEle_59"] = P_SDT_genertor(new R003_StatementEle_59Analyzer()); break;
	case 108: factory["R003_StatementEle_60"] = P_SDT_genertor(new R003_StatementEle_60Analyzer()); break;
	case 109: factory["R003_StatementEle_61"] = P_SDT_genertor(new R003_StatementEle_61Analyzer()); break;
	case 110: factory["R003_StatementEle_62"] = P_SDT_genertor(new R003_StatementEle_62Analyzer()); break;
	case 111: factory["R003_StatementEle_63"] = P_SDT_genertor(new R003_StatementEle_63Analyzer()); break;
	case 112: factory["R003_StatementEle_64"] = P_SDT_genertor(new R003_StatementEle_64Analyzer()); break;
	case 113: factory["R003_StatementEle_65"] = P_SDT_genertor(new R003_StatementEle_65Analyzer()); break;
	case 114: factory["R003_StatementEle_66"] = P_SDT_genertor(new R003_StatementEle_66Analyzer()); break;
	case 115: factory["R003_StatementEle_67"] = P_SDT_genertor(new R003_StatementEle_67Analyzer()); break;
	case 116: factory["R003_StatementEle_68"] = P_SDT_genertor(new R003_StatementEle_68Analyzer()); break;
	case 117: factory["R003_StatementEle_69"] = P_SDT_genertor(new R003_StatementEle_69Analyzer()); break;
	case 118: factory["R003_StatementEle_70"] = P_SDT_genertor(new R003_StatementEle_70Analyzer()); break;
	case 119: factory["R003_StatementEle_71"] = P_SDT_genertor(new R003_StatementEle_71Analyzer()); break;
	case 120: factory["R003_StatementEle_72"] = P_SDT_genertor(new R003_StatementEle_72Analyzer()); break;
	case 121: factory["R003_StatementEle_73"] = P_SDT_genertor(new R003_StatementEle_73Analyzer()); break;
	case 122: factory["R003_StatementEle_74"] = P_SDT_genertor(new R003_StatementEle_74Analyzer()); break;
	case 123: factory["R003_StatementEle_75"] = P_SDT_genertor(new R003_StatementEle_75Analyzer()); break;
	case 124: factory["R003_StatementEle_76"] = P_SDT_genertor(new R003_StatementEle_76Analyzer()); break;
	case 125: factory["R003_StatementEle_77"] = P_SDT_genertor(new R003_StatementEle_77Analyzer()); break;
	case 126: factory["R003_StatementEle_78"] = P_SDT_genertor(new R003_StatementEle_78Analyzer()); break;
	case 127: factory["R003_StatementEle_79"] = P_SDT_genertor(new R003_StatementEle_79Analyzer()); break;
	case 128: factory["R003_StatementEle_80"] = P_SDT_genertor(new R003_StatementEle_80Analyzer()); break;
	case 129: factory["R003_Modifier_0"] = P_SDT_genertor(new R003_Modifier_0Analyzer()); break;
	case 130: factory["R003_Modifier_1"] = P_SDT_genertor(new R003_Modifier_1Analyzer()); break;
	case 131: factory["R003_Modifier_2"] = P_SDT_genertor(new R003_Modifier_2Analyzer()); break;
	case 132: factory["R003_Modifier_3"] = P_SDT_genertor(new R003_Modifier_3Analyzer()); break;
	case 133: factory["R003_Modifier_4"] = P_SDT_genertor(new R003_Modifier_4Analyzer()); break;
	case 134: factory["R003_Modifier_5"] = P_SDT_genertor(new R003_Modifier_5Analyzer()); break;
	case 135: factory["R003_Modifier_6"] = P_SDT_genertor(new R003_Modifier_6Analyzer()); break;
	case 136: factory["R003_Modifier_7"] = P_SDT_genertor(new R003_Modifier_7Analyzer()); break;
	case 137: factory["R003_Modifier_8"] = P_SDT_genertor(new R003_Modifier_8Analyzer()); break;
	case 138: factory["R003_Modifier_9"] = P_SDT_genertor(new R003_Modifier_9Analyzer()); break;
	case 139: factory["R003_Modifier_10"] = P_SDT_genertor(new R003_Modifier_10Analyzer()); break;
	case 140: factory["R003_Modifier_11"] = P_SDT_genertor(new R003_Modifier_11Analyzer()); break;
	case 141: factory["R003_MethodBody_0"] = P_SDT_genertor(new R003_MethodBody_0Analyzer()); break;
	case 142: factory["R003_MethodBody_1"] = P_SDT_genertor(new R003_MethodBody_1Analyzer()); break;
	case 143: factory["R003_Block_0"] = P_SDT_genertor(new R003_Block_0Analyzer()); break;
	case 144: factory["R003_BlockStatements_0"] = P_SDT_genertor(new R003_BlockStatements_0Analyzer()); break;
	default:
		if (key.find("R003_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R003_DefaultAnalyzer());
			}
		};
	}



	return factory[key];
}
SDT_Factory::~SDT_Factory() {}


