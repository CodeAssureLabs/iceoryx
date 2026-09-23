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

TEST(TriggerStatistics_test, DefaultConstructedStatisticsAreZero)
{
    ::testing::Test::RecordProperty("TEST_ID", "56410198-6de1-4806-87db-c79bdf34b040");
    TriggerStatistics sut;

    EXPECT_THAT(sut.activationCount(), Eq(0U));
    EXPECT_THAT(sut.resetCount(), Eq(0U));
}

TEST(TriggerStatistics_test, RecordActivationIncrementsOnlyActivationCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "eeddc857-4775-4013-a276-6789099fdf0b");
    TriggerStatistics sut;

    sut.recordActivation();
    sut.recordActivation();
    sut.recordActivation();

    EXPECT_THAT(sut.activationCount(), Eq(3U));
    EXPECT_THAT(sut.resetCount(), Eq(0U));
}

TEST(TriggerStatistics_test, RecordResetIncrementsOnlyResetCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "45bcd20a-4fa3-4222-a076-d4eae05a5c23");
    TriggerStatistics sut;

    sut.recordReset();
    sut.recordReset();

    EXPECT_THAT(sut.activationCount(), Eq(0U));
    EXPECT_THAT(sut.resetCount(), Eq(2U));
}

TEST(TriggerStatistics_test, ActivationsAndResetsAreCountedIndependently)
{
    ::testing::Test::RecordProperty("TEST_ID", "02f9b1cb-eb2f-4840-b914-2cdd435aaa5a");
    TriggerStatistics sut;

    sut.recordActivation();
    sut.recordReset();
    sut.recordActivation();

    EXPECT_THAT(sut.activationCount(), Eq(2U));
    EXPECT_THAT(sut.resetCount(), Eq(1U));
}

} // namespace
