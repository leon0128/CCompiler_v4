#pragma once

#include <vector>
#include <string>

class TranslationUnit;
class ExternalDeclaration;
class FunctionDefinition;
class Declaration;
class DeclarationSpecifier;
class Declarator;
class CompoundStatement;
class StorageClassSpecifier;
class TypeSpecifier;
class TypeQualifier;
class StructOrUnionSpecifier;
class StructOrUnion;
class Identifier;
class EnumSpecifier;
class TypedefName;
class StructDeclaration;
class SpecifierQualifier;
class StructDeclaratorList;
class TypeSpecifier;
class TypeQualifier;
class StructDeclarator;
class ConstantExpression;
class Pointer;
class DirectDeclarator;
class ParameterTypeList;
class ConditionalExpression;
class LogicalOrExpression;
class LogicalAndExpression;
class Expression;
class InclusiveOrExpression;
class ExclusiveOrExpression;
class AndExpression;
class EqualityExpression;
class RelationalExpression;
class ShiftExpression;
class AdditiveExpression;
class MultiplicativeExpression;
class CastExpression;
class UnaryExpression;
class TypeName;
class PostfixExpression;
class UnaryOperator;
class PrimaryExpression;
class AssignmentExpression;
class Constant;
class String;
class IntegerConstant;
class CharacterConstant;
class FloatingConstant;
class EnumerationConstant;
class AssignmentOperator;
class AbstractDeclarator;
class ParameterList;
class ParameterDeclaration;
class DirectAbstractDeclarator;

class Symbol
{
private:
    static std::vector<Symbol*> SYMBOLS;

public:
    Symbol();
    virtual ~Symbol();

    static void destroy();
};

class TranslationUnit : public Symbol
{
public:
    TranslationUnit():
        Symbol(),
        externalDeclarations(){}
    ~TranslationUnit(){}

    std::vector<ExternalDeclaration*> externalDeclarations;
};

class ExternalDeclaration : public Symbol
{
public:
    enum EExternalDeclaration
    {
        NONE,
        FUNCTION_DEFINITION,
        DECLARATION
    };
    
    ExternalDeclaration():
        Symbol(),
        type(NONE),
        uExternalDeclaration(){}
    ~ExternalDeclaration(){}

    EExternalDeclaration type;
    union
    {
        FunctionDefinition* functionDefinition;
        Declaration* declaration;
    } uExternalDeclaration;
};

class FunctionDefinition : public Symbol
{
public:
    FunctionDefinition():
        Symbol(),
        declarationSpecifiers(),
        declarator(nullptr),
        declarations(),
        compoundStatement(nullptr){}
    ~FunctionDefinition(){}

    std::vector<DeclarationSpecifier*> declarationSpecifiers;
    Declarator* declarator;
    std::vector<Declaration*> declarations;
    CompoundStatement* compoundStatement;
};

class DeclarationSpecifier : public Symbol
{
public:
    DeclarationSpecifier():
        Symbol(),
        type(NONE),
        uDeclarationSpecifier(){}
    ~DeclarationSpecifier(){}
    
    enum EDeclarationSpecifier
    {
        NONE,
        STORAGE_CLASS_SPECIFIER,
        TYPE_SPECIFIER,
        TYPE_QUALIFIER
    };

    EDeclarationSpecifier type;
    union
    {
        StorageClassSpecifier* storageClassSpecifier;
        TypeSpecifier* typeSpecifier;
        TypeQualifier* typeQualifier;
    } uDeclarationSpecifier;
};

class StorageClassSpecifier : public Symbol
{
public:
    StorageClassSpecifier():
        Symbol(),
        type(NONE){}
    ~StorageClassSpecifier(){}

    enum EStorageClassSpecifier
    {
        NONE,
        AUTO,
        REGISTER,
        STATIC,
        EXTERN,
        TYPEDEF
    };

    EStorageClassSpecifier type;
};

class TypeSpecifier : public Symbol
{
public:
    TypeSpecifier():
        Symbol(),
        type(NONE),
        uTypeSpecifier(){}
    ~TypeSpecifier(){}

    enum ETypeSpecifier
    {
        NONE,
        VOID,
        CHAR,
        SHORT,
        INT,
        LONG,
        FLOAT,
        DOUBLE,
        SIGNED,
        UNSIGNED,
        STRUCT_OR_UNION_SPECIFIER,
        ENUM_SPECIFIER,
        TYPEDEF_NAME
    };

    ETypeSpecifier type;
    union
    {
        StructOrUnionSpecifier* structOrUnionSpecifier;
        EnumSpecifier* enumSpecifier;
        TypedefName* typedefName;
    } uTypeSpecifier;
};

class StructOrUnionSpecifier : public Symbol
{
public:
    StructOrUnionSpecifier():
        Symbol(),
        type(NONE),
        uStructOrUnionSpecifier(){}
    ~StructOrUnionSpecifier(){}

    enum EStructOrUnionSpecifier
    {
        NONE,
        STRUCT_OR_UNION_IDENTIFIER_STRUCT_DECLARATIONS,
        STRUCT_OR_UNION_STRUCT_DECLARATIONS,
        STRUCT_OR_UNION_IDENTIFIER
    };

    EStructOrUnionSpecifier type;
    union UStructOrUnionSpecifier
    {
        UStructOrUnionSpecifier(){}
        ~UStructOrUnionSpecifier(){}

        struct 
        {
            StructOrUnion* structOrUnion;
            Identifier* identifier;
            std::vector<StructDeclaration*> structDeclarations;
        } structOrUnionIdentifierStructDeclarations;
        struct
        {
            StructOrUnion* structOrUnion;
            std::vector<StructDeclaration*> structDeclarations;
        } structOrUnionStructDeclarations;
        struct
        {
            StructOrUnion* structOrUnion;
            Identifier* identifier;
        } structOrUnionIdentifier;
    } uStructOrUnionSpecifier;
};

class StructOrUnion : public Symbol
{
public:
    StructOrUnion():
        Symbol(),
        type(NONE){}
    ~StructOrUnion(){}

    enum EStructOrUnion
    {
        NONE,
        STRUCT,
        UNION
    };

    EStructOrUnion type;
};

class StructDeclaration : public Symbol
{
public:
    StructDeclaration():
        Symbol(),
        specifierQualifiers(),
        structDeclaratorList(nullptr){}
    ~StructDeclaration(){}

    std::vector<SpecifierQualifier*> specifierQualifiers;
    StructDeclaratorList* structDeclaratorList;
};

class SpecifierQualifier : public Symbol
{
    SpecifierQualifier():
        Symbol(),
        type(NONE),
        uSpecifierQualifier(){}
    ~SpecifierQualifier(){}

    enum ESpecifierQualifier
    {
        NONE,
        TYPE_SPECIFIER,
        TYPE_QUALIFIER
    };

    ESpecifierQualifier type;
    union
    {
        TypeSpecifier* typeSpecifier;
        TypeQualifier* typeQualifier;
    } uSpecifierQualifier;
};

class StructDeclaratorList : public Symbol
{
public:
    StructDeclaratorList():
        Symbol(),
        type(NONE),
        uStructDeclaratorList(){}
    ~StructDeclaratorList(){}

    enum EStructDeclaratorList
    {
        NONE,
        STRUCT_DECLARATOR,
        STRUCT_DECLARATOR_LIST_STRUCT_DECLARATOR
    };

    EStructDeclaratorList type;
    union UStructDeclaratorList
    {
        UStructDeclaratorList(){}
        ~UStructDeclaratorList(){}

        StructDeclarator* structDeclarator;
        struct
        {
            StructDeclaratorList* structDeclaratorList;
            StructDeclarator* structDeclarator;
        } structDeclaratorListStructDeclarator;
    } uStructDeclaratorList;
};

class StructDeclarator : public Symbol
{
public:
    StructDeclarator():
        Symbol(),
        type(NONE),
        uStructDeclarator(){}
    ~StructDeclarator(){}

    enum EStructDeclarator
    {
        NONE,
        DECLARATOR,
        DECLARATOR_CONSTANT_EXPRESSION,
        CONSTANT_EXPRESSION
    };

    EStructDeclarator type;
    union UStructDeclarator
    {
        UStructDeclarator(){}
        ~UStructDeclarator(){}

        Declarator* declarator;
        struct
        {
            Declarator* declarator;
            ConstantExpression* constantExpression;
        } declaratorConstantExpression;
        ConstantExpression* constantExpression;
    } uStructDeclarator;
};

class Declarator : public Symbol
{
public:
    Declarator():
        Symbol(),
        pointer(nullptr),
        directDeclarator(nullptr){}
    ~Declarator(){}

    Pointer* pointer;
    DirectDeclarator* directDeclarator;
};

class Pointer : public Symbol
{
public:
    Pointer():
        Symbol(),
        typeQualifiers(),
        pointer(nullptr){}
    ~Pointer(){}

    std::vector<TypeQualifier*> typeQualifiers;
    Pointer* pointer;
};

class TypeQualifier : public Symbol
{
public:
    TypeQualifier():
        Symbol(),
        type(NONE){}
    ~TypeQualifier(){}

    enum ETypeQualifier
    {
        NONE,
        CONST,
        VOLATILE
    };

    ETypeQualifier type;
};

class DirectDeclarator : public Symbol
{
public:
    DirectDeclarator():
        Symbol(),
        type(NONE),
        uDirectDeclarator(){}
    ~DirectDeclarator(){}

    enum EDirectDeclarator
    {
        NONE,
        IDENTIFIER,
        DIRECT_DECLARATOR_CONSTANT_EXPRESSION,
        DIRECT_DECLARATOR_PARAMETER_TYPE_LIST,
        DIRECT_DECLARATOR_IDENTIFIERS
    };

    EDirectDeclarator type;
    union UDirectDeclarator
    {
        UDirectDeclarator(){}
        ~UDirectDeclarator(){}

        Identifier* identifier;
        Declarator* declarator;
        struct
        {
            DirectDeclarator* directDeclarator;
            ConstantExpression* constantExpression;
        } directDeclaratorConstantExpression;
        struct
        {
            DirectDeclarator* directDeclarator;
            ParameterTypeList* parameterTypeList;
        } directDeclaratorParameterTypeList;
        struct
        {
            DirectDeclarator* directDeclarator;
            std::vector<Identifier*> identifiers;
        } directDeclaratorIdentifiers;
    } uDirectDeclarator;
};

class ConstantExpression : public Symbol
{
public:
    ConstantExpression():
        Symbol(),
        conditionalExpression(nullptr){}
    ~ConstantExpression(){}

    ConditionalExpression* conditionalExpression;
};

class ConditionalExpression : public Symbol
{
public:
    ConditionalExpression():
        Symbol(),
        type(NONE){}
    ~ConditionalExpression(){}

    enum EConditionalExpression
    {
        NONE,
        LOGICAL_OR_EXPRESSION,
        LOGICAL_OR_EXPRESSION_EXPRESSION_CONDITIONAL_EXPRESSION
    };
    
    EConditionalExpression type;
    union UConditionalExpression
    {
        UConditionalExpression(){}
        ~UConditionalExpression(){}

        LogicalOrExpression* logicalOrExpression;
        struct
        {
            LogicalOrExpression* logicalOrExpression;
            Expression* expression;
            ConditionalExpression* conditionalExpression;
        } logicalOrExpressionExpressionConditionalExpression;
    } uConditionalExpression;
};

class LogicalOrExpression : public Symbol
{
public:
    LogicalOrExpression():
        Symbol(),
        type(NONE),
        uLogicaoOrExpression(){}
    ~LogicalOrExpression(){}

    enum ELogicalOrExpression
    {
        NONE,
        LOGICAL_OR_EXPRESSION,
        LOGICAL_OR_EXPRESSION_LOGICAL_AND_EXPRESSION
    };

    ELogicalOrExpression type;
    union ULogicalOrExpression
    {
        LogicalAndExpression* logicalAndExpression;
        struct
        {
            LogicalOrExpression* logicalOrExpression;
            LogicalAndExpression* logicalAndExpression;
        } logicalOrExpressionLogicalAndExpression;
    } uLogicaoOrExpression;
};

class LogicalAndExpression : public Symbol
{
public:
    LogicalAndExpression():
        Symbol(),
        type(NONE),
        uLogicalAndExpression(){}
    ~LogicalAndExpression(){}

    enum ELogicalAndExpression
    {
        NONE,
        INCLUSIVE_OR_EXPRESSION,
        LOGICAL_AND_EXPRESSION_INCLUSIVE_OR_EXPRESSION
    };

    ELogicalAndExpression type;
    union ULogicalAndExpression
    {
        InclusiveOrExpression* inclusiveOrExpression;
        struct
        {
            LogicalAndExpression* logicalAndExpression;
            InclusiveOrExpression* inclusiveOrExpression;
        } logicalAndExpressionInclusiveOrExpression;
    } uLogicalAndExpression;
};

class InclusiveOrExpression : public Symbol
{
public:
    InclusiveOrExpression():
        Symbol(),
        type(NONE),
        uInclusiveOrExpression(){}
    ~InclusiveOrExpression(){}

    enum EInclusiveOrExpression
    {
        NONE,
        EXCLUSIVE_OR_EXPRESSION,
        INCLUSIVE_OR_EXPRESSION_EXCLUSIVE_OR_EXPRESSION
    };

    EInclusiveOrExpression type;
    union UInclusiveOrExpression
    {
        ExclusiveOrExpression* exclusiveOrExpression;
        struct
        {
            InclusiveOrExpression* inclusiveOrExpression;
            ExclusiveOrExpression* exclusiveOrExpression;
        } inclusiveOrExpressionExclusiveOrExpression;
    } uInclusiveOrExpression;
};

class ExclusiveOrExpression : public Symbol
{
public:
    ExclusiveOrExpression():
        Symbol(),
        type(NONE),
        uExclusiveOrExpression(){}
    ~ExclusiveOrExpression(){}

    enum EExclusiveOrExpression
    {
        NONE,
        AND_EXPRESSION,
        EXCLUSIVE_OR_EXPRESSION_AND_EXPRESSION
    };

    EExclusiveOrExpression type;
    union UExclusiveOrExpression
    {
        AndExpression* andExpression;
        struct
        {
            ExclusiveOrExpression* exclusiveOrExpression;
            AndExpression* andExpression;
        } exclusiveOrExpressionAndExpression;
    } uExclusiveOrExpression;
};

class AndExpression : public Symbol
{
public:
    AndExpression():
        Symbol(),
        type(NONE),
        uAndExpression(){}
    ~AndExpression(){}

    enum EAndExpression
    {
        NONE,
        EQUALITY_EXPRESSION,
        AND_EXPRESSION_EQUALITY_EXPRESSION
    };

    EAndExpression type;
    union UAndExpression
    {
        EqualityExpression* equalityExpression;
        struct
        {
            AndExpression* andExpression;
            EqualityExpression* equalityExpression;
        } andExpressionEqualityExpression;
    } uAndExpression;
};

class EqualityExpression : public Symbol
{
public:
    EqualityExpression():
        Symbol(),
        type(NONE),
        uEqualityExpression(){}
    ~EqualityExpression(){}
    
    enum EEqualityExpression
    {
        NONE,
        RELATIONAL_EXPRESSION,
        EQUALITY_EXPRESSION_EQUAL_RELATIONAL_EXPRESSION,
        EQUALITY_EXPRESSION_NOT_EQUAL_RELATIONAL_EXPRESSION
    };

    EEqualityExpression type;
    union UEqualityExpression
    {
        UEqualityExpression(){}
        ~UEqualityExpression(){}

        RelationalExpression* relationalExpression;
        struct
        {
            EqualityExpression* equalityExpression;
            RelationalExpression* relationalExpression;
        } uEqualityExpressionEqualRelationalExpression;
        struct
        {
            EqualityExpression* equalityExpression;
            RelationalExpression* relationalExpression;
        } uEqualityExpressionNotEqualRelationalExpression;
    } uEqualityExpression;
};

class RelationalExpression : public Symbol
{
public:
    RelationalExpression():
        Symbol(),
        type(NONE),
        uRelationalExpression(){}
    ~RelationalExpression(){}

    enum ERelationalExpression
    {
        NONE,
        SHIFT_EXPRESSION,
        RELATIONAL_EXPRESSION_LESS_SHIFT_EXPRESSION,
        RELATIONAL_EXPRESSION_GREATER_SHIFT_EXPRESSION,
        RELATIONAL_EXPRESSION_LESS_EQUAL_EXPRESSION,
        RELATIONAL_EXPRESSION_GREATER_EQUAL_EXPRESSION
    };

    ERelationalExpression type;
    union URelationalExpression
    {
        URelationalExpression(){}
        ~URelationalExpression(){}

        ShiftExpression* shiftExpression;
        struct
        {
            RelationalExpression* relationalExpression;
            ShiftExpression* shiftExpression;
        } relationalExpressionLessShiftExpression;
        struct
        {
            RelationalExpression* relationalExpression;
            ShiftExpression* shiftExpression;
        } relationalExpressionGreaterShiftExpression;
        struct
        {
            RelationalExpression* relationalExpression;
            ShiftExpression* shiftExpression;
        } relationalExpressionLessEqualShiftExpression;
        struct
        {
            RelationalExpression* relationalExpression;
            ShiftExpression* shiftExpression;
        } relationalExpressionGreaterEqualShiftExpression;
    } uRelationalExpression;
};

class ShiftExpression : public Symbol
{
public:
    ShiftExpression():
        Symbol(),
        type(NONE),
        uShiftExpression(){}
    ~ShiftExpression(){}

    enum EShiftExpression
    {
        NONE,
        ADDITIVE_EXPRESSION,
        SHIFT_EXPRESSION_LEFT_ADDITIVE_EXPRESSION,
        SHIFT_EXPRESSION_RIGHT_ADDITIVE_EXPRESSION
    };

    EShiftExpression type;
    union UShiftExpression
    {
        UShiftExpression(){}
        ~UShiftExpression(){}

        AdditiveExpression* additiveExpression;
        struct
        {
            ShiftExpression* shiftExpression;
            AdditiveExpression* additiveExpression;
        } shiftExpressionLeftAdditiveExpression;
        struct
        {
            ShiftExpression* shiftExpression;
            AdditiveExpression* additiveExpression;
        } shiftExpressionRightAdditiveExpression;
    } uShiftExpression;
};

class AdditiveExpression : public Symbol
{
public:
    AdditiveExpression():
        Symbol(),
        type(NONE),
        uAdditiveExpression(){}
    ~AdditiveExpression(){}

    enum EAdditiveExpression
    {
        NONE,
        MULTIPLICATIVE_EXPRESSION,
        ADDITIVE_EXPRESSION_PLUS_MULTIPLICATIVE_EXPRESSION,
        ADDITIVE_EXPRESSION_MINUS_MULTIPLICATIVE_EXPRESSION
    };

    EAdditiveExpression type;
    union UAdditiveExpression
    {
        UAdditiveExpression(){}
        ~UAdditiveExpression(){}

        MultiplicativeExpression* multiplicativeExpression;
        struct
        {
            AdditiveExpression* additiveExpression;
            MultiplicativeExpression* multiplicativeExpression;
        } additiveExpressionPlusMultiplicativeExpression;
        struct
        {
            AdditiveExpression* additiveExpression;
            MultiplicativeExpression* multiplicativeExpression;
        } additiveExpressionMinusMultiplicativeExpression;
    } uAdditiveExpression;
};

class MultiplicativeExpression : public Symbol
{
public:
    MultiplicativeExpression():
        Symbol(),
        type(NONE),
        uMultiplicativeExpression(){}
    ~MultiplicativeExpression(){}

    enum EMultiplicativeExpression
    {
        NONE,
        CAST_EXPRESSION,
        MULTIPLICATIVE_EXPRESSION_MULTIPLY_CAST_EXPRESSION,
        MULTIPLICATIVE_EXPRESSION_DIVIDE_CAST_EXPRESSION,
        MULTIPLICATIVE_EXPRESSION_MODULO_CAST_EXPRESSION
    };

    EMultiplicativeExpression type;
    union UMultiplicativeExpression
    {
        UMultiplicativeExpression(){}
        ~UMultiplicativeExpression(){}

        CastExpression* castExpression;
        struct
        {
            MultiplicativeExpression* multiplicativeExpression;
            CastExpression* castExpression;
        } multiplicativeExpressionMultiplyCastExpression;
        struct
        {
            MultiplicativeExpression* multiplicativeExpression;
            CastExpression* castExpression;
        } multiplicativeExpressionDivideCastExpression;
        struct
        {
            MultiplicativeExpression* multiplicativeExpression;
            CastExpression* castExpression;
        } multiplicativeExpressionModuloCastExpression;
    } uMultiplicativeExpression;
};

class CastExpression : public Symbol
{
public:
    CastExpression():
        Symbol(),
        type(NONE),
        uCastExpression(){}
    ~CastExpression(){}

    enum ECastExpression
    {
        NONE,
        UNARY_EXPRESSION,
        TYPE_NAME_CAST_EXPRESSION
    };

    ECastExpression type;
    union UCastExpression
    {
        UCastExpression(){}
        ~UCastExpression(){}

        UnaryExpression* unaryExpression;
        struct
        {
            TypeName* typeName;
            CastExpression* castExpression;
        } typeNameCastExpression;
    } uCastExpression;
};

class UnaryExpression : public Symbol
{
public:
    UnaryExpression():
        Symbol(),
        type(NONE),
        uUnaryExpression(){}
    ~UnaryExpression(){}
    
    enum EUnaryExpression
    {
        NONE,
        POSTFIX_EXPRESSION,
        INCREMENT_UNARY_EXPRESSION,
        DECREMENT_UNARY_EXPRESSION,
        UNARY_OPERATOR_CAST_EXPRESSION,
        SIZEOF_UNARY_EXPRESSION,
        SIZEOF_TYPE_NAME
    };

    EUnaryExpression type;
    union UUnaryExpression
    {
        UUnaryExpression(){}
        ~UUnaryExpression(){}

        PostfixExpression* postfixExpression;
        UnaryExpression* incrementUnaryExpression;
        UnaryExpression* decrementUnaryExpression;
        struct
        {
            UnaryOperator* unaryOperator;
            CastExpression* castExpression;
        } unaryOperatorCastExpression;
        UnaryExpression* sizeofUnaryExpression;
        TypeName* sizeofTypeName;
    } uUnaryExpression;
};

class PostfixExpression : public Symbol
{
public:
    PostfixExpression():
        Symbol(),
        type(NONE),
        uPostfixExpression(){}
    ~PostfixExpression(){}

    enum EPostfixExpression
    {
        NONE,
        PRIMARY_EXPRESSION,
        POSTFIX_EXPRESSION_EXPRESSION,
        POSTFIX_EXPRESSION_ASSIGNMENT_EXPRESSIONS,
        POSTFIX_EXPRESSION_DOT_IDENTIFIER,
        POSTFIX_EXPRESSION_ARROW_IDENTIFIER,
        POSTFIX_EXPRESSION_INCREMENT,
        POSTFIX_EXPRESSION_DECREMENT
    };

    EPostfixExpression type;
    union UPostfixExpression
    {
        UPostfixExpression(){}
        ~UPostfixExpression(){}

        PrimaryExpression* primaryExpression;
        struct
        {
            PostfixExpression* postfixExpression;
            Expression* expression;
        } postfixExpressionExpression;
        struct
        {
            PostfixExpression* postfixExpression;
            std::vector<AssignmentExpression*> assignementExpressions;
        } postfixExpressionAssignmentExpressions;
        struct
        {
            PostfixExpression* postfixExpression;
            Identifier* identifier;
        } postfixExpressionDotIdentifier;
        struct
        {
            PostfixExpression* postfixExpression;
            Identifier* identifier;
        } postfixExpressionArrowIdentifier;
        PostfixExpression* postfixExpressionIncrement;
        PostfixExpression* postfixExpressionDecrement;
    } uPostfixExpression;
};

class PrimaryExpression : public Symbol
{
public:
    PrimaryExpression():
        Symbol(),
        type(NONE),
        uPrimaryExpression(){}
    ~PrimaryExpression(){}

    enum EPrimaryExpression
    {
        NONE,
        IDENTIFIER,
        CONSTANT,
        STRING,
        EXPRESSION    
    };

    EPrimaryExpression type;
    union
    {
        Identifier* identifier;
        Constant* constant;
        String* string;
        Expression* expression;
    } uPrimaryExpression;
};

class Constant : public Symbol
{
public:
    Constant():
        Symbol(),
        type(NONE),
        uConstant(){}
    ~Constant(){}

    enum EConstant
    {
        NONE,
        INTEGER_CONSTANT,
        CHARACTER_CONSTANT,
        FLOATING_CONSTANT,
        ENUMERATION_CONSTANT
    };

    EConstant type;
    union
    {
        IntegerConstant* integerConstant;
        CharacterConstant* characterConstant;
        FloatingConstant* floatingConstant;
        EnumerationConstant* enumerationConstant;
    } uConstant;
};

class Expression : public Symbol
{
public:
    Expression():
        Symbol(),
        type(NONE),
        uExpression(){}
    ~Expression(){}

    enum EExpression
    {
        NONE,
        ASSIGNMENT_EXPRESSION,
        EXPRESSION_ASSIGNMENT_EXPRESSION
    };
    
    EExpression type;
    union UExpression
    {
        UExpression(){}
        ~UExpression(){}

        AssignmentExpression* assignmentExpression;
        struct
        {
            Expression* expression;
            AssignmentExpression* assignmentExpression;
        } expressionAssignmentExpression;
    } uExpression;
};

class AssignmentExpression : public Symbol
{
public:
    AssignmentExpression():
        Symbol(),
        type(NONE),
        uAssignmentExpression(){}
    ~AssignmentExpression(){}

    enum EAssignmentExpression
    {
        NONE,
        CONDITIONAL_EXPRESSION,
        UNARY_EXPRESSION_ASSIGNMENT_OPERATOR_ASSIGNMENT_EXPRESSION
    };

    EAssignmentExpression type;
    union UAssignmentExpression
    {
        UAssignmentExpression(){}
        ~UAssignmentExpression(){}

        ConditionalExpression* conditionalExpression;
        struct
        {
            UnaryExpression* unaryExpression;
            AssignmentOperator* assignmentOperator;
            AssignmentExpression* assignmentExpression;
        } unaryExpressionAssignmentOperatorAssignmentExpression;
    } uAssignmentExpression;
};

class AssignmentOperator : public Symbol
{
public:
    AssignmentExpression():
        Symbol(),
        type(NONE){}
    ~AssignmentExpression(){}

    enum EAssignmentOperator
    {
        NONE,
        EQUAL,
        MULTIPLY_EQUAL,
        DIVIDE_EQUAL,
        MODULO_EQUAL,
        PLUS_EQUAL,
        MINUS_EQUAL,
        LEFT_SHIFT_EQUAL,
        RIGHT_SHIFT_EQUAL,
        AND_EQUAL,
        XOR_EQUAL,
        OR_EQUAL
    };

    EAssignmentOperator type;
};

class UnaryOperator : public Symbol
{
public:
    UnaryExpression():
        Symbol(),
        type(NONE){}
    ~UnaryExpression(){}

    enum EUnaryOperator
    {
        NONE,
        AND,
        ASTERISK,
        PLUS,
        MINUS,
        TILDE,
        NOT
    };

    EUnaryOperator type;
};

class TypeName : public Symbol
{
public:
    TypeName():
        Symbol(),
        specifierQualifiers(),
        abstractDeclarator(){}
    ~TypeName(){}

    std::vector<SpecifierQualifier*> specifierQualifiers;
    AbstractDeclarator* abstractDeclarator;
};

class ParameterTypeList : public Symbol
{
public:
    ParameterList():
        Symbol(),
        parameterLists(){}
    ~ParameterList(){}

    std::vector<ParameterList*> parameterLists;
};

class ParameterList : public Symbol
{
public:
    ParameterList():
        Symbol(),
        type(NONE),
        uParameterList(){}
    ~ParameterList(){}
    
    enum EParameterList
    {
        NONE,
        PARAMETER_DECLARATION,
        PARAMETER_LIST_PARAMETER_DECLARATION
    };

    EParameterList type;
    union UParameterList
    {
        UParameterList(){}
        ~UParameterList(){}

        ParameterDeclaration* parameterDeclaration;
        struct
        {
            ParameterList* parameterList;
            ParameterDeclaration* parameterDeclaration;
        } parameterListParameterDeclaration;
    } uParameterList;
};

class ParameterDeclaration : public Symbol
{
public:
    ParameterDeclaration():
        Symbol(),
        type(NONE),
        uParameterDeclaration(){}
    ~ParameterDeclaration(){}

    enum EParameterDeclaration
    {
        NONE,
        DECLARATION_SPECIFIERS_DECLARATOR,
        DECLARATION_SPECIFIERS_ABSTRACT_DECLARATOR,
        DECLARATION_SPECIFIERS
    };

    EParameterDeclaration type;
    union UParameterDeclaration
    {
        UParameterDeclaration(){}
        ~UParameterDeclaration(){}

        struct
        {
            std::vector<DeclarationSpecifier*> declarationSpecifiers;
            Declarator* declarator;
        } declarationSpecifiersDeclarator;
        struct
        {
            std::vector<DeclarationSpecifier*> declarationSpecifiers;
            AbstractDeclarator* abstractDeclarator;
        } declarationSpecifiersAbstractDeclarator;
        std::vector<DeclarationSpecifier*> declarationSpecifiers;
    } uParameterDeclaration;
};

class AbstractDeclarator : public Symbol
{
public:
    AbstractDeclarator():
        Symbol(),
        type(NONE),
        uAbstractDeclarator(){}
    ~AbstractDeclarator(){}

    enum EAbstractDeclarator
    {
        NONE,
        POINTER,
        POINTER_DIRECT_ABSTRACT_DECLARATOR,
        DIRECT_ABSTRACT_DECLARATOR
    };
    
    EAbstractDeclarator type;
    union UAbstractDeclarator
    {
        UAbstractDeclarator(){}
        ~UAbstractDeclarator(){}

        Pointer* pointer;
        struct
        {
            Pointer* pointer;
            DirectAbstractDeclarator* directAbstractDeclarator;
        } pointerDirectAbstractDeclarator;
        DirectAbstractDeclarator* directAbstractDeclarator;
    } uAbstractDeclarator;
};

class DirectAbstractDeclarator : public Symbol
{
public:

    enum EDirec

    union UDirectAbstractDeclarator
    {
        UDirectAbstractDeclarator(){}
        ~UDirectAbstractDeclarator(){}

        AbstractDeclarator* abstractDeclarator;
        struct
        {
            DirectAbstractDeclarator* directAbstractDeclarator;
            ConstantExpression* constantExpression;
        } directAbstractDeclaratorConstantExpression;
        struct
        {
            DirectAbstractDeclarator* directAbstractDeclarator;
            ParameterTypeList* parameterTypeList;
        } directAbstractDeclaratorParameterTypeList;
    } uDirectAbstractDeclarator;
};