//
// Created by 刘立新 on 2020/11/20.
//

#include "ConstantPool.h"
#include "ConstantPoolInfo.h"
const class_file::ConstantPoolInfo* class_file::ConstantPool::getConstantInfo(uint16_t index) const {
    return this->constantPoolInfos[index];
}

class_file::ConstantPool::ConstantPool(uint16_t cpCount,ClassReader &reader):cpCount(cpCount) {
    this->constantPoolInfos = new ConstantPoolInfo*[cpCount];
    // The constant_pool table is indexed from 1 to constant_pool_count - 1;
    for (int i = 1; i <= this->cpCount-1; i++) {
        uint8_t tag = reader.readUint8();
        auto cpInfo = ConstantPoolInfo::newConstantPoolInfoByTag(tag,reader);
        this->constantPoolInfos[i] = cpInfo;
        // TODO ugly code!
        if (tag == ConstantPoolInfo::CONSTANT_Long || tag == ConstantPoolInfo::CONSTANT_Double) {
            // reference from <<jvm8 specification>> page 83
            // All 8-byte constants take up two entries in the constant_pool table of the class file. If a CONSTANT_Long_info
            // or CONSTANT_Double_info structure is the item in the constant_pool table at index n, then the next usable
            // item in the pool is located at index n+2. The constant_pool index n+1 must be valid but is considered
            // unusable
            i++;
            this->constantPoolInfos[i] = nullptr;
        }
    }
}
