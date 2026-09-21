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

#include "iceoryx_posh/internal/runtime/platform_config_probe.hpp"

#include "iox/detail/system_configuration.hpp"
#include "iox/logging.hpp"

namespace iox
{
namespace runtime
{
uint64_t pageAlignedSegmentSize(const uint64_t requestedSize) noexcept
{
    const uint64_t pageSize = detail::pageSize();
    const uint64_t remainder = requestedSize % pageSize;
    if (remainder == 0U)
    {
        return requestedSize;
    }

    const uint64_t alignedSize = requestedSize + (pageSize - remainder);
    IOX_LOG(Debug, "Aligned requested segment size " << requestedSize << " to " << alignedSize);
    return alignedSize;
}
} // namespace runtime
} // namespace iox
