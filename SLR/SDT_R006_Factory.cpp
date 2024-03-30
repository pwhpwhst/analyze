#include <vector>
#include <sstream>
#include <iostream>
#include "SDT_R006_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R006Analyzer.h"
using namespace std;
using namespace boost;



SDT_R006_Factory SDT_R006_Factory::instance;
SDT_R006_Factory::SDT_R006_Factory() {
	control_Param = {
   { "R006_ele_begin_0", 0 },
   { "R006_ParameterListWithParentheses_0", 1 },
   { "R006_ParameterListWithParentheses_1", 2 },
   { "R006_FormalParameterList_0", 3 },
   { "R006_FormalParameterList_1", 4 },
   { "R006_Parameter_0", 5 },
   { "R006_Parameter_1", 6 },
   { "R006_Parameter_2", 7 },
   { "R006_VariableModifierList_0", 8 },
   { "R006_VariableModifierList_1", 9 },
   { "R006_VariableModifierList_2", 10 },
   { "R006_VariableModifierList_3", 11 },
   { "R006_LastFormalParameter_0", 12 },
   { "R006_LastFormalParameter_1", 13 },
   { "R006_LastFormalParameter_2", 14 },
   { "R006_LastFormalParameter_3", 15 },
   { "R006_LastFormalParameter_4", 16 },
   { "R006_FormalParameter_0", 17 },
   { "R006_FormalParameter_1", 18 },
   { "R006_ReceiverParameter_0", 19 },
   { "R006_ReceiverParameter_1", 20 },
   { "R006_ReceiverParameter_2", 21 },
   { "R006_ReceiverParameter_3", 22 },
   { "R006_VariableDeclaratorId_0", 23 },
   { "R006_VariableDeclaratorId_1", 24 },
   { "R006_Identifier_0", 25 },
   { "R006_Dims_0", 26 },
   { "R006_Dims_1", 27 },
   { "R006_Dims_2", 28 },
   { "R006_Dims_3", 29 },
   { "R006_AnnotationList_0", 30 },
   { "R006_AnnotationList_1", 31 },
   { "R006_Annotation_0", 32 },
   { "R006_Annotation_1", 33 },
   { "R006_DetailIdentifier_0", 34 },
   { "R006_DetailIdentifier_1", 35 },
   { "R006_AnnotationContent_0", 36 },
   { "R006_AnnotationContentStatements_0", 37 },
   { "R006_AnnotationContentStatements_1", 38 },
   { "R006_NonPARENTHESES_0", 39 },
   { "R006_NonPARENTHESES_1", 40 },
   { "R006_NonPARENTHESES_2", 41 },
   { "R006_NonPARENTHESES_3", 42 },
   { "R006_NonPARENTHESES_4", 43 },
   { "R006_NonPARENTHESES_5", 44 },
   { "R006_NonPARENTHESES_6", 45 },
   { "R006_NonPARENTHESES_7", 46 },
   { "R006_NonPARENTHESES_8", 47 },
   { "R006_NonPARENTHESES_9", 48 },
   { "R006_NonPARENTHESES_10", 49 },
   { "R006_StatementEle_0", 50 },
   { "R006_StatementEle_1", 51 },
   { "R006_StatementEle_2", 52 },
   { "R006_StatementEle_3", 53 },
   { "R006_StatementEle_4", 54 },
   { "R006_StatementEle_5", 55 },
   { "R006_StatementEle_6", 56 },
   { "R006_StatementEle_7", 57 },
   { "R006_StatementEle_8", 58 },
   { "R006_StatementEle_9", 59 },
   { "R006_StatementEle_10", 60 },
   { "R006_StatementEle_11", 61 },
   { "R006_StatementEle_12", 62 },
   { "R006_StatementEle_13", 63 },
   { "R006_StatementEle_14", 64 },
   { "R006_StatementEle_15", 65 },
   { "R006_StatementEle_16", 66 },
   { "R006_StatementEle_17", 67 },
   { "R006_StatementEle_18", 68 },
   { "R006_StatementEle_19", 69 },
   { "R006_StatementEle_20", 70 },
   { "R006_StatementEle_21", 71 },
   { "R006_StatementEle_22", 72 },
   { "R006_StatementEle_23", 73 },
   { "R006_StatementEle_24", 74 },
   { "R006_StatementEle_25", 75 },
   { "R006_StatementEle_26", 76 },
   { "R006_StatementEle_27", 77 },
   { "R006_StatementEle_28", 78 },
   { "R006_StatementEle_29", 79 },
   { "R006_StatementEle_30", 80 },
   { "R006_StatementEle_31", 81 },
   { "R006_StatementEle_32", 82 },
   { "R006_StatementEle_33", 83 },
   { "R006_StatementEle_34", 84 },
   { "R006_StatementEle_35", 85 },
   { "R006_StatementEle_36", 86 },
   { "R006_StatementEle_37", 87 },
   { "R006_StatementEle_38", 88 },
   { "R006_StatementEle_39", 89 },
   { "R006_StatementEle_40", 90 },
   { "R006_StatementEle_41", 91 },
   { "R006_StatementEle_42", 92 },
   { "R006_StatementEle_43", 93 },
   { "R006_StatementEle_44", 94 },
   { "R006_StatementEle_45", 95 },
   { "R006_StatementEle_46", 96 },
   { "R006_StatementEle_47", 97 },
   { "R006_StatementEle_48", 98 },
   { "R006_StatementEle_49", 99 },
   { "R006_StatementEle_50", 100 },
   { "R006_StatementEle_51", 101 },
   { "R006_StatementEle_52", 102 },
   { "R006_StatementEle_53", 103 },
   { "R006_StatementEle_54", 104 },
   { "R006_StatementEle_55", 105 },
   { "R006_StatementEle_56", 106 },
   { "R006_StatementEle_57", 107 },
   { "R006_StatementEle_58", 108 },
   { "R006_StatementEle_59", 109 },
   { "R006_StatementEle_60", 110 },
   { "R006_StatementEle_61", 111 },
   { "R006_StatementEle_62", 112 },
   { "R006_StatementEle_63", 113 },
   { "R006_StatementEle_64", 114 },
   { "R006_StatementEle_65", 115 },
   { "R006_StatementEle_66", 116 },
   { "R006_StatementEle_67", 117 },
   { "R006_StatementEle_68", 118 },
   { "R006_StatementEle_69", 119 },
   { "R006_StatementEle_70", 120 },
   { "R006_StatementEle_71", 121 },
   { "R006_StatementEle_72", 122 },
   { "R006_TypeArguments_0", 123 },
   { "R006_TypeArguments_1", 124 },
   { "R006_TypeArguments_2", 125 },
   { "R006_TypeArguments_3", 126 },
   { "R006_TypeArgumentListL2_0", 127 },
   { "R006_TypeArgumentListL2_1", 128 },
   { "R006_TypeArgumentListL2_2", 129 },
   { "R006_TypeArgumentListL1_0", 130 },
   { "R006_TypeArgumentListL1_1", 131 },
   { "R006_TypeArgumentListL1_2", 132 },
   { "R006_TypeArgumentList_0", 133 },
   { "R006_TypeArgumentList_1", 134 },
   { "R006_TypeArgumentList_2", 135 },
   { "R006_NonANGLE_BRACKET_0", 136 },
   { "R006_NonANGLE_BRACKET_1", 137 },
   { "R006_NonANGLE_BRACKET_2", 138 },
   { "R006_NonANGLE_BRACKET_3", 139 },
   { "R006_NonANGLE_BRACKET_4", 140 },
   { "R006_NonANGLE_BRACKET_5", 141 },
   { "R006_NonANGLE_BRACKET_6", 142 },
   { "R006_NonANGLE_BRACKET_7", 143 },
   { "R006_NonANGLE_BRACKET_8", 144 },
   { "R006_NonANGLE_BRACKET_9", 145 },
   { "R006_UnannType_0", 146 },
   { "R006_UnannType_1", 147 },
   { "R006_UnannType_2", 148 },
   { "R006_UnannPrimitiveType_0", 149 },
   { "R006_UnannPrimitiveType_1", 150 },
   { "R006_UnannPrimitiveType_2", 151 },
   { "R006_UnannPrimitiveType_3", 152 },
   { "R006_UnannPrimitiveType_4", 153 },
   { "R006_UnannPrimitiveType_5", 154 },
   { "R006_UnannPrimitiveType_6", 155 },
   { "R006_UnannPrimitiveType_7", 156 },
   { "R006_UnannClassOrInterfaceType_0", 157 },
   { "R006_UnannClassOrInterfaceType_1", 158 },
   { "R006_UnannClassOrInterfaceType_2", 159 },
   { "R006_UnannClassOrInterfaceType_3", 160 },
   { "R006_UnannClassOrInterfaceType_4", 161 },
   { "R006_UnannClassOrInterfaceType_5", 162 },
   { "R006_UnannArrayType_0", 163 },
   { "R006_UnannArrayType_1", 164 },
	};
}

P_SDT_genertor SDT_R006_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 0: factory["R006_ele_begin_0"] = P_SDT_genertor(new R006_ele_begin_0Analyzer()); break;
	case 1: factory["R006_ParameterListWithParentheses_0"] = P_SDT_genertor(new R006_ParameterListWithParentheses_0Analyzer()); break;
	case 2: factory["R006_ParameterListWithParentheses_1"] = P_SDT_genertor(new R006_ParameterListWithParentheses_1Analyzer()); break;
	case 3: factory["R006_FormalParameterList_0"] = P_SDT_genertor(new R006_FormalParameterList_0Analyzer()); break;
	case 4: factory["R006_FormalParameterList_1"] = P_SDT_genertor(new R006_FormalParameterList_1Analyzer()); break;
	case 5: factory["R006_Parameter_0"] = P_SDT_genertor(new R006_Parameter_0Analyzer()); break;
	case 6: factory["R006_Parameter_1"] = P_SDT_genertor(new R006_Parameter_1Analyzer()); break;
	case 7: factory["R006_Parameter_2"] = P_SDT_genertor(new R006_Parameter_2Analyzer()); break;
	case 8: factory["R006_VariableModifierList_0"] = P_SDT_genertor(new R006_VariableModifierList_0Analyzer()); break;
	case 9: factory["R006_VariableModifierList_1"] = P_SDT_genertor(new R006_VariableModifierList_1Analyzer()); break;
	case 10: factory["R006_VariableModifierList_2"] = P_SDT_genertor(new R006_VariableModifierList_2Analyzer()); break;
	case 11: factory["R006_VariableModifierList_3"] = P_SDT_genertor(new R006_VariableModifierList_3Analyzer()); break;
	case 12: factory["R006_LastFormalParameter_0"] = P_SDT_genertor(new R006_LastFormalParameter_0Analyzer()); break;
	case 13: factory["R006_LastFormalParameter_1"] = P_SDT_genertor(new R006_LastFormalParameter_1Analyzer()); break;
	case 14: factory["R006_LastFormalParameter_2"] = P_SDT_genertor(new R006_LastFormalParameter_2Analyzer()); break;
	case 15: factory["R006_LastFormalParameter_3"] = P_SDT_genertor(new R006_LastFormalParameter_3Analyzer()); break;
	case 16: factory["R006_LastFormalParameter_4"] = P_SDT_genertor(new R006_LastFormalParameter_4Analyzer()); break;
	case 17: factory["R006_FormalParameter_0"] = P_SDT_genertor(new R006_FormalParameter_0Analyzer()); break;
	case 18: factory["R006_FormalParameter_1"] = P_SDT_genertor(new R006_FormalParameter_1Analyzer()); break;
	case 19: factory["R006_ReceiverParameter_0"] = P_SDT_genertor(new R006_ReceiverParameter_0Analyzer()); break;
	case 20: factory["R006_ReceiverParameter_1"] = P_SDT_genertor(new R006_ReceiverParameter_1Analyzer()); break;
	case 21: factory["R006_ReceiverParameter_2"] = P_SDT_genertor(new R006_ReceiverParameter_2Analyzer()); break;
	case 22: factory["R006_ReceiverParameter_3"] = P_SDT_genertor(new R006_ReceiverParameter_3Analyzer()); break;
	case 23: factory["R006_VariableDeclaratorId_0"] = P_SDT_genertor(new R006_VariableDeclaratorId_0Analyzer()); break;
	case 24: factory["R006_VariableDeclaratorId_1"] = P_SDT_genertor(new R006_VariableDeclaratorId_1Analyzer()); break;
	case 25: factory["R006_Identifier_0"] = P_SDT_genertor(new R006_Identifier_0Analyzer()); break;
	case 26: factory["R006_Dims_0"] = P_SDT_genertor(new R006_Dims_0Analyzer()); break;
	case 27: factory["R006_Dims_1"] = P_SDT_genertor(new R006_Dims_1Analyzer()); break;
	case 28: factory["R006_Dims_2"] = P_SDT_genertor(new R006_Dims_2Analyzer()); break;
	case 29: factory["R006_Dims_3"] = P_SDT_genertor(new R006_Dims_3Analyzer()); break;
	case 30: factory["R006_AnnotationList_0"] = P_SDT_genertor(new R006_AnnotationList_0Analyzer()); break;
	case 31: factory["R006_AnnotationList_1"] = P_SDT_genertor(new R006_AnnotationList_1Analyzer()); break;
	case 32: factory["R006_Annotation_0"] = P_SDT_genertor(new R006_Annotation_0Analyzer()); break;
	case 33: factory["R006_Annotation_1"] = P_SDT_genertor(new R006_Annotation_1Analyzer()); break;
	case 34: factory["R006_DetailIdentifier_0"] = P_SDT_genertor(new R006_DetailIdentifier_0Analyzer()); break;
	case 35: factory["R006_DetailIdentifier_1"] = P_SDT_genertor(new R006_DetailIdentifier_1Analyzer()); break;
	case 36: factory["R006_AnnotationContent_0"] = P_SDT_genertor(new R006_AnnotationContent_0Analyzer()); break;
	case 37: factory["R006_AnnotationContentStatements_0"] = P_SDT_genertor(new R006_AnnotationContentStatements_0Analyzer()); break;
	case 38: factory["R006_AnnotationContentStatements_1"] = P_SDT_genertor(new R006_AnnotationContentStatements_1Analyzer()); break;
	case 39: factory["R006_NonPARENTHESES_0"] = P_SDT_genertor(new R006_NonPARENTHESES_0Analyzer()); break;
	case 40: factory["R006_NonPARENTHESES_1"] = P_SDT_genertor(new R006_NonPARENTHESES_1Analyzer()); break;
	case 41: factory["R006_NonPARENTHESES_2"] = P_SDT_genertor(new R006_NonPARENTHESES_2Analyzer()); break;
	case 42: factory["R006_NonPARENTHESES_3"] = P_SDT_genertor(new R006_NonPARENTHESES_3Analyzer()); break;
	case 43: factory["R006_NonPARENTHESES_4"] = P_SDT_genertor(new R006_NonPARENTHESES_4Analyzer()); break;
	case 44: factory["R006_NonPARENTHESES_5"] = P_SDT_genertor(new R006_NonPARENTHESES_5Analyzer()); break;
	case 45: factory["R006_NonPARENTHESES_6"] = P_SDT_genertor(new R006_NonPARENTHESES_6Analyzer()); break;
	case 46: factory["R006_NonPARENTHESES_7"] = P_SDT_genertor(new R006_NonPARENTHESES_7Analyzer()); break;
	case 47: factory["R006_NonPARENTHESES_8"] = P_SDT_genertor(new R006_NonPARENTHESES_8Analyzer()); break;
	case 48: factory["R006_NonPARENTHESES_9"] = P_SDT_genertor(new R006_NonPARENTHESES_9Analyzer()); break;
	case 49: factory["R006_NonPARENTHESES_10"] = P_SDT_genertor(new R006_NonPARENTHESES_10Analyzer()); break;
	case 50: factory["R006_StatementEle_0"] = P_SDT_genertor(new R006_StatementEle_0Analyzer()); break;
	case 51: factory["R006_StatementEle_1"] = P_SDT_genertor(new R006_StatementEle_1Analyzer()); break;
	case 52: factory["R006_StatementEle_2"] = P_SDT_genertor(new R006_StatementEle_2Analyzer()); break;
	case 53: factory["R006_StatementEle_3"] = P_SDT_genertor(new R006_StatementEle_3Analyzer()); break;
	case 54: factory["R006_StatementEle_4"] = P_SDT_genertor(new R006_StatementEle_4Analyzer()); break;
	case 55: factory["R006_StatementEle_5"] = P_SDT_genertor(new R006_StatementEle_5Analyzer()); break;
	case 56: factory["R006_StatementEle_6"] = P_SDT_genertor(new R006_StatementEle_6Analyzer()); break;
	case 57: factory["R006_StatementEle_7"] = P_SDT_genertor(new R006_StatementEle_7Analyzer()); break;
	case 58: factory["R006_StatementEle_8"] = P_SDT_genertor(new R006_StatementEle_8Analyzer()); break;
	case 59: factory["R006_StatementEle_9"] = P_SDT_genertor(new R006_StatementEle_9Analyzer()); break;
	case 60: factory["R006_StatementEle_10"] = P_SDT_genertor(new R006_StatementEle_10Analyzer()); break;
	case 61: factory["R006_StatementEle_11"] = P_SDT_genertor(new R006_StatementEle_11Analyzer()); break;
	case 62: factory["R006_StatementEle_12"] = P_SDT_genertor(new R006_StatementEle_12Analyzer()); break;
	case 63: factory["R006_StatementEle_13"] = P_SDT_genertor(new R006_StatementEle_13Analyzer()); break;
	case 64: factory["R006_StatementEle_14"] = P_SDT_genertor(new R006_StatementEle_14Analyzer()); break;
	case 65: factory["R006_StatementEle_15"] = P_SDT_genertor(new R006_StatementEle_15Analyzer()); break;
	case 66: factory["R006_StatementEle_16"] = P_SDT_genertor(new R006_StatementEle_16Analyzer()); break;
	case 67: factory["R006_StatementEle_17"] = P_SDT_genertor(new R006_StatementEle_17Analyzer()); break;
	case 68: factory["R006_StatementEle_18"] = P_SDT_genertor(new R006_StatementEle_18Analyzer()); break;
	case 69: factory["R006_StatementEle_19"] = P_SDT_genertor(new R006_StatementEle_19Analyzer()); break;
	case 70: factory["R006_StatementEle_20"] = P_SDT_genertor(new R006_StatementEle_20Analyzer()); break;
	case 71: factory["R006_StatementEle_21"] = P_SDT_genertor(new R006_StatementEle_21Analyzer()); break;
	case 72: factory["R006_StatementEle_22"] = P_SDT_genertor(new R006_StatementEle_22Analyzer()); break;
	case 73: factory["R006_StatementEle_23"] = P_SDT_genertor(new R006_StatementEle_23Analyzer()); break;
	case 74: factory["R006_StatementEle_24"] = P_SDT_genertor(new R006_StatementEle_24Analyzer()); break;
	case 75: factory["R006_StatementEle_25"] = P_SDT_genertor(new R006_StatementEle_25Analyzer()); break;
	case 76: factory["R006_StatementEle_26"] = P_SDT_genertor(new R006_StatementEle_26Analyzer()); break;
	case 77: factory["R006_StatementEle_27"] = P_SDT_genertor(new R006_StatementEle_27Analyzer()); break;
	case 78: factory["R006_StatementEle_28"] = P_SDT_genertor(new R006_StatementEle_28Analyzer()); break;
	case 79: factory["R006_StatementEle_29"] = P_SDT_genertor(new R006_StatementEle_29Analyzer()); break;
	case 80: factory["R006_StatementEle_30"] = P_SDT_genertor(new R006_StatementEle_30Analyzer()); break;
	case 81: factory["R006_StatementEle_31"] = P_SDT_genertor(new R006_StatementEle_31Analyzer()); break;
	case 82: factory["R006_StatementEle_32"] = P_SDT_genertor(new R006_StatementEle_32Analyzer()); break;
	case 83: factory["R006_StatementEle_33"] = P_SDT_genertor(new R006_StatementEle_33Analyzer()); break;
	case 84: factory["R006_StatementEle_34"] = P_SDT_genertor(new R006_StatementEle_34Analyzer()); break;
	case 85: factory["R006_StatementEle_35"] = P_SDT_genertor(new R006_StatementEle_35Analyzer()); break;
	case 86: factory["R006_StatementEle_36"] = P_SDT_genertor(new R006_StatementEle_36Analyzer()); break;
	case 87: factory["R006_StatementEle_37"] = P_SDT_genertor(new R006_StatementEle_37Analyzer()); break;
	case 88: factory["R006_StatementEle_38"] = P_SDT_genertor(new R006_StatementEle_38Analyzer()); break;
	case 89: factory["R006_StatementEle_39"] = P_SDT_genertor(new R006_StatementEle_39Analyzer()); break;
	case 90: factory["R006_StatementEle_40"] = P_SDT_genertor(new R006_StatementEle_40Analyzer()); break;
	case 91: factory["R006_StatementEle_41"] = P_SDT_genertor(new R006_StatementEle_41Analyzer()); break;
	case 92: factory["R006_StatementEle_42"] = P_SDT_genertor(new R006_StatementEle_42Analyzer()); break;
	case 93: factory["R006_StatementEle_43"] = P_SDT_genertor(new R006_StatementEle_43Analyzer()); break;
	case 94: factory["R006_StatementEle_44"] = P_SDT_genertor(new R006_StatementEle_44Analyzer()); break;
	case 95: factory["R006_StatementEle_45"] = P_SDT_genertor(new R006_StatementEle_45Analyzer()); break;
	case 96: factory["R006_StatementEle_46"] = P_SDT_genertor(new R006_StatementEle_46Analyzer()); break;
	case 97: factory["R006_StatementEle_47"] = P_SDT_genertor(new R006_StatementEle_47Analyzer()); break;
	case 98: factory["R006_StatementEle_48"] = P_SDT_genertor(new R006_StatementEle_48Analyzer()); break;
	case 99: factory["R006_StatementEle_49"] = P_SDT_genertor(new R006_StatementEle_49Analyzer()); break;
	case 100: factory["R006_StatementEle_50"] = P_SDT_genertor(new R006_StatementEle_50Analyzer()); break;
	case 101: factory["R006_StatementEle_51"] = P_SDT_genertor(new R006_StatementEle_51Analyzer()); break;
	case 102: factory["R006_StatementEle_52"] = P_SDT_genertor(new R006_StatementEle_52Analyzer()); break;
	case 103: factory["R006_StatementEle_53"] = P_SDT_genertor(new R006_StatementEle_53Analyzer()); break;
	case 104: factory["R006_StatementEle_54"] = P_SDT_genertor(new R006_StatementEle_54Analyzer()); break;
	case 105: factory["R006_StatementEle_55"] = P_SDT_genertor(new R006_StatementEle_55Analyzer()); break;
	case 106: factory["R006_StatementEle_56"] = P_SDT_genertor(new R006_StatementEle_56Analyzer()); break;
	case 107: factory["R006_StatementEle_57"] = P_SDT_genertor(new R006_StatementEle_57Analyzer()); break;
	case 108: factory["R006_StatementEle_58"] = P_SDT_genertor(new R006_StatementEle_58Analyzer()); break;
	case 109: factory["R006_StatementEle_59"] = P_SDT_genertor(new R006_StatementEle_59Analyzer()); break;
	case 110: factory["R006_StatementEle_60"] = P_SDT_genertor(new R006_StatementEle_60Analyzer()); break;
	case 111: factory["R006_StatementEle_61"] = P_SDT_genertor(new R006_StatementEle_61Analyzer()); break;
	case 112: factory["R006_StatementEle_62"] = P_SDT_genertor(new R006_StatementEle_62Analyzer()); break;
	case 113: factory["R006_StatementEle_63"] = P_SDT_genertor(new R006_StatementEle_63Analyzer()); break;
	case 114: factory["R006_StatementEle_64"] = P_SDT_genertor(new R006_StatementEle_64Analyzer()); break;
	case 115: factory["R006_StatementEle_65"] = P_SDT_genertor(new R006_StatementEle_65Analyzer()); break;
	case 116: factory["R006_StatementEle_66"] = P_SDT_genertor(new R006_StatementEle_66Analyzer()); break;
	case 117: factory["R006_StatementEle_67"] = P_SDT_genertor(new R006_StatementEle_67Analyzer()); break;
	case 118: factory["R006_StatementEle_68"] = P_SDT_genertor(new R006_StatementEle_68Analyzer()); break;
	case 119: factory["R006_StatementEle_69"] = P_SDT_genertor(new R006_StatementEle_69Analyzer()); break;
	case 120: factory["R006_StatementEle_70"] = P_SDT_genertor(new R006_StatementEle_70Analyzer()); break;
	case 121: factory["R006_StatementEle_71"] = P_SDT_genertor(new R006_StatementEle_71Analyzer()); break;
	case 122: factory["R006_StatementEle_72"] = P_SDT_genertor(new R006_StatementEle_72Analyzer()); break;
	case 123: factory["R006_TypeArguments_0"] = P_SDT_genertor(new R006_TypeArguments_0Analyzer()); break;
	case 124: factory["R006_TypeArguments_1"] = P_SDT_genertor(new R006_TypeArguments_1Analyzer()); break;
	case 125: factory["R006_TypeArguments_2"] = P_SDT_genertor(new R006_TypeArguments_2Analyzer()); break;
	case 126: factory["R006_TypeArguments_3"] = P_SDT_genertor(new R006_TypeArguments_3Analyzer()); break;
	case 127: factory["R006_TypeArgumentListL2_0"] = P_SDT_genertor(new R006_TypeArgumentListL2_0Analyzer()); break;
	case 128: factory["R006_TypeArgumentListL2_1"] = P_SDT_genertor(new R006_TypeArgumentListL2_1Analyzer()); break;
	case 129: factory["R006_TypeArgumentListL2_2"] = P_SDT_genertor(new R006_TypeArgumentListL2_2Analyzer()); break;
	case 130: factory["R006_TypeArgumentListL1_0"] = P_SDT_genertor(new R006_TypeArgumentListL1_0Analyzer()); break;
	case 131: factory["R006_TypeArgumentListL1_1"] = P_SDT_genertor(new R006_TypeArgumentListL1_1Analyzer()); break;
	case 132: factory["R006_TypeArgumentListL1_2"] = P_SDT_genertor(new R006_TypeArgumentListL1_2Analyzer()); break;
	case 133: factory["R006_TypeArgumentList_0"] = P_SDT_genertor(new R006_TypeArgumentList_0Analyzer()); break;
	case 134: factory["R006_TypeArgumentList_1"] = P_SDT_genertor(new R006_TypeArgumentList_1Analyzer()); break;
	case 135: factory["R006_TypeArgumentList_2"] = P_SDT_genertor(new R006_TypeArgumentList_2Analyzer()); break;
	case 136: factory["R006_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_0Analyzer()); break;
	case 137: factory["R006_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_1Analyzer()); break;
	case 138: factory["R006_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_2Analyzer()); break;
	case 139: factory["R006_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_3Analyzer()); break;
	case 140: factory["R006_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_4Analyzer()); break;
	case 141: factory["R006_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_5Analyzer()); break;
	case 142: factory["R006_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_6Analyzer()); break;
	case 143: factory["R006_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_7Analyzer()); break;
	case 144: factory["R006_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_8Analyzer()); break;
	case 145: factory["R006_NonANGLE_BRACKET_9"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_9Analyzer()); break;
	case 146: factory["R006_UnannType_0"] = P_SDT_genertor(new R006_UnannType_0Analyzer()); break;
	case 147: factory["R006_UnannType_1"] = P_SDT_genertor(new R006_UnannType_1Analyzer()); break;
	case 148: factory["R006_UnannType_2"] = P_SDT_genertor(new R006_UnannType_2Analyzer()); break;
	case 149: factory["R006_UnannPrimitiveType_0"] = P_SDT_genertor(new R006_UnannPrimitiveType_0Analyzer()); break;
	case 150: factory["R006_UnannPrimitiveType_1"] = P_SDT_genertor(new R006_UnannPrimitiveType_1Analyzer()); break;
	case 151: factory["R006_UnannPrimitiveType_2"] = P_SDT_genertor(new R006_UnannPrimitiveType_2Analyzer()); break;
	case 152: factory["R006_UnannPrimitiveType_3"] = P_SDT_genertor(new R006_UnannPrimitiveType_3Analyzer()); break;
	case 153: factory["R006_UnannPrimitiveType_4"] = P_SDT_genertor(new R006_UnannPrimitiveType_4Analyzer()); break;
	case 154: factory["R006_UnannPrimitiveType_5"] = P_SDT_genertor(new R006_UnannPrimitiveType_5Analyzer()); break;
	case 155: factory["R006_UnannPrimitiveType_6"] = P_SDT_genertor(new R006_UnannPrimitiveType_6Analyzer()); break;
	case 156: factory["R006_UnannPrimitiveType_7"] = P_SDT_genertor(new R006_UnannPrimitiveType_7Analyzer()); break;
	case 157: factory["R006_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_0Analyzer()); break;
	case 158: factory["R006_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_1Analyzer()); break;
	case 159: factory["R006_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_2Analyzer()); break;
	case 160: factory["R006_UnannClassOrInterfaceType_3"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_3Analyzer()); break;
	case 161: factory["R006_UnannClassOrInterfaceType_4"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_4Analyzer()); break;
	case 162: factory["R006_UnannClassOrInterfaceType_5"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_5Analyzer()); break;
	case 163: factory["R006_UnannArrayType_0"] = P_SDT_genertor(new R006_UnannArrayType_0Analyzer()); break;
	case 164: factory["R006_UnannArrayType_1"] = P_SDT_genertor(new R006_UnannArrayType_1Analyzer()); break;
	default:

		if (key.find("R006_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R006_DefaultAnalyzer());
			}
		}

	}



	return factory[key];
}
SDT_R006_Factory::~SDT_R006_Factory() {}
