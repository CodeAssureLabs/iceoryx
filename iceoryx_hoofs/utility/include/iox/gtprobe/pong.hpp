// Copyright (c) 2026 by CodeAssure Labs. All rights reserved.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT
// NOTE: '#pragma once' is used instead of a classic #ifndef guard on purpose for this probe header
#pragma once

#include <cstdint>

namespace iox
{
namespace gtprobe
{
/// @brief counts down 'depth' by alternating with ping(); declared before the
///        mutual include so that ping() can refer to it
inline uint32_t pong(const uint32_t depth) noexcept;
} // namespace gtprobe
} // namespace iox

#include "iox/gtprobe/ping.hpp"

namespace iox
{
namespace gtprobe
{
inline uint32_t pong(const uint32_t depth) noexcept
{
    if (depth == 0U)
    {
        return 0U;
    }
    return 1U + ping(depth - 1U);
}
} // namespace gtprobe
} // namespace iox

