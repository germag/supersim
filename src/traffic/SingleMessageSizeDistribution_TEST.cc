/*
 * Copyright 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "traffic/SingleMessageSizeDistribution.h"

#include <gtest/gtest.h>
#include <json/json.h>

#include "test/TestSetup_TEST.h"
#include "traffic/MessageSizeDistributionFactory.h"

TEST(SingleMessageSizeDistribution, simple) {
  TestSetup ts(123, 123, 123);

  const u32 SIZE = 3;

  Json::Value settings;
  settings["type"] = "single";
  settings["message_size"] = SIZE;

  MessageSizeDistribution* msd =
      MessageSizeDistributionFactory::createMessageSizeDistribution(
          "msd", nullptr, settings);

  const u32 ROUNDS = 10000000;
  for (u32 round = 0; round < ROUNDS; round++) {
    u32 size = msd->nextMessageSize();
    ASSERT_EQ(size, SIZE);
  }

  delete msd;
}
