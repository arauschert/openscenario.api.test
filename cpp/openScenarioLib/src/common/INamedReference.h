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

#include "IOpenScenarioModelElement.h"
#include "MemLeakDetection.h"

namespace NET_ASAM_OPENSCENARIO
{
    template <class T>
    class INamedReference: public IOpenScenarioModelElement 
    {
    public:
        /**
         * The real object the reference is pointing to
         * @return resolved real object or null if not yet resolved or could not be resolved.
         */
         virtual std::shared_ptr<T> GetTargetObject()
         {
             return nullptr;
         }

        /**
         * The name that represents the real object.
         * @return the name of the target object.
         */
        virtual std::string GetNameRef()
         {
            return "";
         }

        /**
         * Setting the parent of this named reference
         * @param parent parent in the tree.
         */
        virtual void SetParent(const std::weak_ptr<IOpenScenarioModelElement> parent) {}

    };
}