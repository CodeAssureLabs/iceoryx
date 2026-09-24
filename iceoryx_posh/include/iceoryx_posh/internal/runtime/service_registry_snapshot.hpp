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

#ifndef IOX_POSH_RUNTIME_SERVICE_REGISTRY_SNAPSHOT_HPP
#define IOX_POSH_RUNTIME_SERVICE_REGISTRY_SNAPSHOT_HPP

#include "iceoryx_posh/capro/service_description.hpp"
#include "iceoryx_posh/iceoryx_posh_types.hpp"

#include <vector>

namespace iox
{
namespace runtime
{
/// @brief Collects the services currently visible to the runtime into a snapshot buffer
class ServiceRegistrySnapshot
{
  public:
    ServiceRegistrySnapshot() noexcept
    {
        m_services.reserve(MAX_NUMBER_OF_SERVICES);
    }

    ServiceRegistrySnapshot(const ServiceRegistrySnapshot&) = delete;
    ServiceRegistrySnapshot(ServiceRegistrySnapshot&&) = delete;

    ServiceRegistrySnapshot& operator=(const ServiceRegistrySnapshot&) = delete;
    ServiceRegistrySnapshot& operator=(ServiceRegistrySnapshot&&) = delete;

    void add(const capro::ServiceDescription& service) noexcept
    {
        m_services.push_back(service);
    }

    uint64_t size() const noexcept
    {
        return m_services.size();
    }

    void clear() noexcept
    {
        m_services.clear();
    }

  private:
    std::vector<capro::ServiceDescription> m_services;
};
} // namespace runtime
} // namespace iox

#endif // IOX_POSH_RUNTIME_SERVICE_REGISTRY_SNAPSHOT_HPP
