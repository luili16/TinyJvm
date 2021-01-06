//
// Created by 刘立新 on 2020/11/27.
//

#include "AttributeInfo.h"
#include "ConstantUtf8Info.h"
#include "Attributes.h"
#include "AttrConstantValue.h"
#include "CodeAttribute.h"
#include "AttrRaw.h"
#include "AttrBootstrapMethod.h"
#include "AttrEnclosingMethod.h"
#include "AttrExceptions.h"
#include "AttrLineNumberTable.h"
#include "AttrLocalVariableTable.h"
#include "AttrLocalVariableTypeTable.h"

const std::u16string class_file::AttributeInfo::CONSTANT_VALUE = u"ConstantValue";
const std::u16string class_file::AttributeInfo::CODE = u"Code";
const std::u16string class_file::AttributeInfo::STACK_MAP_TABLE = u"StackMapTable";
const std::u16string class_file::AttributeInfo::EXCEPTIONS = u"Exceptions";
const std::u16string class_file::AttributeInfo::ENCLOSING_METHOD = u"EnclosingMethod";
const std::u16string class_file::AttributeInfo::INNER_CLASSES = u"InnerClasses";
const std::u16string class_file::AttributeInfo::SYNTHETIC = u"Synthetic";
const std::u16string class_file::AttributeInfo::SIGNATURE = u"Signature";
const std::u16string class_file::AttributeInfo::SOURCE_FILE = u"SourceFile";
const std::u16string class_file::AttributeInfo::SOURCE_DEBUG_EXTENSION = u"SourceDebugExtension";
const std::u16string class_file::AttributeInfo::LINE_NUMBER_TABLE = u"LineNumberTable";
const std::u16string class_file::AttributeInfo::LOCAL_VARIABLE_TABLE = u"LocalVariableTable";
const std::u16string class_file::AttributeInfo::LOCAL_VARIABLE_TYPE_TABLE = u"LocalVariableTypeTable";
const std::u16string class_file::AttributeInfo::DEPRECATED = u"Deprecated";
const std::u16string class_file::AttributeInfo::RUNTIME_VISIBLE_ANNOTATIONS = u"RuntimeVisibleAnnotations";
const std::u16string class_file::AttributeInfo::RUNTIME_INVISIBLE_ANNOTATIONS = u"RuntimeInvisibleAnnotations";
const std::u16string class_file::AttributeInfo::RUNTIME_VISIBLE_PARAMETER_ANNOTATIONS = u"RuntimeVisibleParameterAnnotations";
const std::u16string class_file::AttributeInfo::RUNTIME_INVISIBLE_PARAMETER_ANNOTATIONS = u"RuntimeInvisibleParameterAnnotations";
const std::u16string class_file::AttributeInfo::RUNTIME_VISIBLE_TYPE_ANNOTATIONS = u"RuntimeVisibleTypeAnnotations";
const std::u16string class_file::AttributeInfo::RUNTIME_INVISIBLE_TYPE_ANNOTATIONS = u"RuntimeInvisibleTypeAnnotations";
const std::u16string class_file::AttributeInfo::ANNOTATION_DEFAULT = u"AnnotationDefault";
const std::u16string class_file::AttributeInfo::BOOTSTRAP_METHODS = u"BootstrapMethods";
const std::u16string class_file::AttributeInfo::METHOD_PARAMETERS = u"MethodParameters";


uint16_t class_file::AttributeInfo::getAttributeNameIndex() const {
    return this->attributeNameIndex;
}

class_file::AttributeInfo::AttributeInfo(uint16_t attributeNameIndex,
                                         uint32_t attributeLength,
                                         const ConstantPool* constantPool
                                         ) :
        attributeNameIndex(attributeNameIndex),
        attributeLength(attributeLength),
        constantPool(constantPool)
        {
}

uint32_t class_file::AttributeInfo::getAttributeLength() const {
    return this->attributeLength;
}

class_file::AttributeInfo::~AttributeInfo() = default;

class_file::AttributeInfo *
class_file::AttributeInfo::newAttributeInfoByName(const class_file::ConstantPool *constantPool,
                                                  class_file::ClassReader &reader) {

    uint16_t attributeNameIndex = reader.readUint16();
    uint32_t attributeLength = reader.readUint32();
    auto utf8Info = constantPool->getConstantUtf8Info(attributeNameIndex);
    auto attributeName = const_cast<std::u16string &>(*(utf8Info)->decodeMUTF8());
    if (isConstantValue(attributeName)) {
        const uint16_t constantValueIndex = reader.readUint16();
        auto constantValueAttribute = new AttrConstantValue(
                attributeNameIndex,
                attributeLength,
                constantPool,
                constantValueIndex);
        return constantValueAttribute;
    } else if (isCode(attributeName)) {
        const uint16_t maxStack = reader.readUint16();
        const uint16_t maxLocals = reader.readUint16();
        const uint32_t codeLength = reader.readUint32();

        uint8_t *code;
        if (codeLength == 0) {
            code = nullptr;
        } else {
            code = new uint8_t[codeLength];
            for (int i = 0; i < codeLength; i++) {
                code[i] = reader.readUint8();
            }
        }

        const ExceptionTable *exceptionTable = ExceptionTable::newExceptionTable(constantPool, reader);
        const Attributes *attributes = Attributes::newAttributes(constantPool, reader);
        auto codeAttribute = new CodeAttribute(
                attributeNameIndex,
                attributeLength,
                constantPool,
                maxStack,
                maxLocals,
                codeLength,
                code,
                exceptionTable,
                attributes
        );
        return codeAttribute;
    } else if (isBootstrapMethods(attributeName)) {
        uint16_t numBootstrapMethods = reader.readUint16();
        BootStrapMethod** bootstrapMethods = nullptr;
        if (numBootstrapMethods > 0) {
            bootstrapMethods = new BootStrapMethod*[numBootstrapMethods];
            for (int i = 0;i < numBootstrapMethods; i++) {
                uint16_t bootstrapMethodRef = reader.readUint16();
                uint16_t numBootstrapArguments = reader.readUint16();
                uint16_t * bootstrapArguments = nullptr;
                if (numBootstrapArguments > 0) {
                    bootstrapArguments = new uint16_t [numBootstrapArguments];
                    for (int j = 0; j < numBootstrapArguments; j++) {
                        bootstrapArguments[j] = reader.readUint16();
                    }
                }
                bootstrapMethods[i] = new BootStrapMethod(
                        bootstrapMethodRef,
                        numBootstrapArguments,
                        bootstrapArguments
                        );
            }
        }
        auto attr = new AttrBootstrapMethod(
                attributeNameIndex,
                attributeLength,
                constantPool,
                numBootstrapMethods,
                const_cast<const BootStrapMethod**>(bootstrapMethods)
                );
        return attr;
    } else if (isEnclosingMethod(attributeName)) {
        uint16_t classIndex = reader.readUint16();
        uint16_t methodIndex = reader.readUint16();
        auto attr = new AttrEnclosingMethod (
                attributeNameIndex,
                attributeLength,
                constantPool,
                classIndex,
                methodIndex
                );
        return attr;
    } else if (isExceptions(attributeName)) {
        uint16_t numberOfExceptions = reader.readUint16();
        uint16_t *exceptionIndexTable = nullptr;
        if (numberOfExceptions > 0) {
            exceptionIndexTable = new uint16_t [numberOfExceptions];
            for (int i = 0; i < numberOfExceptions; i++) {
                uint16_t uint16t = reader.readUint16();
                exceptionIndexTable[i] = uint16t;
            }
        }
        auto attr = new AttrExceptions(
                attributeNameIndex,
                attributeLength,
                constantPool,
                numberOfExceptions,
                exceptionIndexTable
                );
        return attr;
    } else if (isLineNumberTable(attributeName)) {
        uint16_t lineNumberTableLength = reader.readUint16();
        LineNumberTable0** lineNumberTable = nullptr;
        if (lineNumberTableLength > 0) {
            lineNumberTable = new LineNumberTable0*[lineNumberTableLength];
            for (int i = 0; i < lineNumberTableLength; i++) {
                uint16_t startPc = reader.readUint16();
                uint16_t lineNumber = reader.readUint16();
                lineNumberTable[i] = new LineNumberTable0(
                            startPc,
                            lineNumber
                        );
            }
        }
        auto attr = new AttrLineNumberTable(
                attributeNameIndex,
                attributeLength,
                constantPool,
                lineNumberTableLength,
                const_cast<const LineNumberTable0**>(lineNumberTable)
                );
        return attr;
    } else if (isLocalVariableTable(attributeName)) {
        uint16_t localVariableTableLength = reader.readUint16();
        LocalVariableTable** localVariableTable = nullptr;
        if (localVariableTableLength > 0) {
            localVariableTable = new LocalVariableTable*[localVariableTableLength];
            for (int i = 0; i < localVariableTableLength; i++) {
                uint16_t startPc = reader.readUint16();
                uint16_t length = reader.readUint16();
                uint16_t nameIndex = reader.readUint16();
                uint16_t descriptorIndex = reader.readUint16();
                uint16_t index = reader.readUint16();
                auto table = new LocalVariableTable(
                            startPc,
                            length,
                            nameIndex,
                            descriptorIndex,
                            index
                        );
                localVariableTable[i] = table;
            }
        }
        auto attr = new AttrLocalVariableTable(
                attributeNameIndex,
                attributeLength,
                constantPool,
                localVariableTableLength,
                const_cast<const LocalVariableTable**>(localVariableTable)
                );
        return attr;
    } else if (isLocalVariableTypeTable(attributeName)) {
        uint16_t localVariableTypeTableLength = reader.readUint16();
        LocalVariableTypeTable** localVariableTypeTable = nullptr;
        if (localVariableTypeTableLength > 0) {
            localVariableTypeTable = new LocalVariableTypeTable*[localVariableTypeTableLength];
            for (int i = 0; i < localVariableTypeTableLength; i++) {
                uint16_t startPc = reader.readUint16();
                uint16_t length = reader.readUint16();
                uint16_t nameIndex =reader.readUint16();
                uint16_t signatureIndex = reader.readUint16();
                uint16_t index = reader.readUint16();
                localVariableTypeTable[i] = new LocalVariableTypeTable(
                            startPc,
                            length,
                            nameIndex,
                            signatureIndex,
                            index
                        );
            }
        }
        auto attr = new AttrLocalVariableTypeTable(
                attributeNameIndex,
                attributeLength,
                constantPool,
                localVariableTypeTableLength,
                const_cast<const LocalVariableTypeTable**>(localVariableTypeTable)
        );
        return attr;
    } else {
        uint8_t *info = nullptr;
        if (attributeLength > 0) {
            info = new uint8_t[attributeLength];
            for (int j = 0; j < attributeLength; j++) {
                info[j] = reader.readUint8();
            }
        }
        auto *attributeInfo = new AttrRaw(attributeNameIndex, attributeLength, constantPool, info);
        return attributeInfo;
    }
}

bool class_file::AttributeInfo::isConstantValue(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string &>(AttributeInfo::CONSTANT_VALUE);
}

bool class_file::AttributeInfo::isCode(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string &>(AttributeInfo::CODE);
}

bool class_file::AttributeInfo::isBootstrapMethods(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::BOOTSTRAP_METHODS);
}

bool class_file::AttributeInfo::isEnclosingMethod(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::ENCLOSING_METHOD);
}

bool class_file::AttributeInfo::isExceptions(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::EXCEPTIONS);
}

bool class_file::AttributeInfo::isLineNumberTable(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::LINE_NUMBER_TABLE);
}

bool class_file::AttributeInfo::isLocalVariableTable(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::LOCAL_VARIABLE_TABLE);
}

bool class_file::AttributeInfo::isLocalVariableTypeTable(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::LOCAL_VARIABLE_TYPE_TABLE);
}

std::shared_ptr<std::u16string> class_file::AttributeInfo::getAttributeName() const {
    return this->constantPool->getConstantUtf8Info(this->getAttributeNameIndex())->decodeMUTF8();
}

bool class_file::AttributeInfo::isSignature(std::u16string &attributeName) {
    return attributeName == const_cast<std::u16string&>(AttributeInfo::SIGNATURE);
}


