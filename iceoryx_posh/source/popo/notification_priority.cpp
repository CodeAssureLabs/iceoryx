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

#include "iceoryx_posh/popo/notification_priority.hpp"

namespace iox
{
namespace popo
{
NotificationPriority toNotificationPriority(const uint8_t rawPriority) noexcept
{
    if (rawPriority >= static_cast<uint8_t>(NotificationPriority::HIGH))
    {
        return NotificationPriority::HIGH;
    }
    if (rawPriority == static_cast<uint8_t>(NotificationPriority::NORMAL))
    {
        return NotificationPriority::NORMAL;
    }
    return NotificationPriority::LOW;
}

bool hasHigherPriority(const NotificationPriority lhs, const NotificationPriority rhs) noexcept
{
    return static_cast<uint8_t>(lhs) > static_cast<uint8_t>(rhs);
}
} // namespace popo
} // namespace iox
