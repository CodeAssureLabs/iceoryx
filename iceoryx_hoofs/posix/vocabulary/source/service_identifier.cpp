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

#include "iox/string.hpp"
#include <cstring>

namespace iox
{
namespace detail
{
namespace
{
bool stringMatchesWithWildcard(const char* pattern, const char* value) noexcept
{
    if (pattern == nullptr || value == nullptr)
    {
        return pattern == value;
    }

    if (std::strcmp(pattern, "*") == 0)
    {
        return true;
    }

    return std::strcmp(pattern, value) == 0;
}
} // namespace

bool doesServiceTripleMatch(const char* service,
                            const char* instance,
                            const char* event,
                            const char* otherService,
                            const char* otherInstance,
                            const char* otherEvent) noexcept
{
    return stringMatchesWithWildcard(service, otherService)
           && stringMatchesWithWildcard(instance, otherInstance)
           && stringMatchesWithWildcard(event, otherEvent);
}
} // namespace detail
} // namespace iox
