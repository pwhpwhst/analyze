#include<vector>
#include <sstream>
#include <iostream>
#include "SDT_R005_Factory.h"
#include<boost/algorithm/string.hpp>
#include "../treeAnalyzer/java/R005Analyzer.h"
using namespace std;
using namespace boost;



SDT_R005_Factory SDT_R005_Factory::instance;
SDT_R005_Factory::SDT_R005_Factory() {
	control_Param = {
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
   { "R005_AnnotationList_0", 671 },
   { "R005_AnnotationList_1", 672 }
	};
}

P_SDT_genertor SDT_R005_Factory::getSDT_genertor(const string &key) {
	if (factory.count(key) > 0) {
		return factory[key];
	}


	int caseValue = control_Param.count(key) > 0 ? control_Param[key] : -1;


	switch (caseValue) {
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
	case 671: factory["R005_AnnotationList_0"] = P_SDT_genertor(new R005_AnnotationList_0Analyzer()); break;
	case 672: factory["R005_AnnotationList_1"] = P_SDT_genertor(new R005_AnnotationList_1Analyzer()); break;
	default:
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
SDT_R005_Factory::~SDT_R005_Factory() {}


