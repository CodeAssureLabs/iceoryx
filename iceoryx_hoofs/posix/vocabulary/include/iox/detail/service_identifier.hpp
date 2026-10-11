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

#ifndef IOX_HOOFS_POSIX_VOCABULARY_DETAIL_SERVICE_IDENTIFIER_HPP
#define IOX_HOOFS_POSIX_VOCABULARY_DETAIL_SERVICE_IDENTIFIER_HPP

namespace iox
{
namespace detail
{
/// @brief checks whether two (service, instance, event) identifier triples describe the same
///        service, honouring the wildcard semantics used by the service registry
/// @param[in] service, instance, event the first triple
/// @param[in] otherService, otherInstance, otherEvent the second triple
/// @return true if the triples match, otherwise false
bool doesServiceTripleMatch(const char* service,
                            const char* instance,
                            const char* event,
                            const char* otherService,
                            const char* otherInstance,
                            const char* otherEvent) noexcept;
} // namespace detail
} // namespace iox

#endif // IOX_HOOFS_POSIX_VOCABULARY_DETAIL_SERVICE_IDENTIFIER_HPP
