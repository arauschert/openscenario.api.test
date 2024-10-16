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

#include "BaseTreeContext.h"
#include "MemLeakDetection.h"
#include <memory>
#include "ExportDefinitions.h"

namespace NET_ASAM_OPENSCENARIO
{
    class PropertyTreeContext: public BaseTreeContext
    {

    private:
        std::vector<std::string> _propertyNames = {};

    public:

        /**
         * @param treeObjectContext a model element as the parent of the properties.
         * @param propertyNames the names of the properties as you would use it in the IOpenScenarioFlexElement
         */
		PropertyTreeContext(std::shared_ptr<IOpenScenarioModelElement> treeObjectContext, std::vector<std::string>&  propertyNames);
		virtual ~PropertyTreeContext() = default;
        /**
         * @return the property names
         */
		std::vector<std::string> GetPropertyNames();

        /**
         * Creates a PropertyTreeContext from a object and a single property name (convenience factory method)
         * @param treeObjectContext the tree object context
         * @param propertyName the name of the property
         * @return a property tree context
         */
		OPENSCENARIOLIB_EXP static std::shared_ptr<PropertyTreeContext> Create(std::shared_ptr<IOpenScenarioModelElement> treeObjectContext, const std::string propertyName);

    };
}
