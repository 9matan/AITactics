#pragma once

#include "AITacticsEngine/Interface/AI/Action/IAIAction.h"
#include "AITacticsEngine/Interface/Common/DataContainer/IDataContainer.h"

namespace AITactics
{

class CAIAction : public IAIAction
{
public:
    CAIAction(std::unique_ptr<IDataContainer> dataContainer);

    virtual IDataContainer const& GetActionDataContainer() const override;
private:
    std::unique_ptr<IDataContainer> m_dataContainer;
};

} // namespace AITactics