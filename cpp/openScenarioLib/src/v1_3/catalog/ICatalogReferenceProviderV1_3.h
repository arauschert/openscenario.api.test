/*
 * Copyright 2020 RA Consulting
 *
 * RA Consulting GmbH licenses this file under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "ApiClassInterfacesV1_3.h"
#include "MemLeakDetection.h"
#include <vector>

namespace NET_ASAM_OPENSCENARIO
{
    namespace v1_3
    {
        class ICatalogReferenceProvider
        {
        public:
            ICatalogReferenceProvider() = default;
            virtual ~ICatalogReferenceProvider() = default;
            /**
             * Provides a list with all catalog references from a scenario a file.
             * @return the list with the catalog references
             */
            virtual std::vector<std::shared_ptr<ICatalogReference>> GetCatalogReferences()
            {
                return {};
            }
        };
    }
}