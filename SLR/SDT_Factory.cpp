#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_Factory.h"
#include "../treeAnalyzer/java/R001Analyzer.h"
using namespace std;

SDT_Factory SDT_Factory::instance;
SDT_Factory::SDT_Factory() {
	 control_Param = {

	{ "R001_ele_begin_0", 0 },
	{ "R001_Identifier_0", 1 },
	{ "R001_IdentifierList_0", 2 },
	{ "R001_IdentifierList_1", 3 },
	{ "R001_Literal_0", 4 },
	{ "R001_Literal_1", 5 },
	{ "R001_Literal_2", 6 },
	{ "R001_Literal_3", 7 },
	{ "R001_Literal_4", 8 },
	{ "R001_UnannType_0", 9 },
	{ "R001_UnannType_1", 10 },
	{ "R001_UnannType_2", 11 },
	{ "R001_UnannPrimitiveType_0", 12 },
	{ "R001_UnannPrimitiveType_1", 13 },
	{ "R001_NumericType_0", 14 },
	{ "R001_NumericType_1", 15 },
	{ "R001_IntegralType_0", 16 },
	{ "R001_IntegralType_1", 17 },
	{ "R001_IntegralType_2", 18 },
	{ "R001_IntegralType_3", 19 },
	{ "R001_IntegralType_4", 20 },
	{ "R001_FloatingPointType_0", 21 },
	{ "R001_FloatingPointType_1", 22 },
	{ "R001_UnannClassOrInterfaceType_0", 23 },
	{ "R001_UnannClassOrInterfaceType_1", 24 },
	{ "R001_UnannClassOrInterfaceType_2", 25 },
	{ "R001_UnannClassType_0", 26 },
	{ "R001_UnannClassType_1", 27 },
	{ "R001_UnannArrayType_0", 28 },
	{ "R001_UnannArrayType_1", 29 },
	{ "R001_CompilationUnit_0", 30 },
	{ "R001_CompilationUnit_1", 31 },
	{ "R001_CompilationUnit_2", 32 },
	{ "R001_CompilationUnit_3", 33 },
	{ "R001_CompilationUnit_4", 34 },
	{ "R001_CompilationUnit_5", 35 },
	{ "R001_CompilationUnit_6", 36 },
	{ "R001_PackageDeclaration_0", 37 },
	{ "R001_PackageDeclaration_1", 38 },
	{ "R001_DetailIdentifier_0", 39 },
	{ "R001_DetailIdentifier_1", 40 },
	{ "R001_ImportDeclarationList_0", 41 },
	{ "R001_ImportDeclarationList_1", 42 },
	{ "R001_ImportDeclaration_0", 43 },
	{ "R001_ImportDeclaration_1", 44 },
	{ "R001_ImportDeclaration_2", 45 },
	{ "R001_ImportDeclaration_3", 46 },
	{ "R001_TypeDeclarationList_0", 47 },
	{ "R001_TypeDeclarationList_1", 48 },
	{ "R001_TypeDeclaration_0", 49 },
	{ "R001_TypeDeclaration_1", 50 },
	{ "R001_TypeDeclaration_2", 51 },
	{ "R001_ClassDeclaration_0", 52 },
	{ "R001_ClassDeclaration_1", 53 },
	{ "R001_NormalClassDeclaration_0", 54 },
	{ "R001_NormalClassDeclaration_1", 55 },
	{ "R001_NormalClassDeclaration_2", 56 },
	{ "R001_NormalClassDeclaration_3", 57 },
	{ "R001_NormalClassDeclaration_4", 58 },
	{ "R001_NormalClassDeclaration_5", 59 },
	{ "R001_NormalClassDeclaration_6", 60 },
	{ "R001_NormalClassDeclaration_7", 61 },
	{ "R001_NormalClassDeclaration_8", 62 },
	{ "R001_NormalClassDeclaration_9", 63 },
	{ "R001_NormalClassDeclaration_10", 64 },
	{ "R001_NormalClassDeclaration_11", 65 },
	{ "R001_NormalClassDeclaration_12", 66 },
	{ "R001_NormalClassDeclaration_13", 67 },
	{ "R001_NormalClassDeclaration_14", 68 },
	{ "R001_NormalClassDeclaration_15", 69 },
	{ "R001_ModifierList_0", 70 },
	{ "R001_ModifierList_1", 71 },
	{ "R001_Modifier_0", 72 },
	{ "R001_Modifier_1", 73 },
	{ "R001_Modifier_2", 74 },
	{ "R001_Modifier_3", 75 },
	{ "R001_Modifier_4", 76 },
	{ "R001_Modifier_5", 77 },
	{ "R001_Modifier_6", 78 },
	{ "R001_Modifier_7", 79 },
	{ "R001_Modifier_8", 80 },
	{ "R001_Modifier_9", 81 },
	{ "R001_Modifier_10", 82 },
	{ "R001_Modifier_11", 83 },
	{ "R001_Modifier_12", 84 },
	{ "R001_InterfaceTypeList_0", 85 },
	{ "R001_InterfaceTypeList_1", 86 },
	{ "R001_ClassType_0", 87 },
	{ "R001_ClassType_1", 88 },
	{ "R001_ClassTypeUnit_0", 89 },
	{ "R001_ClassTypeUnit_1", 90 },
	{ "R001_ClassTypeUnit_2", 91 },
	{ "R001_ClassTypeUnit_3", 92 },
	{ "R001_EnumDeclaration_0", 93 },
	{ "R001_EnumDeclaration_1", 94 },
	{ "R001_EnumDeclaration_2", 95 },
	{ "R001_EnumDeclaration_3", 96 },
	{ "R001_InterfaceDeclaration_0", 97 },
	{ "R001_InterfaceDeclaration_1", 98 },
	{ "R001_NormalInterfaceDeclaration_0", 99 },
	{ "R001_NormalInterfaceDeclaration_1", 100 },
	{ "R001_NormalInterfaceDeclaration_2", 101 },
	{ "R001_NormalInterfaceDeclaration_3", 102 },
	{ "R001_NormalInterfaceDeclaration_4", 103 },
	{ "R001_NormalInterfaceDeclaration_5", 104 },
	{ "R001_NormalInterfaceDeclaration_6", 105 },
	{ "R001_NormalInterfaceDeclaration_7", 106 },
	{ "R001_AnnotationTypeDeclaration_0", 107 },
	{ "R001_AnnotationTypeDeclaration_1", 108 },
	{ "R001_Block_0", 109 },
	{ "R001_Block_1", 110 },
	{ "R001_BlockStatements_0", 111 },
	{ "R001_BlockStatements_1", 112 },
	{ "R001_BlockStatements_2", 113 },
	{ "R001_NonBrace_0", 114 },
	{ "R001_NonBrace_1", 115 },
	{ "R001_NonBrace_2", 116 },
	{ "R001_NonBrace_3", 117 },
	{ "R001_NonBrace_4", 118 },
	{ "R001_NonBrace_5", 119 },
	{ "R001_NonBrace_6", 120 },
	{ "R001_NonBrace_7", 121 },
	{ "R001_NonBrace_8", 122 },
	{ "R001_StatementEle_0", 123 },
	{ "R001_StatementEle_1", 124 },
	{ "R001_StatementEle_2", 125 },
	{ "R001_StatementEle_3", 126 },
	{ "R001_StatementEle_4", 127 },
	{ "R001_StatementEle_5", 128 },
	{ "R001_StatementEle_6", 129 },
	{ "R001_StatementEle_7", 130 },
	{ "R001_StatementEle_8", 131 },
	{ "R001_StatementEle_9", 132 },
	{ "R001_StatementEle_10", 133 },
	{ "R001_StatementEle_11", 134 },
	{ "R001_StatementEle_12", 135 },
	{ "R001_StatementEle_13", 136 },
	{ "R001_StatementEle_14", 137 },
	{ "R001_StatementEle_15", 138 },
	{ "R001_StatementEle_16", 139 },
	{ "R001_StatementEle_17", 140 },
	{ "R001_StatementEle_18", 141 },
	{ "R001_StatementEle_19", 142 },
	{ "R001_StatementEle_20", 143 },
	{ "R001_StatementEle_21", 144 },
	{ "R001_StatementEle_22", 145 },
	{ "R001_StatementEle_23", 146 },
	{ "R001_StatementEle_24", 147 },
	{ "R001_StatementEle_25", 148 },
	{ "R001_StatementEle_26", 149 },
	{ "R001_StatementEle_27", 150 },
	{ "R001_StatementEle_28", 151 },
	{ "R001_StatementEle_29", 152 },
	{ "R001_StatementEle_30", 153 },
	{ "R001_StatementEle_31", 154 },
	{ "R001_StatementEle_32", 155 },
	{ "R001_StatementEle_33", 156 },
	{ "R001_StatementEle_34", 157 },
	{ "R001_StatementEle_35", 158 },
	{ "R001_StatementEle_36", 159 },
	{ "R001_StatementEle_37", 160 },
	{ "R001_StatementEle_38", 161 },
	{ "R001_StatementEle_39", 162 },
	{ "R001_StatementEle_40", 163 },
	{ "R001_StatementEle_41", 164 },
	{ "R001_StatementEle_42", 165 },
	{ "R001_StatementEle_43", 166 },
	{ "R001_StatementEle_44", 167 },
	{ "R001_StatementEle_45", 168 },
	{ "R001_StatementEle_46", 169 },
	{ "R001_StatementEle_47", 170 },
	{ "R001_StatementEle_48", 171 },
	{ "R001_StatementEle_49", 172 },
	{ "R001_StatementEle_50", 173 },
	{ "R001_StatementEle_51", 174 },
	{ "R001_StatementEle_52", 175 },
	{ "R001_StatementEle_53", 176 },
	{ "R001_StatementEle_54", 177 },
	{ "R001_StatementEle_55", 178 },
	{ "R001_StatementEle_56", 179 },
	{ "R001_StatementEle_57", 180 },
	{ "R001_StatementEle_58", 181 },
	{ "R001_StatementEle_59", 182 },
	{ "R001_StatementEle_60", 183 },
	{ "R001_StatementEle_61", 184 },
	{ "R001_StatementEle_62", 185 },
	{ "R001_StatementEle_63", 186 },
	{ "R001_StatementEle_64", 187 },
	{ "R001_StatementEle_65", 188 },
	{ "R001_StatementEle_66", 189 },
	{ "R001_StatementEle_67", 190 },
	{ "R001_StatementEle_68", 191 },
	{ "R001_StatementEle_69", 192 },
	{ "R001_StatementEle_70", 193 },
	{ "R001_StatementEle_71", 194 },
	{ "R001_StatementEle_72", 195 },
	{ "R001_StatementEle_73", 196 },
	{ "R001_StatementEle_74", 197 },
	{ "R001_StatementEle_75", 198 },
	{ "R001_StatementEle_76", 199 },
	{ "R001_StatementEle_77", 200 },
	{ "R001_StatementEle_78", 201 },
	{ "R001_StatementEle_79", 202 },
	{ "R001_StatementEle_80", 203 },
	{ "R001_TypeArguments_0", 204 },
	{ "R001_TypeArguments_1", 205 },
	{ "R001_TypeArguments_2", 206 },
	{ "R001_TypeArguments_3", 207 },
	{ "R001_TypeArgumentListL2_0", 208 },
	{ "R001_TypeArgumentListL2_1", 209 },
	{ "R001_TypeArgumentListL2_2", 210 },
	{ "R001_TypeArgumentListL1_0", 211 },
	{ "R001_TypeArgumentListL1_1", 212 },
	{ "R001_TypeArgumentListL1_2", 213 },
	{ "R001_TypeArgumentList_0", 214 },
	{ "R001_TypeArgumentList_1", 215 },
	{ "R001_TypeArgumentList_2", 216 },
	{ "R001_NonANGLE_BRACKET_0", 217 },
	{ "R001_NonANGLE_BRACKET_1", 218 },
	{ "R001_NonANGLE_BRACKET_2", 219 },
	{ "R001_NonANGLE_BRACKET_3", 220 },
	{ "R001_NonANGLE_BRACKET_4", 221 },
	{ "R001_NonANGLE_BRACKET_5", 222 },
	{ "R001_NonANGLE_BRACKET_6", 223 },
	{ "R001_NonANGLE_BRACKET_7", 224 },
	{ "R001_NonANGLE_BRACKET_8", 225 },
	{ "R001_AnnotationList_0", 226 },
	{ "R001_AnnotationList_1", 227 },
	{ "R001_Annotation_0", 228 },
	{ "R001_Annotation_1", 229 },
	{ "R001_Annotation_2", 230 },
	{ "R001_MarkerAnnotation_0", 231 },
	{ "R001_NormalAnnotation_0", 232 },
	{ "R001_AnnotationContent_0", 233 },
	{ "R001_AnnotationContentStatements_0", 234 },
	{ "R001_AnnotationContentStatements_1", 235 },
	{ "R001_AnnotationContentStatements_2", 236 },
	{ "R001_AnnotationContentStatements_3", 237 },
	{ "R001_AnnotationContentStatements_4", 238 },
	{ "R001_AnnotationContentStatements_5", 239 },
	{ "R001_NonPARENTHESES_0", 240 },
	{ "R001_NonPARENTHESES_1", 241 },
	{ "R001_NonPARENTHESES_2", 242 },
	{ "R001_NonPARENTHESES_3", 243 },
	{ "R001_NonPARENTHESES_4", 244 },
	{ "R001_NonPARENTHESES_5", 245 },
	{ "R001_NonPARENTHESES_6", 246 },
	{ "R001_NonPARENTHESES_7", 247 },
	{ "R001_NonPARENTHESES_8", 248 },
	{ "R001_NonPARENTHESES_9", 249 },
	{ "R001_DimExpr_0", 250 },
	{ "R001_DimStatements_0", 251 },
	{ "R001_DimStatements_1", 252 },
	{ "R001_DimStatements_2", 253 },
	{ "R001_NonDim_0", 254 },
	{ "R001_NonDim_1", 255 },
	{ "R001_NonDim_2", 256 },
	{ "R001_NonDim_3", 257 },
	{ "R001_NonDim_4", 258 },
	{ "R001_NonDim_5", 259 },
	{ "R001_NonDim_6", 260 },
	{ "R001_NonDim_7", 261 },
	{ "R001_NonDim_8", 262 },
	{ "R001_NonDim_9", 263 },
	{ "R001_Dims_0", 264 },
	{ "R001_Dims_1", 265 },
	{ "R001_Dim_0", 266 },
	{ "R001_Dim_1", 267 },
	{ "R001_Expression_0", 268 },
	{ "R001_Expression_1", 269 },
	{ "R001_ele_0", 270 },
	{ "R001_ele_1", 271 },
	{ "R001_ele_2", 272 },
	{ "R001_ele_3", 273 },
	{ "R001_ele_4", 274 },
	{ "R001_ele_5", 275 },
	{ "R001_ClassBody_0", 276 },
	{ "R001_ClassBodyDeclarationList_0", 277 },
	{ "R001_ClassBodyDeclarationList_1", 278 },
	{ "R001_ClassBodyDeclaration_0", 279 },
	{ "R001_ClassBodyDeclaration_1", 280 },
	{ "R001_ClassBodyDeclaration_2", 281 },
	{ "R001_ClassMemberDeclaration_0", 282 },
	{ "R001_ClassMemberDeclaration_1", 283 },
	{ "R001_ClassMemberDeclaration_2", 284 },
	{ "R001_ClassMemberDeclaration_3", 285 },
	{ "R001_ClassMemberDeclaration_4", 286 },
	{ "R001_InstanceInitializer_0", 287 },
	{ "R001_StaticInitializer_0", 288 },
	{ "R001_FieldDeclaration_0", 289 },
	{ "R001_FieldDeclaration_1", 290 },
	{ "R001_VariableDeclaratorList_0", 291 },
	{ "R001_VariableDeclaratorList_1", 292 },
	{ "R001_VariableDeclarator_0", 293 },
	{ "R001_VariableDeclarator_1", 294 },
	{ "R001_VariableDeclaratorId_0", 295 },
	{ "R001_VariableDeclaratorId_1", 296 },
	{ "R001_MethodDeclaration_0", 297 },
	{ "R001_MethodDeclaration_1", 298 },
	{ "R001_MethodHeader_0", 299 },
	{ "R001_MethodHeader_1", 300 },
	{ "R001_MethodHeader_2", 301 },
	{ "R001_MethodHeader_3", 302 },
	{ "R001_MethodHeader_4", 303 },
	{ "R001_MethodHeader_5", 304 },
	{ "R001_MethodHeader_6", 305 },
	{ "R001_MethodHeader_7", 306 },
	{ "R001_MethodHeader_8", 307 },
	{ "R001_MethodHeader_9", 308 },
	{ "R001_MethodHeader_10", 309 },
	{ "R001_MethodHeader_11", 310 },
	{ "R001_MethodHeader_12", 311 },
	{ "R001_MethodHeader_13", 312 },
	{ "R001_MethodHeader_14", 313 },
	{ "R001_MethodHeader_15", 314 },
	{ "R001_MethodHeader_16", 315 },
	{ "R001_MethodHeader_17", 316 },
	{ "R001_MethodDeclarator_0", 317 },
	{ "R001_MethodDeclarator_1", 318 },
	{ "R001_MethodDeclarator_2", 319 },
	{ "R001_MethodDeclarator_3", 320 },
	{ "R001_MethodBody_0", 321 },
	{ "R001_MethodBody_1", 322 },
	{ "R001_Throws_0", 323 },
	{ "R001_ExceptionTypeList_0", 324 },
	{ "R001_ExceptionTypeList_1", 325 },
	{ "R001_EnumBody_0", 326 },
	{ "R001_EnumBody_1", 327 },
	{ "R001_EnumBody_2", 328 },
	{ "R001_EnumBody_3", 329 },
	{ "R001_EnumBody_4", 330 },
	{ "R001_EnumBody_5", 331 },
	{ "R001_EnumBody_6", 332 },
	{ "R001_EnumBody_7", 333 },
	{ "R001_EnumConstantList_0", 334 },
	{ "R001_EnumConstantList_1", 335 },
	{ "R001_EnumConstantList_2", 336 },
	{ "R001_EnumConstantList_3", 337 },
	{ "R001_AnnotationTypeBody_0", 338 },
	{ "R001_AnnotationTypeMemberDeclarationList_0", 339 },
	{ "R001_AnnotationTypeMemberDeclarationList_1", 340 },
	{ "R001_AnnotationTypeMemberDeclaration_0", 341 },
	{ "R001_AnnotationTypeMemberDeclaration_1", 342 },
	{ "R001_AnnotationTypeMemberDeclaration_2", 343 },
	{ "R001_AnnotationTypeMemberDeclaration_3", 344 },
	{ "R001_AnnotationTypeMemberDeclaration_4", 345 },
	{ "R001_AnnotationTypeElementDeclaration_0", 346 },
	{ "R001_AnnotationTypeElementDeclaration_1", 347 },
	{ "R001_AnnotationTypeElementDeclaration_2", 348 },
	{ "R001_AnnotationTypeElementDeclaration_3", 349 },
	{ "R001_AnnotationTypeElementDeclaration_4", 350 },
	{ "R001_AnnotationTypeElementDeclaration_5", 351 },
	{ "R001_AnnotationTypeElementDeclaration_6", 352 },
	{ "R001_AnnotationTypeElementDeclaration_7", 353 },
	{ "R001_DefaultValue_0", 354 },
	{ "R001_ElementValue_0", 355 },
	{ "R001_ElementValue_1", 356 }
	};
}

P_SDT_genertor SDT_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key)>0) {
		return factory[key];
	}
	

	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;

	switch (caseValue) {
	case 0: factory["R001_ele_begin_0"] = P_SDT_genertor(new R001_ele_begin_0Analyzer()); break;
	case 1: factory["R001_Identifier_0"] = P_SDT_genertor(new R001_Identifier_0Analyzer()); break;
	case 2: factory["R001_IdentifierList_0"] = P_SDT_genertor(new R001_IdentifierList_0Analyzer()); break;
	case 3: factory["R001_IdentifierList_1"] = P_SDT_genertor(new R001_IdentifierList_1Analyzer()); break;
	case 4: factory["R001_Literal_0"] = P_SDT_genertor(new R001_Literal_0Analyzer()); break;
	case 5: factory["R001_Literal_1"] = P_SDT_genertor(new R001_Literal_1Analyzer()); break;
	case 6: factory["R001_Literal_2"] = P_SDT_genertor(new R001_Literal_2Analyzer()); break;
	case 7: factory["R001_Literal_3"] = P_SDT_genertor(new R001_Literal_3Analyzer()); break;
	case 8: factory["R001_Literal_4"] = P_SDT_genertor(new R001_Literal_4Analyzer()); break;
	case 9: factory["R001_UnannType_0"] = P_SDT_genertor(new R001_UnannType_0Analyzer()); break;
	case 10: factory["R001_UnannType_1"] = P_SDT_genertor(new R001_UnannType_1Analyzer()); break;
	case 11: factory["R001_UnannType_2"] = P_SDT_genertor(new R001_UnannType_2Analyzer()); break;
	case 12: factory["R001_UnannPrimitiveType_0"] = P_SDT_genertor(new R001_UnannPrimitiveType_0Analyzer()); break;
	case 13: factory["R001_UnannPrimitiveType_1"] = P_SDT_genertor(new R001_UnannPrimitiveType_1Analyzer()); break;
	case 14: factory["R001_NumericType_0"] = P_SDT_genertor(new R001_NumericType_0Analyzer()); break;
	case 15: factory["R001_NumericType_1"] = P_SDT_genertor(new R001_NumericType_1Analyzer()); break;
	case 16: factory["R001_IntegralType_0"] = P_SDT_genertor(new R001_IntegralType_0Analyzer()); break;
	case 17: factory["R001_IntegralType_1"] = P_SDT_genertor(new R001_IntegralType_1Analyzer()); break;
	case 18: factory["R001_IntegralType_2"] = P_SDT_genertor(new R001_IntegralType_2Analyzer()); break;
	case 19: factory["R001_IntegralType_3"] = P_SDT_genertor(new R001_IntegralType_3Analyzer()); break;
	case 20: factory["R001_IntegralType_4"] = P_SDT_genertor(new R001_IntegralType_4Analyzer()); break;
	case 21: factory["R001_FloatingPointType_0"] = P_SDT_genertor(new R001_FloatingPointType_0Analyzer()); break;
	case 22: factory["R001_FloatingPointType_1"] = P_SDT_genertor(new R001_FloatingPointType_1Analyzer()); break;
	case 23: factory["R001_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R001_UnannClassOrInterfaceType_0Analyzer()); break;
	case 24: factory["R001_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R001_UnannClassOrInterfaceType_1Analyzer()); break;
	case 25: factory["R001_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R001_UnannClassOrInterfaceType_2Analyzer()); break;
	case 26: factory["R001_UnannClassType_0"] = P_SDT_genertor(new R001_UnannClassType_0Analyzer()); break;
	case 27: factory["R001_UnannClassType_1"] = P_SDT_genertor(new R001_UnannClassType_1Analyzer()); break;
	case 28: factory["R001_UnannArrayType_0"] = P_SDT_genertor(new R001_UnannArrayType_0Analyzer()); break;
	case 29: factory["R001_UnannArrayType_1"] = P_SDT_genertor(new R001_UnannArrayType_1Analyzer()); break;
	case 30: factory["R001_CompilationUnit_0"] = P_SDT_genertor(new R001_CompilationUnit_0Analyzer()); break;
	case 31: factory["R001_CompilationUnit_1"] = P_SDT_genertor(new R001_CompilationUnit_1Analyzer()); break;
	case 32: factory["R001_CompilationUnit_2"] = P_SDT_genertor(new R001_CompilationUnit_2Analyzer()); break;
	case 33: factory["R001_CompilationUnit_3"] = P_SDT_genertor(new R001_CompilationUnit_3Analyzer()); break;
	case 34: factory["R001_CompilationUnit_4"] = P_SDT_genertor(new R001_CompilationUnit_4Analyzer()); break;
	case 35: factory["R001_CompilationUnit_5"] = P_SDT_genertor(new R001_CompilationUnit_5Analyzer()); break;
	case 36: factory["R001_CompilationUnit_6"] = P_SDT_genertor(new R001_CompilationUnit_6Analyzer()); break;
	case 37: factory["R001_PackageDeclaration_0"] = P_SDT_genertor(new R001_PackageDeclaration_0Analyzer()); break;
	case 38: factory["R001_PackageDeclaration_1"] = P_SDT_genertor(new R001_PackageDeclaration_1Analyzer()); break;
	case 39: factory["R001_DetailIdentifier_0"] = P_SDT_genertor(new R001_DetailIdentifier_0Analyzer()); break;
	case 40: factory["R001_DetailIdentifier_1"] = P_SDT_genertor(new R001_DetailIdentifier_1Analyzer()); break;
	case 41: factory["R001_ImportDeclarationList_0"] = P_SDT_genertor(new R001_ImportDeclarationList_0Analyzer()); break;
	case 42: factory["R001_ImportDeclarationList_1"] = P_SDT_genertor(new R001_ImportDeclarationList_1Analyzer()); break;
	case 43: factory["R001_ImportDeclaration_0"] = P_SDT_genertor(new R001_ImportDeclaration_0Analyzer()); break;
	case 44: factory["R001_ImportDeclaration_1"] = P_SDT_genertor(new R001_ImportDeclaration_1Analyzer()); break;
	case 45: factory["R001_ImportDeclaration_2"] = P_SDT_genertor(new R001_ImportDeclaration_2Analyzer()); break;
	case 46: factory["R001_ImportDeclaration_3"] = P_SDT_genertor(new R001_ImportDeclaration_3Analyzer()); break;
	case 47: factory["R001_TypeDeclarationList_0"] = P_SDT_genertor(new R001_TypeDeclarationList_0Analyzer()); break;
	case 48: factory["R001_TypeDeclarationList_1"] = P_SDT_genertor(new R001_TypeDeclarationList_1Analyzer()); break;
	case 49: factory["R001_TypeDeclaration_0"] = P_SDT_genertor(new R001_TypeDeclaration_0Analyzer()); break;
	case 50: factory["R001_TypeDeclaration_1"] = P_SDT_genertor(new R001_TypeDeclaration_1Analyzer()); break;
	case 51: factory["R001_TypeDeclaration_2"] = P_SDT_genertor(new R001_TypeDeclaration_2Analyzer()); break;
	case 52: factory["R001_ClassDeclaration_0"] = P_SDT_genertor(new R001_ClassDeclaration_0Analyzer()); break;
	case 53: factory["R001_ClassDeclaration_1"] = P_SDT_genertor(new R001_ClassDeclaration_1Analyzer()); break;
	case 54: factory["R001_NormalClassDeclaration_0"] = P_SDT_genertor(new R001_NormalClassDeclaration_0Analyzer()); break;
	case 55: factory["R001_NormalClassDeclaration_1"] = P_SDT_genertor(new R001_NormalClassDeclaration_1Analyzer()); break;
	case 56: factory["R001_NormalClassDeclaration_2"] = P_SDT_genertor(new R001_NormalClassDeclaration_2Analyzer()); break;
	case 57: factory["R001_NormalClassDeclaration_3"] = P_SDT_genertor(new R001_NormalClassDeclaration_3Analyzer()); break;
	case 58: factory["R001_NormalClassDeclaration_4"] = P_SDT_genertor(new R001_NormalClassDeclaration_4Analyzer()); break;
	case 59: factory["R001_NormalClassDeclaration_5"] = P_SDT_genertor(new R001_NormalClassDeclaration_5Analyzer()); break;
	case 60: factory["R001_NormalClassDeclaration_6"] = P_SDT_genertor(new R001_NormalClassDeclaration_6Analyzer()); break;
	case 61: factory["R001_NormalClassDeclaration_7"] = P_SDT_genertor(new R001_NormalClassDeclaration_7Analyzer()); break;
	case 62: factory["R001_NormalClassDeclaration_8"] = P_SDT_genertor(new R001_NormalClassDeclaration_8Analyzer()); break;
	case 63: factory["R001_NormalClassDeclaration_9"] = P_SDT_genertor(new R001_NormalClassDeclaration_9Analyzer()); break;
	case 64: factory["R001_NormalClassDeclaration_10"] = P_SDT_genertor(new R001_NormalClassDeclaration_10Analyzer()); break;
	case 65: factory["R001_NormalClassDeclaration_11"] = P_SDT_genertor(new R001_NormalClassDeclaration_11Analyzer()); break;
	case 66: factory["R001_NormalClassDeclaration_12"] = P_SDT_genertor(new R001_NormalClassDeclaration_12Analyzer()); break;
	case 67: factory["R001_NormalClassDeclaration_13"] = P_SDT_genertor(new R001_NormalClassDeclaration_13Analyzer()); break;
	case 68: factory["R001_NormalClassDeclaration_14"] = P_SDT_genertor(new R001_NormalClassDeclaration_14Analyzer()); break;
	case 69: factory["R001_NormalClassDeclaration_15"] = P_SDT_genertor(new R001_NormalClassDeclaration_15Analyzer()); break;
	case 70: factory["R001_ModifierList_0"] = P_SDT_genertor(new R001_ModifierList_0Analyzer()); break;
	case 71: factory["R001_ModifierList_1"] = P_SDT_genertor(new R001_ModifierList_1Analyzer()); break;
	case 72: factory["R001_Modifier_0"] = P_SDT_genertor(new R001_Modifier_0Analyzer()); break;
	case 73: factory["R001_Modifier_1"] = P_SDT_genertor(new R001_Modifier_1Analyzer()); break;
	case 74: factory["R001_Modifier_2"] = P_SDT_genertor(new R001_Modifier_2Analyzer()); break;
	case 75: factory["R001_Modifier_3"] = P_SDT_genertor(new R001_Modifier_3Analyzer()); break;
	case 76: factory["R001_Modifier_4"] = P_SDT_genertor(new R001_Modifier_4Analyzer()); break;
	case 77: factory["R001_Modifier_5"] = P_SDT_genertor(new R001_Modifier_5Analyzer()); break;
	case 78: factory["R001_Modifier_6"] = P_SDT_genertor(new R001_Modifier_6Analyzer()); break;
	case 79: factory["R001_Modifier_7"] = P_SDT_genertor(new R001_Modifier_7Analyzer()); break;
	case 80: factory["R001_Modifier_8"] = P_SDT_genertor(new R001_Modifier_8Analyzer()); break;
	case 81: factory["R001_Modifier_9"] = P_SDT_genertor(new R001_Modifier_9Analyzer()); break;
	case 82: factory["R001_Modifier_10"] = P_SDT_genertor(new R001_Modifier_10Analyzer()); break;
	case 83: factory["R001_Modifier_11"] = P_SDT_genertor(new R001_Modifier_11Analyzer()); break;
	case 84: factory["R001_Modifier_12"] = P_SDT_genertor(new R001_Modifier_12Analyzer()); break;
	case 85: factory["R001_InterfaceTypeList_0"] = P_SDT_genertor(new R001_InterfaceTypeList_0Analyzer()); break;
	case 86: factory["R001_InterfaceTypeList_1"] = P_SDT_genertor(new R001_InterfaceTypeList_1Analyzer()); break;
	case 87: factory["R001_ClassType_0"] = P_SDT_genertor(new R001_ClassType_0Analyzer()); break;
	case 88: factory["R001_ClassType_1"] = P_SDT_genertor(new R001_ClassType_1Analyzer()); break;
	case 89: factory["R001_ClassTypeUnit_0"] = P_SDT_genertor(new R001_ClassTypeUnit_0Analyzer()); break;
	case 90: factory["R001_ClassTypeUnit_1"] = P_SDT_genertor(new R001_ClassTypeUnit_1Analyzer()); break;
	case 91: factory["R001_ClassTypeUnit_2"] = P_SDT_genertor(new R001_ClassTypeUnit_2Analyzer()); break;
	case 92: factory["R001_ClassTypeUnit_3"] = P_SDT_genertor(new R001_ClassTypeUnit_3Analyzer()); break;
	case 93: factory["R001_EnumDeclaration_0"] = P_SDT_genertor(new R001_EnumDeclaration_0Analyzer()); break;
	case 94: factory["R001_EnumDeclaration_1"] = P_SDT_genertor(new R001_EnumDeclaration_1Analyzer()); break;
	case 95: factory["R001_EnumDeclaration_2"] = P_SDT_genertor(new R001_EnumDeclaration_2Analyzer()); break;
	case 96: factory["R001_EnumDeclaration_3"] = P_SDT_genertor(new R001_EnumDeclaration_3Analyzer()); break;
	case 97: factory["R001_InterfaceDeclaration_0"] = P_SDT_genertor(new R001_InterfaceDeclaration_0Analyzer()); break;
	case 98: factory["R001_InterfaceDeclaration_1"] = P_SDT_genertor(new R001_InterfaceDeclaration_1Analyzer()); break;
	case 99: factory["R001_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_0Analyzer()); break;
	case 100: factory["R001_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_1Analyzer()); break;
	case 101: factory["R001_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_2Analyzer()); break;
	case 102: factory["R001_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_3Analyzer()); break;
	case 103: factory["R001_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_4Analyzer()); break;
	case 104: factory["R001_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_5Analyzer()); break;
	case 105: factory["R001_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_6Analyzer()); break;
	case 106: factory["R001_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R001_NormalInterfaceDeclaration_7Analyzer()); break;
	case 107: factory["R001_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R001_AnnotationTypeDeclaration_0Analyzer()); break;
	case 108: factory["R001_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R001_AnnotationTypeDeclaration_1Analyzer()); break;
	case 109: factory["R001_Block_0"] = P_SDT_genertor(new R001_Block_0Analyzer()); break;
	case 110: factory["R001_Block_1"] = P_SDT_genertor(new R001_Block_1Analyzer()); break;
	case 111: factory["R001_BlockStatements_0"] = P_SDT_genertor(new R001_BlockStatements_0Analyzer()); break;
	case 112: factory["R001_BlockStatements_1"] = P_SDT_genertor(new R001_BlockStatements_1Analyzer()); break;
	case 113: factory["R001_BlockStatements_2"] = P_SDT_genertor(new R001_BlockStatements_2Analyzer()); break;
	case 114: factory["R001_NonBrace_0"] = P_SDT_genertor(new R001_NonBrace_0Analyzer()); break;
	case 115: factory["R001_NonBrace_1"] = P_SDT_genertor(new R001_NonBrace_1Analyzer()); break;
	case 116: factory["R001_NonBrace_2"] = P_SDT_genertor(new R001_NonBrace_2Analyzer()); break;
	case 117: factory["R001_NonBrace_3"] = P_SDT_genertor(new R001_NonBrace_3Analyzer()); break;
	case 118: factory["R001_NonBrace_4"] = P_SDT_genertor(new R001_NonBrace_4Analyzer()); break;
	case 119: factory["R001_NonBrace_5"] = P_SDT_genertor(new R001_NonBrace_5Analyzer()); break;
	case 120: factory["R001_NonBrace_6"] = P_SDT_genertor(new R001_NonBrace_6Analyzer()); break;
	case 121: factory["R001_NonBrace_7"] = P_SDT_genertor(new R001_NonBrace_7Analyzer()); break;
	case 122: factory["R001_NonBrace_8"] = P_SDT_genertor(new R001_NonBrace_8Analyzer()); break;
	case 123: factory["R001_StatementEle_0"] = P_SDT_genertor(new R001_StatementEle_0Analyzer()); break;
	case 124: factory["R001_StatementEle_1"] = P_SDT_genertor(new R001_StatementEle_1Analyzer()); break;
	case 125: factory["R001_StatementEle_2"] = P_SDT_genertor(new R001_StatementEle_2Analyzer()); break;
	case 126: factory["R001_StatementEle_3"] = P_SDT_genertor(new R001_StatementEle_3Analyzer()); break;
	case 127: factory["R001_StatementEle_4"] = P_SDT_genertor(new R001_StatementEle_4Analyzer()); break;
	case 128: factory["R001_StatementEle_5"] = P_SDT_genertor(new R001_StatementEle_5Analyzer()); break;
	case 129: factory["R001_StatementEle_6"] = P_SDT_genertor(new R001_StatementEle_6Analyzer()); break;
	case 130: factory["R001_StatementEle_7"] = P_SDT_genertor(new R001_StatementEle_7Analyzer()); break;
	case 131: factory["R001_StatementEle_8"] = P_SDT_genertor(new R001_StatementEle_8Analyzer()); break;
	case 132: factory["R001_StatementEle_9"] = P_SDT_genertor(new R001_StatementEle_9Analyzer()); break;
	case 133: factory["R001_StatementEle_10"] = P_SDT_genertor(new R001_StatementEle_10Analyzer()); break;
	case 134: factory["R001_StatementEle_11"] = P_SDT_genertor(new R001_StatementEle_11Analyzer()); break;
	case 135: factory["R001_StatementEle_12"] = P_SDT_genertor(new R001_StatementEle_12Analyzer()); break;
	case 136: factory["R001_StatementEle_13"] = P_SDT_genertor(new R001_StatementEle_13Analyzer()); break;
	case 137: factory["R001_StatementEle_14"] = P_SDT_genertor(new R001_StatementEle_14Analyzer()); break;
	case 138: factory["R001_StatementEle_15"] = P_SDT_genertor(new R001_StatementEle_15Analyzer()); break;
	case 139: factory["R001_StatementEle_16"] = P_SDT_genertor(new R001_StatementEle_16Analyzer()); break;
	case 140: factory["R001_StatementEle_17"] = P_SDT_genertor(new R001_StatementEle_17Analyzer()); break;
	case 141: factory["R001_StatementEle_18"] = P_SDT_genertor(new R001_StatementEle_18Analyzer()); break;
	case 142: factory["R001_StatementEle_19"] = P_SDT_genertor(new R001_StatementEle_19Analyzer()); break;
	case 143: factory["R001_StatementEle_20"] = P_SDT_genertor(new R001_StatementEle_20Analyzer()); break;
	case 144: factory["R001_StatementEle_21"] = P_SDT_genertor(new R001_StatementEle_21Analyzer()); break;
	case 145: factory["R001_StatementEle_22"] = P_SDT_genertor(new R001_StatementEle_22Analyzer()); break;
	case 146: factory["R001_StatementEle_23"] = P_SDT_genertor(new R001_StatementEle_23Analyzer()); break;
	case 147: factory["R001_StatementEle_24"] = P_SDT_genertor(new R001_StatementEle_24Analyzer()); break;
	case 148: factory["R001_StatementEle_25"] = P_SDT_genertor(new R001_StatementEle_25Analyzer()); break;
	case 149: factory["R001_StatementEle_26"] = P_SDT_genertor(new R001_StatementEle_26Analyzer()); break;
	case 150: factory["R001_StatementEle_27"] = P_SDT_genertor(new R001_StatementEle_27Analyzer()); break;
	case 151: factory["R001_StatementEle_28"] = P_SDT_genertor(new R001_StatementEle_28Analyzer()); break;
	case 152: factory["R001_StatementEle_29"] = P_SDT_genertor(new R001_StatementEle_29Analyzer()); break;
	case 153: factory["R001_StatementEle_30"] = P_SDT_genertor(new R001_StatementEle_30Analyzer()); break;
	case 154: factory["R001_StatementEle_31"] = P_SDT_genertor(new R001_StatementEle_31Analyzer()); break;
	case 155: factory["R001_StatementEle_32"] = P_SDT_genertor(new R001_StatementEle_32Analyzer()); break;
	case 156: factory["R001_StatementEle_33"] = P_SDT_genertor(new R001_StatementEle_33Analyzer()); break;
	case 157: factory["R001_StatementEle_34"] = P_SDT_genertor(new R001_StatementEle_34Analyzer()); break;
	case 158: factory["R001_StatementEle_35"] = P_SDT_genertor(new R001_StatementEle_35Analyzer()); break;
	case 159: factory["R001_StatementEle_36"] = P_SDT_genertor(new R001_StatementEle_36Analyzer()); break;
	case 160: factory["R001_StatementEle_37"] = P_SDT_genertor(new R001_StatementEle_37Analyzer()); break;
	case 161: factory["R001_StatementEle_38"] = P_SDT_genertor(new R001_StatementEle_38Analyzer()); break;
	case 162: factory["R001_StatementEle_39"] = P_SDT_genertor(new R001_StatementEle_39Analyzer()); break;
	case 163: factory["R001_StatementEle_40"] = P_SDT_genertor(new R001_StatementEle_40Analyzer()); break;
	case 164: factory["R001_StatementEle_41"] = P_SDT_genertor(new R001_StatementEle_41Analyzer()); break;
	case 165: factory["R001_StatementEle_42"] = P_SDT_genertor(new R001_StatementEle_42Analyzer()); break;
	case 166: factory["R001_StatementEle_43"] = P_SDT_genertor(new R001_StatementEle_43Analyzer()); break;
	case 167: factory["R001_StatementEle_44"] = P_SDT_genertor(new R001_StatementEle_44Analyzer()); break;
	case 168: factory["R001_StatementEle_45"] = P_SDT_genertor(new R001_StatementEle_45Analyzer()); break;
	case 169: factory["R001_StatementEle_46"] = P_SDT_genertor(new R001_StatementEle_46Analyzer()); break;
	case 170: factory["R001_StatementEle_47"] = P_SDT_genertor(new R001_StatementEle_47Analyzer()); break;
	case 171: factory["R001_StatementEle_48"] = P_SDT_genertor(new R001_StatementEle_48Analyzer()); break;
	case 172: factory["R001_StatementEle_49"] = P_SDT_genertor(new R001_StatementEle_49Analyzer()); break;
	case 173: factory["R001_StatementEle_50"] = P_SDT_genertor(new R001_StatementEle_50Analyzer()); break;
	case 174: factory["R001_StatementEle_51"] = P_SDT_genertor(new R001_StatementEle_51Analyzer()); break;
	case 175: factory["R001_StatementEle_52"] = P_SDT_genertor(new R001_StatementEle_52Analyzer()); break;
	case 176: factory["R001_StatementEle_53"] = P_SDT_genertor(new R001_StatementEle_53Analyzer()); break;
	case 177: factory["R001_StatementEle_54"] = P_SDT_genertor(new R001_StatementEle_54Analyzer()); break;
	case 178: factory["R001_StatementEle_55"] = P_SDT_genertor(new R001_StatementEle_55Analyzer()); break;
	case 179: factory["R001_StatementEle_56"] = P_SDT_genertor(new R001_StatementEle_56Analyzer()); break;
	case 180: factory["R001_StatementEle_57"] = P_SDT_genertor(new R001_StatementEle_57Analyzer()); break;
	case 181: factory["R001_StatementEle_58"] = P_SDT_genertor(new R001_StatementEle_58Analyzer()); break;
	case 182: factory["R001_StatementEle_59"] = P_SDT_genertor(new R001_StatementEle_59Analyzer()); break;
	case 183: factory["R001_StatementEle_60"] = P_SDT_genertor(new R001_StatementEle_60Analyzer()); break;
	case 184: factory["R001_StatementEle_61"] = P_SDT_genertor(new R001_StatementEle_61Analyzer()); break;
	case 185: factory["R001_StatementEle_62"] = P_SDT_genertor(new R001_StatementEle_62Analyzer()); break;
	case 186: factory["R001_StatementEle_63"] = P_SDT_genertor(new R001_StatementEle_63Analyzer()); break;
	case 187: factory["R001_StatementEle_64"] = P_SDT_genertor(new R001_StatementEle_64Analyzer()); break;
	case 188: factory["R001_StatementEle_65"] = P_SDT_genertor(new R001_StatementEle_65Analyzer()); break;
	case 189: factory["R001_StatementEle_66"] = P_SDT_genertor(new R001_StatementEle_66Analyzer()); break;
	case 190: factory["R001_StatementEle_67"] = P_SDT_genertor(new R001_StatementEle_67Analyzer()); break;
	case 191: factory["R001_StatementEle_68"] = P_SDT_genertor(new R001_StatementEle_68Analyzer()); break;
	case 192: factory["R001_StatementEle_69"] = P_SDT_genertor(new R001_StatementEle_69Analyzer()); break;
	case 193: factory["R001_StatementEle_70"] = P_SDT_genertor(new R001_StatementEle_70Analyzer()); break;
	case 194: factory["R001_StatementEle_71"] = P_SDT_genertor(new R001_StatementEle_71Analyzer()); break;
	case 195: factory["R001_StatementEle_72"] = P_SDT_genertor(new R001_StatementEle_72Analyzer()); break;
	case 196: factory["R001_StatementEle_73"] = P_SDT_genertor(new R001_StatementEle_73Analyzer()); break;
	case 197: factory["R001_StatementEle_74"] = P_SDT_genertor(new R001_StatementEle_74Analyzer()); break;
	case 198: factory["R001_StatementEle_75"] = P_SDT_genertor(new R001_StatementEle_75Analyzer()); break;
	case 199: factory["R001_StatementEle_76"] = P_SDT_genertor(new R001_StatementEle_76Analyzer()); break;
	case 200: factory["R001_StatementEle_77"] = P_SDT_genertor(new R001_StatementEle_77Analyzer()); break;
	case 201: factory["R001_StatementEle_78"] = P_SDT_genertor(new R001_StatementEle_78Analyzer()); break;
	case 202: factory["R001_StatementEle_79"] = P_SDT_genertor(new R001_StatementEle_79Analyzer()); break;
	case 203: factory["R001_StatementEle_80"] = P_SDT_genertor(new R001_StatementEle_80Analyzer()); break;
	case 204: factory["R001_TypeArguments_0"] = P_SDT_genertor(new R001_TypeArguments_0Analyzer()); break;
	case 205: factory["R001_TypeArguments_1"] = P_SDT_genertor(new R001_TypeArguments_1Analyzer()); break;
	case 206: factory["R001_TypeArguments_2"] = P_SDT_genertor(new R001_TypeArguments_2Analyzer()); break;
	case 207: factory["R001_TypeArguments_3"] = P_SDT_genertor(new R001_TypeArguments_3Analyzer()); break;
	case 208: factory["R001_TypeArgumentListL2_0"] = P_SDT_genertor(new R001_TypeArgumentListL2_0Analyzer()); break;
	case 209: factory["R001_TypeArgumentListL2_1"] = P_SDT_genertor(new R001_TypeArgumentListL2_1Analyzer()); break;
	case 210: factory["R001_TypeArgumentListL2_2"] = P_SDT_genertor(new R001_TypeArgumentListL2_2Analyzer()); break;
	case 211: factory["R001_TypeArgumentListL1_0"] = P_SDT_genertor(new R001_TypeArgumentListL1_0Analyzer()); break;
	case 212: factory["R001_TypeArgumentListL1_1"] = P_SDT_genertor(new R001_TypeArgumentListL1_1Analyzer()); break;
	case 213: factory["R001_TypeArgumentListL1_2"] = P_SDT_genertor(new R001_TypeArgumentListL1_2Analyzer()); break;
	case 214: factory["R001_TypeArgumentList_0"] = P_SDT_genertor(new R001_TypeArgumentList_0Analyzer()); break;
	case 215: factory["R001_TypeArgumentList_1"] = P_SDT_genertor(new R001_TypeArgumentList_1Analyzer()); break;
	case 216: factory["R001_TypeArgumentList_2"] = P_SDT_genertor(new R001_TypeArgumentList_2Analyzer()); break;
	case 217: factory["R001_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_0Analyzer()); break;
	case 218: factory["R001_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_1Analyzer()); break;
	case 219: factory["R001_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_2Analyzer()); break;
	case 220: factory["R001_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_3Analyzer()); break;
	case 221: factory["R001_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_4Analyzer()); break;
	case 222: factory["R001_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_5Analyzer()); break;
	case 223: factory["R001_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_6Analyzer()); break;
	case 224: factory["R001_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_7Analyzer()); break;
	case 225: factory["R001_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R001_NonANGLE_BRACKET_8Analyzer()); break;
	case 226: factory["R001_AnnotationList_0"] = P_SDT_genertor(new R001_AnnotationList_0Analyzer()); break;
	case 227: factory["R001_AnnotationList_1"] = P_SDT_genertor(new R001_AnnotationList_1Analyzer()); break;
	case 228: factory["R001_Annotation_0"] = P_SDT_genertor(new R001_Annotation_0Analyzer()); break;
	case 229: factory["R001_Annotation_1"] = P_SDT_genertor(new R001_Annotation_1Analyzer()); break;
	case 230: factory["R001_Annotation_2"] = P_SDT_genertor(new R001_Annotation_2Analyzer()); break;
	case 231: factory["R001_MarkerAnnotation_0"] = P_SDT_genertor(new R001_MarkerAnnotation_0Analyzer()); break;
	case 232: factory["R001_NormalAnnotation_0"] = P_SDT_genertor(new R001_NormalAnnotation_0Analyzer()); break;
	case 233: factory["R001_AnnotationContent_0"] = P_SDT_genertor(new R001_AnnotationContent_0Analyzer()); break;
	case 234: factory["R001_AnnotationContentStatements_0"] = P_SDT_genertor(new R001_AnnotationContentStatements_0Analyzer()); break;
	case 235: factory["R001_AnnotationContentStatements_1"] = P_SDT_genertor(new R001_AnnotationContentStatements_1Analyzer()); break;
	case 236: factory["R001_AnnotationContentStatements_2"] = P_SDT_genertor(new R001_AnnotationContentStatements_2Analyzer()); break;
	case 237: factory["R001_AnnotationContentStatements_3"] = P_SDT_genertor(new R001_AnnotationContentStatements_3Analyzer()); break;
	case 238: factory["R001_AnnotationContentStatements_4"] = P_SDT_genertor(new R001_AnnotationContentStatements_4Analyzer()); break;
	case 239: factory["R001_AnnotationContentStatements_5"] = P_SDT_genertor(new R001_AnnotationContentStatements_5Analyzer()); break;
	case 240: factory["R001_NonPARENTHESES_0"] = P_SDT_genertor(new R001_NonPARENTHESES_0Analyzer()); break;
	case 241: factory["R001_NonPARENTHESES_1"] = P_SDT_genertor(new R001_NonPARENTHESES_1Analyzer()); break;
	case 242: factory["R001_NonPARENTHESES_2"] = P_SDT_genertor(new R001_NonPARENTHESES_2Analyzer()); break;
	case 243: factory["R001_NonPARENTHESES_3"] = P_SDT_genertor(new R001_NonPARENTHESES_3Analyzer()); break;
	case 244: factory["R001_NonPARENTHESES_4"] = P_SDT_genertor(new R001_NonPARENTHESES_4Analyzer()); break;
	case 245: factory["R001_NonPARENTHESES_5"] = P_SDT_genertor(new R001_NonPARENTHESES_5Analyzer()); break;
	case 246: factory["R001_NonPARENTHESES_6"] = P_SDT_genertor(new R001_NonPARENTHESES_6Analyzer()); break;
	case 247: factory["R001_NonPARENTHESES_7"] = P_SDT_genertor(new R001_NonPARENTHESES_7Analyzer()); break;
	case 248: factory["R001_NonPARENTHESES_8"] = P_SDT_genertor(new R001_NonPARENTHESES_8Analyzer()); break;
	case 249: factory["R001_NonPARENTHESES_9"] = P_SDT_genertor(new R001_NonPARENTHESES_9Analyzer()); break;
	case 250: factory["R001_DimExpr_0"] = P_SDT_genertor(new R001_DimExpr_0Analyzer()); break;
	case 251: factory["R001_DimStatements_0"] = P_SDT_genertor(new R001_DimStatements_0Analyzer()); break;
	case 252: factory["R001_DimStatements_1"] = P_SDT_genertor(new R001_DimStatements_1Analyzer()); break;
	case 253: factory["R001_DimStatements_2"] = P_SDT_genertor(new R001_DimStatements_2Analyzer()); break;
	case 254: factory["R001_NonDim_0"] = P_SDT_genertor(new R001_NonDim_0Analyzer()); break;
	case 255: factory["R001_NonDim_1"] = P_SDT_genertor(new R001_NonDim_1Analyzer()); break;
	case 256: factory["R001_NonDim_2"] = P_SDT_genertor(new R001_NonDim_2Analyzer()); break;
	case 257: factory["R001_NonDim_3"] = P_SDT_genertor(new R001_NonDim_3Analyzer()); break;
	case 258: factory["R001_NonDim_4"] = P_SDT_genertor(new R001_NonDim_4Analyzer()); break;
	case 259: factory["R001_NonDim_5"] = P_SDT_genertor(new R001_NonDim_5Analyzer()); break;
	case 260: factory["R001_NonDim_6"] = P_SDT_genertor(new R001_NonDim_6Analyzer()); break;
	case 261: factory["R001_NonDim_7"] = P_SDT_genertor(new R001_NonDim_7Analyzer()); break;
	case 262: factory["R001_NonDim_8"] = P_SDT_genertor(new R001_NonDim_8Analyzer()); break;
	case 263: factory["R001_NonDim_9"] = P_SDT_genertor(new R001_NonDim_9Analyzer()); break;
	case 264: factory["R001_Dims_0"] = P_SDT_genertor(new R001_Dims_0Analyzer()); break;
	case 265: factory["R001_Dims_1"] = P_SDT_genertor(new R001_Dims_1Analyzer()); break;
	case 266: factory["R001_Dim_0"] = P_SDT_genertor(new R001_Dim_0Analyzer()); break;
	case 267: factory["R001_Dim_1"] = P_SDT_genertor(new R001_Dim_1Analyzer()); break;
	case 268: factory["R001_Expression_0"] = P_SDT_genertor(new R001_Expression_0Analyzer()); break;
	case 269: factory["R001_Expression_1"] = P_SDT_genertor(new R001_Expression_1Analyzer()); break;
	case 270: factory["R001_ele_0"] = P_SDT_genertor(new R001_ele_0Analyzer()); break;
	case 271: factory["R001_ele_1"] = P_SDT_genertor(new R001_ele_1Analyzer()); break;
	case 272: factory["R001_ele_2"] = P_SDT_genertor(new R001_ele_2Analyzer()); break;
	case 273: factory["R001_ele_3"] = P_SDT_genertor(new R001_ele_3Analyzer()); break;
	case 274: factory["R001_ele_4"] = P_SDT_genertor(new R001_ele_4Analyzer()); break;
	case 275: factory["R001_ele_5"] = P_SDT_genertor(new R001_ele_5Analyzer()); break;
	case 276: factory["R001_ClassBody_0"] = P_SDT_genertor(new R001_ClassBody_0Analyzer()); break;
	case 277: factory["R001_ClassBodyDeclarationList_0"] = P_SDT_genertor(new R001_ClassBodyDeclarationList_0Analyzer()); break;
	case 278: factory["R001_ClassBodyDeclarationList_1"] = P_SDT_genertor(new R001_ClassBodyDeclarationList_1Analyzer()); break;
	case 279: factory["R001_ClassBodyDeclaration_0"] = P_SDT_genertor(new R001_ClassBodyDeclaration_0Analyzer()); break;
	case 280: factory["R001_ClassBodyDeclaration_1"] = P_SDT_genertor(new R001_ClassBodyDeclaration_1Analyzer()); break;
	case 281: factory["R001_ClassBodyDeclaration_2"] = P_SDT_genertor(new R001_ClassBodyDeclaration_2Analyzer()); break;
	case 282: factory["R001_ClassMemberDeclaration_0"] = P_SDT_genertor(new R001_ClassMemberDeclaration_0Analyzer()); break;
	case 283: factory["R001_ClassMemberDeclaration_1"] = P_SDT_genertor(new R001_ClassMemberDeclaration_1Analyzer()); break;
	case 284: factory["R001_ClassMemberDeclaration_2"] = P_SDT_genertor(new R001_ClassMemberDeclaration_2Analyzer()); break;
	case 285: factory["R001_ClassMemberDeclaration_3"] = P_SDT_genertor(new R001_ClassMemberDeclaration_3Analyzer()); break;
	case 286: factory["R001_ClassMemberDeclaration_4"] = P_SDT_genertor(new R001_ClassMemberDeclaration_4Analyzer()); break;
	case 287: factory["R001_InstanceInitializer_0"] = P_SDT_genertor(new R001_InstanceInitializer_0Analyzer()); break;
	case 288: factory["R001_StaticInitializer_0"] = P_SDT_genertor(new R001_StaticInitializer_0Analyzer()); break;
	case 289: factory["R001_FieldDeclaration_0"] = P_SDT_genertor(new R001_FieldDeclaration_0Analyzer()); break;
	case 290: factory["R001_FieldDeclaration_1"] = P_SDT_genertor(new R001_FieldDeclaration_1Analyzer()); break;
	case 291: factory["R001_VariableDeclaratorList_0"] = P_SDT_genertor(new R001_VariableDeclaratorList_0Analyzer()); break;
	case 292: factory["R001_VariableDeclaratorList_1"] = P_SDT_genertor(new R001_VariableDeclaratorList_1Analyzer()); break;
	case 293: factory["R001_VariableDeclarator_0"] = P_SDT_genertor(new R001_VariableDeclarator_0Analyzer()); break;
	case 294: factory["R001_VariableDeclarator_1"] = P_SDT_genertor(new R001_VariableDeclarator_1Analyzer()); break;
	case 295: factory["R001_VariableDeclaratorId_0"] = P_SDT_genertor(new R001_VariableDeclaratorId_0Analyzer()); break;
	case 296: factory["R001_VariableDeclaratorId_1"] = P_SDT_genertor(new R001_VariableDeclaratorId_1Analyzer()); break;
	case 297: factory["R001_MethodDeclaration_0"] = P_SDT_genertor(new R001_MethodDeclaration_0Analyzer()); break;
	case 298: factory["R001_MethodDeclaration_1"] = P_SDT_genertor(new R001_MethodDeclaration_1Analyzer()); break;
	case 299: factory["R001_MethodHeader_0"] = P_SDT_genertor(new R001_MethodHeader_0Analyzer()); break;
	case 300: factory["R001_MethodHeader_1"] = P_SDT_genertor(new R001_MethodHeader_1Analyzer()); break;
	case 301: factory["R001_MethodHeader_2"] = P_SDT_genertor(new R001_MethodHeader_2Analyzer()); break;
	case 302: factory["R001_MethodHeader_3"] = P_SDT_genertor(new R001_MethodHeader_3Analyzer()); break;
	case 303: factory["R001_MethodHeader_4"] = P_SDT_genertor(new R001_MethodHeader_4Analyzer()); break;
	case 304: factory["R001_MethodHeader_5"] = P_SDT_genertor(new R001_MethodHeader_5Analyzer()); break;
	case 305: factory["R001_MethodHeader_6"] = P_SDT_genertor(new R001_MethodHeader_6Analyzer()); break;
	case 306: factory["R001_MethodHeader_7"] = P_SDT_genertor(new R001_MethodHeader_7Analyzer()); break;
	case 307: factory["R001_MethodHeader_8"] = P_SDT_genertor(new R001_MethodHeader_8Analyzer()); break;
	case 308: factory["R001_MethodHeader_9"] = P_SDT_genertor(new R001_MethodHeader_9Analyzer()); break;
	case 309: factory["R001_MethodHeader_10"] = P_SDT_genertor(new R001_MethodHeader_10Analyzer()); break;
	case 310: factory["R001_MethodHeader_11"] = P_SDT_genertor(new R001_MethodHeader_11Analyzer()); break;
	case 311: factory["R001_MethodHeader_12"] = P_SDT_genertor(new R001_MethodHeader_12Analyzer()); break;
	case 312: factory["R001_MethodHeader_13"] = P_SDT_genertor(new R001_MethodHeader_13Analyzer()); break;
	case 313: factory["R001_MethodHeader_14"] = P_SDT_genertor(new R001_MethodHeader_14Analyzer()); break;
	case 314: factory["R001_MethodHeader_15"] = P_SDT_genertor(new R001_MethodHeader_15Analyzer()); break;
	case 315: factory["R001_MethodHeader_16"] = P_SDT_genertor(new R001_MethodHeader_16Analyzer()); break;
	case 316: factory["R001_MethodHeader_17"] = P_SDT_genertor(new R001_MethodHeader_17Analyzer()); break;
	case 317: factory["R001_MethodDeclarator_0"] = P_SDT_genertor(new R001_MethodDeclarator_0Analyzer()); break;
	case 318: factory["R001_MethodDeclarator_1"] = P_SDT_genertor(new R001_MethodDeclarator_1Analyzer()); break;
	case 319: factory["R001_MethodDeclarator_2"] = P_SDT_genertor(new R001_MethodDeclarator_2Analyzer()); break;
	case 320: factory["R001_MethodDeclarator_3"] = P_SDT_genertor(new R001_MethodDeclarator_3Analyzer()); break;
	case 321: factory["R001_MethodBody_0"] = P_SDT_genertor(new R001_MethodBody_0Analyzer()); break;
	case 322: factory["R001_MethodBody_1"] = P_SDT_genertor(new R001_MethodBody_1Analyzer()); break;
	case 323: factory["R001_Throws_0"] = P_SDT_genertor(new R001_Throws_0Analyzer()); break;
	case 324: factory["R001_ExceptionTypeList_0"] = P_SDT_genertor(new R001_ExceptionTypeList_0Analyzer()); break;
	case 325: factory["R001_ExceptionTypeList_1"] = P_SDT_genertor(new R001_ExceptionTypeList_1Analyzer()); break;
	case 326: factory["R001_EnumBody_0"] = P_SDT_genertor(new R001_EnumBody_0Analyzer()); break;
	case 327: factory["R001_EnumBody_1"] = P_SDT_genertor(new R001_EnumBody_1Analyzer()); break;
	case 328: factory["R001_EnumBody_2"] = P_SDT_genertor(new R001_EnumBody_2Analyzer()); break;
	case 329: factory["R001_EnumBody_3"] = P_SDT_genertor(new R001_EnumBody_3Analyzer()); break;
	case 330: factory["R001_EnumBody_4"] = P_SDT_genertor(new R001_EnumBody_4Analyzer()); break;
	case 331: factory["R001_EnumBody_5"] = P_SDT_genertor(new R001_EnumBody_5Analyzer()); break;
	case 332: factory["R001_EnumBody_6"] = P_SDT_genertor(new R001_EnumBody_6Analyzer()); break;
	case 333: factory["R001_EnumBody_7"] = P_SDT_genertor(new R001_EnumBody_7Analyzer()); break;
	case 334: factory["R001_EnumConstantList_0"] = P_SDT_genertor(new R001_EnumConstantList_0Analyzer()); break;
	case 335: factory["R001_EnumConstantList_1"] = P_SDT_genertor(new R001_EnumConstantList_1Analyzer()); break;
	case 336: factory["R001_EnumConstantList_2"] = P_SDT_genertor(new R001_EnumConstantList_2Analyzer()); break;
	case 337: factory["R001_EnumConstantList_3"] = P_SDT_genertor(new R001_EnumConstantList_3Analyzer()); break;
	case 338: factory["R001_AnnotationTypeBody_0"] = P_SDT_genertor(new R001_AnnotationTypeBody_0Analyzer()); break;
	case 339: factory["R001_AnnotationTypeMemberDeclarationList_0"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclarationList_0Analyzer()); break;
	case 340: factory["R001_AnnotationTypeMemberDeclarationList_1"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclarationList_1Analyzer()); break;
	case 341: factory["R001_AnnotationTypeMemberDeclaration_0"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclaration_0Analyzer()); break;
	case 342: factory["R001_AnnotationTypeMemberDeclaration_1"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclaration_1Analyzer()); break;
	case 343: factory["R001_AnnotationTypeMemberDeclaration_2"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclaration_2Analyzer()); break;
	case 344: factory["R001_AnnotationTypeMemberDeclaration_3"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclaration_3Analyzer()); break;
	case 345: factory["R001_AnnotationTypeMemberDeclaration_4"] = P_SDT_genertor(new R001_AnnotationTypeMemberDeclaration_4Analyzer()); break;
	case 346: factory["R001_AnnotationTypeElementDeclaration_0"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_0Analyzer()); break;
	case 347: factory["R001_AnnotationTypeElementDeclaration_1"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_1Analyzer()); break;
	case 348: factory["R001_AnnotationTypeElementDeclaration_2"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_2Analyzer()); break;
	case 349: factory["R001_AnnotationTypeElementDeclaration_3"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_3Analyzer()); break;
	case 350: factory["R001_AnnotationTypeElementDeclaration_4"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_4Analyzer()); break;
	case 351: factory["R001_AnnotationTypeElementDeclaration_5"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_5Analyzer()); break;
	case 352: factory["R001_AnnotationTypeElementDeclaration_6"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_6Analyzer()); break;
	case 353: factory["R001_AnnotationTypeElementDeclaration_7"] = P_SDT_genertor(new R001_AnnotationTypeElementDeclaration_7Analyzer()); break;
	case 354: factory["R001_DefaultValue_0"] = P_SDT_genertor(new R001_DefaultValue_0Analyzer()); break;
	case 355: factory["R001_ElementValue_0"] = P_SDT_genertor(new R001_ElementValue_0Analyzer()); break;
	case 356: factory["R001_ElementValue_1"] = P_SDT_genertor(new R001_ElementValue_1Analyzer()); break;
	default:
		if ("R001_'class'_0" == key
			|| "R001_'IDENTIFIER'_0" == key
			|| "R001_'LEFT_BRACE'_0" == key
			|| "R001_0_0" == key
			|| "R001_'RIGHT_BRACE'_0" == key
			|| "R001_'LEFT_PARENTHESES'_0" == key
			|| "R001_'RIGHT_PARENTHESES'_0" == key
			|| "R001_'int'_0" == key
			|| "R001_'semicolon'_0" == key) {
			factory[key] = P_SDT_genertor(new R001_DefaultAnalyzer());
		};
	}




	return factory[key];
}
SDT_Factory::~SDT_Factory() {}


