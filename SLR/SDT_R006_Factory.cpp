#include<vector>
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
   { "R006_ele_begin_0", 673 },
   { "R006_ParameterListWithParentheses_0", 674 },
   { "R006_ParameterListWithParentheses_1", 675 },
   { "R006_FormalParameterList_0", 676 },
   { "R006_FormalParameterList_1", 677 },
   { "R006_Parameter_0", 678 },
   { "R006_Parameter_1", 679 },
   { "R006_Parameter_2", 680 },
   { "R006_VariableModifierList_0", 684 },
   { "R006_VariableModifierList_1", 685 },
   { "R006_VariableModifierList_2", 686 },
   { "R006_VariableModifierList_3", 687 },
   { "R006_LastFormalParameter_0", 688 },
   { "R006_LastFormalParameter_1", 689 },
   { "R006_LastFormalParameter_2", 690 },
   { "R006_LastFormalParameter_3", 691 },
   { "R006_LastFormalParameter_4", 692 },
   { "R006_FormalParameter_0", 693 },
   { "R006_FormalParameter_1", 694 },
   { "R006_ReceiverParameter_0", 695 },
   { "R006_ReceiverParameter_1", 696 },
   { "R006_ReceiverParameter_2", 697 },
   { "R006_ReceiverParameter_3", 698 },
   { "R006_VariableDeclaratorId_0", 699 },
   { "R006_VariableDeclaratorId_1", 700 },
   { "R006_Identifier_0", 701 },
   { "R006_Dims_0", 702 },
   { "R006_Dims_1", 703 },
   { "R006_Dims_2", 704 },
   { "R006_Dims_3", 705 },
   { "R006_AnnotationList_0", 706 },
   { "R006_AnnotationList_1", 707 },
   { "R006_Annotation_0", 708 },
   { "R006_Annotation_1", 709 },
   { "R006_DetailIdentifier_0", 710 },
   { "R006_DetailIdentifier_1", 711 },
   { "R006_AnnotationContent_0", 712 },
   { "R006_AnnotationContentStatements_0", 713 },
   { "R006_AnnotationContentStatements_1", 714 },
   { "R006_NonPARENTHESES_0", 715 },
   { "R006_NonPARENTHESES_1", 716 },
   { "R006_NonPARENTHESES_2", 717 },
   { "R006_NonPARENTHESES_3", 718 },
   { "R006_NonPARENTHESES_4", 719 },
   { "R006_NonPARENTHESES_5", 720 },
   { "R006_NonPARENTHESES_6", 721 },
   { "R006_NonPARENTHESES_7", 722 },
   { "R006_NonPARENTHESES_8", 723 },
   { "R006_NonPARENTHESES_9", 724 },
   { "R006_NonPARENTHESES_10", 725 },
   { "R006_StatementEle_0", 726 },
   { "R006_StatementEle_1", 727 },
   { "R006_StatementEle_2", 728 },
   { "R006_StatementEle_3", 729 },
   { "R006_StatementEle_4", 730 },
   { "R006_StatementEle_5", 731 },
   { "R006_StatementEle_6", 732 },
   { "R006_StatementEle_7", 733 },
   { "R006_StatementEle_8", 734 },
   { "R006_StatementEle_9", 735 },
   { "R006_StatementEle_10", 736 },
   { "R006_StatementEle_11", 737 },
   { "R006_StatementEle_12", 738 },
   { "R006_StatementEle_13", 739 },
   { "R006_StatementEle_14", 740 },
   { "R006_StatementEle_15", 741 },
   { "R006_StatementEle_16", 742 },
   { "R006_StatementEle_17", 743 },
   { "R006_StatementEle_18", 744 },
   { "R006_StatementEle_19", 745 },
   { "R006_StatementEle_20", 746 },
   { "R006_StatementEle_21", 747 },
   { "R006_StatementEle_22", 748 },
   { "R006_StatementEle_23", 749 },
   { "R006_StatementEle_24", 750 },
   { "R006_StatementEle_25", 751 },
   { "R006_StatementEle_26", 752 },
   { "R006_StatementEle_27", 753 },
   { "R006_StatementEle_28", 754 },
   { "R006_StatementEle_29", 755 },
   { "R006_StatementEle_30", 756 },
   { "R006_StatementEle_31", 757 },
   { "R006_StatementEle_32", 758 },
   { "R006_StatementEle_33", 759 },
   { "R006_StatementEle_34", 760 },
   { "R006_StatementEle_35", 761 },
   { "R006_StatementEle_36", 762 },
   { "R006_StatementEle_37", 763 },
   { "R006_StatementEle_38", 764 },
   { "R006_StatementEle_39", 765 },
   { "R006_StatementEle_40", 766 },
   { "R006_StatementEle_41", 767 },
   { "R006_StatementEle_42", 768 },
   { "R006_StatementEle_43", 769 },
   { "R006_StatementEle_44", 770 },
   { "R006_StatementEle_45", 771 },
   { "R006_StatementEle_46", 772 },
   { "R006_StatementEle_47", 773 },
   { "R006_StatementEle_48", 774 },
   { "R006_StatementEle_49", 775 },
   { "R006_StatementEle_50", 776 },
   { "R006_StatementEle_51", 777 },
   { "R006_StatementEle_52", 778 },
   { "R006_StatementEle_53", 779 },
   { "R006_StatementEle_54", 780 },
   { "R006_StatementEle_55", 781 },
   { "R006_StatementEle_56", 782 },
   { "R006_StatementEle_57", 783 },
   { "R006_StatementEle_58", 784 },
   { "R006_StatementEle_59", 785 },
   { "R006_StatementEle_60", 786 },
   { "R006_StatementEle_61", 787 },
   { "R006_StatementEle_62", 788 },
   { "R006_StatementEle_63", 789 },
   { "R006_StatementEle_64", 790 },
   { "R006_StatementEle_65", 791 },
   { "R006_StatementEle_66", 792 },
   { "R006_StatementEle_67", 793 },
   { "R006_StatementEle_68", 794 },
   { "R006_StatementEle_69", 795 },
   { "R006_StatementEle_70", 796 },
   { "R006_StatementEle_71", 797 },
   { "R006_StatementEle_72", 798 },
   { "R006_TypeArguments_0", 799 },
   { "R006_TypeArgumentList_0", 800 },
   { "R006_TypeArgumentList_1", 801 },
   { "R006_NonANGLE_BRACKET_0", 802 },
   { "R006_NonANGLE_BRACKET_1", 803 },
   { "R006_NonANGLE_BRACKET_2", 804 },
   { "R006_NonANGLE_BRACKET_3", 805 },
   { "R006_NonANGLE_BRACKET_4", 806 },
   { "R006_NonANGLE_BRACKET_5", 807 },
   { "R006_NonANGLE_BRACKET_6", 808 },
   { "R006_NonANGLE_BRACKET_7", 809 },
   { "R006_NonANGLE_BRACKET_8", 810 },
   { "R006_UnannType_0", 811 },
   { "R006_UnannType_1", 812 },
   { "R006_UnannType_2", 813 },
   { "R006_UnannPrimitiveType_0", 814 },
   { "R006_UnannPrimitiveType_1", 815 },
   { "R006_UnannPrimitiveType_2", 816 },
   { "R006_UnannPrimitiveType_3", 817 },
   { "R006_UnannPrimitiveType_4", 818 },
   { "R006_UnannPrimitiveType_5", 819 },
   { "R006_UnannPrimitiveType_6", 820 },
   { "R006_UnannPrimitiveType_7", 821 },
   { "R006_UnannClassOrInterfaceType_0", 822 },
   { "R006_UnannClassOrInterfaceType_1", 823 },
   { "R006_UnannClassOrInterfaceType_2", 824 },
   { "R006_UnannClassOrInterfaceType_3", 825 },
   { "R006_UnannClassOrInterfaceType_4", 826 },
   { "R006_UnannClassOrInterfaceType_5", 827 },
   { "R006_UnannArrayType_0", 828 },
   { "R006_UnannArrayType_1", 829 },
	};
}

P_SDT_genertor SDT_R006_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
	case 673: factory["R006_ele_begin_0"] = P_SDT_genertor(new R006_ele_begin_0Analyzer()); break;
	case 674: factory["R006_ParameterListWithParentheses_0"] = P_SDT_genertor(new R006_ParameterListWithParentheses_0Analyzer()); break;
	case 675: factory["R006_ParameterListWithParentheses_1"] = P_SDT_genertor(new R006_ParameterListWithParentheses_1Analyzer()); break;
	case 676: factory["R006_FormalParameterList_0"] = P_SDT_genertor(new R006_FormalParameterList_0Analyzer()); break;
	case 677: factory["R006_FormalParameterList_1"] = P_SDT_genertor(new R006_FormalParameterList_1Analyzer()); break;
	case 678: factory["R006_Parameter_0"] = P_SDT_genertor(new R006_Parameter_0Analyzer()); break;
	case 679: factory["R006_Parameter_1"] = P_SDT_genertor(new R006_Parameter_1Analyzer()); break;
	case 680: factory["R006_Parameter_2"] = P_SDT_genertor(new R006_Parameter_2Analyzer()); break;
	case 684: factory["R006_VariableModifierList_0"] = P_SDT_genertor(new R006_VariableModifierList_0Analyzer()); break;
	case 685: factory["R006_VariableModifierList_1"] = P_SDT_genertor(new R006_VariableModifierList_1Analyzer()); break;
	case 686: factory["R006_VariableModifierList_2"] = P_SDT_genertor(new R006_VariableModifierList_2Analyzer()); break;
	case 687: factory["R006_VariableModifierList_3"] = P_SDT_genertor(new R006_VariableModifierList_3Analyzer()); break;
	case 688: factory["R006_LastFormalParameter_0"] = P_SDT_genertor(new R006_LastFormalParameter_0Analyzer()); break;
	case 689: factory["R006_LastFormalParameter_1"] = P_SDT_genertor(new R006_LastFormalParameter_1Analyzer()); break;
	case 690: factory["R006_LastFormalParameter_2"] = P_SDT_genertor(new R006_LastFormalParameter_2Analyzer()); break;
	case 691: factory["R006_LastFormalParameter_3"] = P_SDT_genertor(new R006_LastFormalParameter_3Analyzer()); break;
	case 692: factory["R006_LastFormalParameter_4"] = P_SDT_genertor(new R006_LastFormalParameter_4Analyzer()); break;
	case 693: factory["R006_FormalParameter_0"] = P_SDT_genertor(new R006_FormalParameter_0Analyzer()); break;
	case 694: factory["R006_FormalParameter_1"] = P_SDT_genertor(new R006_FormalParameter_1Analyzer()); break;
	case 695: factory["R006_ReceiverParameter_0"] = P_SDT_genertor(new R006_ReceiverParameter_0Analyzer()); break;
	case 696: factory["R006_ReceiverParameter_1"] = P_SDT_genertor(new R006_ReceiverParameter_1Analyzer()); break;
	case 697: factory["R006_ReceiverParameter_2"] = P_SDT_genertor(new R006_ReceiverParameter_2Analyzer()); break;
	case 698: factory["R006_ReceiverParameter_3"] = P_SDT_genertor(new R006_ReceiverParameter_3Analyzer()); break;
	case 699: factory["R006_VariableDeclaratorId_0"] = P_SDT_genertor(new R006_VariableDeclaratorId_0Analyzer()); break;
	case 700: factory["R006_VariableDeclaratorId_1"] = P_SDT_genertor(new R006_VariableDeclaratorId_1Analyzer()); break;
	case 701: factory["R006_Identifier_0"] = P_SDT_genertor(new R006_Identifier_0Analyzer()); break;
	case 702: factory["R006_Dims_0"] = P_SDT_genertor(new R006_Dims_0Analyzer()); break;
	case 703: factory["R006_Dims_1"] = P_SDT_genertor(new R006_Dims_1Analyzer()); break;
	case 704: factory["R006_Dims_2"] = P_SDT_genertor(new R006_Dims_2Analyzer()); break;
	case 705: factory["R006_Dims_3"] = P_SDT_genertor(new R006_Dims_3Analyzer()); break;
	case 706: factory["R006_AnnotationList_0"] = P_SDT_genertor(new R006_AnnotationList_0Analyzer()); break;
	case 707: factory["R006_AnnotationList_1"] = P_SDT_genertor(new R006_AnnotationList_1Analyzer()); break;
	case 708: factory["R006_Annotation_0"] = P_SDT_genertor(new R006_Annotation_0Analyzer()); break;
	case 709: factory["R006_Annotation_1"] = P_SDT_genertor(new R006_Annotation_1Analyzer()); break;
	case 710: factory["R006_DetailIdentifier_0"] = P_SDT_genertor(new R006_DetailIdentifier_0Analyzer()); break;
	case 711: factory["R006_DetailIdentifier_1"] = P_SDT_genertor(new R006_DetailIdentifier_1Analyzer()); break;
	case 712: factory["R006_AnnotationContent_0"] = P_SDT_genertor(new R006_AnnotationContent_0Analyzer()); break;
	case 713: factory["R006_AnnotationContentStatements_0"] = P_SDT_genertor(new R006_AnnotationContentStatements_0Analyzer()); break;
	case 714: factory["R006_AnnotationContentStatements_1"] = P_SDT_genertor(new R006_AnnotationContentStatements_1Analyzer()); break;
	case 715: factory["R006_NonPARENTHESES_0"] = P_SDT_genertor(new R006_NonPARENTHESES_0Analyzer()); break;
	case 716: factory["R006_NonPARENTHESES_1"] = P_SDT_genertor(new R006_NonPARENTHESES_1Analyzer()); break;
	case 717: factory["R006_NonPARENTHESES_2"] = P_SDT_genertor(new R006_NonPARENTHESES_2Analyzer()); break;
	case 718: factory["R006_NonPARENTHESES_3"] = P_SDT_genertor(new R006_NonPARENTHESES_3Analyzer()); break;
	case 719: factory["R006_NonPARENTHESES_4"] = P_SDT_genertor(new R006_NonPARENTHESES_4Analyzer()); break;
	case 720: factory["R006_NonPARENTHESES_5"] = P_SDT_genertor(new R006_NonPARENTHESES_5Analyzer()); break;
	case 721: factory["R006_NonPARENTHESES_6"] = P_SDT_genertor(new R006_NonPARENTHESES_6Analyzer()); break;
	case 722: factory["R006_NonPARENTHESES_7"] = P_SDT_genertor(new R006_NonPARENTHESES_7Analyzer()); break;
	case 723: factory["R006_NonPARENTHESES_8"] = P_SDT_genertor(new R006_NonPARENTHESES_8Analyzer()); break;
	case 724: factory["R006_NonPARENTHESES_9"] = P_SDT_genertor(new R006_NonPARENTHESES_9Analyzer()); break;
	case 725: factory["R006_NonPARENTHESES_10"] = P_SDT_genertor(new R006_NonPARENTHESES_10Analyzer()); break;
	case 726: factory["R006_StatementEle_0"] = P_SDT_genertor(new R006_StatementEle_0Analyzer()); break;
	case 727: factory["R006_StatementEle_1"] = P_SDT_genertor(new R006_StatementEle_1Analyzer()); break;
	case 728: factory["R006_StatementEle_2"] = P_SDT_genertor(new R006_StatementEle_2Analyzer()); break;
	case 729: factory["R006_StatementEle_3"] = P_SDT_genertor(new R006_StatementEle_3Analyzer()); break;
	case 730: factory["R006_StatementEle_4"] = P_SDT_genertor(new R006_StatementEle_4Analyzer()); break;
	case 731: factory["R006_StatementEle_5"] = P_SDT_genertor(new R006_StatementEle_5Analyzer()); break;
	case 732: factory["R006_StatementEle_6"] = P_SDT_genertor(new R006_StatementEle_6Analyzer()); break;
	case 733: factory["R006_StatementEle_7"] = P_SDT_genertor(new R006_StatementEle_7Analyzer()); break;
	case 734: factory["R006_StatementEle_8"] = P_SDT_genertor(new R006_StatementEle_8Analyzer()); break;
	case 735: factory["R006_StatementEle_9"] = P_SDT_genertor(new R006_StatementEle_9Analyzer()); break;
	case 736: factory["R006_StatementEle_10"] = P_SDT_genertor(new R006_StatementEle_10Analyzer()); break;
	case 737: factory["R006_StatementEle_11"] = P_SDT_genertor(new R006_StatementEle_11Analyzer()); break;
	case 738: factory["R006_StatementEle_12"] = P_SDT_genertor(new R006_StatementEle_12Analyzer()); break;
	case 739: factory["R006_StatementEle_13"] = P_SDT_genertor(new R006_StatementEle_13Analyzer()); break;
	case 740: factory["R006_StatementEle_14"] = P_SDT_genertor(new R006_StatementEle_14Analyzer()); break;
	case 741: factory["R006_StatementEle_15"] = P_SDT_genertor(new R006_StatementEle_15Analyzer()); break;
	case 742: factory["R006_StatementEle_16"] = P_SDT_genertor(new R006_StatementEle_16Analyzer()); break;
	case 743: factory["R006_StatementEle_17"] = P_SDT_genertor(new R006_StatementEle_17Analyzer()); break;
	case 744: factory["R006_StatementEle_18"] = P_SDT_genertor(new R006_StatementEle_18Analyzer()); break;
	case 745: factory["R006_StatementEle_19"] = P_SDT_genertor(new R006_StatementEle_19Analyzer()); break;
	case 746: factory["R006_StatementEle_20"] = P_SDT_genertor(new R006_StatementEle_20Analyzer()); break;
	case 747: factory["R006_StatementEle_21"] = P_SDT_genertor(new R006_StatementEle_21Analyzer()); break;
	case 748: factory["R006_StatementEle_22"] = P_SDT_genertor(new R006_StatementEle_22Analyzer()); break;
	case 749: factory["R006_StatementEle_23"] = P_SDT_genertor(new R006_StatementEle_23Analyzer()); break;
	case 750: factory["R006_StatementEle_24"] = P_SDT_genertor(new R006_StatementEle_24Analyzer()); break;
	case 751: factory["R006_StatementEle_25"] = P_SDT_genertor(new R006_StatementEle_25Analyzer()); break;
	case 752: factory["R006_StatementEle_26"] = P_SDT_genertor(new R006_StatementEle_26Analyzer()); break;
	case 753: factory["R006_StatementEle_27"] = P_SDT_genertor(new R006_StatementEle_27Analyzer()); break;
	case 754: factory["R006_StatementEle_28"] = P_SDT_genertor(new R006_StatementEle_28Analyzer()); break;
	case 755: factory["R006_StatementEle_29"] = P_SDT_genertor(new R006_StatementEle_29Analyzer()); break;
	case 756: factory["R006_StatementEle_30"] = P_SDT_genertor(new R006_StatementEle_30Analyzer()); break;
	case 757: factory["R006_StatementEle_31"] = P_SDT_genertor(new R006_StatementEle_31Analyzer()); break;
	case 758: factory["R006_StatementEle_32"] = P_SDT_genertor(new R006_StatementEle_32Analyzer()); break;
	case 759: factory["R006_StatementEle_33"] = P_SDT_genertor(new R006_StatementEle_33Analyzer()); break;
	case 760: factory["R006_StatementEle_34"] = P_SDT_genertor(new R006_StatementEle_34Analyzer()); break;
	case 761: factory["R006_StatementEle_35"] = P_SDT_genertor(new R006_StatementEle_35Analyzer()); break;
	case 762: factory["R006_StatementEle_36"] = P_SDT_genertor(new R006_StatementEle_36Analyzer()); break;
	case 763: factory["R006_StatementEle_37"] = P_SDT_genertor(new R006_StatementEle_37Analyzer()); break;
	case 764: factory["R006_StatementEle_38"] = P_SDT_genertor(new R006_StatementEle_38Analyzer()); break;
	case 765: factory["R006_StatementEle_39"] = P_SDT_genertor(new R006_StatementEle_39Analyzer()); break;
	case 766: factory["R006_StatementEle_40"] = P_SDT_genertor(new R006_StatementEle_40Analyzer()); break;
	case 767: factory["R006_StatementEle_41"] = P_SDT_genertor(new R006_StatementEle_41Analyzer()); break;
	case 768: factory["R006_StatementEle_42"] = P_SDT_genertor(new R006_StatementEle_42Analyzer()); break;
	case 769: factory["R006_StatementEle_43"] = P_SDT_genertor(new R006_StatementEle_43Analyzer()); break;
	case 770: factory["R006_StatementEle_44"] = P_SDT_genertor(new R006_StatementEle_44Analyzer()); break;
	case 771: factory["R006_StatementEle_45"] = P_SDT_genertor(new R006_StatementEle_45Analyzer()); break;
	case 772: factory["R006_StatementEle_46"] = P_SDT_genertor(new R006_StatementEle_46Analyzer()); break;
	case 773: factory["R006_StatementEle_47"] = P_SDT_genertor(new R006_StatementEle_47Analyzer()); break;
	case 774: factory["R006_StatementEle_48"] = P_SDT_genertor(new R006_StatementEle_48Analyzer()); break;
	case 775: factory["R006_StatementEle_49"] = P_SDT_genertor(new R006_StatementEle_49Analyzer()); break;
	case 776: factory["R006_StatementEle_50"] = P_SDT_genertor(new R006_StatementEle_50Analyzer()); break;
	case 777: factory["R006_StatementEle_51"] = P_SDT_genertor(new R006_StatementEle_51Analyzer()); break;
	case 778: factory["R006_StatementEle_52"] = P_SDT_genertor(new R006_StatementEle_52Analyzer()); break;
	case 779: factory["R006_StatementEle_53"] = P_SDT_genertor(new R006_StatementEle_53Analyzer()); break;
	case 780: factory["R006_StatementEle_54"] = P_SDT_genertor(new R006_StatementEle_54Analyzer()); break;
	case 781: factory["R006_StatementEle_55"] = P_SDT_genertor(new R006_StatementEle_55Analyzer()); break;
	case 782: factory["R006_StatementEle_56"] = P_SDT_genertor(new R006_StatementEle_56Analyzer()); break;
	case 783: factory["R006_StatementEle_57"] = P_SDT_genertor(new R006_StatementEle_57Analyzer()); break;
	case 784: factory["R006_StatementEle_58"] = P_SDT_genertor(new R006_StatementEle_58Analyzer()); break;
	case 785: factory["R006_StatementEle_59"] = P_SDT_genertor(new R006_StatementEle_59Analyzer()); break;
	case 786: factory["R006_StatementEle_60"] = P_SDT_genertor(new R006_StatementEle_60Analyzer()); break;
	case 787: factory["R006_StatementEle_61"] = P_SDT_genertor(new R006_StatementEle_61Analyzer()); break;
	case 788: factory["R006_StatementEle_62"] = P_SDT_genertor(new R006_StatementEle_62Analyzer()); break;
	case 789: factory["R006_StatementEle_63"] = P_SDT_genertor(new R006_StatementEle_63Analyzer()); break;
	case 790: factory["R006_StatementEle_64"] = P_SDT_genertor(new R006_StatementEle_64Analyzer()); break;
	case 791: factory["R006_StatementEle_65"] = P_SDT_genertor(new R006_StatementEle_65Analyzer()); break;
	case 792: factory["R006_StatementEle_66"] = P_SDT_genertor(new R006_StatementEle_66Analyzer()); break;
	case 793: factory["R006_StatementEle_67"] = P_SDT_genertor(new R006_StatementEle_67Analyzer()); break;
	case 794: factory["R006_StatementEle_68"] = P_SDT_genertor(new R006_StatementEle_68Analyzer()); break;
	case 795: factory["R006_StatementEle_69"] = P_SDT_genertor(new R006_StatementEle_69Analyzer()); break;
	case 796: factory["R006_StatementEle_70"] = P_SDT_genertor(new R006_StatementEle_70Analyzer()); break;
	case 797: factory["R006_StatementEle_71"] = P_SDT_genertor(new R006_StatementEle_71Analyzer()); break;
	case 798: factory["R006_StatementEle_72"] = P_SDT_genertor(new R006_StatementEle_72Analyzer()); break;
	case 799: factory["R006_TypeArguments_0"] = P_SDT_genertor(new R006_TypeArguments_0Analyzer()); break;
	case 800: factory["R006_TypeArgumentList_0"] = P_SDT_genertor(new R006_TypeArgumentList_0Analyzer()); break;
	case 801: factory["R006_TypeArgumentList_1"] = P_SDT_genertor(new R006_TypeArgumentList_1Analyzer()); break;
	case 802: factory["R006_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_0Analyzer()); break;
	case 803: factory["R006_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_1Analyzer()); break;
	case 804: factory["R006_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_2Analyzer()); break;
	case 805: factory["R006_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_3Analyzer()); break;
	case 806: factory["R006_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_4Analyzer()); break;
	case 807: factory["R006_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_5Analyzer()); break;
	case 808: factory["R006_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_6Analyzer()); break;
	case 809: factory["R006_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_7Analyzer()); break;
	case 810: factory["R006_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R006_NonANGLE_BRACKET_8Analyzer()); break;
	case 811: factory["R006_UnannType_0"] = P_SDT_genertor(new R006_UnannType_0Analyzer()); break;
	case 812: factory["R006_UnannType_1"] = P_SDT_genertor(new R006_UnannType_1Analyzer()); break;
	case 813: factory["R006_UnannType_2"] = P_SDT_genertor(new R006_UnannType_2Analyzer()); break;
	case 814: factory["R006_UnannPrimitiveType_0"] = P_SDT_genertor(new R006_UnannPrimitiveType_0Analyzer()); break;
	case 815: factory["R006_UnannPrimitiveType_1"] = P_SDT_genertor(new R006_UnannPrimitiveType_1Analyzer()); break;
	case 816: factory["R006_UnannPrimitiveType_2"] = P_SDT_genertor(new R006_UnannPrimitiveType_2Analyzer()); break;
	case 817: factory["R006_UnannPrimitiveType_3"] = P_SDT_genertor(new R006_UnannPrimitiveType_3Analyzer()); break;
	case 818: factory["R006_UnannPrimitiveType_4"] = P_SDT_genertor(new R006_UnannPrimitiveType_4Analyzer()); break;
	case 819: factory["R006_UnannPrimitiveType_5"] = P_SDT_genertor(new R006_UnannPrimitiveType_5Analyzer()); break;
	case 820: factory["R006_UnannPrimitiveType_6"] = P_SDT_genertor(new R006_UnannPrimitiveType_6Analyzer()); break;
	case 821: factory["R006_UnannPrimitiveType_7"] = P_SDT_genertor(new R006_UnannPrimitiveType_7Analyzer()); break;
	case 822: factory["R006_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_0Analyzer()); break;
	case 823: factory["R006_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_1Analyzer()); break;
	case 824: factory["R006_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_2Analyzer()); break;
	case 825: factory["R006_UnannClassOrInterfaceType_3"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_3Analyzer()); break;
	case 826: factory["R006_UnannClassOrInterfaceType_4"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_4Analyzer()); break;
	case 827: factory["R006_UnannClassOrInterfaceType_5"] = P_SDT_genertor(new R006_UnannClassOrInterfaceType_5Analyzer()); break;
	case 828: factory["R006_UnannArrayType_0"] = P_SDT_genertor(new R006_UnannArrayType_0Analyzer()); break;
	case 829: factory["R006_UnannArrayType_1"] = P_SDT_genertor(new R006_UnannArrayType_1Analyzer()); break;
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


