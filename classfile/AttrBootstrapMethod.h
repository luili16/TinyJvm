//
// Created by 刘立新 on 2020/12/14.
//

#ifndef CH01_ATTRBOOTSTRAPMETHOD_H
#define CH01_ATTRBOOTSTRAPMETHOD_H

#include "cstdint"
#include "AttributeInfo.h"

namespace class_file {
    class BootStrapMethod {
    public:
        const uint16_t bootstrapMethodRef;
        const uint16_t numBootstrapArguments;
        const uint16_t *bootstrapArguments;
        explicit BootStrapMethod(uint16_t bootstrapMethodRef,
                                  uint16_t numBootstrapArguments,
                                  const uint16_t *bootstrapArguments);
    };


/**
 * BootstrapMethods_attribute {
 *  u2 attribute_name_index;
 *  u4 attribute_length;
 *  u2 num_bootstrap_methods;
 *  {
 *      u2 bootstrap_method_ref;
 *      u2 num_bootstrap_arguments;
 *      u2 bootstrap_arguments[num_bootstrap_arguments];
 *  } bootstrap_methods[num_bootstrap_methods];
 *  }
 */
    class AttrBootstrapMethod: public AttributeInfo {
    public:
        const uint16_t numBootstrapMethods;
        const BootStrapMethod** bootstrapMethods;
        explicit AttrBootstrapMethod(uint16_t attributeNameIndex,
                                     uint32_t attributeLength,
                                     const ConstantPool* constantPool,
                                     uint16_t numBootstrapMethods,
                                     const BootStrapMethod** bootstrapMethods);
        ~AttrBootstrapMethod() override;
        [[nodiscard]] const BootStrapMethod* getBootstrapMethod(uint16_t index) const;
    };
}




#endif //CH01_ATTRBOOTSTRAPMETHOD_H
