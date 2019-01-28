#pragma once

#include "Interface/Common/StringId.h"
#include "CRC.h"

#include <string.h>

namespace
{
static auto const CRCTable = CRC::CRC_32().MakeTable();
}

namespace AITactics
{
    
CStringId::CStringId()
    : m_id(0)
{
}

CStringId::CStringId(char const* const str)
    : m_id(CRC::Calculate(str, strlen(str), CRCTable))
{
}

bool CStringId::operator==(CStringId const other) const
{
    return m_id == other.m_id;
}

} // namespace AITactics