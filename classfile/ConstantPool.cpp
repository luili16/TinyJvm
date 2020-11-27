//
// Created by 刘立新 on 2020/11/20.
//

#include "ConstantPool.h"
#include "ConstantPoolInfo.h"

class_file::ConstantPoolInfo* class_file::ConstantPool::getConstantInfo(uint16_t index) {
    return nullptr;
}

class_file::ConstantPool::ConstantPool(uint16_t cpCount,ClassReader &reader):cpCount(cpCount) {
    this->constantPoolInfos = new ConstantPoolInfo*[cpCount];
    // The constant_pool table is indexed from 1 to constant_pool_count - 1;
    for (int i = 1; i < this->cpCount; i++) {
        uint8_t tag = reader.readUint8();
        auto cpInfo = ConstantPoolInfo::newConstantPoolInfoByTag(tag,reader);
        this->constantPoolInfos[i] = cpInfo;
    }
}
