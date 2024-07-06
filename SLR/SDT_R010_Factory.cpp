#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R010_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R010Analyzer.h"
using namespace std;
using namespace boost;



SDT_R010_Factory SDT_R010_Factory::instance;
SDT_R010_Factory::SDT_R010_Factory() {
	control_Param = {
   { "R010_ele_begin_0", 0 },
   { "R010_TypeParameters_0", 1 },
   { "R010_TypeParameterList_0", 2 },
   { "R010_TypeParameterList_1", 3 },
   { "R010_TypeParameter_0", 4 },
   { "R010_TypeParameter_1", 5 },
   { "R010_TypeParameter_2", 6 },
   { "R010_TypeParameter_3", 7 },
   { "R010_TypeBound_0", 8 },
   { "R010_AdditionalBoundList_0", 9 },
   { "R010_AdditionalBoundList_1", 10 },
   { "R010_ReferenceType_0", 11 },
   { "R010_ReferenceType_1", 12 },
   { "R010_ClassTypeEle_0", 13 },
   { "R010_ClassTypeEle_1", 14 },
   { "R010_ClassTypeEle_2", 15 },
   { "R010_ClassTypeEle_3", 16 },
   { "R010_ClassType_0", 17 },
   { "R010_ClassType_1", 18 },
   { "R010_Dims_0", 19 },
   { "R010_Dims_1", 20 },
   { "R010_Dims_2", 21 },
   { "R010_Dims_3", 22 },
   { "R010_TypeArguments_0", 23 },
   { "R010_TypeArgumentList_0", 24 },
   { "R010_TypeArgumentList_1", 25 },
   { "R010_TypeArgument_0", 26 },
   { "R010_TypeArgument_1", 27 },
   { "R010_Wildcard_0", 28 },
   { "R010_Wildcard_1", 29 },
   { "R010_Wildcard_2", 30 },
   { "R010_Wildcard_3", 31 },
   { "R010_WildcardBounds_0", 32 },
   { "R010_WildcardBounds_1", 33 },
   { "R010_Identifier_0", 34 },
   { "R010_AnnotationList_0", 35 },
   { "R010_AnnotationList_1", 36 },
   { "R010_AnnotationContent_0", 37 },
   { "R010_AnnotationContentStatements_0", 38 },
   { "R010_AnnotationContentStatements_1", 39 },
   { "R010_NonPARENTHESES_0", 40 },
   { "R010_NonPARENTHESES_1", 41 },
   { "R010_NonPARENTHESES_2", 42 },
   { "R010_NonPARENTHESES_3", 43 },
   { "R010_NonPARENTHESES_4", 44 },
   { "R010_NonPARENTHESES_5", 45 },
   { "R010_NonPARENTHESES_6", 46 },
   { "R010_NonPARENTHESES_7", 47 },
   { "R010_NonPARENTHESES_8", 48 },
   { "R010_NonPARENTHESES_9", 49 },
   { "R010_NonPARENTHESES_10", 50 },
   { "R010_StatementEle_0", 51 },
   { "R010_StatementEle_1", 52 },
   { "R010_StatementEle_2", 53 },
   { "R010_StatementEle_3", 54 },
   { "R010_StatementEle_4", 55 },
   { "R010_StatementEle_5", 56 },
   { "R010_StatementEle_6", 57 },
   { "R010_StatementEle_7", 58 },
   { "R010_StatementEle_8", 59 },
   { "R010_StatementEle_9", 60 },
   { "R010_StatementEle_10", 61 },
   { "R010_StatementEle_11", 62 },
   { "R010_StatementEle_12", 63 },
   { "R010_StatementEle_13", 64 },
   { "R010_StatementEle_14", 65 },
   { "R010_StatementEle_15", 66 },
   { "R010_StatementEle_16", 67 },
   { "R010_StatementEle_17", 68 },
   { "R010_StatementEle_18", 69 },
   { "R010_StatementEle_19", 70 },
   { "R010_StatementEle_20", 71 },
   { "R010_StatementEle_21", 72 },
   { "R010_StatementEle_22", 73 },
   { "R010_StatementEle_23", 74 },
   { "R010_StatementEle_24", 75 },
   { "R010_StatementEle_25", 76 },
   { "R010_StatementEle_26", 77 },
   { "R010_StatementEle_27", 78 },
   { "R010_StatementEle_28", 79 },
   { "R010_StatementEle_29", 80 },
   { "R010_StatementEle_30", 81 },
   { "R010_StatementEle_31", 82 },
   { "R010_StatementEle_32", 83 },
   { "R010_StatementEle_33", 84 },
   { "R010_StatementEle_34", 85 },
   { "R010_StatementEle_35", 86 },
   { "R010_StatementEle_36", 87 },
   { "R010_StatementEle_37", 88 },
   { "R010_StatementEle_38", 89 },
   { "R010_StatementEle_39", 90 },
   { "R010_StatementEle_40", 91 },
   { "R010_StatementEle_41", 92 },
   { "R010_StatementEle_42", 93 },
   { "R010_StatementEle_43", 94 },
   { "R010_StatementEle_44", 95 },
   { "R010_StatementEle_45", 96 },
   { "R010_StatementEle_46", 97 },
   { "R010_StatementEle_47", 98 },
   { "R010_StatementEle_48", 99 },
   { "R010_StatementEle_49", 100 },
   { "R010_StatementEle_50", 101 },
   { "R010_StatementEle_51", 102 },
   { "R010_StatementEle_52", 103 },
   { "R010_StatementEle_53", 104 },
   { "R010_StatementEle_54", 105 },
   { "R010_StatementEle_55", 106 },
   { "R010_StatementEle_56", 107 },
   { "R010_StatementEle_57", 108 },
   { "R010_StatementEle_58", 109 },
   { "R010_StatementEle_59", 110 },
   { "R010_StatementEle_60", 111 },
   { "R010_StatementEle_61", 112 },
   { "R010_StatementEle_62", 113 },
   { "R010_StatementEle_63", 114 },
   { "R010_StatementEle_64", 115 },
   { "R010_StatementEle_65", 116 },
   { "R010_StatementEle_66", 117 },
   { "R010_StatementEle_67", 118 },
   { "R010_StatementEle_68", 119 },
   { "R010_StatementEle_69", 120 },
   { "R010_StatementEle_70", 121 },
   { "R010_StatementEle_71", 122 },
   { "R010_StatementEle_72", 123 },
   { "R010_StatementEle_73", 124 },
   { "R010_StatementEle_74", 125 },
   { "R010_StatementEle_75", 126 },
   { "R010_StatementEle_76", 127 },
   { "R010_StatementEle_77", 128 },
   { "R010_StatementEle_78", 129 },
   { "R010_StatementEle_79", 130 },
   { "R010_StatementEle_80", 131 },
	};
}

P_SDT_genertor SDT_R010_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R010_ele_begin_0"] = P_SDT_genertor(new R010_ele_begin_0Analyzer()); break;
	case 1: factory["R010_TypeParameters_0"] = P_SDT_genertor(new R010_TypeParameters_0Analyzer()); break;
	case 2: factory["R010_TypeParameterList_0"] = P_SDT_genertor(new R010_TypeParameterList_0Analyzer()); break;
	case 3: factory["R010_TypeParameterList_1"] = P_SDT_genertor(new R010_TypeParameterList_1Analyzer()); break;
	case 4: factory["R010_TypeParameter_0"] = P_SDT_genertor(new R010_TypeParameter_0Analyzer()); break;
	case 5: factory["R010_TypeParameter_1"] = P_SDT_genertor(new R010_TypeParameter_1Analyzer()); break;
	case 6: factory["R010_TypeParameter_2"] = P_SDT_genertor(new R010_TypeParameter_2Analyzer()); break;
	case 7: factory["R010_TypeParameter_3"] = P_SDT_genertor(new R010_TypeParameter_3Analyzer()); break;
	case 8: factory["R010_TypeBound_0"] = P_SDT_genertor(new R010_TypeBound_0Analyzer()); break;
	case 9: factory["R010_AdditionalBoundList_0"] = P_SDT_genertor(new R010_AdditionalBoundList_0Analyzer()); break;
	case 10: factory["R010_AdditionalBoundList_1"] = P_SDT_genertor(new R010_AdditionalBoundList_1Analyzer()); break;
	case 11: factory["R010_ReferenceType_0"] = P_SDT_genertor(new R010_ReferenceType_0Analyzer()); break;
	case 12: factory["R010_ReferenceType_1"] = P_SDT_genertor(new R010_ReferenceType_1Analyzer()); break;
	case 13: factory["R010_ClassTypeEle_0"] = P_SDT_genertor(new R010_ClassTypeEle_0Analyzer()); break;
	case 14: factory["R010_ClassTypeEle_1"] = P_SDT_genertor(new R010_ClassTypeEle_1Analyzer()); break;
	case 15: factory["R010_ClassTypeEle_2"] = P_SDT_genertor(new R010_ClassTypeEle_2Analyzer()); break;
	case 16: factory["R010_ClassTypeEle_3"] = P_SDT_genertor(new R010_ClassTypeEle_3Analyzer()); break;
	case 17: factory["R010_ClassType_0"] = P_SDT_genertor(new R010_ClassType_0Analyzer()); break;
	case 18: factory["R010_ClassType_1"] = P_SDT_genertor(new R010_ClassType_1Analyzer()); break;
	case 19: factory["R010_Dims_0"] = P_SDT_genertor(new R010_Dims_0Analyzer()); break;
	case 20: factory["R010_Dims_1"] = P_SDT_genertor(new R010_Dims_1Analyzer()); break;
	case 21: factory["R010_Dims_2"] = P_SDT_genertor(new R010_Dims_2Analyzer()); break;
	case 22: factory["R010_Dims_3"] = P_SDT_genertor(new R010_Dims_3Analyzer()); break;
	case 23: factory["R010_TypeArguments_0"] = P_SDT_genertor(new R010_TypeArguments_0Analyzer()); break;
	case 24: factory["R010_TypeArgumentList_0"] = P_SDT_genertor(new R010_TypeArgumentList_0Analyzer()); break;
	case 25: factory["R010_TypeArgumentList_1"] = P_SDT_genertor(new R010_TypeArgumentList_1Analyzer()); break;
	case 26: factory["R010_TypeArgument_0"] = P_SDT_genertor(new R010_TypeArgument_0Analyzer()); break;
	case 27: factory["R010_TypeArgument_1"] = P_SDT_genertor(new R010_TypeArgument_1Analyzer()); break;
	case 28: factory["R010_Wildcard_0"] = P_SDT_genertor(new R010_Wildcard_0Analyzer()); break;
	case 29: factory["R010_Wildcard_1"] = P_SDT_genertor(new R010_Wildcard_1Analyzer()); break;
	case 30: factory["R010_Wildcard_2"] = P_SDT_genertor(new R010_Wildcard_2Analyzer()); break;
	case 31: factory["R010_Wildcard_3"] = P_SDT_genertor(new R010_Wildcard_3Analyzer()); break;
	case 32: factory["R010_WildcardBounds_0"] = P_SDT_genertor(new R010_WildcardBounds_0Analyzer()); break;
	case 33: factory["R010_WildcardBounds_1"] = P_SDT_genertor(new R010_WildcardBounds_1Analyzer()); break;
	case 34: factory["R010_Identifier_0"] = P_SDT_genertor(new R010_Identifier_0Analyzer()); break;
	case 35: factory["R010_AnnotationList_0"] = P_SDT_genertor(new R010_AnnotationList_0Analyzer()); break;
	case 36: factory["R010_AnnotationList_1"] = P_SDT_genertor(new R010_AnnotationList_1Analyzer()); break;
	case 37: factory["R010_AnnotationContent_0"] = P_SDT_genertor(new R010_AnnotationContent_0Analyzer()); break;
	case 38: factory["R010_AnnotationContentStatements_0"] = P_SDT_genertor(new R010_AnnotationContentStatements_0Analyzer()); break;
	case 39: factory["R010_AnnotationContentStatements_1"] = P_SDT_genertor(new R010_AnnotationContentStatements_1Analyzer()); break;
	case 40: factory["R010_NonPARENTHESES_0"] = P_SDT_genertor(new R010_NonPARENTHESES_0Analyzer()); break;
	case 41: factory["R010_NonPARENTHESES_1"] = P_SDT_genertor(new R010_NonPARENTHESES_1Analyzer()); break;
	case 42: factory["R010_NonPARENTHESES_2"] = P_SDT_genertor(new R010_NonPARENTHESES_2Analyzer()); break;
	case 43: factory["R010_NonPARENTHESES_3"] = P_SDT_genertor(new R010_NonPARENTHESES_3Analyzer()); break;
	case 44: factory["R010_NonPARENTHESES_4"] = P_SDT_genertor(new R010_NonPARENTHESES_4Analyzer()); break;
	case 45: factory["R010_NonPARENTHESES_5"] = P_SDT_genertor(new R010_NonPARENTHESES_5Analyzer()); break;
	case 46: factory["R010_NonPARENTHESES_6"] = P_SDT_genertor(new R010_NonPARENTHESES_6Analyzer()); break;
	case 47: factory["R010_NonPARENTHESES_7"] = P_SDT_genertor(new R010_NonPARENTHESES_7Analyzer()); break;
	case 48: factory["R010_NonPARENTHESES_8"] = P_SDT_genertor(new R010_NonPARENTHESES_8Analyzer()); break;
	case 49: factory["R010_NonPARENTHESES_9"] = P_SDT_genertor(new R010_NonPARENTHESES_9Analyzer()); break;
	case 50: factory["R010_NonPARENTHESES_10"] = P_SDT_genertor(new R010_NonPARENTHESES_10Analyzer()); break;
	case 51: factory["R010_StatementEle_0"] = P_SDT_genertor(new R010_StatementEle_0Analyzer()); break;
	case 52: factory["R010_StatementEle_1"] = P_SDT_genertor(new R010_StatementEle_1Analyzer()); break;
	case 53: factory["R010_StatementEle_2"] = P_SDT_genertor(new R010_StatementEle_2Analyzer()); break;
	case 54: factory["R010_StatementEle_3"] = P_SDT_genertor(new R010_StatementEle_3Analyzer()); break;
	case 55: factory["R010_StatementEle_4"] = P_SDT_genertor(new R010_StatementEle_4Analyzer()); break;
	case 56: factory["R010_StatementEle_5"] = P_SDT_genertor(new R010_StatementEle_5Analyzer()); break;
	case 57: factory["R010_StatementEle_6"] = P_SDT_genertor(new R010_StatementEle_6Analyzer()); break;
	case 58: factory["R010_StatementEle_7"] = P_SDT_genertor(new R010_StatementEle_7Analyzer()); break;
	case 59: factory["R010_StatementEle_8"] = P_SDT_genertor(new R010_StatementEle_8Analyzer()); break;
	case 60: factory["R010_StatementEle_9"] = P_SDT_genertor(new R010_StatementEle_9Analyzer()); break;
	case 61: factory["R010_StatementEle_10"] = P_SDT_genertor(new R010_StatementEle_10Analyzer()); break;
	case 62: factory["R010_StatementEle_11"] = P_SDT_genertor(new R010_StatementEle_11Analyzer()); break;
	case 63: factory["R010_StatementEle_12"] = P_SDT_genertor(new R010_StatementEle_12Analyzer()); break;
	case 64: factory["R010_StatementEle_13"] = P_SDT_genertor(new R010_StatementEle_13Analyzer()); break;
	case 65: factory["R010_StatementEle_14"] = P_SDT_genertor(new R010_StatementEle_14Analyzer()); break;
	case 66: factory["R010_StatementEle_15"] = P_SDT_genertor(new R010_StatementEle_15Analyzer()); break;
	case 67: factory["R010_StatementEle_16"] = P_SDT_genertor(new R010_StatementEle_16Analyzer()); break;
	case 68: factory["R010_StatementEle_17"] = P_SDT_genertor(new R010_StatementEle_17Analyzer()); break;
	case 69: factory["R010_StatementEle_18"] = P_SDT_genertor(new R010_StatementEle_18Analyzer()); break;
	case 70: factory["R010_StatementEle_19"] = P_SDT_genertor(new R010_StatementEle_19Analyzer()); break;
	case 71: factory["R010_StatementEle_20"] = P_SDT_genertor(new R010_StatementEle_20Analyzer()); break;
	case 72: factory["R010_StatementEle_21"] = P_SDT_genertor(new R010_StatementEle_21Analyzer()); break;
	case 73: factory["R010_StatementEle_22"] = P_SDT_genertor(new R010_StatementEle_22Analyzer()); break;
	case 74: factory["R010_StatementEle_23"] = P_SDT_genertor(new R010_StatementEle_23Analyzer()); break;
	case 75: factory["R010_StatementEle_24"] = P_SDT_genertor(new R010_StatementEle_24Analyzer()); break;
	case 76: factory["R010_StatementEle_25"] = P_SDT_genertor(new R010_StatementEle_25Analyzer()); break;
	case 77: factory["R010_StatementEle_26"] = P_SDT_genertor(new R010_StatementEle_26Analyzer()); break;
	case 78: factory["R010_StatementEle_27"] = P_SDT_genertor(new R010_StatementEle_27Analyzer()); break;
	case 79: factory["R010_StatementEle_28"] = P_SDT_genertor(new R010_StatementEle_28Analyzer()); break;
	case 80: factory["R010_StatementEle_29"] = P_SDT_genertor(new R010_StatementEle_29Analyzer()); break;
	case 81: factory["R010_StatementEle_30"] = P_SDT_genertor(new R010_StatementEle_30Analyzer()); break;
	case 82: factory["R010_StatementEle_31"] = P_SDT_genertor(new R010_StatementEle_31Analyzer()); break;
	case 83: factory["R010_StatementEle_32"] = P_SDT_genertor(new R010_StatementEle_32Analyzer()); break;
	case 84: factory["R010_StatementEle_33"] = P_SDT_genertor(new R010_StatementEle_33Analyzer()); break;
	case 85: factory["R010_StatementEle_34"] = P_SDT_genertor(new R010_StatementEle_34Analyzer()); break;
	case 86: factory["R010_StatementEle_35"] = P_SDT_genertor(new R010_StatementEle_35Analyzer()); break;
	case 87: factory["R010_StatementEle_36"] = P_SDT_genertor(new R010_StatementEle_36Analyzer()); break;
	case 88: factory["R010_StatementEle_37"] = P_SDT_genertor(new R010_StatementEle_37Analyzer()); break;
	case 89: factory["R010_StatementEle_38"] = P_SDT_genertor(new R010_StatementEle_38Analyzer()); break;
	case 90: factory["R010_StatementEle_39"] = P_SDT_genertor(new R010_StatementEle_39Analyzer()); break;
	case 91: factory["R010_StatementEle_40"] = P_SDT_genertor(new R010_StatementEle_40Analyzer()); break;
	case 92: factory["R010_StatementEle_41"] = P_SDT_genertor(new R010_StatementEle_41Analyzer()); break;
	case 93: factory["R010_StatementEle_42"] = P_SDT_genertor(new R010_StatementEle_42Analyzer()); break;
	case 94: factory["R010_StatementEle_43"] = P_SDT_genertor(new R010_StatementEle_43Analyzer()); break;
	case 95: factory["R010_StatementEle_44"] = P_SDT_genertor(new R010_StatementEle_44Analyzer()); break;
	case 96: factory["R010_StatementEle_45"] = P_SDT_genertor(new R010_StatementEle_45Analyzer()); break;
	case 97: factory["R010_StatementEle_46"] = P_SDT_genertor(new R010_StatementEle_46Analyzer()); break;
	case 98: factory["R010_StatementEle_47"] = P_SDT_genertor(new R010_StatementEle_47Analyzer()); break;
	case 99: factory["R010_StatementEle_48"] = P_SDT_genertor(new R010_StatementEle_48Analyzer()); break;
	case 100: factory["R010_StatementEle_49"] = P_SDT_genertor(new R010_StatementEle_49Analyzer()); break;
	case 101: factory["R010_StatementEle_50"] = P_SDT_genertor(new R010_StatementEle_50Analyzer()); break;
	case 102: factory["R010_StatementEle_51"] = P_SDT_genertor(new R010_StatementEle_51Analyzer()); break;
	case 103: factory["R010_StatementEle_52"] = P_SDT_genertor(new R010_StatementEle_52Analyzer()); break;
	case 104: factory["R010_StatementEle_53"] = P_SDT_genertor(new R010_StatementEle_53Analyzer()); break;
	case 105: factory["R010_StatementEle_54"] = P_SDT_genertor(new R010_StatementEle_54Analyzer()); break;
	case 106: factory["R010_StatementEle_55"] = P_SDT_genertor(new R010_StatementEle_55Analyzer()); break;
	case 107: factory["R010_StatementEle_56"] = P_SDT_genertor(new R010_StatementEle_56Analyzer()); break;
	case 108: factory["R010_StatementEle_57"] = P_SDT_genertor(new R010_StatementEle_57Analyzer()); break;
	case 109: factory["R010_StatementEle_58"] = P_SDT_genertor(new R010_StatementEle_58Analyzer()); break;
	case 110: factory["R010_StatementEle_59"] = P_SDT_genertor(new R010_StatementEle_59Analyzer()); break;
	case 111: factory["R010_StatementEle_60"] = P_SDT_genertor(new R010_StatementEle_60Analyzer()); break;
	case 112: factory["R010_StatementEle_61"] = P_SDT_genertor(new R010_StatementEle_61Analyzer()); break;
	case 113: factory["R010_StatementEle_62"] = P_SDT_genertor(new R010_StatementEle_62Analyzer()); break;
	case 114: factory["R010_StatementEle_63"] = P_SDT_genertor(new R010_StatementEle_63Analyzer()); break;
	case 115: factory["R010_StatementEle_64"] = P_SDT_genertor(new R010_StatementEle_64Analyzer()); break;
	case 116: factory["R010_StatementEle_65"] = P_SDT_genertor(new R010_StatementEle_65Analyzer()); break;
	case 117: factory["R010_StatementEle_66"] = P_SDT_genertor(new R010_StatementEle_66Analyzer()); break;
	case 118: factory["R010_StatementEle_67"] = P_SDT_genertor(new R010_StatementEle_67Analyzer()); break;
	case 119: factory["R010_StatementEle_68"] = P_SDT_genertor(new R010_StatementEle_68Analyzer()); break;
	case 120: factory["R010_StatementEle_69"] = P_SDT_genertor(new R010_StatementEle_69Analyzer()); break;
	case 121: factory["R010_StatementEle_70"] = P_SDT_genertor(new R010_StatementEle_70Analyzer()); break;
	case 122: factory["R010_StatementEle_71"] = P_SDT_genertor(new R010_StatementEle_71Analyzer()); break;
	case 123: factory["R010_StatementEle_72"] = P_SDT_genertor(new R010_StatementEle_72Analyzer()); break;
	case 124: factory["R010_StatementEle_73"] = P_SDT_genertor(new R010_StatementEle_73Analyzer()); break;
	case 125: factory["R010_StatementEle_74"] = P_SDT_genertor(new R010_StatementEle_74Analyzer()); break;
	case 126: factory["R010_StatementEle_75"] = P_SDT_genertor(new R010_StatementEle_75Analyzer()); break;
	case 127: factory["R010_StatementEle_76"] = P_SDT_genertor(new R010_StatementEle_76Analyzer()); break;
	case 128: factory["R010_StatementEle_77"] = P_SDT_genertor(new R010_StatementEle_77Analyzer()); break;
	case 129: factory["R010_StatementEle_78"] = P_SDT_genertor(new R010_StatementEle_78Analyzer()); break;
	case 130: factory["R010_StatementEle_79"] = P_SDT_genertor(new R010_StatementEle_79Analyzer()); break;
	case 131: factory["R010_StatementEle_80"] = P_SDT_genertor(new R010_StatementEle_80Analyzer()); break;
	default:

		if (key.find("R010_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R010_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R010_Factory::~SDT_R010_Factory() {}
