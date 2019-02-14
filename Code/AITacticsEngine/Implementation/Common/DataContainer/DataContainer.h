#pragma once

#include "AITacticsEngine/Interface/Common/DataContainer/IDataContainer.h"

#include <vector>

namespace AITactics
{

class CDataContainer : public IDataContainer
{
public:
    virtual void AddData(std::unique_ptr<IData> data) override;
    virtual std::unique_ptr<IData> RemoveData(CStringId const dataTypeId) override;

    virtual IData* GetDataByTypeId(CStringId const dataTypeId) override;
    virtual IData const* GetDataByTypeId(CStringId const dataTypeId) const override;

    virtual bool ContainsData(CStringId const dataTypeId) const override;

private:
    using DataVector = std::vector<std::unique_ptr<IData>>;

private:
    DataVector::const_iterator FindData(CStringId const dataTypeId) const;
    DataVector::iterator FindData(CStringId const dataTypeId);

private:
    DataVector m_data;
};

} // namespace AITactics