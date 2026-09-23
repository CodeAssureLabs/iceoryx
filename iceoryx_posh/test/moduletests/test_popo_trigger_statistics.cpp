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

#include "iceoryx_posh/popo/trigger_statistics.hpp"
#include "test.hpp"

namespace
{
using namespace ::testing;
using namespace iox::popo;

class TriggerStatistics_test : public Test
{
};

TEST_F(TriggerStatistics_test, ActivationCountStartsAtZero)
{
    ::testing::Test::RecordProperty("TEST_ID", "f7d8e2a1-3b5c-4d9a-8c6e-2f1a7b3d5e9c");
    TriggerStatistics stats;
    EXPECT_THAT(stats.activationCount(), Eq(0U));
}

TEST_F(TriggerStatistics_test, ResetCountStartsAtZero)
{
    ::testing::Test::RecordProperty("TEST_ID", "a1b2c3d4-e5f6-4a7b-8c9d-0e1f2a3b4c5d");
    TriggerStatistics stats;
    EXPECT_THAT(stats.resetCount(), Eq(0U));
}

TEST_F(TriggerStatistics_test, RecordActivationIncrementsCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "b2c3d4e5-f6a7-4b8c-9d0e-1f2a3b4c5d6e");
    TriggerStatistics stats;
    stats.recordActivation();
    EXPECT_THAT(stats.activationCount(), Eq(1U));
}

TEST_F(TriggerStatistics_test, RecordResetIncrementsCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "c3d4e5f6-a7b8-4c9d-0e1f-2a3b4c5d6e7f");
    TriggerStatistics stats;
    stats.recordReset();
    EXPECT_THAT(stats.resetCount(), Eq(1U));
}

TEST_F(TriggerStatistics_test, MultipleActivationsIncrementCorrectly)
{
    ::testing::Test::RecordProperty("TEST_ID", "d4e5f6a7-b8c9-4d0e-1f2a-3b4c5d6e7f8a");
    TriggerStatistics stats;
    stats.recordActivation();
    stats.recordActivation();
    stats.recordActivation();
    EXPECT_THAT(stats.activationCount(), Eq(3U));
}

TEST_F(TriggerStatistics_test, MultipleResetsIncrementCorrectly)
{
    ::testing::Test::RecordProperty("TEST_ID", "e5f6a7b8-c9d0-4e1f-2a3b-4c5d6e7f8a9b");
    TriggerStatistics stats;
    stats.recordReset();
    stats.recordReset();
    EXPECT_THAT(stats.resetCount(), Eq(2U));
}

TEST_F(TriggerStatistics_test, ActivationAndResetCountsAreIndependent)
{
    ::testing::Test::RecordProperty("TEST_ID", "f6a7b8c9-d0e1-4f2a-3b4c-5d6e7f8a9b0c");
    TriggerStatistics stats;
    stats.recordActivation();
    stats.recordActivation();
    stats.recordReset();
    EXPECT_THAT(stats.activationCount(), Eq(2U));
    EXPECT_THAT(stats.resetCount(), Eq(1U));
}

} // namespace
