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
 
package de.rac.openscenario.v1_0.test;

import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import de.rac.openscenario.loader.ScenarioLoaderException;
import de.rac.openscenario.v1_0.api.ICatalogReference;
import de.rac.openscenario.v1_0.api.IOpenScenario;
import de.rac.openscenario.v1_0.api.IScenarioObject;
import de.rac.openscenario.v1_0.api.IVehicle;
import de.rac.openscenario.v1_0.catalog.CatalogHelper;

public class TestImports extends TestBase{


	

	@Test
	public void testImportSuccess() {
		try {
			MessageLogger catalogMessageLogger = new MessageLogger();
			
			IOpenScenario openScenario =  executeImportParsing(getResourceFile("simpleImport/simpleImport.xosc").getAbsolutePath(),catalogMessageLogger);
			// Ego parameterAssignement for maxSpeed
			ICatalogReference catalogReference = getVehicleImport(openScenario, "Ego","car_white");
			Assertions.assertTrue(catalogReference != null);
			Assertions.assertTrue(catalogReference.getRef()!= null);
			IVehicle vehicleImportEgo = CatalogHelper.asVehicle(catalogReference.getRef());
			Assertions.assertTrue(vehicleImportEgo!= null);
			Assertions.assertEquals((Double) 69.0, vehicleImportEgo.getPerformance().getMaxSpeed());
			
			catalogReference = getVehicleImport(openScenario, "OverTaker","car_red");
			Assertions.assertTrue(catalogReference != null);
			Assertions.assertTrue(catalogReference.getRef()!= null);
			IVehicle vehicleImportOvertaker = CatalogHelper.asVehicle(catalogReference.getRef());
			Assertions.assertTrue(vehicleImportOvertaker!= null);
			Assertions.assertEquals((Double) 70.0, vehicleImportOvertaker.getPerformance().getMaxSpeed());
			Assertions.assertTrue(vehicleImportOvertaker != vehicleImportEgo);
			
			Assertions.assertFalse(hasErrors(messageLogger));
		} catch (ScenarioLoaderException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Test
	public void testImportWithParametersSuccess() {
		try {
			MessageLogger catalogMessageLogger = new MessageLogger();
			
			IOpenScenario openScenario = executeImportParsing(getResourceFile( "simpleImportWithParameters/importWithParameters.xosc").getAbsolutePath(),catalogMessageLogger);
			
			// Ego parameterAssignement for maxSpeed
			ICatalogReference catalogReference = getVehicleImport(openScenario, "Ego","car_white");
			Assertions.assertTrue(catalogReference != null);
			Assertions.assertTrue(catalogReference.getRef()!= null);
			IVehicle vehicleImportEgo = CatalogHelper.asVehicle(catalogReference.getRef());
			Assertions.assertTrue(vehicleImportEgo!= null);
			Assertions.assertEquals((Double) 70.0, vehicleImportEgo.getPerformance().getMaxSpeed());
			
			// Overtaker: Same import, different ParamterAssignements for maxSpeed
			catalogReference = getVehicleImport(openScenario, "OverTaker","car_white");
			Assertions.assertTrue(catalogReference != null);
			Assertions.assertTrue(catalogReference.getRef()!= null);
			IVehicle vehicleImportOvertaker = CatalogHelper.asVehicle(catalogReference.getRef());
			Assertions.assertTrue(vehicleImportOvertaker!= null);
			Assertions.assertEquals((Double) 31.0, vehicleImportOvertaker.getPerformance().getMaxSpeed());
			Assertions.assertTrue(vehicleImportOvertaker != vehicleImportEgo);
			
			// ThirdEntity: No ParameterAssignements => Default Value for maxSpeed
			catalogReference = getVehicleImport(openScenario, "ThirdEntity","car_white");
			Assertions.assertTrue(catalogReference != null);
			Assertions.assertTrue(catalogReference.getRef()!= null);
			IVehicle vehicleImportThirdVehicle = CatalogHelper.asVehicle(catalogReference.getRef());
			Assertions.assertTrue(vehicleImportThirdVehicle!= null);
			Assertions.assertEquals((Double) 60.0, vehicleImportThirdVehicle.getPerformance().getMaxSpeed());
			
			Assertions.assertFalse(hasErrors(messageLogger));
		} catch (ScenarioLoaderException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	

	private ICatalogReference getVehicleImport(IOpenScenario openScenario, String scenarioObjectName, String entryName)
	{
		List<IScenarioObject> scenarioObjects = openScenario.getOpenScenarioCategory().getScenarioDefinition().getEntities().getScenarioObjects();
		for (IScenarioObject scenarioObject: scenarioObjects)
		{
			if (scenarioObject.getName().equals(scenarioObjectName))
			{
				ICatalogReference catalogReference = scenarioObject.getEntityObject().getCatalogReference();
				if (catalogReference != null && catalogReference.getEntryName().equals(entryName))
				{
					return catalogReference;
				}
			}
		}
		return null;
	}
	
	
	
}
