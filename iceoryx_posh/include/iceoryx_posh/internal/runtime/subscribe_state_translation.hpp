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

#ifndef IOX_POSH_RUNTIME_SUBSCRIBE_STATE_TRANSLATION_HPP
#define IOX_POSH_RUNTIME_SUBSCRIBE_STATE_TRANSLATION_HPP

#include "iceoryx_binding_c/types.h"
#include "iceoryx_posh/iceoryx_posh_types.hpp"

namespace iox
{
namespace runtime
{
/// @brief translates the runtime subscribe state into the value exposed to C clients
/// @param[in] state the current subscribe state of a subscriber port
/// @return the equivalent iox_SubscribeState value
iox_SubscribeState toCSubscribeState(const SubscribeState state) noexcept;
} // namespace runtime
} // namespace iox

#endif // IOX_POSH_RUNTIME_SUBSCRIBE_STATE_TRANSLATION_HPP
