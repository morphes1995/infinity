//
// Created by jinhai on 23-3-14.
//

#include "physical_drop_schema.h"


#include "main/infinity.h"

namespace infinity {

void
PhysicalDropSchema::Init() {

}

void
PhysicalDropSchema::Execute(SharedPtr<QueryContext>& query_context) {
    Infinity::instance().catalog()->DeleteSchema(*schema_name_, conflict_type_);

    // Generate the result
    Vector<SharedPtr<ColumnDef>> column_defs = {
            MakeShared<ColumnDef>(0, DataType(LogicalType::kInteger), "OK", HashSet<ConstraintType>())
    };

    SharedPtr<TableDef> result_table_def_ptr
            = MakeShared<TableDef>("Tables", column_defs);
    output_ = MakeShared<Table>(result_table_def_ptr, TableType::kDataTable);
}

}
