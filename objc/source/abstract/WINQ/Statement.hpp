/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Statement_hpp
#define Statement_hpp

namespace WCDB {

class Statement {
public:
    enum class Type : int {
        AlterTable,
        Analyze,
        Attach,
        Begin,
        Commit,
        CreateIndex,
        CreateTable,
        CreateTrigger,
        CreateView,
        CreateVirtualTable,
        Delete,
        Detach,
        DropIndex,
        DropTable,
        DropTrigger,
        DropView,
        Insert,
        Pragma,
        Reindex,
        Release,
        Rollback,
        Savepoint,
        Select,
        Update,
        Vacuum,
    };
    virtual Type getType() const = 0;
    virtual const std::string &getDescription() const = 0;
};

class CRUDStatement : public Statement {
public:
    virtual lang::copy_on_write_lazy_lang<lang::CRUDLang>
    getCRUDLang() const = 0;
};

} // namespace WCDB

#endif /* Statement_hpp */