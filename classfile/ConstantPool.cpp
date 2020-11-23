//
// Created by 刘立新 on 2020/11/20.
//

#include "ConstantPool.h"
#include "ConstantPoolInfo.h"

std::shared_ptr<ConstantPoolInfo> ConstantPool::getConstantInfo(uint16_t index) {
    return std::shared_ptr<ConstantPoolInfo>();
}

ConstantPool::ConstantPool(ClassReader &reader) {
    this->cpCount = reader.readUint16();
    this->constantPoolInfos = new ConstantPoolInfo*[cpCount];
    // The constant_pool table is indexed from 1 to constant_pool_count - 1;
    for (int i = 1; i < this->cpCount; i++) {
        uint8_t tag = reader.readUint8();
        auto cpInfo = ConstantPoolInfo::newConstantPoolInfoByTag(tag,reader);
        this->constantPoolInfos[i] = cpInfo;
    }
}
