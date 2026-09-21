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

#include "iox/detail/service_registry_helper.hpp"

#include "iceoryx_posh/capro/service_description.hpp"
#include "iox/string.hpp"

namespace iox
{
namespace detail
{
bool isConcreteServiceRegistryEntry(const char* service, const char* instance, const char* event) noexcept
{
    const capro::ServiceDescription entry{capro::IdString_t{TruncateToCapacity, service},
                                          capro::IdString_t{TruncateToCapacity, instance},
                                          capro::IdString_t{TruncateToCapacity, event}};

    return entry.getServiceIDString() != capro::IdString_t{TruncateToCapacity, "*"}
           && entry.getInstanceIDString() != capro::IdString_t{TruncateToCapacity, "*"}
           && entry.getEventIDString() != capro::IdString_t{TruncateToCapacity, "*"};
}
} // namespace detail
} // namespace iox
