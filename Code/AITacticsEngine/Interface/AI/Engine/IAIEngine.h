#pragma once

namespace AITactics
{

class IAIAgentsManager;
class IAIBrainsManager;
struct SAIEngineParams;

class IAIEngine
{
public:
    virtual ~IAIEngine() {}
    virtual void Initialize(SAIEngineParams const& engineParams) = 0;
    virtual void Shutdown() = 0;

    virtual void Update(float const deltaTime) = 0;

    virtual IAIAgentsManager& GetAgentsManager() = 0;
    virtual IAIBrainsManager& GetBrainsManager() = 0;
};

} // namespace AITactics