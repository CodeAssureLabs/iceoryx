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

TEST_F(TriggerStatistics_test, InitialActivationCountIsZero)
{
    ::testing::Test::RecordProperty("TEST_ID", "806553f2-8107-4b0a-8d63-081d22807a4f");
    EXPECT_EQ(m_sut.activationCount(), 0U);
}

TEST_F(TriggerStatistics_test, InitialResetCountIsZero)
{
    ::testing::Test::RecordProperty("TEST_ID", "79d43d11-dff8-4011-a36d-24cc265d251f");
    EXPECT_EQ(m_sut.resetCount(), 0U);
}

TEST_F(TriggerStatistics_test, RecordActivationIncrementsActivationCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "dcf51a1a-063d-4e6c-81cd-360d2c3a3856");
    m_sut.recordActivation();
    m_sut.recordActivation();

    EXPECT_EQ(m_sut.activationCount(), 2U);
}

TEST_F(TriggerStatistics_test, RecordResetIncrementsResetCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "18236ce3-75df-4801-a2dd-ea9f4dea658b");
    m_sut.recordReset();

    EXPECT_EQ(m_sut.resetCount(), 1U);
}

TEST_F(TriggerStatistics_test, RecordActivationDoesNotChangeResetCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "43d285c7-c201-46c8-974c-ba13590c4cf0");
    m_sut.recordActivation();

    EXPECT_EQ(m_sut.resetCount(), 0U);
}

TEST_F(TriggerStatistics_test, RecordResetDoesNotChangeActivationCount)
{
    ::testing::Test::RecordProperty("TEST_ID", "48915a4a-3510-485c-b792-a894e72bac60");
    m_sut.recordReset();

    EXPECT_EQ(m_sut.activationCount(), 0U);
}

} // namespace
