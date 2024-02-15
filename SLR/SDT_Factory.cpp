#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R003Analyzer.h"
#include "../treeAnalyzer/java/R004Analyzer.h"
#include "../treeAnalyzer/java/R005Analyzer.h"
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
   { "R005_ele_begin_0", 407 },
   { "R005_ClassBodyDeclaration_0", 408 },
   { "R005_ClassBodyDeclaration_1", 409 },
   { "R005_ClassBodyDeclaration_2", 410 },
   { "R005_ClassBodyDeclaration_3", 411 },
   { "R005_ClassMemberDeclaration_0", 412 },
   { "R005_ClassMemberDeclaration_1", 413 },
   { "R005_ClassMemberDeclaration_2", 414 },
   { "R005_ClassMemberDeclaration_3", 415 },
   { "R005_ClassMemberDeclaration_4", 416 },
   { "R005_FieldDeclaration_0", 417 },
   { "R005_FieldDeclaration_1", 418 },
   { "R005_FieldDeclarationFake_0", 419 },
   { "R005_FieldDeclarationFake_1", 420 },
   { "R005_InstanceInitializer_0", 421 },
   { "R005_StaticInitializer_0", 422 },
   { "R005_Block_0", 423 },
   { "R005_Block_1", 424 },
   { "R005_BlockStatements_0", 425 },
   { "R005_BlockStatements_1", 426 },
   { "R005_BlockStatements_2", 427 },
   { "R005_NonBrace_0", 428 },
   { "R005_NonBrace_1", 429 },
   { "R005_NonBrace_2", 430 },
   { "R005_NonBrace_3", 431 },
   { "R005_NonBrace_4", 432 },
   { "R005_NonBrace_5", 433 },
   { "R005_NonBrace_6", 434 },
   { "R005_NonBrace_7", 435 },
   { "R005_NonBrace_8", 436 },
   { "R005_NonBrace_9", 437 },
   { "R005_StatementEle_0", 438 },
   { "R005_StatementEle_1", 439 },
   { "R005_StatementEle_2", 440 },
   { "R005_StatementEle_3", 441 },
   { "R005_StatementEle_4", 442 },
   { "R005_StatementEle_5", 443 },
   { "R005_StatementEle_6", 444 },
   { "R005_StatementEle_7", 445 },
   { "R005_StatementEle_8", 446 },
   { "R005_StatementEle_9", 447 },
   { "R005_StatementEle_10", 448 },
   { "R005_StatementEle_11", 449 },
   { "R005_StatementEle_12", 450 },
   { "R005_StatementEle_13", 451 },
   { "R005_StatementEle_14", 452 },
   { "R005_StatementEle_15", 453 },
   { "R005_StatementEle_16", 454 },
   { "R005_StatementEle_17", 455 },
   { "R005_StatementEle_18", 456 },
   { "R005_StatementEle_19", 457 },
   { "R005_StatementEle_20", 458 },
   { "R005_StatementEle_21", 459 },
   { "R005_StatementEle_22", 460 },
   { "R005_StatementEle_23", 461 },
   { "R005_StatementEle_24", 462 },
   { "R005_StatementEle_25", 463 },
   { "R005_StatementEle_26", 464 },
   { "R005_StatementEle_27", 465 },
   { "R005_StatementEle_28", 466 },
   { "R005_StatementEle_29", 467 },
   { "R005_StatementEle_30", 468 },
   { "R005_StatementEle_31", 469 },
   { "R005_StatementEle_32", 470 },
   { "R005_StatementEle_33", 471 },
   { "R005_StatementEle_34", 472 },
   { "R005_StatementEle_35", 473 },
   { "R005_StatementEle_36", 474 },
   { "R005_StatementEle_37", 475 },
   { "R005_StatementEle_38", 476 },
   { "R005_StatementEle_39", 477 },
   { "R005_StatementEle_40", 478 },
   { "R005_StatementEle_41", 479 },
   { "R005_StatementEle_42", 480 },
   { "R005_StatementEle_43", 481 },
   { "R005_StatementEle_44", 482 },
   { "R005_StatementEle_45", 483 },
   { "R005_StatementEle_46", 484 },
   { "R005_StatementEle_47", 485 },
   { "R005_StatementEle_48", 486 },
   { "R005_StatementEle_49", 487 },
   { "R005_StatementEle_50", 488 },
   { "R005_StatementEle_51", 489 },
   { "R005_StatementEle_52", 490 },
   { "R005_StatementEle_53", 491 },
   { "R005_StatementEle_54", 492 },
   { "R005_StatementEle_55", 493 },
   { "R005_StatementEle_56", 494 },
   { "R005_StatementEle_57", 495 },
   { "R005_StatementEle_58", 496 },
   { "R005_StatementEle_59", 497 },
   { "R005_StatementEle_60", 498 },
   { "R005_StatementEle_61", 499 },
   { "R005_StatementEle_62", 500 },
   { "R005_StatementEle_63", 501 },
   { "R005_StatementEle_64", 502 },
   { "R005_StatementEle_65", 503 },
   { "R005_StatementEle_66", 504 },
   { "R005_StatementEle_67", 505 },
   { "R005_StatementEle_68", 506 },
   { "R005_StatementEle_69", 507 },
   { "R005_StatementEle_70", 508 },
   { "R005_StatementEle_71", 509 },
   { "R005_StatementEle_72", 510 },
   { "R005_StatementEle_73", 511 },
   { "R005_StatementEle_74", 512 },
   { "R005_StatementEle_75", 513 },
   { "R005_StatementEle_76", 514 },
   { "R005_StatementEle_77", 515 },
   { "R005_StatementEle_78", 516 },
   { "R005_StatementEle_79", 517 },
   { "R005_Identifier_0", 518 },
   { "R005_ModifierList_0", 519 },
   { "R005_ModifierList_1", 520 },
   { "R005_Modifier_0", 521 },
   { "R005_Modifier_1", 522 },
   { "R005_Modifier_2", 523 },
   { "R005_Modifier_3", 524 },
   { "R005_Modifier_4", 525 },
   { "R005_Modifier_5", 526 },
   { "R005_Modifier_6", 527 },
   { "R005_Modifier_7", 528 },
   { "R005_Modifier_8", 529 },
   { "R005_Modifier_9", 530 },
   { "R005_Modifier_10", 531 },
   { "R005_Modifier_11", 532 },
   { "R005_Modifier_12", 533 },
   { "R005_Annotation_0", 534 },
   { "R005_Annotation_1", 535 },
   { "R005_DetailIdentifier_0", 536 },
   { "R005_DetailIdentifier_1", 537 },
   { "R005_AnnotationContent_0", 538 },
   { "R005_AnnotationContentStatements_0", 539 },
   { "R005_AnnotationContentStatements_1", 540 },
   { "R005_NonPARENTHESES_0", 541 },
   { "R005_NonPARENTHESES_1", 542 },
   { "R005_NonPARENTHESES_2", 543 },
   { "R005_NonPARENTHESES_3", 544 },
   { "R005_NonPARENTHESES_4", 545 },
   { "R005_NonPARENTHESES_5", 546 },
   { "R005_NonPARENTHESES_6", 547 },
   { "R005_NonPARENTHESES_7", 548 },
   { "R005_NonPARENTHESES_8", 549 },
   { "R005_NonPARENTHESES_9", 550 },
   { "R005_NonPARENTHESES_10", 551 },
   { "R005_TypeArguments_0", 552 },
   { "R005_TypeArgumentList_0", 553 },
   { "R005_TypeArgumentList_1", 554 },
   { "R005_NonANGLE_BRACKET_0", 555 },
   { "R005_NonANGLE_BRACKET_1", 556 },
   { "R005_NonANGLE_BRACKET_2", 557 },
   { "R005_NonANGLE_BRACKET_3", 558 },
   { "R005_NonANGLE_BRACKET_4", 559 },
   { "R005_NonANGLE_BRACKET_5", 560 },
   { "R005_NonANGLE_BRACKET_6", 561 },
   { "R005_NonANGLE_BRACKET_7", 562 },
   { "R005_NonANGLE_BRACKET_8", 563 },
   { "R005_Dims_0", 564 },
   { "R005_Dims_1", 565 },
   { "R005_Dims_2", 566 },
   { "R005_Dims_3", 567 },
   { "R005_UnannType_0", 568 },
   { "R005_UnannType_1", 569 },
   { "R005_UnannType_2", 570 },
   { "R005_UnannPrimitiveType_0", 571 },
   { "R005_UnannPrimitiveType_1", 572 },
   { "R005_UnannPrimitiveType_2", 573 },
   { "R005_UnannPrimitiveType_3", 574 },
   { "R005_UnannPrimitiveType_4", 575 },
   { "R005_UnannPrimitiveType_5", 576 },
   { "R005_UnannPrimitiveType_6", 577 },
   { "R005_UnannPrimitiveType_7", 578 },
   { "R005_UnannClassOrInterfaceType_0", 579 },
   { "R005_UnannClassOrInterfaceType_1", 580 },
   { "R005_UnannClassOrInterfaceType_2", 581 },
   { "R005_UnannClassOrInterfaceType_3", 582 },
   { "R005_UnannClassOrInterfaceType_4", 583 },
   { "R005_UnannClassOrInterfaceType_5", 584 },
   { "R005_UnannArrayType_0", 585 },
   { "R005_UnannArrayType_1", 586 },
   { "R005_VariableDeclaratorList_0", 587 },
   { "R005_VariableDeclaratorList_1", 588 },
   { "R005_VariableDeclarator_0", 589 },
   { "R005_VariableDeclarator_1", 590 },
   { "R005_VariableInitializer_0", 591 },
   { "R005_VariableInitializer_1", 592 },
   { "R005_VariableInitializerEle_0", 593 },
   { "R005_VariableInitializerEle_1", 594 },
   { "R005_VariableInitializerEle_2", 595 },
   { "R005_VariableInitializerEle_3", 596 },
   { "R005_VariableDeclaratorId_0", 597 },
   { "R005_VariableDeclaratorId_1", 598 },
   { "R005_MethodDeclaration_0", 599 },
   { "R005_MethodDeclaration_1", 600 },
   { "R005_MethodDeclaration_2", 601 },
   { "R005_MethodDeclaration_3", 602 },
   { "R005_MethodDeclaration_4", 603 },
   { "R005_MethodDeclaration_5", 604 },
   { "R005_MethodDeclaration_6", 605 },
   { "R005_MethodDeclaration_7", 606 },
   { "R005_MethodHeader_0", 607 },
   { "R005_MethodHeader_1", 608 },
   { "R005_Result_0", 609 },
   { "R005_Result_1", 610 },
   { "R005_MethodDeclarator_0", 611 },
   { "R005_MethodDeclarator_1", 612 },
   { "R005_Throws_0", 613 },
   { "R005_ExceptionTypeList_0", 614 },
   { "R005_ExceptionTypeList_1", 615 },
   { "R005_ExceptionType_0", 616 },
   { "R005_ExceptionType_1", 617 },
   { "R005_ConstructorDeclaration_0", 618 },
   { "R005_ConstructorDeclaration_1", 619 },
   { "R005_ConstructorDeclaration_2", 620 },
   { "R005_ConstructorDeclaration_3", 621 },
   { "R005_ConstructorDeclarator_0", 622 },
   { "R005_ConstructorDeclarator_1", 623 },
   { "R005_ClassDeclaration_0", 624 },
   { "R005_ClassDeclaration_1", 625 },
   { "R005_NormalClassDeclaration_0", 626 },
   { "R005_NormalClassDeclaration_1", 627 },
   { "R005_NormalClassDeclaration_2", 628 },
   { "R005_NormalClassDeclaration_3", 629 },
   { "R005_NormalClassDeclaration_4", 630 },
   { "R005_NormalClassDeclaration_5", 631 },
   { "R005_NormalClassDeclaration_6", 632 },
   { "R005_NormalClassDeclaration_7", 633 },
   { "R005_NormalClassDeclaration_8", 634 },
   { "R005_NormalClassDeclaration_9", 635 },
   { "R005_NormalClassDeclaration_10", 636 },
   { "R005_NormalClassDeclaration_11", 637 },
   { "R005_NormalClassDeclaration_12", 638 },
   { "R005_NormalClassDeclaration_13", 639 },
   { "R005_NormalClassDeclaration_14", 640 },
   { "R005_NormalClassDeclaration_15", 641 },
   { "R005_Superclass_0", 642 },
   { "R005_ClassTypeEle_0", 643 },
   { "R005_ClassTypeEle_1", 644 },
   { "R005_ClassTypeEle_2", 645 },
   { "R005_ClassTypeEle_3", 646 },
   { "R005_ClassType_0", 647 },
   { "R005_ClassType_1", 648 },
   { "R005_Superinterfaces_0", 649 },
   { "R005_InterfaceTypeList_0", 650 },
   { "R005_InterfaceTypeList_1", 651 },
   { "R005_EnumDeclaration_0", 652 },
   { "R005_EnumDeclaration_1", 653 },
   { "R005_EnumDeclaration_2", 654 },
   { "R005_EnumDeclaration_3", 655 },
   { "R005_InterfaceDeclaration_0", 656 },
   { "R005_InterfaceDeclaration_1", 657 },
   { "R005_NormalInterfaceDeclaration_0", 658 },
   { "R005_NormalInterfaceDeclaration_1", 659 },
   { "R005_NormalInterfaceDeclaration_2", 660 },
   { "R005_NormalInterfaceDeclaration_3", 661 },
   { "R005_NormalInterfaceDeclaration_4", 662 },
   { "R005_NormalInterfaceDeclaration_5", 663 },
   { "R005_NormalInterfaceDeclaration_6", 664 },
   { "R005_NormalInterfaceDeclaration_7", 665 },
   { "R005_ExtendsInterfaces_0", 666 },
   { "R005_AnnotationTypeDeclaration_0", 667 },
   { "R005_AnnotationTypeDeclaration_1", 668 },
   { "R005_AnnotationTypeDeclaration_2", 669 },
   { "R005_AnnotationTypeDeclaration_3", 670 },
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
	case 407: factory["R005_ele_begin_0"] = P_SDT_genertor(new R005_ele_begin_0Analyzer()); break;
	case 408: factory["R005_ClassBodyDeclaration_0"] = P_SDT_genertor(new R005_ClassBodyDeclaration_0Analyzer()); break;
	case 409: factory["R005_ClassBodyDeclaration_1"] = P_SDT_genertor(new R005_ClassBodyDeclaration_1Analyzer()); break;
	case 410: factory["R005_ClassBodyDeclaration_2"] = P_SDT_genertor(new R005_ClassBodyDeclaration_2Analyzer()); break;
	case 411: factory["R005_ClassBodyDeclaration_3"] = P_SDT_genertor(new R005_ClassBodyDeclaration_3Analyzer()); break;
	case 412: factory["R005_ClassMemberDeclaration_0"] = P_SDT_genertor(new R005_ClassMemberDeclaration_0Analyzer()); break;
	case 413: factory["R005_ClassMemberDeclaration_1"] = P_SDT_genertor(new R005_ClassMemberDeclaration_1Analyzer()); break;
	case 414: factory["R005_ClassMemberDeclaration_2"] = P_SDT_genertor(new R005_ClassMemberDeclaration_2Analyzer()); break;
	case 415: factory["R005_ClassMemberDeclaration_3"] = P_SDT_genertor(new R005_ClassMemberDeclaration_3Analyzer()); break;
	case 416: factory["R005_ClassMemberDeclaration_4"] = P_SDT_genertor(new R005_ClassMemberDeclaration_4Analyzer()); break;
	case 417: factory["R005_FieldDeclaration_0"] = P_SDT_genertor(new R005_FieldDeclaration_0Analyzer()); break;
	case 418: factory["R005_FieldDeclaration_1"] = P_SDT_genertor(new R005_FieldDeclaration_1Analyzer()); break;
	case 419: factory["R005_FieldDeclarationFake_0"] = P_SDT_genertor(new R005_FieldDeclarationFake_0Analyzer()); break;
	case 420: factory["R005_FieldDeclarationFake_1"] = P_SDT_genertor(new R005_FieldDeclarationFake_1Analyzer()); break;
	case 421: factory["R005_InstanceInitializer_0"] = P_SDT_genertor(new R005_InstanceInitializer_0Analyzer()); break;
	case 422: factory["R005_StaticInitializer_0"] = P_SDT_genertor(new R005_StaticInitializer_0Analyzer()); break;
	case 423: factory["R005_Block_0"] = P_SDT_genertor(new R005_Block_0Analyzer()); break;
	case 424: factory["R005_Block_1"] = P_SDT_genertor(new R005_Block_1Analyzer()); break;
	case 425: factory["R005_BlockStatements_0"] = P_SDT_genertor(new R005_BlockStatements_0Analyzer()); break;
	case 426: factory["R005_BlockStatements_1"] = P_SDT_genertor(new R005_BlockStatements_1Analyzer()); break;
	case 427: factory["R005_BlockStatements_2"] = P_SDT_genertor(new R005_BlockStatements_2Analyzer()); break;
	case 428: factory["R005_NonBrace_0"] = P_SDT_genertor(new R005_NonBrace_0Analyzer()); break;
	case 429: factory["R005_NonBrace_1"] = P_SDT_genertor(new R005_NonBrace_1Analyzer()); break;
	case 430: factory["R005_NonBrace_2"] = P_SDT_genertor(new R005_NonBrace_2Analyzer()); break;
	case 431: factory["R005_NonBrace_3"] = P_SDT_genertor(new R005_NonBrace_3Analyzer()); break;
	case 432: factory["R005_NonBrace_4"] = P_SDT_genertor(new R005_NonBrace_4Analyzer()); break;
	case 433: factory["R005_NonBrace_5"] = P_SDT_genertor(new R005_NonBrace_5Analyzer()); break;
	case 434: factory["R005_NonBrace_6"] = P_SDT_genertor(new R005_NonBrace_6Analyzer()); break;
	case 435: factory["R005_NonBrace_7"] = P_SDT_genertor(new R005_NonBrace_7Analyzer()); break;
	case 436: factory["R005_NonBrace_8"] = P_SDT_genertor(new R005_NonBrace_8Analyzer()); break;
	case 437: factory["R005_NonBrace_9"] = P_SDT_genertor(new R005_NonBrace_9Analyzer()); break;
	case 438: factory["R005_StatementEle_0"] = P_SDT_genertor(new R005_StatementEle_0Analyzer()); break;
	case 439: factory["R005_StatementEle_1"] = P_SDT_genertor(new R005_StatementEle_1Analyzer()); break;
	case 440: factory["R005_StatementEle_2"] = P_SDT_genertor(new R005_StatementEle_2Analyzer()); break;
	case 441: factory["R005_StatementEle_3"] = P_SDT_genertor(new R005_StatementEle_3Analyzer()); break;
	case 442: factory["R005_StatementEle_4"] = P_SDT_genertor(new R005_StatementEle_4Analyzer()); break;
	case 443: factory["R005_StatementEle_5"] = P_SDT_genertor(new R005_StatementEle_5Analyzer()); break;
	case 444: factory["R005_StatementEle_6"] = P_SDT_genertor(new R005_StatementEle_6Analyzer()); break;
	case 445: factory["R005_StatementEle_7"] = P_SDT_genertor(new R005_StatementEle_7Analyzer()); break;
	case 446: factory["R005_StatementEle_8"] = P_SDT_genertor(new R005_StatementEle_8Analyzer()); break;
	case 447: factory["R005_StatementEle_9"] = P_SDT_genertor(new R005_StatementEle_9Analyzer()); break;
	case 448: factory["R005_StatementEle_10"] = P_SDT_genertor(new R005_StatementEle_10Analyzer()); break;
	case 449: factory["R005_StatementEle_11"] = P_SDT_genertor(new R005_StatementEle_11Analyzer()); break;
	case 450: factory["R005_StatementEle_12"] = P_SDT_genertor(new R005_StatementEle_12Analyzer()); break;
	case 451: factory["R005_StatementEle_13"] = P_SDT_genertor(new R005_StatementEle_13Analyzer()); break;
	case 452: factory["R005_StatementEle_14"] = P_SDT_genertor(new R005_StatementEle_14Analyzer()); break;
	case 453: factory["R005_StatementEle_15"] = P_SDT_genertor(new R005_StatementEle_15Analyzer()); break;
	case 454: factory["R005_StatementEle_16"] = P_SDT_genertor(new R005_StatementEle_16Analyzer()); break;
	case 455: factory["R005_StatementEle_17"] = P_SDT_genertor(new R005_StatementEle_17Analyzer()); break;
	case 456: factory["R005_StatementEle_18"] = P_SDT_genertor(new R005_StatementEle_18Analyzer()); break;
	case 457: factory["R005_StatementEle_19"] = P_SDT_genertor(new R005_StatementEle_19Analyzer()); break;
	case 458: factory["R005_StatementEle_20"] = P_SDT_genertor(new R005_StatementEle_20Analyzer()); break;
	case 459: factory["R005_StatementEle_21"] = P_SDT_genertor(new R005_StatementEle_21Analyzer()); break;
	case 460: factory["R005_StatementEle_22"] = P_SDT_genertor(new R005_StatementEle_22Analyzer()); break;
	case 461: factory["R005_StatementEle_23"] = P_SDT_genertor(new R005_StatementEle_23Analyzer()); break;
	case 462: factory["R005_StatementEle_24"] = P_SDT_genertor(new R005_StatementEle_24Analyzer()); break;
	case 463: factory["R005_StatementEle_25"] = P_SDT_genertor(new R005_StatementEle_25Analyzer()); break;
	case 464: factory["R005_StatementEle_26"] = P_SDT_genertor(new R005_StatementEle_26Analyzer()); break;
	case 465: factory["R005_StatementEle_27"] = P_SDT_genertor(new R005_StatementEle_27Analyzer()); break;
	case 466: factory["R005_StatementEle_28"] = P_SDT_genertor(new R005_StatementEle_28Analyzer()); break;
	case 467: factory["R005_StatementEle_29"] = P_SDT_genertor(new R005_StatementEle_29Analyzer()); break;
	case 468: factory["R005_StatementEle_30"] = P_SDT_genertor(new R005_StatementEle_30Analyzer()); break;
	case 469: factory["R005_StatementEle_31"] = P_SDT_genertor(new R005_StatementEle_31Analyzer()); break;
	case 470: factory["R005_StatementEle_32"] = P_SDT_genertor(new R005_StatementEle_32Analyzer()); break;
	case 471: factory["R005_StatementEle_33"] = P_SDT_genertor(new R005_StatementEle_33Analyzer()); break;
	case 472: factory["R005_StatementEle_34"] = P_SDT_genertor(new R005_StatementEle_34Analyzer()); break;
	case 473: factory["R005_StatementEle_35"] = P_SDT_genertor(new R005_StatementEle_35Analyzer()); break;
	case 474: factory["R005_StatementEle_36"] = P_SDT_genertor(new R005_StatementEle_36Analyzer()); break;
	case 475: factory["R005_StatementEle_37"] = P_SDT_genertor(new R005_StatementEle_37Analyzer()); break;
	case 476: factory["R005_StatementEle_38"] = P_SDT_genertor(new R005_StatementEle_38Analyzer()); break;
	case 477: factory["R005_StatementEle_39"] = P_SDT_genertor(new R005_StatementEle_39Analyzer()); break;
	case 478: factory["R005_StatementEle_40"] = P_SDT_genertor(new R005_StatementEle_40Analyzer()); break;
	case 479: factory["R005_StatementEle_41"] = P_SDT_genertor(new R005_StatementEle_41Analyzer()); break;
	case 480: factory["R005_StatementEle_42"] = P_SDT_genertor(new R005_StatementEle_42Analyzer()); break;
	case 481: factory["R005_StatementEle_43"] = P_SDT_genertor(new R005_StatementEle_43Analyzer()); break;
	case 482: factory["R005_StatementEle_44"] = P_SDT_genertor(new R005_StatementEle_44Analyzer()); break;
	case 483: factory["R005_StatementEle_45"] = P_SDT_genertor(new R005_StatementEle_45Analyzer()); break;
	case 484: factory["R005_StatementEle_46"] = P_SDT_genertor(new R005_StatementEle_46Analyzer()); break;
	case 485: factory["R005_StatementEle_47"] = P_SDT_genertor(new R005_StatementEle_47Analyzer()); break;
	case 486: factory["R005_StatementEle_48"] = P_SDT_genertor(new R005_StatementEle_48Analyzer()); break;
	case 487: factory["R005_StatementEle_49"] = P_SDT_genertor(new R005_StatementEle_49Analyzer()); break;
	case 488: factory["R005_StatementEle_50"] = P_SDT_genertor(new R005_StatementEle_50Analyzer()); break;
	case 489: factory["R005_StatementEle_51"] = P_SDT_genertor(new R005_StatementEle_51Analyzer()); break;
	case 490: factory["R005_StatementEle_52"] = P_SDT_genertor(new R005_StatementEle_52Analyzer()); break;
	case 491: factory["R005_StatementEle_53"] = P_SDT_genertor(new R005_StatementEle_53Analyzer()); break;
	case 492: factory["R005_StatementEle_54"] = P_SDT_genertor(new R005_StatementEle_54Analyzer()); break;
	case 493: factory["R005_StatementEle_55"] = P_SDT_genertor(new R005_StatementEle_55Analyzer()); break;
	case 494: factory["R005_StatementEle_56"] = P_SDT_genertor(new R005_StatementEle_56Analyzer()); break;
	case 495: factory["R005_StatementEle_57"] = P_SDT_genertor(new R005_StatementEle_57Analyzer()); break;
	case 496: factory["R005_StatementEle_58"] = P_SDT_genertor(new R005_StatementEle_58Analyzer()); break;
	case 497: factory["R005_StatementEle_59"] = P_SDT_genertor(new R005_StatementEle_59Analyzer()); break;
	case 498: factory["R005_StatementEle_60"] = P_SDT_genertor(new R005_StatementEle_60Analyzer()); break;
	case 499: factory["R005_StatementEle_61"] = P_SDT_genertor(new R005_StatementEle_61Analyzer()); break;
	case 500: factory["R005_StatementEle_62"] = P_SDT_genertor(new R005_StatementEle_62Analyzer()); break;
	case 501: factory["R005_StatementEle_63"] = P_SDT_genertor(new R005_StatementEle_63Analyzer()); break;
	case 502: factory["R005_StatementEle_64"] = P_SDT_genertor(new R005_StatementEle_64Analyzer()); break;
	case 503: factory["R005_StatementEle_65"] = P_SDT_genertor(new R005_StatementEle_65Analyzer()); break;
	case 504: factory["R005_StatementEle_66"] = P_SDT_genertor(new R005_StatementEle_66Analyzer()); break;
	case 505: factory["R005_StatementEle_67"] = P_SDT_genertor(new R005_StatementEle_67Analyzer()); break;
	case 506: factory["R005_StatementEle_68"] = P_SDT_genertor(new R005_StatementEle_68Analyzer()); break;
	case 507: factory["R005_StatementEle_69"] = P_SDT_genertor(new R005_StatementEle_69Analyzer()); break;
	case 508: factory["R005_StatementEle_70"] = P_SDT_genertor(new R005_StatementEle_70Analyzer()); break;
	case 509: factory["R005_StatementEle_71"] = P_SDT_genertor(new R005_StatementEle_71Analyzer()); break;
	case 510: factory["R005_StatementEle_72"] = P_SDT_genertor(new R005_StatementEle_72Analyzer()); break;
	case 511: factory["R005_StatementEle_73"] = P_SDT_genertor(new R005_StatementEle_73Analyzer()); break;
	case 512: factory["R005_StatementEle_74"] = P_SDT_genertor(new R005_StatementEle_74Analyzer()); break;
	case 513: factory["R005_StatementEle_75"] = P_SDT_genertor(new R005_StatementEle_75Analyzer()); break;
	case 514: factory["R005_StatementEle_76"] = P_SDT_genertor(new R005_StatementEle_76Analyzer()); break;
	case 515: factory["R005_StatementEle_77"] = P_SDT_genertor(new R005_StatementEle_77Analyzer()); break;
	case 516: factory["R005_StatementEle_78"] = P_SDT_genertor(new R005_StatementEle_78Analyzer()); break;
	case 517: factory["R005_StatementEle_79"] = P_SDT_genertor(new R005_StatementEle_79Analyzer()); break;
	case 518: factory["R005_Identifier_0"] = P_SDT_genertor(new R005_Identifier_0Analyzer()); break;
	case 519: factory["R005_ModifierList_0"] = P_SDT_genertor(new R005_ModifierList_0Analyzer()); break;
	case 520: factory["R005_ModifierList_1"] = P_SDT_genertor(new R005_ModifierList_1Analyzer()); break;
	case 521: factory["R005_Modifier_0"] = P_SDT_genertor(new R005_Modifier_0Analyzer()); break;
	case 522: factory["R005_Modifier_1"] = P_SDT_genertor(new R005_Modifier_1Analyzer()); break;
	case 523: factory["R005_Modifier_2"] = P_SDT_genertor(new R005_Modifier_2Analyzer()); break;
	case 524: factory["R005_Modifier_3"] = P_SDT_genertor(new R005_Modifier_3Analyzer()); break;
	case 525: factory["R005_Modifier_4"] = P_SDT_genertor(new R005_Modifier_4Analyzer()); break;
	case 526: factory["R005_Modifier_5"] = P_SDT_genertor(new R005_Modifier_5Analyzer()); break;
	case 527: factory["R005_Modifier_6"] = P_SDT_genertor(new R005_Modifier_6Analyzer()); break;
	case 528: factory["R005_Modifier_7"] = P_SDT_genertor(new R005_Modifier_7Analyzer()); break;
	case 529: factory["R005_Modifier_8"] = P_SDT_genertor(new R005_Modifier_8Analyzer()); break;
	case 530: factory["R005_Modifier_9"] = P_SDT_genertor(new R005_Modifier_9Analyzer()); break;
	case 531: factory["R005_Modifier_10"] = P_SDT_genertor(new R005_Modifier_10Analyzer()); break;
	case 532: factory["R005_Modifier_11"] = P_SDT_genertor(new R005_Modifier_11Analyzer()); break;
	case 533: factory["R005_Modifier_12"] = P_SDT_genertor(new R005_Modifier_12Analyzer()); break;
	case 534: factory["R005_Annotation_0"] = P_SDT_genertor(new R005_Annotation_0Analyzer()); break;
	case 535: factory["R005_Annotation_1"] = P_SDT_genertor(new R005_Annotation_1Analyzer()); break;
	case 536: factory["R005_DetailIdentifier_0"] = P_SDT_genertor(new R005_DetailIdentifier_0Analyzer()); break;
	case 537: factory["R005_DetailIdentifier_1"] = P_SDT_genertor(new R005_DetailIdentifier_1Analyzer()); break;
	case 538: factory["R005_AnnotationContent_0"] = P_SDT_genertor(new R005_AnnotationContent_0Analyzer()); break;
	case 539: factory["R005_AnnotationContentStatements_0"] = P_SDT_genertor(new R005_AnnotationContentStatements_0Analyzer()); break;
	case 540: factory["R005_AnnotationContentStatements_1"] = P_SDT_genertor(new R005_AnnotationContentStatements_1Analyzer()); break;
	case 541: factory["R005_NonPARENTHESES_0"] = P_SDT_genertor(new R005_NonPARENTHESES_0Analyzer()); break;
	case 542: factory["R005_NonPARENTHESES_1"] = P_SDT_genertor(new R005_NonPARENTHESES_1Analyzer()); break;
	case 543: factory["R005_NonPARENTHESES_2"] = P_SDT_genertor(new R005_NonPARENTHESES_2Analyzer()); break;
	case 544: factory["R005_NonPARENTHESES_3"] = P_SDT_genertor(new R005_NonPARENTHESES_3Analyzer()); break;
	case 545: factory["R005_NonPARENTHESES_4"] = P_SDT_genertor(new R005_NonPARENTHESES_4Analyzer()); break;
	case 546: factory["R005_NonPARENTHESES_5"] = P_SDT_genertor(new R005_NonPARENTHESES_5Analyzer()); break;
	case 547: factory["R005_NonPARENTHESES_6"] = P_SDT_genertor(new R005_NonPARENTHESES_6Analyzer()); break;
	case 548: factory["R005_NonPARENTHESES_7"] = P_SDT_genertor(new R005_NonPARENTHESES_7Analyzer()); break;
	case 549: factory["R005_NonPARENTHESES_8"] = P_SDT_genertor(new R005_NonPARENTHESES_8Analyzer()); break;
	case 550: factory["R005_NonPARENTHESES_9"] = P_SDT_genertor(new R005_NonPARENTHESES_9Analyzer()); break;
	case 551: factory["R005_NonPARENTHESES_10"] = P_SDT_genertor(new R005_NonPARENTHESES_10Analyzer()); break;
	case 552: factory["R005_TypeArguments_0"] = P_SDT_genertor(new R005_TypeArguments_0Analyzer()); break;
	case 553: factory["R005_TypeArgumentList_0"] = P_SDT_genertor(new R005_TypeArgumentList_0Analyzer()); break;
	case 554: factory["R005_TypeArgumentList_1"] = P_SDT_genertor(new R005_TypeArgumentList_1Analyzer()); break;
	case 555: factory["R005_NonANGLE_BRACKET_0"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_0Analyzer()); break;
	case 556: factory["R005_NonANGLE_BRACKET_1"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_1Analyzer()); break;
	case 557: factory["R005_NonANGLE_BRACKET_2"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_2Analyzer()); break;
	case 558: factory["R005_NonANGLE_BRACKET_3"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_3Analyzer()); break;
	case 559: factory["R005_NonANGLE_BRACKET_4"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_4Analyzer()); break;
	case 560: factory["R005_NonANGLE_BRACKET_5"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_5Analyzer()); break;
	case 561: factory["R005_NonANGLE_BRACKET_6"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_6Analyzer()); break;
	case 562: factory["R005_NonANGLE_BRACKET_7"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_7Analyzer()); break;
	case 563: factory["R005_NonANGLE_BRACKET_8"] = P_SDT_genertor(new R005_NonANGLE_BRACKET_8Analyzer()); break;
	case 564: factory["R005_Dims_0"] = P_SDT_genertor(new R005_Dims_0Analyzer()); break;
	case 565: factory["R005_Dims_1"] = P_SDT_genertor(new R005_Dims_1Analyzer()); break;
	case 566: factory["R005_Dims_2"] = P_SDT_genertor(new R005_Dims_2Analyzer()); break;
	case 567: factory["R005_Dims_3"] = P_SDT_genertor(new R005_Dims_3Analyzer()); break;
	case 568: factory["R005_UnannType_0"] = P_SDT_genertor(new R005_UnannType_0Analyzer()); break;
	case 569: factory["R005_UnannType_1"] = P_SDT_genertor(new R005_UnannType_1Analyzer()); break;
	case 570: factory["R005_UnannType_2"] = P_SDT_genertor(new R005_UnannType_2Analyzer()); break;
	case 571: factory["R005_UnannPrimitiveType_0"] = P_SDT_genertor(new R005_UnannPrimitiveType_0Analyzer()); break;
	case 572: factory["R005_UnannPrimitiveType_1"] = P_SDT_genertor(new R005_UnannPrimitiveType_1Analyzer()); break;
	case 573: factory["R005_UnannPrimitiveType_2"] = P_SDT_genertor(new R005_UnannPrimitiveType_2Analyzer()); break;
	case 574: factory["R005_UnannPrimitiveType_3"] = P_SDT_genertor(new R005_UnannPrimitiveType_3Analyzer()); break;
	case 575: factory["R005_UnannPrimitiveType_4"] = P_SDT_genertor(new R005_UnannPrimitiveType_4Analyzer()); break;
	case 576: factory["R005_UnannPrimitiveType_5"] = P_SDT_genertor(new R005_UnannPrimitiveType_5Analyzer()); break;
	case 577: factory["R005_UnannPrimitiveType_6"] = P_SDT_genertor(new R005_UnannPrimitiveType_6Analyzer()); break;
	case 578: factory["R005_UnannPrimitiveType_7"] = P_SDT_genertor(new R005_UnannPrimitiveType_7Analyzer()); break;
	case 579: factory["R005_UnannClassOrInterfaceType_0"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_0Analyzer()); break;
	case 580: factory["R005_UnannClassOrInterfaceType_1"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_1Analyzer()); break;
	case 581: factory["R005_UnannClassOrInterfaceType_2"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_2Analyzer()); break;
	case 582: factory["R005_UnannClassOrInterfaceType_3"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_3Analyzer()); break;
	case 583: factory["R005_UnannClassOrInterfaceType_4"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_4Analyzer()); break;
	case 584: factory["R005_UnannClassOrInterfaceType_5"] = P_SDT_genertor(new R005_UnannClassOrInterfaceType_5Analyzer()); break;
	case 585: factory["R005_UnannArrayType_0"] = P_SDT_genertor(new R005_UnannArrayType_0Analyzer()); break;
	case 586: factory["R005_UnannArrayType_1"] = P_SDT_genertor(new R005_UnannArrayType_1Analyzer()); break;
	case 587: factory["R005_VariableDeclaratorList_0"] = P_SDT_genertor(new R005_VariableDeclaratorList_0Analyzer()); break;
	case 588: factory["R005_VariableDeclaratorList_1"] = P_SDT_genertor(new R005_VariableDeclaratorList_1Analyzer()); break;
	case 589: factory["R005_VariableDeclarator_0"] = P_SDT_genertor(new R005_VariableDeclarator_0Analyzer()); break;
	case 590: factory["R005_VariableDeclarator_1"] = P_SDT_genertor(new R005_VariableDeclarator_1Analyzer()); break;
	case 591: factory["R005_VariableInitializer_0"] = P_SDT_genertor(new R005_VariableInitializer_0Analyzer()); break;
	case 592: factory["R005_VariableInitializer_1"] = P_SDT_genertor(new R005_VariableInitializer_1Analyzer()); break;
	case 593: factory["R005_VariableInitializerEle_0"] = P_SDT_genertor(new R005_VariableInitializerEle_0Analyzer()); break;
	case 594: factory["R005_VariableInitializerEle_1"] = P_SDT_genertor(new R005_VariableInitializerEle_1Analyzer()); break;
	case 595: factory["R005_VariableInitializerEle_2"] = P_SDT_genertor(new R005_VariableInitializerEle_2Analyzer()); break;
	case 596: factory["R005_VariableInitializerEle_3"] = P_SDT_genertor(new R005_VariableInitializerEle_3Analyzer()); break;
	case 597: factory["R005_VariableDeclaratorId_0"] = P_SDT_genertor(new R005_VariableDeclaratorId_0Analyzer()); break;
	case 598: factory["R005_VariableDeclaratorId_1"] = P_SDT_genertor(new R005_VariableDeclaratorId_1Analyzer()); break;
	case 599: factory["R005_MethodDeclaration_0"] = P_SDT_genertor(new R005_MethodDeclaration_0Analyzer()); break;
	case 600: factory["R005_MethodDeclaration_1"] = P_SDT_genertor(new R005_MethodDeclaration_1Analyzer()); break;
	case 601: factory["R005_MethodDeclaration_2"] = P_SDT_genertor(new R005_MethodDeclaration_2Analyzer()); break;
	case 602: factory["R005_MethodDeclaration_3"] = P_SDT_genertor(new R005_MethodDeclaration_3Analyzer()); break;
	case 603: factory["R005_MethodDeclaration_4"] = P_SDT_genertor(new R005_MethodDeclaration_4Analyzer()); break;
	case 604: factory["R005_MethodDeclaration_5"] = P_SDT_genertor(new R005_MethodDeclaration_5Analyzer()); break;
	case 605: factory["R005_MethodDeclaration_6"] = P_SDT_genertor(new R005_MethodDeclaration_6Analyzer()); break;
	case 606: factory["R005_MethodDeclaration_7"] = P_SDT_genertor(new R005_MethodDeclaration_7Analyzer()); break;
	case 607: factory["R005_MethodHeader_0"] = P_SDT_genertor(new R005_MethodHeader_0Analyzer()); break;
	case 608: factory["R005_MethodHeader_1"] = P_SDT_genertor(new R005_MethodHeader_1Analyzer()); break;
	case 609: factory["R005_Result_0"] = P_SDT_genertor(new R005_Result_0Analyzer()); break;
	case 610: factory["R005_Result_1"] = P_SDT_genertor(new R005_Result_1Analyzer()); break;
	case 611: factory["R005_MethodDeclarator_0"] = P_SDT_genertor(new R005_MethodDeclarator_0Analyzer()); break;
	case 612: factory["R005_MethodDeclarator_1"] = P_SDT_genertor(new R005_MethodDeclarator_1Analyzer()); break;
	case 613: factory["R005_Throws_0"] = P_SDT_genertor(new R005_Throws_0Analyzer()); break;
	case 614: factory["R005_ExceptionTypeList_0"] = P_SDT_genertor(new R005_ExceptionTypeList_0Analyzer()); break;
	case 615: factory["R005_ExceptionTypeList_1"] = P_SDT_genertor(new R005_ExceptionTypeList_1Analyzer()); break;
	case 616: factory["R005_ExceptionType_0"] = P_SDT_genertor(new R005_ExceptionType_0Analyzer()); break;
	case 617: factory["R005_ExceptionType_1"] = P_SDT_genertor(new R005_ExceptionType_1Analyzer()); break;
	case 618: factory["R005_ConstructorDeclaration_0"] = P_SDT_genertor(new R005_ConstructorDeclaration_0Analyzer()); break;
	case 619: factory["R005_ConstructorDeclaration_1"] = P_SDT_genertor(new R005_ConstructorDeclaration_1Analyzer()); break;
	case 620: factory["R005_ConstructorDeclaration_2"] = P_SDT_genertor(new R005_ConstructorDeclaration_2Analyzer()); break;
	case 621: factory["R005_ConstructorDeclaration_3"] = P_SDT_genertor(new R005_ConstructorDeclaration_3Analyzer()); break;
	case 622: factory["R005_ConstructorDeclarator_0"] = P_SDT_genertor(new R005_ConstructorDeclarator_0Analyzer()); break;
	case 623: factory["R005_ConstructorDeclarator_1"] = P_SDT_genertor(new R005_ConstructorDeclarator_1Analyzer()); break;
	case 624: factory["R005_ClassDeclaration_0"] = P_SDT_genertor(new R005_ClassDeclaration_0Analyzer()); break;
	case 625: factory["R005_ClassDeclaration_1"] = P_SDT_genertor(new R005_ClassDeclaration_1Analyzer()); break;
	case 626: factory["R005_NormalClassDeclaration_0"] = P_SDT_genertor(new R005_NormalClassDeclaration_0Analyzer()); break;
	case 627: factory["R005_NormalClassDeclaration_1"] = P_SDT_genertor(new R005_NormalClassDeclaration_1Analyzer()); break;
	case 628: factory["R005_NormalClassDeclaration_2"] = P_SDT_genertor(new R005_NormalClassDeclaration_2Analyzer()); break;
	case 629: factory["R005_NormalClassDeclaration_3"] = P_SDT_genertor(new R005_NormalClassDeclaration_3Analyzer()); break;
	case 630: factory["R005_NormalClassDeclaration_4"] = P_SDT_genertor(new R005_NormalClassDeclaration_4Analyzer()); break;
	case 631: factory["R005_NormalClassDeclaration_5"] = P_SDT_genertor(new R005_NormalClassDeclaration_5Analyzer()); break;
	case 632: factory["R005_NormalClassDeclaration_6"] = P_SDT_genertor(new R005_NormalClassDeclaration_6Analyzer()); break;
	case 633: factory["R005_NormalClassDeclaration_7"] = P_SDT_genertor(new R005_NormalClassDeclaration_7Analyzer()); break;
	case 634: factory["R005_NormalClassDeclaration_8"] = P_SDT_genertor(new R005_NormalClassDeclaration_8Analyzer()); break;
	case 635: factory["R005_NormalClassDeclaration_9"] = P_SDT_genertor(new R005_NormalClassDeclaration_9Analyzer()); break;
	case 636: factory["R005_NormalClassDeclaration_10"] = P_SDT_genertor(new R005_NormalClassDeclaration_10Analyzer()); break;
	case 637: factory["R005_NormalClassDeclaration_11"] = P_SDT_genertor(new R005_NormalClassDeclaration_11Analyzer()); break;
	case 638: factory["R005_NormalClassDeclaration_12"] = P_SDT_genertor(new R005_NormalClassDeclaration_12Analyzer()); break;
	case 639: factory["R005_NormalClassDeclaration_13"] = P_SDT_genertor(new R005_NormalClassDeclaration_13Analyzer()); break;
	case 640: factory["R005_NormalClassDeclaration_14"] = P_SDT_genertor(new R005_NormalClassDeclaration_14Analyzer()); break;
	case 641: factory["R005_NormalClassDeclaration_15"] = P_SDT_genertor(new R005_NormalClassDeclaration_15Analyzer()); break;
	case 642: factory["R005_Superclass_0"] = P_SDT_genertor(new R005_Superclass_0Analyzer()); break;
	case 643: factory["R005_ClassTypeEle_0"] = P_SDT_genertor(new R005_ClassTypeEle_0Analyzer()); break;
	case 644: factory["R005_ClassTypeEle_1"] = P_SDT_genertor(new R005_ClassTypeEle_1Analyzer()); break;
	case 645: factory["R005_ClassTypeEle_2"] = P_SDT_genertor(new R005_ClassTypeEle_2Analyzer()); break;
	case 646: factory["R005_ClassTypeEle_3"] = P_SDT_genertor(new R005_ClassTypeEle_3Analyzer()); break;
	case 647: factory["R005_ClassType_0"] = P_SDT_genertor(new R005_ClassType_0Analyzer()); break;
	case 648: factory["R005_ClassType_1"] = P_SDT_genertor(new R005_ClassType_1Analyzer()); break;
	case 649: factory["R005_Superinterfaces_0"] = P_SDT_genertor(new R005_Superinterfaces_0Analyzer()); break;
	case 650: factory["R005_InterfaceTypeList_0"] = P_SDT_genertor(new R005_InterfaceTypeList_0Analyzer()); break;
	case 651: factory["R005_InterfaceTypeList_1"] = P_SDT_genertor(new R005_InterfaceTypeList_1Analyzer()); break;
	case 652: factory["R005_EnumDeclaration_0"] = P_SDT_genertor(new R005_EnumDeclaration_0Analyzer()); break;
	case 653: factory["R005_EnumDeclaration_1"] = P_SDT_genertor(new R005_EnumDeclaration_1Analyzer()); break;
	case 654: factory["R005_EnumDeclaration_2"] = P_SDT_genertor(new R005_EnumDeclaration_2Analyzer()); break;
	case 655: factory["R005_EnumDeclaration_3"] = P_SDT_genertor(new R005_EnumDeclaration_3Analyzer()); break;
	case 656: factory["R005_InterfaceDeclaration_0"] = P_SDT_genertor(new R005_InterfaceDeclaration_0Analyzer()); break;
	case 657: factory["R005_InterfaceDeclaration_1"] = P_SDT_genertor(new R005_InterfaceDeclaration_1Analyzer()); break;
	case 658: factory["R005_NormalInterfaceDeclaration_0"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_0Analyzer()); break;
	case 659: factory["R005_NormalInterfaceDeclaration_1"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_1Analyzer()); break;
	case 660: factory["R005_NormalInterfaceDeclaration_2"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_2Analyzer()); break;
	case 661: factory["R005_NormalInterfaceDeclaration_3"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_3Analyzer()); break;
	case 662: factory["R005_NormalInterfaceDeclaration_4"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_4Analyzer()); break;
	case 663: factory["R005_NormalInterfaceDeclaration_5"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_5Analyzer()); break;
	case 664: factory["R005_NormalInterfaceDeclaration_6"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_6Analyzer()); break;
	case 665: factory["R005_NormalInterfaceDeclaration_7"] = P_SDT_genertor(new R005_NormalInterfaceDeclaration_7Analyzer()); break;
	case 666: factory["R005_ExtendsInterfaces_0"] = P_SDT_genertor(new R005_ExtendsInterfaces_0Analyzer()); break;
	case 667: factory["R005_AnnotationTypeDeclaration_0"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_0Analyzer()); break;
	case 668: factory["R005_AnnotationTypeDeclaration_1"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_1Analyzer()); break;
	case 669: factory["R005_AnnotationTypeDeclaration_2"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_2Analyzer()); break;
	case 670: factory["R005_AnnotationTypeDeclaration_3"] = P_SDT_genertor(new R005_AnnotationTypeDeclaration_3Analyzer()); break;
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
SDT_Factory::~SDT_Factory() {}


