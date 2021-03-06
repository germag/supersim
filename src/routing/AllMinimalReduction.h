/*
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ROUTING_ALLMINIMALREDUCTION_H_
#define ROUTING_ALLMINIMALREDUCTION_H_

#include <json/json.h>
#include <prim/prim.h>

#include <string>
#include <tuple>
#include <unordered_set>

#include "event/Component.h"
#include "routing/Reduction.h"

class AllMinimalReduction : public Reduction {
 public:
  AllMinimalReduction(
      const std::string& _name, const Component* _parent,
      const PortedDevice* _device, RoutingMode _mode, bool _ignoreDuplicates,
      Json::Value _settings);
  ~AllMinimalReduction();

  void process(
      u32 _minHops,
      const std::unordered_set<std::tuple<u32, u32, u32, f64> >& _minimal,
      const std::unordered_set<std::tuple<u32, u32, u32, f64> >& _nonMinimal,
      std::unordered_set<std::tuple<u32, u32> >* _outputs,
      bool* _allMinimal) override;
};

#endif  // ROUTING_ALLMINIMALREDUCTION_H_
