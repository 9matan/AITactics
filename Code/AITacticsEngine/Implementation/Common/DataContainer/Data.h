#pragma once

#include "AITacticsEngine/Interface/Common/DataContainer/IData.h"

#define DECLARE_DATA_TYPE_BEGIN(DataType) \
class DataType : public AITactics::IData \
{ \
    public: \
        static AITactics::CStringId GetClassId() { return ms_dataTypeId; } \
        virtual AITactics::CStringId GetDataTypeId() const override { return ms_dataTypeId; } \
    private: \
        static AITactics::CStringId const ms_dataTypeId; \

#define DECLARE_DATA_TYPE_END(DataType) };

#define DEFINE_DATA_TYPE(DataType) AITactics::CStringId const DataType::ms_dataTypeId = AITactics::CStringId(#DataType);