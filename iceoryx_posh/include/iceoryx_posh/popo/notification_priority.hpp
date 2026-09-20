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

#ifndef IOX_POSH_POPO_NOTIFICATION_PRIORITY_HPP
#define IOX_POSH_POPO_NOTIFICATION_PRIORITY_HPP

#include <cstdint>

namespace iox
{
namespace popo
{
enum class NotificationPriority : uint8_t
{
    LOW = 0U,
    NORMAL = 1U,
    HIGH = 2U
};

/// @brief clamps a raw priority value into the supported NotificationPriority range
/// @param[in] rawPriority the value provided by the user
/// @return the matching NotificationPriority; values above HIGH saturate to HIGH
NotificationPriority toNotificationPriority(const uint8_t rawPriority) noexcept;

/// @brief returns true if lhs should be delivered before rhs
bool hasHigherPriority(const NotificationPriority lhs, const NotificationPriority rhs) noexcept;
} // namespace popo
} // namespace iox

#endif // IOX_POSH_POPO_NOTIFICATION_PRIORITY_HPP
