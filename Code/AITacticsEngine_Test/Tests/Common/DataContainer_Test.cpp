#include "AITacticsEngine_Test/Tests/Common/IDataContainer_Test.h"
#include "AITacticsEngine/Implementation/Common/DataContainer/DataContainer.h"

namespace AITactics_Test
{

static std::unique_ptr<AITactics::IDataContainer> CreateDataContainer()
{
    return std::make_unique<AITactics::CDataContainer>();
}

INSTANTIATE_TEST_SUITE_P(CDataContainer_Test, IDataContainer_Test,
    testing::Values(&CreateDataContainer));

} // namespace AITactics_Test