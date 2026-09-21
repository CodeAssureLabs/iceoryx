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

#ifndef IOX_HOOFS_UTILITY_SERVICE_REGISTRY_HELPER_HPP
#define IOX_HOOFS_UTILITY_SERVICE_REGISTRY_HELPER_HPP

namespace iox
{
namespace detail
{
/// @brief checks whether a service/instance/event triple describes a concrete registry entry, i.e. none of
///        the three identifiers is a wildcard
/// @param[in] service the service identifier
/// @param[in] instance the instance identifier
/// @param[in] event the event identifier
/// @return true if none of the identifiers is a wildcard, otherwise false
bool isConcreteServiceRegistryEntry(const char* service, const char* instance, const char* event) noexcept;
} // namespace detail
} // namespace iox

#endif // IOX_HOOFS_UTILITY_SERVICE_REGISTRY_HELPER_HPP
