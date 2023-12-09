R004_DefaultAnalyzer::R004_DefaultAnalyzer() {}
R004_DefaultAnalyzer::~R004_DefaultAnalyzer() {}



//beg_ele_begin : CompilationUnit
R004_ele_begin_0Analyzer::R004_ele_begin_0Analyzer() {}
R004_ele_begin_0Analyzer::~R004_ele_begin_0Analyzer() {}



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList TypeDeclarationList
R004_CompilationUnit_0Analyzer::R004_CompilationUnit_0Analyzer() {}
R004_CompilationUnit_0Analyzer::~R004_CompilationUnit_0Analyzer() {}



//beg_CompilationUnit : PackageDeclaration ImportDeclarationList
R004_CompilationUnit_1Analyzer::R004_CompilationUnit_1Analyzer() {}
R004_CompilationUnit_1Analyzer::~R004_CompilationUnit_1Analyzer() {}



//beg_CompilationUnit : PackageDeclaration TypeDeclarationList
R004_CompilationUnit_2Analyzer::R004_CompilationUnit_2Analyzer() {}
R004_CompilationUnit_2Analyzer::~R004_CompilationUnit_2Analyzer() {}



//beg_CompilationUnit : ImportDeclarationList TypeDeclarationList
R004_CompilationUnit_3Analyzer::R004_CompilationUnit_3Analyzer() {}
R004_CompilationUnit_3Analyzer::~R004_CompilationUnit_3Analyzer() {}



//beg_CompilationUnit : PackageDeclaration
R004_CompilationUnit_4Analyzer::R004_CompilationUnit_4Analyzer() {}
R004_CompilationUnit_4Analyzer::~R004_CompilationUnit_4Analyzer() {}



//beg_CompilationUnit : ImportDeclarationList
R004_CompilationUnit_5Analyzer::R004_CompilationUnit_5Analyzer() {}
R004_CompilationUnit_5Analyzer::~R004_CompilationUnit_5Analyzer() {}



//beg_CompilationUnit : TypeDeclarationList
R004_CompilationUnit_6Analyzer::R004_CompilationUnit_6Analyzer() {}
R004_CompilationUnit_6Analyzer::~R004_CompilationUnit_6Analyzer() {}



//beg_PackageDeclaration : 'package' DetailIdentifier 'semicolon'
R004_PackageDeclaration_0Analyzer::R004_PackageDeclaration_0Analyzer() {}
R004_PackageDeclaration_0Analyzer::~R004_PackageDeclaration_0Analyzer() {}



//beg_PackageDeclaration : ModifierList 'package' DetailIdentifier 'semicolon'
R004_PackageDeclaration_1Analyzer::R004_PackageDeclaration_1Analyzer() {}
R004_PackageDeclaration_1Analyzer::~R004_PackageDeclaration_1Analyzer() {}



//beg_DetailIdentifier : Identifier 'SPOT' DetailIdentifier
R004_DetailIdentifier_0Analyzer::R004_DetailIdentifier_0Analyzer() {}
R004_DetailIdentifier_0Analyzer::~R004_DetailIdentifier_0Analyzer() {}



//beg_DetailIdentifier : Identifier
R004_DetailIdentifier_1Analyzer::R004_DetailIdentifier_1Analyzer() {}
R004_DetailIdentifier_1Analyzer::~R004_DetailIdentifier_1Analyzer() {}



//beg_Identifier : 'IDENTIFIER'
R004_Identifier_0Analyzer::R004_Identifier_0Analyzer() {}
R004_Identifier_0Analyzer::~R004_Identifier_0Analyzer() {}



//beg_ImportDeclarationList : ImportDeclaration ImportDeclarationList
R004_ImportDeclarationList_0Analyzer::R004_ImportDeclarationList_0Analyzer() {}
R004_ImportDeclarationList_0Analyzer::~R004_ImportDeclarationList_0Analyzer() {}



//beg_ImportDeclarationList : ImportDeclaration
R004_ImportDeclarationList_1Analyzer::R004_ImportDeclarationList_1Analyzer() {}
R004_ImportDeclarationList_1Analyzer::~R004_ImportDeclarationList_1Analyzer() {}



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'SPOT_STAR' 'semicolon'
R004_ImportDeclaration_0Analyzer::R004_ImportDeclaration_0Analyzer() {}
R004_ImportDeclaration_0Analyzer::~R004_ImportDeclaration_0Analyzer() {}



//beg_ImportDeclaration : 'import' 'static' DetailIdentifier 'semicolon'
R004_ImportDeclaration_1Analyzer::R004_ImportDeclaration_1Analyzer() {}
R004_ImportDeclaration_1Analyzer::~R004_ImportDeclaration_1Analyzer() {}



//beg_ImportDeclaration : 'import' DetailIdentifier 'SPOT_STAR' 'semicolon'
R004_ImportDeclaration_2Analyzer::R004_ImportDeclaration_2Analyzer() {}
R004_ImportDeclaration_2Analyzer::~R004_ImportDeclaration_2Analyzer() {}



//beg_ImportDeclaration : 'import' DetailIdentifier 'semicolon'
R004_ImportDeclaration_3Analyzer::R004_ImportDeclaration_3Analyzer() {}
R004_ImportDeclaration_3Analyzer::~R004_ImportDeclaration_3Analyzer() {}



//beg_TypeDeclarationList : TypeDeclaration
R004_TypeDeclarationList_0Analyzer::R004_TypeDeclarationList_0Analyzer() {}
R004_TypeDeclarationList_0Analyzer::~R004_TypeDeclarationList_0Analyzer() {}



//beg_TypeDeclaration : ClassDeclaration
R004_TypeDeclaration_0Analyzer::R004_TypeDeclaration_0Analyzer() {}
R004_TypeDeclaration_0Analyzer::~R004_TypeDeclaration_0Analyzer() {}



//beg_TypeDeclaration : InterfaceDeclaration
R004_TypeDeclaration_1Analyzer::R004_TypeDeclaration_1Analyzer() {}
R004_TypeDeclaration_1Analyzer::~R004_TypeDeclaration_1Analyzer() {}



//beg_TypeDeclaration : 'semicolon'
R004_TypeDeclaration_2Analyzer::R004_TypeDeclaration_2Analyzer() {}
R004_TypeDeclaration_2Analyzer::~R004_TypeDeclaration_2Analyzer() {}



//beg_ClassDeclaration : NormalClassDeclaration
R004_ClassDeclaration_0Analyzer::R004_ClassDeclaration_0Analyzer() {}
R004_ClassDeclaration_0Analyzer::~R004_ClassDeclaration_0Analyzer() {}



//beg_ClassDeclaration : EnumDeclaration
R004_ClassDeclaration_1Analyzer::R004_ClassDeclaration_1Analyzer() {}
R004_ClassDeclaration_1Analyzer::~R004_ClassDeclaration_1Analyzer() {}



//beg_InterfaceDeclaration : NormalInterfaceDeclaration
R004_InterfaceDeclaration_0Analyzer::R004_InterfaceDeclaration_0Analyzer() {}
R004_InterfaceDeclaration_0Analyzer::~R004_InterfaceDeclaration_0Analyzer() {}



//beg_InterfaceDeclaration : AnnotationTypeDeclaration
R004_InterfaceDeclaration_1Analyzer::R004_InterfaceDeclaration_1Analyzer() {}
R004_InterfaceDeclaration_1Analyzer::~R004_InterfaceDeclaration_1Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier ClassBody
R004_NormalClassDeclaration_0Analyzer::R004_NormalClassDeclaration_0Analyzer() {}
R004_NormalClassDeclaration_0Analyzer::~R004_NormalClassDeclaration_0Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier ClassBody
R004_NormalClassDeclaration_1Analyzer::R004_NormalClassDeclaration_1Analyzer() {}
R004_NormalClassDeclaration_1Analyzer::~R004_NormalClassDeclaration_1Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments ClassBody
R004_NormalClassDeclaration_2Analyzer::R004_NormalClassDeclaration_2Analyzer() {}
R004_NormalClassDeclaration_2Analyzer::~R004_NormalClassDeclaration_2Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments ClassBody
R004_NormalClassDeclaration_3Analyzer::R004_NormalClassDeclaration_3Analyzer() {}
R004_NormalClassDeclaration_3Analyzer::~R004_NormalClassDeclaration_3Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier Superclass ClassBody
R004_NormalClassDeclaration_4Analyzer::R004_NormalClassDeclaration_4Analyzer() {}
R004_NormalClassDeclaration_4Analyzer::~R004_NormalClassDeclaration_4Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass ClassBody
R004_NormalClassDeclaration_5Analyzer::R004_NormalClassDeclaration_5Analyzer() {}
R004_NormalClassDeclaration_5Analyzer::~R004_NormalClassDeclaration_5Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass ClassBody
R004_NormalClassDeclaration_6Analyzer::R004_NormalClassDeclaration_6Analyzer() {}
R004_NormalClassDeclaration_6Analyzer::~R004_NormalClassDeclaration_6Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments ClassBody
R004_NormalClassDeclaration_7Analyzer::R004_NormalClassDeclaration_7Analyzer() {}
R004_NormalClassDeclaration_7Analyzer::~R004_NormalClassDeclaration_7Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier Superinterfaces ClassBody
R004_NormalClassDeclaration_8Analyzer::R004_NormalClassDeclaration_8Analyzer() {}
R004_NormalClassDeclaration_8Analyzer::~R004_NormalClassDeclaration_8Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superinterfaces ClassBody
R004_NormalClassDeclaration_9Analyzer::R004_NormalClassDeclaration_9Analyzer() {}
R004_NormalClassDeclaration_9Analyzer::~R004_NormalClassDeclaration_9Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superinterfaces ClassBody
R004_NormalClassDeclaration_10Analyzer::R004_NormalClassDeclaration_10Analyzer() {}
R004_NormalClassDeclaration_10Analyzer::~R004_NormalClassDeclaration_10Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier TypeArguments Superinterfaces ClassBody
R004_NormalClassDeclaration_11Analyzer::R004_NormalClassDeclaration_11Analyzer() {}
R004_NormalClassDeclaration_11Analyzer::~R004_NormalClassDeclaration_11Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier Superclass Superinterfaces ClassBody
R004_NormalClassDeclaration_12Analyzer::R004_NormalClassDeclaration_12Analyzer() {}
R004_NormalClassDeclaration_12Analyzer::~R004_NormalClassDeclaration_12Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass Superinterfaces ClassBody
R004_NormalClassDeclaration_13Analyzer::R004_NormalClassDeclaration_13Analyzer() {}
R004_NormalClassDeclaration_13Analyzer::~R004_NormalClassDeclaration_13Analyzer() {}



//beg_NormalClassDeclaration : 'class' Identifier TypeArguments Superclass Superinterfaces ClassBody
R004_NormalClassDeclaration_14Analyzer::R004_NormalClassDeclaration_14Analyzer() {}
R004_NormalClassDeclaration_14Analyzer::~R004_NormalClassDeclaration_14Analyzer() {}



//beg_NormalClassDeclaration : ModifierList 'class' Identifier Superclass TypeArguments Superinterfaces ClassBody
R004_NormalClassDeclaration_15Analyzer::R004_NormalClassDeclaration_15Analyzer() {}
R004_NormalClassDeclaration_15Analyzer::~R004_NormalClassDeclaration_15Analyzer() {}



//beg_EnumDeclaration : 'enum' Identifier 'LEFT_BRACE'
R004_EnumDeclaration_0Analyzer::R004_EnumDeclaration_0Analyzer() {}
R004_EnumDeclaration_0Analyzer::~R004_EnumDeclaration_0Analyzer() {}



//beg_EnumDeclaration : ModifierList 'enum' Identifier 'LEFT_BRACE'
R004_EnumDeclaration_1Analyzer::R004_EnumDeclaration_1Analyzer() {}
R004_EnumDeclaration_1Analyzer::~R004_EnumDeclaration_1Analyzer() {}



//beg_EnumDeclaration : 'enum' Identifier Superinterfaces 'LEFT_BRACE'
R004_EnumDeclaration_2Analyzer::R004_EnumDeclaration_2Analyzer() {}
R004_EnumDeclaration_2Analyzer::~R004_EnumDeclaration_2Analyzer() {}



//beg_EnumDeclaration : ModifierList 'enum' Identifier Superinterfaces 'LEFT_BRACE'
R004_EnumDeclaration_3Analyzer::R004_EnumDeclaration_3Analyzer() {}
R004_EnumDeclaration_3Analyzer::~R004_EnumDeclaration_3Analyzer() {}



//beg_NormalInterfaceDeclaration : 'interface' Identifier 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_0Analyzer::R004_NormalInterfaceDeclaration_0Analyzer() {}
R004_NormalInterfaceDeclaration_0Analyzer::~R004_NormalInterfaceDeclaration_0Analyzer() {}



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_1Analyzer::R004_NormalInterfaceDeclaration_1Analyzer() {}
R004_NormalInterfaceDeclaration_1Analyzer::~R004_NormalInterfaceDeclaration_1Analyzer() {}



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_2Analyzer::R004_NormalInterfaceDeclaration_2Analyzer() {}
R004_NormalInterfaceDeclaration_2Analyzer::~R004_NormalInterfaceDeclaration_2Analyzer() {}



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_3Analyzer::R004_NormalInterfaceDeclaration_3Analyzer() {}
R004_NormalInterfaceDeclaration_3Analyzer::~R004_NormalInterfaceDeclaration_3Analyzer() {}



//beg_NormalInterfaceDeclaration : 'interface' Identifier ExtendsInterfaces 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_4Analyzer::R004_NormalInterfaceDeclaration_4Analyzer() {}
R004_NormalInterfaceDeclaration_4Analyzer::~R004_NormalInterfaceDeclaration_4Analyzer() {}



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier ExtendsInterfaces 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_5Analyzer::R004_NormalInterfaceDeclaration_5Analyzer() {}
R004_NormalInterfaceDeclaration_5Analyzer::~R004_NormalInterfaceDeclaration_5Analyzer() {}



//beg_NormalInterfaceDeclaration : 'interface' Identifier TypeArguments ExtendsInterfaces 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_6Analyzer::R004_NormalInterfaceDeclaration_6Analyzer() {}
R004_NormalInterfaceDeclaration_6Analyzer::~R004_NormalInterfaceDeclaration_6Analyzer() {}



//beg_NormalInterfaceDeclaration : ModifierList 'interface' Identifier TypeArguments ExtendsInterfaces 'LEFT_BRACE'
R004_NormalInterfaceDeclaration_7Analyzer::R004_NormalInterfaceDeclaration_7Analyzer() {}
R004_NormalInterfaceDeclaration_7Analyzer::~R004_NormalInterfaceDeclaration_7Analyzer() {}



//beg_ExtendsInterfaces : 'extends' InterfaceTypeList
R004_ExtendsInterfaces_0Analyzer::R004_ExtendsInterfaces_0Analyzer() {}
R004_ExtendsInterfaces_0Analyzer::~R004_ExtendsInterfaces_0Analyzer() {}



//beg_AnnotationTypeDeclaration : 'AT' 'interface' Identifier 'LEFT_BRACE'
R004_AnnotationTypeDeclaration_0Analyzer::R004_AnnotationTypeDeclaration_0Analyzer() {}
R004_AnnotationTypeDeclaration_0Analyzer::~R004_AnnotationTypeDeclaration_0Analyzer() {}



//beg_AnnotationTypeDeclaration : ModifierList 'AT' 'interface' Identifier 'LEFT_BRACE'
R004_AnnotationTypeDeclaration_1Analyzer::R004_AnnotationTypeDeclaration_1Analyzer() {}
R004_AnnotationTypeDeclaration_1Analyzer::~R004_AnnotationTypeDeclaration_1Analyzer() {}



//beg_AnnotationTypeDeclaration : 'AT_INTERFACE' Identifier 'LEFT_BRACE'
R004_AnnotationTypeDeclaration_2Analyzer::R004_AnnotationTypeDeclaration_2Analyzer() {}
R004_AnnotationTypeDeclaration_2Analyzer::~R004_AnnotationTypeDeclaration_2Analyzer() {}



//beg_AnnotationTypeDeclaration : ModifierList 'AT_INTERFACE' Identifier 'LEFT_BRACE'
R004_AnnotationTypeDeclaration_3Analyzer::R004_AnnotationTypeDeclaration_3Analyzer() {}
R004_AnnotationTypeDeclaration_3Analyzer::~R004_AnnotationTypeDeclaration_3Analyzer() {}



//beg_ClassBody : 'LEFT_BRACE' ClassBodyDeclarationList 'RIGHT_BRACE''
R004_ClassBody_0Analyzer::R004_ClassBody_0Analyzer() {}
R004_ClassBody_0Analyzer::~R004_ClassBody_0Analyzer() {}



//beg_ClassBodyDeclarationList : ClassBodyDeclaration ClassBodyDeclarationList
R004_ClassBodyDeclarationList_0Analyzer::R004_ClassBodyDeclarationList_0Analyzer() {}
R004_ClassBodyDeclarationList_0Analyzer::~R004_ClassBodyDeclarationList_0Analyzer() {}



//beg_ClassBodyDeclarationList : 0
R004_ClassBodyDeclarationList_1Analyzer::R004_ClassBodyDeclarationList_1Analyzer() {}
R004_ClassBodyDeclarationList_1Analyzer::~R004_ClassBodyDeclarationList_1Analyzer() {}



//beg_ClassBodyDeclaration : ClassStatementPrefix 'semicolon'
R004_ClassBodyDeclaration_0Analyzer::R004_ClassBodyDeclaration_0Analyzer() {}
R004_ClassBodyDeclaration_0Analyzer::~R004_ClassBodyDeclaration_0Analyzer() {}



//beg_ClassBodyDeclaration : ClassStatementPrefix Block
R004_ClassBodyDeclaration_1Analyzer::R004_ClassBodyDeclaration_1Analyzer() {}
R004_ClassBodyDeclaration_1Analyzer::~R004_ClassBodyDeclaration_1Analyzer() {}



//beg_ClassStatementPrefix : NonBraceAndSemicolon ClassStatementPrefix
R004_ClassStatementPrefix_0Analyzer::R004_ClassStatementPrefix_0Analyzer() {}
R004_ClassStatementPrefix_0Analyzer::~R004_ClassStatementPrefix_0Analyzer() {}



//beg_ClassStatementPrefix : 0
R004_ClassStatementPrefix_1Analyzer::R004_ClassStatementPrefix_1Analyzer() {}
R004_ClassStatementPrefix_1Analyzer::~R004_ClassStatementPrefix_1Analyzer() {}



//beg_NonBraceAndSemicolon : StatementEle
R004_NonBraceAndSemicolon_0Analyzer::R004_NonBraceAndSemicolon_0Analyzer() {}
R004_NonBraceAndSemicolon_0Analyzer::~R004_NonBraceAndSemicolon_0Analyzer() {}



//beg_NonBraceAndSemicolon : 'COMMA'
R004_NonBraceAndSemicolon_1Analyzer::R004_NonBraceAndSemicolon_1Analyzer() {}
R004_NonBraceAndSemicolon_1Analyzer::~R004_NonBraceAndSemicolon_1Analyzer() {}



//beg_NonBraceAndSemicolon : 'LEFT_ANGLE_BRACKET'
R004_NonBraceAndSemicolon_2Analyzer::R004_NonBraceAndSemicolon_2Analyzer() {}
R004_NonBraceAndSemicolon_2Analyzer::~R004_NonBraceAndSemicolon_2Analyzer() {}



//beg_NonBraceAndSemicolon : 'LEFT_BRACKET'
R004_NonBraceAndSemicolon_3Analyzer::R004_NonBraceAndSemicolon_3Analyzer() {}
R004_NonBraceAndSemicolon_3Analyzer::~R004_NonBraceAndSemicolon_3Analyzer() {}



//beg_NonBraceAndSemicolon : 'LEFT_PARENTHESES'
R004_NonBraceAndSemicolon_4Analyzer::R004_NonBraceAndSemicolon_4Analyzer() {}
R004_NonBraceAndSemicolon_4Analyzer::~R004_NonBraceAndSemicolon_4Analyzer() {}



//beg_NonBraceAndSemicolon : 'RIGHT_ANGLE_BRACKET'
R004_NonBraceAndSemicolon_5Analyzer::R004_NonBraceAndSemicolon_5Analyzer() {}
R004_NonBraceAndSemicolon_5Analyzer::~R004_NonBraceAndSemicolon_5Analyzer() {}



//beg_NonBraceAndSemicolon : 'RIGHT_BRACKET'
R004_NonBraceAndSemicolon_6Analyzer::R004_NonBraceAndSemicolon_6Analyzer() {}
R004_NonBraceAndSemicolon_6Analyzer::~R004_NonBraceAndSemicolon_6Analyzer() {}



//beg_NonBraceAndSemicolon : 'RIGHT_PARENTHESES'
R004_NonBraceAndSemicolon_7Analyzer::R004_NonBraceAndSemicolon_7Analyzer() {}
R004_NonBraceAndSemicolon_7Analyzer::~R004_NonBraceAndSemicolon_7Analyzer() {}



//beg_ModifierList : Modifier ModifierList
R004_ModifierList_0Analyzer::R004_ModifierList_0Analyzer() {}
R004_ModifierList_0Analyzer::~R004_ModifierList_0Analyzer() {}



//beg_ModifierList : Modifier
R004_ModifierList_1Analyzer::R004_ModifierList_1Analyzer() {}
R004_ModifierList_1Analyzer::~R004_ModifierList_1Analyzer() {}



//beg_AnnotationContent : 'LEFT_PARENTHESES' AnnotationContentStatements 'RIGHT_PARENTHESES'
R004_AnnotationContent_0Analyzer::R004_AnnotationContent_0Analyzer() {}
R004_AnnotationContent_0Analyzer::~R004_AnnotationContent_0Analyzer() {}



//beg_AnnotationContentStatements : NonPARENTHESES AnnotationContentStatements
R004_AnnotationContentStatements_0Analyzer::R004_AnnotationContentStatements_0Analyzer() {}
R004_AnnotationContentStatements_0Analyzer::~R004_AnnotationContentStatements_0Analyzer() {}



//beg_AnnotationContentStatements : NonPARENTHESES
R004_AnnotationContentStatements_1Analyzer::R004_AnnotationContentStatements_1Analyzer() {}
R004_AnnotationContentStatements_1Analyzer::~R004_AnnotationContentStatements_1Analyzer() {}



//beg_NonPARENTHESES : StatementEle
R004_NonPARENTHESES_0Analyzer::R004_NonPARENTHESES_0Analyzer() {}
R004_NonPARENTHESES_0Analyzer::~R004_NonPARENTHESES_0Analyzer() {}



//beg_NonPARENTHESES : 'COMMA'
R004_NonPARENTHESES_1Analyzer::R004_NonPARENTHESES_1Analyzer() {}
R004_NonPARENTHESES_1Analyzer::~R004_NonPARENTHESES_1Analyzer() {}



//beg_NonPARENTHESES : 'semicolon'
R004_NonPARENTHESES_2Analyzer::R004_NonPARENTHESES_2Analyzer() {}
R004_NonPARENTHESES_2Analyzer::~R004_NonPARENTHESES_2Analyzer() {}



//beg_NonPARENTHESES : 'LEFT_BRACE'
R004_NonPARENTHESES_3Analyzer::R004_NonPARENTHESES_3Analyzer() {}
R004_NonPARENTHESES_3Analyzer::~R004_NonPARENTHESES_3Analyzer() {}



//beg_NonPARENTHESES : 'LEFT_BRACKET'
R004_NonPARENTHESES_4Analyzer::R004_NonPARENTHESES_4Analyzer() {}
R004_NonPARENTHESES_4Analyzer::~R004_NonPARENTHESES_4Analyzer() {}



//beg_NonPARENTHESES : 'LEFT_ANGLE_BRACKET'
R004_NonPARENTHESES_5Analyzer::R004_NonPARENTHESES_5Analyzer() {}
R004_NonPARENTHESES_5Analyzer::~R004_NonPARENTHESES_5Analyzer() {}



//beg_NonPARENTHESES : 'RIGHT_BRACE'
R004_NonPARENTHESES_6Analyzer::R004_NonPARENTHESES_6Analyzer() {}
R004_NonPARENTHESES_6Analyzer::~R004_NonPARENTHESES_6Analyzer() {}



//beg_NonPARENTHESES : 'COMMA_RIGHT_BRACE'
R004_NonPARENTHESES_7Analyzer::R004_NonPARENTHESES_7Analyzer() {}
R004_NonPARENTHESES_7Analyzer::~R004_NonPARENTHESES_7Analyzer() {}



//beg_NonPARENTHESES : 'RIGHT_BRACKET'
R004_NonPARENTHESES_8Analyzer::R004_NonPARENTHESES_8Analyzer() {}
R004_NonPARENTHESES_8Analyzer::~R004_NonPARENTHESES_8Analyzer() {}



//beg_NonPARENTHESES : 'RIGHT_ANGLE_BRACKET'
R004_NonPARENTHESES_9Analyzer::R004_NonPARENTHESES_9Analyzer() {}
R004_NonPARENTHESES_9Analyzer::~R004_NonPARENTHESES_9Analyzer() {}



//beg_StatementEle : 'IDENTIFIER'
R004_StatementEle_0Analyzer::R004_StatementEle_0Analyzer() {}
R004_StatementEle_0Analyzer::~R004_StatementEle_0Analyzer() {}



//beg_StatementEle : 'AND'
R004_StatementEle_1Analyzer::R004_StatementEle_1Analyzer() {}
R004_StatementEle_1Analyzer::~R004_StatementEle_1Analyzer() {}



//beg_StatementEle : 'AND_EQUAL'
R004_StatementEle_2Analyzer::R004_StatementEle_2Analyzer() {}
R004_StatementEle_2Analyzer::~R004_StatementEle_2Analyzer() {}



//beg_StatementEle : 'AT'
R004_StatementEle_3Analyzer::R004_StatementEle_3Analyzer() {}
R004_StatementEle_3Analyzer::~R004_StatementEle_3Analyzer() {}



//beg_StatementEle : 'AT_INTERFACE'
R004_StatementEle_4Analyzer::R004_StatementEle_4Analyzer() {}
R004_StatementEle_4Analyzer::~R004_StatementEle_4Analyzer() {}



//beg_StatementEle : 'BIT_AND'
R004_StatementEle_5Analyzer::R004_StatementEle_5Analyzer() {}
R004_StatementEle_5Analyzer::~R004_StatementEle_5Analyzer() {}



//beg_StatementEle : 'BIT_OR'
R004_StatementEle_6Analyzer::R004_StatementEle_6Analyzer() {}
R004_StatementEle_6Analyzer::~R004_StatementEle_6Analyzer() {}



//beg_StatementEle : 'BooleanLiteral'
R004_StatementEle_7Analyzer::R004_StatementEle_7Analyzer() {}
R004_StatementEle_7Analyzer::~R004_StatementEle_7Analyzer() {}



//beg_StatementEle : 'CARET'
R004_StatementEle_8Analyzer::R004_StatementEle_8Analyzer() {}
R004_StatementEle_8Analyzer::~R004_StatementEle_8Analyzer() {}



//beg_StatementEle : 'COLON'
R004_StatementEle_9Analyzer::R004_StatementEle_9Analyzer() {}
R004_StatementEle_9Analyzer::~R004_StatementEle_9Analyzer() {}



//beg_StatementEle : 'CharacterLiteral'
R004_StatementEle_10Analyzer::R004_StatementEle_10Analyzer() {}
R004_StatementEle_10Analyzer::~R004_StatementEle_10Analyzer() {}



//beg_StatementEle : 'DB_EQUAL'
R004_StatementEle_11Analyzer::R004_StatementEle_11Analyzer() {}
R004_StatementEle_11Analyzer::~R004_StatementEle_11Analyzer() {}



//beg_StatementEle : 'DIVIDE_EQUAL'
R004_StatementEle_12Analyzer::R004_StatementEle_12Analyzer() {}
R004_StatementEle_12Analyzer::~R004_StatementEle_12Analyzer() {}



//beg_StatementEle : 'EQUAL'
R004_StatementEle_13Analyzer::R004_StatementEle_13Analyzer() {}
R004_StatementEle_13Analyzer::~R004_StatementEle_13Analyzer() {}



//beg_StatementEle : 'FloatingPointLiteral'
R004_StatementEle_14Analyzer::R004_StatementEle_14Analyzer() {}
R004_StatementEle_14Analyzer::~R004_StatementEle_14Analyzer() {}



//beg_StatementEle : 'GT_EQUAL'
R004_StatementEle_15Analyzer::R004_StatementEle_15Analyzer() {}
R004_StatementEle_15Analyzer::~R004_StatementEle_15Analyzer() {}



//beg_StatementEle : 'IntegerLiteral'
R004_StatementEle_16Analyzer::R004_StatementEle_16Analyzer() {}
R004_StatementEle_16Analyzer::~R004_StatementEle_16Analyzer() {}



//beg_StatementEle : 'LAMBDA_TO'
R004_StatementEle_17Analyzer::R004_StatementEle_17Analyzer() {}
R004_StatementEle_17Analyzer::~R004_StatementEle_17Analyzer() {}



//beg_StatementEle : 'LEFT_SHIFT'
R004_StatementEle_18Analyzer::R004_StatementEle_18Analyzer() {}
R004_StatementEle_18Analyzer::~R004_StatementEle_18Analyzer() {}



//beg_StatementEle : 'LEFT_SHIFT_EQUAL'
R004_StatementEle_19Analyzer::R004_StatementEle_19Analyzer() {}
R004_StatementEle_19Analyzer::~R004_StatementEle_19Analyzer() {}



//beg_StatementEle : 'LT_EQUAL'
R004_StatementEle_20Analyzer::R004_StatementEle_20Analyzer() {}
R004_StatementEle_20Analyzer::~R004_StatementEle_20Analyzer() {}



//beg_StatementEle : 'MULTI_EQUAL'
R004_StatementEle_21Analyzer::R004_StatementEle_21Analyzer() {}
R004_StatementEle_21Analyzer::~R004_StatementEle_21Analyzer() {}



//beg_StatementEle : 'NOT_EQUAL'
R004_StatementEle_22Analyzer::R004_StatementEle_22Analyzer() {}
R004_StatementEle_22Analyzer::~R004_StatementEle_22Analyzer() {}



//beg_StatementEle : 'OR'
R004_StatementEle_23Analyzer::R004_StatementEle_23Analyzer() {}
R004_StatementEle_23Analyzer::~R004_StatementEle_23Analyzer() {}



//beg_StatementEle : 'OR_EQUAL'
R004_StatementEle_24Analyzer::R004_StatementEle_24Analyzer() {}
R004_StatementEle_24Analyzer::~R004_StatementEle_24Analyzer() {}



//beg_StatementEle : 'PLUS'
R004_StatementEle_25Analyzer::R004_StatementEle_25Analyzer() {}
R004_StatementEle_25Analyzer::~R004_StatementEle_25Analyzer() {}



//beg_StatementEle : 'PLUS_EQUAL'
R004_StatementEle_26Analyzer::R004_StatementEle_26Analyzer() {}
R004_StatementEle_26Analyzer::~R004_StatementEle_26Analyzer() {}



//beg_StatementEle : 'PRECENTAGE'
R004_StatementEle_27Analyzer::R004_StatementEle_27Analyzer() {}
R004_StatementEle_27Analyzer::~R004_StatementEle_27Analyzer() {}



//beg_StatementEle : 'PRECENTAGE_EQUAL'
R004_StatementEle_28Analyzer::R004_StatementEle_28Analyzer() {}
R004_StatementEle_28Analyzer::~R004_StatementEle_28Analyzer() {}



//beg_StatementEle : 'PackageOrTypeNameId'
R004_StatementEle_29Analyzer::R004_StatementEle_29Analyzer() {}
R004_StatementEle_29Analyzer::~R004_StatementEle_29Analyzer() {}



//beg_StatementEle : 'QUESTION'
R004_StatementEle_30Analyzer::R004_StatementEle_30Analyzer() {}
R004_StatementEle_30Analyzer::~R004_StatementEle_30Analyzer() {}



//beg_StatementEle : 'RIGHT_SHIFT'
R004_StatementEle_31Analyzer::R004_StatementEle_31Analyzer() {}
R004_StatementEle_31Analyzer::~R004_StatementEle_31Analyzer() {}



//beg_StatementEle : 'RIGHT_SHIFT2'
R004_StatementEle_32Analyzer::R004_StatementEle_32Analyzer() {}
R004_StatementEle_32Analyzer::~R004_StatementEle_32Analyzer() {}



//beg_StatementEle : 'RIGHT_SHIFT2_EQUAL'
R004_StatementEle_33Analyzer::R004_StatementEle_33Analyzer() {}
R004_StatementEle_33Analyzer::~R004_StatementEle_33Analyzer() {}



//beg_StatementEle : 'RIGHT_SHIFT_EQUAL'
R004_StatementEle_34Analyzer::R004_StatementEle_34Analyzer() {}
R004_StatementEle_34Analyzer::~R004_StatementEle_34Analyzer() {}



//beg_StatementEle : 'RIGTH_BRACKET'
R004_StatementEle_35Analyzer::R004_StatementEle_35Analyzer() {}
R004_StatementEle_35Analyzer::~R004_StatementEle_35Analyzer() {}



//beg_StatementEle : 'SLASH'
R004_StatementEle_36Analyzer::R004_StatementEle_36Analyzer() {}
R004_StatementEle_36Analyzer::~R004_StatementEle_36Analyzer() {}



//beg_StatementEle : 'SPOT'
R004_StatementEle_37Analyzer::R004_StatementEle_37Analyzer() {}
R004_StatementEle_37Analyzer::~R004_StatementEle_37Analyzer() {}



//beg_StatementEle : 'STAR'
R004_StatementEle_38Analyzer::R004_StatementEle_38Analyzer() {}
R004_StatementEle_38Analyzer::~R004_StatementEle_38Analyzer() {}



//beg_StatementEle : 'SUBTRACT'
R004_StatementEle_39Analyzer::R004_StatementEle_39Analyzer() {}
R004_StatementEle_39Analyzer::~R004_StatementEle_39Analyzer() {}



//beg_StatementEle : 'SUBTRACT_EQUAL'
R004_StatementEle_40Analyzer::R004_StatementEle_40Analyzer() {}
R004_StatementEle_40Analyzer::~R004_StatementEle_40Analyzer() {}



//beg_StatementEle : 'SURPRISE'
R004_StatementEle_41Analyzer::R004_StatementEle_41Analyzer() {}
R004_StatementEle_41Analyzer::~R004_StatementEle_41Analyzer() {}



//beg_StatementEle : 'StringLiteral'
R004_StatementEle_42Analyzer::R004_StatementEle_42Analyzer() {}
R004_StatementEle_42Analyzer::~R004_StatementEle_42Analyzer() {}



//beg_StatementEle : 'THREE_SPOT'
R004_StatementEle_43Analyzer::R004_StatementEle_43Analyzer() {}
R004_StatementEle_43Analyzer::~R004_StatementEle_43Analyzer() {}



//beg_StatementEle : 'TILDE'
R004_StatementEle_44Analyzer::R004_StatementEle_44Analyzer() {}
R004_StatementEle_44Analyzer::~R004_StatementEle_44Analyzer() {}



//beg_StatementEle : 'TWO_COLON'
R004_StatementEle_45Analyzer::R004_StatementEle_45Analyzer() {}
R004_StatementEle_45Analyzer::~R004_StatementEle_45Analyzer() {}



//beg_StatementEle : 'TWO_PLUS'
R004_StatementEle_46Analyzer::R004_StatementEle_46Analyzer() {}
R004_StatementEle_46Analyzer::~R004_StatementEle_46Analyzer() {}



//beg_StatementEle : 'TWO_SUBTRACT'
R004_StatementEle_47Analyzer::R004_StatementEle_47Analyzer() {}
R004_StatementEle_47Analyzer::~R004_StatementEle_47Analyzer() {}



//beg_StatementEle : 'TypeNameId'
R004_StatementEle_48Analyzer::R004_StatementEle_48Analyzer() {}
R004_StatementEle_48Analyzer::~R004_StatementEle_48Analyzer() {}



//beg_StatementEle : 'XOR_EQUAL'
R004_StatementEle_49Analyzer::R004_StatementEle_49Analyzer() {}
R004_StatementEle_49Analyzer::~R004_StatementEle_49Analyzer() {}



//beg_StatementEle : 'abstract'
R004_StatementEle_50Analyzer::R004_StatementEle_50Analyzer() {}
R004_StatementEle_50Analyzer::~R004_StatementEle_50Analyzer() {}



//beg_StatementEle : 'boolean'
R004_StatementEle_51Analyzer::R004_StatementEle_51Analyzer() {}
R004_StatementEle_51Analyzer::~R004_StatementEle_51Analyzer() {}



//beg_StatementEle : 'byte'
R004_StatementEle_52Analyzer::R004_StatementEle_52Analyzer() {}
R004_StatementEle_52Analyzer::~R004_StatementEle_52Analyzer() {}



//beg_StatementEle : 'char'
R004_StatementEle_53Analyzer::R004_StatementEle_53Analyzer() {}
R004_StatementEle_53Analyzer::~R004_StatementEle_53Analyzer() {}



//beg_StatementEle : 'class'
R004_StatementEle_54Analyzer::R004_StatementEle_54Analyzer() {}
R004_StatementEle_54Analyzer::~R004_StatementEle_54Analyzer() {}



//beg_StatementEle : 'default'
R004_StatementEle_55Analyzer::R004_StatementEle_55Analyzer() {}
R004_StatementEle_55Analyzer::~R004_StatementEle_55Analyzer() {}



//beg_StatementEle : 'double'
R004_StatementEle_56Analyzer::R004_StatementEle_56Analyzer() {}
R004_StatementEle_56Analyzer::~R004_StatementEle_56Analyzer() {}



//beg_StatementEle : 'enum'
R004_StatementEle_57Analyzer::R004_StatementEle_57Analyzer() {}
R004_StatementEle_57Analyzer::~R004_StatementEle_57Analyzer() {}



//beg_StatementEle : 'extends'
R004_StatementEle_58Analyzer::R004_StatementEle_58Analyzer() {}
R004_StatementEle_58Analyzer::~R004_StatementEle_58Analyzer() {}



//beg_StatementEle : 'final'
R004_StatementEle_59Analyzer::R004_StatementEle_59Analyzer() {}
R004_StatementEle_59Analyzer::~R004_StatementEle_59Analyzer() {}



//beg_StatementEle : 'float'
R004_StatementEle_60Analyzer::R004_StatementEle_60Analyzer() {}
R004_StatementEle_60Analyzer::~R004_StatementEle_60Analyzer() {}



//beg_StatementEle : 'implements'
R004_StatementEle_61Analyzer::R004_StatementEle_61Analyzer() {}
R004_StatementEle_61Analyzer::~R004_StatementEle_61Analyzer() {}



//beg_StatementEle : 'instanceof'
R004_StatementEle_62Analyzer::R004_StatementEle_62Analyzer() {}
R004_StatementEle_62Analyzer::~R004_StatementEle_62Analyzer() {}



//beg_StatementEle : 'int'
R004_StatementEle_63Analyzer::R004_StatementEle_63Analyzer() {}
R004_StatementEle_63Analyzer::~R004_StatementEle_63Analyzer() {}



//beg_StatementEle : 'interface'
R004_StatementEle_64Analyzer::R004_StatementEle_64Analyzer() {}
R004_StatementEle_64Analyzer::~R004_StatementEle_64Analyzer() {}



//beg_StatementEle : 'long'
R004_StatementEle_65Analyzer::R004_StatementEle_65Analyzer() {}
R004_StatementEle_65Analyzer::~R004_StatementEle_65Analyzer() {}



//beg_StatementEle : 'native'
R004_StatementEle_66Analyzer::R004_StatementEle_66Analyzer() {}
R004_StatementEle_66Analyzer::~R004_StatementEle_66Analyzer() {}



//beg_StatementEle : 'new'
R004_StatementEle_67Analyzer::R004_StatementEle_67Analyzer() {}
R004_StatementEle_67Analyzer::~R004_StatementEle_67Analyzer() {}



//beg_StatementEle : 'null'
R004_StatementEle_68Analyzer::R004_StatementEle_68Analyzer() {}
R004_StatementEle_68Analyzer::~R004_StatementEle_68Analyzer() {}



//beg_StatementEle : 'private'
R004_StatementEle_69Analyzer::R004_StatementEle_69Analyzer() {}
R004_StatementEle_69Analyzer::~R004_StatementEle_69Analyzer() {}



//beg_StatementEle : 'protected'
R004_StatementEle_70Analyzer::R004_StatementEle_70Analyzer() {}
R004_StatementEle_70Analyzer::~R004_StatementEle_70Analyzer() {}



//beg_StatementEle : 'public'
R004_StatementEle_71Analyzer::R004_StatementEle_71Analyzer() {}
R004_StatementEle_71Analyzer::~R004_StatementEle_71Analyzer() {}



//beg_StatementEle : 'short'
R004_StatementEle_72Analyzer::R004_StatementEle_72Analyzer() {}
R004_StatementEle_72Analyzer::~R004_StatementEle_72Analyzer() {}



//beg_StatementEle : 'static'
R004_StatementEle_73Analyzer::R004_StatementEle_73Analyzer() {}
R004_StatementEle_73Analyzer::~R004_StatementEle_73Analyzer() {}



//beg_StatementEle : 'super'
R004_StatementEle_74Analyzer::R004_StatementEle_74Analyzer() {}
R004_StatementEle_74Analyzer::~R004_StatementEle_74Analyzer() {}



//beg_StatementEle : 'synchronized'
R004_StatementEle_75Analyzer::R004_StatementEle_75Analyzer() {}
R004_StatementEle_75Analyzer::~R004_StatementEle_75Analyzer() {}



//beg_StatementEle : 'this'
R004_StatementEle_76Analyzer::R004_StatementEle_76Analyzer() {}
R004_StatementEle_76Analyzer::~R004_StatementEle_76Analyzer() {}



//beg_StatementEle : 'throws'
R004_StatementEle_77Analyzer::R004_StatementEle_77Analyzer() {}
R004_StatementEle_77Analyzer::~R004_StatementEle_77Analyzer() {}



//beg_StatementEle : 'transient'
R004_StatementEle_78Analyzer::R004_StatementEle_78Analyzer() {}
R004_StatementEle_78Analyzer::~R004_StatementEle_78Analyzer() {}



//beg_StatementEle : 'void'
R004_StatementEle_79Analyzer::R004_StatementEle_79Analyzer() {}
R004_StatementEle_79Analyzer::~R004_StatementEle_79Analyzer() {}



//beg_StatementEle : 'volatile'
R004_StatementEle_80Analyzer::R004_StatementEle_80Analyzer() {}
R004_StatementEle_80Analyzer::~R004_StatementEle_80Analyzer() {}



//beg_Modifier : 'public'
R004_Modifier_0Analyzer::R004_Modifier_0Analyzer() {}
R004_Modifier_0Analyzer::~R004_Modifier_0Analyzer() {}



//beg_Modifier : 'protected'
R004_Modifier_1Analyzer::R004_Modifier_1Analyzer() {}
R004_Modifier_1Analyzer::~R004_Modifier_1Analyzer() {}



//beg_Modifier : 'private'
R004_Modifier_2Analyzer::R004_Modifier_2Analyzer() {}
R004_Modifier_2Analyzer::~R004_Modifier_2Analyzer() {}



//beg_Modifier : 'abstract'
R004_Modifier_3Analyzer::R004_Modifier_3Analyzer() {}
R004_Modifier_3Analyzer::~R004_Modifier_3Analyzer() {}



//beg_Modifier : 'static'
R004_Modifier_4Analyzer::R004_Modifier_4Analyzer() {}
R004_Modifier_4Analyzer::~R004_Modifier_4Analyzer() {}



//beg_Modifier : 'final'
R004_Modifier_5Analyzer::R004_Modifier_5Analyzer() {}
R004_Modifier_5Analyzer::~R004_Modifier_5Analyzer() {}



//beg_Modifier : 'strictfp'
R004_Modifier_6Analyzer::R004_Modifier_6Analyzer() {}
R004_Modifier_6Analyzer::~R004_Modifier_6Analyzer() {}



//beg_Modifier : 'default'
R004_Modifier_7Analyzer::R004_Modifier_7Analyzer() {}
R004_Modifier_7Analyzer::~R004_Modifier_7Analyzer() {}



//beg_Modifier : 'volatile'
R004_Modifier_8Analyzer::R004_Modifier_8Analyzer() {}
R004_Modifier_8Analyzer::~R004_Modifier_8Analyzer() {}



//beg_Modifier : 'synchronized'
R004_Modifier_9Analyzer::R004_Modifier_9Analyzer() {}
R004_Modifier_9Analyzer::~R004_Modifier_9Analyzer() {}



//beg_Modifier : 'transient'
R004_Modifier_10Analyzer::R004_Modifier_10Analyzer() {}
R004_Modifier_10Analyzer::~R004_Modifier_10Analyzer() {}



//beg_Modifier : 'native'
R004_Modifier_11Analyzer::R004_Modifier_11Analyzer() {}
R004_Modifier_11Analyzer::~R004_Modifier_11Analyzer() {}



//beg_Modifier : Annotation
R004_Modifier_12Analyzer::R004_Modifier_12Analyzer() {}
R004_Modifier_12Analyzer::~R004_Modifier_12Analyzer() {}



//beg_MethodBody : Block
R004_MethodBody_0Analyzer::R004_MethodBody_0Analyzer() {}
R004_MethodBody_0Analyzer::~R004_MethodBody_0Analyzer() {}



//beg_MethodBody : 'semicolon'
R004_MethodBody_1Analyzer::R004_MethodBody_1Analyzer() {}
R004_MethodBody_1Analyzer::~R004_MethodBody_1Analyzer() {}



//beg_Block : 'LEFT_BRACE' BlockStatements 'RIGHT_BRACE'
R004_Block_0Analyzer::R004_Block_0Analyzer() {}
R004_Block_0Analyzer::~R004_Block_0Analyzer() {}



//beg_Block : 'LEFT_BRACE' BlockStatements 'COMMA_RIGHT_BRACE'
R004_Block_1Analyzer::R004_Block_1Analyzer() {}
R004_Block_1Analyzer::~R004_Block_1Analyzer() {}



//beg_BlockStatements : Block BlockStatements
R004_BlockStatements_0Analyzer::R004_BlockStatements_0Analyzer() {}
R004_BlockStatements_0Analyzer::~R004_BlockStatements_0Analyzer() {}



//beg_BlockStatements : NonBrace BlockStatements
R004_BlockStatements_1Analyzer::R004_BlockStatements_1Analyzer() {}
R004_BlockStatements_1Analyzer::~R004_BlockStatements_1Analyzer() {}



//beg_BlockStatements : 0
R004_BlockStatements_2Analyzer::R004_BlockStatements_2Analyzer() {}
R004_BlockStatements_2Analyzer::~R004_BlockStatements_2Analyzer() {}



//beg_NonBrace : StatementEle
R004_NonBrace_0Analyzer::R004_NonBrace_0Analyzer() {}
R004_NonBrace_0Analyzer::~R004_NonBrace_0Analyzer() {}



//beg_NonBrace : 'COMMA'
R004_NonBrace_1Analyzer::R004_NonBrace_1Analyzer() {}
R004_NonBrace_1Analyzer::~R004_NonBrace_1Analyzer() {}



//beg_NonBrace : 'semicolon'
R004_NonBrace_2Analyzer::R004_NonBrace_2Analyzer() {}
R004_NonBrace_2Analyzer::~R004_NonBrace_2Analyzer() {}



//beg_NonBrace : 'LEFT_ANGLE_BRACKET'
R004_NonBrace_3Analyzer::R004_NonBrace_3Analyzer() {}
R004_NonBrace_3Analyzer::~R004_NonBrace_3Analyzer() {}



//beg_NonBrace : 'LEFT_BRACKET'
R004_NonBrace_4Analyzer::R004_NonBrace_4Analyzer() {}
R004_NonBrace_4Analyzer::~R004_NonBrace_4Analyzer() {}



//beg_NonBrace : 'LEFT_PARENTHESES'
R004_NonBrace_5Analyzer::R004_NonBrace_5Analyzer() {}
R004_NonBrace_5Analyzer::~R004_NonBrace_5Analyzer() {}



//beg_NonBrace : 'RIGHT_ANGLE_BRACKET'
R004_NonBrace_6Analyzer::R004_NonBrace_6Analyzer() {}
R004_NonBrace_6Analyzer::~R004_NonBrace_6Analyzer() {}



//beg_NonBrace : 'RIGHT_BRACKET'
R004_NonBrace_7Analyzer::R004_NonBrace_7Analyzer() {}
R004_NonBrace_7Analyzer::~R004_NonBrace_7Analyzer() {}



//beg_NonBrace : 'RIGHT_PARENTHESES'
R004_NonBrace_8Analyzer::R004_NonBrace_8Analyzer() {}
R004_NonBrace_8Analyzer::~R004_NonBrace_8Analyzer() {}



//beg_Annotation : 'AT' DetailIdentifier AnnotationContent
R004_Annotation_0Analyzer::R004_Annotation_0Analyzer() {}
R004_Annotation_0Analyzer::~R004_Annotation_0Analyzer() {}



//beg_Annotation : 'AT' DetailIdentifier
R004_Annotation_1Analyzer::R004_Annotation_1Analyzer() {}
R004_Annotation_1Analyzer::~R004_Annotation_1Analyzer() {}



//beg_TypeArguments : 'LEFT_ANGLE_BRACKET' TypeArgumentList 'RIGHT_ANGLE_BRACKET'
R004_TypeArguments_0Analyzer::R004_TypeArguments_0Analyzer() {}
R004_TypeArguments_0Analyzer::~R004_TypeArguments_0Analyzer() {}



//beg_TypeArgumentList : NonANGLE_BRACKET TypeArgumentList
R004_TypeArgumentList_0Analyzer::R004_TypeArgumentList_0Analyzer() {}
R004_TypeArgumentList_0Analyzer::~R004_TypeArgumentList_0Analyzer() {}



//beg_TypeArgumentList : 0
R004_TypeArgumentList_1Analyzer::R004_TypeArgumentList_1Analyzer() {}
R004_TypeArgumentList_1Analyzer::~R004_TypeArgumentList_1Analyzer() {}



//beg_NonANGLE_BRACKET : 'QUESTION'
R004_NonANGLE_BRACKET_0Analyzer::R004_NonANGLE_BRACKET_0Analyzer() {}
R004_NonANGLE_BRACKET_0Analyzer::~R004_NonANGLE_BRACKET_0Analyzer() {}



//beg_NonANGLE_BRACKET : 'extends'
R004_NonANGLE_BRACKET_1Analyzer::R004_NonANGLE_BRACKET_1Analyzer() {}
R004_NonANGLE_BRACKET_1Analyzer::~R004_NonANGLE_BRACKET_1Analyzer() {}



//beg_NonANGLE_BRACKET : 'super'
R004_NonANGLE_BRACKET_2Analyzer::R004_NonANGLE_BRACKET_2Analyzer() {}
R004_NonANGLE_BRACKET_2Analyzer::~R004_NonANGLE_BRACKET_2Analyzer() {}



//beg_NonANGLE_BRACKET : 'COMMA'
R004_NonANGLE_BRACKET_3Analyzer::R004_NonANGLE_BRACKET_3Analyzer() {}
R004_NonANGLE_BRACKET_3Analyzer::~R004_NonANGLE_BRACKET_3Analyzer() {}



//beg_NonANGLE_BRACKET : Identifier
R004_NonANGLE_BRACKET_4Analyzer::R004_NonANGLE_BRACKET_4Analyzer() {}
R004_NonANGLE_BRACKET_4Analyzer::~R004_NonANGLE_BRACKET_4Analyzer() {}



//beg_NonANGLE_BRACKET : UnannPrimitiveType
R004_NonANGLE_BRACKET_5Analyzer::R004_NonANGLE_BRACKET_5Analyzer() {}
R004_NonANGLE_BRACKET_5Analyzer::~R004_NonANGLE_BRACKET_5Analyzer() {}



//beg_NonANGLE_BRACKET : 'SPOT'
R004_NonANGLE_BRACKET_6Analyzer::R004_NonANGLE_BRACKET_6Analyzer() {}
R004_NonANGLE_BRACKET_6Analyzer::~R004_NonANGLE_BRACKET_6Analyzer() {}



//beg_NonANGLE_BRACKET : 'LEFT_BRACKET'
R004_NonANGLE_BRACKET_7Analyzer::R004_NonANGLE_BRACKET_7Analyzer() {}
R004_NonANGLE_BRACKET_7Analyzer::~R004_NonANGLE_BRACKET_7Analyzer() {}



//beg_NonANGLE_BRACKET : 'RIGHT_BRACKET'
R004_NonANGLE_BRACKET_8Analyzer::R004_NonANGLE_BRACKET_8Analyzer() {}
R004_NonANGLE_BRACKET_8Analyzer::~R004_NonANGLE_BRACKET_8Analyzer() {}



//beg_UnannPrimitiveType : NumericType
R004_UnannPrimitiveType_0Analyzer::R004_UnannPrimitiveType_0Analyzer() {}
R004_UnannPrimitiveType_0Analyzer::~R004_UnannPrimitiveType_0Analyzer() {}



//beg_UnannPrimitiveType : 'boolean'
R004_UnannPrimitiveType_1Analyzer::R004_UnannPrimitiveType_1Analyzer() {}
R004_UnannPrimitiveType_1Analyzer::~R004_UnannPrimitiveType_1Analyzer() {}



//beg_NumericType : IntegralType
R004_NumericType_0Analyzer::R004_NumericType_0Analyzer() {}
R004_NumericType_0Analyzer::~R004_NumericType_0Analyzer() {}



//beg_NumericType : FloatingPointType
R004_NumericType_1Analyzer::R004_NumericType_1Analyzer() {}
R004_NumericType_1Analyzer::~R004_NumericType_1Analyzer() {}



//beg_IntegralType : 'byte'
R004_IntegralType_0Analyzer::R004_IntegralType_0Analyzer() {}
R004_IntegralType_0Analyzer::~R004_IntegralType_0Analyzer() {}



//beg_IntegralType : 'short'
R004_IntegralType_1Analyzer::R004_IntegralType_1Analyzer() {}
R004_IntegralType_1Analyzer::~R004_IntegralType_1Analyzer() {}



//beg_IntegralType : 'int'
R004_IntegralType_2Analyzer::R004_IntegralType_2Analyzer() {}
R004_IntegralType_2Analyzer::~R004_IntegralType_2Analyzer() {}



//beg_IntegralType : 'long'
R004_IntegralType_3Analyzer::R004_IntegralType_3Analyzer() {}
R004_IntegralType_3Analyzer::~R004_IntegralType_3Analyzer() {}



//beg_IntegralType : 'char'
R004_IntegralType_4Analyzer::R004_IntegralType_4Analyzer() {}
R004_IntegralType_4Analyzer::~R004_IntegralType_4Analyzer() {}



//beg_FloatingPointType : 'float'
R004_FloatingPointType_0Analyzer::R004_FloatingPointType_0Analyzer() {}
R004_FloatingPointType_0Analyzer::~R004_FloatingPointType_0Analyzer() {}



//beg_FloatingPointType : 'double'
R004_FloatingPointType_1Analyzer::R004_FloatingPointType_1Analyzer() {}
R004_FloatingPointType_1Analyzer::~R004_FloatingPointType_1Analyzer() {}



//beg_Superclass : 'extends' ClassType
R004_Superclass_0Analyzer::R004_Superclass_0Analyzer() {}
R004_Superclass_0Analyzer::~R004_Superclass_0Analyzer() {}



//beg_ClassTypeEle : Identifier
R004_ClassTypeEle_0Analyzer::R004_ClassTypeEle_0Analyzer() {}
R004_ClassTypeEle_0Analyzer::~R004_ClassTypeEle_0Analyzer() {}



//beg_ClassTypeEle : AnnotationList Identifier
R004_ClassTypeEle_1Analyzer::R004_ClassTypeEle_1Analyzer() {}
R004_ClassTypeEle_1Analyzer::~R004_ClassTypeEle_1Analyzer() {}



//beg_ClassTypeEle : Identifier TypeArguments
R004_ClassTypeEle_2Analyzer::R004_ClassTypeEle_2Analyzer() {}
R004_ClassTypeEle_2Analyzer::~R004_ClassTypeEle_2Analyzer() {}



//beg_ClassTypeEle : AnnotationList Identifier TypeArguments
R004_ClassTypeEle_3Analyzer::R004_ClassTypeEle_3Analyzer() {}
R004_ClassTypeEle_3Analyzer::~R004_ClassTypeEle_3Analyzer() {}



//beg_ClassType : ClassTypeEle
R004_ClassType_0Analyzer::R004_ClassType_0Analyzer() {}
R004_ClassType_0Analyzer::~R004_ClassType_0Analyzer() {}



//beg_ClassType : ClassTypeEle 'SPOT' ClassType
R004_ClassType_1Analyzer::R004_ClassType_1Analyzer() {}
R004_ClassType_1Analyzer::~R004_ClassType_1Analyzer() {}



//beg_AnnotationList : Annotation AnnotationList
R004_AnnotationList_0Analyzer::R004_AnnotationList_0Analyzer() {}
R004_AnnotationList_0Analyzer::~R004_AnnotationList_0Analyzer() {}



//beg_AnnotationList : Annotation
R004_AnnotationList_1Analyzer::R004_AnnotationList_1Analyzer() {}
R004_AnnotationList_1Analyzer::~R004_AnnotationList_1Analyzer() {}



//beg_Superinterfaces : 'implements' InterfaceTypeList
R004_Superinterfaces_0Analyzer::R004_Superinterfaces_0Analyzer() {}
R004_Superinterfaces_0Analyzer::~R004_Superinterfaces_0Analyzer() {}



//beg_InterfaceTypeList : ClassType
R004_InterfaceTypeList_0Analyzer::R004_InterfaceTypeList_0Analyzer() {}
R004_InterfaceTypeList_0Analyzer::~R004_InterfaceTypeList_0Analyzer() {}



//beg_InterfaceTypeList : ClassType 'COMMA' InterfaceTypeList
R004_InterfaceTypeList_1Analyzer::R004_InterfaceTypeList_1Analyzer() {}
R004_InterfaceTypeList_1Analyzer::~R004_InterfaceTypeList_1Analyzer() {}
