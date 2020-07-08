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
package de.rac.openscenario.v1_0.api;


import de.rac.openscenario.api.IOpenScenarioFlexElement;
/**
 * This is a automatic generated file according to the OpenSCENARIO specification version 1.0
 * <p>
 * From OpenSCENARIO class model specification:
 * Definition of macroscopic traffic based on vehicle and controller definitions.
 * 
 * @author RA Consulting OpenSCENARIO generation facility
*/
public interface ITrafficDefinition extends IOpenScenarioFlexElement{

	/**
	 * From OpenSCENARIO class model specification:
	 * Name of the traffic definition.
	 * 
	 * @return value of model property name
	*/
	public String getName();

	/**
	 * From OpenSCENARIO class model specification:
	 * Distribution of vehicle categories within the traffic.
	 * 
	 * @return value of model property vehicleCategoryDistribution
	*/
	public IVehicleCategoryDistribution getVehicleCategoryDistribution();

	/**
	 * From OpenSCENARIO class model specification:
	 * Distribution of controllers within this traffic.
	 * 
	 * @return value of model property controllerDistribution
	*/
	public IControllerDistribution getControllerDistribution();
}
