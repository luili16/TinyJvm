//
// Created by 刘立新 on 2020/12/24.
//

#ifndef CH01_ANNOTATION_H
#define CH01_ANNOTATION_H

#include "AttributeInfo.h"

namespace class_file {
    class Annotation;
    class ElementValue {
    public:
        const uint8_t tag;
        explicit ElementValue(uint8_t tag):tag(tag){};
        virtual ~ElementValue() = 0;
    };

    class RawTypeElementValue: public ElementValue {
    public:
        const uint16_t value;
        explicit RawTypeElementValue(uint8_t tag,uint16_t value):ElementValue(tag),value(value){}
        ~RawTypeElementValue() override = default;
    };

    class EnumTypeElementValue: public ElementValue {
    public:
        const uint16_t typeNameIndex;
        const uint16_t constNameIndex;
        explicit EnumTypeElementValue(uint8_t tag,uint16_t typeNameIndex,uint16_t constNameIndex):ElementValue(tag),typeNameIndex(typeNameIndex),constNameIndex(constNameIndex) {}
        ~EnumTypeElementValue() override = default;
    };

    class ClassTypeElementValue: public ElementValue {
    public:
        const uint16_t classInfoIndex;
        explicit ClassTypeElementValue(uint8_t tag,uint16_t classInfoIndex):ElementValue(tag),classInfoIndex(classInfoIndex) {}
        ~ClassTypeElementValue() override = default;
    };

    class AnnotationTypeElementValue: public ElementValue {
    public:
        const Annotation* annotationValue;
        explicit AnnotationTypeElementValue(uint8_t tag,Annotation*annotationValue):ElementValue(tag),annotationValue(annotationValue) {}
        ~AnnotationTypeElementValue() override = default;
        //{
            //delete annotationValue;
        //};
    };

    class ArrayTypeElementValue: public ElementValue {
    public:
        const uint16_t numValues;
        const ElementValue** values;
        explicit ArrayTypeElementValue(uint8_t tag,uint16_t numValues,const ElementValue** values):ElementValue(tag),numValues(numValues),values(values) {}
        ~ArrayTypeElementValue() override {
            delete [] values;
            values = nullptr;
        };
    };

    class ElementValuePair {
    public:
        const uint16_t elementNameIndex;
        const ElementValue* elementValue;
        explicit ElementValuePair(uint16_t elementNameIndex,const ElementValue* elementValue):elementNameIndex(elementNameIndex),elementValue(elementValue) {}
        ~ElementValuePair() {
            delete elementValue;
            elementValue = nullptr;
        }
    };

    class Annotation {
    public:
        const uint16_t typeIndex;
        const uint16_t numElementValuePairs;
        const ElementValuePair** elementValuePairs;
        Annotation(uint16_t typeIndex,uint16_t numElementValuePairs,const ElementValuePair** elementValuePairs):typeIndex(typeIndex),numElementValuePairs(numElementValuePairs),elementValuePairs(elementValuePairs) {};
        ~Annotation() {
            delete [] elementValuePairs;
            elementValuePairs = nullptr;
        }
    };
}




#endif //CH01_ANNOTATION_H
