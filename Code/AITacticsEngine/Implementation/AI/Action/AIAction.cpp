#include "AITacticsEngine/AITacticsEngine_PCH.h"
#include "AITacticsEngine/Implementation/AI/Action/AIAction.h"

namespace AITactics
{

CAIAction::CAIAction(std::unique_ptr<IDataContainer> dataContainer)
    : m_dataContainer(std::move(dataContainer))
{
}

IDataContainer const& CAIAction::GetActionDataContainer() const
{
    return *m_dataContainer.get();
}

} // namespace AITactics