#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R003Analyzer.h"
#include "../treeAnalyzer/java/R004Analyzer.h"
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
   { "R003_BlockStatements_0", 144 },
   { "R004_ele_begin_0", 145 },
   { "R004_CompilationUnit_0", 146 },
   { "R004_CompilationUnit_1", 147 },
   { "R004_CompilationUnit_2", 148 },
   { "R004_CompilationUnit_3", 149 },
   { "R004_CompilationUnit_4", 150 },
   { "R004_CompilationUnit_5", 151 },
   { "R004_CompilationUnit_6", 152 },
   { "R004_PackageDeclaration_0", 153 },
   { "R004_PackageDeclaration_1", 154 },
   { "R004_DetailIdentifier_0", 155 },
   { "R004_DetailIdentifier_1", 156 },
   { "R004_Identifier_0", 157 },
   { "R004_ImportDeclarationList_0", 158 },
   { "R004_ImportDeclarationList_1", 159 },
   { "R004_ImportDeclaration_0", 160 },
   { "R004_ImportDeclaration_1", 161 },
   { "R004_ImportDeclaration_2", 162 },
   { "R004_ImportDeclaration_3", 163 },
   { "R004_TypeDeclarationList_0", 164 },
   { "R004_TypeDeclaration_0", 165 },
   { "R004_TypeDeclaration_1", 166 },
   { "R004_TypeDeclaration_2", 167 },
   { "R004_ClassDeclaration_0", 168 },
   { "R004_ClassDeclaration_1", 169 },
   { "R004_InterfaceDeclaration_0", 170 },
   { "R004_InterfaceDeclaration_1", 171 },
   { "R004_NormalClassDeclaration_0", 172 },
   { "R004_NormalClassDeclaration_1", 173 },
   { "R004_NormalClassDeclaration_2", 174 },
   { "R004_NormalClassDeclaration_3", 175 },
   { "R004_NormalClassDeclaration_4", 176 },
   { "R004_NormalClassDeclaration_5", 177 },
   { "R004_NormalClassDeclaration_6", 178 },
   { "R004_NormalClassDeclaration_7", 179 },
   { "R004_NormalClassDeclaration_8", 180 },
   { "R004_NormalClassDeclaration_9", 181 },
   { "R004_NormalClassDeclaration_10", 182 },
   { "R004_NormalClassDeclaration_11", 183 },
   { "R004_NormalClassDeclaration_12", 184 },
   { "R004_NormalClassDeclaration_13", 185 },
   { "R004_NormalClassDeclaration_14", 186 },
   { "R004_NormalClassDeclaration_15", 187 },
   { "R004_EnumDeclaration_0", 188 },
   { "R004_EnumDeclaration_1", 189 },
   { "R004_EnumDeclaration_2", 190 },
   { "R004_EnumDeclaration_3", 191 },
   { "R004_NormalInterfaceDeclaration_0", 192 },
   { "R004_NormalInterfaceDeclaration_1", 193 },
   { "R004_NormalInterfaceDeclaration_2", 194 },
   { "R004_NormalInterfaceDeclaration_3", 195 },
   { "R004_NormalInterfaceDeclaration_4", 196 },
   { "R004_NormalInterfaceDeclaration_5", 197 },
   { "R004_NormalInterfaceDeclaration_6", 198 },
   { "R004_NormalInterfaceDeclaration_7", 199 },
   { "R004_ExtendsInterfaces_0", 200 },
   { "R004_AnnotationTypeDeclaration_0", 201 },
   { "R004_AnnotationTypeDeclaration_1", 202 },
   { "R004_AnnotationTypeDeclaration_2", 203 },
   { "R004_AnnotationTypeDeclaration_3", 204 },
   { "R004_ClassBody_0", 205 },
   { "R004_ClassBodyDeclarationList_0", 206 },
   { "R004_ClassBodyDeclarationList_1", 207 },
   { "R004_ClassBodyDeclaration_0", 208 },
   { "R004_ClassBodyDeclaration_1", 209 },
   { "R004_ClassStatementPrefix_0", 210 },
   { "R004_ClassStatementPrefix_1", 211 },
   { "R004_NonBraceAndSemicolon_0", 212 },
   { "R004_NonBraceAndSemicolon_1", 213 },
   { "R004_NonBraceAndSemicolon_2", 214 },
   { "R004_NonBraceAndSemicolon_3", 215 },
   { "R004_NonBraceAndSemicolon_4", 216 },
   { "R004_ModifierList_0", 217 },
   { "R004_ModifierList_1", 218 },
   { "R004_AnnotationContent_0", 219 },
   { "R004_AnnotationContentStatements_0", 220 },
   { "R004_AnnotationContentStatements_1", 221 },
   { "R004_NonPARENTHESES_0", 222 },
   { "R004_NonPARENTHESES_1", 223 },
   { "R004_NonPARENTHESES_2", 224 },
   { "R004_NonPARENTHESES_3", 225 },
   { "R004_NonPARENTHESES_4", 226 },
   { "R004_NonPARENTHESES_5", 227 },
   { "R004_NonPARENTHESES_6", 228 },
   { "R004_NonPARENTHESES_7", 229 },
   { "R004_NonPARENTHESES_8", 230 },
   { "R004_NonPARENTHESES_9", 231 },
   { "R004_StatementEle_0", 232 },
   { "R004_StatementEle_1", 233 },
   { "R004_StatementEle_2", 234 },
   { "R004_StatementEle_3", 235 },
   { "R004_StatementEle_4", 236 },
   { "R004_StatementEle_5", 237 },
   { "R004_StatementEle_6", 238 },
   { "R004_StatementEle_7", 239 },
   { "R004_StatementEle_8", 240 },
   { "R004_StatementEle_9", 241 },
   { "R004_StatementEle_10", 242 },
   { "R004_StatementEle_11", 243 },
   { "R004_StatementEle_12", 244 },
   { "R004_StatementEle_13", 245 },
   { "R004_StatementEle_14", 246 },
   { "R004_StatementEle_15", 247 },
   { "R004_StatementEle_16", 248 },
   { "R004_StatementEle_17", 249 },
   { "R004_StatementEle_18", 250 },
   { "R004_StatementEle_19", 251 },
   { "R004_StatementEle_20", 252 },
   { "R004_StatementEle_21", 253 },
   { "R004_StatementEle_22", 254 },
   { "R004_StatementEle_23", 255 },
   { "R004_StatementEle_24", 256 },
   { "R004_StatementEle_25", 257 },
   { "R004_StatementEle_26", 258 },
   { "R004_StatementEle_27", 259 },
   { "R004_StatementEle_28", 260 },
   { "R004_StatementEle_29", 261 },
   { "R004_StatementEle_30", 262 },
   { "R004_StatementEle_31", 263 },
   { "R004_StatementEle_32", 264 },
   { "R004_StatementEle_33", 265 },
   { "R004_StatementEle_34", 266 },
   { "R004_StatementEle_35", 267 },
   { "R004_StatementEle_36", 268 },
   { "R004_StatementEle_37", 269 },
   { "R004_StatementEle_38", 270 },
   { "R004_StatementEle_39", 271 },
   { "R004_StatementEle_40", 272 },
   { "R004_StatementEle_41", 273 },
   { "R004_StatementEle_42", 274 },
   { "R004_StatementEle_43", 275 },
   { "R004_StatementEle_44", 276 },
   { "R004_StatementEle_45", 277 },
   { "R004_StatementEle_46", 278 },
   { "R004_StatementEle_47", 279 },
   { "R004_StatementEle_48", 280 },
   { "R004_StatementEle_49", 281 },
   { "R004_StatementEle_50", 282 },
   { "R004_StatementEle_51", 283 },
   { "R004_StatementEle_52", 284 },
   { "R004_StatementEle_53", 285 },
   { "R004_StatementEle_54", 286 },
   { "R004_StatementEle_55", 287 },
   { "R004_StatementEle_56", 288 },
   { "R004_StatementEle_57", 289 },
   { "R004_StatementEle_58", 290 },
   { "R004_StatementEle_59", 291 },
   { "R004_StatementEle_60", 292 },
   { "R004_StatementEle_61", 293 },
   { "R004_StatementEle_62", 294 },
   { "R004_StatementEle_63", 295 },
   { "R004_StatementEle_64", 296 },
   { "R004_StatementEle_65", 297 },
   { "R004_StatementEle_66", 298 },
   { "R004_StatementEle_67", 299 },
   { "R004_StatementEle_68", 300 },
   { "R004_StatementEle_69", 301 },
   { "R004_StatementEle_70", 302 },
   { "R004_StatementEle_71", 303 },
   { "R004_StatementEle_72", 304 },
   { "R004_StatementEle_73", 305 },
   { "R004_StatementEle_74", 306 },
   { "R004_StatementEle_75", 307 },
   { "R004_StatementEle_76", 308 },
   { "R004_StatementEle_77", 309 },
   { "R004_StatementEle_78", 310 },
   { "R004_StatementEle_79", 311 },
   { "R004_StatementEle_80", 312 },
   { "R004_Modifier_0", 313 },
   { "R004_Modifier_1", 314 },
   { "R004_Modifier_2", 315 },
   { "R004_Modifier_3", 316 },
   { "R004_Modifier_4", 317 },
   { "R004_Modifier_5", 318 },
   { "R004_Modifier_6", 319 },
   { "R004_Modifier_7", 320 },
   { "R004_Modifier_8", 321 },
   { "R004_Modifier_9", 322 },
   { "R004_Modifier_10", 323 },
   { "R004_Modifier_11", 324 },
   { "R004_Modifier_12", 325 },
   { "R004_MethodBody_0", 326 },
   { "R004_MethodBody_1", 327 },
   { "R004_Block_0", 328 },
   { "R004_Block_1", 329 },
   { "R004_BlockStatements_0", 330 },
   { "R004_BlockStatements_1", 331 },
   { "R004_BlockStatements_2", 332 },
   { "R004_NonBrace_0", 333 },
   { "R004_NonBrace_1", 334 },
   { "R004_NonBrace_2", 335 },
   { "R004_NonBrace_3", 336 },
   { "R004_NonBrace_4", 337 },
   { "R004_NonBrace_5", 338 },
   { "R004_NonBrace_6", 339 },
   { "R004_NonBrace_7", 340 },
   { "R004_NonBrace_8", 341 },
   { "R004_Annotation_0", 342 },
   { "R004_Annotation_1", 343 },
   { "R004_TypeArguments_0", 344 },
   { "R004_TypeArgumentList_0", 345 },
   { "R004_TypeArgumentList_1", 346 },
   { "R004_NonANGLE_BRACKET_0", 347 },
   { "R004_NonANGLE_BRACKET_1", 348 },
   { "R004_NonANGLE_BRACKET_2", 349 },
   { "R004_NonANGLE_BRACKET_3", 350 },
   { "R004_NonANGLE_BRACKET_4", 351 },
   { "R004_NonANGLE_BRACKET_5", 352 },
   { "R004_NonANGLE_BRACKET_6", 353 },
   { "R004_NonANGLE_BRACKET_7", 354 },
   { "R004_NonANGLE_BRACKET_8", 355 },
   { "R004_UnannPrimitiveType_0", 356 },
   { "R004_UnannPrimitiveType_1", 357 },
   { "R004_NumericType_0", 358 },
   { "R004_NumericType_1", 359 },
   { "R004_IntegralType_0", 360 },
   { "R004_IntegralType_1", 361 },
   { "R004_IntegralType_2", 362 },
   { "R004_IntegralType_3", 363 },
   { "R004_IntegralType_4", 364 },
   { "R004_FloatingPointType_0", 365 },
   { "R004_FloatingPointType_1", 366 },
   { "R004_Superclass_0", 367 },
   { "R004_ClassTypeEle_0", 368 },
   { "R004_ClassTypeEle_1", 369 },
   { "R004_ClassTypeEle_2", 370 },
   { "R004_ClassTypeEle_3", 371 },
   { "R004_ClassType_0", 372 },
   { "R004_ClassType_1", 373 },
   { "R004_AnnotationList_0", 374 },
   { "R004_AnnotationList_1", 375 },
   { "R004_Superinterfaces_0", 376 },
   { "R004_InterfaceTypeList_0", 377 },
   { "R004_InterfaceTypeList_1", 378 },
   { "R004_DimExpr_0", 379 },
   { "R004_DimStatements_0", 380 },
   { "R004_DimStatements_1", 381 },
   { "R004_DimStatements_2", 382 },
   { "R004_NonDim_0", 383 },
   { "R004_NonDim_1", 384 },
   { "R004_NonDim_2", 385 },
   { "R004_NonDim_3", 386 },
   { "R004_NonDim_4", 387 },
   { "R004_NonDim_5", 388 },
   { "R004_NonDim_6", 389 },
   { "R004_NonDim_7", 390 },
   { "R004_NonDim_8", 391 },
   { "R004_NonDim_9", 392 },
   { "R004_EnumBody_0", 393 },
   { "R004_EnumBody_1", 394 },
   { "R004_EnumBody_2", 395 },
   { "R004_EnumBody_3", 396 },
   { "R004_EnumBody_4", 397 },
   { "R004_EnumBody_5", 398 },
   { "R004_EnumBody_6", 399 },
   { "R004_EnumBody_7", 400 },
   { "R004_EnumConstantList_0", 401 },
   { "R004_EnumConstantList_1", 402 },
   { "R004_EnumConstantEle_0", 403 },
   { "R004_EnumConstantEle_1", 404 },
   { "R004_EnumConstantEle_2", 405 },
   { "R004_EnumBodyDeclarations_0", 406 },
	};
}

P_SDT_genertor SDT_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
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
	case 145: factory["R004_ele_begin_0"] = P_SDT_genertor(new R004_ele_begin_0Analyzer()); break;
	case 146: factory["R004_CompilationUnit_0"] = P_SDT_genertor(new R004_CompilationUnit_0Analyzer()); break;
	case 147: factory["R004_CompilationUnit_1"] = P_SDT_genertor(new R004_CompilationUnit_1Analyzer()); break;
	case 148: factory["R004_CompilationUnit_2"] = P_SDT_genertor(new R004_CompilationUnit_2Analyzer()); break;
	case 149: factory["R004_CompilationUnit_3"] = P_SDT_genertor(new R004_CompilationUnit_3Analyzer()); break;
	case 150: factory["R004_CompilationUnit_4"] = P_SDT_genertor(new R004_CompilationUnit_4Analyzer()); break;
	case 151: factory["R004_CompilationUnit_5"] = P_SDT_genertor(new R004_CompilationUnit_5Analyzer()); break;
	case 152: factory["R004_CompilationUnit_6"] = P_SDT_genertor(new R004_CompilationUnit_6Analyzer()); break;
	case 153: factory["R004_PackageDeclaration_0"] = P_SDT_genertor(new R004_PackageDeclaration_0Analyzer()); break;
	case 154: factory["R004_PackageDeclaration_1"] = P_SDT_genertor(new R004_PackageDeclaration_1Analyzer()); break;
	case 155: factory["R004_DetailIdentifier_0"] = P_SDT_genertor(new R004_DetailIdentifier_0Analyzer()); break;
	case 156: factory["R004_DetailIdentifier_1"] = P_SDT_genertor(new R004_DetailIdentifier_1Analyzer()); break;
	case 157: factory["R004_Identifier_0"] = P_SDT_genertor(new R004_Identifier_0Analyzer()); break;
	case 158: factory["R004_ImportDeclarationList_0"] = P_SDT_genertor(new R004_ImportDeclarationList_0Analyzer()); break;
	case 159: factory["R004_ImportDeclarationList_1"] = P_SDT_genertor(new R004_ImportDeclarationList_1Analyzer()); break;
	case 160: factory["R004_ImportDeclaration_0"] = P_SDT_genertor(new R004_ImportDeclaration_0Analyzer()); break;
	case 161: factory["R004_ImportDeclaration_1"] = P_SDT_genertor(new R004_ImportDeclaration_1Analyzer()); break;
	case 162: factory["R004_ImportDeclaration_2"] = P_SDT_genertor(new R004_ImportDeclaration_2Analyzer()); break;
	case 163: factory["R004_ImportDeclaration_3"] = P_SDT_genertor(new R004_ImportDeclaration_3Analyzer()); break;
	case 164: factory["R004_TypeDeclarationList_0"] = P_SDT_genertor(new R004_TypeDeclarationList_0Analyzer()); break;
	case 165: factory["R004_TypeDeclaration_0"] = P_SDT_genertor(new R004_TypeDeclaration_0Analyzer()); break;
	case 166: factory["R004_TypeDeclaration_1"] = P_SDT_genertor(new R004_TypeDeclaration_1Analyzer()); break;
	case 167: factory["R004_TypeDeclaration_2"] = P_SDT_genertor(new R004_TypeDeclaration_2Analyzer()); break;
	case 168: factory["R004_ClassDeclaration_0"] = P_SDT_genertor(new R004_ClassDeclaration_0Analyzer()); break;
	case 169: factory["R004_ClassDeclaration_1"] = P_SDT_genertor(new R004_ClassDeclaration_1Analyzer()); break;
	case 170: factory["R004_InterfaceDeclaration_0"] = P_SDT_genertor(new R004_InterfaceDeclaration_0Analyzer()); break;
	case 171: factory["R004_InterfaceDeclaration_1"] = P_SDT_genertor(new R004_InterfaceDeclaration_1Analyzer()); break;
	case 172: factory["R004_NormalClassDeclaration_0"] = P_SDT_genertor(new R004_NormalClassDeclaration_0Analyzer()); break;
	case 173: factory["R004_NormalClassDeclaration_1"] = P_SDT_genertor(new R004_NormalClassDeclaration_1Analyzer()); break;
	case 174: factory["R004_NormalClassDeclaration_2"] = P_SDT_genertor(new R004_NormalClassDeclaration_2Analyzer()); break;
	case 175: factory["R004_NormalClassDeclaration_3"] = P_SDT_genertor(new R004_NormalClassDeclaration_3Analyzer()); break;
	case 176: factory["R004_NormalClassDeclaration_4"] = P_SDT_genertor(new R004_NormalClassDeclaration_4Analyzer()); break;
	case 177: factory["R004_NormalClassDeclaration_5"] = P_SDT_genertor(new R004_NormalClassDeclaration_5Analyzer()); break;
	case 178: factory["R004_NormalClassDeclaration_6"] = P_SDT_genertor(new R004_NormalClassDeclaration_6Analyzer()); break;
	case 179: factory["R004_NormalClassDeclaration_7"] = P_SDT_genertor(new R004_NormalClassDeclaration_7Analyzer()); break;
	case 180: factory["R004_NormalClassDeclaration_8"] = P_SDT_genertor(new R004_NormalClassDeclaration_8Analyzer()); break;
	case 181: factory["R004_NormalClassDeclaration_9"] = P_SDT_genertor(new R004_NormalClassDeclaration_9Analyzer()); break;
	case 182: factory["R004_NormalClassDeclaration_10"] = P_SDT_genertor(new R004_NormalClassDeclaration_10Analyzer()); break;
	case 183: factory["R004_NormalClassDeclaration_11"] = P_SDT_genertor(new R004_NormalClassDeclaration_11Analyzer()); break;
	case 184: factory["R004_NormalClassDeclaration_12"] = P_SDT_genertor(new R004_NormalClassDeclaration_12Analyzer()); break;
	case 185: factory["R004_NormalClassDeclaration_13"] = P_SDT_genertor(new R004_NormalClassDeclaration_13Analyzer()); break;
	case 186: factory["R004_NormalClassDeclaration_14"] = P_SDT_genertor(new R004_NormalClassDeclaration_14Analyzer()); break;
	case 187: factory["R004_NormalClassDeclaration_15"] = P_SDT_genertor(new R004_NormalClassDeclaration_15Analyzer()); break;
	case 188: factory["R004_EnumDeclaration_0"] = P_SDT_genertor(new R004_EnumDeclaration_0Analyzer()); break;
	case 189: factory["R004_EnumDeclaration_1"] = P_SDT_genertor(new R004_EnumDeclaration_1Analyzer()); break;
	case 190: factory["R004_EnumDeclaration_2"] = P_SDT_genertor(new R004_EnumDeclaration_2Analyzer()); break;
	case 191: factory["R004_EnumDeclaration_3"] = P_SDT_genertor(new R004_EnumDeclaration_3Analyzer()); break;
	case 192: factory["R004_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_0Analyzer()); break;
	case 193: factory["R004_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_1Analyzer()); break;
	case 194: factory["R004_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_2Analyzer()); break;
	case 195: factory["R004_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_3Analyzer()); break;
	case 196: factory["R004_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_4Analyzer()); break;
	case 197: factory["R004_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_5Analyzer()); break;
	case 198: factory["R004_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_6Analyzer()); break;
	case 199: factory["R004_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R004_NormalInterfaceDeclaration_7Analyzer()); break;
	case 200: factory["R004_ExtendsInterfaces_0"] = P_SDT_genertor(new R004_ExtendsInterfaces_0Analyzer()); break;
	case 201: factory["R004_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_0Analyzer()); break;
	case 202: factory["R004_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_1Analyzer()); break;
	case 203: factory["R004_AnnotationTypeDeclaration_2"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_2Analyzer()); break;
	case 204: factory["R004_AnnotationTypeDeclaration_3"] = P_SDT_genertor(new R004_AnnotationTypeDeclaration_3Analyzer()); break;
	case 205: factory["R004_ClassBody_0"] = P_SDT_genertor(new R004_ClassBody_0Analyzer()); break;
	case 206: factory["R004_ClassBodyDeclarationList_0"] = P_SDT_genertor(new R004_ClassBodyDeclarationList_0Analyzer()); break;
	case 207: factory["R004_ClassBodyDeclarationList_1"] = P_SDT_genertor(new R004_ClassBodyDeclarationList_1Analyzer()); break;
	case 208: factory["R004_ClassBodyDeclaration_0"] = P_SDT_genertor(new R004_ClassBodyDeclaration_0Analyzer()); break;
	case 209: factory["R004_ClassBodyDeclaration_1"] = P_SDT_genertor(new R004_ClassBodyDeclaration_1Analyzer()); break;
	case 210: factory["R004_ClassStatementPrefix_0"] = P_SDT_genertor(new R004_ClassStatementPrefix_0Analyzer()); break;
	case 211: factory["R004_ClassStatementPrefix_1"] = P_SDT_genertor(new R004_ClassStatementPrefix_1Analyzer()); break;
	case 212: factory["R004_NonBraceAndSemicolon_0"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_0Analyzer()); break;
	case 213: factory["R004_NonBraceAndSemicolon_1"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_1Analyzer()); break;
	case 214: factory["R004_NonBraceAndSemicolon_2"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_2Analyzer()); break;
	case 215: factory["R004_NonBraceAndSemicolon_3"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_3Analyzer()); break;
	case 216: factory["R004_NonBraceAndSemicolon_4"] = P_SDT_genertor(new R004_NonBraceAndSemicolon_4Analyzer()); break;
	case 217: factory["R004_ModifierList_0"] = P_SDT_genertor(new R004_ModifierList_0Analyzer()); break;
	case 218: factory["R004_ModifierList_1"] = P_SDT_genertor(new R004_ModifierList_1Analyzer()); break;
	case 219: factory["R004_AnnotationContent_0"] = P_SDT_genertor(new R004_AnnotationContent_0Analyzer()); break;
	case 220: factory["R004_AnnotationContentStatements_0"] = P_SDT_genertor(new R004_AnnotationContentStatements_0Analyzer()); break;
	case 221: factory["R004_AnnotationContentStatements_1"] = P_SDT_genertor(new R004_AnnotationContentStatements_1Analyzer()); break;
	case 222: factory["R004_NonPARENTHESES_0"] = P_SDT_genertor(new R004_NonPARENTHESES_0Analyzer()); break;
	case 223: factory["R004_NonPARENTHESES_1"] = P_SDT_genertor(new R004_NonPARENTHESES_1Analyzer()); break;
	case 224: factory["R004_NonPARENTHESES_2"] = P_SDT_genertor(new R004_NonPARENTHESES_2Analyzer()); break;
	case 225: factory["R004_NonPARENTHESES_3"] = P_SDT_genertor(new R004_NonPARENTHESES_3Analyzer()); break;
	case 226: factory["R004_NonPARENTHESES_4"] = P_SDT_genertor(new R004_NonPARENTHESES_4Analyzer()); break;
	case 227: factory["R004_NonPARENTHESES_5"] = P_SDT_genertor(new R004_NonPARENTHESES_5Analyzer()); break;
	case 228: factory["R004_NonPARENTHESES_6"] = P_SDT_genertor(new R004_NonPARENTHESES_6Analyzer()); break;
	case 229: factory["R004_NonPARENTHESES_7"] = P_SDT_genertor(new R004_NonPARENTHESES_7Analyzer()); break;
	case 230: factory["R004_NonPARENTHESES_8"] = P_SDT_genertor(new R004_NonPARENTHESES_8Analyzer()); break;
	case 231: factory["R004_NonPARENTHESES_9"] = P_SDT_genertor(new R004_NonPARENTHESES_9Analyzer()); break;
	case 232: factory["R004_StatementEle_0"] = P_SDT_genertor(new R004_StatementEle_0Analyzer()); break;
	case 233: factory["R004_StatementEle_1"] = P_SDT_genertor(new R004_StatementEle_1Analyzer()); break;
	case 234: factory["R004_StatementEle_2"] = P_SDT_genertor(new R004_StatementEle_2Analyzer()); break;
	case 235: factory["R004_StatementEle_3"] = P_SDT_genertor(new R004_StatementEle_3Analyzer()); break;
	case 236: factory["R004_StatementEle_4"] = P_SDT_genertor(new R004_StatementEle_4Analyzer()); break;
	case 237: factory["R004_StatementEle_5"] = P_SDT_genertor(new R004_StatementEle_5Analyzer()); break;
	case 238: factory["R004_StatementEle_6"] = P_SDT_genertor(new R004_StatementEle_6Analyzer()); break;
	case 239: factory["R004_StatementEle_7"] = P_SDT_genertor(new R004_StatementEle_7Analyzer()); break;
	case 240: factory["R004_StatementEle_8"] = P_SDT_genertor(new R004_StatementEle_8Analyzer()); break;
	case 241: factory["R004_StatementEle_9"] = P_SDT_genertor(new R004_StatementEle_9Analyzer()); break;
	case 242: factory["R004_StatementEle_10"] = P_SDT_genertor(new R004_StatementEle_10Analyzer()); break;
	case 243: factory["R004_StatementEle_11"] = P_SDT_genertor(new R004_StatementEle_11Analyzer()); break;
	case 244: factory["R004_StatementEle_12"] = P_SDT_genertor(new R004_StatementEle_12Analyzer()); break;
	case 245: factory["R004_StatementEle_13"] = P_SDT_genertor(new R004_StatementEle_13Analyzer()); break;
	case 246: factory["R004_StatementEle_14"] = P_SDT_genertor(new R004_StatementEle_14Analyzer()); break;
	case 247: factory["R004_StatementEle_15"] = P_SDT_genertor(new R004_StatementEle_15Analyzer()); break;
	case 248: factory["R004_StatementEle_16"] = P_SDT_genertor(new R004_StatementEle_16Analyzer()); break;
	case 249: factory["R004_StatementEle_17"] = P_SDT_genertor(new R004_StatementEle_17Analyzer()); break;
	case 250: factory["R004_StatementEle_18"] = P_SDT_genertor(new R004_StatementEle_18Analyzer()); break;
	case 251: factory["R004_StatementEle_19"] = P_SDT_genertor(new R004_StatementEle_19Analyzer()); break;
	case 252: factory["R004_StatementEle_20"] = P_SDT_genertor(new R004_StatementEle_20Analyzer()); break;
	case 253: factory["R004_StatementEle_21"] = P_SDT_genertor(new R004_StatementEle_21Analyzer()); break;
	case 254: factory["R004_StatementEle_22"] = P_SDT_genertor(new R004_StatementEle_22Analyzer()); break;
	case 255: factory["R004_StatementEle_23"] = P_SDT_genertor(new R004_StatementEle_23Analyzer()); break;
	case 256: factory["R004_StatementEle_24"] = P_SDT_genertor(new R004_StatementEle_24Analyzer()); break;
	case 257: factory["R004_StatementEle_25"] = P_SDT_genertor(new R004_StatementEle_25Analyzer()); break;
	case 258: factory["R004_StatementEle_26"] = P_SDT_genertor(new R004_StatementEle_26Analyzer()); break;
	case 259: factory["R004_StatementEle_27"] = P_SDT_genertor(new R004_StatementEle_27Analyzer()); break;
	case 260: factory["R004_StatementEle_28"] = P_SDT_genertor(new R004_StatementEle_28Analyzer()); break;
	case 261: factory["R004_StatementEle_29"] = P_SDT_genertor(new R004_StatementEle_29Analyzer()); break;
	case 262: factory["R004_StatementEle_30"] = P_SDT_genertor(new R004_StatementEle_30Analyzer()); break;
	case 263: factory["R004_StatementEle_31"] = P_SDT_genertor(new R004_StatementEle_31Analyzer()); break;
	case 264: factory["R004_StatementEle_32"] = P_SDT_genertor(new R004_StatementEle_32Analyzer()); break;
	case 265: factory["R004_StatementEle_33"] = P_SDT_genertor(new R004_StatementEle_33Analyzer()); break;
	case 266: factory["R004_StatementEle_34"] = P_SDT_genertor(new R004_StatementEle_34Analyzer()); break;
	case 267: factory["R004_StatementEle_35"] = P_SDT_genertor(new R004_StatementEle_35Analyzer()); break;
	case 268: factory["R004_StatementEle_36"] = P_SDT_genertor(new R004_StatementEle_36Analyzer()); break;
	case 269: factory["R004_StatementEle_37"] = P_SDT_genertor(new R004_StatementEle_37Analyzer()); break;
	case 270: factory["R004_StatementEle_38"] = P_SDT_genertor(new R004_StatementEle_38Analyzer()); break;
	case 271: factory["R004_StatementEle_39"] = P_SDT_genertor(new R004_StatementEle_39Analyzer()); break;
	case 272: factory["R004_StatementEle_40"] = P_SDT_genertor(new R004_StatementEle_40Analyzer()); break;
	case 273: factory["R004_StatementEle_41"] = P_SDT_genertor(new R004_StatementEle_41Analyzer()); break;
	case 274: factory["R004_StatementEle_42"] = P_SDT_genertor(new R004_StatementEle_42Analyzer()); break;
	case 275: factory["R004_StatementEle_43"] = P_SDT_genertor(new R004_StatementEle_43Analyzer()); break;
	case 276: factory["R004_StatementEle_44"] = P_SDT_genertor(new R004_StatementEle_44Analyzer()); break;
	case 277: factory["R004_StatementEle_45"] = P_SDT_genertor(new R004_StatementEle_45Analyzer()); break;
	case 278: factory["R004_StatementEle_46"] = P_SDT_genertor(new R004_StatementEle_46Analyzer()); break;
	case 279: factory["R004_StatementEle_47"] = P_SDT_genertor(new R004_StatementEle_47Analyzer()); break;
	case 280: factory["R004_StatementEle_48"] = P_SDT_genertor(new R004_StatementEle_48Analyzer()); break;
	case 281: factory["R004_StatementEle_49"] = P_SDT_genertor(new R004_StatementEle_49Analyzer()); break;
	case 282: factory["R004_StatementEle_50"] = P_SDT_genertor(new R004_StatementEle_50Analyzer()); break;
	case 283: factory["R004_StatementEle_51"] = P_SDT_genertor(new R004_StatementEle_51Analyzer()); break;
	case 284: factory["R004_StatementEle_52"] = P_SDT_genertor(new R004_StatementEle_52Analyzer()); break;
	case 285: factory["R004_StatementEle_53"] = P_SDT_genertor(new R004_StatementEle_53Analyzer()); break;
	case 286: factory["R004_StatementEle_54"] = P_SDT_genertor(new R004_StatementEle_54Analyzer()); break;
	case 287: factory["R004_StatementEle_55"] = P_SDT_genertor(new R004_StatementEle_55Analyzer()); break;
	case 288: factory["R004_StatementEle_56"] = P_SDT_genertor(new R004_StatementEle_56Analyzer()); break;
	case 289: factory["R004_StatementEle_57"] = P_SDT_genertor(new R004_StatementEle_57Analyzer()); break;
	case 290: factory["R004_StatementEle_58"] = P_SDT_genertor(new R004_StatementEle_58Analyzer()); break;
	case 291: factory["R004_StatementEle_59"] = P_SDT_genertor(new R004_StatementEle_59Analyzer()); break;
	case 292: factory["R004_StatementEle_60"] = P_SDT_genertor(new R004_StatementEle_60Analyzer()); break;
	case 293: factory["R004_StatementEle_61"] = P_SDT_genertor(new R004_StatementEle_61Analyzer()); break;
	case 294: factory["R004_StatementEle_62"] = P_SDT_genertor(new R004_StatementEle_62Analyzer()); break;
	case 295: factory["R004_StatementEle_63"] = P_SDT_genertor(new R004_StatementEle_63Analyzer()); break;
	case 296: factory["R004_StatementEle_64"] = P_SDT_genertor(new R004_StatementEle_64Analyzer()); break;
	case 297: factory["R004_StatementEle_65"] = P_SDT_genertor(new R004_StatementEle_65Analyzer()); break;
	case 298: factory["R004_StatementEle_66"] = P_SDT_genertor(new R004_StatementEle_66Analyzer()); break;
	case 299: factory["R004_StatementEle_67"] = P_SDT_genertor(new R004_StatementEle_67Analyzer()); break;
	case 300: factory["R004_StatementEle_68"] = P_SDT_genertor(new R004_StatementEle_68Analyzer()); break;
	case 301: factory["R004_StatementEle_69"] = P_SDT_genertor(new R004_StatementEle_69Analyzer()); break;
	case 302: factory["R004_StatementEle_70"] = P_SDT_genertor(new R004_StatementEle_70Analyzer()); break;
	case 303: factory["R004_StatementEle_71"] = P_SDT_genertor(new R004_StatementEle_71Analyzer()); break;
	case 304: factory["R004_StatementEle_72"] = P_SDT_genertor(new R004_StatementEle_72Analyzer()); break;
	case 305: factory["R004_StatementEle_73"] = P_SDT_genertor(new R004_StatementEle_73Analyzer()); break;
	case 306: factory["R004_StatementEle_74"] = P_SDT_genertor(new R004_StatementEle_74Analyzer()); break;
	case 307: factory["R004_StatementEle_75"] = P_SDT_genertor(new R004_StatementEle_75Analyzer()); break;
	case 308: factory["R004_StatementEle_76"] = P_SDT_genertor(new R004_StatementEle_76Analyzer()); break;
	case 309: factory["R004_StatementEle_77"] = P_SDT_genertor(new R004_StatementEle_77Analyzer()); break;
	case 310: factory["R004_StatementEle_78"] = P_SDT_genertor(new R004_StatementEle_78Analyzer()); break;
	case 311: factory["R004_StatementEle_79"] = P_SDT_genertor(new R004_StatementEle_79Analyzer()); break;
	case 312: factory["R004_StatementEle_80"] = P_SDT_genertor(new R004_StatementEle_80Analyzer()); break;
	case 313: factory["R004_Modifier_0"] = P_SDT_genertor(new R004_Modifier_0Analyzer()); break;
	case 314: factory["R004_Modifier_1"] = P_SDT_genertor(new R004_Modifier_1Analyzer()); break;
	case 315: factory["R004_Modifier_2"] = P_SDT_genertor(new R004_Modifier_2Analyzer()); break;
	case 316: factory["R004_Modifier_3"] = P_SDT_genertor(new R004_Modifier_3Analyzer()); break;
	case 317: factory["R004_Modifier_4"] = P_SDT_genertor(new R004_Modifier_4Analyzer()); break;
	case 318: factory["R004_Modifier_5"] = P_SDT_genertor(new R004_Modifier_5Analyzer()); break;
	case 319: factory["R004_Modifier_6"] = P_SDT_genertor(new R004_Modifier_6Analyzer()); break;
	case 320: factory["R004_Modifier_7"] = P_SDT_genertor(new R004_Modifier_7Analyzer()); break;
	case 321: factory["R004_Modifier_8"] = P_SDT_genertor(new R004_Modifier_8Analyzer()); break;
	case 322: factory["R004_Modifier_9"] = P_SDT_genertor(new R004_Modifier_9Analyzer()); break;
	case 323: factory["R004_Modifier_10"] = P_SDT_genertor(new R004_Modifier_10Analyzer()); break;
	case 324: factory["R004_Modifier_11"] = P_SDT_genertor(new R004_Modifier_11Analyzer()); break;
	case 325: factory["R004_Modifier_12"] = P_SDT_genertor(new R004_Modifier_12Analyzer()); break;
	case 326: factory["R004_MethodBody_0"] = P_SDT_genertor(new R004_MethodBody_0Analyzer()); break;
	case 327: factory["R004_MethodBody_1"] = P_SDT_genertor(new R004_MethodBody_1Analyzer()); break;
	case 328: factory["R004_Block_0"] = P_SDT_genertor(new R004_Block_0Analyzer()); break;
	case 329: factory["R004_Block_1"] = P_SDT_genertor(new R004_Block_1Analyzer()); break;
	case 330: factory["R004_BlockStatements_0"] = P_SDT_genertor(new R004_BlockStatements_0Analyzer()); break;
	case 331: factory["R004_BlockStatements_1"] = P_SDT_genertor(new R004_BlockStatements_1Analyzer()); break;
	case 332: factory["R004_BlockStatements_2"] = P_SDT_genertor(new R004_BlockStatements_2Analyzer()); break;
	case 333: factory["R004_NonBrace_0"] = P_SDT_genertor(new R004_NonBrace_0Analyzer()); break;
	case 334: factory["R004_NonBrace_1"] = P_SDT_genertor(new R004_NonBrace_1Analyzer()); break;
	case 335: factory["R004_NonBrace_2"] = P_SDT_genertor(new R004_NonBrace_2Analyzer()); break;
	case 336: factory["R004_NonBrace_3"] = P_SDT_genertor(new R004_NonBrace_3Analyzer()); break;
	case 337: factory["R004_NonBrace_4"] = P_SDT_genertor(new R004_NonBrace_4Analyzer()); break;
	case 338: factory["R004_NonBrace_5"] = P_SDT_genertor(new R004_NonBrace_5Analyzer()); break;
	case 339: factory["R004_NonBrace_6"] = P_SDT_genertor(new R004_NonBrace_6Analyzer()); break;
	case 340: factory["R004_NonBrace_7"] = P_SDT_genertor(new R004_NonBrace_7Analyzer()); break;
	case 341: factory["R004_NonBrace_8"] = P_SDT_genertor(new R004_NonBrace_8Analyzer()); break;
	case 342: factory["R004_Annotation_0"] = P_SDT_genertor(new R004_Annotation_0Analyzer()); break;
	case 343: factory["R004_Annotation_1"] = P_SDT_genertor(new R004_Annotation_1Analyzer()); break;
	case 344: factory["R004_TypeArguments_0"] = P_SDT_genertor(new R004_TypeArguments_0Analyzer()); break;
	case 345: factory["R004_TypeArgumentList_0"] = P_SDT_genertor(new R004_TypeArgumentList_0Analyzer()); break;
	case 346: factory["R004_TypeArgumentList_1"] = P_SDT_genertor(new R004_TypeArgumentList_1Analyzer()); break;
	case 347: factory["R004_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_0Analyzer()); break;
	case 348: factory["R004_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_1Analyzer()); break;
	case 349: factory["R004_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_2Analyzer()); break;
	case 350: factory["R004_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_3Analyzer()); break;
	case 351: factory["R004_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_4Analyzer()); break;
	case 352: factory["R004_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_5Analyzer()); break;
	case 353: factory["R004_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_6Analyzer()); break;
	case 354: factory["R004_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_7Analyzer()); break;
	case 355: factory["R004_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R004_NonANGLE_BRACKET_8Analyzer()); break;
	case 356: factory["R004_UnannPrimitiveType_0"] = P_SDT_genertor(new R004_UnannPrimitiveType_0Analyzer()); break;
	case 357: factory["R004_UnannPrimitiveType_1"] = P_SDT_genertor(new R004_UnannPrimitiveType_1Analyzer()); break;
	case 358: factory["R004_NumericType_0"] = P_SDT_genertor(new R004_NumericType_0Analyzer()); break;
	case 359: factory["R004_NumericType_1"] = P_SDT_genertor(new R004_NumericType_1Analyzer()); break;
	case 360: factory["R004_IntegralType_0"] = P_SDT_genertor(new R004_IntegralType_0Analyzer()); break;
	case 361: factory["R004_IntegralType_1"] = P_SDT_genertor(new R004_IntegralType_1Analyzer()); break;
	case 362: factory["R004_IntegralType_2"] = P_SDT_genertor(new R004_IntegralType_2Analyzer()); break;
	case 363: factory["R004_IntegralType_3"] = P_SDT_genertor(new R004_IntegralType_3Analyzer()); break;
	case 364: factory["R004_IntegralType_4"] = P_SDT_genertor(new R004_IntegralType_4Analyzer()); break;
	case 365: factory["R004_FloatingPointType_0"] = P_SDT_genertor(new R004_FloatingPointType_0Analyzer()); break;
	case 366: factory["R004_FloatingPointType_1"] = P_SDT_genertor(new R004_FloatingPointType_1Analyzer()); break;
	case 367: factory["R004_Superclass_0"] = P_SDT_genertor(new R004_Superclass_0Analyzer()); break;
	case 368: factory["R004_ClassTypeEle_0"] = P_SDT_genertor(new R004_ClassTypeEle_0Analyzer()); break;
	case 369: factory["R004_ClassTypeEle_1"] = P_SDT_genertor(new R004_ClassTypeEle_1Analyzer()); break;
	case 370: factory["R004_ClassTypeEle_2"] = P_SDT_genertor(new R004_ClassTypeEle_2Analyzer()); break;
	case 371: factory["R004_ClassTypeEle_3"] = P_SDT_genertor(new R004_ClassTypeEle_3Analyzer()); break;
	case 372: factory["R004_ClassType_0"] = P_SDT_genertor(new R004_ClassType_0Analyzer()); break;
	case 373: factory["R004_ClassType_1"] = P_SDT_genertor(new R004_ClassType_1Analyzer()); break;
	case 374: factory["R004_AnnotationList_0"] = P_SDT_genertor(new R004_AnnotationList_0Analyzer()); break;
	case 375: factory["R004_AnnotationList_1"] = P_SDT_genertor(new R004_AnnotationList_1Analyzer()); break;
	case 376: factory["R004_Superinterfaces_0"] = P_SDT_genertor(new R004_Superinterfaces_0Analyzer()); break;
	case 377: factory["R004_InterfaceTypeList_0"] = P_SDT_genertor(new R004_InterfaceTypeList_0Analyzer()); break;
	case 378: factory["R004_InterfaceTypeList_1"] = P_SDT_genertor(new R004_InterfaceTypeList_1Analyzer()); break;
	case 379: factory["R004_DimExpr_0"] = P_SDT_genertor(new R004_DimExpr_0Analyzer()); break;
	case 380: factory["R004_DimStatements_0"] = P_SDT_genertor(new R004_DimStatements_0Analyzer()); break;
	case 381: factory["R004_DimStatements_1"] = P_SDT_genertor(new R004_DimStatements_1Analyzer()); break;
	case 382: factory["R004_DimStatements_2"] = P_SDT_genertor(new R004_DimStatements_2Analyzer()); break;
	case 383: factory["R004_NonDim_0"] = P_SDT_genertor(new R004_NonDim_0Analyzer()); break;
	case 384: factory["R004_NonDim_1"] = P_SDT_genertor(new R004_NonDim_1Analyzer()); break;
	case 385: factory["R004_NonDim_2"] = P_SDT_genertor(new R004_NonDim_2Analyzer()); break;
	case 386: factory["R004_NonDim_3"] = P_SDT_genertor(new R004_NonDim_3Analyzer()); break;
	case 387: factory["R004_NonDim_4"] = P_SDT_genertor(new R004_NonDim_4Analyzer()); break;
	case 388: factory["R004_NonDim_5"] = P_SDT_genertor(new R004_NonDim_5Analyzer()); break;
	case 389: factory["R004_NonDim_6"] = P_SDT_genertor(new R004_NonDim_6Analyzer()); break;
	case 390: factory["R004_NonDim_7"] = P_SDT_genertor(new R004_NonDim_7Analyzer()); break;
	case 391: factory["R004_NonDim_8"] = P_SDT_genertor(new R004_NonDim_8Analyzer()); break;
	case 392: factory["R004_NonDim_9"] = P_SDT_genertor(new R004_NonDim_9Analyzer()); break;
	case 393: factory["R004_EnumBody_0"] = P_SDT_genertor(new R004_EnumBody_0Analyzer()); break;
	case 394: factory["R004_EnumBody_1"] = P_SDT_genertor(new R004_EnumBody_1Analyzer()); break;
	case 395: factory["R004_EnumBody_2"] = P_SDT_genertor(new R004_EnumBody_2Analyzer()); break;
	case 396: factory["R004_EnumBody_3"] = P_SDT_genertor(new R004_EnumBody_3Analyzer()); break;
	case 397: factory["R004_EnumBody_4"] = P_SDT_genertor(new R004_EnumBody_4Analyzer()); break;
	case 398: factory["R004_EnumBody_5"] = P_SDT_genertor(new R004_EnumBody_5Analyzer()); break;
	case 399: factory["R004_EnumBody_6"] = P_SDT_genertor(new R004_EnumBody_6Analyzer()); break;
	case 400: factory["R004_EnumBody_7"] = P_SDT_genertor(new R004_EnumBody_7Analyzer()); break;
	case 401: factory["R004_EnumConstantList_0"] = P_SDT_genertor(new R004_EnumConstantList_0Analyzer()); break;
	case 402: factory["R004_EnumConstantList_1"] = P_SDT_genertor(new R004_EnumConstantList_1Analyzer()); break;
	case 403: factory["R004_EnumConstantEle_0"] = P_SDT_genertor(new R004_EnumConstantEle_0Analyzer()); break;
	case 404: factory["R004_EnumConstantEle_1"] = P_SDT_genertor(new R004_EnumConstantEle_1Analyzer()); break;
	case 405: factory["R004_EnumConstantEle_2"] = P_SDT_genertor(new R004_EnumConstantEle_2Analyzer()); break;
	case 406: factory["R004_EnumBodyDeclarations_0"] = P_SDT_genertor(new R004_EnumBodyDeclarations_0Analyzer()); break;
	default:
		if (key.find("R003_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R003_DefaultAnalyzer());
			}
		}


		if (key.find("R004_") == 0) {
			vector <string> string_list;
			split(string_list, key, is_any_of("_"));
			if (string_list[1] == "0" || string_list[1].find("'") == 0) {
				factory[key] = P_SDT_genertor(new R004_DefaultAnalyzer());
			}
		}

		//if (key.find("R005_") == 0) {
		//	vector <string> string_list;
		//	split(string_list, key, is_any_of("_"));
		//	if (string_list[1] == "0" || string_list[1].find("'") == 0) {
		//		factory[key] = P_SDT_genertor(new R005_DefaultAnalyzer());
		//	}
		//}
	}



	return factory[key];
}
SDT_Factory::~SDT_Factory() {}


