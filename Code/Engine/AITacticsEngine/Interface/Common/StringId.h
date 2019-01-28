#pragma once

namespace AITactics
{
    
class CStringId
{
public:
    using Id = unsigned int;

    CStringId();
    explicit CStringId(char const* const str);

    Id GetId() const { return m_id; }
    bool operator==(CStringId const other) const;

private:
    Id m_id;
};

}