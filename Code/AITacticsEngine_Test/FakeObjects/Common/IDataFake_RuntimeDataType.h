#include "AITacticsEngine/Interface/Common/DataContainer/IData.h"

namespace AITactics_Test
{

class IDataFake_RuntimeDataType : public AITactics::IData
{
public:
    IDataFake_RuntimeDataType(char const* const dataType);
    IDataFake_RuntimeDataType(AITactics::CStringId const& dataTypeId);
    virtual AITactics::CStringId GetDataTypeId() const override;

private:
    AITactics::CStringId m_dataType;
};

} // namespace AITactics_Test