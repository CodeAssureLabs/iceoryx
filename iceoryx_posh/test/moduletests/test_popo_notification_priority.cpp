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

#include "test.hpp"

namespace
{
using namespace ::testing;
using namespace iox::popo;

TEST(NotificationPriority_test, ZeroMapsToLow)
{
    ::testing::Test::RecordProperty("TEST_ID", "5f1c6d7e-0c4a-4b9c-9a3e-2b8d1e4f6a01");
    EXPECT_THAT(toNotificationPriority(0U), Eq(NotificationPriority::LOW));
}

TEST(NotificationPriority_test, OneMapsToNormal)
{
    ::testing::Test::RecordProperty("TEST_ID", "5f1c6d7e-0c4a-4b9c-9a3e-2b8d1e4f6a02");
    EXPECT_THAT(toNotificationPriority(1U), Eq(NotificationPriority::NORMAL));
}

TEST(NotificationPriority_test, ValuesAboveHighSaturateToHigh)
{
    ::testing::Test::RecordProperty("TEST_ID", "5f1c6d7e-0c4a-4b9c-9a3e-2b8d1e4f6a03");
    EXPECT_THAT(toNotificationPriority(2U), Eq(NotificationPriority::HIGH));
    EXPECT_THAT(toNotificationPriority(200U), Eq(NotificationPriority::HIGH));
}

TEST(NotificationPriority_test, HigherPriorityIsOrderedFirst)
{
    ::testing::Test::RecordProperty("TEST_ID", "5f1c6d7e-0c4a-4b9c-9a3e-2b8d1e4f6a04");
    EXPECT_TRUE(hasHigherPriority(NotificationPriority::HIGH, NotificationPriority::LOW));
    EXPECT_FALSE(hasHigherPriority(NotificationPriority::LOW, NotificationPriority::HIGH));
    EXPECT_FALSE(hasHigherPriority(NotificationPriority::NORMAL, NotificationPriority::NORMAL));
}
} // namespace
