#pragma once

#include "pipeline.h"
#include "worker_manager.h"
#include "policy_enforcer.h"
#include "main/query_context.h"

namespace infinity {
class PipelineExecutor {
public:
    PipelineExecutor(std::uint16_t max_cores);

    ~PipelineExecutor() noexcept = default;

    void Run();

    bool AdmitQuery(QueryContext* query_context, const SharedPtr<Pipeline> &pipeline);

    bool CancelQuery(QueryContext* query_context);

private:
    void DispatchTask(std::uint16_t worker_id, PipelineTaskPtr task);

private:
    WorkerManager worker_manager_;

    PolicyEnforcer policy_enforcer_;
};
}