#include "AITacticsEngine/AITacticsEngine_PCH.h"

#include "AITacticsEngine/Implementation/Common/DataContainer/DataContainer.h"

namespace AITactics
{

void CDataContainer::AddData(std::unique_ptr<IData> data)
{
    auto const dataTypeId = data->GetDataTypeId();
    assert(!ContainsData(dataTypeId) && "There is the same data type in the container");
    m_data.emplace_back(std::move(data));
}

std::unique_ptr<IData> CDataContainer::RemoveData(CStringId const dataTypeId)
{
    assert(ContainsData(dataTypeId) && "There is no data with such a type to delete");
    auto const dataIter = FindData(dataTypeId);
    auto data = std::move(*dataIter);
    m_data.erase(dataIter);
    return std::move(data);
}

IData& CDataContainer::GetDataByTypeId(CStringId const dataTypeId)
{
    assert(ContainsData(dataTypeId) && "There is no data with such a type");
    auto const dataIter = FindData(dataTypeId);
    return *dataIter->get();
}

IData const& CDataContainer::GetDataByTypeId(CStringId const dataTypeId) const
{
    assert(ContainsData(dataTypeId) && "There is no data with such a type");
    auto const dataIter = FindData(dataTypeId);
    return *dataIter->get();
}

bool CDataContainer::ContainsData(CStringId const dataTypeId) const
{
    auto const dataIter = FindData(dataTypeId);
    return dataIter != m_data.end();
}

CDataContainer::DataVector::const_iterator CDataContainer::FindData(CStringId const dataTypeId) const
{
    return std::find_if(m_data.begin(), m_data.end(), [dataTypeId](auto const& data) 
    {
        return data->GetDataTypeId() == dataTypeId;
    });
}

CDataContainer::DataVector::iterator CDataContainer::FindData(CStringId const dataTypeId)
{
    return std::find_if(m_data.begin(), m_data.end(), [dataTypeId](auto const& data)
    {
        return data->GetDataTypeId() == dataTypeId;
    });
}

} // namespace AITactics