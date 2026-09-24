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
using iox::popo::TriggerStatistics;

TEST(TriggerStatistics_test, DefaultConstructedStatisticsHaveZeroCounts)
{
    ::testing::Test::RecordProperty("TEST_ID", "8105e3d5-7e3a-4c9a-82cf-d2c334407631");
    TriggerStatistics sut;

    EXPECT_THAT(sut.activationCount(), Eq(0U));
    EXPECT_THAT(sut.resetCount(), Eq(0U));
}

TEST(TriggerStatistics_test, RecordActivationIncrementsOnlyActivationCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "efca90fc-457a-45b3-9d79-7288af6c7b2a");
    TriggerStatistics sut;

    sut.recordActivation();

    EXPECT_THAT(sut.activationCount(), Eq(1U));
    EXPECT_THAT(sut.resetCount(), Eq(0U));
}

TEST(TriggerStatistics_test, RecordResetIncrementsOnlyResetCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "71797106-7225-4a71-b6d5-aa6a7b0a683d");
    TriggerStatistics sut;

    sut.recordReset();

    EXPECT_THAT(sut.activationCount(), Eq(0U));
    EXPECT_THAT(sut.resetCount(), Eq(1U));
}

TEST(TriggerStatistics_test, MultipleRecordsAreCountedIndependently)
{
    ::testing::Test::RecordProperty("TEST_ID", "7867a5fc-0acd-4ba9-86e8-ada93406ca57");
    constexpr uint64_t NUMBER_OF_ACTIVATIONS{5U};
    constexpr uint64_t NUMBER_OF_RESETS{3U};
    TriggerStatistics sut;

    for (uint64_t i = 0U; i < NUMBER_OF_ACTIVATIONS; ++i)
    {
        sut.recordActivation();
    }
    for (uint64_t i = 0U; i < NUMBER_OF_RESETS; ++i)
    {
        sut.recordReset();
    }

    EXPECT_THAT(sut.activationCount(), Eq(NUMBER_OF_ACTIVATIONS));
    EXPECT_THAT(sut.resetCount(), Eq(NUMBER_OF_RESETS));
}

} // namespace
