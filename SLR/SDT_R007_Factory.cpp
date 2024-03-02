#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R007_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R007Analyzer.h"
using namespace std;
using namespace boost;



SDT_R007_Factory SDT_R007_Factory::instance;
SDT_R007_Factory::SDT_R007_Factory() {
	control_Param = {
   { "R007_ele_begin_0", 0 },
   { "R007_EnumFirstStatement_0", 1 },
   { "R007_EnumFirstStatement_1", 2 },
   { "R007_EnumConstantList_0", 3 },
   { "R007_EnumConstantList_1", 4 },
   { "R007_EnumConstant_0", 5 },
   { "R007_EnumConstant_1", 6 },
   { "R007_EnumConstant_2", 7 },
   { "R007_EnumConstant_3", 8 },
   { "R007_EnumConstant_4", 9 },
   { "R007_EnumConstant_5", 10 },
   { "R007_EnumConstant_6", 11 },
   { "R007_EnumConstant_7", 12 },
   { "R007_AnnotationList_0", 13 },
   { "R007_AnnotationList_1", 14 },
   { "R007_DetailIdentifier_0", 15 },
   { "R007_DetailIdentifier_1", 16 },
   { "R007_Annotation_0", 17 },
   { "R007_Annotation_1", 18 },
   { "R007_AnnotationContent_0", 19 },
   { "R007_AnnotationContentStatements_0", 20 },
   { "R007_AnnotationContentStatements_1", 21 },
   { "R007_NonPARENTHESES_0", 22 },
   { "R007_NonPARENTHESES_1", 23 },
   { "R007_NonPARENTHESES_2", 24 },
   { "R007_NonPARENTHESES_3", 25 },
   { "R007_NonPARENTHESES_4", 26 },
   { "R007_NonPARENTHESES_5", 27 },
   { "R007_NonPARENTHESES_6", 28 },
   { "R007_NonPARENTHESES_7", 29 },
   { "R007_NonPARENTHESES_8", 30 },
   { "R007_NonPARENTHESES_9", 31 },
   { "R007_NonPARENTHESES_10", 32 },
   { "R007_StatementEle_0", 33 },
   { "R007_StatementEle_1", 34 },
   { "R007_StatementEle_2", 35 },
   { "R007_StatementEle_3", 36 },
   { "R007_StatementEle_4", 37 },
   { "R007_StatementEle_5", 38 },
   { "R007_StatementEle_6", 39 },
   { "R007_StatementEle_7", 40 },
   { "R007_StatementEle_8", 41 },
   { "R007_StatementEle_9", 42 },
   { "R007_StatementEle_10", 43 },
   { "R007_StatementEle_11", 44 },
   { "R007_StatementEle_12", 45 },
   { "R007_StatementEle_13", 46 },
   { "R007_StatementEle_14", 47 },
   { "R007_StatementEle_15", 48 },
   { "R007_StatementEle_16", 49 },
   { "R007_StatementEle_17", 50 },
   { "R007_StatementEle_18", 51 },
   { "R007_StatementEle_19", 52 },
   { "R007_StatementEle_20", 53 },
   { "R007_StatementEle_21", 54 },
   { "R007_StatementEle_22", 55 },
   { "R007_StatementEle_23", 56 },
   { "R007_StatementEle_24", 57 },
   { "R007_StatementEle_25", 58 },
   { "R007_StatementEle_26", 59 },
   { "R007_StatementEle_27", 60 },
   { "R007_StatementEle_28", 61 },
   { "R007_StatementEle_29", 62 },
   { "R007_StatementEle_30", 63 },
   { "R007_StatementEle_31", 64 },
   { "R007_StatementEle_32", 65 },
   { "R007_StatementEle_33", 66 },
   { "R007_StatementEle_34", 67 },
   { "R007_StatementEle_35", 68 },
   { "R007_StatementEle_36", 69 },
   { "R007_StatementEle_37", 70 },
   { "R007_StatementEle_38", 71 },
   { "R007_StatementEle_39", 72 },
   { "R007_StatementEle_40", 73 },
   { "R007_StatementEle_41", 74 },
   { "R007_StatementEle_42", 75 },
   { "R007_StatementEle_43", 76 },
   { "R007_StatementEle_44", 77 },
   { "R007_StatementEle_45", 78 },
   { "R007_StatementEle_46", 79 },
   { "R007_StatementEle_47", 80 },
   { "R007_StatementEle_48", 81 },
   { "R007_StatementEle_49", 82 },
   { "R007_StatementEle_50", 83 },
   { "R007_StatementEle_51", 84 },
   { "R007_StatementEle_52", 85 },
   { "R007_StatementEle_53", 86 },
   { "R007_StatementEle_54", 87 },
   { "R007_StatementEle_55", 88 },
   { "R007_StatementEle_56", 89 },
   { "R007_StatementEle_57", 90 },
   { "R007_StatementEle_58", 91 },
   { "R007_StatementEle_59", 92 },
   { "R007_StatementEle_60", 93 },
   { "R007_StatementEle_61", 94 },
   { "R007_StatementEle_62", 95 },
   { "R007_StatementEle_63", 96 },
   { "R007_StatementEle_64", 97 },
   { "R007_StatementEle_65", 98 },
   { "R007_StatementEle_66", 99 },
   { "R007_StatementEle_67", 100 },
   { "R007_StatementEle_68", 101 },
   { "R007_StatementEle_69", 102 },
   { "R007_StatementEle_70", 103 },
   { "R007_StatementEle_71", 104 },
   { "R007_StatementEle_72", 105 },
   { "R007_StatementEle_73", 106 },
   { "R007_StatementEle_74", 107 },
   { "R007_StatementEle_75", 108 },
   { "R007_StatementEle_76", 109 },
   { "R007_StatementEle_77", 110 },
   { "R007_StatementEle_78", 111 },
   { "R007_StatementEle_79", 112 },
   { "R007_Identifier_0", 113 },
   { "R007_Block_0", 114 },
   { "R007_Block_1", 115 },
   { "R007_BlockStatements_0", 116 },
   { "R007_BlockStatements_1", 117 },
   { "R007_BlockStatements_2", 118 },
   { "R007_NonBrace_0", 119 },
   { "R007_NonBrace_1", 120 },
   { "R007_NonBrace_2", 121 },
   { "R007_NonBrace_3", 122 },
   { "R007_NonBrace_4", 123 },
   { "R007_NonBrace_5", 124 },
   { "R007_NonBrace_6", 125 },
   { "R007_NonBrace_7", 126 },
   { "R007_NonBrace_8", 127 },
   { "R007_NonBrace_9", 128 }
	};
}

P_SDT_genertor SDT_R007_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R007_ele_begin_0"] = P_SDT_genertor(new R007_ele_begin_0Analyzer()); break;
	case 1: factory["R007_EnumFirstStatement_0"] = P_SDT_genertor(new R007_EnumFirstStatement_0Analyzer()); break;
	case 2: factory["R007_EnumFirstStatement_1"] = P_SDT_genertor(new R007_EnumFirstStatement_1Analyzer()); break;
	case 3: factory["R007_EnumConstantList_0"] = P_SDT_genertor(new R007_EnumConstantList_0Analyzer()); break;
	case 4: factory["R007_EnumConstantList_1"] = P_SDT_genertor(new R007_EnumConstantList_1Analyzer()); break;
	case 5: factory["R007_EnumConstant_0"] = P_SDT_genertor(new R007_EnumConstant_0Analyzer()); break;
	case 6: factory["R007_EnumConstant_1"] = P_SDT_genertor(new R007_EnumConstant_1Analyzer()); break;
	case 7: factory["R007_EnumConstant_2"] = P_SDT_genertor(new R007_EnumConstant_2Analyzer()); break;
	case 8: factory["R007_EnumConstant_3"] = P_SDT_genertor(new R007_EnumConstant_3Analyzer()); break;
	case 9: factory["R007_EnumConstant_4"] = P_SDT_genertor(new R007_EnumConstant_4Analyzer()); break;
	case 10: factory["R007_EnumConstant_5"] = P_SDT_genertor(new R007_EnumConstant_5Analyzer()); break;
	case 11: factory["R007_EnumConstant_6"] = P_SDT_genertor(new R007_EnumConstant_6Analyzer()); break;
	case 12: factory["R007_EnumConstant_7"] = P_SDT_genertor(new R007_EnumConstant_7Analyzer()); break;
	case 13: factory["R007_AnnotationList_0"] = P_SDT_genertor(new R007_AnnotationList_0Analyzer()); break;
	case 14: factory["R007_AnnotationList_1"] = P_SDT_genertor(new R007_AnnotationList_1Analyzer()); break;
	case 15: factory["R007_DetailIdentifier_0"] = P_SDT_genertor(new R007_DetailIdentifier_0Analyzer()); break;
	case 16: factory["R007_DetailIdentifier_1"] = P_SDT_genertor(new R007_DetailIdentifier_1Analyzer()); break;
	case 17: factory["R007_Annotation_0"] = P_SDT_genertor(new R007_Annotation_0Analyzer()); break;
	case 18: factory["R007_Annotation_1"] = P_SDT_genertor(new R007_Annotation_1Analyzer()); break;
	case 19: factory["R007_AnnotationContent_0"] = P_SDT_genertor(new R007_AnnotationContent_0Analyzer()); break;
	case 20: factory["R007_AnnotationContentStatements_0"] = P_SDT_genertor(new R007_AnnotationContentStatements_0Analyzer()); break;
	case 21: factory["R007_AnnotationContentStatements_1"] = P_SDT_genertor(new R007_AnnotationContentStatements_1Analyzer()); break;
	case 22: factory["R007_NonPARENTHESES_0"] = P_SDT_genertor(new R007_NonPARENTHESES_0Analyzer()); break;
	case 23: factory["R007_NonPARENTHESES_1"] = P_SDT_genertor(new R007_NonPARENTHESES_1Analyzer()); break;
	case 24: factory["R007_NonPARENTHESES_2"] = P_SDT_genertor(new R007_NonPARENTHESES_2Analyzer()); break;
	case 25: factory["R007_NonPARENTHESES_3"] = P_SDT_genertor(new R007_NonPARENTHESES_3Analyzer()); break;
	case 26: factory["R007_NonPARENTHESES_4"] = P_SDT_genertor(new R007_NonPARENTHESES_4Analyzer()); break;
	case 27: factory["R007_NonPARENTHESES_5"] = P_SDT_genertor(new R007_NonPARENTHESES_5Analyzer()); break;
	case 28: factory["R007_NonPARENTHESES_6"] = P_SDT_genertor(new R007_NonPARENTHESES_6Analyzer()); break;
	case 29: factory["R007_NonPARENTHESES_7"] = P_SDT_genertor(new R007_NonPARENTHESES_7Analyzer()); break;
	case 30: factory["R007_NonPARENTHESES_8"] = P_SDT_genertor(new R007_NonPARENTHESES_8Analyzer()); break;
	case 31: factory["R007_NonPARENTHESES_9"] = P_SDT_genertor(new R007_NonPARENTHESES_9Analyzer()); break;
	case 32: factory["R007_NonPARENTHESES_10"] = P_SDT_genertor(new R007_NonPARENTHESES_10Analyzer()); break;
	case 33: factory["R007_StatementEle_0"] = P_SDT_genertor(new R007_StatementEle_0Analyzer()); break;
	case 34: factory["R007_StatementEle_1"] = P_SDT_genertor(new R007_StatementEle_1Analyzer()); break;
	case 35: factory["R007_StatementEle_2"] = P_SDT_genertor(new R007_StatementEle_2Analyzer()); break;
	case 36: factory["R007_StatementEle_3"] = P_SDT_genertor(new R007_StatementEle_3Analyzer()); break;
	case 37: factory["R007_StatementEle_4"] = P_SDT_genertor(new R007_StatementEle_4Analyzer()); break;
	case 38: factory["R007_StatementEle_5"] = P_SDT_genertor(new R007_StatementEle_5Analyzer()); break;
	case 39: factory["R007_StatementEle_6"] = P_SDT_genertor(new R007_StatementEle_6Analyzer()); break;
	case 40: factory["R007_StatementEle_7"] = P_SDT_genertor(new R007_StatementEle_7Analyzer()); break;
	case 41: factory["R007_StatementEle_8"] = P_SDT_genertor(new R007_StatementEle_8Analyzer()); break;
	case 42: factory["R007_StatementEle_9"] = P_SDT_genertor(new R007_StatementEle_9Analyzer()); break;
	case 43: factory["R007_StatementEle_10"] = P_SDT_genertor(new R007_StatementEle_10Analyzer()); break;
	case 44: factory["R007_StatementEle_11"] = P_SDT_genertor(new R007_StatementEle_11Analyzer()); break;
	case 45: factory["R007_StatementEle_12"] = P_SDT_genertor(new R007_StatementEle_12Analyzer()); break;
	case 46: factory["R007_StatementEle_13"] = P_SDT_genertor(new R007_StatementEle_13Analyzer()); break;
	case 47: factory["R007_StatementEle_14"] = P_SDT_genertor(new R007_StatementEle_14Analyzer()); break;
	case 48: factory["R007_StatementEle_15"] = P_SDT_genertor(new R007_StatementEle_15Analyzer()); break;
	case 49: factory["R007_StatementEle_16"] = P_SDT_genertor(new R007_StatementEle_16Analyzer()); break;
	case 50: factory["R007_StatementEle_17"] = P_SDT_genertor(new R007_StatementEle_17Analyzer()); break;
	case 51: factory["R007_StatementEle_18"] = P_SDT_genertor(new R007_StatementEle_18Analyzer()); break;
	case 52: factory["R007_StatementEle_19"] = P_SDT_genertor(new R007_StatementEle_19Analyzer()); break;
	case 53: factory["R007_StatementEle_20"] = P_SDT_genertor(new R007_StatementEle_20Analyzer()); break;
	case 54: factory["R007_StatementEle_21"] = P_SDT_genertor(new R007_StatementEle_21Analyzer()); break;
	case 55: factory["R007_StatementEle_22"] = P_SDT_genertor(new R007_StatementEle_22Analyzer()); break;
	case 56: factory["R007_StatementEle_23"] = P_SDT_genertor(new R007_StatementEle_23Analyzer()); break;
	case 57: factory["R007_StatementEle_24"] = P_SDT_genertor(new R007_StatementEle_24Analyzer()); break;
	case 58: factory["R007_StatementEle_25"] = P_SDT_genertor(new R007_StatementEle_25Analyzer()); break;
	case 59: factory["R007_StatementEle_26"] = P_SDT_genertor(new R007_StatementEle_26Analyzer()); break;
	case 60: factory["R007_StatementEle_27"] = P_SDT_genertor(new R007_StatementEle_27Analyzer()); break;
	case 61: factory["R007_StatementEle_28"] = P_SDT_genertor(new R007_StatementEle_28Analyzer()); break;
	case 62: factory["R007_StatementEle_29"] = P_SDT_genertor(new R007_StatementEle_29Analyzer()); break;
	case 63: factory["R007_StatementEle_30"] = P_SDT_genertor(new R007_StatementEle_30Analyzer()); break;
	case 64: factory["R007_StatementEle_31"] = P_SDT_genertor(new R007_StatementEle_31Analyzer()); break;
	case 65: factory["R007_StatementEle_32"] = P_SDT_genertor(new R007_StatementEle_32Analyzer()); break;
	case 66: factory["R007_StatementEle_33"] = P_SDT_genertor(new R007_StatementEle_33Analyzer()); break;
	case 67: factory["R007_StatementEle_34"] = P_SDT_genertor(new R007_StatementEle_34Analyzer()); break;
	case 68: factory["R007_StatementEle_35"] = P_SDT_genertor(new R007_StatementEle_35Analyzer()); break;
	case 69: factory["R007_StatementEle_36"] = P_SDT_genertor(new R007_StatementEle_36Analyzer()); break;
	case 70: factory["R007_StatementEle_37"] = P_SDT_genertor(new R007_StatementEle_37Analyzer()); break;
	case 71: factory["R007_StatementEle_38"] = P_SDT_genertor(new R007_StatementEle_38Analyzer()); break;
	case 72: factory["R007_StatementEle_39"] = P_SDT_genertor(new R007_StatementEle_39Analyzer()); break;
	case 73: factory["R007_StatementEle_40"] = P_SDT_genertor(new R007_StatementEle_40Analyzer()); break;
	case 74: factory["R007_StatementEle_41"] = P_SDT_genertor(new R007_StatementEle_41Analyzer()); break;
	case 75: factory["R007_StatementEle_42"] = P_SDT_genertor(new R007_StatementEle_42Analyzer()); break;
	case 76: factory["R007_StatementEle_43"] = P_SDT_genertor(new R007_StatementEle_43Analyzer()); break;
	case 77: factory["R007_StatementEle_44"] = P_SDT_genertor(new R007_StatementEle_44Analyzer()); break;
	case 78: factory["R007_StatementEle_45"] = P_SDT_genertor(new R007_StatementEle_45Analyzer()); break;
	case 79: factory["R007_StatementEle_46"] = P_SDT_genertor(new R007_StatementEle_46Analyzer()); break;
	case 80: factory["R007_StatementEle_47"] = P_SDT_genertor(new R007_StatementEle_47Analyzer()); break;
	case 81: factory["R007_StatementEle_48"] = P_SDT_genertor(new R007_StatementEle_48Analyzer()); break;
	case 82: factory["R007_StatementEle_49"] = P_SDT_genertor(new R007_StatementEle_49Analyzer()); break;
	case 83: factory["R007_StatementEle_50"] = P_SDT_genertor(new R007_StatementEle_50Analyzer()); break;
	case 84: factory["R007_StatementEle_51"] = P_SDT_genertor(new R007_StatementEle_51Analyzer()); break;
	case 85: factory["R007_StatementEle_52"] = P_SDT_genertor(new R007_StatementEle_52Analyzer()); break;
	case 86: factory["R007_StatementEle_53"] = P_SDT_genertor(new R007_StatementEle_53Analyzer()); break;
	case 87: factory["R007_StatementEle_54"] = P_SDT_genertor(new R007_StatementEle_54Analyzer()); break;
	case 88: factory["R007_StatementEle_55"] = P_SDT_genertor(new R007_StatementEle_55Analyzer()); break;
	case 89: factory["R007_StatementEle_56"] = P_SDT_genertor(new R007_StatementEle_56Analyzer()); break;
	case 90: factory["R007_StatementEle_57"] = P_SDT_genertor(new R007_StatementEle_57Analyzer()); break;
	case 91: factory["R007_StatementEle_58"] = P_SDT_genertor(new R007_StatementEle_58Analyzer()); break;
	case 92: factory["R007_StatementEle_59"] = P_SDT_genertor(new R007_StatementEle_59Analyzer()); break;
	case 93: factory["R007_StatementEle_60"] = P_SDT_genertor(new R007_StatementEle_60Analyzer()); break;
	case 94: factory["R007_StatementEle_61"] = P_SDT_genertor(new R007_StatementEle_61Analyzer()); break;
	case 95: factory["R007_StatementEle_62"] = P_SDT_genertor(new R007_StatementEle_62Analyzer()); break;
	case 96: factory["R007_StatementEle_63"] = P_SDT_genertor(new R007_StatementEle_63Analyzer()); break;
	case 97: factory["R007_StatementEle_64"] = P_SDT_genertor(new R007_StatementEle_64Analyzer()); break;
	case 98: factory["R007_StatementEle_65"] = P_SDT_genertor(new R007_StatementEle_65Analyzer()); break;
	case 99: factory["R007_StatementEle_66"] = P_SDT_genertor(new R007_StatementEle_66Analyzer()); break;
	case 100: factory["R007_StatementEle_67"] = P_SDT_genertor(new R007_StatementEle_67Analyzer()); break;
	case 101: factory["R007_StatementEle_68"] = P_SDT_genertor(new R007_StatementEle_68Analyzer()); break;
	case 102: factory["R007_StatementEle_69"] = P_SDT_genertor(new R007_StatementEle_69Analyzer()); break;
	case 103: factory["R007_StatementEle_70"] = P_SDT_genertor(new R007_StatementEle_70Analyzer()); break;
	case 104: factory["R007_StatementEle_71"] = P_SDT_genertor(new R007_StatementEle_71Analyzer()); break;
	case 105: factory["R007_StatementEle_72"] = P_SDT_genertor(new R007_StatementEle_72Analyzer()); break;
	case 106: factory["R007_StatementEle_73"] = P_SDT_genertor(new R007_StatementEle_73Analyzer()); break;
	case 107: factory["R007_StatementEle_74"] = P_SDT_genertor(new R007_StatementEle_74Analyzer()); break;
	case 108: factory["R007_StatementEle_75"] = P_SDT_genertor(new R007_StatementEle_75Analyzer()); break;
	case 109: factory["R007_StatementEle_76"] = P_SDT_genertor(new R007_StatementEle_76Analyzer()); break;
	case 110: factory["R007_StatementEle_77"] = P_SDT_genertor(new R007_StatementEle_77Analyzer()); break;
	case 111: factory["R007_StatementEle_78"] = P_SDT_genertor(new R007_StatementEle_78Analyzer()); break;
	case 112: factory["R007_StatementEle_79"] = P_SDT_genertor(new R007_StatementEle_79Analyzer()); break;
	case 113: factory["R007_Identifier_0"] = P_SDT_genertor(new R007_Identifier_0Analyzer()); break;
	case 114: factory["R007_Block_0"] = P_SDT_genertor(new R007_Block_0Analyzer()); break;
	case 115: factory["R007_Block_1"] = P_SDT_genertor(new R007_Block_1Analyzer()); break;
	case 116: factory["R007_BlockStatements_0"] = P_SDT_genertor(new R007_BlockStatements_0Analyzer()); break;
	case 117: factory["R007_BlockStatements_1"] = P_SDT_genertor(new R007_BlockStatements_1Analyzer()); break;
	case 118: factory["R007_BlockStatements_2"] = P_SDT_genertor(new R007_BlockStatements_2Analyzer()); break;
	case 119: factory["R007_NonBrace_0"] = P_SDT_genertor(new R007_NonBrace_0Analyzer()); break;
	case 120: factory["R007_NonBrace_1"] = P_SDT_genertor(new R007_NonBrace_1Analyzer()); break;
	case 121: factory["R007_NonBrace_2"] = P_SDT_genertor(new R007_NonBrace_2Analyzer()); break;
	case 122: factory["R007_NonBrace_3"] = P_SDT_genertor(new R007_NonBrace_3Analyzer()); break;
	case 123: factory["R007_NonBrace_4"] = P_SDT_genertor(new R007_NonBrace_4Analyzer()); break;
	case 124: factory["R007_NonBrace_5"] = P_SDT_genertor(new R007_NonBrace_5Analyzer()); break;
	case 125: factory["R007_NonBrace_6"] = P_SDT_genertor(new R007_NonBrace_6Analyzer()); break;
	case 126: factory["R007_NonBrace_7"] = P_SDT_genertor(new R007_NonBrace_7Analyzer()); break;
	case 127: factory["R007_NonBrace_8"] = P_SDT_genertor(new R007_NonBrace_8Analyzer()); break;
	case 128: factory["R007_NonBrace_9"] = P_SDT_genertor(new R007_NonBrace_9Analyzer()); break;
	default:

		if (key.find("R007_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R007_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R007_Factory::~SDT_R007_Factory() {}
