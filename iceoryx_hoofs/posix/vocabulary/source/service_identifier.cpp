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

#include "iox/detail/service_identifier.hpp"

#include "iceoryx_posh/capro/service_description.hpp"
#include "iox/string.hpp"

namespace iox
{
namespace detail
{
bool doesServiceTripleMatch(const char* service,
                            const char* instance,
                            const char* event,
                            const char* otherService,
                            const char* otherInstance,
                            const char* otherEvent) noexcept
{
    const capro::ServiceDescription first{capro::IdString_t{TruncateToCapacity, service},
                                          capro::IdString_t{TruncateToCapacity, instance},
                                          capro::IdString_t{TruncateToCapacity, event}};
    const capro::ServiceDescription second{capro::IdString_t{TruncateToCapacity, otherService},
                                           capro::IdString_t{TruncateToCapacity, otherInstance},
                                           capro::IdString_t{TruncateToCapacity, otherEvent}};
    return capro::serviceMatch(first, second);
}
} // namespace detail
} // namespace iox
