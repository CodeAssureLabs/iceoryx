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

#ifndef IOX_POSH_RUNTIME_PLATFORM_CONFIG_PROBE_HPP
#define IOX_POSH_RUNTIME_PLATFORM_CONFIG_PROBE_HPP

#include <cstdint>

namespace iox
{
namespace runtime
{
/// @brief rounds a requested shared memory segment size up to the next multiple of the platform page size
/// @param[in] requestedSize the size in bytes the caller asked for
/// @return the smallest page aligned size that is greater or equal to requestedSize
uint64_t pageAlignedSegmentSize(const uint64_t requestedSize) noexcept;
} // namespace runtime
} // namespace iox

#endif // IOX_POSH_RUNTIME_PLATFORM_CONFIG_PROBE_HPP
