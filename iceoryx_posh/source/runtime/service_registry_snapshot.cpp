// Copyright (c) 2026 by Contributors to the Eclipse Foundation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include "iceoryx_posh/internal/runtime/service_registry_snapshot.hpp"

namespace iox
{
namespace runtime
{
bool ServiceRegistrySnapshot::add(const capro::ServiceDescription& service) noexcept
{
    return m_services.push_back(service);
}

uint64_t ServiceRegistrySnapshot::size() const noexcept
{
    return m_services.size();
}

void ServiceRegistrySnapshot::clear() noexcept
{
    m_services.clear();
}
} // namespace runtime
} // namespace iox
