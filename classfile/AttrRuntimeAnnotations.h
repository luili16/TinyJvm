//
// Created by 刘立新 on 2020/12/24.
//

#ifndef CH01_ATTRRUNTIMEANNOTATIONS_H
#define CH01_ATTRRUNTIMEANNOTATIONS_H
#include "AttributeInfo.h"
#include "Annotation.h"
namespace class_file {
    class AttrRuntimeVisibleAnnotations: public AttributeInfo {
    public:
        const uint16_t numAnnotations;
        const Annotation** annotations;
        explicit AttrRuntimeVisibleAnnotations(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t numAnnotations,const Annotation** annotations):AttributeInfo(attributeNameIndex,attributeLength,constantPool),numAnnotations(numAnnotations),annotations(annotations) {}
        ~AttrRuntimeVisibleAnnotations() override {
            delete [] annotations;
            annotations = nullptr;
        }
    };

    class AttrRuntimeInvisibleAnnotations: public AttributeInfo {
    public:
        const uint16_t numAnnotations;
        const Annotation** annotations;
        explicit AttrRuntimeInvisibleAnnotations(uint16_t attributeNameIndex, uint32_t attributeLength,const ConstantPool* constantPool,uint16_t numAnnotations,const Annotation** annotations):AttributeInfo(attributeNameIndex,attributeLength,constantPool),numAnnotations(numAnnotations),annotations(annotations) {}
        ~AttrRuntimeInvisibleAnnotations() override {
            delete [] annotations;
            annotations = nullptr;
        }
    };

    class AttrRuntimeVisibleParameterAnnotations: public AttributeInfo {

    };

    class AttrRuntimeInvisibleParameterAnnotations: public AttributeInfo {

    };


}

#endif //CH01_ATTRRUNTIMEANNOTATIONS_H
