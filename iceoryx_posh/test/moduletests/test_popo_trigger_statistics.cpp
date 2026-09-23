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
using namespace iox;
using namespace iox::popo;
using namespace ::testing;

class TriggerStatistics_test : public Test
{
  public:
    TriggerStatistics m_sut;
};

TEST_F(TriggerStatistics_test, DefaultConstructedHasZeroCounts)
{
    ::testing::Test::RecordProperty("TEST_ID", "8f1e6f7c-df9f-4d47-8c74-6f4a3b2a5e1a");
    EXPECT_THAT(m_sut.activationCount(), Eq(0U));
    EXPECT_THAT(m_sut.resetCount(), Eq(0U));
}

TEST_F(TriggerStatistics_test, RecordActivationIncrementsActivationCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "6b8e6d18-3f0e-4c62-8f88-1a3d6a4dcd9b");
    m_sut.recordActivation();
    m_sut.recordActivation();

    EXPECT_THAT(m_sut.activationCount(), Eq(2U));
    EXPECT_THAT(m_sut.resetCount(), Eq(0U));
}

TEST_F(TriggerStatistics_test, RecordResetIncrementsResetCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "1e6b2f0e-8b8e-4b78-9a1b-2f3e0a6f9c9c");
    m_sut.recordReset();

    EXPECT_THAT(m_sut.activationCount(), Eq(0U));
    EXPECT_THAT(m_sut.resetCount(), Eq(1U));
}
} // namespace
